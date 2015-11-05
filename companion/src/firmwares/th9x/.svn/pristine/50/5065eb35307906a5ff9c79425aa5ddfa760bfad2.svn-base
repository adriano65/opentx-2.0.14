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

 This file contains any upper level code for data persistency.
 The Layer below is file.cpp and then drivers.cpp

 */

#include "th9x.h"


EFile theFile;  //used for any file operation
EFile theFile2; //sometimes we need two files 

#define FILE_TYP_GENERAL 1
#define FILE_TYP_MODEL   2
#define partCopy(sizeDst,sizeSrc)                         \
      pSrc -= (sizeSrc);                                  \
      pDst -= (sizeDst);                                  \
      memmove(pDst, pSrc, (sizeSrc));                     \
      memset (pDst+(sizeSrc), 0,  (sizeDst)-(sizeSrc));
#define fullCopy(size) partCopy(size,size)
void generalDefault()
{
  memset(&g_eeGeneral,0,sizeof(g_eeGeneral));
  g_eeGeneral.myVers   =  GENVERS_TOP;
  g_eeGeneral.currModel=  0;
  g_eeGeneral.contrast = 30;
  g_eeGeneral.vBatWarn = 90;
  g_eeGeneral.stickMode=  1;
  //int16_t sum=0;
  for (int i = 0; i < 7; ++i) {
    g_eeGeneral.calibMid[i]     = 0x200;
    g_eeGeneral.calibSpanNeg[i] = 0x180;
    g_eeGeneral.calibSpanPos[i] = 0x180;
  }
  //g_eeGeneral.chkSum = sum;
}
bool eeLoadGeneral()
{
  theFile.openRd(FILE_GENERAL);
  uint8_t sz = 0;
  if(theFile.readRlc2((uint8_t*)&g_eeGeneral, 1)==1){
    theFile.openRd(FILE_GENERAL);
    if(g_eeGeneral.myVers < GENVERS192){
      sz = theFile.readRlc1((uint8_t*)&g_eeGeneral, sizeof(g_eeGeneral));
    }else{
      sz = theFile.readRlc2((uint8_t*)&g_eeGeneral, sizeof(g_eeGeneral));
    }
  }

  //uint16_t sum=0;
  if( sz == sizeof(EEGeneral_r0) && g_eeGeneral.myVers == GENVERS0 ){
    printf("converting EEGeneral data from < 119\n");
    char* pSrc = ((char*)&g_eeGeneral) + sizeof(EEGeneral_r0);//Pointers behind the end
    char* pDst = ((char*)&g_eeGeneral) + sizeof(EEGeneral_r119);
    fullCopy(sizeof(EEGeneral_r0)-offsetof(EEGeneral_r0,calibSpan));
    //for(uint8_t i=0; i<12;i++) sum+=g_eeGeneral.calibMid[i];
    //g_eeGeneral.chkSum = sum;
    sz = sizeof(EEGeneral_r119);
    EEGeneral_r119*p119= (EEGeneral_r119*)&g_eeGeneral;
    p119->myVers  = GENVERS119;
  }
  if( sz == sizeof(EEGeneral_r119) && g_eeGeneral.myVers == GENVERS119){
    printf("converting EEGeneral data from 119 to 119_3\n");
    EEGeneral_r119*p119= (EEGeneral_r119*)&g_eeGeneral;
    p119->adcFilt = 2;
    p119->thr0pos = 1; //upper 6 bits of adc value
    p119->myVers  = GENVERS119_3;
  }
  if( sz == sizeof(EEGeneral_r119) && g_eeGeneral.myVers == GENVERS119_3){
    printf("converting EEGeneral data from 119_3 to 150\n");
    char* pSrc = ((char*)&g_eeGeneral) + sizeof(EEGeneral_r119);//Pters behind the end
    char* pDst = ((char*)&g_eeGeneral) + sizeof(EEGeneral_r150);
    fullCopy(sizeof(EEGeneral_r119)-offsetof(EEGeneral_r119,chkSum));
    partCopy(7*2,4*2); //calibSpanPos
    partCopy(7*2,4*2); //calibSpanNeg
    partCopy(7*2,4*2); //calibMid
    EEGeneral_r150*p150= (EEGeneral_r150*)&g_eeGeneral;
    p150->inactivityMin = 0;
    p150->resv = 0;
    for(uint8_t i=4; i<7;i++){
      p150->calibMid[i]     = 0x200;
      p150->calibSpanNeg[i] = 0x180;
      p150->calibSpanPos[i] = 0x180;
    }
    
    sz = sizeof(EEGeneral_r150);
    p150->myVers  = GENVERS150;
  }

  if( sz == sizeof(EEGeneral_r150) && g_eeGeneral.myVers == GENVERS150){
    EEGeneral_r150 *p150= (EEGeneral_r150*)&g_eeGeneral;
    if(p150->stickMode & 1)
      memswap(&p150->trainer.chanMix[1],
              &p150->trainer.chanMix[2],sizeof(p150->trainer.chanMix[1]));
    if(p150->stickMode & 2)
      memswap(&p150->trainer.chanMix[0],
              &p150->trainer.chanMix[3],sizeof(p150->trainer.chanMix[0]));
    p150->myVers  = GENVERS150_5;
  }
  if( sz == sizeof(EEGeneral_r150) && g_eeGeneral.myVers == GENVERS150_5){
    EEGeneral_r150 &p150= *(EEGeneral_r150*)&g_eeGeneral;
    EEGeneral_r192 &p192= *(EEGeneral_r192*)&g_eeGeneral;

    memmove(&p192.trainer.calib[4], 
            &p150.trainer, 
	    sizeof(EEGeneral_r150)-offsetof(EEGeneral_r150,trainer));
    sz+=8;
    p192.myVers  = GENVERS192;
  }
  if( sz == sizeof(EEGeneral_TOP) && g_eeGeneral.myVers == GENVERS_TOP){
    return true;
  }
  printf("bad g_eeGeneral sz=%d vers=%d\n",sz,g_eeGeneral.myVers);
  return false;
}


uint8_t modelMixerDefaults=7;
prog_char* modelMixerDefaultName(uint8_t typ)
{
  switch(typ)
  {
    case 0: return PSTR("select!");
    case 1: return PSTR("Simple 4-Ch");
    case 2: return PSTR("V-Tail");
    case 3: return PSTR("Elevon/Delta");
    case 4: return PSTR("eCCPM");
    case 5: return PSTR("Sim Calib");
    case 6: return PSTR("Servotest");
  }
  return 0;
}
void modelMixerDefault(uint8_t typ)
{
  memset(&g_model.mixData[0],0,sizeof(g_model.mixData));
  MixData_r192*md=&g_model.mixData[0];
  switch (typ){
    //Simple 4-Ch
    case 0:
      break;
    case 1:
      // rud ele thr ail
      for(uint8_t i= 0; i<4; i++){ //
        md->destCh = i+1;       md->srcRaw = i;        md->weight = 100;
        md++;
      }
      break;
    
      //V-Tail
    case 2:
      md->destCh = SRC_RUD+1; md->srcRaw = SRC_RUD;  md->weight = 100; md++;
      md->destCh = SRC_RUD+1; md->srcRaw = SRC_ELE;  md->weight =-100; md++;
      md->destCh = SRC_ELE+1; md->srcRaw = SRC_RUD;  md->weight = 100; md++;
      md->destCh = SRC_ELE+1; md->srcRaw = SRC_ELE;  md->weight = 100; md++;
      md->destCh = SRC_THR+1; md->srcRaw = SRC_THR;  md->weight = 100;
      break;

      //Elevon\\Delta
    case 3:
      md->destCh = SRC_ELE+1; md->srcRaw = SRC_ELE;  md->weight = 100; md++;
      md->destCh = SRC_ELE+1; md->srcRaw = SRC_AIL;  md->weight = 100; md++;
      md->destCh = SRC_THR+1; md->srcRaw = SRC_THR;  md->weight = 100; md++;
      md->destCh = SRC_AIL+1; md->srcRaw = SRC_ELE;  md->weight = 100; md++;
      md->destCh = SRC_AIL+1; md->srcRaw = SRC_AIL;  md->weight =-100;
      break;

      //eCCPM
    case 4:
      md->destCh = SRC_ELE+1; md->srcRaw = SRC_ELE;  md->weight = 72; md++;
      md->destCh = SRC_ELE+1; md->srcRaw = SRC_THR;  md->weight = 55; md++;
      md->destCh = SRC_AIL+1; md->srcRaw = SRC_ELE;  md->weight = 36; md++;
      md->destCh = SRC_AIL+1; md->srcRaw = SRC_AIL;  md->weight = 62; md++;
      md->destCh = SRC_AIL+1; md->srcRaw = SRC_THR;  md->weight = 55; md++;
      md->destCh = 6;         md->srcRaw = SRC_ELE;  md->weight = 36; md++;
      md->destCh = 6;         md->srcRaw = SRC_AIL;  md->weight = 62; md++;
      md->destCh = 6;         md->srcRaw = SRC_THR;  md->weight = 55; md++;
      break;
      // Sim Calib
    case 5:
      for(uint8_t i= 0; i<8; i++){
        md->destCh = i+1;     md->srcRaw = 10;/*MAX*/       md->weight = 100; 
        md->swtch  = 1+SW_ID0-SW_BASE;
        md++;
        md->destCh = i+1;     md->srcRaw = 10;/*MAX*/       md->weight =-100; 
        md->swtch  = 1+SW_ID2-SW_BASE;
        md++;
      }
      break;
      // Servotest
    case 6:
        md->destCh = 1;     md->srcRaw = 10;/*MAX*/       md->weight = 100; 
        md->swtch  = 1+9;   //SW1
        md->switchMode = 1; // iNeg
        md->speedUp    = md->speedDown = 5;
        md++;
        md->destCh = 2;     md->srcRaw = 12;/*CH1*/      md->weight = 100; 
        g_model.switchTab[0].sw    = 0;
        g_model.switchTab[0].opCmp = 0; // <
        g_model.switchTab[0].opRes = 3; //Set Off
        //g_model.switchTab[0].val1  = 40;
        g_model.switchTab[0].val1  = 51+ 7; //p1
        g_model.switchTab[0].val2  = 51+12; //CH1
        g_model.switchTab[1].sw    = 0;
        g_model.switchTab[1].opCmp = 0; // <
        g_model.switchTab[1].opRes = 2; //Set On
        g_model.switchTab[1].val1  = 51+12; //CH1
        g_model.switchTab[1].val2  =-(51+ 7); //p1
        //g_model.switchTab[1].val2  =-40;
      break;
  
  }
}
void modelDefault(uint8_t id)
{
  memset(&g_model,0,sizeof(g_model));
  strncpy_P(g_model.name,PSTR("MODEL     "), 10);
  g_model.name[5]='0'+(id+1)/10;
  g_model.name[6]='0'+(id+1)%10;
  g_model.mdVers = 0; //MDVERS143;
  modelMixerDefault(id==0 ? 1 : 0);
}
void eeLoadModelName(uint8_t id,char*buf,uint8_t len)
{
  if(id<MAX_MODELS)
  {
    //eeprom_read_block(buf,(void*)modelEeOfs(id),sizeof(g_model.name));
    theFile.openRd(FILE_MODEL(id));
    memset(buf,' ',len);
    if(theFile.readRlc2((uint8_t*)buf,sizeof(g_model.name)+1) == (sizeof(g_model.name)+1) )
    {
      uint8_t  vers = buf[sizeof(g_model.name)];
      uint16_t sz   = theFile.size();
      buf[sizeof(g_model.name)]=' ';
      buf+=len;
      *--buf='0'+vers%10; vers/=10;
      *--buf='0'+vers%10;
      *--buf='V';
        --buf;
      while(sz){   --buf; *buf='0'+sz%10;   sz/=10;}
    }
  }
}

void eeLoadModel(uint8_t id)
{
  if(id>=MAX_MODELS) return; //paranoia

  theFile.openRd(FILE_MODEL(id));
  uint16_t sz = 0;
  if(theFile.readRlc2((uint8_t*)&g_model,sizeof(g_model.name)+1) == (sizeof(g_model.name)+1)){
    theFile.openRd(FILE_MODEL(id));
    if(g_model.mdVers < MDVERS192){
      sz = theFile.readRlc1((uint8_t*)&g_model, sizeof(g_model)); 
    }else{
      sz = theFile.readRlc2((uint8_t*)&g_model, sizeof(g_model)); 
    }
  }

// #if 0
//   if( sz == sizeof(ModelData_r0) ){
//     printf("converting model data t0 r84\n");
//     char* pSrc = ((char*)&g_model) + sizeof(ModelData_r0); //Pointers behind the end
//     char* pDst = ((char*)&g_model) + sizeof(ModelData_r84);
//     ModelData_r84 *model84 = (ModelData_r84*)&g_model;
// #define sizeof84(memb) sizeof(((ModelData_r84*)0)->memb)
//     fullCopy(sizeof84(trimData)+sizeof84(curves9)+sizeof84(curves5));
// 
//     partCopy(sizeof84(mixData), sizeof(MixData_r0)*20);
// 
//     for(uint8_t i=0; i<DIM(model84->expoData); i++){
//       partCopy(sizeof(ExpoData_r84), sizeof(ExpoData_r0));
//     }
//     sz = sizeof(ModelData_r84);
//     model84->mdVers = MDVERS84;
//   }
// #endif  
  if( sz == sizeof(ModelData_r84) && g_model.mdVers == MDVERS84) {
    printf("converting model data from r84 to r143\n");
    ModelData_r84  *model84  = (ModelData_r84*)&g_model;
    ModelData_r143 *model143 = (ModelData_r143*)&g_model;
    for(int8_t i=3; i>=0; i--){
      int16_t val = trimExp2(model84->trimData[i].trim) + model84->trimData[i].trimDef_lt133;
      model143->trimData[i].itrim = trimRevert2(val);
      model143->trimData[i].tmode = 0;
    }
    memmove(&model143->curves5, &model84->curves5, sizeof(model84->curves5)+sizeof(model84->curves9));
    memset(model143->curves3, 0, sizeof(model143->curves3));
    model143->curves3[0][2] =  100;
    model143->curves3[2][0] =  100;
    model143->curves3[2][2] =  100;
    model143->curves3[1][0] = -100;
    sz = sizeof(ModelData_r143);
    model84->mdVers = MDVERS143;
  }
  if( sz == sizeof(ModelData_r143) && g_model.mdVers == MDVERS143) {
    printf("converting model data from r143 to r167\n");
    ModelData_r143 *model143 = (ModelData_r143*)&g_model;
    ModelData_r167 *model167 = (ModelData_r167*)&g_model;
    for(int8_t i=0; i<NUM_CHNOUT; i++){
      int8_t v = model143->limitData[i].min-100;
      model167->limitData[i].min   = add7Bit(val2idx50_150(v),40);
      model167->limitData[i].scale = 0;
      v = model143->limitData[i].max+100;
      model167->limitData[i].max   = add7Bit(val2idx50_150(v),-40);
      model167->limitData[i].binSwtch = 0;
    }
    model143->mdVers = MDVERS167;
  }
  if( sz == sizeof(ModelData_r167) && g_model.mdVers == MDVERS167) {
    printf("converting model data from r167 to r171\n");
    ModelData_r167 *model167 = (ModelData_r167*)&g_model;
    ModelData_r171 *model171 = (ModelData_r171*)&g_model;
    ExpoData_r84   *hlpExp   = (ExpoData_r84*) 
      ((char*)&model171->expoTab
       +sizeof(model171->expoTab)
       -sizeof(model167->expoData));
    // old:20B new:45B
    // move old to end
    // clr unused start 25B
    // interpret old to new <= 3*8=24B
    // clr old at end 20B
    //
    memmove(hlpExp, 
	    &model167->expoData,
	    sizeof(ModelData_r167)-offsetof(ModelData_r167,expoData));
    memset(model171->expoTab, 0, 
	   sizeof(model171->expoTab)
	   -sizeof(model167->expoData));
    
    for(int8_t i=0,j=0; i<4; i++){
      if(hlpExp[i].expNorm || hlpExp[i].expNormWeight){
        model171->expoTab[j].drSw    = hlpExp[i].drSw ? -hlpExp[i].drSw : 0;
        model171->expoTab[j].chn     = convertMode(i);
        model171->expoTab[j].mode3   = EM_BOTH;
        model171->expoTab[j].exp5    = val2idx15_100(hlpExp[i].expNorm);
        model171->expoTab[j].weight6 =val2idx30_100(hlpExp[i].expNormWeight+100);
        j++;
      }

      if(hlpExp[i].drSw && (hlpExp[i].expDr || hlpExp[i].expSwWeight)){
	model171->expoTab[j].drSw    = hlpExp[i].drSw;
	model171->expoTab[j].chn     = convertMode(i);
	model171->expoTab[j].mode3   = EM_BOTH;
	model171->expoTab[j].exp5    = val2idx15_100(hlpExp[i].expDr);
	model171->expoTab[j].weight6 =val2idx30_100(hlpExp[i].expSwWeight+100);
        j++;
      }
    }
    memset(hlpExp, 0, sizeof(model167->expoData));
    sz = sizeof(ModelData_r171);

    for(uint8_t i=0;i<MAX_MIXERS;i++){
      MixData_r0 &md = model171->mixData[i];
      if(md.destCh==0) break;
      md.srcRaw = convertMode(md.srcRaw-1)+1;
    }
    if(g_eeGeneral.stickMode & 1)
      memswap(&model171->trimData[1],
              &model171->trimData[2],sizeof(model171->trimData[1]));
    if(g_eeGeneral.stickMode & 2)
      memswap(&model171->trimData[0],
              &model171->trimData[3],sizeof(model171->trimData[0]));

    model167->mdVers = MDVERS171;
  }
  if( sz == sizeof(ModelData_r171) && g_model.mdVers == MDVERS171) {
    printf("converting model data from r171 to r192\n");
    ModelData_r171 *model171 = (ModelData_r171*)&g_model;
    ModelData_r192 *model192 = (ModelData_r192*)&g_model;
    memmove(&model192->curves3, 
	    &model171->curves3,
	    sizeof(ModelData_r171)-offsetof(ModelData_r171,curves3));
    for(uint8_t i=MAX_MIXERS;i>0;){i--;
      MixData_r0   &md0   = model171->mixData[i];
      MixData_r192 &md192 = model192->mixData[i];
      uint8_t dc=md0.destCh;
      if(dc==0){
	memset(&md192,0,5);
	continue;
      }
      memmove(&md192.weight,&md0.weight,3);
      //                       0  1   2   3   4  5  6  7   8   9
      uint8_t sr=md0.srcRaw; //0 RUD ELE THR AIL P1 P2 P3 MAX FUL X1-4
      memset(&md192,0,2);
      md192.destCh =dc;
      if(sr>4){
	if(sr<=9) md192.switchMode=1; //P1-3, FUL I=-1
	if(sr==8) md192.switchMode=2; //MAX I=0
	if(sr==9) sr=8; //FUL->MAX
        if(sr>9)  sr+=8;//space for ch1-ch8
        if(sr>7)  sr+=3;//space for p1-3
      }
      md192.srcRaw =sr-1; //now start with 0
      if(md192.weight<0 && md192.curve){
        md192.weight   = -md192.weight;
        md192.curveNeg = 1;
      }
    }
    
    sz = sizeof(ModelData_r192);
    model171->mdVers = MDVERS192;
  }
  if( sz == sizeof(ModelData_r192) && g_model.mdVers == MDVERS192) {
    printf("converting model data from r192 to r204\n");
    ModelData_r192 *model192 = (ModelData_r192*)&g_model;
    ModelData_r204 *model204 = (ModelData_r204*)&g_model;
    memmove(&model204->trimData,&model192->trimData,sizeof(model192->trimData));
    memset(model204->switchTab,0,sizeof(model204->switchTab));
    model204->trimData[0].tmode=0;
    model204->trimData[1].tmode=0;
    model204->trimData[2].tmode=0;
    model204->trimData[3].tmode=0;
    sz = sizeof(ModelData_r204);
    model204->mdVers = MDVERS204;
  }
  if( sz == sizeof(ModelData_TOP) && g_model.mdVers == MDVERS_TOP) {
    return;
  }

  printf("bad model%d data using default\n",id+1);
  modelDefault(id);

}

bool eeDuplicateModel(uint8_t id)
{
  uint8_t i;
  for( i=id+1; i<MAX_MODELS; i++)
  {
    if(! EFile::exists(FILE_MODEL(i))) break;
  }
  if(i==MAX_MODELS) return false; //no free space in directory left

  theFile.openRd(FILE_MODEL(id));
  theFile2.create(FILE_MODEL(i),FILE_TYP_MODEL,200);
  uint8_t buf[15];
  uint8_t l;
  while((l=theFile.read(buf,15)))
  {
    theFile2.write(buf,l);
    wdt_reset();
  }
  theFile2.closeTrunc();
  //todo error handling
  return true;
}
void eeReadAll()
{
  if(!EeFsOpen()  || 
     EeFsck() < 0 || 
     !eeLoadGeneral()
  )
  {
#ifdef SIM
    printf("bad eeprom contents\n");
#else
    alert(PSTR("Bad EEprom Data"));
#endif
    EeFsFormat();
    generalDefault();
    theFile.writeRlc2(FILE_GENERAL,FILE_TYP_GENERAL,(uint8_t*)&g_eeGeneral, 
                     sizeof(g_eeGeneral),200);

    modelDefault(0);
    theFile.writeRlc2(FILE_MODEL(0),FILE_TYP_MODEL,(uint8_t*)&g_model, 
                     sizeof(g_model),200);
  }
  eeLoadModel(g_eeGeneral.currModel);
}


static uint8_t  s_eeDirtyMsk;
static uint16_t s_eeDirtyTime10ms;
void eeDirty(uint8_t msk)
{
  if(!msk) return;
  s_eeDirtyMsk      |= msk;
  s_eeDirtyTime10ms  = g_tmr10ms;
}
#define WRITE_DELAY_10MS 100
void eeCheck(bool immediately)
{
  if(!s_eeDirtyMsk) return;
  if( !immediately && ((g_tmr10ms - s_eeDirtyTime10ms) < WRITE_DELAY_10MS)) return;
  if(s_eeDirtyMsk & EE_GENERAL){
    s_eeDirtyMsk &= ~EE_GENERAL; //not int safe
    if(theFile.writeRlc2(FILE_TMP, FILE_TYP_GENERAL, (uint8_t*)&g_eeGeneral, 
                        sizeof(g_eeGeneral),20) == sizeof(g_eeGeneral))
    {   
      EFile::swap(FILE_GENERAL,FILE_TMP);
    }else{
      if(theFile.write_errno()==ERR_TMO){
        s_eeDirtyMsk |= EE_GENERAL; //try again
        s_eeDirtyTime10ms = g_tmr10ms - WRITE_DELAY_10MS;
        printf("writing aborted GENERAL\n");
      }else{
        alert(PSTR("EEPROM overflow"));
      }
    }
    //first finish GENERAL, then MODEL !!avoid Toggle effect
  }
  else if(s_eeDirtyMsk & EE_MODEL){
    s_eeDirtyMsk &= ~EE_MODEL;//not int safe
    g_model.mdVers = MDVERS_TOP;
    if(theFile.writeRlc2(FILE_TMP, FILE_TYP_MODEL, (uint8_t*)&g_model, 
                        sizeof(g_model),20) == sizeof(g_model))
    {
      EFile::swap(FILE_MODEL(g_eeGeneral.currModel),FILE_TMP);
    }else{
      if(theFile.write_errno()==ERR_TMO){
        s_eeDirtyMsk |= EE_MODEL; //try again
        s_eeDirtyTime10ms = g_tmr10ms - WRITE_DELAY_10MS;
        printf("writing aborted MODEL\n");
      }else{
        alert(PSTR("EEPROM overflow"));
      }
    }
  }
  beepStore();
}
