/*
 * Authors (alphabetical order)
 * - Andre Bernet <bernet.andre@gmail.com>
 * - Andreas Weitl
 * - Bertrand Songis <bsongis@gmail.com>
 * - Bryan J. Rentoul (Gruvin) <gruvin@gmail.com>
 * - Cameron Weeks <th9xer@gmail.com>
 * - Erez Raviv
 * - Gabriel Birkus
 * - Jean-Pierre Parisy
 * - Karl Szmutny
 * - Michael Blandford
 * - Michal Hlavinka
 * - Pat Mackenzie
 * - Philip Moss
 * - Rob Thomson
 * - Romolo Manfredini <romolo.manfredini@gmail.com>
 * - Thomas Husterer
 *
 * opentx is based on code named
 * gruvin9x by Bryan J. Rentoul: http://code.google.com/p/gruvin9x/,
 * er9x by Erez Raviv: http://code.google.com/p/er9x/,
 * and the original (and ongoing) project by
 * Thomas Husterer, th9x: http://code.google.com/p/th9x/
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include "opentx.h"

#if defined(PCBTARANIS)
PACK(typedef struct {
  uint8_t  mode;         // 0=end, 1=pos, 2=neg, 3=both
  uint8_t  chn;
  int8_t   swtch;
  uint16_t flightModes;
  int8_t   weight;
  uint8_t  curveMode;
  char     name[LEN_EXPOMIX_NAME];
  uint8_t  spare[2];
  int8_t   curveParam;
}) ExpoData_v215;
#else
PACK(typedef struct {
  uint8_t  mode;         // 0=end, 1=pos, 2=neg, 3=both
  uint8_t  chn;
  int8_t   swtch;
  uint16_t flightModes;
  int8_t   weight;
  uint8_t  curveMode;
  char     name[LEN_EXPOMIX_NAME];
  int8_t   curveParam;
}) ExpoData_v215;
#endif

#if defined(PCBTARANIS)
  #define LIMITDATA_V215_EXTRA  char name[LEN_CHANNEL_NAME];
#else
  #define LIMITDATA_V215_EXTRA
#endif

PACK(typedef struct {
  int8_t  min;
  int8_t  max;
  int8_t  ppmCenter;
  int16_t offset:14;
  uint16_t symetrical:1;
  uint16_t revert:1;
  LIMITDATA_V215_EXTRA
}) LimitData_v215;

#if defined(PCBTARANIS)
PACK(typedef struct {
  uint8_t  destCh;
  uint16_t flightModes;
  uint8_t  curveMode:1;       // O=curve, 1=differential
  uint8_t  noExpo:1;
  int8_t   carryTrim:3;
  uint8_t  mltpx:2;           // multiplex method: 0 means +=, 1 means *=, 2 means :=
  uint8_t  spare1:1;
  int16_t  weight;
  int8_t   swtch;
  int8_t   curveParam;
  uint8_t  mixWarn:4;         // mixer warning
  uint8_t  srcVariant:4;
  uint8_t  delayUp;
  uint8_t  delayDown;
  uint8_t  speedUp;
  uint8_t  speedDown;
  uint8_t  srcRaw;
  int16_t  offset;
  char     name[LEN_EXPOMIX_NAME];
  uint8_t  spare2[2];
}) MixData_v215;
#else
PACK(typedef struct {
  uint8_t  destCh;
  uint16_t flightModes;
  uint8_t  curveMode:1;       // O=curve, 1=differential
  uint8_t  noExpo:1;
  int8_t   carryTrim:3;
  uint8_t  mltpx:2;           // multiplex method: 0 means +=, 1 means *=, 2 means :=
  uint8_t  spare:1;
  int16_t  weight;
  int8_t   swtch;
  int8_t   curveParam;
  uint8_t  mixWarn:4;         // mixer warning
  uint8_t  srcVariant:4;
  uint8_t  delayUp;
  uint8_t  delayDown;
  uint8_t  speedUp;
  uint8_t  speedDown;
  uint8_t  srcRaw;
  int16_t  offset;
  char     name[LEN_EXPOMIX_NAME];
}) MixData_v215;
#endif

PACK(typedef struct {
  int8_t    mode;            // timer trigger source -> off, abs, stk, stk%, sw/!sw, !m_sw/!m_sw
  uint16_t  start:12;
  uint16_t  countdownBeep:1;
  uint16_t  minuteBeep:1;
  uint16_t  persistent:1;
  uint16_t  spare:1;
  uint16_t  value;
}) TimerData_v215;

PACK(typedef struct {
  int16_t trim[4];
  int8_t swtch;       // swtch of phase[0] is not used
  char name[LEN_FP_NAME];
  uint8_t fadeIn;
  uint8_t fadeOut;
  ROTARY_ENCODER_ARRAY;
  gvar_t gvars[5];
}) FlightModeData_v215;

PACK(typedef struct {
  int16_t v1;
  int16_t v2;
  uint8_t func;
  uint8_t delay;
  uint8_t duration;
  int8_t  andsw;
}) LogicalSwitchData_v215;

#if defined(PCBTARANIS)
PACK(typedef struct {
  int8_t  swtch;
  uint8_t func;
  PACK(union {
    char name[10];
    struct {
      int16_t val;
      int16_t ext1;
      int16_t ext2;
    } composite;
  }) param;
  uint8_t mode:2;
  uint8_t active:6;
}) CustomFnData_v215;
#else
PACK(typedef struct {
  int8_t  swtch;
  uint8_t func;
  PACK(union {
    char name[6];
    struct {
      int16_t val;
      int16_t ext1;
      int16_t ext2;
    } composite;
  }) param;
  uint8_t mode:2;
  uint8_t active:6;
}) CustomFnData_v215;
#endif

PACK(typedef struct {
  FrSkyChannelData channels[2];
  uint8_t usrProto; // Protocol in FrSky user data, 0=None, 1=FrSky hub, 2=WS HowHigh, 3=Halcyon
  uint8_t voltsSource;
  uint8_t blades;   // How many blades for RPMs, 0=2 blades, 1=3 blades
  uint8_t currentSource;
  uint8_t screensType;
  FrSkyScreenData screens[MAX_FRSKY_SCREENS];
  uint8_t varioSource;
  int8_t  varioCenterMax;
  int8_t  varioCenterMin;
  int8_t  varioMin;
  int8_t  varioMax;
  FrSkyRSSIAlarm rssiAlarms[2];
}) FrSkyData_v215;

PACK(typedef struct {
  ModelHeader header;
  TimerData_v215 timers[MAX_TIMERS];
  uint8_t   protocol:3;
  uint8_t   thrTrim:1;            // Enable Throttle Trim
  int8_t    ppmNCH:4;
  uint8_t   trimInc:3;            // Trim Increments
  uint8_t   disableThrottleWarning:1;
  uint8_t   pulsePol:1;
  uint8_t   extendedLimits:1;
  uint8_t   extendedTrims:1;
  uint8_t   throttleReversed:1;
  int8_t    ppmDelay;
  BeepANACenter beepANACenter;        // 1<<0->A1.. 1<<6->A7
  MixData_v215   mixData[MAX_MIXERS];
  LimitData_v215 limitData[NUM_CHNOUT];
  ExpoData_v215  expoData[32];

  int16_t   curves[16];
  int8_t    points[NUM_POINTS];

  LogicalSwitchData_v215 logicalSw[NUM_LOGICAL_SWITCH];
  CustomFnData_v215 funcSw[32];
  SwashRingData swashR;
  FlightModeData_v215 flightModeData[MAX_FLIGHT_MODES];

  int8_t    ppmFrameLength;       // 0=22.5ms  (10ms-30ms) 0.5ms increments
  uint8_t   thrTraceSrc;

  swstate_t switchWarningStates;

  char gvar_names[5][LEN_GVAR_NAME];

  FrSkyData_v215 frsky;

  MODELDATA_EXTRA

}) ModelData_v215;

#if defined(PCBTARANIS)
  #define NUM_POTS_215 4
#else
  #define NUM_POTS_215 3
#endif

PACK(typedef struct {
  uint8_t   version;
  uint16_t  variant;
  int16_t   calibMid[NUM_STICKS+NUM_POTS_215];
  int16_t   calibSpanNeg[NUM_STICKS+NUM_POTS_215];
  int16_t   calibSpanPos[NUM_STICKS+NUM_POTS_215];
  uint16_t  chkSum;
  int8_t    currModel;
  uint8_t   contrast;
  uint8_t   vBatWarn;
  int8_t    vBatCalib;
  int8_t    backlightMode;
  TrainerData trainer;
  uint8_t   view;            // index of view in main screen
  int8_t    buzzerMode:2;    // -2=quiet, -1=only alarms, 0=no keys, 1=all
  uint8_t   fai:1;
  int8_t    beepMode:2;      // -2=quiet, -1=only alarms, 0=no keys, 1=all
  uint8_t   alarmsFlash:1;
  uint8_t   disableMemoryWarning:1;
  uint8_t   disableAlarmWarning:1;
  uint8_t   stickMode:2;
  int8_t    timezone:5;
  uint8_t   spare1:1;
  uint8_t   inactivityTimer;
  uint8_t   mavbaud:3;
  SPLASH_MODE; /* 3bits */
  int8_t    hapticMode:2;    // -2=quiet, -1=only alarms, 0=no keys, 1=all
  uint8_t   blOffBright:4;
  uint8_t   blOnBright:4;
  uint8_t   lightAutoOff;
  uint8_t   templateSetup;   // RETA order for receiver channels
  int8_t    PPM_Multiplier;
  int8_t    hapticLength;
  uint8_t   reNavigation;    // not used on STOCK board
  int8_t    beepLength:3;
  uint8_t   hapticStrength:3;
  uint8_t   gpsFormat:1;
  uint8_t   unexpectedShutdown:1;
  uint8_t   speakerPitch;
  int8_t    speakerVolume;
  int8_t    vBatMin;
  int8_t    vBatMax;
  uint8_t   backlightBright;
  int8_t    currentCalib;
  int8_t    temperatureWarn;
  uint8_t   mAhWarn;
  uint16_t  mAhUsed;
  uint32_t  globalTimer;
  int8_t    temperatureCalib;
  uint8_t   btBaudrate;
  uint8_t   optrexDisplay;
  uint8_t   sticksGain;
  uint8_t   rotarySteps;
  uint8_t   countryCode;
  uint8_t   imperial;
  char      ttsLanguage[2];
  int8_t    beepVolume;
  int8_t    wavVolume;
  int8_t    varioVolume;
  int8_t    backgroundVolume;
}) GeneralSettings_v215;

void ConvertGeneralSettings_215_to_216(EEGeneral &settings)
{
  GeneralSettings_v215 oldSettings;
  memcpy(&oldSettings, &settings, sizeof(oldSettings));

  settings.version = 216;
  for (int i=0, j=0; i<NUM_STICKS+NUM_POTS; i++) {
    settings.calib[i].mid = oldSettings.calibMid[j];
    settings.calib[i].spanNeg = oldSettings.calibSpanNeg[j];
    settings.calib[i].spanPos = oldSettings.calibSpanPos[j];
#if defined(PCBTARANIS)
    if (i==POT3) continue;
#endif
    j++;
  }
  settings.chkSum = evalChkSum();

  memcpy(&settings.currModel, &oldSettings.currModel, sizeof(GeneralSettings_v215)-offsetof(GeneralSettings_v215, currModel));

  settings.hapticStrength = 0; // Haptic strength reset
}

int ConvertTelemetrySource_215_to_216(int source)
{
  // TELEM_TX_TIME and 5 spare added
  if (source >= TELEM_TX_TIME)
    source += 6;
  // TELEM_RSSI_TX added
  if (source >= TELEM_RSSI_TX)
    source += 1;
  // Reserve added
  if (source >= TELEM_RESERVE0)
    source += 1;
  // A3 and A4 added
  if (source >= TELEM_A3)
    source += 2;
  // ASpd and dTE added + 5 reserve
  if (source >= TELEM_ASPEED)
    source += 7;
  // A3 and A4 MIN added
  if (source >= TELEM_MIN_A3)
    source += 2;
  // ASpd+ Cel- Cels- and Vfas- added
  if (source >= TELEM_MAX_ASPEED)
    source += 4;
  // 5 reserve added
  if (source >= TELEM_RESERVE6)
    source += 5;

  return source;
}

#if defined(PCBTARANIS)
int ConvertSource_215_to_216(int source, bool insertZero=false)
{
  if (insertZero)
    source += 1;
  // Virtual Inputs and Lua Outputs added
  if (source > 0)
    source += MAX_INPUTS + MAX_SCRIPTS*MAX_SCRIPT_OUTPUTS;
  // S3 added
  if (source > MIXSRC_POT2)
    source += 1;
  // PPM9-PPM16 added
  if (source > MIXSRC_FIRST_TRAINER+7)
    source += 8;
  // 4 GVARS added
  if (source > MIXSRC_GVAR1+4)
    source += 4;
  // Telemetry conversions
  if (source >= MIXSRC_FIRST_TELEM)
    source = MIXSRC_FIRST_TELEM + ConvertTelemetrySource_215_to_216(source-MIXSRC_FIRST_TELEM+1) - 1;

  return source;
}

int ConvertSwitch_215_to_216(int swtch)
{
  if (swtch < 0)
    return -ConvertSwitch_215_to_216(-swtch);
  else if (swtch <= SWSRC_LAST_SWITCH)
    return swtch;
  else if (swtch > SWSRC_LAST_SWITCH + 32 + 1) {
    swtch -= (SWSRC_LAST_SWITCH + 32 + 1);
    if (swtch > SWSRC_ON)
      swtch = 0;
    return swtch;
  }
  else {
    swtch += (2*4) + (3*6); // 4 trims and 2 * 6-pos added as switches
    return swtch;
  }
}
#else
int ConvertSource_215_to_216(int source, bool insertZero=false)
{
  if (insertZero)
    source += 1;
  // PPM9-PPM16 added
  if (source > MIXSRC_FIRST_TRAINER+7)
    source += 8;
  // 4 GVARS added
  if (source > MIXSRC_GVAR1+4)
    source += 4;
  // Telemetry conversions
  if (source >= MIXSRC_FIRST_TELEM)
    source = MIXSRC_FIRST_TELEM + ConvertTelemetrySource_215_to_216(source-MIXSRC_FIRST_TELEM+1) - 1;

  return source;
}

int ConvertSwitch_215_to_216(int swtch)
{
  if (swtch < 0)
    return -ConvertSwitch_215_to_216(-swtch);
  else if (swtch <= SWSRC_LAST_SWITCH)
    return swtch;
  else {
    swtch += (2*4) + 1; // 4 trims and REa added
    if (swtch > SWSRC_ON)
      swtch -= (9+32+1);
    if (swtch > SWSRC_ON)
      swtch = SWSRC_ON;
    return swtch;
  }
}
#endif

int16_t ConvertGVAR_215_to_216(int16_t var)
{
  if (var <= -508)
    return var + 512 - 4096;
  else if (var >= 507)
    return var - 512 + 4096;
  else
    return var;
}

void ConvertModel_215_to_216(ModelData &model)
{
  // Virtual inputs added instead of Expo/DR
  // LUA scripts added
  // GVARS: now 9 GVARS, popup param added
  // Curves: structure changed, 32 curves
  // Limits: min and max with PREC1
  // Custom Functions: play repeat * 5
  // Logical Switches: better precision for x when A comes from telemetry
  // Main View: altitude in top bar
  // Mixes: GVARS in weight moved from 512 to 4096 and -512 to -4096, because GVARS may be used in limits [-1250:1250]
  // Switches: two 6-pos pots added, REa added to Sky9x

  assert(sizeof(ModelData_v215) <= sizeof(ModelData));

  ModelData_v215 oldModel;
  memcpy(&oldModel, &model, sizeof(oldModel));
  memset(&model, 0, sizeof(ModelData));

  char name[LEN_MODEL_NAME+1];
  zchar2str(name, oldModel.header.name, LEN_MODEL_NAME);
  TRACE("Model %s conversion from v215 to v216", name);

  memcpy(&g_model.header, &oldModel.header, sizeof(g_model.header));
  for (uint8_t i=0; i<2; i++) {
    TimerData & timer = g_model.timers[i];
    if (oldModel.timers[i].mode >= TMRMODE_COUNT)
      timer.mode = TMRMODE_COUNT + ConvertSwitch_215_to_216(oldModel.timers[i].mode - TMRMODE_COUNT + 1) - 1;
    else
      timer.mode = oldModel.timers[i].mode;
    timer.start = oldModel.timers[i].start;
    timer.minuteBeep = oldModel.timers[i].minuteBeep;
    timer.persistent = oldModel.timers[i].persistent;
    timer.countdownBeep = oldModel.timers[i].countdownBeep;
    timer.value = oldModel.timers[i].value;
  }
  g_model.thrTrim = oldModel.thrTrim;
  g_model.trimInc = oldModel.trimInc - 2;
  g_model.disableThrottleWarning = oldModel.disableThrottleWarning;
  g_model.extendedLimits = oldModel.extendedLimits;
  g_model.extendedTrims = oldModel.extendedTrims;
  g_model.throttleReversed = oldModel.throttleReversed;

#if defined(PCBTARANIS)
  g_model.beepANACenter = (oldModel.beepANACenter & 0x3f) | ((oldModel.beepANACenter & 0xc0) << 1);
#else
  g_model.beepANACenter = oldModel.beepANACenter;
#endif

  for (uint8_t i=0; i<64; i++) {
    MixData * mix = &g_model.mixData[i];
    MixData_v215 * oldMix = &oldModel.mixData[i];
#if defined(PCBTARANIS)
    mix->destCh = oldMix->destCh;
    mix->flightModes = oldMix->flightModes;
    mix->mltpx = oldMix->mltpx;
    if (oldMix->carryTrim == TRIM_OFF) mix->carryTrim = TRIM_OFF;
    mix->weight = ConvertGVAR_215_to_216(oldMix->weight);
    mix->swtch = ConvertSwitch_215_to_216(oldMix->swtch);
    if (oldMix->curveMode==0/*differential*/) {
      mix->curve.type = CURVE_REF_DIFF;
      mix->curve.value = oldMix->curveParam;
    }
    else if (oldMix->curveParam <= 6) {
      mix->curve.type = CURVE_REF_FUNC;
      mix->curve.value = oldMix->curveParam;
    }
    else {
      mix->curve.type = CURVE_REF_CUSTOM;
      mix->curve.value = oldMix->curveParam - 6;
    }
    mix->mixWarn = oldMix->mixWarn;
    mix->delayUp = oldMix->delayUp;
    mix->delayDown = oldMix->delayDown;
    mix->speedUp = oldMix->speedUp;
    mix->speedDown = oldMix->speedDown;
    mix->srcRaw = oldMix->srcRaw;
    if (mix->srcRaw > 4 || oldMix->noExpo)
      mix->srcRaw = ConvertSource_215_to_216(mix->srcRaw);
    mix->offset = ConvertGVAR_215_to_216(oldMix->offset);
    memcpy(mix->name, oldMix->name, LEN_EXPOMIX_NAME);
    if (!GV_IS_GV_VALUE(mix->weight, 500, 500) && !GV_IS_GV_VALUE(mix->offset, 500, 500)) {
      mix->offset = divRoundClosest(mix->offset * mix->weight, 100);
    }
#else
    mix->destCh = oldMix->destCh;
    mix->mixWarn = oldMix->mixWarn;
    mix->flightModes = oldMix->flightModes;
    mix->curveMode = oldMix->curveMode;
    mix->noExpo = oldMix->noExpo;
    mix->carryTrim = oldMix->carryTrim;
    mix->mltpx = oldMix->mltpx;
    mix->weight = oldMix->weight;
    mix->swtch = ConvertSwitch_215_to_216(oldMix->swtch);
    mix->curveParam = oldMix->curveParam;
    mix->delayUp = oldMix->delayUp;
    mix->delayDown = oldMix->delayDown;
    mix->speedUp = oldMix->speedUp;
    mix->speedDown = oldMix->speedDown;
    mix->srcRaw = ConvertSource_215_to_216(oldMix->srcRaw);
    mix->offset = oldMix->offset;
    memcpy(mix->name, oldMix->name, LEN_EXPOMIX_NAME);
#endif
  }
  for (uint8_t i=0; i<32; i++) {
#if defined(PCBTARANIS)
    g_model.limitData[i].min = 10 * oldModel.limitData[i].min;
    g_model.limitData[i].max = 10 * oldModel.limitData[i].max;
#else
    g_model.limitData[i].min = oldModel.limitData[i].min;
    g_model.limitData[i].max = oldModel.limitData[i].max;
#endif
    g_model.limitData[i].ppmCenter = oldModel.limitData[i].ppmCenter;
    g_model.limitData[i].offset = oldModel.limitData[i].offset;
    g_model.limitData[i].symetrical = oldModel.limitData[i].symetrical;
    g_model.limitData[i].revert = oldModel.limitData[i].revert;
#if defined(PCBTARANIS)
    memcpy(g_model.limitData[i].name, oldModel.limitData[i].name, LEN_CHANNEL_NAME);
#endif
  }
#if defined(PCBTARANIS)
  int indexes[NUM_STICKS] = { 0, 0, 0, 0 };
#endif
  for (uint8_t i=0; i<32; i++) {
    ExpoData * expo = &g_model.expoData[i];
    ExpoData_v215 * oldExpo = &oldModel.expoData[i];
    if (oldExpo->mode) {
#if defined(PCBTARANIS)
      uint8_t chn = oldExpo->chn;
      if (!oldExpo->swtch && !oldExpo->flightModes) {
        indexes[chn] = -1;
      }
      else if (indexes[chn] != -1) {
        indexes[chn] = i+1;
      }
      for (uint8_t j=chn+1; j<NUM_STICKS; j++) {
        indexes[j] = i+1;
      }
      expo->srcRaw = MIXSRC_Rud+chn;
      expo->chn = chn;
      expo->mode = oldExpo->mode;
      expo->swtch = ConvertSwitch_215_to_216(oldExpo->swtch);
      expo->flightModes = oldExpo->flightModes;
      expo->weight = oldExpo->weight;
      memcpy(expo->name, oldExpo->name, LEN_EXPOMIX_NAME);
      if (oldExpo->curveMode==0/*expo*/) {
        if (oldExpo->curveParam) {
          expo->curve.type = CURVE_REF_EXPO;
          expo->curve.value = oldExpo->curveParam;
        }
      }
      else if (oldExpo->curveParam <= 6) {
        expo->curve.type = CURVE_REF_FUNC;
        expo->curve.value = oldExpo->curveParam;
      }
      else {
        expo->curve.type = CURVE_REF_CUSTOM;
        expo->curve.value = oldExpo->curveParam - 6;
      }
#else
      expo->mode = oldExpo->mode;
      expo->chn = oldExpo->chn;
      expo->curveMode = oldExpo->curveMode;
      expo->swtch = oldExpo->swtch;
      expo->flightModes = oldExpo->flightModes;
      expo->weight = oldExpo->weight;
      memcpy(expo->name, oldExpo->name, LEN_EXPOMIX_NAME);
      expo->curveParam = oldExpo->curveParam;
#endif
    }
    else {
      break;
    }
  }
#if defined(PCBTARANIS)
  for (int i=NUM_STICKS-1; i>=0; i--) {
    int idx = indexes[i];
    if (idx >= 0) {
      ExpoData * expo = expoAddress(idx);
      memmove(expo+1, expo, (MAX_EXPOS-(idx+1))*sizeof(ExpoData));
      memclear(expo, sizeof(ExpoData));
      expo->srcRaw = MIXSRC_Rud + i;
      expo->chn = i;
      expo->weight = 100;
      expo->curve.type = CURVE_REF_EXPO;
      expo->mode = 3;
    }
    for (int c=0; c<4; c++) {
      g_model.inputNames[i][c] = char2idx(STR_VSRCRAW[1+STR_VSRCRAW[0]*(i+1)+c]);
    }
  }
#endif
  for (uint8_t i=0; i<16; i++) {
#if defined(PCBTARANIS)
    int8_t *cur = &oldModel.points[i==0 ? 0 : 5*i+oldModel.curves[i-1]];
    int8_t *nxt = &oldModel.points[5+5*i+oldModel.curves[i]];
    uint8_t size = nxt - cur;
    if ((size & 1) == 0) {
      g_model.curves[i].type = CURVE_TYPE_CUSTOM;
      g_model.curves[i].points = (size / 2) - 4;
    }
    else {
      g_model.curves[i].points = size-5;
    }
#else
    g_model.curves[i] = oldModel.curves[i];
#endif
  }
  for (uint16_t i=0; i<512; i++) {
    g_model.points[i] = oldModel.points[i];
  }
  for (uint8_t i=0; i<32; i++) {
    LogicalSwitchData & sw = g_model.logicalSw[i];
    sw.func = oldModel.logicalSw[i].func;
    if (sw.func >= LS_FUNC_VEQUAL) sw.func += 1;
    if (sw.func >= LS_FUNC_RANGE) sw.func += 1;
    if (sw.func >= LS_FUNC_STAY) sw.func += 1;
    sw.v1 = oldModel.logicalSw[i].v1;
    sw.v2 = oldModel.logicalSw[i].v2;
    sw.delay = oldModel.logicalSw[i].delay * 5;
    sw.duration = oldModel.logicalSw[i].duration * 5;
    sw.andsw = ConvertSwitch_215_to_216(oldModel.logicalSw[i].andsw);
    uint8_t cstate = lswFamily(sw.func);
    if (cstate == LS_FAMILY_BOOL) {
      sw.v1 = ConvertSwitch_215_to_216(sw.v1);
      sw.v2 = ConvertSwitch_215_to_216(sw.v2);
    }
    else if (cstate == LS_FAMILY_OFS || cstate == LS_FAMILY_COMP || cstate == LS_FAMILY_DIFF) {
      sw.v1 = ConvertSource_215_to_216(sw.v1);
      if (cstate == LS_FAMILY_OFS || cstate == LS_FAMILY_DIFF) {
        if ((uint8_t)sw.v1 >= MIXSRC_FIRST_TELEM) {
          switch ((uint8_t)sw.v1) {
            case MIXSRC_FIRST_TELEM + TELEM_TIMER1-1:
            case MIXSRC_FIRST_TELEM + TELEM_TIMER2-1:
              sw.v2 = (sw.v2+128) * 3;
              break;
            case MIXSRC_FIRST_TELEM + TELEM_ALT-1:
            case MIXSRC_FIRST_TELEM + TELEM_GPSALT-1:
            case MIXSRC_FIRST_TELEM + TELEM_MIN_ALT-1:
            case MIXSRC_FIRST_TELEM + TELEM_MAX_ALT-1:
              sw.v2 = (sw.v2+128) * 8 - 500;
              break;
            case MIXSRC_FIRST_TELEM + TELEM_RPM-1:
            case MIXSRC_FIRST_TELEM + TELEM_MAX_RPM-1:
              sw.v2 = (sw.v2+128) * 50;
              break;
            case MIXSRC_FIRST_TELEM + TELEM_T1-1:
            case MIXSRC_FIRST_TELEM + TELEM_T2-1:
            case MIXSRC_FIRST_TELEM + TELEM_MAX_T1-1:
            case MIXSRC_FIRST_TELEM + TELEM_MAX_T2-1:
              sw.v2 = (sw.v2+128) + 30;
              break;
            case MIXSRC_FIRST_TELEM + TELEM_CELL-1:
            case MIXSRC_FIRST_TELEM + TELEM_HDG-1:
              sw.v2 = (sw.v2+128) * 2;
              break;
            case MIXSRC_FIRST_TELEM + TELEM_DIST-1:
            case MIXSRC_FIRST_TELEM + TELEM_MAX_DIST-1:
              sw.v2 = (sw.v2+128) * 8;
              break;
            case MIXSRC_FIRST_TELEM + TELEM_CURRENT-1:
            case MIXSRC_FIRST_TELEM + TELEM_POWER-1:
              sw.v2 = (sw.v2+128) * 5;
              break;
            case MIXSRC_FIRST_TELEM + TELEM_CONSUMPTION-1:
              sw.v2 = (sw.v2+128) * 20;
              break;
            default:
              sw.v2 += 128;
              break;
          }
        }
      }
      else if (cstate == LS_FAMILY_COMP) {
        sw.v2 = ConvertSource_215_to_216(sw.v2);
      }
    }
  }
  for (uint8_t i=0; i<32; i++) {
    CustomFnData & fn = g_model.funcSw[i];
    fn.swtch = ConvertSwitch_215_to_216(oldModel.funcSw[i].swtch);
    fn.func = oldModel.funcSw[i].func;
    if (fn.func <= 15) {
      fn.all.param = fn.func;
      fn.func = FUNC_OVERRIDE_CHANNEL;
    }
    else if (fn.func <= 20) {
      fn.all.param = fn.func - 16;
      fn.func = FUNC_TRAINER;
    }
    else if (fn.func == 21) {
      fn.func = FUNC_INSTANT_TRIM;
    }
    else if (fn.func == 22) {
      fn.func = FUNC_PLAY_SOUND;
    }
#if defined(PCBSKY9X)
    else if (fn.func == 23) {
      fn.func = FUNC_HAPTIC;
    }
#endif
    else if (fn.func == 23+IS_PCBSKY9X) {
      fn.func = FUNC_RESET;
    }
    else if (fn.func == 24+IS_PCBSKY9X) {
      fn.func = FUNC_VARIO;
    }
    else if (fn.func == 25+IS_PCBSKY9X) {
      fn.func = FUNC_PLAY_TRACK;
    }
    else if (fn.func == 26+IS_PCBSKY9X) {
      fn.func = FUNC_PLAY_VALUE;
    }
    else if (fn.func == 27+IS_PCBSKY9X) {
      fn.func = FUNC_LOGS;
    }
    else if (fn.func == 28+IS_PCBSKY9X) {
      fn.func = FUNC_VOLUME;
    }
    else if (fn.func == 29+IS_PCBSKY9X) {
      fn.func = FUNC_BACKLIGHT;
    }
    else if (fn.func == 30+IS_PCBSKY9X) {
      fn.func = FUNC_BACKGND_MUSIC;
    }
    else if (fn.func == 31+IS_PCBSKY9X) {
      fn.func = FUNC_BACKGND_MUSIC_PAUSE;
    }
    else {
      fn.all.param = fn.func - 32 - IS_PCBSKY9X;
      fn.all.mode = oldModel.funcSw[i].mode;
      fn.func = FUNC_ADJUST_GVAR;
    }

    fn.active = oldModel.funcSw[i].active;
    if (HAS_REPEAT_PARAM(fn.func)) {
      fn.active *= 5;
    }

    if (fn.func == FUNC_PLAY_TRACK || fn.func == FUNC_BACKGND_MUSIC) {
      memcpy(fn.play.name, oldModel.funcSw[i].param.name, 8);
    }
    else {
      fn.all.val = oldModel.funcSw[i].param.composite.val;
    }
    if (fn.func == FUNC_PLAY_VALUE || fn.func == FUNC_VOLUME || (IS_ADJUST_GV_FUNC(fn.func) && fn.all.mode == FUNC_ADJUST_GVAR_SOURCE)) {
#if defined(PCBTARANIS)
      fn.all.val = ConvertSource_215_to_216(fn.all.val, true);
#endif
    }
  }

  g_model.swashR = oldModel.swashR;
  g_model.swashR.collectiveSource = ConvertSource_215_to_216(g_model.swashR.collectiveSource);

  for (uint8_t i=0; i<9; i++) {
    if (i==0 || oldModel.flightModeData[i].swtch) {
      memcpy(&g_model.flightModeData[i], &oldModel.flightModeData[i], sizeof(oldModel.flightModeData[i])); // the last 4 gvars will remain blank
      g_model.flightModeData[i].swtch = ConvertSwitch_215_to_216(oldModel.flightModeData[i].swtch);
#if defined(PCBTARANIS)
      for (uint8_t t=0; t<4; t++) {
        int trim = oldModel.flightModeData[i].trim[t];
        if (trim > 500) {
          trim -= 501;
          if (trim >= i)
            trim += 1;
          g_model.flightModeData[i].trim[t].mode = 2*trim;
          g_model.flightModeData[i].trim[t].value = 0;
        }
        else {
          g_model.flightModeData[i].trim[t].mode = 2*i;
          g_model.flightModeData[i].trim[t].value = trim;
        }
      }
#endif
    }
  }
  g_model.thrTraceSrc = oldModel.thrTraceSrc;
#if defined(PCBTARANIS)
  // S3 added
  if (g_model.thrTraceSrc >= THROTTLE_SOURCE_S3)
    g_model.thrTraceSrc += 1;
#endif
  g_model.switchWarningStates = oldModel.switchWarningStates >> 1;
  g_model.nSwToWarn = (oldModel.switchWarningStates & 0x01) ? 0xFF : 0;
  for (uint8_t i=0; i<5; i++) {
    memcpy(g_model.gvars[i].name, oldModel.gvar_names[i], LEN_GVAR_NAME);
  }

#if defined(FRSKY)
  memcpy(&g_model.frsky, &oldModel.frsky, 2*sizeof(FrSkyChannelData));
  // gap for A3-A4
  memcpy(((uint8_t *)&g_model.frsky) + 4*sizeof(FrSkyChannelData), ((uint8_t *)&oldModel.frsky) + 2*sizeof(FrSkyChannelData), sizeof(oldModel.frsky) - 2*sizeof(FrSkyChannelData));
  // A3 and A4 introduced
  if (g_model.frsky.voltsSource >= FRSKY_VOLTS_SOURCE_A3)
    g_model.frsky.voltsSource += 2;
  if (g_model.frsky.currentSource >= FRSKY_CURRENT_SOURCE_A3)
    g_model.frsky.currentSource += 2;

  for (int i=0; i<3; i++) {
    if (g_model.frsky.screensType & (1<<i)) {
      // gauges
      for (int j=0; j<4; j++) {
        uint8_t & source = g_model.frsky.screens[i].bars[j].source;
        source = ConvertTelemetrySource_215_to_216(source);
      }
    }
    else {
      // numbers
      for (int j=0; j<4; j++) {
        for (int k=0; k<NUM_LINE_ITEMS; k++) {
          uint8_t & source = g_model.frsky.screens[i].lines[j].sources[k];
          source = ConvertTelemetrySource_215_to_216(source);
        }
      }
    }
  }
#endif

#if defined(PCBTARANIS)
  g_model.externalModule = oldModel.externalModule;
  g_model.trainerMode = oldModel.trainerMode;
  memcpy(g_model.curveNames, oldModel.curveNames, sizeof(g_model.curveNames));
#endif

  memcpy(g_model.moduleData, oldModel.moduleData, sizeof(g_model.moduleData));
}

void ConvertModel(int id, int version)
{
  loadModel(id);

  if (version == 215) {
    version = 216;
    ConvertModel_215_to_216(g_model);
  }

  uint8_t currModel = g_eeGeneral.currModel;
  g_eeGeneral.currModel = id;
  s_eeDirtyMsk = EE_MODEL;
  eeCheck(true);
  g_eeGeneral.currModel = currModel;
}

bool eeConvert()
{
  const char *msg = NULL;

  if (g_eeGeneral.version == 215) {
    msg = PSTR("EEprom Data v215");
  }
  else {
    return false;
  }

  int conversionVersionStart = g_eeGeneral.version;

  // Information to the user and wait for key press
  g_eeGeneral.optrexDisplay = 0;
  g_eeGeneral.backlightMode = e_backlight_mode_on;
  g_eeGeneral.backlightBright = 0;
  g_eeGeneral.contrast = 25;
  ALERT(STR_EEPROMWARN, msg, AU_BAD_EEPROM);

  // Message
  MESSAGE(STR_EEPROMWARN, STR_EEPROM_CONVERTING, NULL, AU_EEPROM_FORMATTING); // TODO translations

  // General Settings conversion
  loadGeneralSettings();
  int version = conversionVersionStart;
  if (version == 215) {
    version = 216;
    ConvertGeneralSettings_215_to_216(g_eeGeneral);
  }
  s_eeDirtyMsk = EE_GENERAL;
  eeCheck(true);

#if LCD_W >= 212
  lcd_rect(60, 6*FH+4, 132, 3);
#else
  lcd_rect(10, 6*FH+4, 102, 3);
#endif

  // Models conversion
  for (uint8_t id=0; id<MAX_MODELS; id++) {
#if LCD_W >= 212
    lcd_hline(61, 6*FH+5, 10+id*2, FORCE);
#else
    lcd_hline(11, 6*FH+5, 10+(id*3)/2, FORCE);
#endif
    lcdRefresh();
    if (eeModelExists(id)) {
      ConvertModel(id, conversionVersionStart);
    }

  }

  return true;
}
