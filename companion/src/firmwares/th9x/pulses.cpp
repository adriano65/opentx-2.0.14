/*
 * Author	Thomas Husterer <thus1@t-online.de>
 * Author	Josef Glatthaar <josef.glatthaar@googlemail.com >
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 */

#include "th9x.h"
/******************************************************************************
  the functions below are called from int-level
  the functions below are called from int-level
  the functions below are called from int-level
******************************************************************************/

static uint8_t  pulses2MHz[50*3];
static uint8_t *pulses2MHzPtr;
uint8_t  g_pulseLoopCnt; //only in ppm-mode

#define CTRL_END 0
#define CTRL_CNT 1
#define CTRL_REP_1CMD -3
#define CTRL_REP_2CMD -6


extern uint8_t g_tmr1Latency_max;
extern uint8_t g_tmr1Latency_min;

#ifndef SIM
//ISR(TIMER1_OVF_vect)
ISR(TIMER1_COMPA_vect) //2MHz pulse generation
{
  static uint8_t *pulsePtr = pulses2MHz;
  //uint8_t i = 0;
  //do{
    // Timer schnell auslesen funktioniert nicht, deshalb i
    //  }while(dt<4 && i++<5);
  uint8_t dt=TCNT1L;

  if(g_tmr1Latency_max<dt) g_tmr1Latency_max=dt;
  if(g_tmr1Latency_min>dt) g_tmr1Latency_min=dt;

  PORTB ^= (1<<OUT_B_PPM);

  //
  // format of control-stream
  // 
  // tme16 + [ rep8 + cnt8 ] +ctrl8 
  // rep8 < 0 (-3,-6,-9..) 
  // cnt8 = 1..255  1=exec 1x 
  // ctrl >=0 (0 = finish, 1 = cont)
  // 
  // 

  int8_t ctrl,dmy;
  asm volatile(
    " ld   %[ctrl],Z+        \n\t"
    " ld   %[dmy],Z+        \n\t"
    " out  %B[ocr1a],%[dmy]      \n\t"
    " out  %A[ocr1a],%[ctrl]      \n\t"
    " ld   %[ctrl],Z+        \n\t"
    " sbrs %[ctrl],7         \n\t" //skip if neg
    " jmp  1f                \n\t"
    //neg value -> loop
    " ld   %[dmy],Z+         \n\t" //counter
    " subi %[dmy],1          \n\t" //counter--
    " breq 2f                \n\t"
    
    
    //counter != 0
    " st   -Z,%[dmy]         \n\t" //store counter--
    " add  r30,%[ctrl]       \n\t"
    " brcs 1f                \n\t"
    " subi r31,1             \n\t" //add ff+carry
    " jmp  1f                \n\t" //!! ctrl != 0

    //counter == 0
    " 2:                     \n\t" 
    " ld   %[ctrl],Z+        \n\t"

    " 1:                     \n\t"
    : [p]   "=z"  (pulsePtr)
    , [ctrl]"=r"  (ctrl)
    , [dmy] "=r"  (dmy)
    :       "%[p]"(pulsePtr)
    , [ocr1a]   "I"(_SFR_IO_ADDR(OCR1A))
	    //    : "r30", "r31"
  );
  if( ctrl == 0) {
    //TIMSK &= ~(1<<OCIE1A); //stop reentrance 
    //sei();
    //http://www.nongnu.org/avr-libc/user-manual/FAQ.html#faq_reg_usage
    //Call-used registers (r18-r27, r30-r31)
    asm volatile(
      " push   r18              \n\t"
      " push   r19              \n\t"
      " push   r20              \n\t"
      " push   r21              \n\t"
      " push   r22              \n\t"
      " push   r23              \n\t" //r24,25 r30,r31 are already saved
      " push   r26              \n\t"
      " push   r27              \n\t"
      " call   setupPulses      \n\t"
      //" sts    %[pulsePtr],r24 \n\t"
      //" sts    %[pulsePtr]+1,r25 \n\t"
      " pop    r27              \n\t"
      " pop    r26              \n\t"
      " pop    r23              \n\t"
      " pop    r22              \n\t"
      " pop    r21              \n\t"
      " pop    r20              \n\t"
      " pop    r19              \n\t"
      " pop    r18              \n\t"
      //: [pulsePtr]"=m"(pulsePtr)
      //:
      //: "r24","r25"
    );
    pulsePtr = pulses2MHz;
    
    //uint16_t ret=*pulsePtr;
    
    //cli();
    //TIMSK |= (1<<OCIE1A);
    //for(int j=0; j<600; j++){asm("");  }

  }
  heartbeat |= HEART_TIMER2Mhz;
}
#endif


static void _send_u8(uint8_t u8)
{
#ifdef  SIM
  *(pulses2MHzPtr)++=u8; 
#else
  asm volatile(
    " st   Z+,%A[u]        \n\t"

    : [p]"=z"(pulses2MHzPtr)
    :    "%[p]"(pulses2MHzPtr)
    , [u]"r"(u8)
  );

#endif
}
static void _send_u16(uint16_t u16)
{
#ifdef  SIM
  *(*(uint16_t**)&pulses2MHzPtr)++=u16; 
#else
  asm volatile(
    " st   Z+,%A[t0]        \n\t"
    " st   Z+,%B[t0]        \n\t"

    : [p]"=z"(pulses2MHzPtr)
    :    "%[p]"(pulses2MHzPtr)
    , [t0]"r"(u16)
  );

#endif
}

static void _send_1(uint16_t t0)
{
  //  *(*(uint16_t**)&pulses2MHzPtr)++=t0; 
  _send_u16(t0);
  *pulses2MHzPtr++=CTRL_CNT; 
  //_send_u8(CTRL_CNT);
}
static void _send_rep1(uint16_t t0,uint8_t cnt)
{
  //  *(*(uint16_t**)&pulses2MHzPtr)++=t0; 
  _send_u16(t0);
  _send_u8(CTRL_REP_1CMD);
  _send_u8(cnt);
  _send_u8(CTRL_CNT);
}
static void _send_2(uint16_t t0,uint16_t t1)
{
  _send_1(t0);
  _send_1(t1);
}


#define BITS  10
#define BITS2 (BITS-1)

NOINLINE uint8_t reduce7u(int16_t v, uint8_t sfr)
{
  v += (1<<BITS2);
  if(v <  0) v=0;
  if(v >= (1<<BITS)) v=(1<<BITS)-1;
  return v>>sfr;
}

NOINLINE int8_t reduce7s(int16_t v, uint8_t sfr, uint8_t sf2, int8_t ofs2)
{
  v += (1<<BITS2)+sf2;
  if(v&(1<<BITS)) v = (1<<BITS)-1; //no overflow
  int8_t  i8 = (uint16_t)v>>sfr;
  if(i8<=0) i8=1;
  i8-=ofs2;
  if(i8>=ofs2) i8=ofs2-1;//no overflow
  return i8;
}
//these defines allow the compiler to preclculate constants
#define getChan7u(i,bitsRes) reduce7u(g_chans512[i],(BITS-bitsRes))
#define getChan7s(i,bitsRes) reduce7s(g_chans512[i],(BITS-bitsRes),1<<((BITS-bitsRes)-1),1<<(bitsRes-1))

static void setupPulsesPPM()
{
  //http://www.aerodesign.de/peter/2000/PCM/frame_ppm.gif
  //22.5 ges   0.3low 8* (0.7-1.7 high 0.3low) high
  //uint16_t rest=22500u*2;
  //   _----_-----_ .. ----------------------
  //pulses2MHzPtr = pulses2MHz;
  uint16_t rest=(22500u-300u*9)*2; //issue 4, 41
  //uint8_t j=0;
  for(uint8_t i=0;i<8;i++){ //NUM_CHNOUT
    int16_t v = g_chans512[i];
    v = 2*v - v/21 + 1200*2; // 24/512 = 3/64 ~ 1/21
    rest-=v;//chans[i];
    _send_2(300*2-1,v-1);
  }
  _send_2(300*2-1,rest-1);
  g_pulseLoopCnt++;

}


// _ oder - je 0.6ms  (gemessen 0.7ms)
//
// Achtung !! 0 am Ausgang = sendesignal high
//  
//____-----_-_-_--_--_   -_--__  -_-_-_-_  -_-_-_-_  --__--__-_______
//         trailer        chan     m1         m2      
//
//see /home/thus/txt/silverlit/thus.txt
// 0-Bit: 600us hi +  600us lo
// 1-Bit:1200us hi + 1200us lo
//m1, m2 most significant bit first |m1-m2| <= 9
//chan: 01=C 10=B
//chk = 0 - chan -m1>>2 -m1 -m2>>2 -m2
//<= 500us Probleme
//>= 650us Probleme
//periode orig: 450ms

#define BITLEN (600u*2)
#define send_hilo_silv( hi, lo) _send_2( (hi)*BITLEN-1,(lo)*BITLEN-1 )

static void sendBitSilv(uint8_t val)
{
  // 0-Bit: 600us hi +  600us lo
  // 1-Bit:1200us hi + 1200us lo
  send_hilo_silv((val)?2:1,(val)?2:1);
}
static void send2BitsSilv(uint8_t val)
{
  sendBitSilv(val&2);sendBitSilv(val&1);
}
static void setupPulsesSilver(int8_t chan)
{

  if(chan) chan=3-chan; // A=0->0 B=1->2 C=2->1
  uint8_t m1 = getChan7u(0,4);
  uint8_t m2 = getChan7u(1,4);
  if (m2 > m1+9) m1=m2-9;
  if (m1 > m2+9) m2=m1-9;
  send_hilo_silv(5,1); //idx 0 erzeugt pegel=0 am Ausgang, wird  als high gesendet
  send2BitsSilv(0);
  send_hilo_silv(2,1);
  send_hilo_silv(2,1);

  send2BitsSilv(chan); //chan 1=C 2=B 0=A?
  uint8_t sum = 0 - chan;
  
  send2BitsSilv(m1>>2); //m1
  sum-=m1>>2;
  send2BitsSilv(m1);
  sum-=m1;

  send2BitsSilv(m2>>2); //m2
  sum-=m2>>2;
  send2BitsSilv(m2);
  sum-=m2;

  send2BitsSilv(sum); //chk

  send_hilo_silv(1,50);


}



/*
http://www.sourcinggate.com/ctp-1009-metal-proportional-coaxial-electric-rc-helicopters-mode-p-6725.html
  TRACE CTP-1009  
   - = send 45MHz  
   _ = send nix
    start1       0      1           start2
  -------__     --_    -__         -----__
   7ms   2     .8 .4  .4 .8         5   2 

 frame:
  start1  24Bits_1  start2  24_Bits2 

 24Bits phase1:
  7 x Bits  Throttle lsb first
  1 x 0

  6 x Bits  rotate lsb first
  1 x Bit   1=rechts
  1 x 0

  4 x Bits  chk5 = nib2 ^ nib4
  4 x Bits  chk6 = nib1 ^ nib3

 24Bits phase2:
  7 x Bits  Vorwaets lsb first 0x3f = mid
  1 x 1

  7 x Bits  0x0e lsb first
  1 x 1

  4 x Bits  chk5 = nib2 ^ nib4
  4 x Bits  chk6 = nib1 ^ nib3

 */

#define BIT_TRA (400u*2)
static void sendBitTra(uint8_t val)
{
  if(val) _send_2( BIT_TRA*1-1 , BIT_TRA*2-1 );
  else    _send_2( BIT_TRA*2-1 , BIT_TRA*1-1 );
}
static void sendByteTra(uint8_t val)
{
  for(uint8_t i=0; i<8; i++, val>>=1) sendBitTra(val&1);
}
static void setupPulsesTracerCtp1009()
{
  static bool phase;
  if( (phase=!phase) ){
    uint8_t thr = getChan7u(0,7);
    int8_t  rot = getChan7s(1,7);
    if(rot<0) rot = -rot | 0x40;
//     }
    //printf("thr %02x  rot %02x\n",thr,rot);
    sendByteTra(thr);
    sendByteTra(rot);
    uint8_t chk=thr^rot;
    sendByteTra( (chk>>4) | (chk<<4) );
    _send_2( 5000*2-1, 2000*2-1 );
  }else{
    //uint8_t fwd = min(127u,(uint16_t)(g_chans512[2]+512) /  8u) | 0x80;
    uint8_t fwd = getChan7u(2,7) | 0x80;
    //printf("fwd %02x \n",fwd);
    sendByteTra(fwd);
    sendByteTra(0x8e);
    uint8_t chk=fwd^0x8e;
    sendByteTra( (chk>>4) | (chk<<4) );
    _send_2( 7000*2-1, 2000*2-1 );
  }
}

//http://www.rclineforum.de/forum/board49-zubeh-r-elektronik-usw/fernsteuerungen-sender-und-emp/neuer-9-kanal-sender-f-r-70-au/Beitrag_3897736#post3897736
//(dsm2( LP4DSM aus den RTF ( Ready To Fly ) Sendern von Spektrum.
//http://www.rcgroups.com/forums/showpost.php?p=18554028&postcount=237
// /home/thus/txt/flieger/PPMtoDSM.c
/*
  125000 Baud 8n1      _ xxxx xxxx - ---
#define DSM2_CHANNELS      6                // Max number of DSM2 Channels transmitted
#define DSM2_BIT (8*2)  
bind:
  DSM2_Header = 0x80,0
static byte DSM2_Channel[DSM2_CHANNELS*2] = {
                ch
  0x00,0xAA,     0 0aa
  0x05,0xFF,     1 1ff
  0x09,0xFF,     2 1ff
  0x0D,0xFF,     3 1ff
  0x13,0x54,     4 354
  0x14,0xAA      5 0aa 
};

normal:
  DSM2_Header = 0,0;
  DSM2_Channel[i*2]   = (byte)(i<<2) | highByte(pulse);
  DSM2_Channel[i*2+1] = lowByte(pulse);


 */

#define BITLEN_DSM2 (8*2) //125000 Baud
static void sendByteDsm2(uint8_t b) //max 10changes 0 10 10 10 10 1
{
  bool    lev = 0;
  uint8_t len = BITLEN_DSM2; //max val: 9*16 < 256
  //printf("%02x,",b);
  //if(b==0) printf("\n");
  for( uint8_t i=0; i<=8; i++){ //8Bits + Stop=1
    bool nlev = b & 1; //lsb first
    if(lev == nlev){
      len += BITLEN_DSM2;
    }else{
      //*pulses2MHzPtr++ = len -1;
      _send_1(len -1);
      len  = BITLEN_DSM2;
      lev  = nlev;
    }
    b = (b>>1) | 0x80; //shift in stop bit
  }
  _send_1(len + 10*BITLEN_DSM2 -1); //some more space-time for security
}


static void setupPulsesDsm2(uint8_t chns)
{
  static uint8_t dsmDat[2+6*2]={0x80,0,  0x00,0xAA,  0x05,0xFF,  0x09,0xFF,  0x0D,0xFF,  0x13,0x54,  0x14,0xAA};

  static uint8_t state = 0;

  if(state==0){
    
    if((dsmDat[0] == 0) || ! keyState(SW_Trainer) ){
      dsmDat[0]=0; dsmDat[1]=0;  //DSM2_Header = 0,0;
      for(uint8_t i=0; i<chns; i++){
        uint16_t pulse = limit(0, g_chans512[i]+512,1023);
        dsmDat[2+2*i] = (i<<2) | ((pulse>>8)&0x03);
        dsmDat[3+2*i] = pulse & 0xff;
      }
    }
  }
  sendByteDsm2(dsmDat[state++]);
  sendByteDsm2(dsmDat[state++]);
  if(state >= 2+chns*2){
    pulses2MHzPtr-=3; //remove last stopbits and 
    _send_1(20000u*2 -1); //prolong them
    state=0;
  }
}


// swift V-Max 3-Kanal Heli mit Gyro/Kreisel
//http://www.rclineforum.de/forum/board49-zubeh-r-elektronik-usw/fernsteuerungen-sender-und-emp/neuer-9-kanal-sender-f-r-70-au/Beitrag_3893851#post3893851
//http://www.rclineforum.de/forum/index.php?page=ExternalLink&url=aHR0cDovL3d3dy5yYy1kaXNjb3VudC5kZS9zdG9yZS9wcm9kdWN0X2luZm8ucGhwL3Byb2R1Y3RzX2lkLzEwOTAvcHJvZHVjdC9zd2lmdC12LW1heC0zLWthbmFsLWhlbGktbWl0LWd5cm8va3JlaXNlbC5odG1s
// http://dangerousprototypes.com/forum/viewtopic.php?f=56&t=1822
/* ~/txt/flieger/protokolle/at25ppm2ir-swift.c
Example frame captured during the initial analysis. 
It begins with a preamble ( high level for 3,6ms then low level for 1ms),
then 32 data bits each taking 1ms and coded by pulse length 
"1" - 0,3ms high & 0,7ms low, a 
"0" - 0,7ms high & 0,3ms low). 
The last bit is the stop bit "1".




Promix Messung tiny: 28 Pules/30ms  gap~27.5ms
tiny code
00000000
00001111
10011100
11111010
1

thus code: 30 Pules/30ms
00111100
11110000
11100001
11011100
1


MSB transmitted first
--|--B3--------------
31| 0 fixed
30| MSB throttle
29| ...
28| ...
27| ...
26| ...
25| ...
24| LSB throttle
--|--B2--------------
23| MSB rudder
22| ...
21| ...
20| LSB rudder
19| MSB forward/backward
18| ...
17| ...
16| LSB forward/backward
--|--B1--------------
15| FLAG 1 - rudder left, 0 - rudder right
14| FLAG 1 - backward, 0 - forward
13| FLAG 1 - trim left, 0 - trim right
12| MSB trim
11| ...
10| ...
09| ...
08| LSB trim
--|--B0--------------
07| MSB CHANNEL, A - 11
06| LSB CHANNEL
05| MSB CRC
04| ...
03| ... CRC = (0x0F + B3 + B2 + B1) & 0x3F
02| ...
01| ...
00| LSB CRC
--|------------------

38KHz Traeger ~ 13us/halfper
    preamble       "1"   "0"      stop="1"  next ppm
   3.6ms  1ms    .3 .7   .7 .3    .3         27.5ms?  2.4ms?
   ------_____    -__    ---_      -__      _________

0.3ms ~ 22.8 halfs 23
0.7ms ~ 53.2 halfs 53
*/
#define LEN_38KHZ (13*2) //= 38,46KHz
#define HALFS_1    23     //high-len of 1-bit
#define HALFS_0    53     //high-len of 0-bit
#define HALFS_FULL 76
static void setupPulsesHeliSwift(uint8_t chan)
{ 
  static uint8_t state = 0;
  static uint8_t values[4];
  bool mod38=true;
  if(chan>=3){mod38=false;chan-=3;}
  if(state==0){
    if(mod38){
      _send_rep1(13*2-1,200);
      _send_rep1(13*2-1,75); //276*13us=3.6 ms
    }else{
      _send_1(13*275*2-1);   //3.6 ms
    }
    _send_1(1013*2-1);   //1 ms
    uint8_t heli_throttle  = getChan7u(2,7);
    values[3] = heli_throttle;// & 0x7F;
    int8_t  heli_rudder    = getChan7s(0,5);
    int8_t  heli_elevator  = getChan7s(1,5);
    int8_t  heli_trim      = getChan7s(3,6);
    //printf("heli_throttle%d heli_rudder%d heli_elevator%d heli_trim%d\n",heli_throttle,heli_rudder,heli_elevator,heli_trim);
    //values[2] = ((abs(heli_rudder) & 0x0F) << 4) | (abs(heli_elevator) & 0x0F);
    values[2] = (abs(heli_rudder) << 4) | abs(heli_elevator);
    //values[1] = ((heli_rudder <= 0) ? 0x80 : 0) | ((heli_elevator >= 0) ? 0x40 : 0) | ((heli_trim < 0) ? 0x20 : 0) | (abs(heli_trim) & 0x1F);
    values[1] = ((heli_rudder < 0) ? 0x80 : 0) | ((heli_elevator < 0) ? 0x40 : 0) | ((heli_trim < 0) ? 0x20 : 0) | abs(heli_trim);
    values[0] = ((15 + values[3] + values[2] + values[1]) & 0x3F) | (chan^3)<<6;
    state++;
  }else if(state<=32){ //1..32 bit 33=stopbit
    uint8_t idx = 32-state;
    if(values[idx/8] & (1<<(idx%8))){
      //       //0.3ms ~ 22.8 halfs 23 13us=26-1
      //       //0.7ms ~ 53.2 halfs 53 13us=26-1
      if(mod38) _send_rep1(LEN_38KHZ-1,HALFS_1);
      else      _send_1(LEN_38KHZ*HALFS_1-1);
      _send_1   (LEN_38KHZ*(HALFS_FULL-HALFS_1)-1);
    }else{
      //       //0.7ms ~ 53.2 halfs 53 13us=26-1
      //       //0.3ms ~ 22.8 halfs 23 13us=26-1
      if(mod38) _send_rep1(LEN_38KHZ-1,HALFS_0);
      else      _send_1(LEN_38KHZ*HALFS_0-1);
      _send_1   (LEN_38KHZ*(HALFS_FULL-HALFS_0)-1);
    }
    state++;
    // 
  }else if(state==33){
    if(mod38) _send_rep1(LEN_38KHZ-1,HALFS_1); //stop 1
    else      _send_1(LEN_38KHZ*HALFS_1-1); //stop 1
    _send_1   (27500u*2-1);  //27.5ms //+2400us
    state=0;
  }
}



//picco z
//http://home.versanet.de/~b-konze/uni_fb/uni_fb.htm
// /home/husteret/txt/flieger/protokolle/m168fb_ufo_v08/picooz.c
//
// 1900  650 650         1226             650       1226           Stop
// ----   __  -- __ -- __----__----__     --__      ----____       --__
/*
  chn:2 a=00 b=01 c=10
  pow:4u msb first
  trim:4s  -2,0,1
  direction:3s
  -chk[0]
  -chk[1]
  0
-------
2-bit sum = 0

chk:2 = chn:2 + pow>>2:2 +pow:2 +  trim>>2:2 +trim:2 dir + direction>>1:2 + direction<<1:2

 */

#define PICOOZ_RC_HIGH	 93 //(1226/13)
#define PICOOZ_RC_LOW	 49 //(650/13)

void picco_sendB1(bool bit)
{
  if(bit){
    _send_rep1(LEN_38KHZ-1, PICOOZ_RC_HIGH);     //ungerade anzahl 10101
    _send_1   (1226*2 - 1);   //lange 0
  }else{
    _send_rep1(LEN_38KHZ-1, PICOOZ_RC_LOW);      //ungerade anzahl 10101
    _send_1   (650*2  - 1);   //lange 0
  }
}
void picco_sendBn(uint8_t bits, uint8_t n)
{
  while(n--) picco_sendB1(bits & (1<<n));
}

static void setupPulsesPiccoZ(uint8_t chn)
{
  // 1900  650 650         1226             650 0bit  1226 1bit      Stop
  // ----   __  -- __ -- __----__----__     --__      ----____       --__
  static bool    state = 0;
  static uint8_t pow;
  static int8_t  trim;
  static int8_t  dir;
  static uint8_t chk;
  if(state == 0)  {
    _send_rep1(LEN_38KHZ-1, 147);   // 1900/13  !! must be odd
    _send_1   (650*2 - 1);//
    picco_sendBn(0,2);
    _send_rep1(LEN_38KHZ-1, PICOOZ_RC_HIGH);
    _send_1   (650*2 - 1);//
    _send_rep1(LEN_38KHZ-1, PICOOZ_RC_HIGH);
    _send_1   (650*2 - 1);//
    //   chn:2 a=00 b=01 c=10
    //   pow:4u msb first
    //   trim:4s  -2,0,1
    //   dir:3s
    //   -chk[0]
    //   -chk[1]
    //   0
    pow  = getChan7u(2,4);
    trim = getChan7s(1,4);
    dir  = getChan7s(0,3);
    chk    = - (chn+ (pow>>2) + pow + (trim>>2) + trim + (dir>>1) + (dir<<1));
  }else{
    picco_sendBn(chn,2);
    picco_sendBn(pow,4);
    picco_sendBn(trim,4);
    picco_sendBn(dir,3);
    picco_sendB1(chk & (1<<0)); //lsb first, because we are here on a odd bit (dir is only 3 bits)
    picco_sendB1(chk & (1<<1));
    _send_rep1(LEN_38KHZ-1, PICOOZ_RC_LOW); //0-bit pulses
    _send_1   (20000u*2  - 1); //20ms gap ?
  }
  state = !state;
}






void setupPulses() 
{
  uint8_t  stbyLevel     = 1; //default
  pulses2MHzPtr = pulses2MHz;
  //  uint16_t* ret = pulses2MHz;
  switch(g_model.protocol)
  {
    case PROTO_SILV:         // Achtung !! 0 am Ausgang = sendesignal high
      setupPulsesSilver(g_model.protocolPar);
      break;
    case PROTO_TRACER_CTP1009: // Achtung !! 0 am Ausgang = sendesignal high
      setupPulsesTracerCtp1009();
      break;
    case PROTO_SILV_PICCOZ:
      setupPulsesPiccoZ(g_model.protocolPar);
      stbyLevel=0; //start with 1
       break;
    case PROTO_HELI_SWIFT:
      setupPulsesHeliSwift(g_model.protocolPar);
      stbyLevel=0; //start with 1
      break;
    case PROTO_DSM2_6:
      setupPulsesDsm2(6);
      break;
    case PROTO_PPM:
    default:
      setupPulsesPPM();
      break;
  }
  uint16_t n=pulses2MHzPtr-pulses2MHz;
  if( n > DIM(pulses2MHz)) alert(PSTR("pulse tab overflow"));
  pulses2MHzPtr[-1] = CTRL_END;


#ifdef xSIM
  static int s_cnt;
  if(s_cnt++%100==0){
    //if(s_cnt++<40){
    uint8_t *p=pulses2MHz;
    bool lev = (stbyLevel&1)^1;
    while(1){
      uint16_t val=*(*(uint16_t**)&p)++;
      int8_t   ctl=*p++;
      printf(" %d:%d",lev,val);
      if(ctl<0){
	uint8_t   cnt=*p++;
// 	if(--cnt){
// 	  *--p=cnt;
//           p+=ctl;
// 	  printf("r");
// 	}else{
// 	  printf("R");
// 	  ctl=*p++;
// 	}
        printf("x%d,r=%d",cnt,-ctl/3);
        if(((ctl/3 * cnt)&1) == 0) lev=!lev;
        ctl=*p++;
      }
      if(ctl==0) break;
      lev=!lev;
    }    

    printf("f\n\n");
  }
#endif
  if( stbyLevel&1 ) { //start with 0
    PORTB |=  (1<<OUT_B_PPM);
  }else{
    PORTB &= ~(1<<OUT_B_PPM);
  }

  //return pulses2MHz;
}








