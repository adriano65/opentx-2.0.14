/*
 * Authors (alphabetical order)
 * - Adriano Carosso <adriano.carosso@gmail.com>
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
#include "../opentx.h"				// includes "telemetry/mavlink.h" too

/*
 * 	mavlink_system_t ----------------------------------------------------------------
    uint8_t sysid;   // Used by the MAVLink message_xx_send() convenience function
    uint8_t compid;  // Used by the MAVLink message_xx_send() convenience function
    uint8_t type;    // Unused, can be used by user to store the system's type
    uint8_t state;   // Unused, can be used by user to store the system's state
    uint8_t mode;    // Unused, can be used by user to store the system's mode
    uint8_t nav_mode; // Unused, can be used by user to store the system's navigation mode
 */
mavlink_system_t mavlink_system = {	  MAV_TYPE_FIXED_WING
									, MAV_COMP_ID_MISSIONPLANNER
									, MAV_AUTOPILOT_GENERIC
									, 0
									, 0
									, 0 };
/* The message buffer	*/
static mavlink_message_t mavlink_message;
/* The currently message pointer (to decoded)	*/
static mavlink_message_t* pmavlink_msg = &mavlink_message;

/* function used by MAVLINK_USE_CONVENIENCE_FUNCTIONS */
//MAVLINK_SEND_UART_BYTES(chan, (const uint8_t *)buf, len);
void mavlink_send_uart_bytes(uint8_t chan, const uint8_t *buffer, uint32_t size) { 
    if (chan == MAVLINK_COMM_0) {
		//txPdcUsart(buffer, size); 
		}
    if (chan == MAVLINK_COMM_1) {
		//txPdcUsart(buffer, size); 
		}
}

// Mavlink message decoded Status Text
#define PARAM_NB_REPEAT 10
#define LEN_STATUSTEXT 20
static char mav_statustext[LEN_STATUSTEXT];
static int8_t mav_heartbeat = 0;
static uint8_t data_stream_start_stop = 0;

// Telemetry data holder
Mavlink_t mavlinkRT;

// *****************************************************

#if defined(CPUARM)
	Fifo<32> TelemTxFifo;
	OS_STK TelemetryTxStack[MAVLINK_STACK_SIZE];
	#if defined(MAVLINK_DEBUG)
	  #error "MAVLINK_DEBUG NOT works yet."
	  #ifdef BLUETOOTH
		#error "---->> MAVLINK_DEBUG NOT works with BLUETOOTH defined (btTask conflicts)"
	  #endif
	  
	  //uint32_t txBt(uint32_t data) {
	  uint32_t txBt(const char data) {
	  #ifndef SIMU
		Uart *pUart = BT_USART;

		if (pUart->UART_TNCR == 0) {
		  pUart->UART_TPR = data;
		  pUart->UART_TCR = 1;
		  pUart->UART_PTCR = US_PTCR_TXTEN;
		  pUart->UART_IER = UART_IER_TXBUFE;
		  NVIC_EnableIRQ(UART1_IRQn);
		  return 1; // Sent OK
		  }
	  #endif
		return 0 ;  // Busy
	  }
	  
	  extern "C" void UART1_IRQHandler() {
		Uart *pUart = BT_USART;
		if ( pUart->UART_SR & UART_SR_TXBUFE ) {
		  pUart->UART_IDR = UART_IDR_TXBUFE ;
		  pUart->UART_PTCR = US_PTCR_TXTDIS ;
		  }
		if ( pUart->UART_SR & UART_SR_RXRDY ) {
		  TelemRxFifo.push(pUart->UART_RHR);
		  }
	  }
	  
	#endif
	/*
	void Txchar(uint8_t c) {
	  //Uart *pUart = SECOND_SERIAL_UART;

	  // Wait for the transmitter to be ready
	 // while ( (pUart->UART_SR & UART_SR_TXEMPTY) == 0 ) ;

	  // Send character
	  //pUart->UART_THR = c;
	  
	  SECOND_SERIAL_UART->UART_THR = c;
	}
	
	void txCom2Uart( uint8_t *buffer ) {
		Uart *pUart=SECOND_SERIAL_UART ;

		if ( pUart->UART_TNCR == 0 ) {
		#ifndef SIMU
			pUart->UART_TNPR = (uint32_t)buffer ;
		#endif
			pUart->UART_TNCR = 1 ;
			pUart->UART_PTCR = US_PTCR_TXTEN ;
			}
		return;
	}
	*/
//SerialFuncP RXHandler = processSerialMavlinkData;
#endif


/*Reset basic Mavlink variables */
void MAVLINK_reset(void) {
	mavlink_status_t* p_status = mavlink_get_channel_status(MAVLINK_COMM_0);
	p_status->current_rx_seq = 0;
	p_status->current_tx_seq = 0;
	memset(&mavlinkRT, 0, sizeof(mavlinkRT));
	mavlinkRT.rcv_control_mode = MAV_MODE_PREFLIGHT;
	mavlinkRT.req_mode = MAV_MODE_ENUM_END;

	mavlinkRT.heartbeat.type = MAV_TYPE_ENUM_END;
	mavlinkRT.heartbeat.autopilot = MAV_AUTOPILOT_ENUM_END;
	mavlinkRT.heartbeat.custom_mode = MAV_AUTOPILOT_INVALID;

	data_stream_start_stop = 0;
}

/* initialize serial (see opentx.cpp) */
void MAVLINK_Init(bool bHardReset) {
	mav_statustext[0] = 0;
	#if !defined(SIMU)
	  #if defined(CPUARM)
	  if (bHardReset) MAVLINK_reset();
	  // enable AFTER CoInitOS()
	  if (bHardReset) TelemetryTxTaskId = CoCreateTask(TelemetryTxTask, NULL, 19, &TelemetryTxStack[MAVLINK_STACK_SIZE-1], MAVLINK_STACK_SIZE);
	  g_model.externalModule=MODULE_TYPE_PPM;
	  #endif
	  switch (g_model.telemetryCom) {
		case 0:
			// SKY9x
			//telemetryPortInit -> UART2_Configure -> SECOND_USART -> USART0 -> 0x40024000U Base Address
			telemetryPortInit(Index2Baud(g_model.telemetryBaud));
			break;			  
		case 1:
			// in ersky9x CONSOLE_USART==UART0
			// 9XR-PRO has external module connected via FUTABA Port
			// telemetrySecondPortInit -> SECOND_UART_Configure -> SECOND_SERIAL_UART -> UART0 -> 0x400E0600U Base Address
			/* my taranis is wired on first and second serial (first is RX only) :-) */
			telemetrySecondPortInit(Index2Baud(g_model.telemetryBaud));
			break;			  
		case 2:
			// btSetBaudrate -> UART3_Configure -> BT_USART -> UART1 -> 0x400E0800U Base Address
			//UART3_Configure(Index2Baud(g_model.telemetryBaud), Master_frequency);
			break;			  
		}
	#endif
	TRACE("MAVLINK_Init %s", bHardReset ? "true" : "false");
}

void MAVLINK_telemetryWakeup() {
    #if !defined(SIMU)
	#if defined(PCBSKY9X) && !defined(REVA) && !defined(REVX)
		rxPdcUsart(processSerialMavlinkData);
	#else
		uint8_t data;
		#if defined(MAVLINK_DEBUG)
		  if (TelemRxFifo.pop(data)) {
			  processSerialMavlinkData(data);
			  }
		#else
		  while (TelemRxFifo.pop(data)) {
			processSerialMavlinkData(data);
			}	
		#endif
	#endif
    #endif
}

uint32_t Index2Baud(uint8_t mavbaudIdx) {
	switch (mavbaudIdx) {
	  //"1200  ""2400  ""4800  ""9600  ""19200 ""38400 ""57600 ""115200"
	  case 0:
		return 1200;
	  case 1:
		return 2400;
	  case 2:
		return 4800;
	  case 3:
		return 9600;
	  case 4:
		return 19200;
	  case 5:
		return 38400;
	  case 6:
		return 57600;
	  case 7:
		return 115200;
	  }
	return 9600;
}

#if defined(CPUARM) && !defined(SIMU)
void TelemetryTxTask(void* pdata) {
  uint8_t byte;
  uint16_t msElapsedX10=0;

  TelemTxFlag = CoCreateFlag(true, false);	//(BOOL bAutoReset,BOOL bInitialState);
  CoTickDelay(1) ;

  while (1) {
    uint32_t errcode = CoWaitForSingleFlag(TelemTxFlag, 10); // Wait for flag MAX 20 ms
		if (errcode == E_OK) {
			while (TelemTxFifo.pop(byte)) {
			  #if defined(REVX)
				#if defined(MAVLINK_DEBUG)
					txBt(byte);
				#else
					debugPutc(byte);	/* second_serial_driver.cpp */
				#endif
			  #else
				#if defined(SKY9X)
					//txPdcUsart(&byte, 1); 
				#else
					
				#endif
			  #endif
			  }
		  }
	msElapsedX10++;
	if (msElapsedX10>50) { // once per second
	  msElapsedX10=0; }
	}		// while 1
  
}

void TxPushByte(uint8_t data) {
  TelemTxFifo.push(data);
  CoSetFlag(TelemTxFlag); // Tell the TelemetryTxTask something to do
}
#endif


void request_mavlink_rates() {
    const int  maxStreams = 6;
    const uint8_t MAVStreams[maxStreams] = {MAV_DATA_STREAM_RAW_SENSORS,
											MAV_DATA_STREAM_EXTENDED_STATUS,
											MAV_DATA_STREAM_RC_CHANNELS,
											MAV_DATA_STREAM_POSITION,
											MAV_DATA_STREAM_EXTRA1, 
											MAV_DATA_STREAM_EXTRA2};
    const uint16_t MAVRates[maxStreams] = {0x02, 0x02, 0x05, 0x02, 0x05, 0x02};
    for (int i=0; i < maxStreams; i++) {
        mavlink_msg_request_data_stream_send(MAVLINK_COMM_0,
											 //mavlinkRT.radio_sysid,
											 2,
											 //mavlinkRT.radio_compid,
											 3,
											 MAVStreams[i], MAVRates[i], 1);
    }
}

/*
 * Calculates the MAVLink checksum on a packet in parameter buffer
 * and append it after the data
 
static void mavlink_checksum(uint8_t* buf) {
  register uint8_t length = buf[1];
  uint16_t sum = 0xFFFF;
  uint8_t i, stoplen;

  stoplen = length + MAV_HEADER_SIZE + 1;

  // MAVLink 1.0 has an extra CRC seed
  buf[length + MAV_HEADER_SIZE] = MAVLINK_RADIO_CRC_EXTRA;

  i = 1;
  while (i<stoplen) {
    register uint8_t tmp;
    tmp = buf[i] ^ (uint8_t)(sum&0xff);
    tmp ^= (tmp<<4);
    sum = (sum>>8) ^ (tmp<<8) ^ (tmp<<3) ^ (tmp>>4);
    i++;
  }

  buf[length+MAV_HEADER_SIZE] = sum&0xFF;
  buf[length+MAV_HEADER_SIZE+1] = sum>>8;
}
*/

/* Mavlink message parser
 *	Parses the characters in a mavlink message.
 *	Case statement parses each character as it is received.
 *	One big change form the 0.9 to 1.0 version is the MAVLINK_CRC_EXTRA. 
 * This requires the mavlink_message_crcs array of 256 bytes.
 * 
 Mavlink frame detection: 

Field name			Index (Bytes)	Purpose
----------------------------------------------------------------------------------------------------------
Start-of-frame		0			Denotes the start of frame transmission (v1.0: 0xFE)
Payload length		1			Length of the following payload
Packet sequence	2				Each component counts up his send sequence. 
								Allows to detect packet loss
System ID			3			Identification of the SENDING system. 
								Allows to differentiate different systems on the same network.
Component ID		4			Identification of the SENDING component. 
								Allows to differentiate different components of the same system, 
								e.g. the IMU and the autopilot.
Message ID			5			Identification of the message
								Defines what the payload "means""" and how it should be correctly decoded.
Payload			6 to (n+6)		The data into the message, depends on the message id.
CRC				(n+7) to (n+8)	Check-sum of the entire packet, excluding the packet start sign (LSB to MSB)
------------------------------------------------------------------------------------------------------------
*/
NOINLINE void processSerialMavlinkData(uint8_t c) {
	// The current decoding status
	mavlink_status_t* p_status = mavlink_get_channel_status(MAVLINK_COMM_0);

#if MAVLINK_CRC_EXTRA
	static const uint8_t mavlink_message_crcs[256] PROGMEM = MAVLINK_MESSAGE_CRCS;
#define MAVLINK_MESSAGE_CRC(msgid) mavlink_message_crcs[msgid]
#endif
	
#if defined(BLUETOOTH)
  // TODO if (g_model.bt_telemetry)
  btPushByte(c);
#endif
  
	switch (p_status->parse_state) {
		case MAVLINK_PARSE_STATE_UNINIT:
		case MAVLINK_PARSE_STATE_IDLE:
			if (c == MAVLINK_STX) {
				p_status->parse_state = MAVLINK_PARSE_STATE_GOT_STX;
				mavlink_start_checksum(pmavlink_msg);
				}
			TRACE("MAVLINK_PARSE_STATE %d", p_status->parse_state);
			break;

		case MAVLINK_PARSE_STATE_GOT_STX:
			// NOT counting STX, LENGTH, SEQ, SYSID, COMPID, MSGID, CRC1 and CRC2
			pmavlink_msg->len = c;
			p_status->packet_idx = 0;
			mavlink_update_checksum(pmavlink_msg, c);
			p_status->parse_state = MAVLINK_PARSE_STATE_GOT_LENGTH;
			break;

		case MAVLINK_PARSE_STATE_GOT_LENGTH:
			pmavlink_msg->seq = c;
			mavlink_update_checksum(pmavlink_msg, c);
			p_status->parse_state = MAVLINK_PARSE_STATE_GOT_SEQ;
			break;

		case MAVLINK_PARSE_STATE_GOT_SEQ:
			pmavlink_msg->sysid = c;
			mavlink_update_checksum(pmavlink_msg, c);
			p_status->parse_state = MAVLINK_PARSE_STATE_GOT_SYSID;
			break;

		case MAVLINK_PARSE_STATE_GOT_SYSID:
			pmavlink_msg->compid = c;
			mavlink_update_checksum(pmavlink_msg, c);
			p_status->parse_state = MAVLINK_PARSE_STATE_GOT_COMPID;
			break;

		case MAVLINK_PARSE_STATE_GOT_COMPID:
			pmavlink_msg->msgid = c;
			mavlink_update_checksum(pmavlink_msg, c);
			if (pmavlink_msg->len == 0) {
				p_status->parse_state = MAVLINK_PARSE_STATE_GOT_PAYLOAD;
				}
			else {
				p_status->parse_state = MAVLINK_PARSE_STATE_GOT_MSGID;
				}
			break;

		case MAVLINK_PARSE_STATE_GOT_MSGID:
			_MAV_PAYLOAD_NON_CONST(pmavlink_msg)[p_status->packet_idx++] = (char) c;
			mavlink_update_checksum(pmavlink_msg, c);
			if (p_status->packet_idx == pmavlink_msg->len) {
				p_status->parse_state = MAVLINK_PARSE_STATE_GOT_PAYLOAD;
				}
			break;

		case MAVLINK_PARSE_STATE_GOT_PAYLOAD:
			#if MAVLINK_CRC_EXTRA
			mavlink_update_checksum(pmavlink_msg, pgm_read_byte(&(mavlink_message_crcs[pmavlink_msg->msgid])));
			#endif
			if (c != (pmavlink_msg->checksum & 0xFF)) {
				// Check first checksum byte
				p_status->parse_error = 3;
				} 
			else {
				p_status->parse_state = MAVLINK_PARSE_STATE_GOT_CRC1;
				}
			break;

		case MAVLINK_PARSE_STATE_GOT_CRC1:
			if (c != (pmavlink_msg->checksum >> 8)) {
				// Check second checksum byte
				p_status->parse_error = 4;
				}
			else {
				// Successfully got message ------------------------------------------------
				mavlinkRT.packet_fixed++;
				
				p_status->current_rx_seq = pmavlink_msg->seq;
				//p_status->msg_received = 1;
				p_status->parse_state = MAVLINK_PARSE_STATE_IDLE;
				//memcpy(r_message, pmavlink_msg, sizeof(mavlink_message_t));
				handleMessage(pmavlink_msg);
				}
			break;
		}
	// Error occur
	if (p_status->parse_error) {
		p_status->parse_state = MAVLINK_PARSE_STATE_IDLE;
		if (c == MAVLINK_STX) {
			p_status->parse_state = MAVLINK_PARSE_STATE_GOT_STX;
			mavlink_start_checksum(pmavlink_msg);
		}
		mavlinkRT.packet_drop++;
		p_status->parse_error = 0;
	}
	// If a message has been sucessfully decoded, check index
	/*
	 if (p_status->msg_received == 1) {
	 p_status->current_rx_seq = pmavlink_msg->seq;
	 p_status->packet_rx_success_count++;
	 }
	 */

	//r_mavlink_status->current_rx_seq = p_status->current_rx_seq + 1;
	//r_mavlink_status->packet_rx_success_count = p_status->packet_rx_success_count;
	//r_mavlink_status->packet_rx_drop_count = p_status->parse_error;
	//p_status->parse_error = 0;
	//return p_status->msg_received;
}


/*!	\brief Status log message
 *	\details Processes the mavlink status messages. This message contains a
 *	severity and a message. The severity is an enum defined by MAV_SEVERITY also
 *	see RFC-5424 for the severity levels.
 *	The original message is maximum 50 characters and is without termination
 *	character. For readablity on the 9x the only the first 15 (LEN_STATUSTEXT)
 *	characters are used. To get the full message you can use the commented
 *	funtion below.
 */

static inline void REC_MAVLINK_MSG_ID_STATUSTEXT(const mavlink_message_t* msg) {
	_MAV_RETURN_char_array(msg, mav_statustext, LEN_STATUSTEXT,  1);
}

/*!	\brief System status including cpu load, battery status and communication status.
 *	\details From this message we use use only the battery information. The rest
 *	is not realy of use while flying. The complete message can be decoded in to
 *	a struct with the first two commented lines.
 *  The battery votage is in mV. We divide by 100 to display tenths of volts.'
 *	\todo Add battery remaining variable in mavlinkRT struct for estimated
 *	remaining battery. Decoding function already in place.
 */

static inline void REC_MAVLINK_MSG_ID_SYS_STATUS(const mavlink_message_t* msg) {
	mavlinkRT.vbat = mavlink_msg_sys_status_get_voltage_battery(msg) / 100; // Voltage * 10
	mavlinkRT.ibat = mavlink_msg_sys_status_get_current_battery(msg) / 10;
	mavlinkRT.rem_bat = mavlink_msg_sys_status_get_battery_remaining(msg);

#ifdef MAVLINK_PARAMS
	mavlinkRT.vbat_low = (getMavlinParamsValue(BATT_MONITOR) > 0)
					&& (((float) mavlinkRT.vbat / 10.0) < getMavlinParamsValue(LOW_VOLT)) && (mavlinkRT.vbat > 50);
#else
	mavlinkRT.vbat_low = (mavlinkRT.rem_bat < 10);
#endif
}

/* Receive rc channels */
static inline void REC_MAVLINK_MSG_ID_RC_CHANNELS_RAW(const mavlink_message_t* msg) {
	uint8_t temp_rssi =(mavlink_msg_rc_channels_raw_get_rssi(msg) * 100) / 255;
	uint8_t temp_scale = 25 + g_model.mavlink.rc_rssi_scale * 5;
	mavlinkRT.rc_rssi =  (temp_rssi * 100) / temp_scale;
}

/*Arducopter specific radio message */
static inline void REC_MAVLINK_MSG_ID_RADIO(const mavlink_message_t* msg) {
	mavlinkRT.pc_rssi =  (mavlink_msg_radio_get_rssi(msg) * 100) / 255;
	mavlinkRT.packet_drop = mavlink_msg_radio_get_rxerrors(msg);
	mavlinkRT.packet_fixed = mavlink_msg_radio_get_fixed(msg);
}
static inline void REC_MAVLINK_MSG_ID_RADIO_STATUS(const mavlink_message_t* msg) {
	REC_MAVLINK_MSG_ID_RADIO(msg);
}

/* Navigation output message */
static inline void REC_MAVLINK_MSG_ID_NAV_CONTROLLER_OUTPUT(const mavlink_message_t* msg) {
	mavlinkRT.bearing = mavlink_msg_nav_controller_output_get_target_bearing(msg);
}

/* Hud navigation message */
static inline void REC_MAVLINK_MSG_ID_VFR_HUD(const mavlink_message_t* msg) {
	mavlinkRT.heading = mavlink_msg_vfr_hud_get_heading(msg);
	mavlinkRT.loc_current.rel_alt = mavlink_msg_vfr_hud_get_alt(msg);
}

/*!	\brief Heartbeat message
 *	\details Heartbeat message is used for the following information:
 *	type and autopilot is used to determine if the UAV is an ArduPlane or Arducopter
 */
static inline void REC_MAVLINK_MSG_ID_HEARTBEAT(const mavlink_message_t* msg) {
	mavlink_msg_heartbeat_decode(msg, &mavlinkRT.heartbeat);
	mavlinkRT.active = (mavlinkRT.heartbeat.base_mode & MAV_MODE_FLAG_SAFETY_ARMED) ? true : false;
}

static inline void REC_MAVLINK_MSG_ID_HIL_CONTROLS(const mavlink_message_t* msg) {
	mavlinkRT.nav_mode = mavlink_msg_hil_controls_get_mode(msg);
}

/* Process GPS raw integer message
 *	This message contains the following data:
 *		- fix type: 0-1: no fix, 2: 2D fix, 3: 3D fix.
 *		- Latitude, longitude in 1E7 * degrees
 *		- Altitude 1E3 * meters above MSL.
 *		- Course over ground in 100 * degrees
 *		- GPS HDOP horizontal dilution of precision in cm (m*100).
 *		- Ground speed in m/s * 100
 * 
---->   Received data
Data are received as packets, each packet is identified by a prefix of seven
characters ('$GPGGA,' or '$GPRMC,')and is ended by one star plus two bytes checksum.
The values are terminated by a comma.

$GPGGA - Global Positioning System Fix Data, Time, Position and fix related data fora GPS receiver.

                                                      11
        1         2       3 4        5 6 7  8   9  10 |  12 13  14   15
        |         |       | |        | | |  |   |   | |   | |   |    |
    GGA,hhmmss.ss,llll.ll,a,yyyyy.yy,a,x,xx,x.x,x.x,M,x.x,M,x.x,xxxx*hh<CR><LF>

Field Number:
  1) Universal Time Coordinated (UTC)
  2) Latitude
  3) N or S (North or South)
  4) Longitude
  5) E or W (East or West)
  6) GPS Quality Indicator,
     0 - fix not available,
     1 - GPS fix,
     2 - Differential GPS fix
  7) Number of satellites in view, 00 - 12
  8) Horizontal Dilution of precision
  9) Antenna Altitude above/below mean-sea-level (geoid)
 10) Units of antenna altitude, meters
 11) Geoidal separation, the difference between the WGS-84 earth
     ellipsoid and mean-sea-level (geoid), "-" means mean-sea-level
     below ellipsoid
 12) Units of geoidal separation, meters
 13) Age of differential GPS data, time in seconds since last SC104
     type 1 or 9 update, null field when DGPS is not used
 14) Differential reference station ID, 0000-1023
 *
 15) Checksum
 CrLf


$GPRMC - Recommended Minimum Navigation Information
                                                            12
        1         2 3       4 5        6 7   8   9    10  11|
        |         | |       | |        | |   |   |    |   | |
    RMC,hhmmss.ss,A,llll.ll,a,yyyyy.yy,a,x.x,x.x,xxxx,x.x,a*hh<CR><LF>

 Field Number:
  1) UTC Time
  2) Status, V = Navigation receiver warning
  3) Latitude
  4) N or S
  5) Longitude
  6) E or W
  7) Speed over ground, knots
  8) Track made good, degrees true. = =  Course over ground (COG)
  9) Date, ddmmyy
 10) Magnetic Variation, degrees
 11) E or W
 12) Checksum
 */
static inline void REC_MAVLINK_MSG_ID_GPS_RAW_INT(const mavlink_message_t* msg) {
	mavlinkRT.fix_type = mavlink_msg_gps_raw_int_get_fix_type(msg);
	mavlinkRT.loc_current.lat = mavlink_msg_gps_raw_int_get_lat(msg) / 1E7;
	mavlinkRT.loc_current.lon = mavlink_msg_gps_raw_int_get_lon(msg) / 1E7;
	mavlinkRT.loc_current.gps_alt = mavlink_msg_gps_raw_int_get_alt(msg) / 1E3;
	mavlinkRT.eph = mavlink_msg_gps_raw_int_get_eph(msg) / 100.0;
	mavlinkRT.course = mavlink_msg_gps_raw_int_get_cog(msg) / 100.0;
	mavlinkRT.ground_speed = mavlink_msg_gps_raw_int_get_vel(msg) / 100.0 ;
	mavlinkRT.satellites_visible = mavlink_msg_gps_raw_int_get_satellites_visible(msg);
}

static inline void REC_MAVLINK_MESSAGE_INFO_ATTITUDE(const mavlink_message_t* msg) {
  ;
}

static inline void REC_MAVLINK_MESSAGE_INFO_SYSTEM_TIME(const mavlink_message_t* msg) {
}


#ifdef MAVLINK_PARAMS
const pm_char *getParamId(uint8_t idx) {
	const pm_char *mav_params_id [((NB_PID_PARAMS / 2) + 4)]  = {
		PSTR("RATE_YAW"), // Rate Yaw
		PSTR("STB_YAW"), // Stabilize Yaw
		PSTR("RATE_PIT"), // Rate Pitch
		PSTR("STB_PIT"), // Stabilize Pitch
		PSTR("RATE_RLL"), // Rate Roll
		PSTR("STB_RLL"), // Stabilize Roll
		PSTR("THR_ALT"), // PSTR("THR_BAR"), // Altitude Hold
		PSTR("HLD_LON"), // Loiter
		PSTR("HLD_LAT"), // Loiter
		PSTR("NAV_LON"), // Nav WP
		PSTR("NAV_LAT"), // Nav WP
		PSTR("LOW_VOLT"), // Battery low voltage
		PSTR("VOLT_DIVIDER"), //
		PSTR("BATT_MONITOR"), //
		PSTR("BATT_CAPACITY")
	};
	uint8_t i;
	if (idx < NB_PID_PARAMS) {
		i = idx / 2;
	} else {
		i = idx - (NB_PID_PARAMS / 2);
	}
	return mav_params_id[i];
}

void setMavlinParamsValue(uint8_t idx, float val) {
	MavlinkParam_t *param = getParam(idx);
	if (idx < NB_PARAMS && val != param->value) {
		param->value = val;
		param->repeat = PARAM_NB_REPEAT;
		uint8_t link_idx = NB_PID_PARAMS;
		switch (idx) {
		case RATE_PIT_P:
		case RATE_PIT_I:
		case STB_PIT_P:
		case STB_PIT_I:
			link_idx = idx + 4;
			break;
		case RATE_RLL_P:
		case RATE_RLL_I:
		case STB_RLL_P:
		case STB_RLL_I:
			link_idx = idx - 4;
			break;
		case HLD_LON_P:
		case HLD_LON_I:
		case NAV_LON_P:
		case NAV_LON_I:
			link_idx = idx + 2;
			break;
		case HLD_LAT_P:
		case HLD_LAT_I:
		case NAV_LAT_P:
		case NAV_LAT_I:
			link_idx = idx - 2;
			break;
		default:
			break;
		}
		if (link_idx < NB_PID_PARAMS) {
			MavlinkParam_t *p = getParam(link_idx);
			p->value = val;
			p->repeat = PARAM_NB_REPEAT;
		}
	}
}

void putsMavlinParams(uint8_t x, uint8_t y, uint8_t idx, uint8_t att) {
	if (idx < NB_PARAMS) {
		const pm_char * s = getParamId(idx);
		char c;
		while ((c = pgm_read_byte(s++))) {
			lcd_putcAtt(x, y, (c == '_' ? ' ' : c), 0);
			x += FW;
		}
		if (idx < NB_PID_PARAMS) {
			x = 11 * FW;
			lcd_putcAtt(x, y, "PI"[idx & 0x01], att);
		}
	}
}

static inline void setParamValue(int8_t *id, float value) {
	int8_t *p_id;
	for (int8_t idx = 0; idx < NB_PARAMS; idx++) {
		const pm_char * s = getParamId(idx);
		p_id = id;
		while (1) {
			char c1 = pgm_read_byte(s++);
			if (!c1) {
				// Founded !
				uint8_t founded = !*p_id;
				if (idx < NB_PID_PARAMS) {
					p_id++;
					switch (*p_id++) {
					case 'P':
						founded = !*p_id;
						break;
					case 'I':
						founded = !*p_id;
						idx++;
						break;
					default:
						founded = 0;
						break;
					}
				}
				// test end of string char == 0 and a valid PI
				if (founded) {
					MavlinkParam_t *param = getParam(idx);
					param->repeat = 0;
					param->valid = 1;
					param->value = value;
					mav_req_params_nb_recv++;
				}
				return;
			} else if (c1 != *p_id++) {
				break;
			}
		}
		if (idx < NB_PID_PARAMS) {
			// Skip I Parameter from PID
			idx++;
		}
	}
}

static inline void REC_MAVLINK_MSG_ID_PARAM_VALUE(const mavlink_message_t* msg) {
	mavlink_param_value_t param_value;
	mavlink_msg_param_value_decode(msg, &param_value);
	char *id = param_value.param_id;
	setParamValue((int8_t*)id, param_value.param_value);
	//data_stream_start_stop = 0; // stop data stream while getting params list
	watch_mav_req_params_list = mav_req_params_nb_recv < (NB_PARAMS - 5) ? 20 : 0; // stop timeout
}
#endif


#ifdef MAVLINK_PARAMS
static inline void MAVLINK_msg_param_request_list_send() {
	mavlink_channel_t chan = MAVLINK_COMM_0;
	mavlink_msg_param_request_list_send(chan, mavlink_system.sysid, mavlink_system.compid);
}

static inline void MAVLINK_msg_param_set(uint8_t idx) {
	const pm_char* s = getParamId(idx);
	int8_t buf[15];
	int8_t *p = buf;
	while (1) {
		char c = pgm_read_byte(s++);
		if (!c) {
			if (idx < NB_PID_PARAMS) {
				*p++ = '_';
				uint8_t colIdx = idx & 0x01;
				*p++ = "PI"[colIdx];
			}
			*p++ = 0;
			break;
		}
		*p++ = c;
	}
	//float param_value = ((float) mavlinkRT.params[idx].pi_param[subIdx].pi_value / 100.00 + 0.005);
	float param_value = getParam(idx)->value;

	mavlink_channel_t chan = MAVLINK_COMM_0;
	uint8_t param_type = (uint8_t)MAV_PARAM_TYPE_REAL32;
	const char* param_id = (const char*)buf;
	mavlink_msg_param_set_send(chan, mavlink_system.sysid, mavlink_system.compid, param_id, param_value, param_type);

}
#endif

/*
static inline void MAVLINK_msg_request_data_stream_pack_send(uint8_t req_stream_id, uint16_t req_message_rate, uint8_t start_stop) {
	mavlink_channel_t chan = MAVLINK_COMM_0;
	mavlink_msg_request_data_stream_send(chan, mavlink_system.sysid, mavlink_system.compid, req_stream_id, req_message_rate, start_stop);
}
*/
/* Decode the various messages groups APM can send
 * 
 */
static inline void handleMessage(mavlink_message_t* pmavlink_msg) {
	switch (pmavlink_msg->msgid) {
		case MAVLINK_MSG_ID_HEARTBEAT:
			REC_MAVLINK_MSG_ID_HEARTBEAT(pmavlink_msg);
			break;
		case MAVLINK_MSG_ID_STATUSTEXT:
			REC_MAVLINK_MSG_ID_STATUSTEXT(pmavlink_msg);
			AUDIO_WARNING1();
			break;
		case MAVLINK_MSG_ID_SYS_STATUS:
			REC_MAVLINK_MSG_ID_SYS_STATUS(pmavlink_msg);
			break;
		case MAVLINK_MSG_ID_RC_CHANNELS_RAW:
			REC_MAVLINK_MSG_ID_RC_CHANNELS_RAW(pmavlink_msg);
			break;
		case MAVLINK_MSG_ID_RADIO:
			REC_MAVLINK_MSG_ID_RADIO(pmavlink_msg);
			break;
		case MAVLINK_MSG_ID_RADIO_STATUS:
			REC_MAVLINK_MSG_ID_RADIO_STATUS(pmavlink_msg);
			break;
		case MAVLINK_MSG_ID_NAV_CONTROLLER_OUTPUT:
			REC_MAVLINK_MSG_ID_NAV_CONTROLLER_OUTPUT(pmavlink_msg);
			break;
		case MAVLINK_MSG_ID_VFR_HUD:
			REC_MAVLINK_MSG_ID_VFR_HUD(pmavlink_msg);
			break;
		case MAVLINK_MSG_ID_HIL_CONTROLS:
			REC_MAVLINK_MSG_ID_HIL_CONTROLS(pmavlink_msg);
			break;
		case MAVLINK_MSG_ID_GPS_RAW_INT:
			REC_MAVLINK_MSG_ID_GPS_RAW_INT(pmavlink_msg);
			break;
		case MAVLINK_MSG_ID_ATTITUDE:
			REC_MAVLINK_MESSAGE_INFO_ATTITUDE(pmavlink_msg);
			break;
		case MAVLINK_MSG_ID_SYSTEM_TIME:
			REC_MAVLINK_MESSAGE_INFO_SYSTEM_TIME(pmavlink_msg);
			break;
			
	#ifdef MAVLINK_PARAMS
		case MAVLINK_MSG_ID_PARAM_VALUE:
			REC_MAVLINK_MSG_ID_PARAM_VALUE(pmavlink_msg);
			break;
	#endif
		default:
			mavlinkRT.unknow_pckt_cnt++;
			break;
	}

}


/*!	\brief Looks like some kind of task switcher on a timer
 *	\todo Figure out where this was used for and integrate in current
 *	implemnetation. Function disabled without any side affects.
 */
#if 0
 void MAVLINK10mspoll(uint8_t count) {
	switch (count) {
	case 2: // MAVLINK_MSG_ID_ACTION
		if (watch_mav_req_id_action > 0) {
			watch_mav_req_id_action--;
			// Repeat  is not ack : 150ms*0x07
			if ((watch_mav_req_id_action & 0x07) == 0) {
				uint8_t action = MAVLINK_CtrlMode2Action(mavlinkRT.req_mode);
				MAVLINK_msg_action_pack_send(action);
				char *ptr = mav_statustext;
				*ptr++ = 'R';
				*ptr++ = 'Q';
				*ptr++ = ' ';
				*ptr++ = action / 10 + '0';
				*ptr++ = action % 10 + '0';
				*ptr++ = 0;
			}
		}
		if (mavlinkRT.ack_result < 5) {
			if (mavlinkRT.ack_result > 0) {
				mavlinkRT.ack_result++;
			}
		}
		break;
#ifdef MAVLINK_PARAMS
	case 4: // MAVLINK_MSG_ID_PARAM_REQUEST_LIST
		if (watch_mav_req_params_list > 0) {
			watch_mav_req_params_list--;
			if (watch_mav_req_params_list == 0) {
				mav_req_params_nb_recv = 0;
				MAVLINK_msg_param_request_list_send();
				watch_mav_req_params_list = 20;
			}
		}
		break;
#endif
	case 6: // MAVLINK_MSG_ID_REQUEST_DATA_STREAM
		if (watch_mav_req_start_data_stream > 0) {
			watch_mav_req_start_data_stream--;
			if (watch_mav_req_start_data_stream == 0) {
				uint8_t req_stream_id = 2;
				uint16_t req_message_rate = 1;

				MAVLINK_msg_request_data_stream_pack_send(req_stream_id, req_message_rate, data_stream_start_stop);
				watch_mav_req_start_data_stream = 20;
				data_stream_start_stop = 1; // maybe start next time
			}
		}
		break;
#ifdef MAVLINK_PARAMS
	case 8: // MAVLINK_MSG_ID_PARAM_SET
		if (watch_mav_req_params_set > 0) {
			watch_mav_req_params_set--;
			if (watch_mav_req_params_set == 0) {
				for (uint8_t idx = 0; idx < NB_PARAMS; idx++) {
					if (getParam(idx)->repeat) {
						getParam(idx)->repeat--;
						MAVLINK_msg_param_set(idx);
						watch_mav_req_params_set = 3; // 300ms
						return;
					}
				}
			}
		}
		break;
#endif
	default:
		return;
	}
}
#endif
