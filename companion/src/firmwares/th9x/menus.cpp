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
#include "foldedlist.h"


uint8_t g_event; //global g_event

int8_t add7Bit(int8_t a,int8_t b){ 
  a  = (a+b) & 0x7f;
  if(a & 0x40) a|=0x80;
  return a;
}
int16_t lim2val(int8_t limidx,int8_t dlt){ 
  return idx2val50_150(add7Bit(limidx,dlt));
}


uint16_t slopeFull100ms(uint8_t speed);

static int16_t anaCalib[4];
int16_t g_chans512[NUM_CHNOUT];
uint8_t g_sumAna;
uint8_t g_virtSw[8];

//sticks
#include "sticks.lbm"

void menuProcSwitches();

typedef PROGMEM void (*MenuFuncP_PROGMEM)();

MenuFuncP_PROGMEM APM menuTabModel[] = {
  menuProcModelSelect,
  menuProcModel, 
  menuProcExpoAll, 
  menuProcMix, 
  menuProcSwitches,
  menuProcTrim, 
  menuProcLimits,
  menuProcCurve
};

MenuFuncP_PROGMEM APM menuTabDiag[] = {
  menuProcSetup0,
  menuProcSetup1,
  menuProcSetup2,
  menuProcTrainer,
  menuProcDiagVers,
  menuProcDiagKeys, 
  menuProcDiagAna, 
  menuProcDiagCalib
#ifdef SIM
  //  ,menuProcDisplayTest
#endif
};

//#define PARR8(args...) (__extension__({static prog_uint8_t APM __c[] = args;&__c[0];}))
struct MState2
{
  uint8_t m_posVert;
  uint8_t m_posHorz;
  bool    m_valEdit:1;
  int8_t  m_posVertChg:2;
  int8_t  m_posHorzChg:2;
  //void init(){m_posVert=m_posHorz=0;};
  void init(){m_posVert=0;m_valEdit=0;};
  prog_uint8_t *m_tab;
  //  static uint8_t g_event;
  void check_v(uint8_t curr,MenuFuncP *menuTab, uint8_t menuTabSize, uint8_t maxrow);
  void check( uint8_t curr,MenuFuncP *menuTab, uint8_t menuTabSize, prog_int8_t*subTab,uint8_t subTabMax,uint8_t maxrow);
};
#define MSTATE_TAB  static prog_int8_t APM mstate_tab[]


/*
  MSTATE_CHECK0_VxH
  0   = ohne menu tab umschaltung (rechts-links zum folgemenu)
  V   = nur vertikal navigation
  VxH = vert + horiz navigation  braucht MSTATE_TAB
*/


#define MSTATE_CHECK0_VxH(numRows)             mstate2.check(0,0,0,mstate_tab,DIM(mstate_tab)-1,numRows-1)
#define MSTATE_CHECK0_V(numRows)               mstate2.check_v(0,0,0,numRows-1)
#define MSTATE_CHECK_VxH(curr,menuTab,numRows) mstate2.check(curr,menuTab,DIM(menuTab),mstate_tab,DIM(mstate_tab)-1,numRows-1)
#define MSTATE_CHECK_V(curr,menuTab,numRows)   mstate2.check_v(curr,menuTab,DIM(menuTab),numRows-1)

void MState2::check_v( uint8_t curr,MenuFuncP *menuTab, uint8_t menuTabSize, uint8_t maxrow)
{ 
  check(  curr, menuTab, menuTabSize, 0, 0, maxrow);
}
void MState2::check( uint8_t curr,MenuFuncP *menuTab, uint8_t menuTabSize, prog_int8_t*horTab,uint8_t horTabMax,uint8_t maxrow)
{
  m_posVertChg=0;
  m_posHorzChg=0;
  if(menuTab) {
    uint8_t attr = INVERS; 
    curr--; //calc from 0, user counts from 1

    if(m_posVert==0){
      attr = ATT_CSR_EDT;
      switch(g_event)
      {
        case EVT_KEY_FIRST(KEY_LEFT):
          curr += menuTabSize-2;
	  //fallthrough
        case EVT_KEY_FIRST(KEY_RIGHT):
          curr++;
          if(curr>=menuTabSize) curr-=menuTabSize;
          chainMenu((MenuFuncP)pgm_read_adr(&menuTab[curr]));
	  killEvents();
          break;
      }
    }
    lcd_putcAtt(128-FW*1,0,menuTabSize+'0',attr);
    lcd_putcAtt(128-FW*2,0,'/',attr);
    lcd_putcAtt(128-FW*3,0,curr+'1',attr);
  }

#define INC(val,max) if(val<max) {val++;} else {val=0;}
#define DEC(val,max) if(val>0  ) {val--;} else {val=max;}
  switch(g_event) {
    case EVT_ENTRY:
      checkLastSwitch(0,0);
      init();//BLINK_SYNC;
      break;
    case EVT_KEY_LONG(KEY_EXIT):
      popMenu(true); //return to uppermost, beeps itself
      break;
    case EVT_KEY_BREAK(KEY_EXIT):
      if(m_valEdit){ //innermost state, leave first
	m_valEdit=0;
      }else if(m_posVert && menuTab) {
	init();
      } else {
	popMenu();  //beeps itself
      }
      beepKey();  
      BLINK_SYNC;
      break;
  }
  if(horTab){
#define NUMCOL(row) (int8_t)pgm_read_byte(horTab+min( row, horTabMax ))
    bool    horzCsr = NUMCOL(m_posVert) < 0; //vert kamm
    uint8_t maxcol  = horzCsr ? -NUMCOL(m_posVert) : NUMCOL(m_posVert)-1;
    switch(g_event) {
      case EVT_KEY_BREAK(KEY_DOWN): //inc vert
        if(!horzCsr || m_posHorz==0){
          INC(m_posVert,maxrow);
	  m_posVertChg=1;
          if(NUMCOL(m_posVert)<0){
            m_posHorz=0; //auf kopfelement setzen, damit vert navigierbar
          }else{
            m_posHorz=min(m_posHorz,(uint8_t)(NUMCOL(m_posVert)-1));
          }
        }
        BLINK_SYNC; 
        break;
      case EVT_KEY_BREAK(KEY_UP):   //dec vert
        if(!horzCsr || m_posHorz==0){
          DEC(m_posVert,maxrow);
	  m_posVertChg=-1;
          if(NUMCOL(m_posVert)<0){
            m_posHorz=0; //auf kopfelement setzen, damit vert navigierbar
          }else{
            m_posHorz=min(m_posHorz,(uint8_t)(NUMCOL(m_posVert)-1));
          }
        }
        BLINK_SYNC;
        break;
      case EVT_KEY_LONG(KEY_DOWN):  //inc horz
        if(! NAVI_ADVANCED) break;
        if(horzCsr) break;
        killEvents();
        INC(m_posHorz,maxcol);
        m_posHorzChg=+1;
        BLINK_SYNC; 
        break;
      case EVT_KEY_LONG(KEY_UP):   //dec horz
        if(! NAVI_ADVANCED) break;
        if(horzCsr) break;
        killEvents();
        DEC(m_posHorz,maxcol);
        m_posHorzChg=-1;
        BLINK_SYNC;
        break;
      case EVT_KEY_LONG(KEY_LEFT):   //
      case EVT_KEY_LONG(KEY_RIGHT):  //start edit
        if(! NAVI_ADVANCED) break;
        m_valEdit = 1;
        break;
      case EVT_KEY_BREAK(KEY_MENU):
        BLINK_SYNC; 
        m_valEdit ^= 1;
        break;
      case EVT_KEY_BREAK(KEY_RIGHT):  //inc horz
        if(m_valEdit) break;
        INC(m_posHorz,maxcol);
        m_posHorzChg=+1;
        BLINK_SYNC; 
        break;
      case EVT_KEY_BREAK(KEY_LEFT):   //dec horz
        if(m_valEdit) break;
        DEC(m_posHorz,maxcol);
        m_posHorzChg=-1;
        BLINK_SYNC;
        break;
    }
  }else //no horTab
    switch(g_event) { 
      case EVT_KEY_REPT(KEY_DOWN):  //inc vert
        if(m_posVert==maxrow) break;
      case EVT_KEY_FIRST(KEY_DOWN): //inc
        //if(horTab)break;
        INC(m_posVert,maxrow);
	m_posVertChg=1;
        BLINK_SYNC;
        break;

      case EVT_KEY_REPT(KEY_UP):  //dec vert
        if(m_posVert==0) break;
      case EVT_KEY_FIRST(KEY_UP): //dec
        //if(horTab)break;
        DEC(m_posVert,maxrow);
	m_posVertChg=-1;
        BLINK_SYNC;
        break;
    }
}


#ifdef SIM
extern char g_title[80];
MState2 mstate2;
#define TITLEP(pstr) lcd_putsAtt(0,0,pstr,INVERS);sprintf(g_title,"%s_%d_%d",pstr,mstate2.m_posVert,mstate2.m_posHorz);
#else
#define TITLEP(pstr) lcd_putsAtt(0,0,pstr,INVERS)  
#endif
#define TITLE(str)   TITLEP(PSTR(str))





static uint8_t s_curveChan;

uint8_t curveTyp(uint8_t idx)
{
  if(idx<3) return 3;
  if(idx<5) return 5;
  return 9;
}
int8_t* curveTab(uint8_t idx)
{
  if(idx<3) return g_model.curves3[idx];
  if(idx<5) return g_model.curves5[idx-3];
  return           g_model.curves9[idx-5];
}

void menuProcCurveOne() {
  static MState2 mstate2;
  uint8_t x = TITLE("CURVE f");
  lcd_putcAtt(x, 0, s_curveChan + '1', INVERS);

  uint8_t cvTyp=curveTyp(s_curveChan);
  int8_t *crv = curveTab(s_curveChan);
  MSTATE_CHECK0_V(cvTyp+1);

  int8_t  sub    = mstate2.m_posVert;


  for (uint8_t i = 0; i < min(cvTyp,(uint8_t)5); i++) {
    uint8_t y = i * FH + 16;
    uint8_t attr = sub == i ? ATT_CSR_EDT : 0;
    lcd_outdezAtt(4 * FW, y, crv[i], attr);
  }
  if(cvTyp==9)
    for (uint8_t i = 0; i < 4; i++) {
      uint8_t y = i * FH + 16;
      uint8_t attr = sub == i + 5 ? ATT_CSR_EDT : 0;
      lcd_outdezAtt(8 * FW, y, crv[i + 5], attr);
    }
  lcd_putsAtt( 2*FW, 7*FH,PSTR("PRESET"),sub == cvTyp ? ATT_CSR_EDT : 0);

  static int8_t dfltCrv;
  if(sub<cvTyp)  CHECK_INCDEC_H_MODELVAR(  crv[sub], -100,100);
  else {
    if( checkIncDecGen2( &dfltCrv, -10, 10, 0)){
      for (uint8_t i = 0; i < 5; i++) {
        int8_t pos=0,neg=0;
        switch(abs(dfltCrv)){
          case 0: break;
          case 1: 
          case 2: 
          case 3: 
          case 4: neg = -25*abs(dfltCrv)*i/4;  pos=-neg;  break;
          case 5: neg =  50-25*i/2  ; pos =    100-neg;   break;
          case 6:                     pos =       25*i   ;break;
          case 7: neg =      -25*i  ;                     break;
          case 8: neg =       25*i  ; pos =       25*i   ;break;
          case 9: neg = -100        ; pos = -100+ 50*i   ;break;
         case 10: neg = +100 -50*i  ; pos = +100         ;break;
        }
        if(dfltCrv<0) {neg=-neg;pos=-pos;}
        switch(cvTyp){ 
          case 9:                crv[4-i] = neg; crv[4+i] = pos;  break;
          case 5: if(i%2) break; crv[2-i/2] = neg; crv[2+i/2] = pos;  break;
          case 3: if(i%4) break; crv[1-i/4] = neg; crv[1+i/4] = pos;  break;
        }
      }
      eeDirty(EE_MODEL);
    }
  }

#define WCHART 32
#define X0     (128-WCHART-2)
#define Y0     32
#define RESX    512
#define RESXu   512u
#define RESXul  512ul
#define RESKul  100ul

  for (uint8_t xv = 0; xv < WCHART * 2; xv++) {
    uint16_t yv = intpol(xv * (RESXu / WCHART) - RESXu, s_curveChan) / 
      (RESXu / WCHART);
    if((int16_t)yv<-31) yv=-31;
    lcd_plot(X0 + xv - WCHART, Y0 - yv);
    if ((xv & 3) == 0) {
      lcd_plot(X0 + xv - WCHART, Y0 + 0);
    }
  }
  lcd_vline(X0, Y0 - WCHART, WCHART * 2);
}

void menuProcCurve() {
  static MState2 mstate2;
  TITLE("CURVES");
  MSTATE_CHECK_V(8,menuTabModel,7+1);
  int8_t  sub    = mstate2.m_posVert - 1;

  switch (g_event) {
    case EVT_KEY_LONG(KEY_MENU):  //!! _LONG
    if (sub >= 0) {
      s_curveChan = sub;
      pushMenu(menuProcCurveOne);
      return;
    }
    break;
  }
  uint8_t y    = 1*FH;
  for (uint8_t i = 0; i < 7; i++) {
    uint8_t attr = sub == i ? ATT_CSR_EDT : 0;
    lcd_putsAtt(   FW*0, y,PSTR("f"),attr);
    lcd_outdezAtt( FW*2, y,i+1 ,attr);

  uint8_t cvTyp=curveTyp(i);
  int8_t *crv = curveTab(i);
    for (uint8_t j = 0; j < min(cvTyp,(uint8_t)5); j++) {
      lcd_outdezAtt( j*(3*FW+3) + 7*FW, y, crv[j], 0);
    }
    y += FH;
  }
}

static bool  s_limitCacheOk;
#define LIMITS_DIRTY s_limitCacheOk=false
void menuProcLimits()
{
  static MState2 mstate2;
  TITLE("LIMITS");  
  MSTATE_TAB = { 5,5};
  MSTATE_CHECK_VxH(7,menuTabModel,8+1+1);

  int8_t  sub    = mstate2.m_posVert;// - 1;
  uint8_t subHor = mstate2.m_posHorz + 1;
  if(sub<=1)       mstate2.m_valEdit=0;
  static uint8_t s_pgOfs;
  if(sub>7) s_pgOfs = 2;
  if(sub<6) s_pgOfs = 0;

  switch(g_event)
  {
    case EVT_ENTRY:
      s_pgOfs = 0;
      break;
  }
  for(uint8_t i=0; i<5; i++){
    uint8_t    x=5*FW+i*(3*FW+2);
    if(i==0){ x-=FW;}
    lcd_putsmAtt(x , 1*FH,PSTR("subT\t""min\t""scl\t""max\t""inv"),i,(sub==1 && mstate2.m_posHorz==i) ? INVERS : 0);
  }
  sub-=2;
#define ATTR(row,col) ((sub==row && subHor==col) ? (mstate2.m_valEdit?ATT_CSR_EDT:ATT_CSR_MV) : 0)
  for(uint8_t i=0; i<6; i++){
    uint8_t y=(i+2)*FH;
    uint8_t k=i+s_pgOfs;
    uint8_t v;
    LimitData_r167 *ld = &g_model.limitData[k];
    putsChn(0,y,k+1, 0);
    for(uint8_t j=1; j<=5;j++){
      uint8_t attr = ATTR(k,j);
      bool    edit = attr == ATT_CSR_EDT;
      switch(j)
      {
        case 1:
          lcd_outdezAtt(  7*FW, y,  ld->offset,               attr);
          if(edit) {
            if(CHECK_INCDEC_H_MODELVAR_BF(  ld->offset, -63,63))  LIMITS_DIRTY;
          }
          break;        
        case 2:
          v = add7Bit(ld->min,-40);
          lcd_outdezAtt(  12*FW, y, idx2val50_150(v),   attr);
          if(edit) {
            if(CHECK_INCDEC_H_MODELVAR(  v, -50,50))  LIMITS_DIRTY; 
          }
          ld->min = add7Bit(v,40);
          break;        
      case 3:{
	  uint8_t scl_bin=ld->scale+ld->binSwtch*2;
          lcd_putsmAtt(   13*FW, y, PSTR(" \t*\tS"),scl_bin,attr);
          if(edit) {
            CHECK_INCDEC_H_MODELVAR_BF(  scl_bin,    0,2);
	    ld->scale    =     scl_bin & 1;
	    ld->binSwtch = !! (scl_bin & 2);
          }
          break;
      }
        case 4:
          v = add7Bit(ld->max,+40);
          lcd_outdezAtt( 18*FW, y, idx2val50_150(v),    attr);
          if(edit) {
            if(CHECK_INCDEC_H_MODELVAR_BF(  v, -50,50))  LIMITS_DIRTY; 
          }
          ld->max = add7Bit(v,-40);
          break;        
        case 5:
          lcd_putsmAtt(   18*FW, y, PSTR(" - \tINV"),ld->revert,attr);
          if(edit) {
            CHECK_INCDEC_H_MODELVAR_BF(  ld->revert,    0,1);
          }
          break;        
      }
    }
  }
}

t_ExpoData_r171 *g_altTrim[4]; //=0, not used by default
int8_t getTrimRawMode(uint8_t iLog)
{
  if(g_altTrim[iLog]){
    return g_altTrim[iLog]->exp5;
  }else{
    return g_model.trimData[iLog].tmode;
  }
}
int8_t getTrimRaw(uint8_t iLog)
{
  if(g_altTrim[iLog]){
    return g_altTrim[iLog]->weight6;
  }else{
    return g_model.trimData[iLog].itrim;
  }
}
void   setTrimRaw(uint8_t iLog,int8_t ival)
{
  if(g_altTrim[iLog]){
    g_altTrim[iLog]->weight6 = ival;
  }else{
    g_model.trimData[iLog].itrim = ival;
  }
}

int16_t trimVal(uint8_t iLog)
{
  int8_t  itrim = getTrimRaw(iLog);
  int8_t  tmode = getTrimRawMode(iLog);
  int16_t ret   = trimExpMu(abs(itrim),tmode);
  return  itrim <0 ? -ret : ret;
}

void menuProcTrim()
{
  static MState2 mstate2;
  TITLE("TRIM-SUBTRIM");  
  MSTATE_TAB = {2};
  MSTATE_CHECK_VxH(6,menuTabModel,4+1);
  int8_t  sub    = mstate2.m_posVert - 1;
  int8_t  subHor = mstate2.m_posHorz;
  static int16_t outHelp[NUM_CHNOUT];
  if(sub>=0)
  {
    int8_t  trimTmp = g_model.trimData[sub].itrim;
    g_model.trimData[sub].itrim = 0;
    perOut(outHelp); //try output calculation without this trim-value
    g_model.trimData[sub].itrim = trimTmp;
    for(uint8_t i=0; i<NUM_CHNOUT;i++){
      outHelp[i] = (g_chans512[i] - outHelp[i]) ;
      outHelp[i] = (outHelp[i] + sgn(outHelp[i])*2) / 5 ;
    }
  }


  lcd_puts_P( 5*FW, 1*FH,PSTR("Trim   Subtrim"));
  lcd_puts_P(11*FW, 2*FH,PSTR(      "Ch14 Ch58"));
  for(uint8_t iLog=0; iLog<4; iLog++)
  {
    uint8_t y=iLog*FH+FH*3;
    putsChnRaw(0,y,iLog,0);//attr);
    for(uint8_t j=0; j<2;j++){
      uint8_t attr = ATTR(iLog,j);
      bool    edit = attr == ATT_CSR_EDT;
      switch(j)
      {
        case 0:
          lcd_putsmAtt(   4*FW, y, PSTR("D1\tD2\tD4\tD8"),g_model.trimData[iLog].tmode,attr);
          if(edit) {
            CHECK_INCDEC_H_MODELVAR_BF(  g_model.trimData[iLog].tmode,    0,3);
          }
          break;

        case 1:
	  //uint8_t attr = sub==iLog ? INVERS : 0; 
	  lcd_outdezAtt(10*FW, y, trimVal(iLog)*2, attr|PREC1 );
	  if(edit && outHelp[iLog] && BLINK_ON_PHASE) lcd_outdezAtt(14*FW, y, outHelp[iLog]   , outHelp[iLog]   ? ATT_CSR_EDT|SIGN : 0);
	  else           lcd_outdezAtt(14*FW, y, g_model.limitData[iLog].offset , 0);
	  
	  if(edit && outHelp[iLog+4] && BLINK_ON_PHASE)lcd_outdezAtt(19*FW, y, outHelp[iLog+4] , outHelp[iLog+4] ? ATT_CSR_EDT|SIGN : 0);
	  else           lcd_outdezAtt(19*FW, y, g_model.limitData[iLog+4].offset , 0);
	  if(edit && g_event== EVT_KEY_BREAK(KEY_RIGHT)) {
	    for(uint8_t i=0; i<NUM_CHNOUT;i++){
	      g_model.limitData[i].offset += outHelp[i];
	    }
	    g_model.trimData[sub].itrim     = 0;
	    STORE_MODELVARS;
	    beepKey();
	  }
	  break;
      }
    }
  }
  lcd_puts_P(FW*7,FH*7,PSTR("--> Rearrange"));  
}


int16_t getSrcVal(uint8_t srcRaw, uint8_t destCh);
int16_t getSrcValSw(int8_t swId,int8_t opCmp)
{
  if(opCmp != 0){
    return getSwitch(swId,0);
  }else{
    uint8_t aswId=abs(swId);
    int16_t ret;
    if(aswId <= 50){
      ret = idx2val50_150_512(aswId);
    }else{
      ret = getSrcVal(aswId-51,0);
    }
    return swId < 0 ? -ret : ret;
  }
}

void editSwitchVals( uint8_t which,uint8_t mEdit,uint8_t x, uint8_t y, uint8_t idt)
{
  bool     edit    = mEdit==1;
  uint8_t  editAtt = mEdit ? (edit ? ATT_CSR_EDT : ATT_CSR_MV ) : 0;
  SwitchData_r204 &sd = g_model.switchTab[idt];
  switch(which)
  {
    case 0:
    case 2:
      {
        int8_t val = which==0 ? sd.val1 : sd.val2;

        if(sd.opCmp != 0){
          if(val)putsDrSwitches(x-FW*4,  y, val, editAtt);
          else   lcd_putsAtt(   x-FW*1,  y, PSTR("0"),editAtt);
     
          if(edit) {
            CHECK_INCDEC_H_MODELVAR(  val, MIN_DRSWITCH, MAX_DRSWITCH);
          }
        }else{
          uint8_t aswId=abs(val);
          if(aswId  <= 50){
            lcd_outdezAtt(  x, y, idx2val50_150(val),editAtt);
          }else{
            if(val<0)lcd_putcAtt(x-FW*3-5, y, '-',  editAtt);
            putsChnRaw( x-FW*3,   y, aswId-51,editAtt);
          }
          if(edit) {
            CHECK_INCDEC_H_MODELVAR(  val, -(NUM_XCHNRAW+50), NUM_XCHNRAW+50);
          }
        }
        if(which==0) sd.val1=val; else sd.val2=val;
      }
      break; 
    case 1:
      lcd_putsmAtt(x-FW*1,y,PSTR("<\t&\t|\t^"), sd.opCmp,editAtt);
      if(edit) {
        int8_t op = sd.opCmp;
        
        CHECK_INCDEC_H_MODELVAR(  op, -1,3);
        if(op==-1){
          int8_t val = sd.val1;
          sd.val1    = sd.val2;
          sd.val2    = val;
        }else{
          sd.opCmp = op;
        }
      }
      break; 
    case 3:
      lcd_putsmAtt(x-FW*3,y,PSTR("\tSet\tOn \tOff\tInv\t&\t|\t^"), sd.opRes,editAtt);
      if(edit) CHECK_INCDEC_H_MODELVAR_BF(  sd.opRes, 1,7);
      break; 
    case 4:   lcd_putsAtt(x-FW*6,y,PSTR("[MENU]"),editAtt);
      //if(edit && g_event==EVT_KEY_FIRST(KEY_MENU)){ //loeschen ok
      if(edit && g_event==EVT_KEY_LONG(KEY_MENU)){ //loeschen ok
        FL_INST.rmCurrLine();
	killEvents();
	popMenu();  
      }
      break;
  }  
}
void menuProcSwitchOne()
{
  static MState2 mstate2;
  uint8_t x=TITLEP(FL_INST.currInsMode() ? PSTR("INSERT ") : PSTR("EDIT "));  
  lcd_puts_P( x, 0,PSTR("SW"));
  lcd_putc( x+2*FW, 0,g_model.switchTab[FL_INST.editIDT()].sw+'1');
  MSTATE_CHECK0_V(5);
  int8_t  sub    = mstate2.m_posVert;


  uint8_t  y = FH*2;
  for(uint8_t i=0;i<5;i++){
    uint8_t  x = FW*7;
    if(i==3){x+=FW*9;}
    if(i==4){y+=FH;}
    lcd_putsmAtt( FW*8, y,PSTR("Val1\tOp1 \tVal2\t Op2\tRM  "),i,INVERS);

    editSwitchVals(i,sub==i,x, y,FL_INST.editIDT());
    y+=FH;
  }
}

uint8_t chProcSwitches(uint8_t*line, uint8_t setCh)
{
  SwitchData_r204 &sd = *(SwitchData_r204*)line;
  if(setCh) sd.sw = setCh-1;
  return sd.sw+1;
}

uint8_t s_swNested; //selected sw 1..
void menuProcSwitchesCom(bool nest);
void menuProcSwitchesNested()
{
  menuProcSwitchesCom(true);
}
void menuProcSwitches()
{
  menuProcSwitchesCom(false);
}
void menuProcSwitchesCom( bool nested)
{
  static MState2 mstate2;
  uint8_t x=TITLE("SWITCHES  ");  
  int8_t  sub;//    = mstate2.m_posVert;
  //int8_t  subOld  = mstate2.m_posVert;
#define SW_COLS (4+2)
  MSTATE_TAB = {SW_COLS};
  if(nested){
    MSTATE_CHECK0_VxH(FL_INST.numWithHdr()-1);
    sub= mstate2.m_posVert+1;//nested has no line 0
    //subOld++;
  }else{
    MSTATE_CHECK_VxH(5,menuTabModel,FL_INST.numWithHdr());
    sub= mstate2.m_posVert;
  }
  int8_t  subHor = mstate2.m_posHorz;
  if(sub<1 || subHor==0)       mstate2.m_valEdit=0;

  FL_INST.init(g_model.switchTab,DIM(g_model.switchTab),sizeof(g_model.switchTab[0]),chProcSwitches,8);

  if(FL_INST.listEditMode(subHor==(SW_COLS-1))) mstate2.m_valEdit=0;

  lcd_outdezAtt(  x, 0, FL_INST.fillLevel(),INVERS); //fill level



  uint8_t what;
  switch(what=FL_INST.doEvent(sub,mstate2.m_posVertChg,subHor==0))
  {
    case FoldedListNew:
    case FoldedListNewEdit:
      {
        SwitchData_r204  *sd = &g_model.switchTab[FL_INST.editIDT()];
        sd->sw              = FL_INST.currDestCh()-1; //1;   //
        sd->opRes           = 1;
      }
      if(what==FoldedListNew)break;
      //fallthrough
    case FoldedListEdit:
      pushMenu(menuProcSwitchOne);
      break;
    case FoldedListDup:
    case FoldedListSwap:
    default:;
      break;
  }
  mstate2.m_posVert = FL_INST.m_subIFL - (nested?1:0);
  if(FL_INST.m_chnNav && mstate2.m_posVert) mstate2.m_posHorz=subHor=0;




  static prog_uint8_t APM colPos[]={8*FW,11*FW,15*FW,20*FW,127};

  if(s_swNested ){
    mstate2.m_posVert = FL_INST.findChn(s_swNested)-1; //+1 in init seq
    s_swNested=0;
  }
  //uint8_t y = 2*FH;
  uint8_t y = 1*FH;
  //  for(FoldedList::Line* line=FL_INST.firstLine(sub>=2?sub-1:0);
  for(FoldedList::Line* line=FL_INST.firstLine();
      line;
      line=FL_INST.nextLine(7), y+=FH
      )
  {
    if(line->showHeader){
      lcd_puts_P( 5*FW+2, y,PSTR("val op val op2 "ARR_N_S));
    }  
    if(line->showCh){  
      lcd_putsAtt( 0, y,PSTR("SW"),FL_INST.isSelectedCh()?ATT_CSR_MV:0);
      lcd_putcAtt( 0+2*FW, y,line->chId+'0',FL_INST.isSelectedCh()?ATT_CSR_MV:0);
    }
    if(line->showDat){ //show data 
      uint8_t  sel = FL_INST.isSelectedDat()?1:0;  //selected line
      bool lineEdit = 0;
      if(sel && FL_INST.listEditMode()) {sel=0; lineEdit=true;}
      if(sel && !mstate2.m_valEdit)  sel=2;

      for(uint8_t j=0; j<4; j++){
        editSwitchVals(j,
                       subHor==(j+1) ? sel : 0, 
                       pgm_read_byte(&colPos[j]),   y,line->idt);
      }
      if(lineEdit) {
        lcd_barAtt( 4*FW,  y,128-5*FW-1,INVERS);
        if(BLINK_ON_PHASE)lcd_putsAtt( 128-FW,y,PSTR(ARR_N_S),0);
      }
    }
//     if(FL_INST.isSelectedCh()) {
//       if(BLINK_ON_PHASE) {
//         //lcd_hline(pgm_read_byte(&colPos[subHor])-FW*3,y+7,FW*3);//FW*4);
//         lcd_hline(0,y+7,pgm_read_byte(&colPos[subHor]));
//       }
//     }

  }
}

void showSwitches(uint8_t subSw) //submenu of main
{
#define HBAR3 18 
#define WBAR3  8
  uint8_t y0       = 32+4+HBAR3/2;
  for(uint8_t i=0; i<8; i++) {
    uint8_t x0       = i*12+64-36-6 + (i<4?-3:+3);
    lcd_rect(x0-WBAR3/2,y0-HBAR3/2,WBAR3,HBAR3);
    uint8_t y=y0+2;
    if(g_virtSw[i]) y-=HBAR3/2;
    lcd_fill(x0-WBAR3/2+2,y,WBAR3-4,HBAR3/2-4);
    if(subSw==i && BLINK_ON_PHASE){
      lcd_rect(x0-WBAR3/2+1,y-1,WBAR3-2,HBAR3/2-2);
    }
  }
}




void editMixVals( uint8_t which,uint8_t mEdit,uint8_t x, uint8_t y, uint8_t idt)
{
  bool     edit    = mEdit==1;
  uint8_t  editAtt = mEdit ? (edit ? ATT_CSR_EDT : ATT_CSR_MV ) : 0;
  MixData_r192 &md2 = g_model.mixData[idt];
#define CURV_STR     "  \t""f1\t""f2\t""f3\t""f4\t""f5\t""f6\t""f7"
  //if(g_model.limitData[destCh].binSwtch) {md2.srcRaw=SRC_MAX;md2.curve=0;md2.speedDown=md2.speedUp=0; }

  switch(which)
  {
    case 0:   putsChnRaw( x-FW*3,y,md2.srcRaw,editAtt);
      if(edit) CHECK_INCDEC_H_MODELVAR_BF(  md2.srcRaw, 0,NUM_XCHNRAW-1); //!! bitfield
      break;
    case 1:   lcd_outdezAtt(x-FW*0,y,md2.weight,editAtt);
      if(edit) CHECK_INCDEC_H_MODELVAR(  md2.weight, -125,125);
      break;
    case 2:   lcd_putsmAtt(x-FW*1,y,PSTR("+\t*\t="), md2.mixMode,editAtt);
      if(edit) CHECK_INCDEC_H_MODELVAR_BF(  md2.mixMode, 0,2);
      break;
    case 3:   
      if(md2.curveNeg&&md2.curve) lcd_putcAtt(x-FW*3+3,y,'!', editAtt);
      lcd_putsmAtt(x-FW*2,y,PSTR(CURV_STR),  md2.curve,editAtt);

      if(edit){
	int8_t cv = md2.curve; if(md2.curveNeg) cv=-cv;
	CHECK_INCDEC_H_MODELVAR(  cv, -7,7);
	md2.curve    = abs(cv);
	md2.curveNeg = cv<0;
      }
	
      if( mEdit &&  md2.curve>=1 && g_event==EVT_KEY_LONG(KEY_MENU)){ //_LONG
        s_curveChan = md2.curve-1;
	killEvents();
        pushMenu(menuProcCurveOne);
        return;
      }
      break;
    case 4:   putsDrSwitches(x-FW*4,  y,md2.swtch,editAtt);
      {
	int8_t sw=md2.swtch; if(sw<MIN_DRSWITCH) sw+=32;
	if(edit) {
	  CHECK_INCDEC_H_MODELVAR(  sw, MIN_DRSWITCH, MAX_DRSWITCH); //!! bitfield
	  md2.swtch=sw; //if(sw>15) sw-=32; 
	  CHECK_LAST_SWITCH(md2.swtch,EE_MODEL|_FL_POSNEG);
	}
	if( mEdit && abs(sw)>MAX_DRSWITCH_R && g_event==EVT_KEY_LONG(KEY_MENU)){ //LONG
          s_swNested = abs(sw)-MAX_DRSWITCH_R;
	  killEvents();
	  pushMenu(menuProcSwitchesNested);
	  return;
	}
	break;
      }
    case 15:
    case 5:   
      if(!md2.swtch){
	lcd_putsAtt(x-FW*2+2, y, PSTR("  "),editAtt);
	break;
      }
      if(which==15)
	lcd_putsmAtt(x-FW*2+2, y, PSTR("  \ti-\ti0\ti+"),md2.switchMode,editAtt);
      else
	lcd_putsmAtt(x, y, PSTR("oOff\tiNeg\tiNul\tiPos"),md2.switchMode,editAtt);
      //}
      if(edit){
	CHECK_INCDEC_H_MODELVAR_BF( md2.switchMode , 0,3);
      }
      break;
    case 6:   
      {
	lcd_puts_P(x-FW*4, y, PSTR(ARR_SW"  s"));
	uint16_t slope = slopeFull100ms(md2.speedDown);
	if(slope<100)  lcd_outdezAtt(x-FW*1,y,slope,   editAtt|PREC1);
	else           lcd_outdezAtt(x-FW*1,y,slope/10,editAtt);
	if(edit)  CHECK_INCDEC_H_MODELVAR_BF(  md2.speedDown, 0,15); //!! bitfield
	break;
      }
    case 7:
      {
	lcd_puts_P(x-FW*4, y, PSTR("  s"ARR_NE));
	uint16_t slope = slopeFull100ms(md2.speedUp);
	if(slope<100)  lcd_outdezAtt(x-FW*2,y,slope,   editAtt|PREC1);
	else           lcd_outdezAtt(x-FW*2,y,slope/10,editAtt);
	if(edit)  CHECK_INCDEC_H_MODELVAR_BF(  md2.speedUp, 0,15); //!! bitfield
	break;
      }
    case 8:   lcd_putsAtt(x-FW*6,y,PSTR("[MENU]"),editAtt);
      //if(edit && g_event==EVT_KEY_FIRST(KEY_MENU)){ //_LONG
      if(edit && g_event==EVT_KEY_LONG(KEY_MENU)){ //_LONG
        FL_INST.rmCurrLine();
	killEvents();
	popMenu();  
      }
      break;
  }
}

void menuProcMixOne()
{
  static MState2 mstate2;
  uint8_t x=TITLEP(FL_INST.currInsMode() ? PSTR("INSERT MIX ") : PSTR("EDIT MIX "));  
  MixData_r192 &md2 = g_model.mixData[FL_INST.editIDT()];
  putsChn(x,0,md2.destCh,0);
  MSTATE_CHECK0_V(9);
  int8_t  sub    = mstate2.m_posVert;


  uint8_t  y = FH*1;
  for(uint8_t i=0;i<=8;i++){
    uint8_t  x = FW*7;
    if(i==2){x+=FW*8; y-=FH;}
    if(i==5){x+=FW*7;y-=FH;}
    if(i==7){x+=FW*11;y-=FH;}
    if(i==8){y+=FH;}
    lcd_putsmAtt( FW*8, y,PSTR(" Src \t%  Op\t\tCurve\tSwtch\t\tSlope\t\t RM  "),i,INVERS);

    editMixVals(i,sub==i,x, y,FL_INST.editIDT());
    y+=FH;
  }

}

uint8_t chProcMixes(uint8_t*line, uint8_t setCh)
{
  MixData_r192 &md = *(MixData_r192*)line;
  if(setCh) md.destCh = setCh;
  return md.destCh;
}

uint8_t currMixerLine; //for debuginfo: mixer line values
int32_t currMixerVal;
int32_t currMixerSum;
void menuProcMix()
{
  static MState2 mstate2;
  uint8_t x=TITLE("MIXER  ");  
  //int8_t subOld  = mstate2.m_posVert;
#define MIX_COLS (6+2)
  MSTATE_TAB = {MIX_COLS};
  MSTATE_CHECK_VxH(4,menuTabModel,FL_INST.numWithHdr());
  int8_t  sub    = mstate2.m_posVert;
  int8_t  subHor = mstate2.m_posHorz;
  if(sub<1 || subHor==0)       mstate2.m_valEdit=0;

  //printf("menuProcMix.mstate2.m_posVert=%d\n",mstate2.m_posVert);

  MixData_r192  *md= g_model.mixData;
  FL_INST.init(g_model.mixData,DIM(g_model.mixData),sizeof(g_model.mixData[0]),chProcMixes,NUM_XCHNOUT);
  if(FL_INST.listEditMode(subHor==(MIX_COLS-1))) mstate2.m_valEdit=0;

  lcd_outdezAtt(  x, 0, FL_INST.fillLevel(),INVERS); //fill level




  static prog_uint8_t APM colPos[]={3*FW,7*FW-2,11*FW-3,14*FW-4,18*FW-4,20*FW-3,127};
  uint8_t y = 1*FH;
  for(FoldedList::Line* line=FL_INST.firstLine();
      line;
      line=FL_INST.nextLine(7), y+=FH
      )
  {
    if(line->showHeader){
      lcd_puts_P(     3*FW+2, y, PSTR("inp  % crv sw,mod"ARR_N_S));
    }  
    if(line->showCh){  
      putsChn(0,y,line->chId,FL_INST.isSelectedCh()?ATT_CSR_MV:0); // show CHx
    }
    if(line->showDat){ //show data 
      MixData_r192 &md2=md[line->idt];
      uint8_t  sel = FL_INST.isSelectedDat(); 
      bool lineEdit = 0;
      if(sel && FL_INST.listEditMode()) {sel=0; lineEdit=true;}
      if(sel && !mstate2.m_valEdit)     sel=2;

      if(sel) { //show diag values
        if(line->showCh) {
          if(subHor==2 && mstate2.m_posHorzChg==+1 ) mstate2.m_posHorz=subHor=3;
          if(subHor==1 && mstate2.m_posHorzChg==-1 ) mstate2.m_posHorz=subHor=0;
          if(subHor==1) subHor=2; //fake horiz-pos
        }
        currMixerLine = line->idt;
        lcd_outdez(  11*FW, 0, currMixerVal>>9);
        lcd_putc  (  11*FW, 0, '/');
        lcd_outdez(  15*FW+1, 0, currMixerSum>>9);
      }        
      for(uint8_t j=0; j<6; j++){
        if(j==0 && line->showCh) continue;
        static prog_uint8_t APM idx[]={2,0,1,3,4,15};

        editMixVals(pgm_read_byte(&idx[j]),
                    subHor==(j+1) ? sel : 0,
                    pgm_read_byte(&colPos[j]),   y,line->idt); //2op
        
      }
      if(md2.speedDown || md2.speedUp)lcd_putsAtt(20*FW+1, y, PSTR(ARR_NE),0);
      //if(lineEdit) lcd_barAtt( 4*FW,y,16*FW,BLINK);
      if(lineEdit) {
        lcd_barAtt( 4*FW,  y,128-5*FW-1,INVERS);
        if(BLINK_ON_PHASE)lcd_putsAtt( 128-FW,y,PSTR(ARR_N_S),0);
      }

    }
  } //for 7
  uint8_t what;
  switch(what=FL_INST.doEvent(sub,mstate2.m_posVertChg,subHor==0))
  {
    case FoldedListNew:
    case FoldedListNewEdit:
      {
        MixData_r192  *md = &g_model.mixData[FL_INST.editIDT()];
        md->destCh      = FL_INST.currDestCh(); //-s_mixTab[sub];
        md->srcRaw      = FL_INST.currDestCh()-1; //1;   //
        md->weight      = 100;
        // md->swtch       = 0; //no switch
        // md->curve       = 0; //linear
        // md->speedUp     = 0; //Servogeschwindigkeit aus Tabelle (10ms Cycle)
        // md->speedDown   = 0; //
      }
      if(what==FoldedListNew)break;
      //fallthrough
    case FoldedListEdit:
      pushMenu(menuProcMixOne);
      return;
      break;
    case FoldedListDup:
    case FoldedListSwap:
    default:;
      break;
  }
  mstate2.m_posVert=FL_INST.m_subIFL; //
  if(FL_INST.m_chnNav && mstate2.m_posVert) mstate2.m_posHorz=subHor=0;

}










uint16_t expou(uint16_t x,uint16_t x2, uint8_t k)
{
  // 7   9   9   9     7      9
  // k * x * x * x + (RK-k) * x
  // RK  RX  RX        RK 
  //(k * x * x     + (Rk-k)*4) * x2
  //     2**16                     RK*4
  
  uint32_t r32;
  r32  = x * k;    //9+7
  r32 *= x;        //25
  r32  = (uint8_t)(100u-k)*4u + (uint16_t)(r32>>16) ; //9
  r32 *= x2;       //18
  return r32/400;
  // return ((unsigned long)x*x*x2/0x10000*k/(RESXul*RESXul/0x10000) 
  //         +             (RESKul-k)*x2+RESKul/2)
  //  / RESKul;
}
// expo-funktion:
// ---------------
// kmplot
// f(x,k)=exp(ln(x)*k/10) ;P[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]
// f(x,k)=x*x*x*k/10 + x*(1-k/10) ;P[0,1,2,3,4,5,6,7,8,9,10]
// f(x,k)=x*x*k/10 + x*(1-k/10) ;P[0,1,2,3,4,5,6,7,8,9,10]
// f(x,k)=1+(x-1)*(x-1)*(x-1)*k/10 + (x-1)*(1-k/10) ;P[0,1,2,3,4,5,6,7,8,9,10]

int16_t expo2(int16_t x, int16_t x2, int8_t k)
{
  if(k == 0) return x2;
  int16_t   y;
  bool    neg =  x < 0;
  if(neg){   x = -x; x2=-x2;}
  if(k<0){
    y = RESXu-expou(RESXu-x,RESXu-x2,-k);
  }else{
    y = expou(x,x2,k);
  }
  return neg? -y:y;
}
inline int16_t expo(int16_t x, int8_t k)
{
  return expo2(x,x,k);
}




void editExpoVals(uint8_t which,uint8_t mEdit,uint8_t x, uint8_t y, uint8_t idt)
{
  bool     edit    = mEdit==1;
  uint8_t  editAtt = mEdit ? (edit ? ATT_CSR_EDT : ATT_CSR_MV ) : 0;
  ExpoData_r171 &ed = g_model.expoTab[idt];
  if(ed.mode3==EM_ALT_TRIM){
    ed.curve=0;
    ed.exp5&=3;
  }

  switch(which)
  {
    case 0:
      //x+=2*FW;
      x-=2*FW;
      lcd_putsmAtt( x, y,PSTR("\t" "<0\t" ">0\t" "  \t" "T-\t" "AT"),ed.mode3,editAtt);
      if(edit) CHECK_INCDEC_H_MODELVAR_BF(ed.mode3, EM_POS, EM_ALT_TRIM);
      break;
    case 1:
      //x+=4*FW;
      if(ed.mode3==EM_ALT_TRIM){
        lcd_putsmAtt( x-2*FW, y, PSTR("D1\tD2\tD4\tD8"),ed.exp5,editAtt);
        if(edit) CHECK_INCDEC_H_MODELVAR_BF(ed.exp5, 0, 3);
      }else{
        lcd_outdezAtt(x, y, idx2val15_100(ed.exp5), editAtt);
        if(edit) CHECK_INCDEC_H_MODELVAR_BF(ed.exp5,-15, 15);
      }
      break; 
    case 2:
      //x+=4*FW;
      if(ed.mode3==EM_ALT_TRIM){
        int8_t  itrim = ed.weight6;  
        int16_t vtrim = trimExpMu(abs(itrim),ed.exp5)*2; //promille

        lcd_outdezAtt(x, y, itrim <0 ? -vtrim : vtrim, editAtt|PREC1);
      }else{
        lcd_outdezAtt(x, y, idx2val30_100(ed.weight6), editAtt);
      }
      if(edit) CHECK_INCDEC_H_MODELVAR_BF(ed.weight6,-30,30);
      break; 
    case 3:
      {
	x-=4*FW-1;
	putsDrSwitches(x,y,ed.drSw,editAtt);
	int8_t sw=ed.drSw; if(sw<MIN_DRSWITCH) sw+=32;
	if(edit) {
	  CHECK_INCDEC_H_MODELVAR(sw,MIN_DRSWITCH,MAX_DRSWITCH); 
	  //if(sw>15) sw-=32; 
	  ed.drSw=sw; 
	  CHECK_LAST_SWITCH(ed.drSw,EE_MODEL);
	}
	//if( mEdit && abs(sw)>MAX_DRSWITCH_R && g_event==EVT_KEY_FIRST(KEY_MENU)){//_LONG
	if( mEdit && abs(sw)>MAX_DRSWITCH_R && g_event==EVT_KEY_LONG(KEY_MENU)){//_LONG
          s_swNested = abs(sw)-MAX_DRSWITCH_R;
	  killEvents();
	  pushMenu(menuProcSwitchesNested);
	  return;
	}
      }
      break; 
    case 4:
      //x+=1*FW;
      x-=2*FW;
      lcd_putsmAtt( x, y,PSTR(CURV_STR),ed.curve,editAtt);
      if(edit) CHECK_INCDEC_H_MODELVAR_BF(  ed.curve, 0,7); //!! bitfield
      //if(mEdit && ed.curve>=1 && g_event==EVT_KEY_FIRST(KEY_MENU)){//_LONG
      if(mEdit && ed.curve>=1 && g_event==EVT_KEY_LONG(KEY_MENU)){//_LONG
	s_curveChan = ed.curve-1;
	killEvents();
	pushMenu(menuProcCurveOne);
        return;
      }
      break;
    case 5:
      //x-=2*FW;
      x-=6*FW;
      lcd_putsAtt( x, y,PSTR("[MENU]"),editAtt);
      //if(edit && g_event==EVT_KEY_FIRST(KEY_MENU)){ //remove ok
      if(edit && g_event==EVT_KEY_LONG(KEY_MENU)){ //remove ok
        FL_INST.rmCurrLine();
	killEvents();
	popMenu();  
      }

      break; 
  }
}

void menuProcExpoOne()
{
  static MState2 mstate2;
  uint8_t x=TITLE("EXPO/DR ");  
  ExpoData_r171 &ed = g_model.expoTab[FL_INST.editIDT()];
  putsChnRaw(x,0,ed.chn,0);
  MSTATE_CHECK0_V(6);
  int8_t  sub    = mstate2.m_posVert;

  uint8_t  y = FH*2;

  for(uint8_t i=0;i<6;i++){
    lcd_putsm_P(0,y,ed.mode3==EM_ALT_TRIM?
                PSTR("Mode\t""TScale\t""Trim\t""DrSw\t""\t""RM"):
                PSTR("Mode\t""Expo\t""Weight\t""DrSw\t""Crv\t""RM")
                ,i);
    editExpoVals(i,sub==i,9*FW, y,FL_INST.editIDT());
    y+=FH;
  }
  if(ed.mode3==EM_ALT_TRIM) return;
  int8_t   kView = idx2val15_100(ed.exp5);
  int8_t   wView = idx2val30_100(ed.weight6);
  uint8_t  mode3  = ed.mode3;
 
#define WCHART 32
#define X0     (128-WCHART-2)
#define Y0     32
  for(int8_t xv=-WCHART;xv<WCHART;xv++)
  {
    int16_t yv=expo(xv*(RESX/WCHART),kView);
    if(ed.curve) yv = intpol(yv, ed.curve - 1);
    yv /= (RESX/WCHART);
    yv  = (yv * wView)/100;
    if((xv<0 && mode3==EM_POS)||(xv>0 && mode3==EM_NEG)||(mode3>=EM_BOTH)) lcd_plot(X0+xv, Y0-yv);
  }
  lcd_vline(X0,Y0-WCHART,WCHART*2);
  lcd_hline(X0-WCHART,Y0,WCHART*2);

  int16_t x512  = anaCalib[ed.chn];//FL_INST.currIDT()];
  int16_t y512  = expo(x512,kView);

  //dy/dx
  int16_t dy  = x512>0 ? y512-expo(x512-20,kView) : expo(x512+20,kView)-y512;
  //lcd_outdezNAtt(14*FW, 2*FH,   dy*(100/20), LEADING0|PREC2,3);
  lcd_outdezNAtt(14*FW, 2*FH,   dy*(100/20), 0,3);

  y512 = y512 * (wView / 4)/(100 / 4);
  lcd_outdezAtt( 19*FW, 6*FH,x512*25/((signed) RESXu/4), 0 );
  lcd_outdezAtt( 14*FW, 1*FH,y512*25/((signed) RESXu/4), 0 );
  x512 = X0+x512/(RESXu/WCHART);
  y512 = Y0-y512/(RESXu/WCHART);
  lcd_vline(x512, y512-3,3*2+1);
  lcd_hline(x512-3, y512,3*2+1);
  
}

uint8_t chProcExpos(uint8_t*line, uint8_t setCh)
{
  ExpoData_r171 &ed = *(ExpoData_r171*)line;
  if(setCh) ed.chn = setCh-1;
  return ed.chn+1;
}

void menuProcExpoAll()
{
  static MState2 mstate2;
  uint8_t x=TITLE("EXPO/DR  ");  
  //int8_t subOld  = mstate2.m_posVert;
#define EXP_COLS (5+2)
  MSTATE_TAB = {EXP_COLS};
  MSTATE_CHECK_VxH(3,menuTabModel,FL_INST.numWithHdr());
  int8_t  sub    = mstate2.m_posVert;
  int8_t  subHor = mstate2.m_posHorz;
  if(sub<1 || subHor==0)       mstate2.m_valEdit=0;

  FL_INST.init(g_model.expoTab,DIM(g_model.expoTab),sizeof(g_model.expoTab[0]),chProcExpos,4);
  if(FL_INST.listEditMode(subHor==(EXP_COLS-1))) mstate2.m_valEdit=0;

  lcd_outdezAtt(  x, 0, FL_INST.fillLevel(),INVERS); //fill level






  static prog_uint8_t APM colPos[]={6*FW,9*FW,12*FW+3,16*FW+2,20*FW-3,127};
  uint8_t y = 1*FH;
  for(FoldedList::Line* line=FL_INST.firstLine();
      line;
      line=FL_INST.nextLine(7), y+=FH
      )
  {
    if(line->showHeader){
      lcd_puts_P( 2*FW+2, y, PSTR("mod exp  % sw crv "ARR_N_S));
    }  
    if(line->showCh){  
      putsChnRaw( 0, y,line->chId-1,FL_INST.isSelectedCh()?ATT_CSR_MV:0);
    }
    if(line->showDat){ //show data 
      uint8_t  sel = FL_INST.isSelectedDat()?1:0;  //selected line
      bool lineEdit = 0;
      if(sel && FL_INST.listEditMode()) {sel=0; lineEdit=true;}
      if(sel && !mstate2.m_valEdit)     sel=2;
      for(uint8_t j=0; j<5; j++){
        editExpoVals(j,
                     subHor==(j+1) ? sel : 0,
                     pgm_read_byte(&colPos[j]),  y,line->idt);
      }
      //if(lineEdit) lcd_barAtt( 4*FW,y,16*FW,BLINK);
      if(lineEdit) {
        lcd_barAtt( 4*FW,  y,128-5*FW-1,INVERS);
        if(BLINK_ON_PHASE)lcd_putsAtt( 128-FW,y,PSTR(ARR_N_S),0);
      }
    }
  }
  uint8_t what;
  switch(what=FL_INST.doEvent
(sub,mstate2.m_posVertChg,subHor==0))
  {
    case FoldedListNew:
    case FoldedListNewEdit:
      {
        ExpoData_r171  *ed = &g_model.expoTab[FL_INST.editIDT()];
        ed->chn         = FL_INST.currDestCh()-1; //-s_mixTab[sub];
        ed->mode3       = EM_BOTH; //both neg+pos
        //ed->exp5        = 0;
        ed->weight6     = 30;
        //ed->drSw        = 0; //no switch
      }
      if(what==FoldedListNew)break;
      //fallthrough
    case FoldedListEdit:
      pushMenu(menuProcExpoOne);
      return;
      break;
    case FoldedListDup:
    case FoldedListSwap:
    default:;
      break;
  }
  mstate2.m_posVert=FL_INST.m_subIFL;
  if(FL_INST.m_chnNav && mstate2.m_posVert) mstate2.m_posHorz=subHor=0;

}

const prog_char APM s_charTab[]=" ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_-.";
#define NUMCHARS (sizeof(s_charTab)-1)

uint8_t char2idx(char c)
{
  for(int8_t ret=0;;ret++)
  {
    char cc= pgm_read_byte(s_charTab+ret);
    if(cc==c) return ret;
    if(cc==0) return 0;
  }
}
char idx2char(uint8_t idx)
{
  if(idx < NUMCHARS) return pgm_read_byte(s_charTab+idx);
  return ' ';
}

//#define UNIFIED 
void menuProcModel()
{
  static MState2 mstate2;
  uint8_t x=TITLE("SETUP ");  
  lcd_outdezNAtt(x+2*FW,0,g_eeGeneral.currModel+1,INVERS+LEADING0,2); 
  //#ifdef UNIFIED
  MSTATE_TAB = { 1,sizeof(g_model.name),4,2,1,1};
  MSTATE_CHECK_VxH(2,menuTabModel,5+1);
  uint8_t subHor = mstate2.m_posHorz+1;
  //#else
  //  MSTATE_TAB = { 1,(int8_t)-sizeof(g_model.name),-4,-2,1,1};
  //  MSTATE_CHECK_VxH(2,menuTabModel,5+1);
  //  uint8_t subHor = mstate2.m_posHorz;//+1;
  //#endif
  int8_t  sub    = mstate2.m_posVert-1;

  static uint8_t s_type;
  switch(g_event){
    case EVT_ENTRY:
      s_type=0;
      if(g_eeGeneral.currModel==0 && !g_model.mdVers)
        s_type = 1; //beim ersten Modell solls shon mal funktionieren
      break;
    case EVT_EXIT: 
      //(! g_model.mdVers && s_type)  {
      if (s_type)  {
        modelMixerDefault(s_type);
        eeDirty(EE_MODEL);
      }
      return;
  }

  uint8_t y=1*FH;
  for(uint8_t i=0; i<5; i++)
  {
    y+=FH;
    //#ifdef UNIFIED
    uint8_t attr = sub==i ? (mstate2.m_valEdit ? ATT_CSR_EDT : ATT_CSR_MV) : 0; 
    //#else
    //    uint8_t attr = sub==i ? ATT_CSR_EDT  : 0; 
    //#endif
    //if(i<3)
    lcd_putsmAtt(  0,    y,    PSTR("Name\t""Timer\t""Proto\t""Preset\t""RM"),i,0);//(subHor==0 && attr) ? INVERS : 0);
    //else        
    //  lcd_putsm_P(  0,    y,    PSTR("Type\t""RM"),i-3);
    switch(i){
      case 0:    
        lcd_putsnAtt(   8*FW, y, g_model.name ,sizeof(g_model.name),BSS_NO_INV);
        if(attr && subHor) {
          char v = char2idx(g_model.name[subHor-1]);
          //#ifdef UNIFIED
          if(attr == ATT_CSR_EDT){
            CHECK_INCDEC_H_MODELVAR_BF( v ,0,NUMCHARS-1);
          }
          //#else
          //          CHECK_INCDEC_V_MODELVAR_BF( v ,0,NUMCHARS-1);
          //#endif
          v = idx2char(v);
          g_model.name[subHor-1]=v;
          lcd_putcAtt((8+subHor-1)*FW, y, v,attr);
        }
        break;
      case 1:
        putsTime(       7*FW-2, y, g_model.tmrVal,
                        ( subHor==1 ? attr:0),
                        ( subHor==2 ? attr:0) );
        lcd_putsmAtt(  14*FW, y, PSTR("OFF\tABS\tTHR\tTHR%"),g_model.tmrMode,
                       ( subHor==3 ? attr:0));
        putsDrSwitches(17*FW, y, g_model.tmrSw , ( subHor==4 ? attr:0));

        if(attr==ATT_CSR_EDT) switch(subHor) 
        {
          case 1:
            {
              int8_t min=g_model.tmrVal/60;
              //#ifdef UNIFIED
              CHECK_INCDEC_H_MODELVAR_BF( min ,0,59);
              //#else
              //              CHECK_INCDEC_V_MODELVAR_BF( min ,0,59);
              //#endif
              g_model.tmrVal = g_model.tmrVal%60 + min*60;
              break;
            }
          case 2:
            {
              int8_t sec=g_model.tmrVal%60;
              //#ifdef UNIFIED
              sec -= checkIncDec_hm( sec+2 ,1,62)-2;
              //#else
              //              sec -= checkIncDec_vm( sec+2 ,1,62)-2;
              //#endif
              g_model.tmrVal -= sec ;
              if((int16_t)g_model.tmrVal < 0) g_model.tmrVal=0;
              break;
            }
          case 3:
            //#ifdef UNIFIED
            CHECK_INCDEC_H_MODELVAR_BF( g_model.tmrMode ,0,3);
            //#else
            //            CHECK_INCDEC_V_MODELVAR_BF( g_model.tmrMode ,0,3);
            //#endif
            break;
          case 4:
            {
              int8_t sw = g_model.tmrSw; if(sw<MIN_DRSWITCH) sw+=32;
              //#ifdef UNIFIED
              CHECK_INCDEC_H_MODELVAR_BF( sw, MIN_DRSWITCH, MAX_DRSWITCH);
              //#else
              //              CHECK_INCDEC_V_MODELVAR_BF( sw, MIN_DRSWITCH, MAX_DRSWITCH);
              //#endif
              g_model.tmrSw = sw;
            }
            break;
        }
        break;
      case 2:  
        {
          typedef PROGMEM const char* prog_charp;
          static const prog_char APM p0[]="\x00""-";
          static const prog_char APM p1[]="\x02""A\tB\tC\t";
          static const prog_char APM p2[]="\x00""-";
          static const prog_char APM p3[]="\x02""A\tB\tC\t";
          static const prog_char APM p4[]="\x05""A\tB\tC\tA=\tB=\tC=\t";
          static const prog_char APM p5[]="\x00""-";
          //static const prog_char* protTab[]  ={p0,p1,p2,p3,p4,p5};
          static prog_charp APM protTab[]  ={p0,p1,p2,p3,p4,p5};
	  const prog_char* p = (const prog_char*)pgm_read_adr(&protTab[min<uint8_t>(g_model.protocol,5)]);

	  lcd_putsmAtt(   8*FW, y, PSTR(PROT_STR),g_model.protocol,( subHor==1 ? attr:0));
	  lcd_putsmAtt(   14*FW, y, p+1,min<uint8_t>(g_model.protocolPar,pgm_read_byte(p)),( subHor==2 ? attr:0));
	  if(attr==ATT_CSR_EDT) switch(subHor)    {
            //#ifdef UNIFIED
	  case 1: CHECK_INCDEC_H_MODELVAR_BF(g_model.protocol,0,PROT_MAX);	    break;
	  case 2: CHECK_INCDEC_H_MODELVAR_BF(g_model.protocolPar,0,pgm_read_byte(p));break;
            //#else
            //	  case 1: CHECK_INCDEC_V_MODELVAR_BF(g_model.protocol,0,PROT_MAX);	    break;
            //	  case 2: CHECK_INCDEC_V_MODELVAR_BF(g_model.protocolPar,0,pgm_read_byte(p));break;
            //#endif
	  }
        }
	break;
      case 3:
        if(g_model.mdVers && s_type==0)
          lcd_putsAtt(  FW*8, y, PSTR("modif!"),attr?INVERS:0);
        else
          lcd_putsAtt(  FW*8, y, modelMixerDefaultName(s_type),attr);
        if(attr){
          checkIncDecGen2( &s_type, 0, modelMixerDefaults-1, 0);
        }
        //}else{
        //lcd_putsAtt(  FW*8, y, PSTR("modif."),attr?INVERS:0);
        //}
        y+=FH;
        break;
      case 4:
        //lcd_putsAtt(    0, (7)*FH, PSTR("RM"),attr);
        lcd_putsAtt(  FW*8, y, PSTR("[MENU LONG]"),attr);
        if(attr){
          if(g_event==EVT_KEY_LONG(KEY_MENU)){ //rm mit LONG??
            killEvents();
            EFile::rm(FILE_MODEL(g_eeGeneral.currModel)); //delete file
            eeLoadModel(g_eeGeneral.currModel); //load default values
            chainMenu(menuProcModelSelect);
          }
        }       
    }//switch(i)
  }
}
void menuProcModelSelect()
{
  static uint8_t s_listEditMode;
  static MState2 mstate2;
  TITLE("MODELSEL");  
  lcd_puts_P(     10*FW, 0, PSTR("free"));
  lcd_outdezAtt(  18*FW, 0, EeFsGetFree(),0);
  lcd_putsAtt(128-FW*3,0,PSTR("1/8"),INVERS);
  int8_t subOld  = mstate2.m_posVert;
  MSTATE_CHECK0_V(MAX_MODELS);
  int8_t  sub    = mstate2.m_posVert;
  static uint8_t s_pgOfs;
  switch(g_event)
  {
    //case  EVT_KEY_FIRST(KEY_MENU):
    case  EVT_KEY_FIRST(KEY_EXIT):
      if(s_listEditMode){
        s_listEditMode = false;
        beepKey();
        killEvents();
        break;
      }
      //fallthrough
    case  EVT_KEY_BREAK(KEY_MENU): //shortcut
    case  EVT_KEY_FIRST(KEY_RIGHT):
      if(g_eeGeneral.currModel != mstate2.m_posVert)
      {
        eeLoadModel(g_eeGeneral.currModel = mstate2.m_posVert);
        eeDirty(EE_GENERAL);
        LIMITS_DIRTY;
        beepKey();
      }
      //case EXIT handled in checkExit
      if(g_event!=EVT_KEY_FIRST(KEY_EXIT))  chainMenu(menuProcModel);
      break;
    case  EVT_KEY_LONG(KEY_MENU): // edit line mit pos??
      if(!s_listEditMode){
        s_listEditMode = true;
        beepKey();
      }else{
        if(eeDuplicateModel(sub)) {
          beepKey();
          s_listEditMode = false;
        }
        else beepWarnNoDup(); //model duplicate not possible
      }
      killEvents();
      break;

    case EVT_ENTRY:
      s_listEditMode = false;
      
      mstate2.m_posVert = g_eeGeneral.currModel;
      eeCheck(true); //force writing of current model data before this is changed
      break;
  }
  if(s_listEditMode && subOld!=sub){
    EFile::swap(FILE_MODEL(subOld),FILE_MODEL(sub));
  }

  if(sub-s_pgOfs < 1)        s_pgOfs = max(0,sub-1);
  else if(sub-s_pgOfs >4 )  s_pgOfs = min(MAX_MODELS-6,sub-4);
  for(uint8_t i=0; i<6; i++){
    uint8_t y=(i+2)*FH;
    uint8_t k=i+s_pgOfs;
    lcd_outdezNAtt(  2*FW, y, k+1, ((sub==k) ? (s_listEditMode ? INVERS : ATT_CSR_EDT ) : 0) + LEADING0,2);
    static char buf[sizeof(g_model.name)+8];
    eeLoadModelName(k,buf,sizeof(buf));
    lcd_putsnAtt(  3*FW, y, buf,sizeof(buf),BSS_NO_INV|((sub==k) ? (s_listEditMode ? ATT_CSR_EDT : 0 ) : 0));
  }

}


#ifdef SIM
void menuProcDisplayTest()
{
  static MState2 mstate2;
  TITLE("CALIB");
  MSTATE_CHECK_V(9,menuTabDiag,4);
  static int x0,y0;
  switch(g_event)
  {
    case EVT_KEY_REPT(KEY_RIGHT):
    case EVT_KEY_FIRST(KEY_RIGHT):
      x0+=1;
      break;
    case EVT_KEY_REPT(KEY_LEFT):
    case EVT_KEY_FIRST(KEY_LEFT):
      x0-=1;
      break;
    case EVT_KEY_REPT(KEY_DOWN):
    case EVT_KEY_FIRST(KEY_DOWN):
      y0+=1;
      break;
    case EVT_KEY_REPT(KEY_UP):
    case EVT_KEY_FIRST(KEY_UP):
      y0-=1;
      break;
  }

  for(int i=0; i<30; i++)
  {
    lcd_vline(x0+i,y0,i);
    lcd_hline(x0+40,y0+i,i);
  }
}
#endif
void menuProcDiagCalib()
{
  static MState2 mstate2;
  TITLE("CALIB");
  MSTATE_CHECK_V(8,menuTabDiag,4);
  int8_t  sub    = mstate2.m_posVert ;
  static int16_t midVals[7];
  static int16_t loVals[7];
  static int16_t hiVals[7];

  for(uint8_t i=0; i<7; i++) { //get low and high vals for sticks and trims
    int16_t vt = anaIn(i);
    loVals[i] = min(vt,loVals[i]);
    hiVals[i] = max(vt,hiVals[i]);
    if(i>=4) midVals[i] = (loVals[i] + hiVals[i])/2;
  }

  switch(g_event)
  {
    case EVT_ENTRY:
      for(uint8_t i=0; i<7; i++) loVals[i] = 15000;
      break;
    case EVT_KEY_BREAK(KEY_DOWN): // !! achtung sub schon umgesetzt
      switch(sub)
      {
        case 2: //get mid
          for(uint8_t i=0; i<4; i++)midVals[i] = anaIn(i);
          beepKey();
          break;
        case 3: 
          printf("do calib");
          for(uint8_t i=0; i<7; i++)
            if(hiVals[i]-loVals[i]>50) {
            g_eeGeneral.calibMid[i]  = midVals[i];
              int16_t v = midVals[i] - loVals[i];
            g_eeGeneral.calibSpanNeg[i] = v - v/64;
              v = hiVals[i] - midVals[i];
            g_eeGeneral.calibSpanPos[i] = v - v/64;
          }
          //int16_t sum=0;
          //for(uint8_t i=0; i<12;i++) sum+=g_eeGeneral.calibMid[i];
          //g_eeGeneral.chkSum = sum;
          eeDirty(EE_GENERAL); //eeWriteGeneral();
          beepKey();
          break;
      }
      break;
  }
  for(uint8_t i=1; i<4; i++)
  {
    uint8_t y=i*FH+FH;
    lcd_putsmAtt( 0, y,PSTR("\tSetMid\tMovArnd\tDone"),i,
                    sub==i ? INVERS : 0);
  }
  for(uint8_t i=0; i<7; i++)
  {
    uint8_t y=i*FH+0;
    lcd_puts_P( 11*FW,  y+1*FH, PSTR("<    >"));  
    lcd_outhex4( 8*FW-3,y+1*FH, sub==2 ? loVals[i]  :g_eeGeneral.calibSpanNeg[i]);
    lcd_outhex4(12*FW,  y+1*FH, sub==1 ? anaIn(i) : (sub==2 ? midVals[i] :g_eeGeneral.calibMid[i]));
    lcd_outhex4(17*FW,  y+1*FH, sub==2 ? hiVals[i]  :g_eeGeneral.calibSpanPos[i]);
  }

}
void menuProcDiagAna()
{
  static MState2 mstate2;
  TITLE("ANA");  
  MSTATE_CHECK_V(7,menuTabDiag,9);
  int8_t  sub    = mstate2.m_posVert-1 ;
  for(uint8_t i=0; i<8; i++)
  {
    uint8_t y=i*FH;
    lcd_putsnAtt( 4*FW, y,PSTR("A1A2A3A4A5A6A7A8")+2*i,2,sub==i ? INVERS : 0);  
    //lcd_outhex4( 8*FW, y,g_anaIns[i]);
    lcd_outhex4( 7*FW, y,anaIn(i));
    if(i<7){
      //int16_t v = g_anaIns[i];
      int16_t v = anaIn(i) - g_eeGeneral.calibMid[i];
      v =  v*50/max(1, (v > 0 ? g_eeGeneral.calibSpanPos[i] :  g_eeGeneral.calibSpanNeg[i])/2);
      lcd_outdez(15*FW, y, v);
        //lcd_outdez(17*FW, y, (v-g_eeGeneral.calibMid[i])*50/ max(1,g_eeGeneral.calibSpan[i]/2));
    }
    if(i==7){
      putsVBat(12*FW,y,sub==7 ? ATT_CSR_EDT : 0);
    }
  }
  if(sub==7){
   CHECK_INCDEC_H_GENVAR( g_eeGeneral.vBatCalib, -127, 127);
  }
#ifdef WITH_ADC_STAT
  switch(g_event)
    {
      case EVT_KEY_FIRST(KEY_MENU): //ok
      g_rawPos=0;
      break;
    }
  g_rawChan=sub;
  for(uint8_t j=0; j<DIM(g_rawVals); j++){
    lcd_outdez(20*FW+2 , (j+1)*FH, g_rawVals[j]);
  }
#endif
}

void menuProcDiagKeys()
{
  static MState2 mstate2;
  TITLE("DIAG");  
  MSTATE_CHECK_V(6,menuTabDiag,1);

  uint8_t x;

  x=7*FW;
  for(uint8_t i=0; i<9; i++)
  {
    uint8_t y=i*FH; //+FH;
    if(i>(SW_ID0-SW_BASE_DIAG)) y-=FH; //overwrite ID0
    bool t=keyState((EnumKeys)(SW_BASE_DIAG+i));
    putsDrSwitches(x,y,i+1,0); //ohne off,on
    lcd_putcAtt(x+FW*4+2,  y,t+'0',t ? INVERS : 0);
  }

  x=0;
  for(uint8_t i=0; i<6; i++)
  {
    uint8_t y=(5-i)*FH+2*FH;
    bool t=keyState((EnumKeys)(KEY_MENU+i)); //ok
    lcd_putsm_P(x, y,PSTR(" Menu\t Exit\t Down\t   Up\tRight\t Left"),i);  
    lcd_putcAtt(x+FW*5+2,  y,t+'0',t);
  }


  x=14*FW;
  lcd_puts_P(x, 3*FH,PSTR("Trim- +"));  
  for(uint8_t i=0; i<4; i++)
  {
    uint8_t y=i*FH+FH*4;
    lcd_img(    x,       y, sticks,i,0);
    bool tm=keyState((EnumKeys)(TRM_BASE+2*i));
    bool tp=keyState((EnumKeys)(TRM_BASE+2*i+1));
    lcd_putcAtt(x+FW*4,  y, tm+'0',tm ? INVERS : 0);
    lcd_putcAtt(x+FW*6,  y, tp+'0',tp ? INVERS : 0);
  }
}
void menuProcDiagVers()
{
  static MState2 mstate2;
  TITLE("VERSION");
  MSTATE_CHECK_V(5,menuTabDiag,1);

  lcd_puts_P(0, 2*FH,stamp4 ); 
  lcd_puts_P(0, 3*FH,stamp1 ); 
  lcd_puts_P(0, 4*FH,stamp2 ); 
  lcd_puts_P(0, 5*FH,stamp3 ); 
}

void menuProcTrainer()
{
  static MState2 mstate2;
  TITLE("TRAINER");  
  MSTATE_TAB = { 4,4};
  MSTATE_CHECK_VxH(4,menuTabDiag,1+1+4+1);
  int8_t  sub    = mstate2.m_posVert;//-1 ;
  uint8_t subHor = mstate2.m_posHorz+1;
  if(sub<=1)       mstate2.m_valEdit=0;
  uint8_t y;

  if(PING & (1<<INP_G_RF_POW)) // i am the slave
  {
    lcd_puts_P(  7*FW,3*FH , PSTR("Slave"));
    return;
  }
  
  for(uint8_t i=0; i<4; i++){
    //lcd_puts_P( 3*FW, 1*FH,PSTR("mode prc src swt"));
    lcd_putsmAtt( 3*FW+i*4*FW, 1*FH,PSTR("mode\t"" prc\t"" src\t"" swt"),i,(sub==1 && mstate2.m_posHorz==i) ? INVERS : 0);
  }
//   if(sub==1){
//     checkIncDecGen2( &mstate2.m_posHorz, 0, 3, 0);
//   }
  sub-=2;
  for(uint8_t iLog=0; iLog<4; iLog++){
    y=(iLog+2)*FH;
    TrainerData1_r0*  td = &g_eeGeneral.trainer.chanMix[iLog];
    putsChnRaw( 0, y,iLog,0);

    for(uint8_t j=1; j<=4;j++){
      uint8_t attr = ATTR(iLog,j);
      bool    edit = attr == ATT_CSR_EDT;

      switch(j)
      {
        case 1:

          //    edit = (sub==iLog && subHor==1);
          lcd_putsmAtt(   4*FW, y, PSTR("off\t +=\t :="),td->mode,  attr);
          if(edit) td->mode = checkIncDec_hg(  td->mode, 0,2); //!! bitfield

          break;        
        case 2:
          //   edit = (sub==iLog && subHor==2);
          lcd_outdezAtt( 11*FW, y, td->studWeight*13/4,attr);
          if(edit) td->studWeight = checkIncDec_hg(  td->studWeight, -31,31); //!! bitfield

          break;        
        case 3:
          //    edit = (sub==iLog && subHor==3);
          lcd_putsmAtt(  12*FW, y, PSTR("ch1\tch2\tch3\tch4\tch5\tch6\tch7\tch8"),td->srcChn, attr);
          if(edit) td->srcChn = checkIncDec_hg(  td->srcChn, 0,7); //!! bitfield

          break;        
        case 4:
          //edit = (sub==iLog && subHor==4);
          putsDrSwitches(15*FW, y, td->swtch, attr);
          if(edit) {
            td->swtch = checkIncDec_hg(  td->swtch,  MIN_DRSWITCH_R, MAX_DRSWITCH_R); //!! bitfield
            CHECK_LAST_SWITCH(td->swtch,EE_GENERAL|_FL_POSNEG);
          }

      }
    }
  }
  bool edit = (sub==4);
  y    = 6*FH;
  lcd_putsAtt(  0*FW, y, PSTR("Cal"),(sub==4) ? ATT_CSR_EDT : 0);
  if(g_trainerSlaveActiveChns){
    uint8_t x = 7*FW;
    for(uint8_t i=0; i<g_trainerSlaveActiveChns; i++)
    {
      if(i==4){y+=FH;x=7*FW;}
      lcd_outdezAtt( x , y, (g_ppmIns[i]-g_eeGeneral.trainer.calib[i])*2,PREC1 );
      x+=4*FW;
    }
    if(edit)
    {
      if(g_event==EVT_KEY_LONG(KEY_MENU)){ //edit = do uncalib
        killEvents();
        memset(g_eeGeneral.trainer.calib,0,sizeof(g_eeGeneral.trainer.calib));
        beepKey();
      }
      if(g_event==EVT_KEY_BREAK(KEY_MENU)){ //edit = docalib
        memcpy(g_eeGeneral.trainer.calib,g_ppmIns,sizeof(g_eeGeneral.trainer.calib));
        eeDirty(EE_GENERAL);
        beepKey();
      }
    }
  }
  
}
void menuProcSetup2()
{
  static MState2 mstate2;
  TITLE("WARNINGS");  
  MSTATE_CHECK_V(3,menuTabDiag,1+5);
  int8_t  sub    = mstate2.m_posVert-1 ;
  for(uint8_t i=0; i<5; i++){
    uint8_t y=i*FH+1*FH;
    uint8_t attr = sub==i ? ATT_CSR_EDT : 0; 
    lcd_putsmAtt( FW*5,y,PSTR("  THR pos\t"
                              "  Switches\t"
                              "  Mem free\t"
                              "V Bat low\t"
                              "m Inactive\t"
			      ),i,0);
    switch(i){
      case 0: //"THR pos "
      case 1: //"Switches"
      case 2: //"Mem free"
        {
          uint8_t bit = 1<<i;
          bool    val = !(g_eeGeneral.warnOpts & bit);
          lcd_putsAtt( FW*2, y, val ? PSTR("ON"): PSTR("OFF"),attr);
          if(attr)  {
            val = checkIncDec_hg(  val, 0, 1); //!! bitfield
            if(checkIncDec_Ret && (i==0) && val) // THR warn changed
              setTHR0pos();
          }
          g_eeGeneral.warnOpts |= bit;
          if(val) g_eeGeneral.warnOpts &= ~bit;


          break;
        }
      case 3://"Bat low "
        lcd_outdezAtt(4*FW,y,g_eeGeneral.vBatWarn,attr|PREC1);
        if(attr){
          CHECK_INCDEC_H_GENVAR( g_eeGeneral.vBatWarn, 50, 120); //5-10V
        }
        break;
      case 4://"Inactive"
        lcd_outdezAtt(4*FW,y,g_eeGeneral.inactivityMin,attr);
        if(attr){
          CHECK_INCDEC_H_GENVAR( g_eeGeneral.inactivityMin, 0, 30);
        }
        break;
    }
  }
}
static prog_uint8_t APM s_istTmrVals1[]={ 0,10,20,40}; 
static prog_uint8_t APM s_istTmrVals2[]={ 5,10,20,40}; 
void menuProcSetup1()
{
  static MState2 mstate2;
  TITLE("SETUP BASIC2");  
  MSTATE_CHECK_V(2,menuTabDiag,1+5);
  int8_t  sub    = mstate2.m_posVert-1 ;

  uint8_t y=2*FH;
  for(uint8_t i=0; i<5; i++,y += FH){
    uint8_t attr = sub==i ? ATT_CSR_EDT : 0; 
    lcd_putsmAtt( FW*6,y,PSTR(
			      "  Inst Trim\t"
                              "s  setup dly\t"
                              "s  lease dly\t"
			      "s Key Long\t"
			      "  Navigation\t"
			      ),i,0);
    switch(i){
      case 0:// "instant trim switch"
#define TrimSwitch (MAX_DRSWITCH_R-g_eeGeneral.iTrimSwitch)
	putsDrSwitches(2*FW,y,TrimSwitch,attr);
        if(attr){
          CHECK_INCDEC_H_GENVAR_BF( g_eeGeneral.iTrimSwitch, 0, MAX_DRSWITCH_R-1);
        }
        break;
      case 1:// "instant trim switch"
        lcd_outdezAtt( FW*6, y, pgm_read_byte(&s_istTmrVals1[g_eeGeneral.iTrimTme1]),attr+PREC1);
        if(attr){
          CHECK_INCDEC_H_GENVAR_BF( g_eeGeneral.iTrimTme1, 0, 3);
        }
        break;
      case 2:// "instant trim switch"
        lcd_outdezAtt( FW*6, y, pgm_read_byte(&s_istTmrVals2[g_eeGeneral.iTrimTme2]),attr+PREC1);
        if(attr){
          CHECK_INCDEC_H_GENVAR_BF( g_eeGeneral.iTrimTme2, 0, 3);
        }
        break;
      case 3:// Keyspeed
        lcd_outdezAtt( FW*6, y, (g_eeGeneral.keySpeed+2)*13,attr|PREC2);
        if(attr)  CHECK_INCDEC_H_GENVAR_BF(g_eeGeneral.keySpeed,0,3);
        break;
      case 4:// Navigation
        lcd_putsmAtt(  0*FW, y, PSTR("simple\tadvncd"),g_eeGeneral.naviMode,attr);
        if(attr)  CHECK_INCDEC_H_GENVAR_BF(g_eeGeneral.naviMode,0,1);
        break;
    }
  }
}
void menuProcSetup0()
{
  static MState2 mstate2;
  TITLE("SETUP BASIC1");  
  MSTATE_CHECK_V(1,menuTabDiag,1+5);
  int8_t  sub    = mstate2.m_posVert-1 ;

  uint8_t y=1*FH;
  for(uint8_t i=0; i<5; i++,y += FH){
    
    uint8_t attr = sub==i ? ATT_CSR_EDT : 0; 
    lcd_putsmAtt( FW*8,y,PSTR("Contrast\t"
			      "AdcFilt.\t"
			      "Light\t"
			      "BeepMod\t"
			      //"InstTrim  s   s\t\t\t"
			      ),i,0);
    switch(i){
      case 0: //Contrast
        lcd_outdezAtt(6*FW,y,g_eeGeneral.contrast,attr);
        if(attr){
          CHECK_INCDEC_H_GENVAR( g_eeGeneral.contrast, 20, 45);
          lcdSetRefVolt(g_eeGeneral.contrast);
        }
        break;
      case 1://"AdcFilt."
        lcd_outdezAtt( FW*6, y, g_eeGeneral.adcFilt,attr);
        if(attr)  CHECK_INCDEC_H_GENVAR_BF(g_eeGeneral.adcFilt,0,3);
        break;
      case 2://Light
        if(g_eeGeneral.lightSw<=MAX_DRSWITCH_R){
          putsDrSwitches(2*FW,y,g_eeGeneral.lightSw,attr);
        }else{
          uint8_t sec6=(g_eeGeneral.lightSw-MAX_DRSWITCH_R);
          if(sec6>10) sec6=5*(sec6-8);
          lcd_outdezAtt(6*FW,y,sec6,(attr)|PREC1);
          lcd_puts_P( 6*FW,y, PSTR("m"));
        }
        if(attr){
          CHECK_INCDEC_H_GENVAR( g_eeGeneral.lightSw, MIN_DRSWITCH_R, MAX_DRSWITCH_R+20);
          CHECK_LAST_SWITCH(g_eeGeneral.lightSw,EE_GENERAL|_FL_POSNEG);
        }
        break;
      case 3:// "Beeper  "

        lcd_putsmAtt(  0*FW, y, PSTR(" quiet\tsilent\tnormal\t  loud"),g_eeGeneral.beepVol,attr);
  //lcd_outdezAtt( FW*4, y, g_eeGeneral.beepVol,attr);
        if(attr)  CHECK_INCDEC_H_GENVAR_BF(g_eeGeneral.beepVol,0,3);
        break;
      case 4://stick Mode
        y += FH;
        lcd_putsAtt( 1*FW, y, PSTR("Mode"),0);//sub==3?INVERS:0);
        lcd_putcAtt( 3*FW, y+FH, '1'+g_eeGeneral.stickMode,attr);
        for(uint8_t i=0; i<4; i++)
        {
          lcd_img(    (6+4*i)*FW, y,   sticks,i,0);
          putsChnRaw( (6+4*i)*FW, y+FH,convertMode(i),0);//sub==3?BLINK:0);
        }
        if(attr){
          CHECK_INCDEC_H_GENVAR_BF(g_eeGeneral.stickMode,0,3);
        }
        break;
    }
  }
}

uint16_t s_timeCumTot;    //sec seit einschalten
uint16_t s_timeCumAbs;    //sec seit letztem timer null (EXIT-LONG)
uint16_t s_timeCumThr;    //sec seit letztem timer null (EXIT-LONG) nur  THR
uint16_t s_timeCum16ThrP; //1/16 sec seit letztem timer null (EXIT-LONG) THR%
uint8_t  s_timerState;
#define TMR_OFF     0
#define TMR_RUNNING 1
#define TMR_BEEPING 2
#define TMR_BEEPSTOPPED 3
int16_t  s_timerVal;
void timer(uint8_t val)
{
  static uint16_t s_time;
  static uint16_t s_cnt;
  static uint16_t s_sum;
  s_cnt++;
  s_sum+=val;
  if((g_tmr10ms-s_time)<100) //1 sec
    return;
  s_time += 100;
  val     = s_sum/s_cnt;
  s_sum  -= val*s_cnt; //rest
  s_cnt   = 0;

  s_timeCumTot           += 1; 

  if(getSwitch(g_model.tmrSw,1)){
    s_timeCumAbs           += 1;
    if(val) s_timeCumThr   += 1;
    s_timeCum16ThrP        += val/2;
  }

  s_timerVal = g_model.tmrVal;
  switch(g_model.tmrMode)
  {
    case TMRMODE_NONE:
      s_timerState = TMR_OFF;
      return;
    case TMRMODE_THR_REL:
      s_timerVal -= s_timeCum16ThrP/16;
      break;
    case TMRMODE_THR:     
      s_timerVal -= s_timeCumThr;
      break;
    case TMRMODE_ABS:
      s_timerVal -= s_timeCumAbs;
      break;
  }
  switch(s_timerState)
  {
    case TMR_OFF:
      if(g_model.tmrMode != TMRMODE_NONE) s_timerState=TMR_RUNNING;
      break;
    case TMR_RUNNING:
      //if(s_timerVal<=0 && g_model.tmrVal) s_timerState=TMR_BEEPING;
      if(s_timerVal<=MAX_ALERT_TIME && g_model.tmrVal) s_timerState=TMR_BEEPING;
      break;
    case TMR_BEEPING:
      //if(s_timerVal <= -MAX_ALERT_TIME)   s_timerState=TMR_STOPPED;
      if(s_timerVal < 0)                  s_timerState=TMR_BEEPSTOPPED;
      if(g_model.tmrVal == 0)             s_timerState=TMR_RUNNING;
      break;
    case TMR_BEEPSTOPPED:
      break;
  }

  if(s_timerState==TMR_BEEPING){
    static int16_t last_tmr;
    if(last_tmr != s_timerVal){
      last_tmr   = s_timerVal;
      if(s_timerVal>20  )       {if((s_timerVal&1)==0)beepTmr();}
      else if(s_timerVal>10  )  {beepTmr();}
      else if(s_timerVal>0)     {beepTmrDbl();}
      else                      {beepTmrLong();}
    }
  }
}


#define MAXTRACE 120
uint8_t s_traceBuf[MAXTRACE];
uint16_t s_traceWr;
uint16_t s_traceCnt;
void trace(uint8_t val)
{
  if(val>31)val=31;
  if(g_eeGeneral.thr0pos > 8) val=31-val; //inverted throttle usage

  timer(val);
  static uint16_t s_time;
  static uint16_t s_cnt;
  static uint16_t s_sum;
  s_cnt++;
  s_sum+=val;
  if((g_tmr10ms-s_time)<1000) //10 sec
    return;
  s_time= g_tmr10ms;
  val   = s_sum/s_cnt;
  s_sum = 0;
  s_cnt = 0;


  s_traceCnt++;
  s_traceBuf[s_traceWr++] = val;
  if(s_traceWr>=MAXTRACE) s_traceWr=0;
}


uint8_t g_tmr1Latency_max;
uint8_t g_tmr1Latency_min = 0xff;
uint16_t g_timeMain;
uint16_t g_timePerOut;
void menuProcStatistic2()
{
  TITLE("STAT2");  
  switch(g_event)
  {
    case EVT_KEY_FIRST(KEY_MENU): //reset vals
      g_tmr1Latency_min = 0xff;
      g_tmr1Latency_max = 0;
      g_timeMain    = 0;
      g_timePerOut  = 0;
      g_badAdc=g_allAdc=0;
      beepKey();
      break;
    case EVT_KEY_FIRST(KEY_DOWN):
      chainMenu(menuProcStatistic); 
      break;
    case EVT_KEY_FIRST(KEY_UP):
    case EVT_KEY_FIRST(KEY_EXIT):
      chainMenu(menuProc0); 
      break;
  }
  lcd_puts_P( 0*FW,  1*FH, PSTR("tmr1Lat max    us"));
  lcd_outdezAtt(14*FW , 1*FH, g_tmr1Latency_max*5,PREC1);
  lcd_puts_P( 0*FW,  2*FH, PSTR("tmr1Lat min    us"));
  lcd_outdezAtt(14*FW , 2*FH, g_tmr1Latency_min*5,PREC1 );
  lcd_puts_P( 0*FW,  3*FH, PSTR("tmr1 Jitter    us"));
  lcd_outdez(14*FW , 3*FH, (g_tmr1Latency_max - g_tmr1Latency_min) /2 );
  lcd_puts_P( 0*FW,  4*FH, PSTR("tmain          ms"));
  lcd_outdezAtt(14*FW , 4*FH, g_timeMain*5/8,PREC1 );
  lcd_puts_P( 0*FW,  5*FH, PSTR("tperOut        ms"));
  lcd_outdezAtt(14*FW , 5*FH, g_timePerOut*5/8 ,PREC1);
  
  lcd_puts_P( 0*FW,  6*FH, PSTR("adc err        %"));

  if(g_allAdc > 300 ){
    g_allAdc /= 4;
    g_badAdc /= 4;
  }
  if(g_allAdc) lcd_outdez(14*FW , 6*FH, g_badAdc*100/g_allAdc );

  
}

void menuProcStatistic()
{
  TITLE("STAT");  
  switch(g_event)
  {
    case EVT_KEY_FIRST(KEY_UP):
      chainMenu(menuProcStatistic2); 
      break;
    case EVT_KEY_FIRST(KEY_DOWN):
    case EVT_KEY_FIRST(KEY_EXIT):
      chainMenu(menuProc0); 
      break;
  }

  lcd_puts_P(  1*FW, FH*1, PSTR("TME"));
  putsTime(    4*FW, FH*1, s_timeCumAbs, 0, 0);
  lcd_puts_P( 17*FW, FH*1, PSTR("PWR"));
  putsTime(   10*FW, FH*1, s_timeCumTot,      0, 0);

  lcd_puts_P(  1*FW, FH*2, PSTR("THR"));
  putsTime(    4*FW, FH*2, s_timeCumThr, 0, 0);
  lcd_puts_P( 17*FW, FH*2, PSTR("THR%"));
  putsTime(   10*FW, FH*2, s_timeCum16ThrP/16, 0, 0);


  uint16_t traceRd = s_traceCnt>MAXTRACE ? s_traceWr : 0;
  uint8_t x=5;
  uint8_t y=60;
  lcd_hline(x-3,y,120+3+3);
  lcd_hlineStip(x-3,y-16,120+3+3,0x11);
  lcd_hlineStip(x-3,y-32,120+3+3,0x11);
  lcd_vline(x,y-32,32+3);

  for(uint8_t i=0; i<120; i+=6)
  {
    lcd_vline(x+i+6,y-1,3);
  }
  for(uint8_t i=1; i<=120; i++)
  {
    lcd_vline(x+i,y-s_traceBuf[traceRd],s_traceBuf[traceRd]);
    traceRd++;
    if(traceRd>=MAXTRACE) traceRd=0;
    if(traceRd==s_traceWr) break;
  }

}

extern volatile uint16_t captureRing[16];


#define MAX_VIEWS  4
#define VIEW_NUM   0
#define VIEW_GRAPH 1
#define VIEW_SWTCH 2
#define VIEW_TRIM  3
uint8_t g_istTrimState;
void menuProc0()
{
#ifdef SIM
  sprintf(g_title,"M0");  
#endif
  static uint8_t   sub;
  static uint8_t   subSw;
  static MenuFuncP s_lastPopMenu[2];
  static uint8_t   view;

  if(view==VIEW_SWTCH){
    switch(g_event){
      static bool s_autoBack;
    case EVT_KEY_BREAK(KEY_RIGHT):
      subSw+=2;
    case EVT_KEY_BREAK(KEY_LEFT):
      subSw = (subSw+8-1)%8;
      BLINK_SYNC;
      g_event=0;
      break;
    case  EVT_KEY_BREAK(KEY_MENU): //switch release
      if(!s_autoBack) break;
      //fallthrough
      g_event=0;
    case  EVT_KEY_FIRST(KEY_EXIT):
      g_virtSw[subSw]=0;
      BLINK_SYNC;
      break;
      case  EVT_KEY_FIRST(KEY_MENU): //switch press
      s_autoBack=false;
      g_virtSw[subSw]=1;
      BLINK_SYNC;
      g_event=0;
      break;
      case  EVT_KEY_LONG(KEY_MENU):    //swith press as button
      s_autoBack=true;
      g_event=0;
      break;
    }
  }
  switch(g_event)
  {
//     case  EVT_KEY_LONG(KEY_MENU):
//       switch(sub){
//         case 0: 
//           pushMenu(menuProcSetup0);
//           break;
//         case 1:
//           pushMenu(menuProcModelSelect);//menuProcModel);
//           break;
//       }
//       killEvents();
//       break;
    case EVT_KEY_FIRST(KEY_RIGHT):
      //if(getEventDbl(g_event)==2 && s_lastPopMenu[1]){
//       if(sub<1) { //!! used in ENTRY_UP
//         sub=sub+1;
//         beepKey();
//       }
//       if(getEventDbl(g_event)==2){
// 	sub=1;
//         pushMenu(menuProcModelSelect);//menuProcExpoAll); 
//         //pushMenu(s_lastPopMenu[1]);
//         killEvents();
//         return;
//         break;
//       }
      break;
    case EVT_KEY_LONG(KEY_RIGHT):
      sub=1;
      if(s_lastPopMenu[1]){
        pushMenu(s_lastPopMenu[1]);
      }else{
        pushMenu(menuProcModelSelect);//menuProcExpoAll); 
      }
      killEvents();
      return;
      break;
    case EVT_KEY_FIRST(KEY_LEFT):
      // if(sub>0) { //!! used in ENTRY_UP
//         sub=sub-1;
//         beepKey();
//       }
      //if(getEventDbl(g_event)==2 && s_lastPopMenu[0]){
      //  pushMenu(s_lastPopMenu[0]);
      //  break;
      //}
      break;
    case EVT_KEY_LONG(KEY_LEFT):
      sub=0;
      if(s_lastPopMenu[0]){
        pushMenu(s_lastPopMenu[0]);
      }else{
        pushMenu(menuProcSetup0);
      }
      killEvents();
      return;
      break;
      //states of instant trim
#define IST_OFF      0
#define IST_CHECKKEY 1
#define IST_WAITKEY  2
#define IST_PREPARE  3
#define IST_FIX      4
    case EVT_KEY_BREAK(KEY_UP):
      view += 2;
    case EVT_KEY_BREAK(KEY_DOWN):
      view = (view+MAX_VIEWS-1) % MAX_VIEWS;
      if(view==VIEW_TRIM) {
	g_istTrimState=IST_CHECKKEY;
      } else {
	g_eeGeneral.view = view; //instant trim is not persistent
      }
      eeDirty(EE_GENERAL);
      beepKey();
      break;

    case EVT_KEY_LONG(KEY_UP):
      chainMenu(menuProcStatistic); 
      killEvents();
      break;
    case EVT_KEY_LONG(KEY_DOWN):
      chainMenu(menuProcStatistic2); 
      killEvents();
      break;
    case EVT_KEY_FIRST(KEY_EXIT):
      if(s_timerState==TMR_BEEPING) {
        s_timerState = TMR_BEEPSTOPPED;
        beepKey();
      }
      break;
    case EVT_KEY_LONG(KEY_EXIT):
      s_timerState = TMR_OFF; //is changed to RUNNING dep from mode
      s_timeCumAbs=0;
      s_timeCumThr=0;
      s_timeCum16ThrP=0;
      beepKey();
      break;
    case EVT_ENTRY_UP:
      s_lastPopMenu[sub] = lastPopMenu();
    case EVT_ENTRY:
      killEventsRaw(KEY_EXIT);
      killEventsRaw(KEY_UP);
      killEventsRaw(KEY_DOWN);
    case EVT_EXIT:
      view=g_eeGeneral.view;
      g_istTrimState=IST_OFF;
      return;
  }


  uint8_t x=FW*2;
  lcd_putsAtt(x-3,1*FH,PSTR("th9x"),INVERS);//sub==0 ? INVERS : 0);
  lcd_putsnAtt(x+ 4*FW,   0*FH, g_model.name ,sizeof(g_model.name)-3,BSS_NO_INV|DBLSIZE);
  lcd_putsnAtt(x+ 15*FW+4,   0*FH, g_model.name+sizeof(g_model.name)-3,3,BSS_NO_INV);
  putsVBat(x-3+0*FW,2*FH, g_vbat100mV < g_eeGeneral.vBatWarn ? BLINK : 0);

  if(s_timerState != TMR_OFF){
    uint8_t att = DBLSIZE | (s_timerState==TMR_BEEPING ? BLINK : 0);
    putsTime( x+8*FW-0, FH*2, g_model.tmrVal==0 ? -s_timerVal:s_timerVal, att,att);
    lcd_putsmAtt(   x+4*FW, FH*2, PSTR("\tTME\tTHR\tTHR%"),g_model.tmrMode,0);
    putsTime(       x+3*FW, FH*3, s_timeCumAbs, 0,0);
  }
  if(g_trainerSlaveActiveChns){
    lcd_putsAtt(x-3+2*FW, 3*FH,PSTR("T"), 0);
    lcd_putcAtt(x-3+3*FW ,3*FH,g_trainerSlaveActiveChns+'0',0);
  }
  lcd_vline(x-3+4*FW,0,4*FH-1);
  //lcd_vline(x-2+4*FW,0,4*FH-1);

  //trim sliders
  for(uint8_t i=0; i<4; i++)
  {
#define TL 27
    //                        LH LV RV RH
    static uint8_t x[4]    = {128*1/4+2, 4, 128-4, 128*3/4-2};
    static uint8_t vert[4] = {0,1,1,0};
    uint8_t xm,ym;
    xm=x[i];
    int8_t itrim = getTrimRaw( convertMode(i));
    itrim = max((int8_t)-(TL+1),min((int8_t)(TL+1),itrim) );
    if(vert[i]){
      ym=31;
      lcd_vline(xm,   ym-TL, TL*2);
      lcd_vline(xm-1, ym-1,  3);
      lcd_vline(xm+1, ym-1,  3);
      //lcd_hline(xm-1, ym,     3);
      ym -= itrim;//val;
    }else{
      ym=60;
      lcd_hline(xm-TL,ym,    TL*2);
      lcd_hline(xm-1, ym-1,  3);
      lcd_hline(xm-1, ym+1,  3);
      //lcd_vline(xm,   ym-1,     3);
      xm += itrim;//val;
    }

    //value marker
#define MW 7
    lcd_vline(xm-MW/2,ym-MW/2,MW);
    lcd_hline(xm-MW/2,ym+MW/2,MW);
    lcd_vline(xm+MW/2,ym-MW/2,MW);
    lcd_hline(xm-MW/2,ym-MW/2,MW);
  }
  uint8_t x0,y0;
  switch(view)
    {
    case VIEW_NUM:
      for(uint8_t i=0; i<NUM_CHNOUT; i++) {
	x0 = (i%4*9+3)*FW/2;
	y0 = i/4*FH+40;
	// *1000/512 =   *2 - 24/512
	lcd_outdezAtt( x0+4*FW , y0, g_chans512[i]*2-g_chans512[i]/21,PREC1 );
      }
      break;
    case VIEW_GRAPH:
#define WBAR2 (50/2)
      for(uint8_t i=0; i<NUM_CHNOUT; i++) {
	x0       = i<4 ? 128/4+4 : 128*3/4-4;
	y0       = 38+(i%4)*5;
	int8_t l = (abs(g_chans512[i])+WBAR2/2) * WBAR2 / 512;
	lcd_hlineStip(x0-WBAR2,y0,WBAR2*2+1,0x55);
	lcd_vline(x0,y0-2,5);
	if(g_chans512[i]>0){
	  x0+=1;
	}else{
	  x0-=l;
	}
	lcd_hline(x0,y0+1,l);
	lcd_hline(x0,y0-1,l);
      }
      break;
    case VIEW_SWTCH:
      showSwitches(subSw);
      break;
    case VIEW_TRIM:
      lcd_putsAtt(2*FW,5*FH,PSTR("Instant Trim"), 0);
      switch(g_istTrimState){
      case IST_WAITKEY:
	lcd_putsAtt(2*FW,6*FH,PSTR("press "), BLINK);
	putsDrSwitches(8*FW,6*FH,TrimSwitch,BLINK);

	break;
      case IST_PREPARE:
	lcd_putsAtt(2*FW,6*FH,PSTR("adjust flight"), BLINK);
	break;
      case IST_FIX:
	lcd_putsAtt(2*FW,6*FH,PSTR("release Sticks"), BLINK);
	break;
      }
      break;

    }

}

static int16_t s_cacheLimitsMin[NUM_CHNOUT];
static int16_t s_cacheLimitsMax[NUM_CHNOUT];

void calcLimitCache()
{
  if(s_limitCacheOk) return;
  printf("calc limit cache\n");
  s_limitCacheOk = true;
  for(uint8_t i=0; i<NUM_CHNOUT; i++){
    int16_t v;
    v = lim2val(g_model.limitData[i].min,-40);
    s_cacheLimitsMin[i] = 5*v + v/8 ; // *512/100 ~  *(5 1/8)
    v = lim2val(g_model.limitData[i].max,+40);
    s_cacheLimitsMax[i] = 5*v + v/8 ; // *512/100 ~  *(5 1/8)
  }
}




int16_t intpol(int16_t x, uint8_t idx) // -100, -75, -50, -25, 0 ,25 ,50, 75, 100
{
#define D9 (RESX * 2 / 8)
#define D5 (RESX * 2 / 4)
#define D3 (RESX * 2 / 2)
  uint8_t cvTyp=curveTyp(idx);
  int8_t *crv = curveTab(idx);
  /*  bool    cv9 = idx >= 2;
  int8_t *crv = cv9 ? g_model.curves9[idx-2] : g_model.curves5[idx];*/
  int16_t erg;

  x+=RESXu;
  if(x < 0) {
    erg = crv[0]             * (RESX/2);
  } else if(x >= (RESX*2)) {
    erg = crv[cvTyp-1] * (RESX/2);
  } else {
    int16_t a,dx;
    switch(cvTyp){
      case 9:	a   = (uint16_t)x / D9;	dx  =((uint16_t)x % D9) * 2; break;
      case 5:	a   = (uint16_t)x / D5;	dx  =((uint16_t)x % D5)    ; break;
      default: /*case 3*/	a   = (uint16_t)x / D3;	dx  =((uint16_t)x % D3) / 2; break;
/*    } else {
      a   = (uint16_t)x / D5;
      dx  = (uint16_t)x % D5;*/
    }
    erg  = (int16_t)crv[a]*(D5-dx) + (int16_t)crv[a+1]*(dx);
  }
  return erg / 50; // 100*D5/RESX;
}


/*
  dt=[ 1, 1,1,1,1,1,1,2,1,3,2,3,4,6,9];dx=[18,13,9,6,4,3,2,3,1,2,1,1,1,1,1]
  rp=1; 15.times{|i| r=dx[i]*100.0/(dt[i]); printf("%2d: rate=%4d i/s full=%5.1fs %3.1f\n",i+1,r,1024.0/r,rp/r);rp=r}
 1: rate=1800 i/s full=  0.6s 0.0
 2: rate=1300 i/s full=  0.8s 1.4
 3: rate= 900 i/s full=  1.1s 1.4
 4: rate= 600 i/s full=  1.7s 1.5
 5: rate= 400 i/s full=  2.6s 1.5
 6: rate= 300 i/s full=  3.4s 1.3
 7: rate= 200 i/s full=  5.1s 1.5
 8: rate= 150 i/s full=  6.8s 1.3
 9: rate= 100 i/s full= 10.2s 1.5
10: rate=  66 i/s full= 15.4s 1.5
11: rate=  50 i/s full= 20.5s 1.3
12: rate=  33 i/s full= 30.7s 1.5
13: rate=  25 i/s full= 41.0s 1.3
14: rate=  16 i/s full= 61.4s 1.5
15: rate=  11 i/s full= 92.2s 1.5
*/
//                                     1  2 3 4 5 6 7 8 9 0 1 2 3 4 5
//                                                        1 1 1 1 1 1 
static prog_uint8_t APM s_slopeDlt[]={18,13,9,6,4,3,2,3,1,2,1,1,1,1,1}; 
static prog_uint8_t APM s_slopeTmr[]={ 1, 1,1,1,1,1,1,2,1,3,2,3,4,6,9};

uint16_t slopeFull100ms(uint8_t speed) //zeit fuer anstieg von -512 bis 512 in 100ms
{
  if(speed==0) return 0;
  int8_t  delta    = pgm_read_byte(&s_slopeDlt[speed-1]);
  uint8_t timerend = pgm_read_byte(&s_slopeTmr[speed-1]); // *10ms
  // 1024* timerend*10ms / delta
  return (102 * timerend + delta / 2 ) / delta;     
}

static int16_t anas [SRC_MAX];
static int32_t chanSum32[NUM_XCHNOUT];          // Ausgaenge + intermidiates
int16_t getSrcVal(uint8_t srcRaw, uint8_t destCh)
{
  //RUD..AIL P1..p3 MAX CUR CH1..CH8 X1..X4 T1..T8
  //|   anas           |     chanSum32         | g_ppmIns
  if(srcRaw<SRC_MAX){
    return anas[srcRaw];
  }else{
    if(srcRaw==SRC_MAX)
      return 512;
    else if(srcRaw>=SRC_T1){
      uint8_t i=srcRaw-SRC_T1;
      if(i<g_trainerSlaveActiveChns)
        return (g_ppmIns[i]- g_eeGeneral.trainer.calib[i]);
      else
        return 0;
    }else {
      uint8_t i = (srcRaw==SRC_MAX) ? destCh : srcRaw-SRC_CH1;
      int32_t   v = chanSum32[i];
      return (v + (v>0 ? 100/2 : -100/2)) / 100;
    }
  }
}


void perOut(int16_t *chanOut)
{
  static int16_t anas2      [4];
  static bool    trimAssym  [4]; //assymetric trim, at neg end

  memset(trimAssym,0,sizeof(trimAssym));
  g_sumAna=0;
  //Normierung  [0..1024] ->   [-512..512]
  //  anaIn(hw7) ->    anas[hw7]   anaCalib[hw4]
  for(uint8_t iHw=0;iHw<7;iHw++){        // calc Sticks
    int16_t v= anaIn(iHw);
    g_sumAna += (uint8_t)v;

#ifndef COMPANION9X
    v -= g_eeGeneral.calibMid[iHw];
    v  =  v * (int32_t)RESX /  (max((int16_t)100,
                                    (v>0 ? 
                                     g_eeGeneral.calibSpanPos[iHw] : 
                                     g_eeGeneral.calibSpanNeg[iHw])));
#endif

    if(v <= -RESX) v = -RESX;
    if(v >=  RESX) v =  RESX;
    uint8_t iLog = convertMode(iHw);
    anas[iLog] = v; //10+1 Bit  
    if(iHw<4)anaCalib[iLog] =  v; //for show in expo 
    else     anas[iLog+3]   = (v+512)/2; //p1-3
  }

  memcpy(anas2,anas,sizeof(anas2));//values before expo, to ensure same expo base when multiple expo lines are used

  memset(g_altTrim,0,sizeof(g_altTrim));//
  //Expotab   anas[log4] -> anas[log4]
  for(uint8_t i=0;i<DIM(g_model.expoTab);i++){
    ExpoData_r171 &ed = g_model.expoTab[i];
    if(ed.mode3==0) break; //end of list
    if(ed.mode3==EM_ALT_TRIM) { //alternative trim
      if(getSwitch(ed.drSw,0)) {
        g_altTrim[ed.chn] = &ed;
      }
      continue;
    }
    if(ed.mode3==EM_TRIM_INV) trimAssym[ed.chn]=true;
    if(getSwitch(ed.drSw,1)) {
      int16_t v = anas[ed.chn];
      if(ed.mode3>=EM_BOTH || (ed.mode3==EM_POS && v<0) || (ed.mode3==EM_NEG && v>0)){
        //      if((v<0 && ed.mode3&1) || (v>0 && ed.mode3&2)){
        int16_t k=idx2val15_100(ed.exp5);
        v = expo2(anas2[ed.chn],v,k);
        if(ed.curve) v = intpol(v, ed.curve - 1);
        v = v * (int32_t)(idx2val30_100(ed.weight6)) / 100;
	anas[ed.chn] = v;
      }
    }
  }

  //Trainer,   anas[log4] -> anas[log4]
  //Trace THR
  //Trim
  for(uint8_t iLog=0;iLog<4;iLog++){        // calc Sticks
    int16_t v = anas[iLog];

    TrainerData1_r0*  td = &g_eeGeneral.trainer.chanMix[iLog];
    if(g_trainerSlaveActiveChns && td->mode && getSwitch(td->swtch,1) &&
       td->srcChn<g_trainerSlaveActiveChns){
      uint8_t chStud = td->srcChn;
      int16_t vStud  = (g_ppmIns[chStud]- g_eeGeneral.trainer.calib[chStud])*
	td->studWeight/31;

      switch(td->mode)
      {
	case 1: v += vStud;   break; // add-mode
	case 2: v  = vStud;   break; // subst-mode
      }
    }

    //trace throttle
    if(iLog == SRC_THR)  trace((v+512)/32); //trace thr 0..31

    //trim
    
    anas2[iLog]= v;//values before trim
    if(trimAssym[iLog]){                       
      v += trimVal(iLog)*(int32_t)(512-v)/1024; //260*1024
    }else{
      v += trimVal(iLog);
    }
    anas[iLog] = v;
  }
  // In anas stehen jetzt die Werte mit Trimmung -512..511

  //Instant trim anas[log4] -> anas[log4]
  if(g_istTrimState!=IST_OFF){
    static bool     s_istInitKey;
    static uint16_t s_istTmr;
    static uint16_t s_istAnas[4];
    switch(g_istTrimState){
      case IST_CHECKKEY:
        s_istInitKey = getSwitch(TrimSwitch,0);
        g_istTrimState = IST_WAITKEY;
        break;
      case IST_WAITKEY:
        if(s_istInitKey != getSwitch(TrimSwitch,0)){
          g_istTrimState = IST_PREPARE;
          s_istTmr=pgm_read_byte(&s_istTmrVals1[g_eeGeneral.iTrimTme1])*10;
        }
        break;
      case IST_PREPARE:
        if(s_istTmr%50==0)beepTmr();
        if(s_istTmr-- == 0){
          memcpy(s_istAnas,anas,sizeof(s_istAnas));
          g_istTrimState = IST_FIX;
          s_istTmr=pgm_read_byte(&s_istTmrVals2[g_eeGeneral.iTrimTme2])*10;
        }
        break;
      case IST_FIX:
        if(s_istTmr%5==0)beepTmr();
        if(s_istTmr-- == 0){
          g_istTrimState = IST_CHECKKEY;
          s_istTmr=0;
          for(uint8_t i=0; i<4;i++){
            if(!trimAssym[i]){
              setTrimRaw(i,trimRevertM(s_istAnas[i]-anas2[i],getTrimRawMode(i)));
            }
          }
        }else{
          memcpy(anas,s_istAnas,sizeof(s_istAnas));
        }
        break;
    }
  }

  // virtual switches

  int8_t lastSw = -1;
  int8_t lastOp =  0;
  bool   currRes=  0;
  static bool lastTab[MAX_SWITCHES];
  for(uint8_t i=0;i<MAX_SWITCHES;i++){
    SwitchData_r204  &sd = g_model.switchTab[i];
    if(sd.opRes==0) break;
    int16_t val1 = getSrcValSw(sd.val1,sd.opCmp);
    int16_t val2 = getSrcValSw(sd.val2,sd.opCmp);
    bool    res  = false;
    switch(sd.opCmp){ //"<\t&\t|\t^"
      case 0: res = val1 <= val2; break;
      case 1: res = val1 && val2; break;
      case 2: res = val1 || val2; break;
      case 3: res = val1 ^  val2; break;
    }
    uint8_t sw=sd.sw;
    if(lastSw!=sw){
      lastSw = sw;
      lastOp = 0;
    }
    switch(lastOp){
      case 5:  currRes &= res; break;
      case 6:  currRes |= res; break;
      case 7:  currRes ^= res; break;
      default: currRes  = res; break;
    }
    //printf("i=%d,res=%d val1=%d, val2=%d\n",i,res,val1,val2);
    //res = resTmp[sw] = resTmp[sw] && res; //and to result before (case4)
 
    if(currRes != lastTab[i])
      switch(sd.opRes){ //"\t=>\ton\toff\t&"
        case 1: g_virtSw[sw]             = currRes;   break;
        case 2: if(currRes) g_virtSw[sw] = true;      break;
        case 3: if(currRes) g_virtSw[sw] = false;     break;
        case 4: if(currRes) g_virtSw[sw]^= 1;         break;    
          //case 4: lastOp = 4;                   break;
      }
    lastTab[i]=currRes;
    lastOp = sd.opRes;

  } // virtual switches

  //Mixer loop anas[log7] -> chanSum32[]
  int8_t currSeen = -1;
  for(uint8_t i=0;i<=MAX_MIXERS;i++){
    MixData_r192 &md = g_model.mixData[i]; //!! i geht bis 1 hinter listenende
    uint8_t destCh   = i<MAX_MIXERS ? md.destCh-1 : 0xff; //am ende 0xff (destCh==0)

    int8_t destCh2   = destCh;
    if(destCh==0xff) destCh2=NUM_XCHNOUT-1;//am listende restl. chans loeschen
    while(currSeen < destCh2 ){
      chanSum32[++currSeen] = 0;//loeschen wenn erstmals in liste auftaucht
    }
    if(destCh==0xff) break;

    int16_t v=0;
    if(getSwitch(md.swtch,1)){
      v = getSrcVal(md.srcRaw, destCh);
    }else
      switch(md.switchMode){
	case 0: currMixerVal=0; goto mixend;  // Zeile abgeschaltet
	case 1: v=-512; break;
      //case 2: v=   0; break; default
	case 3: v= 512; break;
      }

    if (md.speedUp || md.speedDown)
    {
      static uint8_t timer[MAX_MIXERS];
      static int16_t act  [MAX_MIXERS];
      int16_t     diff     = v - act[i];
      if(diff){
        uint8_t   speed    = (diff > 0) ? md.speedUp : md.speedDown;
        if(speed){
          uint8_t timerend = pgm_read_byte(&s_slopeTmr[speed-1]);
          int8_t  dlt      = pgm_read_byte(&s_slopeDlt[speed-1]);
          dlt              = min((int16_t)dlt, abs(diff)) ;
          if(diff < 0) dlt = -dlt;

          if (--timer[i] != 0)
          {
            if (timer[i] > timerend) timer[i] = timerend;
          }
          else
          {
            act[i]        += dlt;
            timer[i]       = timerend;
          }
        }else{ //!speed
          act[i]   = v;
          timer[i] = 0;
        }
      }
      v = act[i];
    }// if speedUp||speedDown
    if(md.curve) v = intpol(md.curveNeg ? -v : v, md.curve - 1);
    
    if(destCh<8 && g_model.limitData[destCh].binSwtch){
      //Binary Switch
      chanSum32[destCh] += (0x01u << md.weight); //swmode==0, no src, speed, curve
    }else{
      int32_t dv=(int32_t)v*md.weight; // 10+1 Bit + 7 = 17+1
      if(currMixerLine==i){
        currMixerVal=dv; //for mixer debug
        //mov32div8to16(currMixerVal,dv);
      }
      switch(md.mixMode){
        case 0: //+
          dv+=chanSum32[destCh]; //Mixerzeile zum Ausgang addieren
          break;
        case 1: //*
          dv/=50;
          dv*=chanSum32[destCh]; //
          dv/=51200/50;
          break;
        case 2: //=
          break;
      }
      chanSum32[destCh]  = dv; //
    }
    mixend:
    if(currMixerLine==i){
      currMixerSum=chanSum32[destCh];
      //mov32div8to16(currMixerSum,chanSum32[destCh-1]);
    }
      
  }

  //limit + revert loop
  calcLimitCache();
  for(uint8_t i=0;i<NUM_CHNOUT;i++){
    int32_t v32 = chanSum32[i];
    int16_t v   = 0;
    if(g_model.limitData[i].binSwtch){
      if(g_pulseLoopCnt&1){
	v=(v32<<2)-512; //range -256 - +256
      }else{
	v=(g_pulseLoopCnt&2) ? +600 : -600; // max vals for calib 
      }
    }else{
      if(g_model.limitData[i].scale){
	if(v32>0)      v =  v32 * s_cacheLimitsMax[i] / 51200;
	else if(v32<0) v = -v32 * s_cacheLimitsMin[i] / 51200;
      }else{
	if(v32) v = (v32 + (v32 > 0 ? 100/2 : -100/2)) / 100;
      }
      v = max(s_cacheLimitsMin[i],v);
      v = min(s_cacheLimitsMax[i],v);

      if(g_model.limitData[i].revert) v=-v;
      //offset after limit -> 
      v+=g_model.limitData[i].offset*5; // 512/100  //issue 40
    }

#ifndef SIM
    asm(""::"r"(v)); //enforce calc of v before cli
#endif
    cli();
    chanOut[i]=v; //copy consistent word to int-level
    sei();
  }    

#ifdef SIM
  setupPulses();
#endif

}




