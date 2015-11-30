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

#include "opentxM128simulator.h"
#include "opentxinterface.h"
#include "opentxeeprom.h"

#define SIMU
#define SIMU_EXCEPTIONS
#define PCBSTD
#define CPUM128
#define HELI
#define TEMPLATES
#define SPLASH
#define FLIGHT_MODES
#define FRSKY
#define FRSKY_HUB
#define WS_HOW_HIGH
#define VARIO
#define PPM_UNIT_PERCENT_PREC1
#define AUDIO
#define HAPTIC
#define AUTOSWITCH
#define GRAPHICS
#define CURVES
#define XCURVES
#define GVARS
#define BOLD_FONT
#define VOICE
#define PPM_CENTER_ADJUSTABLE
#define PPM_LIMITS_SYMETRICAL
#define GAUGES
#define GPS
#define FAI_CHOICE
#define FRSKY_STICKS
#define DSM2
#define DSM2_PPM
#define OVERRIDE_CHANNEL_FUNCTION
#define FLAVOUR "9x128"

#define EEPROM_VARIANT SIMU_M128_VARIANTS
#define GAUGES

#undef min
#undef max

#include <exception>

namespace OpenTxM128 {
#include "radio/src/targets/stock/board_stock.cpp"
#include "radio/src/targets/common_avr/telemetry_driver.cpp"
#include "radio/src/eeprom_common.cpp"
#include "radio/src/eeprom_rlc.cpp"
#include "radio/src/opentx.cpp"
#include "radio/src/strhelpers.cpp"
#include "radio/src/switches.cpp"
#include "radio/src/curves.cpp"
#include "radio/src/mixer.cpp"
#include "radio/src/pulses/pulses_avr.cpp"
#include "radio/src/stamp.cpp"
#include "radio/src/maths.cpp"
#include "radio/src/vario.cpp"
#include "radio/src/gui/menus.cpp"
#include "radio/src/gui/menu_model.cpp"
#include "radio/src/gui/menu_general.cpp"
#include "radio/src/gui/view_main.cpp"
#include "radio/src/gui/view_statistics.cpp"
#include "radio/src/gui/view_frsky.cpp"
#include "radio/src/lcd_common.cpp"
#include "radio/src/lcd_default.cpp"
#include "radio/src/keys.cpp"
#include "radio/src/targets/simu/simpgmspace.cpp"
#include "radio/src/templates.cpp"
#include "radio/src/translations.cpp"
#include "radio/src/fonts.cpp"
#include "radio/src/audio_avr.cpp"
#include "radio/src/targets/stock/voice.cpp"
#include "radio/src/telemetry/frsky.cpp"
#include "radio/src/telemetry/frsky_d.cpp"

#include "radio/src/telemetry/mavlink.cpp"
#include "radio/src/gui/view_mavlink.cpp"

#include "radio/src/translations/tts_en.cpp"
#include "radio/src/haptic.cpp"

int16_t g_anas[NUM_STICKS+BOARD_9X_NUM_POTS];

uint16_t anaIn(uint8_t chan)
{
  if (chan == 7)
    return 150;
  else
    return g_anas[chan];
}

bool hasExtendedTrims()
{
  return g_model.extendedTrims;
}

uint8_t getStickMode()
{
  return limit<uint8_t>(0, g_eeGeneral.stickMode, 3);
}

}

using namespace OpenTxM128;

OpenTxM128Simulator::OpenTxM128Simulator()
{
}

bool OpenTxM128Simulator::timer10ms()
{
#define TIMER10MS_IMPORT
#include "simulatorimport.h"
}

uint8_t * OpenTxM128Simulator::getLcd()
{
#define GETLCD_IMPORT
#include "simulatorimport.h"
}

bool OpenTxM128Simulator::lcdChanged(bool & lightEnable)
{
#define LCDCHANGED_IMPORT
#include "simulatorimport.h"
}

void OpenTxM128Simulator::start(QByteArray & eeprom, bool tests)
{
  memcpy(OpenTxM128::eeprom, eeprom.data(), std::min<int>(sizeof(OpenTxM128::eeprom), eeprom.size()));
  StartEepromThread(NULL);
  StartMainThread(tests);
}

void OpenTxM128Simulator::start(const char * filename, bool tests)
{
  StartEepromThread(filename);
  StartMainThread(tests);
}

void OpenTxM128Simulator::stop()
{
  StopMainThread();
  StopEepromThread();
}

void OpenTxM128Simulator::getValues(TxOutputs &outputs)
{
#define GETVALUES_IMPORT
#define g_chans512 channelOutputs
#include "simulatorimport.h"
}

void OpenTxM128Simulator::setValues(TxInputs &inputs)
{
#define SETVALUES_IMPORT
#include "simulatorimport.h"
}

void OpenTxM128Simulator::setTrim(unsigned int idx, int value)
{
  idx = OpenTxM128::modn12x3[4*getStickMode() + idx];
  uint8_t phase = getTrimFlightPhase(getFlightMode(), idx);
  setTrimValue(phase, idx, value);
}

void OpenTxM128Simulator::getTrims(Trims & trims)
{
  uint8_t phase = getFlightMode();
  trims.extended = hasExtendedTrims();
  for (uint8_t idx=0; idx<4; idx++) {
    trims.values[idx] = getTrimValue(getTrimFlightPhase(phase, idx), idx);
  }

  for (int i=0; i<2; i++) {
    uint8_t idx = OpenTxM128::modn12x3[4*getStickMode() + i];
    int16_t tmp = trims.values[i];
    trims.values[i] = trims.values[idx];
    trims.values[idx] = tmp;
  }
}

void OpenTxM128Simulator::wheelEvent(uint8_t steps)
{
}

unsigned int OpenTxM128Simulator::getPhase()
{
  return getFlightMode();
}

const char * OpenTxM128Simulator::getPhaseName(unsigned int phase)
{
  static char buff[sizeof(g_model.flightModeData[0].name)+1];
  zchar2str(buff, g_model.flightModeData[phase].name, sizeof(g_model.flightModeData[0].name));
  return buff;
}

const char * OpenTxM128Simulator::getError()
{
#define GETERROR_IMPORT
#include "simulatorimport.h"
}
