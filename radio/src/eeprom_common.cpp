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

#include <stdint.h>
#include "opentx.h"
#include "inttypes.h"
#include "string.h"

uint8_t   s_eeDirtyMsk;
tmr10ms_t s_eeDirtyTime10ms;

void eeDirty(uint8_t msk)
{
  s_eeDirtyMsk |= msk;
  s_eeDirtyTime10ms = get_tmr10ms() ;
}

#if defined(CPUARM)
ModelHeader modelHeaders[MAX_MODELS];
void eeLoadModelHeaders()
{
  for (uint32_t i=0; i<MAX_MODELS; i++) {
    eeLoadModelHeader(i, &modelHeaders[i]);
  }
}
#endif

void eeLoadModel(uint8_t id) {
  if (id<MAX_MODELS) {
	TRACE("eeLoadModel %d", id);

	#if defined(CPUARM)
    watchdogSetTimeout(500/*5s*/);
	#endif

	#if defined(SDCARD)
    closeLogs();
	#endif

    if (pulsesStarted()) {
      pausePulses();
    }

    pauseMixerCalculations();

	#if defined(PCBSKY9X)
    uint16_t size = File_system[id+1].size ;
    memset(&g_model, 0, sizeof(g_model));
	
	#else	
	
    theFile.openRlc(FILE_MODEL(id));
    uint16_t size = theFile.readRlc((uint8_t*)&g_model, sizeof(g_model));
	#endif

	#ifdef SIMU
    if (size > 0 && size != sizeof(g_model)) {
      printf("Model data read=%d bytes vs %d bytes\n", size, (int)sizeof(ModelData));
	  }
	#endif

    bool newModel = false;

    if (size < 256) {
      modelDefault(id);
      eeCheck(true);
      newModel = true;
	  }
	#if defined(PCBSKY9X)
    else {
      read32_eeprom_data((File_system[id+1].block_no << 12) + sizeof(struct t_eeprom_header), (uint8_t *)&g_model, size) ;
	  }
	#endif

    AUDIO_FLUSH();
    flightReset();
    logicalSwitchesReset();

    if (pulsesStarted()) {
      if (!newModel) {
        checkAll();
		}
      resumePulses();
	  }

    activeFnSwitches = 0;
    activeFunctions = 0;
    memclear(lastFunctionTime, sizeof(lastFunctionTime));

	#if !defined(PCBSTD)
    for (uint8_t i=0; i<MAX_TIMERS; i++) {
      if (g_model.timers[i].persistent) {
        timersStates[i].val = g_model.timers[i].value;
		}
	  }
	#endif

	switch (g_model.telemetryProtocol) {
	  #if defined(FRSKY)
	  #if defined(CPUARM)
	  case PROTOCOL_FRSKY_SPORT:
	  #endif
	  case PROTOCOL_FRSKY_D:		
		FRSKY_Init();
		#if defined(CPUARM)
		if (g_model.frsky.mAhPersistent) {
		  frskyData.hub.currentConsumption = g_model.frsky.storedMah;
		  }
		#endif
		break;
	  #endif
		
	  #if defined(MAVLINK)
	  case PROTOCOL_MAVLINK:
		MAVLINK_Init(true);
		break;
	  #endif
	  }
	

    LOAD_MODEL_CURVES();

    resumeMixerCalculations();
    // TODO pulses should be started after mixer calculations ...

#if defined(FRSKY) || defined(MAVLINK)
    frskySendAlarms();
#endif

#if defined(CPUARM) && defined(SDCARD)
    referenceModelAudioFiles();
#endif

    LOAD_MODEL_BITMAP();
    LUA_LOAD_MODEL_SCRIPTS();
    SEND_FAILSAFE_1S();
  }
}
