/*
 * Author - Bertrand Songis <bsongis@gmail.com>
 * 
 * Based on th9x -> http://code.google.com/p/th9x/
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

#ifndef eeprom_interface_h
#define eeprom_interface_h

#include <inttypes.h>
#include <string.h>
#include <QString>
#include <QStringList>
#include <QList>
#include <QtXml>
#include <iostream>

#if __GNUC__
  #define PACK( __Declaration__ ) __Declaration__ __attribute__((__packed__))
#else
  #include "../targets/windows/winbuild.h"
#endif

#define EESIZE_STOCK          2048
#define EESIZE_M128           4096
#define EESIZE_GRUVIN9X       4096
#define EESIZE_TARANIS        (32*1024)
#define EESIZE_SKY9X          (128*4096)
#define EESIZE_9XRPRO         (128*4096)
#define EESIZE_RLC_MAX        EESIZE_TARANIS

template<class t> t LIMIT(t mi, t x, t ma) { return std::min(std::max(mi, x), ma); }

enum BoardEnum {
  BOARD_STOCK,
  BOARD_M128,
  BOARD_MEGA2560,
  BOARD_GRUVIN9X,
  BOARD_SKY9X,
  BOARD_9XRPRO,
  BOARD_TARANIS,
  BOARD_TARANIS_PLUS
};

QString getBoardName(BoardEnum board);

#define IS_9X(board)           (board==BOARD_STOCK || board==BOARD_M128)
#define IS_STOCK(board)        (board==BOARD_STOCK)
#define IS_2560(board)         (board==BOARD_GRUVIN9X || board==BOARD_MEGA2560)
#define IS_SKY9X(board)        (board==BOARD_SKY9X || board==BOARD_9XRPRO)
#define IS_9XRPRO(board)       (board==BOARD_9XRPRO)
#define IS_TARANIS(board)      (board==BOARD_TARANIS  || board==BOARD_TARANIS_PLUS)
#define IS_TARANIS_PLUS(board) (board==BOARD_TARANIS_PLUS)
#define IS_ARM(board)          (IS_TARANIS(board) || IS_SKY9X(board))

const uint8_t modn12x3[4][4]= {
  {1, 2, 3, 4},
  {1, 3, 2, 4},
  {4, 2, 3, 1},
  {4, 3, 2, 1} };

#define C9X_MAX_MODELS            60
#define C9X_MAX_FLIGHT_MODES      9
#define C9X_MAX_MIXERS            64
#define C9X_MAX_INPUTS            32
#define C9X_MAX_EXPOS             64
#define C9X_MAX_CURVES            32
#define C9X_MAX_POINTS            17
#define C9X_MAX_GVARS             9
#define C9X_MAX_ENCODERS          2
#define C9X_NUM_CHNOUT            32 // number of real output channels
#define C9X_NUM_CSW               32 // number of custom switches
#define C9X_MAX_CUSTOM_FUNCTIONS  64 // number of functions assigned to switches
#define C9X_NUM_MODULES           2

#define STK_RUD  1
#define STK_ELE  2
#define STK_THR  3
#define STK_AIL  4
#define STK_P1   5
#define STK_P2   6
#define STK_P3   7

enum Switches {
  SWITCH_NONE,

  SWITCH_THR = SWITCH_NONE+1,
  SWITCH_RUD,
  SWITCH_ELE,
  SWITCH_ID0,
  SWITCH_ID1,
  SWITCH_ID2,
  SWITCH_AIL,
  SWITCH_GEA,
  SWITCH_TRN,

  SWITCH_SA0 = SWITCH_NONE+1,
  SWITCH_SA1,
  SWITCH_SA2,
  SWITCH_SB0,
  SWITCH_SB1,
  SWITCH_SB2,
  SWITCH_SC0,
  SWITCH_SC1,
  SWITCH_SC2,
  SWITCH_SD0,
  SWITCH_SD1,
  SWITCH_SD2,
  SWITCH_SE0,
  SWITCH_SE1,
  SWITCH_SE2,
  SWITCH_SF0,
  SWITCH_SF1,
  SWITCH_SG0,
  SWITCH_SG1,
  SWITCH_SG2,
  SWITCH_SH0,
  SWITCH_SH1
};

enum TimerModes {
  TMRMODE_NONE,
  TMRMODE_ABS,
  TMRMODE_THR,
  TMRMODE_THR_REL,
  TMRMODE_THR_TRG,
  TMRMODE_FIRST_SWITCH
};

#define TRIM_LH_L  0
#define TRIM_LH_R  1
#define TRIM_LV_DN 2
#define TRIM_LV_UP 3
#define TRIM_RV_DN 4
#define TRIM_RV_UP 5
#define TRIM_RH_L  6
#define TRIM_RH_R  7
#define TRIM_NONE  8

// Beep center bits
#define BC_BIT_RUD (0x01)
#define BC_BIT_ELE (0x02)
#define BC_BIT_THR (0x04)
#define BC_BIT_AIL (0x08)
#define BC_BIT_P1  (0x10)
#define BC_BIT_P2  (0x20)
#define BC_BIT_P3  (0x40)
#define BC_BIT_P4  (0x80)
#define BC_BIT_REA (0x80)
#define BC_BIT_REB (0x100)

// TODO remove this enum!
enum EnumKeys {
  KEY_MENU,
  KEY_EXIT,
#if defined(PCBACT)
  KEY_CLR,
  KEY_PAGE,
  KEY_PLUS,  /* Fake, used for rotary encoder */
  KEY_MINUS, /* Fake, used for rotary encoder */
#elif defined(PCBX9D)
  KEY_ENTER,
  KEY_PAGE,
  KEY_PLUS,
  KEY_MINUS,
#else
  KEY_DOWN,
  KEY_UP,
  KEY_RIGHT,
  KEY_LEFT,
#endif
};

#define CHAR_FOR_NAMES " ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_-."
#define CHAR_FOR_NAMES_REGEX "[ A-Za-z0-9_.-,]*"

enum HeliSwashTypes {
 HELI_SWASH_TYPE_NONE=0,
 HELI_SWASH_TYPE_120,
 HELI_SWASH_TYPE_120X,
 HELI_SWASH_TYPE_140,
 HELI_SWASH_TYPE_90
};

#define NUM_STICKS          4
#define BOARD_9X_NUM_POTS   3
#define C9X_NUM_POTS        5
#define NUM_CAL_PPM         4
#define NUM_CYC             3
#define C9X_NUM_SWITCHES    10
#define C9X_NUM_KEYS        6
#define C9X_MAX_TIMERS      2

extern const char * switches9X[];
extern const char * switchesX9D[];
extern const char leftArrow[];
extern const char rightArrow[];
extern const char upArrow[];
extern const char downArrow[];

enum ThrottleSource {
  THROTTLE_SOURCE_THR,
  THROTTLE_SOURCE_P1,
  THROTTLE_SOURCE_P2,
  THROTTLE_SOURCE_P3,
  THROTTLE_SOURCE_S1 = THROTTLE_SOURCE_P1,
  THROTTLE_SOURCE_S2,
  THROTTLE_SOURCE_S3,
  THROTTLE_SOURCE_LS,
  THROTTLE_SOURCE_RS,
  THROTTLE_SOURCE_FIRST_CHANNEL,
};

enum TelemetrySource {
  TELEMETRY_SOURCE_TX_BATT,
  TELEMETRY_SOURCE_TX_TIME,
  TELEMETRY_SOURCE_TIMER1,
  TELEMETRY_SOURCE_TIMER2,
  TELEMETRY_SOURCE_SWR,
  TELEMETRY_SOURCE_RSSI_TX,
  TELEMETRY_SOURCE_RSSI_RX,
  TELEMETRY_SOURCE_A1,
  TELEMETRY_SOURCE_A2,
  TELEMETRY_SOURCE_A3,
  TELEMETRY_SOURCE_A4,
  TELEMETRY_SOURCE_ALT,
  TELEMETRY_SOURCE_RPM,
  TELEMETRY_SOURCE_FUEL,
  TELEMETRY_SOURCE_T1,
  TELEMETRY_SOURCE_T2,
  TELEMETRY_SOURCE_SPEED,
  TELEMETRY_SOURCE_DIST,
  TELEMETRY_SOURCE_GPS_ALT,
  TELEMETRY_SOURCE_CELL,
  TELEMETRY_SOURCE_CELLS_SUM,
  TELEMETRY_SOURCE_VFAS,
  TELEMETRY_SOURCE_CURRENT,
  TELEMETRY_SOURCE_CONSUMPTION,
  TELEMETRY_SOURCE_POWER,
  TELEMETRY_SOURCE_ACCX,
  TELEMETRY_SOURCE_ACCY,
  TELEMETRY_SOURCE_ACCZ,
  TELEMETRY_SOURCE_HDG,
  TELEMETRY_SOURCE_VERTICAL_SPEED,
  TELEMETRY_SOURCE_ASPEED,
  TELEMETRY_SOURCE_DTE,
  TELEMETRY_SOURCE_A1_MIN,
  TELEMETRY_SOURCE_A2_MIN,
  TELEMETRY_SOURCE_A3_MIN,
  TELEMETRY_SOURCE_A4_MIN,
  TELEMETRY_SOURCE_ALT_MIN,
  TELEMETRY_SOURCE_ALT_MAX,
  TELEMETRY_SOURCE_RPM_MAX,
  TELEMETRY_SOURCE_T1_MAX,
  TELEMETRY_SOURCE_T2_MAX,
  TELEMETRY_SOURCE_SPEED_MAX,
  TELEMETRY_SOURCE_DIST_MAX,
  TELEMETRY_SOURCE_ASPEED_MAX,
  TELEMETRY_SOURCE_CELL_MIN,
  TELEMETRY_SOURCE_CELLS_MIN,
  TELEMETRY_SOURCE_VFAS_MIN,
  TELEMETRY_SOURCE_CURRENT_MAX,
  TELEMETRY_SOURCE_POWER_MAX,
  TELEMETRY_SOURCE_ACC,
  TELEMETRY_SOURCE_GPS_TIME,
  TELEMETRY_SOURCES_STATUS_COUNT = TELEMETRY_SOURCE_GPS_TIME+1,
  TELEMETRY_SOURCES_DISPLAY_COUNT = TELEMETRY_SOURCE_POWER_MAX+1,
  TELEMETRY_SOURCES_COUNT = TELEMETRY_SOURCE_POWER_MAX+1,
  TELEMETRY_SOURCE_RESERVE = -1
};

#define TM_HASTELEMETRY     0x01
#define TM_HASOFFSET        0x02
#define TM_HASWSHH          0x04

enum RawSourceType {
  SOURCE_TYPE_NONE,
  SOURCE_TYPE_VIRTUAL_INPUT,
  SOURCE_TYPE_LUA_OUTPUT,
  SOURCE_TYPE_STICK, // and POTS
  SOURCE_TYPE_ROTARY_ENCODER,
  SOURCE_TYPE_TRIM,
  SOURCE_TYPE_MAX,
  SOURCE_TYPE_SWITCH,
  SOURCE_TYPE_CUSTOM_SWITCH,
  SOURCE_TYPE_CYC,
  SOURCE_TYPE_PPM,
  SOURCE_TYPE_CH,
  SOURCE_TYPE_GVAR,
  SOURCE_TYPE_TELEMETRY,
  MAX_SOURCE_TYPE
};

class ModelData;

QString AnalogString(int index);
QString RotaryEncoderString(int index);

class RawSourceRange
{
  public:
    RawSourceRange():
      decimals(0),
      min(0.0),
      max(0.0),
      step(1.0),
      offset(0.0)
    {
    }

    float getValue(int value) {
      return min + float(value) * step;
    }

    int decimals;
    double min;
    double max;
    double step;
    double offset;
    QString unit;
};

#define RANGE_SINGLE_PRECISION    1
#define RANGE_DELTA_FUNCTION      2
#define RANGE_DELTA_ABS_FUNCTION  4

class GeneralSettings;
class RawSource {
  public:
    RawSource():
      type(SOURCE_TYPE_NONE),
      index(0)
    {
    }

    RawSource(int value):
      type(RawSourceType(abs(value)/65536)),
      index(value >= 0 ? abs(value)%65536 : -(abs(value)%65536))
    {
    }

    RawSource(RawSourceType type, int index=0):
      type(type),
      index(index)
    {
    }

    inline const int toValue() const
    {
      return index >= 0 ? (type * 65536 + index) : -(type * 65536 - index);
    }

    QString toString(const ModelData & model);
    
    RawSourceRange getRange(const ModelData & model, const GeneralSettings & settings, unsigned int flags=0) const;
    
    bool operator == ( const RawSource & other) {
      return (this->type == other.type) && (this->index == other.index);
    }

    bool operator != ( const RawSource & other) {
      return (this->type != other.type) || (this->index != other.index);
    }

    bool isTimeBased() const
    {
      return (type==SOURCE_TYPE_TELEMETRY && (index==TELEMETRY_SOURCE_TX_TIME || index==TELEMETRY_SOURCE_TIMER1 || index==TELEMETRY_SOURCE_TIMER2));
    }

    RawSourceType type;
    int index;
};

enum RawSwitchType {
  SWITCH_TYPE_NONE,
  SWITCH_TYPE_SWITCH,
  SWITCH_TYPE_VIRTUAL,
  SWITCH_TYPE_MULTIPOS_POT,
  SWITCH_TYPE_TRIM,
  SWITCH_TYPE_ROTARY_ENCODER,
  SWITCH_TYPE_ON,
  SWITCH_TYPE_OFF,
  SWITCH_TYPE_ONE,
  SWITCH_TYPE_FLIGHT_MODE,
  SWITCH_TYPE_TIMER_MODE
};

class RawSwitch {
  public:
    RawSwitch():
      type(SWITCH_TYPE_NONE),
      index(0)
    {
    }

    explicit RawSwitch(int value):
      type(RawSwitchType(abs(value)/256)),
      index(value >= 0 ? abs(value)%256 : -(abs(value)%256))
    {
    }

    RawSwitch(RawSwitchType type, int index=0):
      type(type),
      index(index)
    {
    }

    inline const int toValue() const
    {
      return index >= 0 ? (type * 256 + index) : -(type * 256 - index);
    }

    QString toString();

    bool operator== ( const RawSwitch& other) {
      return (this->type == other.type) && (this->index == other.index);
    }

    bool operator!= ( const RawSwitch& other) {
      return (this->type != other.type) || (this->index != other.index);
    }

    RawSwitchType type;
    int index;
};

class TrainerMix {
  public:
    TrainerMix() { clear(); }
    unsigned int src; // 0-7 = ch1-8
    RawSwitch swtch;
    int weight;
    unsigned int mode;   // off, add-mode, subst-mode
    void clear() { memset(this, 0, sizeof(TrainerMix)); }
};

class TrainerData {
  public:
    TrainerData() { clear(); }
    int         calib[4];
    TrainerMix  mix[4];
    void clear() { memset(this, 0, sizeof(TrainerData)); }
};

enum BeeperMode {
  e_quiet = -2,
  e_alarms_only = -1,
  e_no_keys = 0,
  e_all = 1
};

class GeneralSettings {
  public:
    GeneralSettings();

    int getDefaultStick(unsigned int channel) const;
    RawSource getDefaultSource(unsigned int channel) const;
    int getDefaultChannel(unsigned int stick) const;

    unsigned int version;
    unsigned int variant;
    int   calibMid[NUM_STICKS+C9X_NUM_POTS];
    int   calibSpanNeg[NUM_STICKS+C9X_NUM_POTS];
    int   calibSpanPos[NUM_STICKS+C9X_NUM_POTS];
    unsigned int  currModel; // 0..15
    unsigned int   contrast;
    unsigned int   vBatWarn;
    int    vBatCalib;
    int    vBatMin;
    int    vBatMax;
    int   backlightMode;
    TrainerData trainer;
    unsigned int   view;    // main screen view // TODO enum
    bool      disableThrottleWarning;
    bool      fai;
    int       switchWarning; // -1=down, 0=off, 1=up
    bool      disableMemoryWarning;
    BeeperMode beeperMode;
    bool      disableAlarmWarning;
    bool      enableTelemetryAlarm;
    BeeperMode hapticMode;
    unsigned int   stickMode; // TODO enum
    int    timezone;
    bool      optrexDisplay;
    unsigned int    inactivityTimer;
    unsigned int spare1;
    unsigned int spare2;
    bool      minuteBeep;
    bool      preBeep;
    bool      flashBeep;
    bool      disablePotScroll;
    bool      frskyinternalalarm;
    bool      disableBG;
    unsigned int  splashMode;
    int splashDuration;
    unsigned int  backlightDelay;
    bool   blightinv;
    bool   stickScroll;
    unsigned int   templateSetup;  //RETA order according to chout_ar array
    int    PPM_Multiplier;
    int    hapticLength;
    unsigned int   reNavigation;
    unsigned int stickReverse;
    bool      hideNameOnSplash;
    bool      enablePpmsim;
    unsigned int   speakerPitch;
    int   hapticStrength;
    unsigned int   speakerMode;
    unsigned int   lightOnStickMove; /* er9x / ersky9x only */
    char      ownerName[10+1];
    unsigned int   switchWarningStates;
    int    beeperLength;
    unsigned int    gpsFormat;
    int     speakerVolume;
    unsigned int   backlightBright;
    int switchesDelay;
    int    currentCalib;
    int    temperatureCalib;
    int    temperatureWarn;
    unsigned int mAhWarn;
    unsigned int mAhUsed;
    unsigned int globalTimer;
    unsigned int sticksGain;
    unsigned int rotarySteps;
    unsigned int countryCode;
    unsigned int imperial;
    bool crosstrim;
    char ttsLanguage[2+1];
    int beepVolume;
    int wavVolume;
    int varioVolume;
    int varioPitch;
    int varioRange;
    int varioRepeat;
    int backgroundVolume;
    unsigned int switchUnlockStates;
    unsigned int potsType[8];
    unsigned int backlightColor;
};

class CurveReference {
  public:
    enum CurveRefType {
      CURVE_REF_DIFF,
      CURVE_REF_EXPO,
      CURVE_REF_FUNC,
      CURVE_REF_CUSTOM
    };

    CurveReference() { clear(); }

    CurveReference(CurveRefType type, int value):
      type(type),
      value(value)
    {
    }

    void clear() { memset(this, 0, sizeof(CurveReference)); }

    CurveRefType type;
    int value;

    QString toString();
};

enum InputMode {
  INPUT_MODE_NONE,
  INPUT_MODE_POS,
  INPUT_MODE_NEG,
  INPUT_MODE_BOTH
};

class ExpoData {
  public:
    ExpoData() { clear(); }
    RawSource srcRaw;
    unsigned int scale;
    unsigned int mode;
    unsigned int chn;
    RawSwitch swtch;
    unsigned int phases;        // -5=!FP4, 0=normal, 5=FP4
    int  weight;
    int offset;
    CurveReference curve;
    int carryTrim;
    char name[10+1];
    void clear() { memset(this, 0, sizeof(ExpoData)); }
};

class CurvePoint {
  public:
    int8_t x;
    int8_t y;
};

class CurveData {
  public:
    enum CurveType {
      CURVE_TYPE_STANDARD,
      CURVE_TYPE_CUSTOM,
      CURVE_TYPE_LAST = CURVE_TYPE_CUSTOM
    };

    CurveData() { clear(5); }

    CurveType type;
    bool smooth;
    int  count;
    CurvePoint points[C9X_MAX_POINTS];
    char name[6+1];
    void clear(int count) { memset(this, 0, sizeof(CurveData)); this->count = count; }
};

class LimitData {
  public:
    LimitData() { clear(); }
    int   min;
    int   max;
    bool  revert;
    int   offset;
    int   ppmCenter;
    bool  symetrical;
    char  name[6+1];
    CurveReference curve;
    QString minToString();
    QString maxToString();
    QString offsetToString();
    void clear();
};

enum MltpxValue {
  MLTPX_ADD=0,
  MLTPX_MUL=1,
  MLTPX_REP=2
};

#define MIXDATA_NAME_LEN  10

class MixData {
  public:
    MixData() { clear(); }
    unsigned int destCh;            //        1..C9X_NUM_CHNOUT
    RawSource srcRaw;
    int     weight;
    RawSwitch swtch;
    CurveReference     curve;             //0=symmetrisch
    unsigned int delayUp;
    unsigned int delayDown;
    unsigned int speedUp;           // Servogeschwindigkeit aus Tabelle (10ms Cycle)
    unsigned int speedDown;         // 0 nichts
    int  carryTrim;
    bool noExpo;
    MltpxValue mltpx;          // multiplex method 0=+ 1=* 2=replace
    unsigned int mixWarn;           // mixer warning
    unsigned int phases;             // -5=!FP4, 0=normal, 5=FP4
    int    sOffset;
    char   name[MIXDATA_NAME_LEN+1];

    void clear() { memset(this, 0, sizeof(MixData)); }
};

enum CSFunction {
  LS_FN_OFF,
  LS_FN_VPOS,
  LS_FN_VNEG,
  LS_FN_APOS,
  LS_FN_ANEG,
  LS_FN_AND,
  LS_FN_OR,
  LS_FN_XOR,
  LS_FN_EQUAL,
  LS_FN_NEQUAL,
  LS_FN_GREATER,
  LS_FN_LESS,
  LS_FN_EGREATER,
  LS_FN_ELESS,
  LS_FN_DPOS,
  LS_FN_DAPOS,
  LS_FN_VEQUAL, // added at the end to avoid everything renumbered
  LS_FN_VALMOSTEQUAL,
  LS_FN_TIMER,
  LS_FN_STICKY,
  LS_FN_STAY,
  // later ... LS_FN_RANGE,
  LS_FN_MAX
};

enum CSFunctionFamily {
  LS_FAMILY_VOFS,
  LS_FAMILY_VBOOL,
  LS_FAMILY_VCOMP,
  LS_FAMILY_TIMER,
  LS_FAMILY_STICKY,
  LS_FAMILY_STAY,
};

class LogicalSwitchData { // Logical Switches data
  public:
    LogicalSwitchData(unsigned int func=0)
    {
      clear();
      this->func = func;
    }
    unsigned int func;
    int val1;
    int val2;
    int val3;
    unsigned int delay;
    unsigned int duration;
    int andsw;
    void clear() { memset(this, 0, sizeof(LogicalSwitchData)); }
    CSFunctionFamily getFunctionFamily();
    unsigned int getRangeFlags();
    QString funcToString();
    QString toString(const ModelData & model, const GeneralSettings & settings);
};

enum AssignFunc {
  FuncOverrideCH1 = 0,
  FuncOverrideCH32 = FuncOverrideCH1+C9X_NUM_CHNOUT-1,
  FuncTrainer,
  FuncTrainerRUD,
  FuncTrainerELE,
  FuncTrainerTHR,
  FuncTrainerAIL,
  FuncInstantTrim,
  FuncPlaySound,
  FuncPlayHaptic,
  FuncReset,
  FuncSetTimer1,
  FuncSetTimer2,
  FuncVario,
  FuncPlayPrompt,
  FuncPlayBoth,
  FuncPlayValue,
  FuncPlayScript,
  FuncLogs,
  FuncVolume,
  FuncBacklight,
  FuncBackgroundMusic,
  FuncBackgroundMusicPause,
  FuncAdjustGV1,
  FuncAdjustGVLast = FuncAdjustGV1+C9X_MAX_GVARS-1,
  FuncCount,
  FuncReserve = -1
};

class FuncSwData { // Function Switches data
  public:
    FuncSwData(AssignFunc func=FuncOverrideCH1) { clear(); this->func = func; }
    RawSwitch    swtch;
    AssignFunc   func;
    int param;
    char paramarm[10];
    unsigned int enabled; // TODO perhaps not any more the right name
    unsigned int adjustMode;
    int repeatParam;
    void clear();
    QString funcToString();
    QString paramToString();
    QString repeatToString();
    QStringList toStringList();
};

class FlightModeData {
  public:
    FlightModeData() { clear(); }
    int trimMode[NUM_STICKS];
    int trimRef[NUM_STICKS];
    int trim[NUM_STICKS];
    RawSwitch swtch;
    char name[10+1];
    unsigned int fadeIn;
    unsigned int fadeOut;
    int rotaryEncoders[2];
    int gvars[C9X_MAX_GVARS];
    void clear() { memset(this, 0, sizeof(FlightModeData)); }
};

class SwashRingData { // Swash Ring data
  public:
    SwashRingData() { clear(); }
    bool      invertELE;
    bool      invertAIL;
    bool      invertCOL;
    unsigned int  type;
    RawSource collectiveSource;
    unsigned int  value;
    void clear() { memset(this, 0, sizeof(SwashRingData)); }
};

class FrSkyAlarmData {
  public:
    FrSkyAlarmData() { clear(); }
    unsigned int   level;               // 0=none, 1=Yellow, 2=Orange, 3=Red
    unsigned int   greater;             // 0=LT(<), 1=GT(>)
    unsigned int value;               // 0.1V steps EG. 6.6 Volts = 66. 25.1V = 251, etc.

    void clear() { memset(this, 0, sizeof(FrSkyAlarmData)); }
};

class FrSkyRSSIAlarm {
  public:
    FrSkyRSSIAlarm() { clear(0, 50); }
    unsigned int level;
    int value;
    void clear(unsigned int level, int value) { this->level = level; this->value = value;}
};

class FrSkyChannelData {
  public:
    FrSkyChannelData() { clear(); }
    unsigned int ratio;                // 0.0 means not used, 0.1V steps EG. 6.6 Volts = 66. 25.1V = 251, etc.
    unsigned int type;                 // future use: 0=volts, 1=ml...
    int   offset;
    unsigned int multiplier;
    FrSkyAlarmData alarms[2];

    float getRatio() const;
    RawSourceRange getRange() const;
    void clear() { memset(this, 0, sizeof(FrSkyChannelData)); }
};

struct FrSkyBarData {
  unsigned int   source;
  unsigned int   barMin;           // minimum for bar display
  unsigned int   barMax;           // ditto for max display (would usually = ratio)
};

struct FrSkyLineData {
  unsigned int     source[3];
};

class FrSkyScreenData {
  public:
    FrSkyScreenData() { clear(); }

    typedef union {
      FrSkyBarData bars[4];
      FrSkyLineData lines[4];
    } FrSkyScreenBody;

    unsigned int type;
    FrSkyScreenBody body;

    void clear() { memset(this, 0, sizeof(FrSkyScreenData)); }
};

enum TelemetryVarioSources {
  TELEMETRY_VARIO_SOURCE_ALTI,
  TELEMETRY_VARIO_SOURCE_ALTI_PLUS,
  TELEMETRY_VARIO_SOURCE_VSPEED,
  TELEMETRY_VARIO_SOURCE_A1,
  TELEMETRY_VARIO_SOURCE_A2,
  TELEMETRY_VARIO_SOURCE_DTE,
};

enum TelemetryVoltsSources {
  TELEMETRY_VOLTS_SOURCE_A1,
  TELEMETRY_VOLTS_SOURCE_A2,
  TELEMETRY_VOLTS_SOURCE_A3,
  TELEMETRY_VOLTS_SOURCE_A4,
  TELEMETRY_VOLTS_SOURCE_FAS,
  TELEMETRY_VOLTS_SOURCE_CELLS
};

enum TelemetryCurrentSources {
  TELEMETRY_CURRENT_SOURCE_NONE,
  TELEMETRY_CURRENT_SOURCE_A1,
  TELEMETRY_CURRENT_SOURCE_A2,
  TELEMETRY_CURRENT_SOURCE_A3,
  TELEMETRY_CURRENT_SOURCE_A4,
  TELEMETRY_CURRENT_SOURCE_FAS
};

class FrSkyData {
  public:
    FrSkyData() { clear(); }
    FrSkyChannelData channels[4];
    unsigned int usrProto;
    int blades;
    unsigned int voltsSource;
    bool altitudeDisplayed;
    unsigned int currentSource;
    unsigned int FrSkyGpsAlt;
    FrSkyScreenData screens[3];
    FrSkyRSSIAlarm rssiAlarms[2];
    unsigned int varioSource;
    int varioMin;
    int varioCenterMin;    // if increment in 0.2m/s = 3.0m/s max
    int varioCenterMax;
    int varioMax;
    bool mAhPersistent;
    unsigned int storedMah;
    int fasOffset;

    void clear();
};

class MavlinkData {
  public:
    MavlinkData() { clear();}
    unsigned int rc_rssi_scale;
    unsigned int pc_rssi_en;
    unsigned int bluetooth_en;
    unsigned int mavreq_en;
	
    void clear() { memset(this, 0, sizeof(MavlinkData)); }
};

class TimerData {
  public:
    TimerData() { clear(); }
    RawSwitch    mode;
    bool         minuteBeep;
    unsigned int countdownBeep;
    unsigned int val;
    unsigned int persistent;
    int          pvalue;
    void clear() { memset(this, 0, sizeof(TimerData)); mode = RawSwitch(SWITCH_TYPE_TIMER_MODE, 0); }
};

enum RFprotocol {
  OFF,
  PPM,
  SILV_A,
  SILV_B,
  SILV_C,
  CTP1009,
  LP45,
  DSM2,
  DSMX,
  PPM16,
  PPMSIM,
  PXX_XJT_X16,
  PXX_XJT_D8,
  PXX_XJT_LR12,
  PXX_DJT,
  PROTO_LAST
};

class ModuleData {
  public:
    ModuleData() { clear(); }
    int          RFprotocol;
    unsigned int channelsStart;
    int          channelsCount; // 0=8 channels
    unsigned int failsafeMode;
    int          failsafeChannels[C9X_NUM_CHNOUT];
    int          ppmDelay;
    bool         ppmPulsePol;           // false = positive
    int          ppmFrameLength;
    void clear() { memset(this, 0, sizeof(ModuleData)); }
    QString polarityToString() { return ppmPulsePol ? QObject::tr("Positive") : QObject::tr("Negative"); }
};

#define C9X_MAX_SCRIPTS       7
#define C9X_MAX_SCRIPT_INPUTS 10
class ScriptData {
  public:
    ScriptData() { clear(); }
    char    filename[10+1];
    char    name[10+1];
    int     inputs[C9X_MAX_SCRIPT_INPUTS];
    void clear() { memset(this, 0, sizeof(ScriptData)); }
};

class ModelData {
  public:
    ModelData();
    ModelData(const ModelData & src);
    ModelData & operator = (const ModelData & src);

    ExpoData * insertInput(const int idx);
    void removeInput(const int idx);

    bool isInputValid(const unsigned int idx) const;

    bool      used;
    char      name[12+1];
    TimerData timers[2];
    bool      thrTrim;            // Enable Throttle Trim
    int       trimInc;            // Trim Increments
    bool      disableThrottleWarning;

    unsigned int beepANACenter;      // 1<<0->A1.. 1<<6->A7

    bool      extendedLimits; // TODO xml
    bool      extendedTrims;
    bool      throttleReversed;
    FlightModeData flightModeData[C9X_MAX_FLIGHT_MODES];
    MixData   mixData[C9X_MAX_MIXERS];
    LimitData limitData[C9X_NUM_CHNOUT];

    char      inputNames[C9X_MAX_INPUTS][4+1];
    ExpoData  expoData[C9X_MAX_EXPOS];

    CurveData curves[C9X_MAX_CURVES];
    LogicalSwitchData  customSw[C9X_NUM_CSW];
    FuncSwData    funcSw[C9X_MAX_CUSTOM_FUNCTIONS];
    SwashRingData swashRingData;
    unsigned int thrTraceSrc;
    unsigned int modelId;
    unsigned int switchWarningStates;
    unsigned int nSwToWarn;
    unsigned int nPotsToWarn;
    int          potPosition[C9X_NUM_POTS];
    bool         displayChecklist;
    // TODO structure
    char     gvars_names[C9X_MAX_GVARS][6+1];
    bool     gvars_popups[C9X_MAX_GVARS];
    MavlinkData mavlink;
    unsigned int telemetryProtocol;
    unsigned int 		telemetryCom;
    unsigned int 		telemetryBaud;  
    unsigned int		telemetryMirrorCom;
    FrSkyData frsky;

    char bitmap[10+1];

    unsigned int trainerMode;

    ModuleData moduleData[C9X_NUM_MODULES+1/*trainer*/];

    ScriptData scriptData[C9X_MAX_SCRIPTS];

    void clear();
    bool isempty();
    void setDefaultInputs(const GeneralSettings & settings);
    void setDefaultMixes(const GeneralSettings & settings);
    void setDefaultValues(unsigned int id, const GeneralSettings & settings);

    int getTrimValue(int phaseIdx, int trimIdx);
    void setTrimValue(int phaseIdx, int trimIdx, int value);

    bool isGVarLinked(int phaseIdx, int gvarIdx);
    int getGVarValue(int phaseIdx, int gvarIdx);

    ModelData removeGlobalVars();

    void clearMixes();
    void clearInputs();

    int getChannelsMax(bool forceExtendedLimits=false) const;

  protected:
    void removeGlobalVar(int & var);
};

class RadioData {
  public:   
    GeneralSettings generalSettings;
    ModelData models[C9X_MAX_MODELS];    
};

// TODO rename FlightPhase to FlightMode
enum Capability {
  FlightModes,
  FlightModesName,
  FlightModesHaveFades,
  Imperial,
  Mixes,
  Timers,
  TimeDivisions,
  CustomFunctions,
  SafetyChannelCustomFunction,
  VoicesAsNumbers,
  VoicesMaxLength,
  ModelVoice,
  MultiLangVoice,
  ModelImage,
  Pots,
  Switches,
  SwitchesPositions,
  LogicalSwitches,
  CustomAndSwitches,
  HasNegAndSwitches,
  LogicalSwitchesExt,
  RotaryEncoders,
  Outputs,
  ChannelsName,
  ExtraInputs,
  ExtendedTrims,
  NumCurves,
  NumCurvePoints,
  OffsetWeight,
  Simulation,
  SoundMod,
  SoundPitch,
  MaxVolume,
  EepromBackup,
  Haptic,
  HasBeeper,
  ModelTrainerEnable,
  Timer2ThrTrig,
  HasExpoNames,
  HasNoExpo,
  HasMixerNames,
  HasChNames,
  HasCvNames,
  HasPxxCountry,
  HasPPMStart,
  HasGeneralUnits,
  HasFAIMode,
  OptrexDisplay,
  PPMExtCtrl,
  PPMFrameLength,
  DSM2Indexes,
  Telemetry,
  TelemetryUnits,
  TelemetryBars,
  Heli,
  Gvars,
  GvarsInCS,
  GvarsAreNamed,
  GvarsFlightModes,
  GvarsName,
  NoTelemetryProtocol,
  TelemetryCustomScreens,
  TelemetryCustomScreensFieldsPerLine,
  TelemetryTimeshift,
  TelemetryMaxMultiplier,
  HasAltitudeSel,
  HasVario,
  HasVarioSink,
  HasFailsafe,
  HasSoundMixer,
  NumModules,
  PPMCenter,
  PPMUnitMicroseconds,
  SYMLimits,
  HasCurrentCalibration,
  HasVolume,
  HasBrightness,
  PerModelTimers,
  SlowScale,
  SlowRange,
  PermTimers,
  HasSDLogs,
  CSFunc,
  LCDWidth,
  GetThrSwitch,
  HasDisplayText,
  VirtualInputs,
  TrainerInputs,
  LuaScripts,
  LuaInputsPerScript,
  LuaOutputsPerScript,
  LimitsPer1000,
  EnhancedCurves,
  HasFasOffset,
  HasMahPersistent,
  MultiposPots,
  MultiposPotsPositions,
  SimulatorVariant,
  MavlinkTelemetry,
  HasInputDiff,
  HasMixerExpo,
};

class SimulatorInterface;
class EEPROMInterface
{
  public:

    EEPROMInterface(BoardEnum board):
      board(board)
    {
    }

    virtual ~EEPROMInterface() {}

    inline BoardEnum getBoard() { return board; }

    virtual bool load(RadioData &radioData, const uint8_t *eeprom, int size) = 0;

    virtual bool loadBackup(RadioData &radioData, uint8_t *eeprom, int esize, int index) = 0;
    
    virtual bool loadxml(RadioData &radioData, QDomDocument &doc) = 0;

    virtual int save(uint8_t *eeprom, RadioData &radioData, uint32_t variant=0, uint8_t version=0) = 0;

    virtual int getSize(ModelData &) = 0;
    
    virtual int getSize(GeneralSettings &) = 0;
    
    virtual int isAvailable(RFprotocol proto, int port=0) = 0;

    virtual const int getEEpromSize() = 0;

    virtual const int getMaxModels() = 0;

  protected:

    BoardEnum board;

  private:

    EEPROMInterface();

};

extern std::list<QString> EEPROMWarnings;

/* EEPROM string conversion functions */
void setEEPROMString(char *dst, const char *src, int size);
void getEEPROMString(char *dst, const char *src, int size);

float ValToTim(int value);
int TimToVal(float value);

QString getSignedStr(int value);
QString getGVarString(int16_t val, bool sign=false);

inline int applyStickMode(int stick, unsigned int mode)
{
  if (mode == 0 || mode > 4) {
    std::cerr << "Incorrect stick mode" << mode;
    return stick;
  }

  const unsigned int stickModes[]= {
      1, 2, 3, 4,
      1, 3, 2, 4,
      4, 2, 3, 1,
      4, 3, 2, 1 };

  if (stick >= 1 && stick <= 4)
    return stickModes[(mode-1)*4 + stick - 1];
  else
    return stick;
}

inline void applyStickModeToModel(ModelData &model, unsigned int mode)
{
  ModelData model_copy = model;

  // trims
  for (int p=0; p<C9X_MAX_FLIGHT_MODES; p++) {
    for (int i=0; i<NUM_STICKS/2; i++) {
      int converted_stick = applyStickMode(i+1, mode) - 1;
      int tmp = model.flightModeData[p].trim[i];
      model.flightModeData[p].trim[i] = model.flightModeData[p].trim[converted_stick];
      model.flightModeData[p].trim[converted_stick] = tmp;
      tmp = model.flightModeData[p].trimRef[i];
      model.flightModeData[p].trimRef[i] = model.flightModeData[p].trimRef[converted_stick];
      model.flightModeData[p].trimRef[converted_stick] = tmp;
    }
  }

  // expos
  for (unsigned int i=0; i<sizeof(model.expoData) / sizeof(model.expoData[1]); i++) {
    if (model.expoData[i].mode)
      model_copy.expoData[i].chn = applyStickMode(model.expoData[i].chn+1, mode) - 1;
  }
  int index=0;
  for (unsigned int i=0; i<NUM_STICKS; i++) {
    for (unsigned int e=0; e<sizeof(model.expoData) / sizeof(model.expoData[1]); e++) {
      if (model_copy.expoData[e].mode && model_copy.expoData[e].chn == i)
        model.expoData[index++] = model_copy.expoData[e];
    }
  }

  // mixers
  for (int i=0; i<C9X_MAX_MIXERS; i++) {
    if (model.mixData[i].srcRaw.type == SOURCE_TYPE_STICK) {
      model.mixData[i].srcRaw.index = applyStickMode(model.mixData[i].srcRaw.index + 1, mode) - 1;
    }
  }

  // virtual switches
  for (int i=0; i<C9X_NUM_CSW; i++) {
    RawSource source;
    switch (model.customSw[i].getFunctionFamily()) {
      case LS_FAMILY_VCOMP:
        source = RawSource(model.customSw[i].val2);
        if (source.type == SOURCE_TYPE_STICK)
          source.index = applyStickMode(source.index + 1, mode) - 1;
        model.customSw[i].val2 = source.toValue();
        // no break
      case LS_FAMILY_VOFS:
        source = RawSource(model.customSw[i].val1);
        if (source.type == SOURCE_TYPE_STICK)
          source.index = applyStickMode(source.index + 1, mode) - 1;
        model.customSw[i].val1 = source.toValue();
        break;
      default:
        break;
    }
  }

  // heli
  if (model.swashRingData.collectiveSource.type == SOURCE_TYPE_STICK)
    model.swashRingData.collectiveSource.index = applyStickMode(model.swashRingData.collectiveSource.index + 1, mode) - 1;
}

void RegisterEepromInterfaces();
void UnregisterFirmwares();
void registerOpenTxFirmwares();

bool LoadBackup(RadioData &radioData, uint8_t *eeprom, int esize, int index);
bool LoadEeprom(RadioData &radioData, const uint8_t *eeprom, int size);
bool LoadEepromXml(RadioData &radioData, QDomDocument &doc);

struct Option {
  const char * name;
  QString tooltip;
  uint32_t variant;
};

class FirmwareInterface {

  public:
    FirmwareInterface(const QString & id, const QString & name, const BoardEnum board, EEPROMInterface * eepromInterface):
      id(id),
      name(name),
      board(board),
      eepromInterface(eepromInterface),
      variantBase(0),
      base(NULL)
    {
    }

    FirmwareInterface(FirmwareInterface * base, const QString & id, const QString & name, const BoardEnum board, EEPROMInterface * eepromInterface):
      id(id),
      name(name),
      board(board),
      eepromInterface(eepromInterface),
      variantBase(0),
      base(base)
    {
    }

    virtual ~FirmwareInterface()
    {
      delete eepromInterface;
    }

    inline const FirmwareInterface * getFirmwareBase() const
    {
      return base ? base : this;
    }

    // TODO needed?
    inline void setVariantBase(unsigned int variant)
    {
      variantBase = variant;
    }

    virtual FirmwareInterface * getFirmwareVariant(const QString & id) { return NULL; }

    unsigned int getVariantNumber();

    virtual void addLanguage(const char *lang);

    virtual void addTTSLanguage(const char *lang);

    virtual void addOption(const char *option, QString tooltip="", uint32_t variant=0);

    virtual void addOptions(Option options[]);

    inline int saveEEPROM(uint8_t *eeprom, RadioData &radioData, uint32_t variant=0, unsigned int version=0)
    {
      return eepromInterface->save(eeprom, radioData, variant, version);
    }

    virtual QString getStampUrl() = 0;

    virtual QString getReleaseNotesUrl() = 0;

    virtual QString getFirmwareUrl() = 0;

    inline BoardEnum getBoard() const
    {
      return board;
    }

    inline QString getName() const
    {
      return name;
    }

    inline QString getId() const
    {
      return id;
    }

    inline EEPROMInterface * getEepromInterface()
    {
      return eepromInterface;
    }

    virtual int getCapability(const Capability) = 0;

    virtual bool isTelemetrySourceAvailable(int source) = 0;

    virtual SimulatorInterface * getSimulator()
    {
      return NULL;
    }

  public:
    QList<const char *> languages;
    QList<const char *> ttslanguages;
    QList< QList<Option> > opts;

  protected:
    QString id;
    QString name;
    BoardEnum board;
    EEPROMInterface * eepromInterface;
    unsigned int variantBase;
    FirmwareInterface * base;

  private:
    FirmwareInterface();

};

extern QList<FirmwareInterface *> firmwares;
extern FirmwareInterface * default_firmware_variant;
extern FirmwareInterface * current_firmware_variant;

FirmwareInterface * GetFirmware(QString id);

inline FirmwareInterface * GetCurrentFirmware()
{
  return current_firmware_variant;
}

inline EEPROMInterface * GetEepromInterface()
{
  return GetCurrentFirmware()->getEepromInterface();
}

void UnregisterEepromInterfaces();

inline int divRoundClosest(const int n, const int d)
{
  return ((n < 0) ^ (d < 0)) ? ((n - d/2)/d) : ((n + d/2)/d);
}

#define CHECK_IN_ARRAY(T, index) ((unsigned int)index < (unsigned int)(sizeof(T)/sizeof(T[0])) ? T[(unsigned int)index] : "???")

#endif
