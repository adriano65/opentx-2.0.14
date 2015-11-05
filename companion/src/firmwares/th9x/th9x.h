/*
 * Author	Thomas Husterer <thus1@t-online.de>
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
#ifndef th9x_h
#define th9x_h


// #define WITH_ADC_STAT

#define VERS 1

#include <inttypes.h>
#include <string.h>
#ifdef SIM
  #include "simpgmspace.h"
  #define APM
  #include "stdio.h"
#else
///opt/cross/avr/include/avr/pgmspace.h
  #include <stdio.h>
  #define printf(...)
  #include <stddef.h>
  #include <avr/io.h>
  #define assert(x)
  //disable whole pgmspace functionality for all avr-gcc because
  //avr-gcc > 4.2.1 does not work anyway
  //http://www.mail-archive.com/gcc-bugs@gcc.gnu.org/msg239240.html
  //http://gcc.gnu.org/bugzilla/show_bug.cgi?id=34734
  //
  //Workarounds:
  //
  //PSTR is fixed below
  //all prog_xx definitions must use APM explicitely

  //#define __ATTR_PROGMEM__   
  #include <avr/pgmspace.h>
  #ifdef __cplusplus
    #define APM __attribute__(( section(".progmem.data") ))
    #undef PSTR
    #define PSTR(s) (__extension__({static prog_char APM __c[] = (s);&__c[0];}))
  #endif

  #include <avr/eeprom.h>
  #include <avr/sleep.h>
  #include <avr/interrupt.h>
  #define F_CPU 16000000UL  // 16 MHz
  #include <util/delay.h>
  #define pgm_read_adr(address_short) pgm_read_word(address_short)
  #include <avr/wdt.h>
#endif
//#define eeprom_write_block eeWriteBlockCmp

#include "file.h"
//
//                  elev                        thr 
//                   LV                         RV
//                 2 ^                        4 ^
//                   1                          2
//                   |     rudd                 |     aile
//              <----X--3-> LH             <----X--0-> RH
//              6    |    7                1    |    0
//                   |                          |
//                 3 v                        5 v
//


//PORTA  7      6       5       4       3       2       1       0
//       O      O       O       O       O       O       O       O
//       ------------------------ LCD_DAT -----------------------
// 
//PORTB  7      6       5       4       3       2       1       0
//       O      i       i       i       i       i       i       O   
//       light  KEY_LFT KEY_RGT KEY_UP  KEY_DWN KEY_EXT KEY_MEN  PPM
// 
//PORTC  7      6       5       4       3       2       1       0
//       -      -       O       O       O       O       O       -
//       NC     NC    LCD_E   LCD_RNW  LCD_A0  LCD_RES LCD_CS1  NC
// 
//PORTD  7      6       5       4       3       2       1       0
//       i      i       i       i       i       i       i       i
//     TRM_D_DWN _UP  TRM_C_DWN _UP   TRM_B_DWN _UP   TRM_A_DWN _UP      
// 
//PORTE  7      6       5       4       3       2       1       0
//       i      i       i       i       O       i       i       i
//     PPM_IN  ID2    Trainer  Gear   Buzzer   ElevDR  AileDR  THRCT
// 
//PORTF  7      6       5       4       3       2       1       0
//       ai     ai      ai      ai      ai      ai      ai      ai 
// ANA_ BAT   PITT_TRM HOV_THR HOV_PIT  STCK_LH STCK_RV STCK_LV STCK_RH
//                                      rud    thro   elev   aile
//PORTG  7      6       5       4       3       2       1       0
//       -      -       -       O       i               i       i
//                            SIM_CTL  ID1      NC      RF_POW RuddDR

#define PORTA_LCD_DAT  PORTA
#define OUT_B_LIGHT   7
#define INP_B_KEY_LFT 6
#define INP_B_KEY_RGT 5
#define INP_B_KEY_UP  4
#define INP_B_KEY_DWN 3
#define INP_B_KEY_EXT 2
#define INP_B_KEY_MEN 1
#define OUT_B_PPM 0
#define PORTC_LCD_CTRL PORTC
#define OUT_C_LCD_E     5
#define OUT_C_LCD_RnW   4
#define OUT_C_LCD_A0    3
#define OUT_C_LCD_RES   2
#define OUT_C_LCD_CS1   1

#define INP_D_TRM_LH_UP   7
#define INP_D_TRM_LH_DWN  6
#define INP_D_TRM_RV_DWN  5
#define INP_D_TRM_RV_UP   4
#define INP_D_TRM_LV_DWN  3
#define INP_D_TRM_LV_UP   2
#define INP_D_TRM_RH_DWN  1
#define INP_D_TRM_RH_UP   0

#define INP_E_PPM_IN  7
#define INP_E_ID2     6
#define INP_E_Trainer 5  
#define INP_E_Gear    4
#define OUT_E_BUZZER  3
#define INP_E_ElevDR  2 
#define INP_E_AileDR  1 
#define INP_E_ThrCt   0

#define OUT_G_SIM_CTL  4 //1 : phone-jack=ppm_in
#define INP_G_ID1      3
#define INP_G_RF_POW   1
#define INP_G_RuddDR   0


//convert from mode 1 to mode g_eeGeneral.stickMode
//NOTICE!  =>  1..4 -> 1..4
uint8_t convertMode(uint8_t srcChn);

#define THRCHN (2-(g_eeGeneral.stickMode&1)) //stickMode=0123 -> thr=2121
//#define THRCHN convertMode(SRC_THR)
int8_t  idx2val15_100(int8_t idx);
int8_t  val2idx15_100(int8_t val);
int8_t  idx2val30_100(int8_t idx);
int8_t  val2idx30_100(int8_t val);
int16_t idx2val50_150(int8_t idx);
int16_t idx2val50_150_512(int8_t idx);
int8_t  val2idx50_150(int16_t val);




enum EnumKeys {
  KEY_MENU=0 ,
  KEY_EXIT ,
  KEY_DOWN ,
  KEY_UP  ,
  KEY_RIGHT ,
  KEY_LEFT ,
  TRM_LH_DWN  ,
  TRM_LH_UP   ,
  TRM_LV_DWN  ,
  TRM_LV_UP   ,
  TRM_RV_DWN  ,
  TRM_RV_UP   ,
  TRM_RH_DWN  ,
  TRM_RH_UP   ,
  SW_ThrCt  ,
  SW_RuddDR ,
  SW_ElevDR ,
  SW_ID0    ,
  SW_ID1    ,
  SW_ID2    ,
  SW_AileDR ,
  SW_Gear   ,
  SW_Trainer 
};
#define SW_BASE      SW_ThrCt
#define SW_BASE_DIAG SW_ThrCt
//see SWITCHES_STR
//real switches
#define MAX_DRSWITCH_R  (9)
#define MIN_DRSWITCH_R -(9)
//real + virtual switches
#define MAX_DRSWITCH    (17)
#define MIN_DRSWITCH   -(14)
#define SWITCHES_STR "THR""RUD""ELE""ID0""ID1""ID2""AIL""GEA""TRN""SW1""SW2""SW3""SW4""SW5""SW6""SW7""SW8"

// 0                                                10
// nc "THR""RUD""ELE""ID0""ID1""ID2""AIL""GEA""TRN" on
//    "THR""RUD""ELE""ID0""ID1""ID2""AIL""GEA""TRN" off

// 0                                       8                            15  -16 -15
// on "THR""RUD""ELE""ID0""ID1""ID2""AIL""GEA""TRN" SW1 SW2 SW3 SW4 SW5 SW6 SW7 SW8
//    "THR""RUD""ELE""ID0""ID1""ID2""AIL""GEA""TRN" SW1 SW2 SW3 SW4 SW5
//
// op2   x  < <= = != > >=  y
//

// dst:3 1..8
// op2:2  = pos neg
// op1:2  < <= = !=
// src1:5
// src2:5 imm?

#define NUM_KEYS TRM_RH_UP+1
#define TRM_BASE TRM_LH_DWN

#define _MSK_KEY_REPT    0x40
#define _MSK_KEY_FIRST   0x20
#define IS_KEY_BREAK(evt)  (((evt)&0xf0)        ==                 _MSK_KEY_FIRST)
#define IS_KEY_FIRST(evt)  (((evt)&0xf0)        ==  (_MSK_KEY_REPT|_MSK_KEY_FIRST))
#define IS_KEY_REPT(evt)   ( (evt)&                  _MSK_KEY_REPT)
#define EVT_KEY_BREAK(key) ((key)|                                 _MSK_KEY_FIRST)
#define EVT_KEY_FIRST(key) ((key)|                   _MSK_KEY_REPT|_MSK_KEY_FIRST)
#define EVT_KEY_REPT(key)  ((key)|                   _MSK_KEY_REPT     )
#define EVT_KEY_LONG(key)  ((key)|0x80)
//#define EVT_KEY_DBL(key)   ((key)|_MSK_KEY_DBL)
//#define EVT_KEY_DBL(key)   ((key)|0x10)
#define EVT_ENTRY               (0xff - _MSK_KEY_REPT)
#define EVT_ENTRY_UP            (0xfe - _MSK_KEY_REPT)
#define EVT_EXIT                (0xfd - _MSK_KEY_REPT)
#define EVT_TYPE_MASK            0xf0
#define EVT_KEY_MASK             0x0f



//number of virtual output/input channels X1..X4
#define NUM_VIRT     4
//number of real outputchannels CH1-CH8
#define NUM_CHNOUT   8
///number of real output channels (CH1-CH8) plus virtual output channels X1-X4
#define NUM_XCHNOUT (NUM_CHNOUT+NUM_VIRT)
///number of real input channels (1-9) plus virtual input channels X1-X4
#define NUM_XCHNRAW (7+3+2+  NUM_VIRT + 8 +8)

#define DST_CH1  0 //..CH8
#define DST_X1   8 //..X4

#define SRC_RUD  0
#define SRC_ELE  1
#define SRC_THR  2
#define SRC_AIL  3
#define SRC_P1   4
#define SRC_P2   5
#define SRC_P3   6
#define SRC_p1   7
#define SRC_p2   8
#define SRC_p3   9
#define SRC_MAX 10
#define SRC_CUR 11
#define SRC_CH1 12 //..CH8
#define SRC_X1  20 //..X4
#define SRC_T1  24 //..T8
#define SRC_STR "RUD\t""ELE\t""THR\t""AIL\t"\
                " P1\t"" P2\t"" P3\t"\
                " p1\t"" p2\t"" p3\t"\
                "MAX\t""CUR\t"\
                "CH1\t""CH2\t""CH3\t""CH4\t" \
                "CH5\t""CH6\t""CH7\t""CH8\t" \
                " X1\t"" X2\t"" X3\t"" X4\t" \
                " T1\t"" T2\t"" T3\t"" T4\t" \
                " T5\t"" T6\t"" T7\t"" T8\t" \


#define TMRMODE_NONE     0
#define TMRMODE_ABS      1
#define TMRMODE_THR      2
#define TMRMODE_THR_REL  3
#define MAX_ALERT_TIME   30


#define PROTO_PPM            0
#define PROTO_SILV           1 //ABC
#define PROTO_TRACER_CTP1009 2
#define PROTO_SILV_PICCOZ    3 //ABC
#define PROTO_HELI_SWIFT     4 //ABC
#define PROTO_DSM2_6         5
#define PROT_MAX             5
#define PROT_STR "PPM\tSILV\tTRAC09\tPICZ\tSWIFT\tDSM2\t"



typedef void (*MenuFuncP)();


extern uint8_t g_event;
void slowEvents(uint8_t event);
/// stoppt alle events von dieser taste bis eine kurze Zeit abgelaufen ist
void pauseEvents(uint8_t enuk);
/// liefert die Zahl der schnellen Wiederholungen dieser Taste
uint8_t getEventDbl(uint8_t event);
/// stoppt alle events von dieser taste bis diese wieder losgelassen wird
void    killEvents();
void    killEventsRaw(uint8_t event);
/// liefert den Wert einer beliebigen Taste KEY_MENU..SW_Trainer
bool    keyState(EnumKeys enuk);
/// Liefert das naechste Tasten-Event, auch trim-Tasten.
/// Das Ergebnis hat die Form:
/// EVT_KEY_BREAK(key), EVT_KEY_FIRST(key), EVT_KEY_REPT(key) oder EVT_KEY_LONG(key)
uint8_t getEvent();

/// goto given Menu, but substitute current menu in menuStack
void    chainMenu(MenuFuncP newMenu);
/// goto given Menu, store current menu in menuStack
void    pushMenu(MenuFuncP newMenu);
///deliver address of last menu which was popped from
MenuFuncP lastPopMenu();
/// return to last menu in menustack
/// if uppermost is set true, thenmenu return to uppermost menu in menustack
void    popMenu(bool uppermost=false);
/// Gibt Alarm Maske auf lcd aus. 
/// mode==0:
/// Die Maske wird so lange angezeigt bis eine beliebige Taste gedrueckt wird.
/// mode==1:
/// Die Maske wird angezeigt.
/// mode==2:
/// Tastendruck wird geprüft. :
/// return: false wenn Taste gedrückt wurde.
bool    alert(const prog_char * s, uint8_t mode=0);

///common init for simu and target
void    init();
/// periodisches Hauptprogramm
void    perMain();
/// Bearbeitet alle zeitkritischen Jobs.
/// wie z.B. einlesen aller Eingaenge, Entprellung, Key-Repeat..
void    per10ms();
void    perChecks();
/// Erzeugt periodisch alle Outputs ausser Bildschirmausgaben.
void perOut(int16_t *chanOut);
///   Liefert den Zustand des Switches 'swtch'. Die Numerierung erfolgt ab 1
///   (1=SW_ON, 2=SW_ThrCt, 10=SW_Trainer). 0 Bedeutet not conected.
///   Negative Werte  erzeugen invertierte Ergebnisse.
///   Die Funktion putsDrSwitches(..) erzeugt den passenden Ausdruck.
///   
///   \param swtch
///     0                : not connected. Liefert den Wert 'nc'
///     1.. MAX_DRSWITCH : SW_ON .. SW_Trainer
///    -1..-MAX_DRSWITCH : negierte Werte
///   \param nc Wert, der bei swtch==0 geliefert wird.
bool    getSwitch(int8_t swtch, bool nc);
/// Zeigt den Namen des Switches 'swtch' im display an
///   \param x     x-koordinate 0..127 
///   \param y     y-koordinate 0..63 (nur durch 8 teilbar)
///   \param swtch -MAX_DRSWITCH ..  MAX_DRSWITCH
///   \param att   NO_INV,INVERS,BLINK
///
void putsDrSwitches(uint8_t x,uint8_t y,int8_t swtch,uint8_t att);


void checkMem();
void setTHR0pos();
void checkTHR();
///   Pr�ft beim Einschalten ob alle Switches 'off' sind.
void    checkSwitches();
uint8_t checkLastSwitch(uint8_t sw,uint8_t flg);


/// Bearbeite alle events die zum gewaehlten mode passen.
/// KEY_LEFT u. KEY_RIGHT
/// oder KEY_UP u. KEY_DOWN falls _FL_VERT in i_flags gesetzt ist.
/// Dabei wird der Wert der Variablen i_pval unter Beachtung der Grenzen
/// i_min und i_max veraendet.
/// i_pval hat die Groesse 1Byte oder 2Bytes falls _FL_SIZE2  in i_flags gesetzt ist
/// falls EE_GENERAL oder EE_MODEL in i_flags gesetzt ist wird bei Aenderung
/// der Variablen zusaetzlich eeDirty() aufgerufen.
/// Als Bestaetigung wird beep() aufgerufen bzw. beepWarn() wenn die Stellgrenze erreicht wird.
bool checkIncDecGen2( void *i_pval, int16_t i_min, int16_t i_max, uint8_t i_flags);

///Hilfs-template zum Speichersparenden Aufruf von checkIncDecGen2
template<int16_t min,int16_t max>
bool checkIncDecModVar( void*p, uint8_t flags)
{
  return checkIncDecGen2( p, min, max, flags);
}


///Hilfs-funktion zum Aufruf von checkIncDecGen2 fuer bitfield Variablen
int8_t checkIncDec_hm( int8_t i_val, int8_t i_min, int8_t i_max);
///Hilfs-funktion zum Aufruf von checkIncDecGen2 fuer bitfield Variablen
int8_t checkIncDec_vm( int8_t i_val, int8_t i_min, int8_t i_max);
///Hilfs-funktion zum Aufruf von checkIncDecGen2 fuer bitfield Variablen
int8_t checkIncDec_hg( int8_t i_val, int8_t i_min, int8_t i_max);
///Hilfs-funktion zum Aufruf von checkIncDecGen2 fuer bitfield Variablen
int8_t checkIncDec_vg( int8_t i_val, int8_t i_min, int8_t i_max);

extern bool    checkIncDec_Ret;//global helper vars

#define _FL_SIZE2     4
#define _FL_VERT      8
#define _FL_POSNEG 0X10

#define CHECK_INCDEC_H_GENVAR( var, min, max)     \
  checkIncDecModVar<min,max>(&var,(sizeof(var)==2 ? _FL_SIZE2 : 0)|EE_GENERAL) \

#define CHECK_INCDEC_H_MODELVAR( var, min, max)     \
  checkIncDecModVar<min,max>(&var,(sizeof(var)==2 ? _FL_SIZE2 : 0)|EE_MODEL) \


//#define CHECK_INCDEC_V_MODELVAR( event, var, min, max)                
//  checkIncDecModVar<min,max>(event,&var,(sizeof(var)==2 ? _FL_SIZE2 : 0)|_FL_VERT|EE_MODEL) 

//for bitfields
#define CHECK_INCDEC_H_GENVAR_BF( var, min, max)               \
  ( var=checkIncDec_hg(var,min,max),                              \
    checkIncDec_Ret                                                     \
  )
#define CHECK_INCDEC_H_MODELVAR_BF( var, min, max)               \
  ( var=checkIncDec_hm(var,min,max),                              \
    checkIncDec_Ret                                                     \
  )
#define CHECK_INCDEC_V_MODELVAR_BF( var, min, max)               \
  ( var=checkIncDec_vm(var,min,max),                              \
    checkIncDec_Ret                                                     \
  )
//#define CHECK_INCDEC_V_MODELVAR_BF( event, var, min, max)             
//  ( var=checkIncDec_vm(event,var,min,max),                              
//    checkIncDec_Ret                                                     
//  )

#define CHECK_LAST_SWITCH( var, flg)                                    \
   var=checkLastSwitch(var,flg)
  


#define STORE_MODELVARS eeDirty(EE_MODEL)





/// liefert Dimension eines Arrays
#define DIM(arr) (sizeof((arr))/sizeof((arr)[0]))

#ifndef NOINLINE
#define NOINLINE __attribute__ ((noinline))
#endif

/// liefert Betrag des Arguments
template<class t> inline t abs(t a){ return a >  0 ? a : (t)-a; }
/// liefert das Minimum der Argumente
template<class t> inline t min(t a, t b){ return a<b?a:b; }
/// liefert das Maximum der Argumente
template<class t> inline t max(t a, t b){ return a>b?a:b; }

template<class t> inline t limit(t mi, t x, t ma){ return min(max(mi,x),ma); }


#define MAX(a,b) (a>b?a:b)
template<class t> inline int8_t sgn(t a){ return a>0 ? 1 : (a < 0 ? (t)-1 : (t)0); }
int8_t add7Bit(int8_t a,int8_t b);
void memswap(void *dest, const void *src, uint8_t n);


#define EE_GENERAL 1
#define EE_MODEL   2
/// Markiert einen EEPROM-Bereich als dirty. der Bereich wird dann in
/// eeCheck ins EEPROM zurueckgeschrieben.
void eeWriteBlockCmp(const void *i_pointer_ram, void *i_pointer_eeprom, size_t size);
void eeDirty(uint8_t msk);
void eeCheck(bool immediately=false);
//void eeWriteGeneral();
void eeReadAll();
void eeLoadModelName(uint8_t id,char*buf,uint8_t len);
void eeLoadModel(uint8_t id);
//void eeSaveModel(uint8_t id);
bool eeDuplicateModel(uint8_t id);


/// Schreibt [RUD ELE THR AIL P1 P2 P3 MAX] aufs lcd
void putsChnRaw(uint8_t x,uint8_t y,uint8_t idx1,uint8_t att);
//#define MAX_CHN 8

/// Schreibt [CH1 CH2 CH3 CH4 CH5 CH6 CH7 CH8] aufs lcd
void putsChn(uint8_t x,uint8_t y,uint8_t idx1,uint8_t att);
/// Schreibt die Batteriespannung aufs lcd
void putsVBat(uint8_t x,uint8_t y,uint8_t att);
void putsTime(uint8_t x,uint8_t y,int16_t tme,uint8_t att,uint8_t att2);


void menuProcLimits();
void menuProcMixOne();
void menuProcMix();
void menuProcCurve();
void menuProcTrim();
void menuProcExpoOne();
void menuProcExpoAll();
void menuProcModel();
void menuProcDiagCalib();
void menuProcDiagAna();
void menuProcDiagKeys();
void menuProcDiagVers();
void menuProcTrainer();
void menuProcSetup0();
void menuProcSetup1();
void menuProcSetup2();
void menuProcMain();
void menuProcModelSelect();

void menuProcStatistic2();
void menuProcStatistic();
void menuProc0();
void menuProcDisplayTest();

//extern "C" uint8_t* setupPulses();
extern "C" void setupPulses();
extern uint8_t  g_pulseLoopCnt; //only in ppm-mode

extern int16_t intpol(int16_t, uint8_t);

//extern uint16_t s_ana[8];
extern uint16_t anaIn(uint8_t chan);




//extern TrainerData g_trainer;
//extern uint16_t           g_anaIns[8];
extern uint8_t            g_vbat100mV;
extern volatile uint16_t  g_tmr10ms;
extern volatile uint16_t  g_tmr1s;
extern volatile uint8_t   g_blinkTmr10ms;
extern volatile uint8_t   g_nextBeep;

#define HEART_TIMER2Mhz 1;
#define HEART_TIMER10ms 2;

extern uint8_t            heartbeat;


extern int16_t            g_ppmIns[8];
extern uint8_t            g_virtSw[8];
extern int16_t            g_chans512[NUM_CHNOUT];
extern uint8_t            g_sumAna;
extern uint8_t            g_trainerSlaveActiveChns;
extern uint16_t           g_lightAct1s;
extern uint16_t           g_actTime1s;
extern uint16_t           g_badAdc,g_allAdc;

#ifdef WITH_ADC_STAT
extern uint16_t g_rawVals[7];
extern uint8_t  g_rawPos;
extern uint8_t  g_rawChan;
#endif


#include "lcd.h"
extern const char stamp1[];
extern const char stamp2[];
extern const char stamp3[];
extern const char stamp4[];
#include "myeeprom.h"
int8_t getTrimRaw(uint8_t iLog);
int8_t getTrimRawMode(uint8_t iLog);
void   setTrimRaw(uint8_t iLog,int8_t ival);

inline void _beep(uint8_t b) {
  g_nextBeep=b;
  printf("beep %d\n",b);
}

/// verschiedene beep varianten see drivers.cpp
#define beepKey()           _beep(1)
#define beepStore()         _beep(1)
#define beepWarnMax()       _beep(2)
#define beepTrim()          _beep(3)
#define beepTmr()           _beep(3)
#define beepBat()           _beep(3)
#define beepTmrLong()       _beep(4)
#define beepTmrDbl()        _beep(6)
#define beepWarnNoDup()     _beep(4)
#define beepTrim0()         _beep(4)
#define beepWarnInactive()  _beep(4)
#define beepErr()           _beep(5)


extern uint8_t modelMixerDefaults;
prog_char* modelMixerDefaultName(uint8_t typ);
void modelMixerDefault(uint8_t typ);


uint16_t getTmr16KHz();

int8_t trimRevert2(int16_t val);
inline int16_t trimExp2(int8_t trim)
{
  //0 1 3 6 10 15
  return trim*(abs(trim)+1)/2;
}
int8_t   trimRevertM(int16_t val, uint8_t tmode);
uint16_t trimExpMu(uint8_t atrim, uint8_t tmode);




void memswap(void *dest,const void*src,uint8_t len);

#endif



/*eof*/
