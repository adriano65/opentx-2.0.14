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
#ifndef eeprom_h
#define eeprom_h


//eeprom data
//#define EE_VERSION 2
#define MAX_MODELS 16
#define MAX_MIXERS 25
#define MAX_SWITCHES 16
#define MAX_EXPOS  15

#ifndef PACK
#define PACK( __Declaration__ ) __Declaration__ __attribute__((__packed__))
#endif

PACK(typedef struct t_TrainerData1_r0 {
  uint8_t srcChn:3; //0-7 = ch1-8
  int8_t  swtch:5;
  int8_t  studWeight:6;
  uint8_t mode:2;   //off,add-mode,subst-mode
}) TrainerData1_r0; //

PACK(typedef struct t_TrainerData_r0 {
  int16_t       calib[4];
  TrainerData1_r0  chanMix[4];
}) TrainerData_r0; //

PACK(typedef struct t_TrainerData_r192 {
  int16_t       calib[8]; //192: 4->8
  TrainerData1_r0  chanMix[4];
}) TrainerData_r192; //

#define GENVERS0 1
PACK(typedef struct t_EEGeneral_r0 {  //<r119
  uint8_t   myVers;
  int16_t   calibMid[4];
  int16_t   calibSpan[4];
  uint16_t  chkSum;
  uint8_t   currModel; //0..15
  uint8_t   contrast;
  uint8_t   vBatWarn;
  int8_t    vBatCalib;  
  int8_t    lightSw;
  TrainerData_r0 trainer; //
  uint8_t   view;     //index of subview in main scrren
  uint8_t   warnOpts; //bitset for several warnings
  uint8_t   stickMode;   // 1
}) EEGeneral_r0;//<r119;
#define GENVERS119   2
#define GENVERS119_3 3
PACK(typedef struct t_EEGeneral_r119 {
  uint8_t   myVers;
  int16_t   calibMid[4];
  int16_t   calibSpanNeg[4]; //ge119
  int16_t   calibSpanPos[4]; //ge119
  uint16_t  chkSum;
  uint8_t   currModel; //0..15
  uint8_t   contrast;
  uint8_t   vBatWarn;
  int8_t    vBatCalib; 
  int8_t    lightSw;
  TrainerData_r0 trainer;
  uint8_t   adcFilt:2;     // was view in earlier versions
  uint8_t   reserve:2;     // was view in earlier versions
  uint8_t   thr0pos:4;     // was view in earlier versions
  uint8_t   warnOpts:3; //bitset for several warnings
  uint8_t   beepVol:2;  //
  uint8_t   view:3;     //index of subview in main screen
  uint8_t   stickMode;   // 1
}) EEGeneral_r119;
#define GENVERS150   4
#define GENVERS150_5 5
PACK(typedef struct t_EEGeneral_r150 {
  uint8_t   myVers;
  int16_t   calibMid[7];             //ge150 4->7
  int16_t   calibSpanNeg[7]; //ge119 //ge150 4->7
  int16_t   calibSpanPos[7]; //ge119 //ge150 4->7
  //uint16_t  chkSum;
  uint8_t   inactivityMin;    //ge150
  uint8_t   resv;             //ge150
  uint8_t   currModel; //0..15
  uint8_t   contrast;
  uint8_t   vBatWarn;
  int8_t    vBatCalib; 
  int8_t    lightSw;
  TrainerData_r0 trainer;
  uint8_t   adcFilt:2;     // was view in earlier versions
  uint8_t   reserve:2;     // was view in earlier versions
  uint8_t   thr0pos:4;     // was view in earlier versions
  uint8_t   warnOpts:3; //bitset for several warnings
  uint8_t   beepVol:2;  //
  uint8_t   view:3;     //index of subview in main screen
  uint8_t   stickMode;   // 1
}) EEGeneral_r150;

#define GENVERS192   6
#define WARN_THR (!(g_eeGeneral.warnOpts & 0x01))
#define WARN_SW  (!(g_eeGeneral.warnOpts & 0x02))
#define WARN_MEM (!(g_eeGeneral.warnOpts & 0x04))
#define BEEP_VOL ( g_eeGeneral.beepVol )
#define NAVI_ADVANCED (g_eeGeneral.naviMode&1)
PACK(typedef struct t_EEGeneral_r192 {
  uint8_t   myVers;
  int16_t   calibMid[7];             //ge150 4->7
  int16_t   calibSpanNeg[7]; //ge119 //ge150 4->7
  int16_t   calibSpanPos[7]; //ge119 //ge150 4->7
  //uint16_t  chkSum;
  uint8_t   inactivityMin;    //ge150
  uint8_t   iTrimSwitch:4;    //ge192
  uint8_t   iTrimTme1:2;    
  uint8_t   iTrimTme2:2;    
  uint8_t   currModel; //0..15
  uint8_t   contrast;
  uint8_t   vBatWarn;
  int8_t    vBatCalib; 
  int8_t    lightSw;
  TrainerData_r192 trainer;
  uint8_t   adcFilt:2;     // was view in earlier versions
  uint8_t   keySpeed:2;     // was view in earlier versions
  uint8_t   thr0pos:4;     // was view in earlier versions
  uint8_t   warnOpts:3; //bitset for several warnings
  uint8_t   beepVol:2;  //
  uint8_t   view:3;     //index of subview in main screen

  uint8_t   stickMode:2;// 
  uint8_t   naviMode:2; //
}) EEGeneral_r192;
#define EEGeneral_TOP EEGeneral_r192
#define GENVERS_TOP GENVERS192


/////////////////////////////////////////////////////////////////////////////
//eeprom modelspec
/////////////////////////////////////////////////////////////////////////////


PACK(typedef struct t_SwitchData_r204 {
  uint8_t sw:3; //0..7
  uint8_t opCmp:2; //< & | ^
  uint8_t opRes:3; //0 => 1=> 0=> !=> & | ^
  int8_t val1; //
  int8_t val2; //
}) SwitchData_r204; //
PACK(typedef struct t_ExpoData_r84 {
  int8_t  expNorm;
  int8_t  expDr;
  int8_t  drSw;
  int8_t  expNormWeight;
  int8_t  expSwWeight;
}) ExpoData_r84; //5*4=20


#define EM_POS      1
#define EM_NEG      2
#define EM_BOTH     3
#define EM_TRIM_INV 4
#define EM_ALT_TRIM 5
PACK(typedef struct t_ExpoData_r171 {
  int8_t  exp5:5;
  uint8_t mode3:3; //0=end 1=pos 2=neg 3=both 4=trimNeg 5=alt trim

  int8_t  weight6:6;
  uint8_t chn:2;  //

  int8_t  drSw:5;
  uint8_t curve:3; //
}) ExpoData_r171; //3*15=45


PACK(typedef struct t_TrimData_r0 {
  int8_t  trim;    //quadratisch
  int16_t trimDef_lt133;
}) TrimData_r0;//<r143

PACK(typedef struct t_TrimData_r143 {
  int8_t  itrim:6; //trim index
  uint8_t tmode:2;
}) TrimData_r143;


PACK(typedef struct t_LimitData_r84 {
  int8_t  min;
  int8_t  max; 
  bool    revert:1;
  int8_t  offset:7;
}) LimitData_r84;
PACK(typedef struct t_LimitData_r167 {
  int8_t  min:7;
  bool    scale:1;
  int8_t  max:7; 
  bool    binSwtch:1; //resv
  bool    revert:1;
  int8_t  offset:7;
}) LimitData_r167;

PACK(typedef struct t_MixData_r0 {
  uint8_t destCh:4; //0=end   1..NUM_CHNOUT,X1-X4
  uint8_t srcRaw:4; //0=off   S1-4,P1-3,max,ful ,X1-X4
  int8_t  weight;
  int8_t  swtch:5;
  uint8_t curve:3; //0=off 1..7=cv1..7
  uint8_t speedUp:4;         // Servogeschwindigkeit aus Tabelle (10ms Cycle)
  uint8_t speedDown:4;      // 0 nichts
}) MixData_r0;
//more data:
// destCh 12 -> 16                                     4+1?
// srcRaw 14 -> S1-4,P1-3,ful,s1-4,p1-3,max,ch1-16 32  4+1
//              ful           half
// srcRaw 14 -> S1-4,P1-3,max,p1-3,X1-X4,T1-8  23 4+1
// curve  8->16 ,neg                                   3+2(1)
// sw-mode -100,0,disable                              0+2
// mix-mode + * = 1?                                    0+2
//
PACK(typedef struct t_MixData_r192 {
  uint8_t destCh:4;    // 1..NUM_CHNOUT,X1-X4
  uint8_t mixMode:2;   // + * =
  uint8_t dmy1:2;   //

  uint8_t srcRaw:5;    // S1-4,P1-3,p1-3,max,cur,Ch1-8,X1-4,T1-8  32
  uint8_t switchMode:2; //switchMode oOff\tiNeg\tiNul\tiPos
  uint8_t curveNeg:1;  // Cv cV

  int8_t  weight;

  int8_t  swtch:5;
  uint8_t curve:3; //0=off 1..7=cv1..7

  uint8_t speedUp:4;         // Servogeschwindigkeit aus Tabelle (10ms Cycle)
  uint8_t speedDown:4;      // 0 nichts
}) MixData_r192; //210



#define MDVERS84 1
PACK(typedef struct t_ModelData_r84 {
  char      name[10];             // 10 must be first for eeLoadModelName
  uint8_t   mdVers;               // 1
  uint8_t   tmrMode;              // 1
  uint16_t  tmrVal;               // 2
  uint8_t   protocol;             // 1
  char      res[3];               // 3
  LimitData_r84 limitData[NUM_CHNOUT];// 3*8
  ExpoData_r84  expoData[4];          // 5*4
  MixData_r0   mixData[MAX_MIXERS];  //0 4*25
  int8_t    curves5[2][5];        // 10
  int8_t    curves9[2][9];        // 18
  TrimData_r0  trimData[4];          // 3*4
}) ModelData_r84; //202

#define MDVERS143 2
PACK(typedef struct t_ModelData_r143 {
  char      name[10];             // 10 must be first for eeLoadModelName
  uint8_t   mdVers;               // 1
  uint8_t   tmrMode;              // 1
  uint16_t  tmrVal;               // 2
  uint8_t   protocol;             // 1
  char      res[3];               // 3
  LimitData_r84 limitData[NUM_CHNOUT];// 3*8
  ExpoData_r84  expoData[4];          // 5*4
  MixData_r0   mixData[MAX_MIXERS];  //0 4*25
  int8_t    curves3[3][3];        // 9  new143
  int8_t    curves5[2][5];        // 10
  int8_t    curves9[2][9];        // 18
  TrimData_r143  trimData[4];    // 3*4 -> 1*4
}) ModelData_r143; //203

#define MDVERS167 3
PACK(typedef struct t_ModelData_r167 {
  char      name[10];             // 10 must be first for eeLoadModelName
  uint8_t   mdVers;               // 1
  uint8_t   tmrMode;              // 1
  uint16_t  tmrVal;               // 2
  uint8_t   protocol;             // 1
  char      res[3];               // 3
  LimitData_r167 limitData[NUM_CHNOUT];// 3*8
  ExpoData_r84  expoData[4];          // 5*4
  MixData_r0   mixData[MAX_MIXERS];  //0 4*25
  int8_t    curves3[3][3];        // 9  new143
  int8_t    curves5[2][5];        // 10
  int8_t    curves9[2][9];        // 18
  TrimData_r143  trimData[4];    // 3*4 -> 1*4
}) ModelData_r167; //203

#define MDVERS171 4
PACK(typedef struct t_ModelData_r171 {
  char      name[10];             // 10 must be first for eeLoadModelName
  uint8_t   mdVers;               // 1
  uint8_t   tmrMode;              // 1
  uint16_t  tmrVal;               // 2
  uint8_t   protocol;             // 1
  char      res[3];               // 3
  LimitData_r167 limitData[NUM_CHNOUT];// 3*8
  ExpoData_r171  expoTab[MAX_EXPOS];      // 5*4 -> 3*15
  MixData_r0   mixData[MAX_MIXERS];  //0 4*25
  int8_t    curves3[3][3];        // 9  new143
  int8_t    curves5[2][5];        // 10
  int8_t    curves9[2][9];        // 18
  TrimData_r143  trimData[4];    // 3*4 -> 1*4
}) ModelData_r171; //228

#define MDVERS192 5
PACK(typedef struct t_ModelData_r192 {
  char      name[10];             // 10 must be first for eeLoadModelName
  uint8_t   mdVers;               // 1
  uint8_t   tmrMode;              // 1
  uint16_t  tmrVal;               // 2
  uint8_t   protocol;             // 1
  char      res[3];               // 3
  LimitData_r167 limitData[NUM_CHNOUT];// 3*8
  ExpoData_r171  expoTab[MAX_EXPOS];      // 5*4 -> 3*15
  MixData_r192   mixData[MAX_MIXERS];  //0 5*25
  int8_t    curves3[3][3];        // 9  new143
  int8_t    curves5[2][5];        // 10
  int8_t    curves9[2][9];        // 18
  TrimData_r143  trimData[4];    // 3*4 -> 1*4
}) ModelData_r192; //253

#define MDVERS204 6
PACK(typedef struct t_ModelData_r204 {
  char      name[10];             // 10 must be first for eeLoadModelName
  uint8_t   mdVers;               // 1
  uint8_t   tmrMode:3;            // 1
  int8_t    tmrSw:5;              // 
  uint16_t  tmrVal;               // 2
  uint8_t   protocol:5;           // 1
  uint8_t   protocolPar:3;        // 
  char      res[3];               // 3
  LimitData_r167 limitData[NUM_CHNOUT];// 3*8
  ExpoData_r171  expoTab[MAX_EXPOS];      // 5*4 -> 3*15
  MixData_r192   mixData[MAX_MIXERS];  //0 5*25
  int8_t    curves3[3][3];        // 9  new143
  int8_t    curves5[2][5];        // 10
  int8_t    curves9[2][9];        // 18
  SwitchData_r204 switchTab[MAX_SWITCHES];//
  TrimData_r143   trimData[4];    // 3*4 -> 1*4
}) ModelData_r204; //253
#define MDVERS_TOP    MDVERS204
#define ModelData_TOP ModelData_r204


extern EEGeneral_TOP g_eeGeneral;
extern ModelData_TOP g_model;












#endif
/*eof*/
