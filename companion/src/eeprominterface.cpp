#include <stdio.h>
#include <list>
#include <float.h>
#include "eeprominterface.h"
#include "firmwares/er9x/er9xinterface.h"
//#include "firmwares/th9x/th9xinterface.h"
#include "firmwares/gruvin9x/gruvin9xinterface.h"
#include "firmwares/opentx/opentxinterface.h"
#include "firmwares/opentx/opentxeeprom.h"
#include "firmwares/ersky9x/ersky9xinterface.h"
#include "appdata.h"
#include "helpers.h"
#include "wizarddata.h"

std::list<QString> EEPROMWarnings;

const char * switches9X[] = { "3POS", "THR", "RUD", "ELE", "AIL", "GEA", "TRN" };
const char * switchesX9D[] = { "SA", "SB", "SC", "SD", "SE", "SF", "SG", "SH" };
const char leftArrow[] = {(char)0xE2, (char)0x86, (char)0x90, 0};
const char rightArrow[] = {(char)0xE2, (char)0x86, (char)0x92, 0};
const char upArrow[] = {(char)0xE2, (char)0x86, (char)0x91, 0};
const char downArrow[] = {(char)0xE2, (char)0x86, (char)0x93, 0};

const uint8_t chout_ar[] = { // First number is 0..23 -> template setup,  Second is relevant channel out
  1,2,3,4 , 1,2,4,3 , 1,3,2,4 , 1,3,4,2 , 1,4,2,3 , 1,4,3,2,
  2,1,3,4 , 2,1,4,3 , 2,3,1,4 , 2,3,4,1 , 2,4,1,3 , 2,4,3,1,
  3,1,2,4 , 3,1,4,2 , 3,2,1,4 , 3,2,4,1 , 3,4,1,2 , 3,4,2,1,
  4,1,2,3 , 4,1,3,2 , 4,2,1,3 , 4,2,3,1 , 4,3,1,2 , 4,3,2,1
};

void setEEPROMString(char *dst, const char *src, int size)
{
  memcpy(dst, src, size);
  for (int i=size-1; i>=0; i--) {
    if (dst[i] == '\0')
      dst[i] = ' ';
    else
      break;
  }
}

void getEEPROMString(char *dst, const char *src, int size)
{
  memcpy(dst, src, size);
  dst[size] = '\0';
  for (int i=size-1; i>=0; i--) {
    if (dst[i] == ' ')
      dst[i] = '\0';
    else
      break;
  }
}

float ValToTim(int value)
{
   return ((value < -109 ? 129+value : (value < 7 ? (113+value)*5 : (53+value)*10))/10.0);
}

int TimToVal(float value)
{
  int temp;
  if (value>60) {
    temp=136+round((value-60));
  }
  else if (value>2) {
    temp=20+round((value-2.0)*2.0);
  }
  else {
    temp=round(value*10.0);
  }
  return (temp-129);
}

QString getSignedStr(int value)
{
  return value > 0 ? QString("+%1").arg(value) : QString("%1").arg(value);
}

QString getGVarString(int16_t val, bool sign)
{
  if (val >= -10000 && val <= 10000) {
    if (sign)
      return QString("%1%").arg(getSignedStr(val));
    else
      return QString("%1%").arg(val);
  }
  else {
    if (val<0)
      return QObject::tr("-GV%1").arg(-val-10000);
    else
      return QObject::tr("GV%1").arg(val-10000);
  }
}

RawSourceRange RawSource::getRange(const ModelData & model, const GeneralSettings & settings, unsigned int flags) const
{
  RawSourceRange result;

  FirmwareInterface * firmware = GetCurrentFirmware();
  int board = firmware->getBoard();
  bool singleprec = (flags & RANGE_SINGLE_PRECISION);

  if (!singleprec && !IS_ARM(board)) {
    singleprec = true;
  }

  switch (type) {
    case SOURCE_TYPE_TELEMETRY:
      if (singleprec) {
        result.offset = -DBL_MAX;
      }

      switch (index) {
        case TELEMETRY_SOURCE_TX_BATT:
          result.step = 0.1;
          result.decimals = 1;
          result.max = 25.5;
          result.unit = QObject::tr("V");
          break;
        case TELEMETRY_SOURCE_TX_TIME:
          result.step = 1;
          result.max = 24*60 - 1;
          break;
        case TELEMETRY_SOURCE_TIMER1:
        case TELEMETRY_SOURCE_TIMER2:
          result.step = singleprec ? 5 : 1;
          result.max = singleprec ? 255*5 : 60*60;
          result.unit = QObject::tr("s");
          break;
        case TELEMETRY_SOURCE_RSSI_TX:
        case TELEMETRY_SOURCE_RSSI_RX:
          result.max = 100;
          if (singleprec) result.offset = 128;
          break;
        case TELEMETRY_SOURCE_A1_MIN:
        case TELEMETRY_SOURCE_A2_MIN:
        case TELEMETRY_SOURCE_A3_MIN:
        case TELEMETRY_SOURCE_A4_MIN:
          result = model.frsky.channels[index-TELEMETRY_SOURCE_A1_MIN].getRange();
          break;
        case TELEMETRY_SOURCE_A1:
        case TELEMETRY_SOURCE_A2:
        case TELEMETRY_SOURCE_A3:
        case TELEMETRY_SOURCE_A4:
          result = model.frsky.channels[index-TELEMETRY_SOURCE_A1].getRange();
          break;
        case TELEMETRY_SOURCE_ALT:
        case TELEMETRY_SOURCE_ALT_MIN:
        case TELEMETRY_SOURCE_ALT_MAX:
        case TELEMETRY_SOURCE_GPS_ALT:
          result.step = singleprec ? 8 : 1;
          result.min = -500;
          result.max = singleprec ? 1540 : 3000;
          if (firmware->getCapability(Imperial) || settings.imperial) {
            result.step = (result.step * 105) / 32;
            result.min = (result.min * 105) / 32;
            result.max = (result.max * 105) / 32;
            result.unit = QObject::tr("ft");
          }
          else {
            result.unit = QObject::tr("m");
          }
          break;
        case TELEMETRY_SOURCE_T1:
        case TELEMETRY_SOURCE_T1_MAX:
        case TELEMETRY_SOURCE_T2:
        case TELEMETRY_SOURCE_T2_MAX:
          result.min = -30;
          result.max = 225;
          result.unit = QObject::trUtf8("°C");
          break;
        case TELEMETRY_SOURCE_HDG:
          result.step = singleprec ? 2 : 1;
          result.max = 360;
          if (singleprec) result.offset = 256;
          result.unit = QObject::trUtf8("°");
          break;
        case TELEMETRY_SOURCE_RPM:
        case TELEMETRY_SOURCE_RPM_MAX:
          result.step = singleprec ? 50 : 1;
          result.max = singleprec ? 12750 : 30000;
          break;
        case TELEMETRY_SOURCE_FUEL:
          result.max = 100;
          result.unit = QObject::tr("%");
          break;
        case TELEMETRY_SOURCE_ASPEED:
        case TELEMETRY_SOURCE_ASPEED_MAX:
          result.decimals = 1;
          result.step = singleprec ? 2.0 : 0.1;
          result.max = singleprec ? (2*255) : 2000;
          if (firmware->getCapability(Imperial) || settings.imperial) {
            result.step *= 1.150779;
            result.max *= 1.150779;
            result.unit = QObject::tr("mph");
          }
          else {
            result.step *= 1.852;
            result.max *= 1.852;
            result.unit = QObject::tr("km/h");
          }
          break;
        case TELEMETRY_SOURCE_SPEED:
        case TELEMETRY_SOURCE_SPEED_MAX:
          result.step = singleprec ? 2 : 1;
          result.max = singleprec ? (2*255) : 2000;
          if (firmware->getCapability(Imperial) || settings.imperial) {
            result.step *= 1.150779;
            result.max *= 1.150779;
            result.unit = QObject::tr("mph");
          }
          else {
            result.step *= 1.852;
            result.max *= 1.852;
            result.unit = QObject::tr("km/h");
          }
          break;
        case TELEMETRY_SOURCE_VERTICAL_SPEED:
          result.step = 0.1;
          result.min = singleprec ? -12.5 : -300.0;
          result.max = singleprec ? 13.0 : 300.0;
          result.decimals = 1;
          result.unit = QObject::tr("m/s");
          break;
        case TELEMETRY_SOURCE_DTE:
          result.max = 30000;
          break;
        case TELEMETRY_SOURCE_DIST:
        case TELEMETRY_SOURCE_DIST_MAX:
          result.step = singleprec ? 8 : 1;
          result.max = singleprec ? 2040 : 10000;
          result.unit = QObject::tr("m");
          break;
        case TELEMETRY_SOURCE_CELL:
        case TELEMETRY_SOURCE_CELL_MIN:
          result.step = singleprec ? 0.02 : 0.01;
          result.max = 5.1;
          result.decimals = 2;
          result.unit = QObject::tr("V");
          break;
        case TELEMETRY_SOURCE_CELLS_SUM:
        case TELEMETRY_SOURCE_CELLS_MIN:
        case TELEMETRY_SOURCE_VFAS:
        case TELEMETRY_SOURCE_VFAS_MIN:
          result.step = 0.1;
          result.max = singleprec ? 25.5 : 100.0;
          result.decimals = 1;
          result.unit = QObject::tr("V");
          break;
        case TELEMETRY_SOURCE_CURRENT:
        case TELEMETRY_SOURCE_CURRENT_MAX:
          result.step = singleprec ? 0.5 : 0.1;
          result.max = singleprec ? 127.5 : 200.0;
          result.decimals = 1;
          result.unit = QObject::tr("A");
          break;
        case TELEMETRY_SOURCE_CONSUMPTION:
          result.step = singleprec ? 100 : 1;
          result.max = singleprec ? 25500 : 30000;
          result.unit = QObject::tr("mAh");
          break;
        case TELEMETRY_SOURCE_POWER:
        case TELEMETRY_SOURCE_POWER_MAX:
          result.step = singleprec ? 5 : 1;
          result.max = singleprec ? 1275 : 2000;
          result.unit = QObject::tr("W");
          break;
        case TELEMETRY_SOURCE_ACCX:
        case TELEMETRY_SOURCE_ACCY:
        case TELEMETRY_SOURCE_ACCZ:
          result.step = 0.01;
          result.decimals = 2;
          result.max = singleprec ? 2.55 : 10.00;
          result.min = singleprec ? 0 : -10.00;
          result.unit = QObject::tr("g");
          break;
        default:
          result.max = 125;
          break;
      }

      if (singleprec && result.offset==-DBL_MAX) {
        result.offset = result.max - (127*result.step);
      }

      if (flags & (RANGE_DELTA_FUNCTION|RANGE_DELTA_ABS_FUNCTION)) {
        if (singleprec) {
          result.offset = 0;
          result.min = result.step * -127;
          result.max = result.step * 127;
        }
        else {
          result.min = -result.max;
        }
      }
      break;

    case SOURCE_TYPE_GVAR:
      result.max = 1024;
      result.min = -result.max;
      break;

    default:
      result.max = model.getChannelsMax(true);
      result.min = -result.max;
      break;
  }

  if (flags & RANGE_DELTA_ABS_FUNCTION) {
    result.min = 0;
  }

  return result;
}

QString AnalogString(int index)
{
  static const QString sticks[]  = { QObject::tr("Rud"), QObject::tr("Ele"), QObject::tr("Thr"), QObject::tr("Ail") };
  static const QString pots9X[]  = { QObject::tr("P1"), QObject::tr("P2"), QObject::tr("P3") };
  static const QString potsTaranis[] = { QObject::tr("S1"), QObject::tr("S2"), QObject::tr("S3"), QObject::tr("LS"), QObject::tr("RS") };

  if (index < 4)
    return CHECK_IN_ARRAY(sticks, index);
  else
    return (IS_TARANIS(GetEepromInterface()->getBoard()) ? CHECK_IN_ARRAY(potsTaranis, index-4) : CHECK_IN_ARRAY(pots9X, index-4));
}

QString RotaryEncoderString(int index)
{
  static const QString rotary[]  = { QObject::tr("REa"), QObject::tr("REb") };
  return CHECK_IN_ARRAY(rotary, index);
}

QString RawSource::toString(const ModelData & model)
{
  static const QString trims[] = {
    QObject::tr("TrmR"), QObject::tr("TrmE"), QObject::tr("TrmT"), QObject::tr("TrmA")
  };

  static const QString telemetry[] = {
    QObject::tr("Batt"), QObject::tr("Time"), QObject::tr("Timer1"), QObject::tr("Timer2"),
    QObject::tr("SWR"), QObject::tr("RSSI Tx"), QObject::tr("RSSI Rx"),
    QObject::tr("A1"), QObject::tr("A2"), QObject::tr("A3"), QObject::tr("A4"),
    QObject::tr("Alt"), QObject::tr("Rpm"), QObject::tr("Fuel"), QObject::tr("T1"), QObject::tr("T2"),
    QObject::tr("Speed"), QObject::tr("Dist"), QObject::tr("GPS Alt"),
    QObject::tr("Cell"), QObject::tr("Cells"), QObject::tr("Vfas"), QObject::tr("Curr"), QObject::tr("Cnsp"), QObject::tr("Powr"),
    QObject::tr("AccX"), QObject::tr("AccY"), QObject::tr("AccZ"),
    QObject::tr("Hdg "), QObject::tr("VSpd"), QObject::tr("AirSpeed"), QObject::tr("dTE"),
    QObject::tr("A1-"),  QObject::tr("A2-"), QObject::tr("A3-"),  QObject::tr("A4-"),
    QObject::tr("Alt-"), QObject::tr("Alt+"), QObject::tr("Rpm+"), QObject::tr("T1+"), QObject::tr("T2+"), QObject::tr("Speed+"), QObject::tr("Dist+"), QObject::tr("AirSpeed+"),
    QObject::tr("Cell-"), QObject::tr("Cells-"), QObject::tr("Vfas-"), QObject::tr("Curr+"), QObject::tr("Powr+"),
    QObject::tr("ACC"), QObject::tr("GPS Time"),
  };

  static const QString logicalSwitches[] = {
    QObject::tr("L1"), QObject::tr("L2"), QObject::tr("L3"), QObject::tr("L4"), QObject::tr("L5"), QObject::tr("L6"), QObject::tr("L7"), QObject::tr("L8"), QObject::tr("L9"), QObject::tr("L10"),
    QObject::tr("L11"), QObject::tr("L12"), QObject::tr("L13"), QObject::tr("L14"), QObject::tr("L15"), QObject::tr("L16"), QObject::tr("L17"), QObject::tr("L18"), QObject::tr("L19"), QObject::tr("L20"),
    QObject::tr("L21"), QObject::tr("L22"), QObject::tr("L23"), QObject::tr("L24"), QObject::tr("L25"), QObject::tr("L26"), QObject::tr("L27"), QObject::tr("L28"), QObject::tr("L29"), QObject::tr("L30"),
    QObject::tr("L31"), QObject::tr("L32")
  };
  
  if (index<0) {
    return QObject::tr("----");
  }
  switch (type) {
    case SOURCE_TYPE_VIRTUAL_INPUT:
    {
      QString result = QObject::tr("[I%1]").arg(index+1);
      if (strlen(model.inputNames[index]) > 0) {
        result += QString(model.inputNames[index]);
      }
      return result;
    }
    case SOURCE_TYPE_LUA_OUTPUT:
      return QObject::tr("LUA%1%2").arg(index/16+1).arg(QChar('a'+index%16));
    case SOURCE_TYPE_STICK:
      return AnalogString(index);
    case SOURCE_TYPE_TRIM:
      return CHECK_IN_ARRAY(trims, index);
    case SOURCE_TYPE_ROTARY_ENCODER:
      return RotaryEncoderString(index);
    case SOURCE_TYPE_MAX:
      return QObject::tr("MAX");
    case SOURCE_TYPE_SWITCH:
      return (IS_TARANIS(GetEepromInterface()->getBoard()) ? CHECK_IN_ARRAY(switchesX9D, index) : CHECK_IN_ARRAY(switches9X, index));
    case SOURCE_TYPE_CUSTOM_SWITCH:
      return logicalSwitches[index];
    case SOURCE_TYPE_CYC:
      return QObject::tr("CYC%1").arg(index+1);
    case SOURCE_TYPE_PPM:
      return QObject::tr("TR%1").arg(index+1);
    case SOURCE_TYPE_CH:
      return QObject::tr("CH%1").arg(index+1);
    case SOURCE_TYPE_TELEMETRY:
      return CHECK_IN_ARRAY(telemetry, index);
    case SOURCE_TYPE_GVAR:
      return QObject::tr("GV%1").arg(index+1);      
    default:
      return QObject::tr("----");
  }
}

QString SwitchUp(const char sw)
{
  const char result[] = {'S', sw, upArrow[0], upArrow[1], upArrow[2], 0};
  return QString::fromUtf8(result);
}

QString SwitchDn(const char sw)
{
  const char result[] = {'S', sw, downArrow[0], downArrow[1], downArrow[2], 0};
  return QString::fromUtf8(result);
}

QString RawSwitch::toString()
{
  static const QString switches9X[] = {
    QString("THR"), QString("RUD"), QString("ELE"),
    QString("ID0"), QString("ID1"), QString("ID2"),
    QString("AIL"), QString("GEA"), QString("TRN")
  };

  static const QString switchesX9D[] = {
    SwitchUp('A'), QString::fromUtf8("SA-"), SwitchDn('A'),
    SwitchUp('B'), QString::fromUtf8("SB-"), SwitchDn('B'),
    SwitchUp('C'), QString::fromUtf8("SC-"), SwitchDn('C'),
    SwitchUp('D'), QString::fromUtf8("SD-"), SwitchDn('D'),
    SwitchUp('E'), QString::fromUtf8("SE-"), SwitchDn('E'),
    SwitchUp('F'), SwitchDn('F'),
    SwitchUp('G'), QString::fromUtf8("SG-"), SwitchDn('G'),
    SwitchUp('H'), SwitchDn('H'),
  };

  static const QString logicalSwitches[] = {
    QObject::tr("L1"), QObject::tr("L2"), QObject::tr("L3"), QObject::tr("L4"), QObject::tr("L5"), QObject::tr("L6"), QObject::tr("L7"), QObject::tr("L8"), QObject::tr("L9"), QObject::tr("L10"),
    QObject::tr("L11"), QObject::tr("L12"), QObject::tr("L13"), QObject::tr("L14"), QObject::tr("L15"), QObject::tr("L16"), QObject::tr("L17"), QObject::tr("L18"), QObject::tr("L19"), QObject::tr("L20"),
    QObject::tr("L21"), QObject::tr("L22"), QObject::tr("L23"), QObject::tr("L24"), QObject::tr("L25"), QObject::tr("L26"), QObject::tr("L27"), QObject::tr("L28"), QObject::tr("L29"), QObject::tr("L30"),
    QObject::tr("L31"), QObject::tr("L32")
  };

  static const QString flightModes[] = {
    QObject::tr("FM0"), QObject::tr("FM1"), QObject::tr("FM2"), QObject::tr("FM3"), QObject::tr("FM4"), QObject::tr("FM5"), QObject::tr("FM6"), QObject::tr("FM7"), QObject::tr("FM8")
  };

  static const QString multiposPots[] = {
    QObject::tr("S11"), QObject::tr("S12"), QObject::tr("S13"), QObject::tr("S14"), QObject::tr("S15"), QObject::tr("S16"),
    QObject::tr("S21"), QObject::tr("S22"), QObject::tr("S23"), QObject::tr("S24"), QObject::tr("S25"), QObject::tr("S26"),
    QObject::tr("S31"), QObject::tr("S32"), QObject::tr("S33"), QObject::tr("S34"), QObject::tr("S35"), QObject::tr("S36")
  };

  static const QString trimsSwitches[] = {
    QObject::tr("RudTrim Left"), QObject::tr("RudTrim Right"),
    QObject::tr("EleTrim Down"), QObject::tr("EleTrim Up"),
    QObject::tr("ThrTrim Down"), QObject::tr("ThrTrim Up"),
    QObject::tr("AilTrim Left"), QObject::tr("AilTrim Right")
  };

  static const QString rotaryEncoders[] = {
    QObject::tr("REa"), QObject::tr("REb")
  };

  static const QString timerModes[] = {
    QObject::tr("OFF"), QObject::tr("ON"),
    QObject::tr("THs"), QObject::tr("TH%"), QObject::tr("THt")
  };

  if (index < 0) {
    return QString("!") + RawSwitch(type, -index).toString();
  }
  else {
    switch(type) {
      case SWITCH_TYPE_SWITCH:
        if (IS_TARANIS(GetEepromInterface()->getBoard()))
          return CHECK_IN_ARRAY(switchesX9D, index-1);
        else
          return CHECK_IN_ARRAY(switches9X, index-1);
      case SWITCH_TYPE_VIRTUAL:
        return CHECK_IN_ARRAY(logicalSwitches, index-1);
      case SWITCH_TYPE_MULTIPOS_POT:
        return CHECK_IN_ARRAY(multiposPots, index-1);
      case SWITCH_TYPE_TRIM:
        return CHECK_IN_ARRAY(trimsSwitches, index-1);
      case SWITCH_TYPE_ROTARY_ENCODER:
        return CHECK_IN_ARRAY(rotaryEncoders, index-1);
      case SWITCH_TYPE_ON:
        return QObject::tr("ON");
      case SWITCH_TYPE_OFF:
        return QObject::tr("OFF");
      case SWITCH_TYPE_ONE:
        return QObject::tr("One");
      case SWITCH_TYPE_FLIGHT_MODE:
        return CHECK_IN_ARRAY(flightModes, index-1);
      case SWITCH_TYPE_NONE:
        return QObject::tr("----");
      case SWITCH_TYPE_TIMER_MODE:
        return CHECK_IN_ARRAY(timerModes, index);
      default:
        return QObject::tr("???");
    }
  }
}

QString CurveReference::toString()
{
  if (value == 0) {
    return "----";
  }
  else {
    switch(type) {
      case CURVE_REF_DIFF:
        return QObject::tr("Diff(%1)").arg(getGVarString(value));
      case CURVE_REF_EXPO:
        return QObject::tr("Expo(%1)").arg(getGVarString(value));
      case CURVE_REF_FUNC:
        return QObject::tr("Function(%1)").arg(QString("x>0" "x<0" "|x|" "f>0" "f<0" "|f|").mid(3*(value-1), 3));
      default:
        return QString(value > 0 ? QObject::tr("Curve(%1)") : QObject::tr("!Curve(%1)")).arg(abs(value));
    }
  }
}

CSFunctionFamily LogicalSwitchData::getFunctionFamily()
{
  if (func == LS_FN_STAY)
    return LS_FAMILY_STAY;
  else if (func == LS_FN_TIMER)
    return LS_FAMILY_TIMER;
  else if (func == LS_FN_STICKY)
    return LS_FAMILY_STICKY;
  else if (func < LS_FN_AND || func > LS_FN_ELESS)
    return LS_FAMILY_VOFS;
  else if (func < LS_FN_EQUAL)
    return LS_FAMILY_VBOOL;
  else
    return LS_FAMILY_VCOMP;
}

unsigned int LogicalSwitchData::getRangeFlags()
{
  if (func == LS_FN_DPOS)
    return RANGE_DELTA_FUNCTION;
  else if (func == LS_FN_DAPOS)
    return RANGE_DELTA_ABS_FUNCTION;
  else
    return 0;
}

QString LogicalSwitchData::funcToString()
{
  switch (func) {
    case LS_FN_OFF:
      return QObject::tr("---");
    case LS_FN_VPOS:
      return QObject::tr("a>x");
    case LS_FN_VNEG:
      return QObject::tr("a<x");
    case LS_FN_APOS:
      return QObject::tr("|a|>x");
    case LS_FN_ANEG:
      return QObject::tr("|a|<x");
    case LS_FN_AND:
      return QObject::tr("AND");
    case LS_FN_OR:
      return QObject::tr("OR");
    case LS_FN_XOR:
      return QObject::tr("XOR");
    case LS_FN_EQUAL:
      return QObject::tr("a=b");
    case LS_FN_NEQUAL:
      return QObject::tr("a!=b");
    case LS_FN_GREATER:
      return QObject::tr("a>b");
    case LS_FN_LESS:
      return QObject::tr("a<b");
    case LS_FN_EGREATER:
      return QObject::tr("a>=b");
    case LS_FN_ELESS:
      return QObject::tr("a<=b");
    case LS_FN_DPOS:
      return QObject::tr("d>=x");
    case LS_FN_DAPOS:
      return QObject::tr("|d|>=x");
    case LS_FN_VEQUAL:
      return QObject::tr("a=x");
    case LS_FN_VALMOSTEQUAL:
      return QObject::tr("a~x");
    case LS_FN_TIMER:
      return QObject::tr("Timer");
    case LS_FN_STICKY:
      return QObject::tr("Sticky");
    case LS_FN_STAY:
      return QObject::tr("Edge");
    default:
      return QObject::tr("Unknown");
  }
}

QString LogicalSwitchData::toString(const ModelData & model, const GeneralSettings & settings)
{
  QString result = "";

  if (!func)
    return result;

  if (andsw!=0) {
    result +="( ";
  }
  switch (getFunctionFamily()) {
    case LS_FAMILY_STAY:
      result += QObject::tr("Edge(%1, [%2:%3])").arg(RawSwitch(val1).toString()).arg(ValToTim(val2)).arg(ValToTim(val2+val3));
      break;
    case LS_FAMILY_STICKY:
      result += QObject::tr("Sticky(%1, %2)").arg(RawSwitch(val1).toString()).arg(RawSwitch(val2).toString());
      break;
    case LS_FAMILY_TIMER:
      result += QObject::tr("Timer(%1, %2)").arg(ValToTim(val1)).arg(ValToTim(val2));
      break;
    case LS_FAMILY_VOFS: {
      RawSource source = RawSource(val1);
      RawSourceRange range = source.getRange(model, settings);
      QString res;
      if (val1)
        res += source.toString(model);
      else
        res += "0";
      res.remove(" ");
      if (func == LS_FN_APOS || func == LS_FN_ANEG)
        res = "|" + res + "|";
      else if (func == LS_FN_DAPOS)
        res = "|d(" + res + ")|";
      else if (func == LS_FN_DPOS) result = "d(" + res + ")";
      result += res;

      if (func == LS_FN_APOS || func == LS_FN_VPOS || func == LS_FN_DPOS || func == LS_FN_DAPOS)
        result += " &gt; ";
      else if (func == LS_FN_ANEG || func == LS_FN_VNEG)
        result += " &lt; ";
      else if (func == LS_FN_VALMOSTEQUAL)
        result += " ~ ";
      else
        result += " missing";
      result += QString::number(range.step * (val2 /*TODO+ source.getRawOffset(model)*/) + range.offset);
      break;
    }
    case LS_FAMILY_VBOOL:
      result += RawSwitch(val1).toString();
      switch (func) {
        case LS_FN_AND:
          result += " AND ";
          break;
        case LS_FN_OR:
          result += " OR ";
          break;
        case LS_FN_XOR:
          result += " XOR ";
          break;
       default:
          result += " bar ";
          break;
      }
      result += RawSwitch(val2).toString();
      break;

    case LS_FAMILY_VCOMP:
      if (val1)
        result += RawSource(val1).toString(model);
      else
        result += "0";
      switch (func) {
        case LS_FN_EQUAL:
        case LS_FN_VEQUAL:
          result += " = ";
          break;
        case LS_FN_NEQUAL:
          result += " != ";
          break;
        case LS_FN_GREATER:
          result += " &gt; ";
          break;
        case LS_FN_LESS:
          result += " &lt; ";
          break;
        case LS_FN_EGREATER:
          result += " &gt;= ";
          break;
        case LS_FN_ELESS:
          result += " &lt;= ";
          break;
        default:
          result += " foo ";
          break;
      }
      if (val2)
        result += RawSource(val2).toString(model);
      else
        result += "0";
      break;
  }

  if (andsw!=0) {
    result +=" ) AND ";
    result += RawSwitch(andsw).toString();
  }

  if (GetCurrentFirmware()->getCapability(LogicalSwitchesExt)) {
    if (duration)
      result += QObject::tr(" Duration (%1s)").arg(duration/10.0);
    if (delay)
      result += QObject::tr(" Delay (%1s)").arg(delay/10.0);
  }

  return result;
}

void FuncSwData::clear()
{
  memset(this, 0, sizeof(FuncSwData));
  if (!GetCurrentFirmware()->getCapability(SafetyChannelCustomFunction)) {
    func = FuncTrainer;
  }
}

QString FuncSwData::funcToString()
{
  ModelData model;
  if (func >= FuncOverrideCH1 && func <= FuncOverrideCH32)
    return QObject::tr("Override %1").arg(RawSource(SOURCE_TYPE_CH, func).toString(model));
  else if (func == FuncTrainer)
    return QObject::tr("Trainer");
  else if (func == FuncTrainerRUD)
    return QObject::tr("Trainer RUD");
  else if (func == FuncTrainerELE)
    return QObject::tr("Trainer ELE");
  else if (func == FuncTrainerTHR)
    return QObject::tr("Trainer THR");
  else if (func == FuncTrainerAIL)
    return QObject::tr("Trainer AIL");
  else if (func == FuncInstantTrim)
    return QObject::tr("Instant Trim");
  else if (func == FuncPlaySound)
    return QObject::tr("Play Sound");
  else if (func == FuncPlayHaptic)
    return QObject::tr("Play Haptic");
  else if (func == FuncReset)
    return QObject::tr("Reset");
  else if (func >= FuncSetTimer1 && func <= FuncSetTimer2)
    return QObject::tr("Set Timer %1").arg(func-FuncSetTimer1+1);
  else if (func == FuncVario)
    return QObject::tr("Vario");
  else if (func == FuncPlayPrompt)
    return QObject::tr("Play Track");
  else if (func == FuncPlayBoth)
    return QObject::tr("Play Both");
  else if (func == FuncPlayValue)
    return QObject::tr("Play Value");
  else if (func == FuncPlayScript)
    return QObject::tr("Play Script");
  else if (func == FuncLogs)
    return QObject::tr("SD Logs");
  else if (func == FuncVolume)
    return QObject::tr("Volume");
  else if (func == FuncBacklight)
    return QObject::tr("Backlight");
  else if (func == FuncBackgroundMusic)
    return QObject::tr("Background Music");
  else if (func == FuncBackgroundMusicPause)
    return QObject::tr("Background Music Pause");
  else if (func >= FuncAdjustGV1 && func <= FuncAdjustGVLast)
    return QObject::tr("Adjust GV%1").arg(func-FuncAdjustGV1+1);
  else {
    return QString("???"); // Highlight unknown functions with output of question marks.(BTW should not happen that we do not know what a function is)
  }
}

QString FuncSwData::paramToString()
{
  QStringList qs;
  if (func <= FuncInstantTrim) {
    return QString("%1").arg(param);
  }
  else if (func==FuncPlaySound) {
    qs <<"Beep 1" << "Beep 2" << "Beep 3" << "Warn1" << "Warn2" << "Cheep" << "Ratata" << "Tick" << "Siren" << "Ring" ;
    qs << "SciFi" << "Robot" << "Chirp" << "Tada" << "Crickt"  << "AlmClk"  ;
    if (param>=0 && param<(int)qs.count())
      return qs.at(param);
    else
      return QObject::tr("<font color=red><b>Inconsistent parameter</b></font>");
  }
  else if (func==FuncPlayHaptic) {
    qs << "0" << "1" << "2" << "3";
    if (param>=0 && param<(int)qs.count())
      return qs.at(param);
    else
      return QObject::tr("<font color=red><b>Inconsistent parameter</b></font>");
  }
  else if (func==FuncReset) {
    qs.append( QObject::tr("Timer1"));
    qs.append( QObject::tr("Timer2"));
    qs.append( QObject::tr("All"));
    qs.append( QObject::tr("Telemetry"));
    if (param>=0 && param<(int)qs.count())
      return qs.at(param);
    else
      return QObject::tr("<font color=red><b>Inconsistent parameter</b></font>");
  }
  else if ((func==FuncVolume)|| (func==FuncPlayValue)) {
    RawSource item(param);
    ModelData model;
    return item.toString(model);
  }
  else if ((func==FuncPlayPrompt) || (func==FuncPlayBoth)) {
    if ( GetCurrentFirmware()->getCapability(VoicesAsNumbers)) {
      return QString("%1").arg(param);
    } else {
      return paramarm;
    }
  }
  else if ((func>FuncBackgroundMusicPause) && (func<FuncCount)) {
    ModelData model;
    switch (adjustMode) {
      case 0:
        return QObject::tr("Value ")+QString("%1").arg(param);
        break;
      case 1:
        return RawSource(param).toString(model);
        break;
      case 2:
        return RawSource(param).toString(model);
        break;
      case 3:
        if (param==0) {
          return QObject::tr("Decr:")+QString(" -1");
        }
        else {
          return QObject::tr("Incr:")+QString(" +1");
        }
        break;
      default:
        return "";
    }
  }
  return "";
}

QString FuncSwData::repeatToString()
{
  if (repeatParam==0) {
    return QObject::tr("No repeat");
  }
  else {
    unsigned int step = IS_ARM(GetEepromInterface()->getBoard()) ? 5 : 10;
    return QObject::tr("%1 sec").arg(step*repeatParam);
  }
}

QString LimitData::minToString()
{
  return QString::number((qreal)min/10);
}

QString LimitData::maxToString()
{
  return QString::number((qreal)max/10);
}

QString LimitData::offsetToString()
{
  return QString::number((qreal)offset/10, 'f', 1);
}

void LimitData::clear()
{
  memset(this, 0, sizeof(LimitData));
  min = -1000;
  max = +1000;
}

GeneralSettings::GeneralSettings()
{
  memset(this, 0, sizeof(GeneralSettings));

  contrast  = 25;
  vBatWarn  = 90;

  for (int i=0; i<NUM_STICKS+C9X_NUM_POTS; ++i) {
    calibMid[i]     = 0x200;
    calibSpanNeg[i] = 0x180;
    calibSpanPos[i] = 0x180;
  }

  BoardEnum board = GetEepromInterface()->getBoard();
  if (IS_TARANIS(board)) {
    potsType[0] = 1;
    potsType[1] = 1;
  }

  if (IS_ARM(board)) {
    speakerVolume = 12;
  }

  templateSetup = g.profile[g.id()].channelOrder();
  stickMode = g.profile[g.id()].defaultMode();

  QString t_calib=g.profile[g.id()].stickPotCalib();
  int potsnum=GetCurrentFirmware()->getCapability(Pots);
  if (t_calib.isEmpty()) {
    return;
  }
  else {
    QString t_trainercalib=g.profile[g.id()].trainerCalib();
    int8_t t_vBatCalib=(int8_t)g.profile[g.id()].vBatCalib();
    int8_t t_currentCalib=(int8_t)g.profile[g.id()].currentCalib();
    int8_t t_PPM_Multiplier=(int8_t)g.profile[g.id()].ppmMultiplier();
    uint8_t t_stickMode=(uint8_t)g.profile[g.id()].gsStickMode();
    uint8_t t_vBatWarn=(uint8_t)g.profile[g.id()].vBatWarn();
    QString t_DisplaySet=g.profile[g.id()].display();
    QString t_BeeperSet=g.profile[g.id()].beeper();
    QString t_HapticSet=g.profile[g.id()].haptic();
    QString t_SpeakerSet=g.profile[g.id()].speaker();
    QString t_CountrySet=g.profile[g.id()].countryCode();

    if ((t_calib.length()==(NUM_STICKS+potsnum)*12) && (t_trainercalib.length()==16)) {
      QString Byte;
      int16_t byte16;
      bool ok;
      for (int i=0; i<(NUM_STICKS+potsnum); i++) {
        Byte=t_calib.mid(i*12,4);
        byte16=(int16_t)Byte.toInt(&ok,16);
        if (ok)
          calibMid[i]=byte16;
        Byte=t_calib.mid(4+i*12,4);
        byte16=(int16_t)Byte.toInt(&ok,16);
        if (ok)
          calibSpanNeg[i]=byte16;
        Byte=t_calib.mid(8+i*12,4);
        byte16=(int16_t)Byte.toInt(&ok,16);
        if (ok)
          calibSpanPos[i]=byte16;
      }
      for (int i=0; i<4; i++) {
        Byte=t_trainercalib.mid(i*4,4);
        byte16=(int16_t)Byte.toInt(&ok,16);
        if (ok)
          trainer.calib[i]=byte16;
      }
      currentCalib=t_currentCalib;
      vBatCalib=t_vBatCalib;
      vBatWarn=t_vBatWarn;
      PPM_Multiplier=t_PPM_Multiplier;
      stickMode = t_stickMode;
    }
    if ((t_DisplaySet.length()==6) && (t_BeeperSet.length()==4) && (t_HapticSet.length()==6) && (t_SpeakerSet.length()==6)) {
      uint8_t byte8u;
      int8_t byte8;
      bool ok;
      byte8=(int8_t)t_DisplaySet.mid(0,2).toInt(&ok,16);
      if (ok)
        optrexDisplay=(byte8==1 ? true : false);
      byte8u=(uint8_t)t_DisplaySet.mid(2,2).toUInt(&ok,16);
      if (ok)
        contrast=byte8u;
      byte8u=(uint8_t)t_DisplaySet.mid(4,2).toUInt(&ok,16);
      if (ok)
        backlightBright=byte8u;
      byte8=(int8_t)t_BeeperSet.mid(0,2).toUInt(&ok,16);
      if (ok)
        beeperMode=(BeeperMode)byte8;
      byte8=(int8_t)t_BeeperSet.mid(2,2).toInt(&ok,16);
      if (ok)
        beeperLength=byte8;
      byte8=(int8_t)t_HapticSet.mid(0,2).toUInt(&ok,16);
      if (ok)
        hapticMode=(BeeperMode)byte8;
      byte8=(int8_t)t_HapticSet.mid(2,2).toInt(&ok,16);
      if (ok)
        hapticStrength=byte8;
      byte8=(int8_t)t_HapticSet.mid(4,2).toInt(&ok,16);
      if (ok)
        hapticLength=byte8;
      byte8u=(uint8_t)t_SpeakerSet.mid(0,2).toUInt(&ok,16);
      if (ok)
        speakerMode=byte8u;
      byte8u=(uint8_t)t_SpeakerSet.mid(2,2).toUInt(&ok,16);
      if (ok)
        speakerPitch=byte8u;
      byte8u=(uint8_t)t_SpeakerSet.mid(4,2).toUInt(&ok,16);
      if (ok)
        speakerVolume=byte8u;
      if (t_CountrySet.length()==6) {
        byte8u=(uint8_t)t_CountrySet.mid(0,2).toUInt(&ok,16);
        if (ok)
          countryCode=byte8u;
        byte8u=(uint8_t)t_CountrySet.mid(2,2).toUInt(&ok,16);
        if (ok)
          imperial=byte8u;
        QString chars=t_CountrySet.mid(4,2);
        ttsLanguage[0]=chars[0].toAscii();
        ttsLanguage[1]=chars[1].toAscii();
      }
    }
  }
}

int GeneralSettings::getDefaultStick(unsigned int channel) const
{
  if (channel >= NUM_STICKS)
    return -1;
  else
    return chout_ar[4*templateSetup + channel] - 1;
}

RawSource GeneralSettings::getDefaultSource(unsigned int channel) const
{
  int stick = getDefaultStick(channel);
  if (stick >= 0)
    return RawSource(SOURCE_TYPE_STICK, stick);
  else
    return RawSource(SOURCE_TYPE_NONE);
}

int GeneralSettings::getDefaultChannel(unsigned int stick) const
{
  for (int i=0; i<4; i++){
    if (getDefaultStick(i) == (int)stick)
      return i;
  }
  return -1;
}

float FrSkyChannelData::getRatio() const
{
  if (type==0 || type==1 || type==2)
    return float(ratio << multiplier) / 10.0;
  else
    return ratio << multiplier;
}

RawSourceRange FrSkyChannelData::getRange() const
{
  RawSourceRange result;
  float ratio = getRatio();
  if (type==0 || type==1 || type==2)
    result.decimals = 2;
  else
    result.decimals = 0;
  result.step = ratio / 255;
  result.min = offset * result.step;
  result.max = ratio + result.min;
  result.unit = QObject::tr("V");
  return result;
}

void FrSkyData::clear()
{
  memset(this, 0, sizeof(FrSkyData));
  rssiAlarms[0].clear(2, 45);
  rssiAlarms[1].clear(3, 42);
  varioSource = 2/*VARIO*/;
  blades = 2;
}

ModelData::ModelData()
{
  clear();
}

ModelData::ModelData(const ModelData & src)
{
  *this = src;
}

ModelData & ModelData::operator = (const ModelData & src)
{
  memcpy(this, &src, sizeof(ModelData));
  return *this;
}

ExpoData * ModelData::insertInput(const int idx)
{
  memmove(&expoData[idx+1], &expoData[idx], (C9X_MAX_EXPOS-(idx+1))*sizeof(ExpoData));
  expoData[idx].clear();
  return &expoData[idx];
}

bool ModelData::isInputValid(const unsigned int idx) const
{
  for (int i=0; i<C9X_MAX_EXPOS; i++) {
    const ExpoData * expo = &expoData[i];
    if (expo->mode == 0) break;
    if (expo->chn == idx)
      return true;
  }
  return false;
}

void ModelData::removeInput(const int idx)
{
  unsigned int chn = expoData[idx].chn;

  memmove(&expoData[idx], &expoData[idx+1], (C9X_MAX_EXPOS-(idx+1))*sizeof(ExpoData));
  expoData[C9X_MAX_EXPOS-1].clear();

  //also remove input name if removing last line for this input
  bool found = false;
  for (int i=0; i<C9X_MAX_EXPOS; i++) {
    if (expoData[i].mode==0) continue;
    if (expoData[i].chn==chn) {
      found = true;
      break;
    }
  }
  if (!found) inputNames[chn][0] = 0;
}

void ModelData::clearInputs()
{
  for (int i=0; i<C9X_MAX_EXPOS; i++)
    expoData[i].clear();

  //clear all input names
  if (GetCurrentFirmware()->getCapability(VirtualInputs)) {
    for (int i=0; i<C9X_MAX_INPUTS; i++) {
      inputNames[i][0] = 0;
    }
  }
}

void ModelData::clearMixes()
{
  for (int i=0; i<C9X_MAX_MIXERS; i++)
    mixData[i].clear();
}

void ModelData::clear()
{
  memset(this, 0, sizeof(ModelData));
  moduleData[0].channelsCount = 8;
  moduleData[1].channelsStart = 0;
  moduleData[1].channelsCount = 8;
  moduleData[0].ppmDelay = 300;
  moduleData[1].ppmDelay = 300;
  moduleData[2].ppmDelay = 300;
  int board = GetEepromInterface()->getBoard();
  if (IS_TARANIS(board)) {
    moduleData[0].RFprotocol=PXX_XJT_X16;
    moduleData[1].RFprotocol=OFF;
  }
  else {
    moduleData[0].RFprotocol=PPM;
    moduleData[1].RFprotocol=OFF;      
  }
  for (int i=0; i<C9X_MAX_FLIGHT_MODES; i++) {
    flightModeData[i].clear();
  }
  clearInputs();
  clearMixes();
  for (int i=0; i<C9X_NUM_CHNOUT; i++)
    limitData[i].clear();
  for (int i=0; i<NUM_STICKS; i++)
    expoData[i].clear();
  for (int i=0; i<C9X_NUM_CSW; i++)
    customSw[i].clear();
  for (int i=0; i<C9X_MAX_CUSTOM_FUNCTIONS; i++)
    funcSw[i].clear();
  for (int i=0; i<C9X_MAX_CURVES; i++)
    curves[i].clear(5);
  for (int i=0; i<2; i++)
    timers[i].clear();
  swashRingData.clear();
  frsky.clear();
}

bool ModelData::isempty()
{
  return !used;
}

void ModelData::setDefaultInputs(const GeneralSettings & settings)
{
  if (IS_TARANIS(GetEepromInterface()->getBoard())) {
    for (int i=0; i<NUM_STICKS; i++) {
      ExpoData * expo = &expoData[i];
      expo->chn = i;
      expo->mode = INPUT_MODE_BOTH;
      expo->srcRaw = settings.getDefaultSource(i);
      expo->weight = 100;
      strncpy(inputNames[i], expo->srcRaw.toString(*this).toLatin1().constData(), sizeof(inputNames[i])-1);
    }
  }
}

void ModelData::setDefaultMixes(const GeneralSettings & settings)
{
  if (IS_TARANIS(GetEepromInterface()->getBoard())) {
    setDefaultInputs(settings);
  }

  for (int i=0; i<NUM_STICKS; i++) {
    MixData * mix = &mixData[i];
    mix->destCh = i+1;
    mix->weight = 100;
    if (IS_TARANIS(GetEepromInterface()->getBoard())) {
      mix->srcRaw = RawSource(SOURCE_TYPE_VIRTUAL_INPUT, i);
    }
    else {
      mix->srcRaw = RawSource(SOURCE_TYPE_STICK, i);
    }
  }
}

void ModelData::setDefaultValues(unsigned int id, const GeneralSettings & settings)
{
  clear();
  used = true;
  sprintf(name, "MODEL%02d", id+1);
  modelId = id+1;
  setDefaultMixes(settings);
}

int ModelData::getTrimValue(int phaseIdx, int trimIdx)
{
  int result = 0;
  for (int i=0; i<C9X_MAX_FLIGHT_MODES; i++) {
    FlightModeData & phase = flightModeData[phaseIdx];
    if (phase.trimMode[trimIdx] < 0) {
      return result;
    }
    else {
      if (phase.trimRef[trimIdx] == phaseIdx || phaseIdx == 0) {
        return result + phase.trim[trimIdx];
      }
      else {
        phaseIdx = phase.trimRef[trimIdx];
        if (phase.trimMode[trimIdx] == 0)
          result = 0;
        else
          result += phase.trim[trimIdx];
      }
    }
  }
  return 0;
}

bool ModelData::isGVarLinked(int phaseIdx, int gvarIdx)
{
  return flightModeData[phaseIdx].gvars[gvarIdx] > 1024;
}

int ModelData::getGVarValue(int phaseIdx, int gvarIdx)
{
  int idx = flightModeData[phaseIdx].gvars[gvarIdx];
  for (int i=0; idx>1024 && i<C9X_MAX_FLIGHT_MODES; i++) {
    int nextPhase = idx - 1025;
    if (nextPhase >= phaseIdx) nextPhase += 1;
    phaseIdx = nextPhase;
    idx = flightModeData[phaseIdx].gvars[gvarIdx];
  }
  return idx;
}

void ModelData::setTrimValue(int phaseIdx, int trimIdx, int value)
{
  for (uint8_t i=0; i<C9X_MAX_FLIGHT_MODES; i++) {
    FlightModeData & phase = flightModeData[phaseIdx];
    int mode = phase.trimMode[trimIdx];
    int p = phase.trimRef[trimIdx];
    int & trim = phase.trim[trimIdx];
    if (mode < 0)
      return;
    if (p == phaseIdx || phaseIdx == 0) {
      trim = value;
      break;;
    }
    else if (mode == 0) {
      phaseIdx = p;
    }
    else {
      trim = value - getTrimValue(p, trimIdx);
      if (trim < -500)
        trim = -500;
      if (trim > 500)
        trim = 500;
      break;
    }
  }
}

void ModelData::removeGlobalVar(int & var)
{
  if (var >= 126 && var <= 130)
    var = flightModeData[0].gvars[var-126];
  else if (var <= -126 && var >= -130)
    var = - flightModeData[0].gvars[-126-var];
}

ModelData ModelData::removeGlobalVars()
{
  ModelData result = *this;

  for (int i=0; i<C9X_MAX_MIXERS; i++) {
    removeGlobalVar(mixData[i].weight);
    removeGlobalVar(mixData[i].curve.value);
    removeGlobalVar(mixData[i].sOffset);
  }

  for (int i=0; i<C9X_MAX_EXPOS; i++) {
    removeGlobalVar(expoData[i].weight);
    removeGlobalVar(expoData[i].curve.value);
  }

  return result;
}

int ModelData::getChannelsMax(bool forceExtendedLimits) const
{
  if (forceExtendedLimits || extendedLimits)
    return IS_TARANIS(GetCurrentFirmware()->getBoard()) ? 150 : 125;
  else
    return 100;
}

QList<EEPROMInterface *> eepromInterfaces;
void RegisterEepromInterfaces()
{
  eepromInterfaces.push_back(new OpenTxEepromInterface(BOARD_STOCK));
  eepromInterfaces.push_back(new OpenTxEepromInterface(BOARD_M128));
  eepromInterfaces.push_back(new OpenTxEepromInterface(BOARD_GRUVIN9X));
  eepromInterfaces.push_back(new OpenTxEepromInterface(BOARD_SKY9X));
  eepromInterfaces.push_back(new OpenTxEepromInterface(BOARD_9XRPRO));
  eepromInterfaces.push_back(new OpenTxEepromInterface(BOARD_TARANIS));
  eepromInterfaces.push_back(new OpenTxEepromInterface(BOARD_TARANIS_PLUS));  
  eepromInterfaces.push_back(new Gruvin9xInterface(BOARD_STOCK));
  eepromInterfaces.push_back(new Gruvin9xInterface(BOARD_GRUVIN9X));
  eepromInterfaces.push_back(new Ersky9xInterface());
  //eepromInterfaces.push_back(new Th9xInterface());
  eepromInterfaces.push_back(new Er9xInterface());
}

void UnregisterEepromInterfaces()
{
  foreach(EEPROMInterface * intf, eepromInterfaces) {
    // qDebug() << "UnregisterEepromInterfaces(): deleting " <<  QString::number( reinterpret_cast<uint64_t>(intf), 16 );
    delete intf;
  } 
  OpenTxEepromCleanup();
}

QList<FirmwareInterface *> firmwares;
FirmwareInterface * default_firmware_variant;
FirmwareInterface * current_firmware_variant;

void UnregisterFirmwares() 
{
  foreach (FirmwareInterface * f, firmwares) {
    delete f;
  }
}

bool LoadEeprom(RadioData &radioData, const uint8_t *eeprom, const int size)
{
  foreach(EEPROMInterface *eepromInterface, eepromInterfaces) {
    if (eepromInterface->load(radioData, eeprom, size))
      return true;
  }

  return false;
}

bool LoadBackup(RadioData &radioData, uint8_t *eeprom, int size, int index)
{
  foreach(EEPROMInterface *eepromInterface, eepromInterfaces) {
    if (eepromInterface->loadBackup(radioData, eeprom, size, index))
      return true;
  }

  return false;
}


bool LoadEepromXml(RadioData &radioData, QDomDocument &doc)
{
  foreach(EEPROMInterface *eepromInterface, eepromInterfaces) {
    if (eepromInterface->loadxml(radioData, doc))
      return true;
  }

  return false;
}

QString getBoardName(BoardEnum board)
{
  switch (board) {
    case BOARD_STOCK:
      return "9X";
    case BOARD_M128:
      return "9X128";
    case BOARD_GRUVIN9X:
      return "Gruvin9x";
    case BOARD_MEGA2560:
      return "MEGA2560";
    case BOARD_TARANIS:
      return "Taranis";
    case BOARD_TARANIS_PLUS:
      return "Taranis Plus";
    case BOARD_SKY9X:
      return "Sky9x";
    case BOARD_9XRPRO:
      return "9XR-PRO";
    default:
      return "Unknown";
  }
}

FirmwareInterface * GetFirmware(QString id)
{
  foreach(FirmwareInterface * firmware, firmwares) {
    FirmwareInterface * result = firmware->getFirmwareVariant(id);
    if (result) {
      return result;
    }
  }

  return default_firmware_variant;
}

void FirmwareInterface::addOption(const char *option, QString tooltip, uint32_t variant)
{
  Option options[] = { { option, tooltip, variant }, { NULL } };
  addOptions(options);
}

unsigned int FirmwareInterface::getVariantNumber()
{
  unsigned int result = 0;
  const FirmwareInterface * base = getFirmwareBase();
  QStringList options = id.mid(base->getId().length()+1).split("-", QString::SkipEmptyParts);
  foreach(QString option, options) {
    foreach(QList<Option> group, base->opts) {
      foreach(Option opt, group) {
        if (opt.name == option) {
          result += opt.variant;
        }
      }
    }
  }
  return result;
}

void FirmwareInterface::addLanguage(const char *lang)
{
  languages.push_back(lang);
}

void FirmwareInterface::addTTSLanguage(const char *lang)
{
  ttslanguages.push_back(lang);
}

void FirmwareInterface::addOptions(Option options[])
{
  QList<Option> opts;
  for (int i=0; options[i].name; i++) {
    opts.push_back(options[i]);
  }
  this->opts.push_back(opts);
}
