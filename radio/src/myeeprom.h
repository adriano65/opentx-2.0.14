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

#ifndef myeeprom_h
#define myeeprom_h

#include <inttypes.h>

#if defined(EXPORT)
  #define LUA_EXPORT(...)                     LEXP(__VA_ARGS__)
  #define LUA_EXPORT_TELEMETRY(...)           LEXP_TELEMETRY(__VA_ARGS__)
  #define LUA_EXPORT_MULTIPLE(...)            LEXP_MULTIPLE(__VA_ARGS__)
  #define LUA_EXPORT_EXTRA(...)               LEXP_EXTRA(__VA_ARGS__)
#else 
  #define LUA_EXPORT(...)
  #define LUA_EXPORT_TELEMETRY(...)
  #define LUA_EXPORT_MULTIPLE(...)
  #define LUA_EXPORT_EXTRA(...)
#endif 

#define WARN_THR_BIT  0x01
#define WARN_BEP_BIT  0x80
#define WARN_SW_BIT   0x02
#define WARN_MEM_BIT  0x04
#define WARN_BVAL_BIT 0x38

#define WARN_THR     (!(g_eeGeneral.warnOpts & WARN_THR_BIT))
#define WARN_BEP     (!(g_eeGeneral.warnOpts & WARN_BEP_BIT))
#define WARN_SW      (!(g_eeGeneral.warnOpts & WARN_SW_BIT))
#define WARN_MEM     (!(g_eeGeneral.warnOpts & WARN_MEM_BIT))
#define BEEP_VAL     ( (g_eeGeneral.warnOpts & WARN_BVAL_BIT) >>3 )

#if defined(PCBTARANIS)
  #define EEPROM_VER             216
  #define FIRST_CONV_EEPROM_VER  215
#elif defined(PCBSKY9X)
  #define EEPROM_VER             216
  #define FIRST_CONV_EEPROM_VER  215
#elif defined(CPUM2560) || defined(CPUM2561)
  #define EEPROM_VER             217
  #define FIRST_CONV_EEPROM_VER  EEPROM_VER
#elif defined(CPUM128)
  #define EEPROM_VER             217
#else
  #define EEPROM_VER             216
#endif

#ifndef PACK
#define PACK( __Declaration__ ) __Declaration__ __attribute__((__packed__))
#endif

#if defined (CPUARM)
  #define ARM_FIELD(x) x;
  #define AVR_FIELD(x)
#else
  #define ARM_FIELD(x)
  #define AVR_FIELD(x) x;
#endif

#if defined(PCBTARANIS)
  #define MAX_MODELS          60
  #define NUM_CHNOUT          32 // number of real output channels CH1-CH32
  #define MAX_FLIGHT_MODES    9
  #define MAX_MIXERS          64
  #define MAX_EXPOS           64
  #define NUM_LOGICAL_SWITCH  32 // number of custom switches
  #define NUM_CFN             64 // number of functions assigned to switches
  #define MAX_SCRIPTS         7
  #define MAX_INPUTS          32
  #define NUM_TRAINER         16
  #define NUM_POTS            5
  #define NUM_XPOTS           3
#elif defined(CPUARM)
  #define MAX_MODELS          60
  #define NUM_CHNOUT          32 // number of real output channels CH1-CH32
  #define MAX_FLIGHT_MODES    9
  #define MAX_MIXERS          64
  #define MAX_EXPOS           32
  #define NUM_LOGICAL_SWITCH  32 // number of custom switches
  #define NUM_CFN             64      // number of functions assigned to switches
  #define NUM_TRAINER         16
  #define NUM_POTS            3
  #define NUM_XPOTS           0
#elif defined(CPUM2560) || defined(CPUM2561)
  #define MAX_MODELS          30
  #define NUM_CHNOUT          16 // number of real output channels CH1-CH16
  #define MAX_FLIGHT_MODES    6
  #define MAX_MIXERS          32
  #define MAX_EXPOS           16
  #define NUM_LOGICAL_SWITCH  12 // number of custom switches
  #define NUM_CFN             24 // number of functions assigned to switches
  #define NUM_TRAINER         8
  #define NUM_POTS            3
  #define NUM_XPOTS           0
#elif defined(CPUM128)
  #define MAX_MODELS          30
  #define NUM_CHNOUT          16 // number of real output channels CH1-CH16
  #define MAX_FLIGHT_MODES    5
  #define MAX_MIXERS          32
  #define MAX_EXPOS           14
  #define NUM_LOGICAL_SWITCH  12 // number of custom switches
  #define NUM_CFN             24 // number of functions assigned to switches
  #define NUM_TRAINER         8
  #define NUM_POTS            3
  #define NUM_XPOTS           0
#else
  #define MAX_MODELS          16
  #define NUM_CHNOUT          16 // number of real output channels CH1-CH16
  #define MAX_FLIGHT_MODES    5
  #define MAX_MIXERS          32
  #define MAX_EXPOS           14
  #define NUM_LOGICAL_SWITCH  12 // number of custom switches
  #define NUM_CFN             16 // number of functions assigned to switches
  #define NUM_TRAINER         8
  #define NUM_POTS            3
  #define NUM_XPOTS           0
#endif

#define MAX_TIMERS    2
#define NUM_CYC       3
#define NUM_CAL_PPM   4

#if defined(PCBTARANIS)
  #define LEN_MODEL_NAME     12
  #define LEN_BITMAP_NAME    10
  #define LEN_EXPOMIX_NAME   8
  #define LEN_FP_NAME        10
  #define LEN_CHANNEL_NAME   6
  #define LEN_INPUT_NAME     4
  enum CurveType {
    CURVE_TYPE_STANDARD,
    CURVE_TYPE_CUSTOM,
    CURVE_TYPE_LAST = CURVE_TYPE_CUSTOM
  };
PACK(typedef struct {
  uint8_t type:3;
  uint8_t smooth:1;
  uint8_t spare:4;
  int8_t  points;
}) CurveInfo;
  #define MAX_CURVES         32
  #define NUM_POINTS         512
  #define CURVDATA           CurveInfo
#elif defined(CPUARM)
  #define LEN_MODEL_NAME     10
  #define LEN_EXPOMIX_NAME   6
  #define LEN_FP_NAME        6
  #define MAX_CURVES         16
  #define NUM_POINTS         512
  #define CURVDATA           int16_t
#else
  #define LEN_MODEL_NAME     10
  #define LEN_FP_NAME        6
  #define MAX_CURVES         8
  #define NUM_POINTS         (112-MAX_CURVES)
  #define CURVDATA           int8_t
#endif

#if defined(PCBTARANIS) || defined(PCBSKY9X)
  #define NUM_MODULES 2
#else
  #define NUM_MODULES 1
#endif

typedef int16_t gvar_t;

#if !defined(PCBSTD)
  #define LEN_GVAR_NAME 6
  #define GVAR_MAX      1024
  #define GVAR_LIMIT    500
  PACK(typedef struct {
    char    name[LEN_GVAR_NAME];
    uint8_t popup:1;
    uint8_t spare:7;
  }) global_gvar_t;
#endif

#define RESERVE_RANGE_FOR_GVARS 10
// even we do not spend space in EEPROM for 10 GVARS, we reserve the space inside the range of values, like offset, weight, etc.

#if defined(PCBSTD) && defined(GVARS)
  #define MAX_GVARS 5
  #define MODEL_GVARS_DATA gvar_t gvars[MAX_GVARS];
  #define PHASE_GVARS_DATA
  #define GVAR_VALUE(x, p) g_model.gvars[x]
#elif defined(PCBSTD)
  #define MAX_GVARS 0
  #define MODEL_GVARS_DATA
  #define PHASE_GVARS_DATA
#else
  #if defined(CPUARM)
    #define MAX_GVARS 9
  #else
    #define MAX_GVARS 5
  #endif
  #define MODEL_GVARS_DATA global_gvar_t gvars[MAX_GVARS];
  #define PHASE_GVARS_DATA gvar_t gvars[MAX_GVARS]
  #define GVAR_VALUE(x, p) g_model.flightModeData[p].gvars[x]
#endif

PACK(typedef struct t_TrainerMix {
  uint8_t srcChn:6; // 0-7 = ch1-8
  uint8_t mode:2;   // off,add-mode,subst-mode
  int8_t  studWeight;
}) TrainerMix;

PACK(typedef struct t_TrainerData {
  int16_t        calib[4];
  TrainerMix     mix[4];
}) TrainerData;

PACK(typedef struct t_FrSkyRSSIAlarm {
  int8_t    level:2;
  int8_t    value:6;
}) FrSkyRSSIAlarm;

#if defined(PCBTARANIS)
enum MainViews {
  VIEW_TIMERS,
  VIEW_INPUTS,
  VIEW_SWITCHES,
  VIEW_COUNT
};
#else
enum MainViews {
  VIEW_OUTPUTS_VALUES,
  VIEW_OUTPUTS_BARS,
  VIEW_INPUTS,
  VIEW_TIMER2,
  VIEW_COUNT
};
#endif

enum BeeperMode {
  e_mode_quiet = -2,
  e_mode_alarms,
  e_mode_nokeys,
  e_mode_all
};

#if defined(CPUARM)
  #define EXTRA_GENERAL_FIELDS_ARM \
  uint8_t  backlightBright; \
  int8_t   currentCalib; \
  int8_t   temperatureWarn; \
  uint8_t  mAhWarn; \
  uint16_t mAhUsed; \
  uint32_t globalTimer; \
  int8_t   temperatureCalib; \
  uint8_t  btBaudrate; \
  uint8_t  optrexDisplay; \
  uint8_t  sticksGain; \
  uint8_t  rotarySteps; \
  uint8_t  countryCode; \
  uint8_t  imperial; \
  char     ttsLanguage[2]; \
  int8_t   beepVolume; \
  int8_t   wavVolume; \
  int8_t   varioVolume; \
  int8_t   varioPitch; \
  int8_t   varioRange; \
  int8_t   varioRepeat; \
  int8_t   backgroundVolume;
#endif

#if defined(PCBTARANIS)
enum uartModes {
  UART_MODE_NONE,
  UART_MODE_TELEMETRY_MIRROR,
  UART_MODE_TELEMETRY,
#if defined(DEBUG)
  UART_MODE_DEBUG,
#endif
  UART_MODE_COUNT,
  UART_MODE_MAX = UART_MODE_COUNT-1
};

#define EXTRA_GENERAL_FIELDS \
  EXTRA_GENERAL_FIELDS_ARM \
  uint8_t  uart3Mode; \
  uint8_t  potsType; \
  uint8_t  backlightColor;
#elif defined(CPUARM)
  #define EXTRA_GENERAL_FIELDS EXTRA_GENERAL_FIELDS_ARM
#elif defined(PXX)
  #define EXTRA_GENERAL_FIELDS uint8_t  countryCode;
#else
  #define EXTRA_GENERAL_FIELDS
#endif

PACK(typedef struct t_ModuleData {
  int8_t  rfProtocol;
  uint8_t channelsStart;
  int8_t  channelsCount; // 0=8 channels
  uint8_t failsafeMode;
  int16_t failsafeChannels[NUM_CHNOUT];
  int8_t  ppmDelay;
  int8_t  ppmFrameLength;
  uint8_t ppmPulsePol;
}) ModuleData;

#define SET_DEFAULT_PPM_FRAME_LENGTH(idx) g_model.moduleData[idx].ppmFrameLength = 4 * max((int8_t)0, g_model.moduleData[idx].channelsCount)

#define MAX_SCRIPT_INPUTS  10
#define MAX_SCRIPT_OUTPUTS 6
PACK(typedef struct t_ScriptData {
  char    file[10];
  char    name[10];
  int8_t  inputs[MAX_SCRIPT_INPUTS];
}) ScriptData;

#if defined(PCBTARANIS)
  enum ModuleIndex {
    INTERNAL_MODULE,
    EXTERNAL_MODULE,
    TRAINER_MODULE
  };
  #define MODELDATA_BITMAP  char bitmap[LEN_BITMAP_NAME];
  #define MODELDATA_EXTRA   uint8_t externalModule; uint8_t trainerMode; ModuleData moduleData[NUM_MODULES+1]; char curveNames[MAX_CURVES][6]; ScriptData scriptsData[MAX_SCRIPTS]; char inputNames[MAX_INPUTS][LEN_INPUT_NAME]; uint8_t nPotsToWarn; int8_t potPosition[NUM_POTS]; uint8_t spare[2];
  #define LIMITDATA_EXTRA   char name[LEN_CHANNEL_NAME]; int8_t curve;
  #define swstate_t         uint16_t
#elif defined(PCBSKY9X)
  enum ModuleIndex {
    EXTERNAL_MODULE,
    EXTRA_MODULE,
    TRAINER_MODULE
  };
  #define MODELDATA_BITMAP
  #define MODELDATA_EXTRA   uint8_t externalModule; ModuleData moduleData[NUM_MODULES+1]; uint8_t nPotsToWarn; int8_t potPosition[NUM_POTS]; uint8_t rxBattAlarms[2];
  #define LIMITDATA_EXTRA
  #define swstate_t         uint8_t
#else
  #define MODELDATA_BITMAP
  #define MODELDATA_EXTRA   
  #define LIMITDATA_EXTRA
  #define swstate_t         uint8_t
#endif

enum BacklightMode {
  e_backlight_mode_off  = 0,
  e_backlight_mode_keys = 1,
  e_backlight_mode_sticks = 2,
  e_backlight_mode_all = e_backlight_mode_keys+e_backlight_mode_sticks,
  e_backlight_mode_on
};

#if defined(FSPLASH)
  #define SPLASH_MODE uint8_t splashMode:3
#elif defined(PCBTARANIS)
  #define SPLASH_MODE int8_t splashMode:3
#else
  #define SPLASH_MODE uint8_t splashMode:1; uint8_t splashSpare:2
#endif

#define XPOTS_MULTIPOS_COUNT 6

#if defined(PCBTARANIS)
PACK(typedef struct {
  uint8_t count;
  uint8_t steps[XPOTS_MULTIPOS_COUNT-1];
}) StepsCalibData;
#endif

PACK(typedef struct {
  int16_t mid;
  int16_t spanNeg;
  int16_t spanPos;
}) CalibData;

#if defined(PCBSTD)
  #define N_PCBSTD_FIELD(x)
#else
  #define N_PCBSTD_FIELD(x) x;
#endif

#if defined(PCBTARANIS)
  #define N_TARANIS_FIELD(x)
#else
  #define N_TARANIS_FIELD(x) x;
#endif

#define ALTERNATE_VIEW 0x10
PACK(typedef struct t_EEGeneral {
  uint8_t   version;
  uint16_t  variant;
  CalibData calib[NUM_STICKS+NUM_POTS];
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
  AVR_FIELD(uint8_t blOffBright:4)
  AVR_FIELD(uint8_t blOnBright:4)
  ARM_FIELD(int8_t switchesDelay)
  uint8_t   lightAutoOff;
  uint8_t   templateSetup;   // RETA order for receiver channels
  int8_t    PPM_Multiplier;
  int8_t    hapticLength;
  N_PCBSTD_FIELD( uint8_t   reNavigation)
  N_TARANIS_FIELD(uint8_t   stickReverse)
  int8_t    beepLength:3;
  int8_t    hapticStrength:3;
  uint8_t   gpsFormat:1;
  uint8_t   unexpectedShutdown:1;
  uint8_t   speakerPitch;
  int8_t    speakerVolume;
  int8_t    vBatMin;
  int8_t    vBatMax;

  EXTRA_GENERAL_FIELDS

  swstate_t switchUnlockStates;

}) EEGeneral;

#define SWITCHES_DELAY()     uint8_t(15+g_eeGeneral.switchesDelay)
#define SWITCHES_DELAY_NONE  (-15)
#define HAPTIC_STRENGTH()    (3+g_eeGeneral.hapticStrength)

#if defined(PCBTARANIS)
enum CurveRefType {
  CURVE_REF_DIFF,
  CURVE_REF_EXPO,
  CURVE_REF_FUNC,
  CURVE_REF_CUSTOM
};
PACK(typedef struct {
  uint8_t type;
  int8_t  value;
}) CurveRef;
#else
  #define MODE_DIFFERENTIAL  0
  #define MODE_EXPO          0
  #define MODE_CURVE         1
#endif

#if defined(PCBTARANIS)
PACK(typedef struct {
  uint8_t  srcRaw;
  uint16_t scale;
  uint8_t  chn;
  int8_t   swtch;
  uint16_t flightModes;
  int8_t   weight;
  int8_t   carryTrim:6;
  uint8_t  mode:2;
  char     name[LEN_EXPOMIX_NAME];
  int8_t   offset;
  CurveRef curve;
  uint8_t  spare;
}) ExpoData;
#define MIN_EXPO_WEIGHT         -100
#define EXPO_VALID(ed)          ((ed)->mode)
#define EXPO_MODE_ENABLE(ed, v) (((v)<0 && ((ed)->mode&1)) || ((v)>=0 && ((ed)->mode&2)))
#elif defined(CPUARM)
PACK(typedef struct {
  uint8_t  mode:2;         // 0=end, 1=pos, 2=neg, 3=both
  uint8_t  chn:4;
  uint8_t  curveMode:2;
  int8_t   swtch;
  uint16_t flightModes;
  int8_t   weight;
  char     name[LEN_EXPOMIX_NAME];
  int8_t   curveParam;
}) ExpoData;
#define MIN_EXPO_WEIGHT         0
#define EXPO_VALID(ed)          ((ed)->mode)
#define EXPO_MODE_ENABLE(ed, v) (((v)<0 && ((ed)->mode&1)) || ((v)>=0 && ((ed)->mode&2)))
#elif defined(CPUM2560) || defined(CPUM2561)
PACK(typedef struct t_ExpoData {
  uint8_t mode:2;         // 0=end, 1=pos, 2=neg, 3=both
  uint8_t chn:2;
  uint8_t curveMode:1;
  uint8_t spare:3;
  uint8_t flightModes;
  int8_t  swtch;
  uint8_t weight;
  int8_t  curveParam;
}) ExpoData;
#define MIN_EXPO_WEIGHT         0
#define EXPO_VALID(ed)          ((ed)->mode)
#define EXPO_MODE_ENABLE(ed, v) (((v)<0 && ((ed)->mode&1)) || ((v)>=0 && ((ed)->mode&2)))
#else
PACK(typedef struct t_ExpoData {
  uint8_t mode:2;         // 0=end, 1=pos, 2=neg, 3=both
  int8_t  swtch:6;
  uint8_t chn:2;
  uint8_t flightModes:5;
  uint8_t curveMode:1;
  uint8_t weight;         // One spare bit here (used for GVARS)
  int8_t  curveParam;
}) ExpoData;
#define MIN_EXPO_WEIGHT         0
#define EXPO_VALID(ed)          ((ed)->mode)
#define EXPO_MODE_ENABLE(ed, v) (((v)<0 && ((ed)->mode&1)) || ((v)>=0 && ((ed)->mode&2)))
#endif

#if defined(PCBTARANIS)
  #define limit_min_max_t     int16_t
  #define LIMIT_EXT_PERCENT   150
  #define LIMIT_EXT_MAX       (LIMIT_EXT_PERCENT*10)
  #define LIMIT_MAX(lim)      (GV_IS_GV_VALUE(lim->max, -LIMIT_EXT_MAX, LIMIT_EXT_MAX) ? GET_GVAR(lim->max, -LIMIT_EXT_MAX, LIMIT_EXT_MAX, mixerCurrentFlightMode)*10 : lim->max+1000)
  #define LIMIT_MIN(lim)      (GV_IS_GV_VALUE(lim->min, -LIMIT_EXT_MAX, LIMIT_EXT_MAX) ? GET_GVAR(lim->min, -LIMIT_EXT_MAX, LIMIT_EXT_MAX, mixerCurrentFlightMode)*10 : lim->min-1000)
  #define LIMIT_OFS(lim)      (GV_IS_GV_VALUE(lim->offset, -1000, 1000) ? GET_GVAR(lim->offset, -1000, 1000, mixerCurrentFlightMode)*10 : lim->offset)
  #define LIMIT_MAX_RESX(lim) calc1000toRESX(LIMIT_MAX(lim))
  #define LIMIT_MIN_RESX(lim) calc1000toRESX(LIMIT_MIN(lim))
  #define LIMIT_OFS_RESX(lim) calc1000toRESX(LIMIT_OFS(lim))
#else
  #define limit_min_max_t     int8_t
  #define LIMIT_EXT_PERCENT   125
  #define LIMIT_EXT_MAX       LIMIT_EXT_PERCENT
  #define LIMIT_MAX(lim)      (lim->max+100)
  #define LIMIT_MIN(lim)      (lim->min-100)
  #define LIMIT_OFS(lim)      (lim->offset)
  #define LIMIT_MAX_RESX(lim) calc100toRESX(LIMIT_MAX(lim))
  #define LIMIT_MIN_RESX(lim) calc100toRESX(LIMIT_MIN(lim))
  #define LIMIT_OFS_RESX(lim) calc1000toRESX(LIMIT_OFS(lim))
#endif

PACK(typedef struct t_LimitData {
  limit_min_max_t min;
  limit_min_max_t max;
  int8_t  ppmCenter;
  int16_t offset:14;
  uint16_t symetrical:1;
  uint16_t revert:1;

  LIMITDATA_EXTRA

}) LimitData;

#define TRIM_OFF    (1)
#define TRIM_ON     (0)
#define TRIM_RUD    (-1)
#define TRIM_ELE    (-2)
#define TRIM_THR    (-3)
#define TRIM_AIL    (-4)

#define MLTPX_ADD   0
#define MLTPX_MUL   1
#define MLTPX_REP   2

#if defined(CPUARM)
#define GV1_SMALL       128
#define GV1_LARGE       4096
#define GV_RANGE_WEIGHT 500
#define GV_RANGE_OFFSET 500
#define DELAY_STEP      10
#define SLOW_STEP       10
#define DELAY_MAX       (25*DELAY_STEP) /* 25 seconds */
#define SLOW_MAX        (25*SLOW_STEP)  /* 25 seconds */
#if defined(PCBTARANIS)
PACK(typedef struct {
  uint8_t  destCh;
  uint16_t flightModes;
  uint8_t  mltpx:2;         // multiplex method: 0 means +=, 1 means *=, 2 means :=
  uint8_t  carryTrim:1;
  uint8_t  spare1:5;
  int16_t  weight;
  int8_t   swtch;
  CurveRef curve;
  uint8_t  mixWarn:4;       // mixer warning
  uint8_t  spare2:4;
  uint8_t  delayUp;
  uint8_t  delayDown;
  uint8_t  speedUp;
  uint8_t  speedDown;
  uint8_t  srcRaw;
  int16_t  offset;
  char     name[LEN_EXPOMIX_NAME];
  uint8_t  spare3;
}) MixData;
#else
PACK(typedef struct {
  uint8_t  destCh:5;
  uint8_t  mixWarn:3;         // mixer warning
  uint16_t flightModes;
  uint8_t  curveMode:1;
  uint8_t  noExpo:1;
  int8_t   carryTrim:3;
  uint8_t  mltpx:2;           // multiplex method: 0 means +=, 1 means *=, 2 means :=
  uint8_t  spare:1;
  int16_t  weight;
  int8_t   swtch;
  int8_t   curveParam;
  uint8_t  delayUp;
  uint8_t  delayDown;
  uint8_t  speedUp;
  uint8_t  speedDown;
  uint8_t  srcRaw;
  int16_t  offset;
  char     name[LEN_EXPOMIX_NAME];
}) MixData;
#endif
#define MD_WEIGHT(md) (md->weight)
#define MD_WEIGHT_TO_UNION(md, var) var.word = md->weight
#define MD_UNION_TO_WEIGHT(var, md) md->weight = var.word
// #define MD_SETWEIGHT(md, val) md->weight = val

PACK( union u_int8int16_t {
  struct {
    int8_t  lo;
    uint8_t hi;
  } bytes_t;
  int16_t word;
});

#define MD_OFFSET(md) (md->offset)
#define MD_OFFSET_TO_UNION(md, var) var.word = md->offset
#define MD_UNION_TO_OFFSET(var, md) md->offset = var.word
// #define MD_SETOFFSET(md, val) md->offset = val

#else

// highest bit used for small values in mix 128 --> 8 bit is enough
#define GV1_SMALL  128
// highest bit used for large values in mix 256 --> 9 bits is used (8 bits + 1 extra bit from weightMode/offsetMode)
#define GV1_LARGE  256

#define DELAY_STEP  2
#define SLOW_STEP   2
#define DELAY_MAX   15 /* 7.5 seconds */
#define SLOW_MAX    15 /* 7.5 seconds */

#if defined(CPUM2560) || defined(CPUM2561)
PACK(typedef struct t_MixData {
  uint8_t destCh:4;          // 0, 1..NUM_CHNOUT
  uint8_t curveMode:1;       // O=curve, 1=differential
  uint8_t noExpo:1;
  uint8_t weightMode:1;
  uint8_t offsetMode:1;
  uint8_t srcRaw;
  int8_t  weight;
  int8_t  swtch;
  uint8_t flightModes;
  uint8_t mltpx:2;           // multiplex method: 0 means +=, 1 means *=, 2 means :=
  int8_t  carryTrim:3;
  uint8_t mixWarn:2;         // mixer warning
  uint8_t spare:1;
  uint8_t delayUp:4;
  uint8_t delayDown:4;
  uint8_t speedUp:4;
  uint8_t speedDown:4;
  int8_t  curveParam;
  int8_t  offset;
}) MixData;
#else
PACK(typedef struct t_MixData {
  uint8_t destCh:4;          // 0, 1..NUM_CHNOUT
  uint8_t curveMode:1;       // O=curve, 1=differential
  uint8_t noExpo:1;
  uint8_t weightMode:1;
  uint8_t offsetMode:1;
  int8_t  weight;
  int8_t  swtch:6;
  uint8_t mltpx:2;           // multiplex method: 0 means +=, 1 means *=, 2 means :=
  uint8_t flightModes:5;
  int8_t  carryTrim:3;
  uint8_t srcRaw:6;
  uint8_t mixWarn:2;         // mixer warning
  uint8_t delayUp:4;
  uint8_t delayDown:4;
  uint8_t speedUp:4;
  uint8_t speedDown:4;
  int8_t  curveParam;
  int8_t  offset;
}) MixData;
#endif
PACK( union u_gvarint_t {
  struct {
    int8_t lo;
    uint8_t hi;
  } bytes_t;
  int16_t word;
	
  u_gvarint_t(int8_t l, uint8_t h) {bytes_t.lo=l; bytes_t.hi=h?255:0;} // hi bit is negativ sign

private:
  // prevent unwanted constructors, also saves program
  u_gvarint_t() {}
  u_gvarint_t(const u_gvarint_t&) {}
}); 
#define MD_WEIGHT(md) (u_gvarint_t(md->weight,md->weightMode).word)
  
PACK( union u_int8int16_t {
  struct {
    int8_t  lo;
    uint8_t hi;
  } bytes_t;
  int16_t word;
});

#define MD_WEIGHT_TO_UNION(md, var) var.bytes_t.lo=md->weight; var.bytes_t.hi=md->weightMode?255:0
#define MD_UNION_TO_WEIGHT(var, md) md->weight=var.bytes_t.lo; if (var.word<0) md->weightMode=1; else md->weightMode=0
// #define MD_SETWEIGHT(md, val) md->weight=val; if (val<0) md->weightMode=1; else md->weightMode=0 

#define MD_OFFSET(md) (u_gvarint_t(md->offset,md->offsetMode).word)
#define MD_OFFSET_TO_UNION(md, var) var.bytes_t.lo=md->offset; var.bytes_t.hi=md->offsetMode?255:0
#define MD_UNION_TO_OFFSET(var, md) md->offset=var.bytes_t.lo; if (var.word<0) md->offsetMode=1; else md->offsetMode=0 /* set negative sign */
// #define MD_SETOFFSET(md, val) md->offset=val; if (val<0) md->offsetMode=1; else md->offsetMode=0

#endif

enum LogicalSwitchesFunctions {
  LS_FUNC_NONE,
#if defined(CPUARM)
  LS_FUNC_VEQUAL, // v==offset
#endif
  LS_FUNC_VALMOSTEQUAL, // v~=offset
  LS_FUNC_VPOS,   // v>offset
  LS_FUNC_VNEG,   // v<offset
#if defined(CPUARM)
  LS_FUNC_RANGE,
#endif
  LS_FUNC_APOS,   // |v|>offset
  LS_FUNC_ANEG,   // |v|<offset
  LS_FUNC_AND,
  LS_FUNC_OR,
  LS_FUNC_XOR,
#if defined(CPUARM)
  LS_FUNC_STAY,
#endif
  LS_FUNC_EQUAL,
  LS_FUNC_GREATER,
  LS_FUNC_LESS,
  LS_FUNC_DIFFEGREATER,
  LS_FUNC_ADIFFEGREATER,
  LS_FUNC_TIMER,
  LS_FUNC_STICKY,
  LS_FUNC_COUNT,
  LS_FUNC_MAX = LS_FUNC_COUNT-1
};

#if defined(CPUARM)
#define MAX_LS_DURATION 250 /*25s*/
#define MAX_LS_DELAY    250 /*25s*/
#define MAX_LS_ANDSW    SWSRC_LAST
typedef int16_t ls_telemetry_value_t;
PACK(typedef struct t_LogicalSwitchData { // Logical Switches data
  int8_t  v1;
  int16_t v2;
  int16_t v3;
  uint8_t func;
  uint8_t delay;
  uint8_t duration;
  int8_t  andsw;
}) LogicalSwitchData;
#else
typedef uint8_t ls_telemetry_value_t;
#define MAX_LS_ANDSW    15
PACK(typedef struct t_LogicalSwitchData { // Logical Switches data
  int8_t  v1; //input
  int8_t  v2; //offset
  uint8_t func:4;
  uint8_t andsw:4;
}) LogicalSwitchData;
#endif

enum Functions {
  // first the functions which need a checkbox
  FUNC_OVERRIDE_CHANNEL,
  FUNC_TRAINER,
  FUNC_INSTANT_TRIM,
  FUNC_RESET,
#if defined(CPUARM)
  FUNC_SET_TIMER,
#endif
  FUNC_ADJUST_GVAR,
#if defined(CPUARM)
  FUNC_VOLUME,
  FUNC_RESERVE1,
  FUNC_RESERVE2,
  FUNC_RESERVE3,
#endif

  // then the other functions
  FUNC_FIRST_WITHOUT_ENABLE,
  FUNC_PLAY_SOUND = FUNC_FIRST_WITHOUT_ENABLE,
  FUNC_PLAY_TRACK,
#if !defined(CPUARM)
  FUNC_PLAY_BOTH,
#endif
  FUNC_PLAY_VALUE,
#if defined(CPUARM)
  FUNC_PLAY_DIFF,
  FUNC_PLAY_SCRIPT,
  FUNC_RESERVE5,
  FUNC_BACKGND_MUSIC,
  FUNC_BACKGND_MUSIC_PAUSE,
#endif
  FUNC_VARIO,
  FUNC_HAPTIC,
#if !defined(PCBSTD)
  FUNC_LOGS,
#endif
  FUNC_BACKLIGHT,
#if defined(DEBUG)
  FUNC_TEST, // should remain the last before MAX as not added in companion9x
#endif
  FUNC_MAX
};

#if defined(OVERRIDE_CHANNEL_FUNCTION)
  #define HAS_ENABLE_PARAM(func)    ((func) < FUNC_FIRST_WITHOUT_ENABLE)
#else
  #define HAS_ENABLE_PARAM(func)    ((func) < FUNC_FIRST_WITHOUT_ENABLE && (func) != FUNC_OVERRIDE_CHANNEL)
#endif

#if defined(VOICE)
  #define IS_PLAY_FUNC(func)      ((func) >= FUNC_PLAY_SOUND && func <= FUNC_PLAY_VALUE)
#else
  #define IS_PLAY_FUNC(func)      ((func) == FUNC_PLAY_SOUND)
#endif

#if defined(CPUARM)
  #define IS_PLAY_BOTH_FUNC(func) (0)
  #define IS_VOLUME_FUNC(func)    ((func) == FUNC_VOLUME)
#else
  #define IS_PLAY_BOTH_FUNC(func) ((func) == FUNC_PLAY_BOTH)
  #define IS_VOLUME_FUNC(func)    (0)
#endif

#if defined(GVARS)
  #define IS_ADJUST_GV_FUNC(func) ((func) == FUNC_ADJUST_GVAR)
#else
  #define IS_ADJUST_GV_FUNC(func) (0)
#endif

#if defined(HAPTIC)
  #define IS_HAPTIC_FUNC(func)    ((func) == FUNC_HAPTIC)
#else
  #define IS_HAPTIC_FUNC(func)    (0)
#endif

#define HAS_REPEAT_PARAM(func)    (IS_PLAY_FUNC(func) || IS_HAPTIC_FUNC(func))

enum ResetFunctionParam {
  FUNC_RESET_TIMER1,
  FUNC_RESET_TIMER2,
  FUNC_RESET_FLIGHT,
#if defined(FRSKY)
  FUNC_RESET_TELEMETRY,
#endif
#if ROTARY_ENCODERS > 0
  FUNC_RESET_ROTENC1,
#endif
#if ROTARY_ENCODERS > 1
  FUNC_RESET_ROTENC2,
#endif
  FUNC_RESET_PARAMS_COUNT,
  FUNC_RESET_PARAM_LAST = FUNC_RESET_PARAMS_COUNT-1
};

enum AdjustGvarFunctionParam {
  FUNC_ADJUST_GVAR_CONSTANT,
  FUNC_ADJUST_GVAR_SOURCE,
  FUNC_ADJUST_GVAR_GVAR,
  FUNC_ADJUST_GVAR_INC,
};

#if defined(CPUARM)
#if defined(PCBTARANIS)
  #define LEN_CFN_NAME 8
  #define CFN_SPARE_TYPE int32_t
#else
  #define LEN_CFN_NAME 6
  #define CFN_SPARE_TYPE int16_t
#endif
PACK(typedef struct t_CustomFnData { // Function Switches data
  int8_t  swtch;
  uint8_t func;
  PACK(union {
    PACK(struct {
      char name[LEN_CFN_NAME];
    }) play;

    PACK(struct {
      int16_t val;
      uint8_t mode;
      uint8_t param;
      CFN_SPARE_TYPE spare2;
    }) all;

    PACK(struct {
      int32_t val1;
      CFN_SPARE_TYPE val2;
    }) clear;
  });
  uint8_t active;
}) CustomFnData;
#define CFN_EMPTY(p)            (!(p)->swtch)
#define CFN_SWITCH(p)           ((p)->swtch)
#define CFN_FUNC(p)             ((p)->func)
#define CFN_ACTIVE(p)           ((p)->active)
#define CFN_CH_INDEX(p)         ((p)->all.param)
#define CFN_GVAR_INDEX(p)       ((p)->all.param)
#define CFN_TIMER_INDEX(p)      ((p)->all.param)
#define CFN_PLAY_REPEAT(p)      ((p)->active)
#define CFN_PLAY_REPEAT_MUL     1
#define CFN_PLAY_REPEAT_NOSTART 0xFF
#define CFN_GVAR_MODE(p)        ((p)->all.mode)
#define CFN_PARAM(p)            ((p)->all.val)
#define CFN_RESET(p)            ((p)->active=0, (p)->clear.val1=0, (p)->clear.val2=0)
#define CFN_GVAR_CST_MAX        GVAR_LIMIT
#else
PACK(typedef struct t_CustomFnData {
  PACK(union {
    PACK(struct {
      int16_t   swtch:6;
      uint16_t  func:4;
      uint16_t  mode:2;
      uint16_t  param:3;
      uint16_t  active:1;
    }) gvar;

    PACK(struct {
      int16_t   swtch:6;
      uint16_t  func:4;
      uint16_t  param:4;
      uint16_t  spare:1;
      uint16_t  active:1;
    }) all;
  });
  uint8_t value;
}) CustomFnData;
#define CFN_SWITCH(p)       ((p)->all.swtch)
#define CFN_FUNC(p)         ((p)->all.func)
#define CFN_ACTIVE(p)       ((p)->all.active)
#define CFN_CH_INDEX(p)     ((p)->all.param)
#define CFN_TIMER_INDEX(p)  ((p)->all.param)
#define CFN_GVAR_INDEX(p)   ((p)->gvar.param)
#define CFN_PLAY_REPEAT(p)  ((p)->all.param)
#define CFN_PLAY_REPEAT_MUL 10
#define CFN_GVAR_MODE(p)    ((p)->gvar.mode)
#define CFN_PARAM(p)        ((p)->value)
#define CFN_RESET(p)        ((p)->all.active = 0, CFN_PARAM(p) = 0)
#define CFN_GVAR_CST_MAX    125
#endif

enum TelemetryUnit {
  UNIT_VOLTS,
  UNIT_AMPS,
  UNIT_METERS_PER_SECOND,
  UNIT_RAW,
  UNIT_SPEED,
  UNIT_DIST,
  UNIT_TEMPERATURE,
  UNIT_PERCENT,
  UNIT_MILLIAMPS,
  UNIT_A1A2_MAX = UNIT_MILLIAMPS,
  UNIT_MAH,
  UNIT_WATTS,
  UNIT_DBM,
  UNIT_FEET,
  UNIT_KTS,
  UNIT_HOURS,
  UNIT_MINUTES,
  UNIT_SECONDS,
  UNIT_RPMS,
  UNIT_G,
  UNIT_HDG,
};

#if defined(CPUARM)
PACK(typedef struct {
  uint8_t   ratio;              // 0.0 means not used, 0.1V steps EG. 6.6 Volts = 66. 25.1V = 251, etc.
  int16_t   offset:12;
  uint16_t  type:4;             // channel unit (0=volts, ...)
  uint8_t   alarms_value[2];    // 0.1V steps EG. 6.6 Volts = 66. 25.1V = 251, etc.
  uint8_t   alarms_level:4;
  uint8_t   alarms_greater:2;   // 0=LT(<), 1=GT(>)
  uint8_t   spare:2;
  uint8_t   multiplier;         // 0=no multiplier, 1=*2 multiplier
}) FrSkyChannelData;
#else
PACK(typedef struct {
  uint8_t   ratio;              // 0.0 means not used, 0.1V steps EG. 6.6 Volts = 66. 25.1V = 251, etc.
  int16_t   offset:12;
  uint16_t  type:4;             // channel unit (0=volts, ...)
  uint8_t   alarms_value[2];    // 0.1V steps EG. 6.6 Volts = 66. 25.1V = 251, etc. 
  uint8_t   alarms_level:4;
  uint8_t   alarms_greater:2;   // 0=LT(<), 1=GT(>)
  uint8_t   multiplier:2;       // 0=no multiplier, 1=*2 multiplier
}) FrSkyChannelData;
#endif

enum TelemetrySource {
  TELEM_NONE,
  TELEM_TX_VOLTAGE,               LUA_EXPORT_TELEMETRY("tx-voltage", "Transmitter battery voltage [volts]")
#if defined(CPUARM)
  TELEM_TX_TIME,                  LUA_EXPORT_TELEMETRY("clock", "RTC clock [minutes from midnight]")
  TELEM_RESERVE1,
  TELEM_RESERVE2,
  TELEM_RESERVE3,
  TELEM_RESERVE4,
  TELEM_RESERVE5,
#endif
  TELEM_TIMER1,                   LUA_EXPORT_TELEMETRY("timer1", "Timer 1 value [seconds]")
  TELEM_TIMER2,                   LUA_EXPORT_TELEMETRY("timer2", "Timer 2 value [seconds]")
#if defined(CPUARM)       
  TELEM_SWR,                      LUA_EXPORT_TELEMETRY("swr", "Transmitter antenna quality [less is better]")
#endif        
  TELEM_RSSI_TX,        
  TELEM_RSSI_RX,                  LUA_EXPORT_TELEMETRY("rssi", "RSSI [more is better]")
#if defined(CPUARM)       
  TELEM_RESERVE0,       
#endif        
  TELEM_A_FIRST,        
  TELEM_A1=TELEM_A_FIRST,         LUA_EXPORT_TELEMETRY("a1", "A1 analogue value [units as configured]")
  TELEM_A2,                       LUA_EXPORT_TELEMETRY("a2", "A2 analogue value [units as configured]")
#if !defined(CPUARM)        
  TELEM_A_LAST=TELEM_A2,        
#else       
  TELEM_A3,                       LUA_EXPORT_TELEMETRY("a3", "A3 analogue value [units as configured]")
  TELEM_A4,                       LUA_EXPORT_TELEMETRY("a4", "A4 analogue value [units as configured]")
  TELEM_A_LAST=TELEM_A4,        
#endif        
  TELEM_ALT,                      LUA_EXPORT_TELEMETRY("altitude", "Variometer altitude [meters]")
  TELEM_RPM,                      LUA_EXPORT_TELEMETRY("rpm", "Rotational speed [revolutions per minute]")
  TELEM_FUEL,                     LUA_EXPORT_TELEMETRY("fuel", "Fuel level [percent]")
  TELEM_T1,                       LUA_EXPORT_TELEMETRY("temp1", "Temperature 1 [degrees celsius]")
  TELEM_T2,                       LUA_EXPORT_TELEMETRY("temp2", "Temperature 2 [degrees celsius]")
  TELEM_SPEED,                    LUA_EXPORT_TELEMETRY("gps-speed", "GPS speed [knots]")
  TELEM_DIST,                     LUA_EXPORT_TELEMETRY("distance", "GPS distance [meters]")
  TELEM_GPSALT,                   LUA_EXPORT_TELEMETRY("gps-altitude", "GPS altitude [meters]")
  TELEM_CELL,                     LUA_EXPORT_TELEMETRY("cell-min", "LiPo sensor - lowest current cell voltage [volts]")
  TELEM_CELLS_SUM,                LUA_EXPORT_TELEMETRY("cell-sum", "LiPo sensor - current summ of all cell voltages [volts]")
  TELEM_VFAS,                     LUA_EXPORT_TELEMETRY("vfas", "Current sensor - voltage [volts]")
  TELEM_CURRENT,                  LUA_EXPORT_TELEMETRY("current", "Current sensor - current [ampers]")
  TELEM_CONSUMPTION,              LUA_EXPORT_TELEMETRY("consumption", "Current sensor - consumption [mili amper hours]")
  TELEM_POWER,                    LUA_EXPORT_TELEMETRY("power", "Current sensor - power [wats]")
  TELEM_ACCx,                     LUA_EXPORT_TELEMETRY("accx", "G sensor - acceleration in X axis [g]")
  TELEM_ACCy,                     LUA_EXPORT_TELEMETRY("accy", "G sensor - acceleration in Y axis [g]")
  TELEM_ACCz,                     LUA_EXPORT_TELEMETRY("accz", "G sensor - acceleration in Z axis [g]")
  TELEM_HDG,                      LUA_EXPORT_TELEMETRY("heading", "GPS heading [degrees]")
  TELEM_VSPEED,                   LUA_EXPORT_TELEMETRY("vertical-speed", "Variometer vertical speed [m/s]")
  TELEM_ASPEED,                   LUA_EXPORT_TELEMETRY("air-speed", "Air speed [knots]")
  TELEM_DTE,                      LUA_EXPORT_TELEMETRY("dte", "Total energy [???]")
#if defined(CPUARM)
  TELEM_RESERVE6,
  TELEM_RESERVE7,
  TELEM_RESERVE8,
  TELEM_RESERVE9,
  TELEM_RESERVE10,
#endif
  TELEM_MIN_A_FIRST,
  TELEM_MIN_A1=TELEM_MIN_A_FIRST, LUA_EXPORT_TELEMETRY("a1-min", "A1 analogue value minimum [units as configured]")
  TELEM_MIN_A2,                   LUA_EXPORT_TELEMETRY("a2-min", "A2 analogue value minimum [units as configured]")
#if !defined(CPUARM)
  TELEM_MIN_A_LAST=TELEM_MIN_A2,
#else
  TELEM_MIN_A3,                   LUA_EXPORT_TELEMETRY("a3-min", "A3 analogue value minimum [units as configured]")
  TELEM_MIN_A4,                   LUA_EXPORT_TELEMETRY("a4-min", "A4 analogue value minimum [units as configured]")
  TELEM_MIN_A_LAST=TELEM_MIN_A4,
#endif
  // TODO: add A1-4 MAX
  TELEM_MIN_ALT,                  LUA_EXPORT_TELEMETRY("altitude-min", "Lowest altitude [meters]")
  TELEM_MAX_ALT,                  LUA_EXPORT_TELEMETRY("altitude-max", "Highest altitude [meters]")
  TELEM_MAX_RPM,                  LUA_EXPORT_TELEMETRY("rpm-max", "Highest rotational speed [revolutions per minute] [meters]")
  TELEM_MAX_T1,                   LUA_EXPORT_TELEMETRY("temp1-max", "Highest temperature 1 [degrees celsius]")
  TELEM_MAX_T2,                   LUA_EXPORT_TELEMETRY("temp2-max", "Highest temperature 2 [degrees celsius]")
  TELEM_MAX_SPEED,                LUA_EXPORT_TELEMETRY("gps-speed-max", "Highest GPS speed [knots]")
  TELEM_MAX_DIST,                 LUA_EXPORT_TELEMETRY("distance-max", "Biggest GPS distance [meters]")
  TELEM_MAX_ASPEED,               LUA_EXPORT_TELEMETRY("air-speed-max", "Highest air speed [knots]")
  TELEM_MIN_CELL,                 LUA_EXPORT_TELEMETRY("cell-min-min", "LiPo sensor - all time lowest cell voltage [volts]")
  TELEM_MIN_CELLS_SUM,            LUA_EXPORT_TELEMETRY("cell-sum-min", "LiPo sensor - all time lowest summ of all cell voltages [volts]")
  TELEM_MIN_VFAS,                 LUA_EXPORT_TELEMETRY("vfas-min", "Current sensor - lowest voltage [volts]")
  TELEM_MAX_CURRENT,              LUA_EXPORT_TELEMETRY("current-max", "Current sensor - highest current [ampers]")
  TELEM_MAX_POWER,                LUA_EXPORT_TELEMETRY("power-max", "Current sensor - highest power [wats]")
#if defined(CPUARM)
  TELEM_RESERVE11,
  TELEM_RESERVE12,
  TELEM_RESERVE13,
  TELEM_RESERVE14,
  TELEM_RESERVE15,
#endif
  TELEM_ACC,
  TELEM_GPS_TIME,
  TELEM_CSW_MAX = TELEM_MAX_POWER,
  TELEM_NOUSR_MAX = TELEM_A2,
#if defined(FRSKY)
  TELEM_DISPLAY_MAX = TELEM_MAX_POWER,
#else
  TELEM_DISPLAY_MAX = TELEM_TIMER2, // because used also in PlayValue
#endif
  TELEM_STATUS_MAX = TELEM_GPS_TIME,
  TELEM_FIRST_STREAMED_VALUE = TELEM_RSSI_TX,
};

enum VarioSource {
#if !defined(FRSKY_SPORT)
  VARIO_SOURCE_ALTI,
  VARIO_SOURCE_ALTI_PLUS,
#endif
  VARIO_SOURCE_VSPEED,
  VARIO_SOURCE_A1,
  VARIO_SOURCE_A2,
#if defined(FRSKY_SPORT)
  VARIO_SOURCE_DTE,
#endif
  VARIO_SOURCE_COUNT,
  VARIO_SOURCE_LAST = VARIO_SOURCE_COUNT-1
};

#if defined(FRSKY_HUB)
  #define NUM_TELEMETRY      TELEM_CSW_MAX
#elif defined(WS_HOW_HIGH)
  #define NUM_TELEMETRY      TELEM_ALT
#elif defined(FRSKY)
  #define NUM_TELEMETRY      TELEM_A2
#elif defined(MAVLINK)
  #define NUM_TELEMETRY      4
#else
  #define NUM_TELEMETRY      TELEM_TIMER2
#endif

PACK(typedef struct t_FrSkyBarData {
  uint8_t    source;
  uint8_t    barMin;           // minimum for bar display
  uint8_t    barMax;           // ditto for max display (would usually = ratio)
}) FrSkyBarData;

#if defined(PCBTARANIS)
  #define NUM_LINE_ITEMS 3
#else
  #define NUM_LINE_ITEMS 2
#endif
PACK(typedef struct t_FrSkyLineData {
  uint8_t    sources[NUM_LINE_ITEMS];
}) FrSkyLineData;

typedef union t_FrSkyScreenData {
  FrSkyBarData  bars[4];
  FrSkyLineData lines[4];
} FrSkyScreenData;

enum FrskyUsrProtocols {
  USR_PROTO_NONE,
  USR_PROTO_FRSKY,
  USR_PROTO_WS_HOW_HIGH,
  USR_PROTO_LAST = USR_PROTO_WS_HOW_HIGH,
};

enum FrskyCurrentSource {
  FRSKY_CURRENT_SOURCE_NONE,
  FRSKY_CURRENT_SOURCE_A1,
  FRSKY_CURRENT_SOURCE_A2,
#if defined(CPUARM)
  FRSKY_CURRENT_SOURCE_A3,
  FRSKY_CURRENT_SOURCE_A4,
#endif
  FRSKY_CURRENT_SOURCE_FAS,
  FRSKY_CURRENT_SOURCE_LAST=FRSKY_CURRENT_SOURCE_FAS
};

enum FrskyVoltsSource {
  FRSKY_VOLTS_SOURCE_A1,
  FRSKY_VOLTS_SOURCE_A2,
#if defined(CPUARM)
  FRSKY_VOLTS_SOURCE_A3,
  FRSKY_VOLTS_SOURCE_A4,
#endif
  FRSKY_VOLTS_SOURCE_FAS,
  FRSKY_VOLTS_SOURCE_CELLS,
  FRSKY_VOLTS_SOURCE_LAST=FRSKY_VOLTS_SOURCE_CELLS
};

#if defined(CPUARM)
#define MAX_FRSKY_A_CHANNELS 4
#define MAX_FRSKY_SCREENS 3
PACK(typedef struct t_FrSkyData {
  FrSkyChannelData channels[MAX_FRSKY_A_CHANNELS];
  uint8_t usrProto; // Protocol in FrSky user data, 0=None, 1=FrSky hub, 2=WS HowHigh, 3=Halcyon
  uint8_t voltsSource:7;
  uint8_t altitudeDisplayed:1;
  int8_t blades;    // How many blades for RPMs, 0=2 blades
  uint8_t currentSource;
  uint8_t screensType;
  FrSkyScreenData screens[MAX_FRSKY_SCREENS];
  uint8_t varioSource;
  int8_t  varioCenterMax;
  int8_t  varioCenterMin;
  int8_t  varioMin;
  int8_t  varioMax;
  FrSkyRSSIAlarm rssiAlarms[2];
  uint16_t mAhPersistent:1;
  uint16_t storedMah:15;
  int8_t   fasOffset;
}) FrSkyData;
#define MIN_BLADES -1   // 1 blade
#define MAX_BLADES 126  // 128 blades
#else
#define MAX_FRSKY_A_CHANNELS 2
#define MAX_FRSKY_SCREENS 2
PACK(typedef struct t_FrSkyData {
  FrSkyChannelData channels[MAX_FRSKY_A_CHANNELS];
  uint8_t usrProto:2; // Protocol in FrSky user data, 0=None, 1=FrSky hub, 2=WS HowHigh, 3=Halcyon
  uint8_t blades:2;   // How many blades for RPMs, 0=2 blades
  uint8_t screensType:2;
  uint8_t voltsSource:2;
  int8_t  varioMin:4;
  int8_t  varioMax:4;
  FrSkyRSSIAlarm rssiAlarms[2];
  FrSkyScreenData screens[MAX_FRSKY_SCREENS];
  uint8_t varioSource:3;
  int8_t  varioCenterMin:5;
  uint8_t currentSource:3;
  int8_t  varioCenterMax:5;
  int8_t  fasOffset;
}) FrSkyData;
#define MIN_BLADES 0 // 2 blades
#define MAX_BLADES 3 // 5 blades
#endif

#if defined(MAVLINK)
PACK(typedef struct t_MavlinkData {
  uint8_t rc_rssi_scale:4;
  uint8_t pc_rssi_en:1;
  uint8_t spare1:3;
  uint8_t spare2[3];
}) MavlinkData;
#endif

enum SwashType {
  SWASH_TYPE_NONE,
  SWASH_TYPE_120,
  SWASH_TYPE_120X,
  SWASH_TYPE_140,
  SWASH_TYPE_90,
  SWASH_TYPE_MAX = SWASH_TYPE_90
};

PACK(typedef struct t_SwashRingData { // Swash Ring data
  uint8_t   invertELE:1;
  uint8_t   invertAIL:1;
  uint8_t   invertCOL:1;
  uint8_t   type:5;  
  uint8_t   collectiveSource;
  uint8_t   value;
}) SwashRingData;

#define TRIM_EXTENDED_MAX 500
#define TRIM_EXTENDED_MIN (-TRIM_EXTENDED_MAX)
#define TRIM_MAX 125
#define TRIM_MIN (-TRIM_MAX)

#define ROTARY_ENCODER_MAX  1024

#if defined(PCBTARANIS) || defined(REVX)
  #define NUM_ROTARY_ENCODERS 0
  #define ROTARY_ENCODER_ARRAY int16_t rotaryEncoders[1];
#elif defined(PCBSKY9X)
  #define NUM_ROTARY_ENCODERS 1
  #define ROTARY_ENCODER_ARRAY int16_t rotaryEncoders[1];
#elif defined(CPUM2560)
  #define NUM_ROTARY_ENCODERS 2
  #define ROTARY_ENCODER_ARRAY int16_t rotaryEncoders[2];
#else
  #define NUM_ROTARY_ENCODERS 0
  #define ROTARY_ENCODER_ARRAY
#endif

#if defined(PCBSTD)
  #define TRIMS_ARRAY       int8_t trim[4]; int8_t trim_ext:8
  #define TRIMS_ARRAY_SIZE  5
  #define trim_t            int16_t
#else
  #if defined(PCBTARANIS)
    PACK(typedef struct {
      int16_t  value:11;
      uint16_t mode:5;
    }) trim_t;
    #define TRIM_MODE_NONE  0x1F  // 0b11111
  #else
    #define trim_t          int16_t
  #endif
  #define TRIMS_ARRAY       trim_t trim[4]
  #define TRIMS_ARRAY_SIZE  8
#endif

#if defined(CPUARM)
PACK(typedef struct t_FlightModeData {
  TRIMS_ARRAY;
  int8_t swtch;       // swtch of phase[0] is not used
  char name[LEN_FP_NAME];
  uint8_t fadeIn;
  uint8_t fadeOut;
  ROTARY_ENCODER_ARRAY;
  PHASE_GVARS_DATA;
}) FlightModeData;
#else
PACK(typedef struct t_FlightModeData {
  TRIMS_ARRAY;
  int8_t swtch;       // swtch of phase[0] is not used
  char name[LEN_FP_NAME];
  uint8_t fadeIn:4;
  uint8_t fadeOut:4;
  ROTARY_ENCODER_ARRAY;
  PHASE_GVARS_DATA;
}) FlightModeData;
#endif

enum SwitchSources {
  SWSRC_NONE = 0,

  SWSRC_FIRST_SWITCH,

#if defined(PCBTARANIS)
  SWSRC_SA0 = SWSRC_FIRST_SWITCH,
  SWSRC_SA1,
  SWSRC_SA2,
  SWSRC_SB0,
  SWSRC_SB1,
  SWSRC_SB2,
  SWSRC_SC0,
  SWSRC_SC1,
  SWSRC_SC2,
  SWSRC_SD0,
  SWSRC_SD1,
  SWSRC_SD2,
  SWSRC_SE0,
  SWSRC_SE1,
  SWSRC_SE2,
  SWSRC_SF0,
  SWSRC_SF2,
  SWSRC_SG0,
  SWSRC_SG1,
  SWSRC_SG2,
  SWSRC_SH0,
  SWSRC_SH2,
  SWSRC_TRAINER = SWSRC_SH2,
#else
  SWSRC_ID0 = SWSRC_FIRST_SWITCH,
  SWSRC_ID1,
  SWSRC_ID2,
#if defined(EXTRA_3POS)
  SWSRC_ID3,
  SWSRC_ID4,
  SWSRC_ID5,
#endif
  SWSRC_THR,
  SWSRC_RUD,
  SWSRC_ELE,
  SWSRC_AIL,
  SWSRC_GEA,
  SWSRC_TRN,
  SWSRC_TRAINER = SWSRC_TRN,
#endif

  SWSRC_LAST_SWITCH = SWSRC_TRAINER,

#if defined(PCBTARANIS)
  SWSRC_FIRST_MULTIPOS_SWITCH,
  SWSRC_LAST_MULTIPOS_SWITCH = SWSRC_FIRST_MULTIPOS_SWITCH + (NUM_XPOTS*XPOTS_MULTIPOS_COUNT) - 1,
#endif

  SWSRC_FIRST_TRIM,
  SWSRC_TrimRudLeft = SWSRC_FIRST_TRIM,
  SWSRC_TrimRudRight,
  SWSRC_TrimEleDown,
  SWSRC_TrimEleUp,
  SWSRC_TrimThrDown,
  SWSRC_TrimThrUp,
  SWSRC_TrimAilLeft,
  SWSRC_TrimAilRight,
  SWSRC_LAST_TRIM = SWSRC_TrimAilRight,

#if defined(PCBSKY9X)
  SWSRC_REa,
#elif defined(PCBGRUVIN9X) || defined(PCBMEGA2560)
  SWSRC_REa,
  SWSRC_REb,
#endif

  SWSRC_FIRST_LOGICAL_SWITCH,
  SWSRC_SW1 = SWSRC_FIRST_LOGICAL_SWITCH,
  SWSRC_SW2,
  SWSRC_SW3,
  SWSRC_SW4,
  SWSRC_SW5,
  SWSRC_SW6,
  SWSRC_SW7,
  SWSRC_SW8,
  SWSRC_SW9,
  SWSRC_SWA,
  SWSRC_SWB,
  SWSRC_SWC,
  SWSRC_LAST_LOGICAL_SWITCH = SWSRC_FIRST_LOGICAL_SWITCH+NUM_LOGICAL_SWITCH-1,

  SWSRC_ON,
  SWSRC_One,

#if defined(CPUARM)
  SWSRC_FIRST_FLIGHT_MODE,
  SWSRC_LAST_FLIGHT_MODE = SWSRC_FIRST_FLIGHT_MODE+MAX_FLIGHT_MODES-1,
#endif

  SWSRC_COUNT,

  SWSRC_OFF = -SWSRC_ON,

  SWSRC_LAST = SWSRC_COUNT-1,
  SWSRC_FIRST = -SWSRC_LAST,

#if defined(CPUARM)
  SWSRC_LAST_IN_LOGICAL_SWITCHES = SWSRC_LAST_FLIGHT_MODE,
  SWSRC_LAST_IN_MIXES = SWSRC_LAST_FLIGHT_MODE,
#else
  SWSRC_LAST_IN_LOGICAL_SWITCHES = SWSRC_LAST_LOGICAL_SWITCH,
  SWSRC_LAST_IN_MIXES = SWSRC_LAST_LOGICAL_SWITCH,
#endif
  SWSRC_FIRST_IN_LOGICAL_SWITCHES = -SWSRC_LAST_IN_LOGICAL_SWITCHES,
  SWSRC_FIRST_IN_MIXES = -SWSRC_LAST_IN_MIXES,
};

enum MixSources {
  MIXSRC_NONE,

#if defined(PCBTARANIS)
  MIXSRC_FIRST_INPUT,             LUA_EXPORT_MULTIPLE("input", "Input [I%d]", MAX_INPUTS)
  MIXSRC_LAST_INPUT = MIXSRC_FIRST_INPUT+MAX_INPUTS-1,

  MIXSRC_FIRST_LUA,
  MIXSRC_LAST_LUA = MIXSRC_FIRST_LUA+(MAX_SCRIPTS*MAX_SCRIPT_OUTPUTS)-1,
#endif

  MIXSRC_Rud,                     LUA_EXPORT("rud", "Rudder")
  MIXSRC_Ele,                     LUA_EXPORT("ele", "Elevator")
  MIXSRC_Thr,                     LUA_EXPORT("thr", "Throttle")
  MIXSRC_Ail,                     LUA_EXPORT("ail", "Aileron")

  MIXSRC_FIRST_POT,
#if defined(PCBTARANIS)
  MIXSRC_POT1 = MIXSRC_FIRST_POT, LUA_EXPORT("s1", "Potentiometer 1")
  MIXSRC_POT2,                    LUA_EXPORT("s2", "Potentiometer 2")
  MIXSRC_POT3,                    LUA_EXPORT("s3", "Potentiometer 3")
  MIXSRC_SLIDER1,                 LUA_EXPORT("ls", "Left slider")
  MIXSRC_SLIDER2,                 LUA_EXPORT("rs", "Right slider")
  MIXSRC_LAST_POT = MIXSRC_SLIDER2,
#else
  MIXSRC_P1 = MIXSRC_FIRST_POT,
  MIXSRC_P2,
  #if defined(EXTRA_3POS)
    MIXSRC_LAST_POT = MIXSRC_P2,
  #else
    MIXSRC_P3,
    MIXSRC_LAST_POT = MIXSRC_P3,
  #endif
#endif

#if defined(PCBSKY9X)
  MIXSRC_REa,
  MIXSRC_LAST_ROTARY_ENCODER = MIXSRC_REa,
#elif defined(PCBGRUVIN9X) || defined(PCBMEGA2560)
  MIXSRC_REa,
  MIXSRC_REb,
  #if ROTARY_ENCODERS > 2
    MIXSRC_REc,
    MIXSRC_REd,
    MIXSRC_LAST_ROTARY_ENCODER = MIXSRC_REd,
  #else
    MIXSRC_LAST_ROTARY_ENCODER = MIXSRC_REb,
  #endif
#endif

  MIXSRC_MAX,

  MIXSRC_CYC1,                  LUA_EXPORT("cyc1", "Cyclic 1")
  MIXSRC_CYC2,                  LUA_EXPORT("cyc2", "Cyclic 2")
  MIXSRC_CYC3,                  LUA_EXPORT("cyc3", "Cyclic 3")

  MIXSRC_TrimRud,               LUA_EXPORT("trim-rud", "Rudder trim")
  MIXSRC_TrimEle,               LUA_EXPORT("trim-ele", "Elevator trim")
  MIXSRC_TrimThr,               LUA_EXPORT("trim-thr", "Throttle trim")
  MIXSRC_TrimAil,               LUA_EXPORT("trim-ail", "Aileron trim")

  MIXSRC_FIRST_SWITCH,

#if defined(PCBTARANIS)
  MIXSRC_SA = MIXSRC_FIRST_SWITCH,  LUA_EXPORT("sa", "Switch A")
  MIXSRC_SB,                        LUA_EXPORT("sb", "Switch B")
  MIXSRC_SC,                        LUA_EXPORT("sc", "Switch C")
  MIXSRC_SD,                        LUA_EXPORT("sd", "Switch D")
  MIXSRC_SE,                        LUA_EXPORT("se", "Switch E")
  MIXSRC_SF,                        LUA_EXPORT("sf", "Switch F")
  MIXSRC_SG,                        LUA_EXPORT("sg", "Switch G")
  MIXSRC_SH,                        LUA_EXPORT("sh", "Switch H")
#else
  MIXSRC_3POS = MIXSRC_FIRST_SWITCH,
  #if defined(EXTRA_3POS)
    MIXSRC_3POS2,
  #endif
  MIXSRC_THR,
  MIXSRC_RUD,
  MIXSRC_ELE,
  MIXSRC_AIL,
  MIXSRC_GEA,
  MIXSRC_TRN,
#endif
  MIXSRC_FIRST_LOGICAL_SWITCH,
  MIXSRC_SW1 = MIXSRC_FIRST_LOGICAL_SWITCH, LUA_EXPORT_MULTIPLE("ls", "Logical switch L%d", NUM_LOGICAL_SWITCH)
  MIXSRC_SW9 = MIXSRC_SW1 + 8,
  MIXSRC_SWA,
  MIXSRC_SWB,
  MIXSRC_SWC,
  MIXSRC_LAST_LOGICAL_SWITCH = MIXSRC_FIRST_LOGICAL_SWITCH+NUM_LOGICAL_SWITCH-1,

  MIXSRC_FIRST_TRAINER,                     LUA_EXPORT_MULTIPLE("trn", "Trainer input %d", NUM_TRAINER)
  MIXSRC_LAST_TRAINER = MIXSRC_FIRST_TRAINER+NUM_TRAINER-1,

  MIXSRC_FIRST_CH,
  MIXSRC_CH1 = MIXSRC_FIRST_CH,             LUA_EXPORT_MULTIPLE("ch", "Channel CH%d", NUM_CHNOUT)
  MIXSRC_CH2,
  MIXSRC_CH3,
  MIXSRC_CH4,
  MIXSRC_CH5,
  MIXSRC_CH6,
  MIXSRC_CH7,
  MIXSRC_CH8,
  MIXSRC_CH9,
  MIXSRC_CH10,
  MIXSRC_CH11,
  MIXSRC_CH12,
  MIXSRC_CH13,
  MIXSRC_CH14,
  MIXSRC_CH15,
  MIXSRC_CH16,
  MIXSRC_LAST_CH = MIXSRC_CH1+NUM_CHNOUT-1,

  MIXSRC_GVAR1,                             LUA_EXPORT_MULTIPLE("gvar", "Global variable %d", MAX_GVARS)
  MIXSRC_LAST_GVAR = MIXSRC_GVAR1+MAX_GVARS-1,

  MIXSRC_FIRST_TELEM,
  MIXSRC_LAST_TELEM = MIXSRC_FIRST_TELEM+NUM_TELEMETRY-1
};

#if defined(LUA)
#define EXTRA_FIRST 1000
enum LuaExtraFields {
  EXTRA_LATITUDE = EXTRA_FIRST, LUA_EXPORT_EXTRA("latitude", "GPS latitude [degrees, North is positive]", \
                                                 "gpsToDouble(frskyData.hub.gpsLatitudeNS=='S', frskyData.hub.gpsLatitude_bp, frskyData.hub.gpsLatitude_ap)", \
                                                 "frskyData.hub.gpsFix")
  EXTRA_LONGITUDE,              LUA_EXPORT_EXTRA("longitude", "GPS longitude [degrees, East is positive]", \
                                                 "gpsToDouble(frskyData.hub.gpsLongitudeEW=='W', frskyData.hub.gpsLongitude_bp, frskyData.hub.gpsLongitude_ap)", \
                                                 "frskyData.hub.gpsFix")
  EXTRA_PILOT_LATITUDE,         LUA_EXPORT_EXTRA("pilot-latitude", "Latitude of frist GPS position [degrees, North is positive]", \
                                                 "pilotLatitude", "frskyData.hub.gpsFix")
  EXTRA_PILOT_LONGITUDE,        LUA_EXPORT_EXTRA("pilot-longitude", "Longitude of frist GPS position [degrees, East is positive]", \
                                                 "pilotLongitude", "frskyData.hub.gpsFix")
  EXTRA_GPS_CLOCK,              LUA_EXPORT_EXTRA("gps-clock", "GPS clock [seconds from midnight]", \
                                                 "(int)(frskyData.hub.hour)*3600 + frskyData.hub.min*60 + frskyData.hub.sec", "frskyData.hub.gpsFix")
  EXTRA_FLIGHT_MODE             LUA_EXPORT_EXTRA("flight-mode", "Current flight mode number [number]", \
                                                 "getFlightMode()", "true")     
};
#endif // #if defined(LUA)

#define MIXSRC_FIRST   (MIXSRC_NONE+1)
#define MIXSRC_LAST    MIXSRC_LAST_CH
#define INPUTSRC_FIRST MIXSRC_Rud
#define INPUTSRC_LAST  MIXSRC_LAST_TELEM

#define MIN_POINTS 3
#define MAX_POINTS 17

enum TimerModes {
  TMRMODE_NONE,
  TMRMODE_ABS,
  TMRMODE_THR,
  TMRMODE_THR_REL,
  TMRMODE_THR_TRG,
  TMRMODE_COUNT
};

enum CountDownModes {
  COUNTDOWN_SILENT,
  COUNTDOWN_BEEPS,
  COUNTDOWN_VOICE
};

#if defined(CPUARM) || defined(CPUM2560)
PACK(typedef struct t_TimerData {
  int8_t   mode;            // timer trigger source -> off, abs, stk, stk%, sw/!sw, !m_sw/!m_sw
  uint16_t start;
  uint8_t  countdownBeep:2;
  uint8_t  minuteBeep:1;
  uint8_t  persistent:2;
  uint8_t  spare:3;
  uint16_t value;
}) TimerData;
#define IS_MANUAL_RESET_TIMER(idx) (g_model.timers[idx].persistent == 2)
#else
PACK(typedef struct t_TimerData {
  int8_t    mode;            // timer trigger source -> off, abs, stk, stk%, sw/!sw, !m_sw/!m_sw
  uint16_t  start:12;
  uint16_t  countdownBeep:1;
  uint16_t  minuteBeep:1;
  uint16_t  spare:2;
}) TimerData;
#define IS_MANUAL_RESET_TIMER(idx) 0
#endif

enum Protocols {
  PROTO_PPM,
#if !defined(CPUARM)
  PROTO_PPM16,
  PROTO_PPMSIM,
#endif
#if defined(PXX) || defined(DSM2) || defined(IRPROTOS)
  PROTO_PXX,
#endif
#if defined(DSM2) || defined(IRPROTOS)
  PROTO_DSM2_LP45,
  PROTO_DSM2_DSM2,
  PROTO_DSM2_DSMX,
#endif
#if defined(IRPROTOS)
  // we will need 4 bytes for proto :(
  PROTO_SILV,
  PROTO_TRAC09,
  PROTO_PICZ,
  PROTO_SWIFT,
#endif
  PROTO_MAX,
  PROTO_NONE
};

enum RFProtocols {
  RF_PROTO_OFF = -1,
  RF_PROTO_X16,
  RF_PROTO_D8,
  RF_PROTO_LR12,
  RF_PROTO_LAST = RF_PROTO_LR12
};

enum DSM2Protocols {
  DSM2_PROTO_LP45,
  DSM2_PROTO_DSM2,
  DSM2_PROTO_DSMX,
};

enum ModuleTypes {
  MODULE_TYPE_NONE = 0,
  MODULE_TYPE_PPM,
  MODULE_TYPE_XJT,
#if defined(DSM2)
  MODULE_TYPE_DSM2,
#endif
  MODULE_TYPE_COUNT
};

enum FailsafeModes {
  FAILSAFE_HOLD,
  FAILSAFE_CUSTOM,
  FAILSAFE_NOPULSES,
  FAILSAFE_RECEIVER,
  FAILSAFE_LAST = FAILSAFE_RECEIVER
};

#if defined(FRSKY)
  #define TELEMETRY_DATA FrSkyData frsky;
#elif defined(MAVLINK)
  #define TELEMETRY_DATA MavlinkData mavlink;
#else
  #define TELEMETRY_DATA
#endif

#if defined(CPUARM) || defined(PCBGRUVIN9X) || defined(PCBMEGA2560)
  #define BeepANACenter uint16_t
#else
  #define BeepANACenter uint8_t
#endif

PACK(typedef struct {
  char      name[LEN_MODEL_NAME]; // must be first for eeLoadModelName
  uint8_t   modelId;
  MODELDATA_BITMAP
}) ModelHeader;

enum ThrottleSources {
  THROTTLE_SOURCE_THR,
#if defined(PCBTARANIS)
  THROTTLE_SOURCE_S1,
  THROTTLE_SOURCE_S2,
  THROTTLE_SOURCE_S3,
  THROTTLE_SOURCE_LS,
  THROTTLE_SOURCE_RS,
#else
  THROTTLE_SOURCE_P1,
  THROTTLE_SOURCE_P2,
  THROTTLE_SOURCE_P3,
#endif
  THROTTLE_SOURCE_CH1,
};

enum TelemetryProtocol
{
  PROTOCOL_TELEMETRY_FIRST,
  PROTOCOL_FRSKY_SPORT = PROTOCOL_TELEMETRY_FIRST,
  PROTOCOL_FRSKY_D,
  PROTOCOL_FRSKY_D_SECONDARY
};

PACK(typedef struct t_ModelData {
  ModelHeader header;
  TimerData timers[MAX_TIMERS];
  AVR_FIELD(uint8_t   protocol:3)
  ARM_FIELD(uint8_t   telemetryProtocol:3)
  uint8_t   thrTrim:1;            // Enable Throttle Trim
  AVR_FIELD(int8_t    ppmNCH:4)
  ARM_FIELD(int8_t    spare2:4)
  int8_t    trimInc:3;            // Trim Increments
  uint8_t   disableThrottleWarning:1;
  ARM_FIELD(uint8_t displayChecklist:1)
  AVR_FIELD(uint8_t pulsePol:1)
  uint8_t   extendedLimits:1;
  uint8_t   extendedTrims:1;
  uint8_t   throttleReversed:1;
  AVR_FIELD(int8_t ppmDelay)
  BeepANACenter beepANACenter;        // 1<<0->A1.. 1<<6->A7
  MixData   mixData[MAX_MIXERS];
  LimitData limitData[NUM_CHNOUT];
  ExpoData  expoData[MAX_EXPOS];
  
  CURVDATA  curves[MAX_CURVES];
  int8_t    points[NUM_POINTS];
  
  LogicalSwitchData logicalSw[NUM_LOGICAL_SWITCH];
  CustomFnData funcSw[NUM_CFN];
  SwashRingData swashR;
  FlightModeData flightModeData[MAX_FLIGHT_MODES];

  AVR_FIELD(int8_t ppmFrameLength)     // 0=22.5ms  (10ms-30ms) 0.5ms increments
  uint8_t   thrTraceSrc;
  
  swstate_t switchWarningStates;
  uint8_t nSwToWarn;

  MODEL_GVARS_DATA

  TELEMETRY_DATA

  MODELDATA_EXTRA

}) ModelData;

extern EEGeneral g_eeGeneral;
extern ModelData g_model;

#define TOTAL_EEPROM_USAGE (sizeof(ModelData)*MAX_MODELS + sizeof(EEGeneral))

#endif
/*eof*/
