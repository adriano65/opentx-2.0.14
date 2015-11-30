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

#include "opentxGruvin9xsimulator.h"
#include "opentxinterface.h"
#include "opentxeeprom.h"

#define SIMU
#define SIMU_EXCEPTIONS
#define PCBGRUVIN9X
#define CPUM2560
#define ROTARY_ENCODERS 2
#define HELI
#define TEMPLATES
#define SPLASH
#define FLIGHT_MODES
#define FRSKY
#define FRSKY_HUB
#define WS_HOW_HIGH
#define VARIO
#define PPM_UNIT_PERCENT_PREC1
#define BUZZER
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
#define OVERRIDE_CHANNEL_FUNCTION
#define FLAVOUR "gruvin9x"

#define EEPROM_VARIANT 3

#undef min
#undef max

#include <exception>

namespace Open9xGruvin9x {
#include "radio/src/targets/gruvin9x/board_gruvin9x.cpp"
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
#include "radio/src/buzzer.cpp"
#include "radio/src/targets/gruvin9x/somo14d.cpp"
#include "radio/src/telemetry/frsky.cpp"
#include "radio/src/telemetry/frsky_d.cpp"
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

using namespace Open9xGruvin9x;

Open9xGruvin9xSimulator::Open9xGruvin9xSimulator()
{
}

bool Open9xGruvin9xSimulator::timer10ms()
{
#define TIMER10MS_IMPORT
#include "simulatorimport.h"
}

uint8_t * Open9xGruvin9xSimulator::getLcd()
{
#define GETLCD_IMPORT
#include "simulatorimport.h"
}

bool Open9xGruvin9xSimulator::lcdChanged(bool & lightEnable)
{
#define LCDCHANGED_IMPORT
#include "simulatorimport.h"
}

void Open9xGruvin9xSimulator::start(QByteArray & eeprom, bool tests)
{
  g_rotenc[0] = 0;
  g_rotenc[1] = 0;
  memcpy(Open9xGruvin9x::eeprom, eeprom.data(), std::min<int>(sizeof(Open9xGruvin9x::eeprom), eeprom.size()));
  StartEepromThread(NULL);
  StartMainThread(tests);
}

void Open9xGruvin9xSimulator::start(const char * filename, bool tests)
{
  g_rotenc[0] = 0;
  g_rotenc[1] = 0;
  StartEepromThread(filename);
  StartMainThread(tests);
}

void Open9xGruvin9xSimulator::stop()
{
  StopMainThread();
  StopEepromThread();
}

void Open9xGruvin9xSimulator::getValues(TxOutputs &outputs)
{
#define GETVALUES_IMPORT
#define g_chans512 channelOutputs
#include "simulatorimport.h"
  outputs.beep = g_beepCnt;
  g_beepCnt = 0;
}

void Open9xGruvin9xSimulator::setValues(TxInputs &inputs)
{
#define SETVALUES_IMPORT
#include "simulatorimport.h"
}

void Open9xGruvin9xSimulator::setTrim(unsigned int idx, int value)
{
  idx = Open9xGruvin9x::modn12x3[4*getStickMode() + idx];
  uint8_t phase = getTrimFlightPhase(getFlightMode(), idx);
  setTrimValue(phase, idx, value);
}

void Open9xGruvin9xSimulator::getTrims(Trims & trims)
{
  uint8_t phase = getFlightMode();
  trims.extended = hasExtendedTrims();
  for (uint8_t idx=0; idx<4; idx++) {
    trims.values[idx] = getTrimValue(getTrimFlightPhase(phase, idx), idx);
  }

  for (int i=0; i<2; i++) {
    uint8_t idx = Open9xGruvin9x::modn12x3[4*getStickMode() + i];
    int16_t tmp = trims.values[i];
    trims.values[i] = trims.values[idx];
    trims.values[idx] = tmp;
  }
}

void Open9xGruvin9xSimulator::wheelEvent(uint8_t steps)
{
  g_rotenc[0] += steps;
}

unsigned int Open9xGruvin9xSimulator::getPhase()
{
  return getFlightMode();
}

const char * Open9xGruvin9xSimulator::getPhaseName(unsigned int phase)
{
  static char buff[sizeof(g_model.flightModeData[0].name)+1];
  zchar2str(buff, g_model.flightModeData[phase].name, sizeof(g_model.flightModeData[0].name));
  return buff;
}

const char * Open9xGruvin9xSimulator::getError()
{
#define GETERROR_IMPORT
#include "simulatorimport.h"
}
