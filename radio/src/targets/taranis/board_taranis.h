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

#ifndef board_taranis_h
#define board_taranis_h

#include "stddef.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "STM32F2xx_StdPeriph_Lib_V1.1.0/Libraries/STM32F2xx_StdPeriph_Driver/inc/stm32f2xx_rcc.h"
#include "STM32F2xx_StdPeriph_Lib_V1.1.0/Libraries/STM32F2xx_StdPeriph_Driver/inc/stm32f2xx_gpio.h"
#include "STM32F2xx_StdPeriph_Lib_V1.1.0/Libraries/STM32F2xx_StdPeriph_Driver/inc/stm32f2xx_spi.h"
#include "STM32F2xx_StdPeriph_Lib_V1.1.0/Libraries/STM32F2xx_StdPeriph_Driver/inc/stm32f2xx_rtc.h"
#include "STM32F2xx_StdPeriph_Lib_V1.1.0/Libraries/STM32F2xx_StdPeriph_Driver/inc/stm32f2xx_pwr.h"
#include "STM32F2xx_StdPeriph_Lib_V1.1.0/Libraries/STM32F2xx_StdPeriph_Driver/inc/stm32f2xx_dma.h"
#include "STM32F2xx_StdPeriph_Lib_V1.1.0/Libraries/STM32F2xx_StdPeriph_Driver/inc/stm32f2xx_usart.h"
#include "STM32F2xx_StdPeriph_Lib_V1.1.0/Libraries/CMSIS/Device/ST/STM32F2xx/Include/stm32f2xx.h"

#if !defined(SIMU)
  #include "STM32_USB-Host-Device_Lib_V2.1.0/Libraries/STM32_USB_Device_Library/Class/msc/inc/usbd_msc_core.h"
  #include "STM32_USB-Host-Device_Lib_V2.1.0/Libraries/STM32_USB_Device_Library/Class/hid/inc/usbd_hid_core.h"
  #include "STM32_USB-Host-Device_Lib_V2.1.0/Libraries/STM32_USB_Device_Library/Core/inc/usbd_usr.h"
  #include "usbd_desc.h"
  #include "usb_conf.h"
  #include "usbd_conf.h"
#endif

#include "hal.h"
#include "aspi.h"
#include "i2c.h"

#ifdef __cplusplus
}
#endif

#if !defined(BOOT)
#include "audio_driver.h"
#endif

#define FLASHSIZE          0x80000
#define BOOTLOADER_SIZE    0x8000
#define FIRMWARE_ADDRESS   0x08000000

#define PERI1_FREQUENCY    30000000
#define PERI2_FREQUENCY    60000000
#define TIMER_MULT_APB1    2
#define TIMER_MULT_APB2    2

#define JACK_PPM_OUT()
#define JACK_PPM_IN()

#define PIN_MODE_MASK      0x0003
#define PIN_INPUT          0x0000
#define PIN_OUTPUT         0x0001
#define PIN_PERIPHERAL     0x0002
#define PIN_ANALOG         0x0003
#define PIN_PULL_MASK      0x000C
#define PIN_PULLUP         0x0004
#define PIN_NO_PULLUP      0x0000
#define PIN_PULLDOWN       0x0008
#define PIN_NO_PULLDOWN    0x0000
#define PIN_PERI_MASK      0x00F0
#define PIN_PUSHPULL       0x0000
#define PIN_ODRAIN         0x8000
#define PIN_PORT_MASK      0x0700
#define PIN_SPEED_MASK     0x6000

void configure_pins( uint32_t pins, uint16_t config );

#define strcpy_P strcpy
#define strcat_P strcat

extern uint16_t sessionTimer;

#define SLAVE_MODE()         (g_model.trainerMode == 1)
#define TRAINER_CONNECTED()  (GPIO_ReadInputDataBit(GPIOTRNDET, PIN_TRNDET) == Bit_RESET)

void delaysInit(void);

void delaysInit(void);
void delay_01us(uint16_t nb);

// SD driver
#if defined(SIMU)
  #define sdInit()
  #define sdDone()
#else
  #define SD_IS_HC()              (1)
  #define SD_GET_SIZE_MB()        (0)
  #define SD_GET_BLOCKNR()        (0)
  #define SD_GET_SPEED()          (0)
  void sdInit(void);
  void sdDone(void);
  void sdPoll10ms(void);
  #define sdMountPoll()
  uint32_t sdMounted(void);
  #define SD_CARD_PRESENT()       (~SD_PRESENT_GPIO->IDR & SD_PRESENT_GPIO_Pin)
#endif

// Flash Write driver
#define FLASH_PAGESIZE 256
void unlockFlash(void);
void lockFlash(void);
void writeFlash(uint32_t * address, uint32_t * buffer);
uint32_t isFirmwareStart(const void * buffer);
uint32_t isBootloaderStart(const void * buffer);

// Pulses driver
void init_no_pulses(uint32_t port);
void disable_no_pulses(uint32_t port);
void init_ppm( uint32_t module_index );
void disable_ppm( uint32_t module_index );
void init_pxx( uint32_t module_index );
void disable_pxx( uint32_t module_index );
void init_dsm2( uint32_t module_index );
void disable_dsm2( uint32_t module_index );

// Trainer driver
void init_trainer_ppm(void);
void stop_trainer_ppm(void);
void init_trainer_capture(void);
void stop_trainer_capture(void);

// Keys driver
void keysInit(void);
uint32_t readKeys(void);
uint32_t readTrims(void);
#define TRIMS_PRESSED() (readTrims())
#define KEYS_PRESSED()  (~readKeys())
#define DBLKEYS_PRESSED_RGT_LFT(i) ((in & ((2<<KEY_PLUS) + (2<<KEY_MINUS))) == ((2<<KEY_PLUS) + (2<<KEY_MINUS)))
#define DBLKEYS_PRESSED_UP_DWN(i)  ((in & ((2<<KEY_MENU) + (2<<KEY_PAGE))) == ((2<<KEY_MENU) + (2<<KEY_PAGE)))
#define DBLKEYS_PRESSED_RGT_UP(i)  ((in & ((2<<KEY_ENTER) + (2<<KEY_MINUS))) == ((2<<KEY_ENTER) + (2<<KEY_MINUS)))
#define DBLKEYS_PRESSED_LFT_DWN(i) ((in & ((2<<KEY_PAGE) + (2<<KEY_EXIT))) == ((2<<KEY_PAGE) + (2<<KEY_EXIT)))

// WDT driver
#if !defined(SIMU)
#define wdt_disable()
void watchdogInit(unsigned int duration);
#define wdt_enable(x)   watchdogInit(1500)
#define wdt_reset()     IWDG->KR = 0xAAAA
#define WAS_RESET_BY_WATCHDOG()   (RCC->CSR & (RCC_CSR_WDGRSTF | RCC_CSR_WWDGRSTF))
#define WAS_RESET_BY_SOFTWARE()   (RCC->CSR & RCC_CSR_SFTRSTF)
#endif

// ADC driver
void adcInit(void);
void adcRead(void);
extern volatile uint16_t Analog_values[];
#if defined(REV3)
  #define BATT_SCALE    120
#else
  #define BATT_SCALE    150
#endif

#ifdef __cplusplus
extern "C" {
#endif

// Power driver
void pwrInit(void);
uint32_t pwrCheck(void);
void pwrOff(void);
#define UNEXPECTED_SHUTDOWN() (g_eeGeneral.unexpectedShutdown)
#define INTERNAL_RF_ON()      GPIO_SetBits(GPIO_INT_RF_PWR, PIN_INT_RF_PWR)
#define INTERNAL_RF_OFF()     GPIO_ResetBits(GPIO_INT_RF_PWR, PIN_INT_RF_PWR)
#define EXTERNAL_RF_ON()      GPIO_SetBits(GPIO_EXT_RF_PWR, PIN_EXT_RF_PWR)
#define EXTERNAL_RF_OFF()     GPIO_ResetBits(GPIO_EXT_RF_PWR, PIN_EXT_RF_PWR)

// Backlight driver
#if defined(REVPLUS)
void turnBacklightOn(uint8_t level, uint8_t color);
void turnBacklightOff(void);
  #define setBacklight(xx)      turnBacklightOn(xx, g_eeGeneral.backlightColor)
  #define __BACKLIGHT_ON        turnBacklightOn(g_eeGeneral.backlightBright, g_eeGeneral.backlightColor)
  #define __BACKLIGHT_OFF       turnBacklightOff()
  #define IS_BACKLIGHT_ON()     (TIM4->CCR4 != 0) || (TIM4->CCR2 != 0)
#else
  #define setBacklight(xx)      TIM10->CCR1 = 100-xx
  #define __BACKLIGHT_ON        TIM10->CCR1 = 100-g_eeGeneral.backlightBright
  #define __BACKLIGHT_OFF       TIM10->CCR1 = 0
  #define IS_BACKLIGHT_ON()     (TIM10->CCR1 != 0)
#endif

// USB driver
int usbPlugged(void);
void usbInit(void);
void usbStart(void);
#if defined(USB_JOYSTICK)
void usbStop(void);
#endif

#ifdef __cplusplus
}
#endif

// EEPROM driver
#if !defined(SIMU)
#define eepromInit()          I2C_EE_Init()
#define eeprom_read_block     I2C_EE_BufferRead
#define eeWriteBlockCmp       I2C_EE_BufferWrite
#else
#define eepromInit()
void eeWriteBlockCmp(const void *pointer_ram, uint16_t pointer_eeprom, size_t size);
#endif

// Debug driver
void debugPutc(const char c);

// Telemetry driver
void telemetryPortInit(uint32_t baudrate);

// Haptic driver
void hapticInit(void);
void hapticOff(void);
#define HAPTIC_OFF()    hapticOff()
#if defined(REVPLUS)
  void hapticOn(uint32_t pwmPercent);
#else
  void hapticOn(void);
  #define HAPTIC_ON()   hapticOn()
#endif

// UART3 driver
#define DEBUG_BAUDRATE      115200
void telemetrySecondPortInit(uint32_t);
void uart3Putc(const char c);

extern uint8_t currentTrainerMode;

#endif
