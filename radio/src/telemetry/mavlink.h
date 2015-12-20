/*
 * Authors (alphabetical order)
 * - Andre Bernet <bernet.andre@gmail.com>
 * - Andreas Weitl
 * - Bertrand Songis <bsongis@gmail.com>
 * - Bryan J. Rentoul (Gruvin) <gruvin@gmail.com>
 * - Cameron Weeks <th9xer@gmail.com>
 * - Erez Raviv
 * - Gabriel Birkus
 * - Gerard Valade <gerard.valade@gmail.com>
 * - Jean-Pierre Parisy
 * - Karl Szmutny
 * - Michael Blandford
 * - Michal Hlavinka
 * - Pat Mackenzie
 * - Philip Moss
 * - Rienk de Jong
 * - Rob Thomson
 * - Romolo Manfredini <romolo.manfredini@gmail.com>
 * - Thomas Husterer
 *
 * Adapted from mavlink for ardupilot
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published
 * by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 */
 
#ifndef _MAVLINK_H_
#define _MAVLINK_H_

#define MAV_SYSTEM_ID	1


//#undef MAVLINK_USE_CONVENIENCE_FUNCTIONS
#define MAVLINK_USE_CONVENIENCE_FUNCTIONS

void mavlink_send_uart_bytes(uint8_t, const uint8_t *buffer, uint32_t size);
#define MAVLINK_SEND_UART_BYTES mavlink_send_uart_bytes

#include "../GCS_MAVLink/include_v1.0/mavlink_types.h"
extern mavlink_system_t mavlink_system;

#include "../GCS_MAVLink/include_v1.0/ardupilotmega/mavlink.h"

//#define MAVLINK_BIG_ENDIAN 1
//#undef MAVLINK_LITTLE_ENDIAN 1
/*
static const uint8_t ap_modes_lut[18] PROGMEM = {0,1,2,3,12,4,5,12,12,12,6,7,8,9,12,12,10,11};
*/

#define MAVLINK_STACK_SIZE       200
/*
 * Type definitions
 */

#ifdef MAVLINK_PARAMS

enum ACM_PARAMS {
	RATE_YAW_P, // Rate Yaw
	RATE_YAW_I, // Rate Yaw
	STB_YAW_P, // Stabilize Yaw
	STB_YAW_I, // Stabilize Yaw
	RATE_PIT_P, // Rate Pitch
	RATE_PIT_I, // Rate Pitch
	STB_PIT_P, // Stabilize Pitch
	STB_PIT_I, // Stabilize Pitch
	RATE_RLL_P, // Rate Roll
	RATE_RLL_I, // Rate Roll
	STB_RLL_P, // Stabilize Roll
	STB_RLL_I, // Stabilize Roll
	THR_ALT_P, // THR_BAR, // Altitude Hold
	THR_ALT_I, // THR_BAR, // Altitude Hold
	HLD_LON_P, // Loiter
	HLD_LON_I, // Loiter
	HLD_LAT_P, // Loiter
	HLD_LAT_I, // Loiter
	NAV_LON_P, // Nav WP
	NAV_LON_I, // Nav WP
	NAV_LAT_P, // Nav WPs
	NAV_LAT_I, // Nav WP
	NB_PID_PARAMS, // Number of PI Parameters
	LOW_VOLT = NB_PID_PARAMS,
	IN_VOLT, //
	BATT_MONITOR, //
	BATT_CAPACITY, //
	NB_PARAMS
};
//#define NB_PID_PARAMS 24
#define NB_COL_PARAMS 2
#define NB_ROW_PARAMS ((NB_PARAMS+1)/NB_COL_PARAMS)

typedef struct MavlinkParam_ {
	uint8_t repeat :4;
	uint8_t valid :4;
	float value;
} MavlinkParam_t;

#endif

typedef struct Location_ {
	float lat; 		//Latitude in degrees
	float lon; 		//Longitude in degrees
	float gps_alt; 	//Altitude in meters
	float rel_alt;
} Location_t;

typedef struct Mavlink_ {
	uint8_t		mav_sysid;
	uint8_t		mav_compid;	
	uint8_t		radio_sysid;
	uint8_t		radio_compid;
	mavlink_heartbeat_t		heartbeat;
	uint16_t	packet_drop;
	uint16_t	packet_fixed;

	bool 		active;
	uint8_t 	nav_mode;
	uint8_t 	rcv_control_mode;	// System mode, see MAV_MODE ENUM in mavlink/include/mavlink_types.h
	uint8_t 	vbat; 				// Battery voltage, in millivolts (1 = 1 millivolt)
	uint8_t 	ibat; 				// Battery current, in millivolts (1 = 1 millivolt)
	uint8_t 	rem_bat; 			// Remaining battery percent
	bool 		vbat_low;
	
	uint8_t 	rc_rssi;
	uint8_t 	pc_rssi;
	
	uint8_t 	debug;
	uint16_t	unknow_pckt_cnt;

	// MSG ACTION / ACK
	uint8_t 	req_mode;
	int8_t 		ack_result;

	// GPS
	uint8_t 	fix_type; // 0-1: no fix, 2: 2D fix, 3: 3D fix. 
						  // Some applications will not use the value of this field unless it is at least two, so always correctly fill in the fix.
	uint8_t 	satellites_visible; // Number of visible satellites
	Location_t	loc_current;
	float 		eph;
	uint16_t 	course;
	float 		ground_speed;		// Ground speed
	// Navigation
	uint16_t 	heading;
	uint16_t 	bearing;

#ifdef MAVLINK_PARAMS
	// Params
	MavlinkParam_t params[NB_PARAMS];
#endif

} Mavlink_t;

// Telemetry data hold
extern Mavlink_t mavlinkRT;

/*
 * Funtion definitions
 */
extern inline uint8_t MAVLINK_CtrlMode2Action(uint8_t mode) {
	uint8_t action;
	
	return action;
}
void MAVLINK_Init(bool);
void MAVLINK_telemetryWakeup(void);
NOINLINE void processSerialMavlinkData(uint8_t);
uint32_t Index2Baud(uint8_t);
#if defined(CPUARM)
OS_TID TelemetryTxTaskId;
OS_FlagID TelemTxFlag;
//static void mavlink_checksum(uint8_t*);
void TelemetryTxTask(void*);
void TxPushByte(uint8_t);
#endif

static inline void handleMessage(mavlink_message_t* );

#ifdef MAVLINK_PARAMS

void putsMavlinParams(uint8_t x, uint8_t y, uint8_t idx, uint8_t att);
void setMavlinParamsValue(uint8_t idx, float val);

inline uint8_t getIdxParam(uint8_t rowIdx, uint8_t colIdx) {
	return (rowIdx * NB_COL_PARAMS) + colIdx;
}

inline MavlinkParam_t * getParam(uint8_t idx) {
	return &telemetry_data.params[idx];
}

inline float getMavlinParamsValue(uint8_t idx) {
	return telemetry_data.params[idx].value;
}

inline uint8_t isDirtyParamsValue(uint8_t idx) {
	return telemetry_data.params[idx].repeat;
}

inline uint8_t isValidParamsValue(uint8_t idx) {
	return telemetry_data.params[idx].valid;
}

inline float getCoefPrecis(uint8_t precis) {
	switch (precis) {
	case 1:
		return 10.0;
	case 2:
		return 100.0;
	case 3:
		return 1000.0;
	}
	return 1.0;

}

inline int16_t getMaxMavlinParamsValue(uint8_t idx) {
	int16_t max = 0;
	switch (idx) {
	case LOW_VOLT:
		max = 2500; // 25.0 Volt max
		break;
	case IN_VOLT:
		max = 900; // 7.00 Volt max
		break;
	case BATT_MONITOR:
		max = 3;
		break;
	case BATT_CAPACITY:
		max = 7000; // 7000 mAh max
		break;
	default:
		if (idx < NB_PID_PARAMS) {
			max = (idx & 0x01) ? 1000 : 750;
		}
		break;
	}
	return max;
}

inline uint8_t getPrecisMavlinParamsValue(uint8_t idx) {
	uint8_t precis = 2;
	switch (idx) {
	case LOW_VOLT:
		precis = 2;
		break;
	case IN_VOLT:
		precis = 2;
		break;
	case BATT_MONITOR:
		precis = 0;
		break;
	case BATT_CAPACITY:
		precis = 0;
		break;
	default:
		if (idx < NB_PID_PARAMS) {
			if (idx & 0x01)
				precis = 3;
		}
		break;
	}
	return precis;
}

void lcd_outdezFloat(uint8_t x, uint8_t y, float val, uint8_t precis, uint8_t mode);
#endif

#endif

