/****************************************************************************
 *  Copyright (c) 2014 by Michael Blandford. All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *  1. Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *  3. Neither the name of the author nor the names of its contributors may
 *     be used to endorse or promote products derived from this software
 *     without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
 *  THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 *  OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 *  AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 *  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
 *  THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 *  SUCH DAMAGE.
 *
 ****************************************************************************
 * Other Authors:
 * - Andre Bernet
 * - Bertrand Songis
 * - Bryan J. Rentoul (Gruvin)
 * - Cameron Weeks
 * - Erez Raviv
 * - Jean-Pierre Parisy
 * - Karl Szmutny
 * - Michal Hlavinka
 * - Pat Mackenzie
 * - Philip Moss
 * - Rob Thomson
 * - Romolo Manfredini
 * - Thomas Husterer
 *
 ****************************************************************************/

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "board_taranis.h"
#include "../eeprom_rlc.h"
#include "../pwr.h"
#include "../lcd.h"
#include "../keys.h"
//#include "../sdcard.h"
#include "../FatFs/ff.h"
#include "../FatFs/diskio.h"
#include "../translations/en.h"
#include "../stamp-opentx.h"

#if defined(PCBTARANIS)
  #define BOOTLOADER_TITLE      " Taranis BootLoader - " VERS_STR
  #define BOOT_KEY_UP		KEY_PLUS
  #define BOOT_KEY_DOWN		KEY_MINUS
  #define BOOT_KEY_LEFT		KEY_MENU
  #define BOOT_KEY_RIGHT	KEY_PAGE
  #define BOOT_KEY_MENU		KEY_ENTER
  #define BOOT_KEY_EXIT		KEY_EXIT
  #define DISPLAY_CHAR_WIDTH	35
#elif defined(PCBSKY9X)
  #define BOOTLOADER_TITLE      "Sky9x Boot Loader - " VERS_STR
#endif

const uint8_t bootloaderVersion[] __attribute__ ((section(".version"), used)) =
{
  'B', 'O', 'O', 'T', '1', '0'
};

// states
enum BootLoaderStates {
  ST_START,
  ST_FLASH_MENU,
  ST_DIR_CHECK,
  ST_OPEN_DIR,
  ST_FILE_LIST,
  ST_FLASH_CHECK,
  ST_FLASHING,
  ST_FLASH_DONE,
  ST_RESTORE_MENU,
  ST_USB,
  ST_REBOOT,
};

enum MemoryTypes {
  MEM_FLASH,
  MEM_EEPROM
};

#define BLOCK_LEN 4096

/*----------------------------------------------------------------------------
 *        Local variables
 *----------------------------------------------------------------------------*/

uint32_t FirmwareSize;
uint32_t firmwareAddress = FIRMWARE_ADDRESS;
uint32_t firmwareWritten = 0;
uint32_t eepromAddress = 0;
uint32_t eepromWritten = 0;

TCHAR backupFilename[60];

uint32_t Master_frequency;
volatile uint8_t Tenms;
uint8_t EE_timer;

FIL FlashFile;
DIR Dj;
FILINFO Finfo;

TCHAR Filenames[20][50];
uint32_t FileSize[20];
uint32_t FnStartIndex;
uint32_t Valid;

uint32_t FlashSize;

uint32_t LockBits;

uint32_t Block_buffer[1024];
UINT BlockCount;

uint32_t memoryType;

uint32_t unlocked = 0;

#if defined(PCBSKY9X)
  extern int32_t EblockAddress;
#endif

extern uint32_t EepromBlocked;

extern void init_spi(void);
extern void writeBlock(void);
extern void usbPluggedIn();

/*----------------------------------------------------------------------------
 *         Global functions
 *----------------------------------------------------------------------------*/

#if defined(PCBSKY9X)
// Starts TIMER0 at full speed (MCK/2) for delay timing
// @ 36MHz this is 18MHz
// This was 6 MHz, we may need to slow it to TIMER_CLOCK2 (MCK/8=4.5 MHz)
void start_timer0()
{
  register Tc *ptc;

  PMC->PMC_PCER0 |= 0x00800000L;		// Enable peripheral clock to TC0

  ptc = TC0;// Tc block 0 (TC0-2)
  ptc->TC_BCR = 0;// No sync
  ptc->TC_BMR = 2;
  ptc->TC_CHANNEL[0].TC_CMR = 0x00008001;// Waveform mode MCK/8 for 36MHz osc.(Upset be write below)
  ptc->TC_CHANNEL[0].TC_RC = 0xFFF0;
  ptc->TC_CHANNEL[0].TC_RA = 0;
  ptc->TC_CHANNEL[0].TC_CMR = 0x00008040;// 0000 0000 0000 0000 1000 0000 0100 0000, stop at regC, 18MHz
  ptc->TC_CHANNEL[0].TC_CCR = 5;// Enable clock and trigger it (may only need trigger)
}

void stop_timer0( void )
{
  TC0->TC_CHANNEL[0].TC_CCR = TC_CCR0_CLKDIS;		// Disable clock
}

void delay2ms()
{
  TC0->TC_CHANNEL[0].TC_CCR = 5;// Enable clock and trigger it (may only need trigger)
  while ( TC0->TC_CHANNEL[0].TC_CV < 36000 )// 2mS, Value depends on MCK/2 (used 18MHz)
  {
    // Wait
  }
}
#endif

void interrupt10ms(void)
{
  Tenms |= 1;			// 10 mS has passed

  uint32_t enuk = KEY_MENU;
  uint32_t in = ~readKeys();

  for (int i=1; i<7; ++i) {
    uint32_t value = in & (1 << i);
    keys[enuk].input(value, (EnumKeys) enuk);
    ++enuk;
  }
}

#if defined(PCBSKY9X)
void init10msTimer()
{
  register Tc *ptc;
  register uint32_t timer;

  PMC->PMC_PCER0 |= 0x02000000L;		// Enable peripheral clock to TC2

  timer = Master_frequency / 12800;// MCK/128 and 100 Hz

  ptc = TC0;// Tc block 0 (TC0-2)
  ptc->TC_BCR = 0;// No sync
  ptc->TC_BMR = 0;
  ptc->TC_CHANNEL[2].TC_CMR = 0x00008000;// Waveform mode
  ptc->TC_CHANNEL[2].TC_RC = timer;// 10 Hz
  ptc->TC_CHANNEL[2].TC_RA = timer >> 1;
  ptc->TC_CHANNEL[2].TC_CMR = 0x0009C003;// 0000 0000 0000 1001 1100 0000 0000 0011
                                         // MCK/128, set @ RA, Clear @ RC waveform
  ptc->TC_CHANNEL[2].TC_CCR = 5;// Enable clock and trigger it (may only need trigger)

  NVIC_EnableIRQ(TC2_IRQn);
  TC0->TC_CHANNEL[2].TC_IER = TC_IER0_CPCS;
}

extern "C" void TC2_IRQHandler()
{
  register uint32_t dummy;

  /* Clear status bit to acknowledge interrupt */
  dummy = TC0->TC_CHANNEL[2].TC_SR;
  (void) dummy;		// Discard value - prevents compiler warning

  interrupt10ms();

}
#endif

#if defined(PCBTARANIS)
void init10msTimer()
{
  // Timer14
  RCC->APB1ENR |= RCC_APB1ENR_TIM14EN;		// Enable clock
  TIM14->ARR = 9999;	// 10mS
  TIM14->PSC = (PERI1_FREQUENCY * TIMER_MULT_APB1) / 1000000 - 1;	// 1uS from 12MHz
  TIM14->CCER = 0;
  TIM14->CCMR1 = 0;
  TIM14->EGR = 0;
  TIM14->CR1 = 5;
  TIM14->DIER |= 1;
  NVIC_EnableIRQ(TIM8_TRG_COM_TIM14_IRQn);
}

extern "C" void TIM8_TRG_COM_TIM14_IRQHandler()
{
  TIM14->SR &= ~TIM_SR_UIF;
  interrupt10ms();
}
#endif

FRESULT readBinDir(DIR *dj, FILINFO *fno)
{
  FRESULT fr;
  uint32_t loop;
  do {
    loop = 0;
    fr = f_readdir(dj, fno);		// First entry

    if (fr != FR_OK || fno->fname[0] == 0) {
      break;
    }
    if (*fno->lfname == 0) {
      strAppend(fno->lfname, fno->fname);	// Copy 8.3 name
    }
    int32_t len = strlen(fno->lfname) - 4;
    if (len < 0) {
      loop = 1;
    }
    if (fno->lfname[len] != '.') {
      loop = 1;
    }
    if ((fno->lfname[len + 1] != 'b') && (fno->lfname[len + 1] != 'B')) {
      loop = 1;
    }
    if ((fno->lfname[len + 2] != 'i') && (fno->lfname[len + 2] != 'I')) {
      loop = 1;
    }
    if ((fno->lfname[len + 3] != 'n') && (fno->lfname[len + 3] != 'N')) {
      loop = 1;
    }

  } while (loop);
  return fr;
}

uint32_t fillNames(uint32_t index)
{
  uint32_t i;
  FRESULT fr;
  Finfo.lfname = Filenames[0];
  Finfo.lfsize = 48;
  fr = f_readdir(&Dj, 0);					// rewind
  fr = f_readdir(&Dj, &Finfo);		// Skip .
  fr = f_readdir(&Dj, &Finfo);		// Skip ..
  i = 0;
  while (i <= index) {
    fr = readBinDir(&Dj, &Finfo);		// First entry
    FileSize[0] = Finfo.fsize;
    i += 1;
    if (fr == FR_NO_FILE) {
      return 0;
    }
  }
  for (i = 1; i < 7; i += 1) {
    Finfo.lfname = Filenames[i];
    fr = readBinDir(&Dj, &Finfo);		// First entry
    FileSize[i] = Finfo.fsize;
    if (fr != FR_OK || Finfo.fname[0] == 0) {
      break;
    }
  }
  return i;
}

const char *getBinaryPath()
{
  if (memoryType == MEM_FLASH)
    return FIRMWARES_PATH;
  else
    return EEPROMS_PATH;
}

FRESULT openBinaryFile(uint32_t index)
{
  TCHAR filename[60];
  FRESULT fr;
  memset(Block_buffer, 0, sizeof(Block_buffer));
  strAppend(strAppend(strAppend(filename, getBinaryPath()), "/"), Filenames[index]);
  if ((fr = f_open(&FlashFile, filename, FA_READ)) != FR_OK) {
    return fr;
  }
  if (memoryType == MEM_FLASH) {
    if ((fr = f_lseek(&FlashFile, BOOTLOADER_SIZE)) != FR_OK) {
      return fr;
    }
  }
  fr = f_read(&FlashFile, (BYTE *)Block_buffer, BLOCK_LEN, &BlockCount);
  
  if (BlockCount == BLOCK_LEN)
    return fr;
  else
    return FR_INVALID_OBJECT;
}

uint32_t isValidBufferStart(const void * buffer)
{
  if (memoryType == MEM_FLASH)
    return isFirmwareStart(buffer);
  else
    return isEepromStart(buffer);
}

int menuFlashFile(uint32_t index, uint8_t event)
{
  FRESULT fr;

  lcd_putsLeft(4*FH, "\012Hold [ENT] to start writing");

  if (Valid == 0) {
    // Validate file here
    if ((fr = openBinaryFile(index))) {
      Valid = 2;
    }
    else {
      if ((fr = f_close(&FlashFile))) {
        Valid = 2;
      }
      else {
        Valid = 1;
      }
      if (!isValidBufferStart(Block_buffer)) {
        Valid = 2;
      }
    }
  }

  if (Valid == 2) {
    if (memoryType == MEM_FLASH)
      lcd_putsLeft(4*FH,  "\011Not a valid firmware file!        ");
    else
      lcd_putsLeft(4*FH,  "\011Not a valid EEPROM file!          ");    
    if (event == EVT_KEY_BREAK(BOOT_KEY_EXIT) || event == EVT_KEY_BREAK(BOOT_KEY_MENU)) {
      return 0;
    }
    return -1;
  }

  if (event == EVT_KEY_LONG(BOOT_KEY_MENU)) {
    fr = openBinaryFile(index);
    return (fr == FR_OK && isValidBufferStart(Block_buffer));
  }
  else if (event == EVT_KEY_FIRST(BOOT_KEY_EXIT)) {
    return 0;
  }

  return -1;
}

extern Key keys[];

static uint32_t PowerUpDelay;

void writeFlashBlock()
{
  uint32_t blockOffset = 0;
  while (BlockCount) {
    writeFlash((uint32_t *)firmwareAddress, &Block_buffer[blockOffset]);
    blockOffset += FLASH_PAGESIZE/4; // 32-bit words
    firmwareAddress += FLASH_PAGESIZE;
    if (BlockCount > FLASH_PAGESIZE) {
      BlockCount -= FLASH_PAGESIZE;
    }
    else {
      BlockCount = 0;
    }
  }
}

void writeEepromBlock()
{
  eeWriteBlockCmp((uint8_t *)Block_buffer, eepromAddress, BlockCount);
  eepromAddress += BlockCount;
}

int main()
{
  uint32_t index = 0;
  uint32_t maxhsize = DISPLAY_CHAR_WIDTH;
  FRESULT fr;
  uint32_t state = ST_START;
  uint32_t nameCount = 0;
  uint32_t vpos = 0;
  uint32_t hpos = 0;

#if defined(PCBTARANIS)
  wdt_reset();
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; 		// Enable portA clock
#endif

  pwrInit();

#if defined(PCBSKY9X)
  MATRIX->CCFG_SYSIO |= 0x000000F0L;		// Disable syspins, enable B4,5,6,7
#endif

#if defined(PCBSKY9X)
  init_SDcard();
  PIOC->PIO_PER = PIO_PC25;		// Enable bit C25 (USB-detect)
  start_timer0();
#endif

#if defined(PCBTARANIS)
  delaysInit();               //needed for lcdInit()
#endif 
  lcdInit();

#if defined(PCBSKY9X)
  extern uint8_t OptrexDisplay;
  OptrexDisplay = 1;
#endif
  lcd_clear();
  lcd_putsLeft(0, BOOTLOADER_TITLE);
  lcd_invert_line(0);
  lcdRefresh();
#if defined(PCBSKY9X)
  OptrexDisplay = 0;
  lcdRefresh();
#endif

#if defined(PCBTARANIS)
#if defined(REVPLUS)
  turnBacklightOn(0, 0);
#endif
  keysInit();
  I2C_EE_Init();
#endif

  __enable_irq();
  init10msTimer();

#if defined(PCBSKY9X)
  EblockAddress = -1;
  init_spi();
#endif

#if defined(PCBSKY9X)
  LockBits = readLockBits();
  if (LockBits) {
    clearLockBits();
  }
#endif

#if defined(PCBTARANIS)
  // SD card detect pin
  sdInit();
  usbInit();
  usbStart();
#endif

  for (;;) {
    wdt_reset();

    if (Tenms) {

      if (EE_timer) {
        if (--EE_timer == 0) {
#if defined(PCBSKY9X)
          writeBlock();
#endif
        }
      }

      Tenms = 0;

      lcd_clear();
      lcd_putsLeft(0, BOOTLOADER_TITLE);
      lcd_invert_line(0);

      uint8_t event = getEvent();

      if (state != ST_USB) {
        if (usbPlugged()) {
          state = ST_USB;
          if (!unlocked) {
            unlocked = 1;
            unlockFlash();
          }
          usbPluggedIn();
        }
      }

      if (state == ST_START) {
        lcd_putsLeft(2*FH, "\010Write Firmware");
        lcd_putsLeft(3*FH, "\010Restore EEPROM");
        lcd_putsLeft(4*FH, "\010Exit");
        lcd_invert_line(2+vpos);
        lcd_putsLeft(7*FH, INDENT "Or plug in a USB cable for mass storage");
        if (event == EVT_KEY_FIRST(BOOT_KEY_DOWN)) {
          vpos == 2 ? vpos = 0 : vpos = vpos+1;
        }
        else if (event == EVT_KEY_FIRST(BOOT_KEY_UP)) {
          vpos == 0 ? vpos = 2 : vpos = vpos-1;
        }
        else if (event == EVT_KEY_BREAK(BOOT_KEY_MENU)) {
          switch (vpos) {
            case 0:
              state = ST_FLASH_MENU;
              break;
            case 1:
              state = ST_RESTORE_MENU;
              break;
            default:
              state = ST_REBOOT;
          }
        }
      }

      if (state == ST_USB) {
        lcd_putsLeft(4*FH, "\026USB Connected");
        if (usbPlugged() == 0) {
          vpos = 0;
          if (unlocked) {
            lockFlash();
            unlocked = 0;
          }
          state = ST_START;
        }
#if defined(PCBSKY9X)
        usbMassStorage();
#endif
      }

      if (state == ST_FLASH_MENU || state == ST_RESTORE_MENU) {
        sdInit();
        memoryType = (state == ST_RESTORE_MENU ? MEM_EEPROM : MEM_FLASH);
        state = ST_DIR_CHECK;
      }

      else if (state == ST_DIR_CHECK) {
        fr = f_chdir(getBinaryPath());
        if (fr == FR_OK) {
          state = ST_OPEN_DIR;
        }
        else {
          lcd_putsLeft(2*FH, INDENT "Directory is missing!");
          if (event == EVT_KEY_BREAK(BOOT_KEY_EXIT) || event == EVT_KEY_BREAK(BOOT_KEY_MENU)) {
            vpos = 0;
            state = ST_START;
          }
        }
      }

      if (state == ST_OPEN_DIR) {
        index = 0;
        fr = f_opendir(&Dj, ".");
        if (fr == FR_OK) {
          state = ST_FILE_LIST;
          nameCount = fillNames(0);
          hpos = 0;
          vpos = 0;
        }
      }

      if (state == ST_FILE_LIST) {
        uint32_t limit = 6;
        if (nameCount < limit) {
          limit = nameCount;
        }
        maxhsize = 0;
        for (uint32_t i=0; i<limit; i++) {
          uint32_t x;
          x = strlen(Filenames[i]);
          if (x > maxhsize) {
            maxhsize = x;
          }
          if (x > DISPLAY_CHAR_WIDTH) {
            if (hpos + DISPLAY_CHAR_WIDTH > x) {
              x = x - DISPLAY_CHAR_WIDTH;
            }
            else {
              x = hpos;
            }
          }
          else {
            x = 0;
          }
          lcd_putsnAtt(INDENT_WIDTH, 16 + FH * i, &Filenames[i][x], DISPLAY_CHAR_WIDTH, 0);
        }

        if (event == EVT_KEY_REPT(BOOT_KEY_DOWN) || event == EVT_KEY_FIRST(BOOT_KEY_DOWN)) {
          if (vpos < limit - 1) {
            vpos += 1;
          }
          else {
            if (nameCount > limit) {
              index += 1;
              nameCount = fillNames(index);
            }
          }
        }
        else if (event == EVT_KEY_REPT(BOOT_KEY_UP) || event == EVT_KEY_FIRST(BOOT_KEY_UP)) {
          if (vpos > 0) {
            vpos -= 1;
          }
          else {
            if (index) {
              index -= 1;
              nameCount = fillNames(index);
            }
          }
        }
#if !defined(PCBTARANIS)
        else if (event == EVT_KEY_REPT(BOOT_KEY_RIGHT) || event == EVT_KEY_FIRST(BOOT_KEY_RIGHT)) {
          if (hpos + DISPLAY_CHAR_WIDTH < maxhsize) {
            hpos += 1;
          }
        }
        else if (event == EVT_KEY_REPT(BOOT_KEY_LEFT) || event == EVT_KEY_FIRST(BOOT_KEY_LEFT)) {
          if (hpos) {
            hpos -= 1;
          }
        }
#endif
        else if (event == EVT_KEY_BREAK(BOOT_KEY_MENU)) {
          // Select file to flash
          state = ST_FLASH_CHECK;
          Valid = 0;
        }
        else if (event == EVT_KEY_FIRST(BOOT_KEY_EXIT)) {
          state = ST_START;
          vpos = 0;
        }

        lcd_invert_line(2 + vpos);
      }

      else if (state == ST_FLASH_CHECK) {
        int result = menuFlashFile(vpos, event);
        FirmwareSize = FileSize[vpos] - BOOTLOADER_SIZE;
        if (result == 0) {
          // canceled
          state = ST_FILE_LIST;
        }
        else if (result == 1) {
          // confirmed
          firmwareAddress = FIRMWARE_ADDRESS + BOOTLOADER_SIZE;
          firmwareWritten = 0;
          eepromAddress = 0;
          eepromWritten = 0;
          state = ST_FLASHING;
        }
      }

      else if (state == ST_FLASHING) {
        // commit to flashing
        lcd_putsLeft(4*FH, "\032Writing...");
        
        if (!unlocked && (memoryType == MEM_FLASH)) {
          unlocked = 1;
          unlockFlash();
        }
        
        int progress;
        if (memoryType == MEM_FLASH) {
          writeFlashBlock();
          firmwareWritten += sizeof(Block_buffer);
          progress = (200*firmwareWritten) / FirmwareSize;
        }
        else {
          writeEepromBlock();
          eepromWritten += sizeof(Block_buffer);
          progress = (200*eepromWritten) / EESIZE;
        }

        lcd_rect( 3, 6*FH+4, 204, 7);
        lcd_hline(5, 6*FH+6, progress, FORCE);
        lcd_hline(5, 6*FH+7, progress, FORCE);
        lcd_hline(5, 6*FH+8, progress, FORCE);

        fr = f_read(&FlashFile, (BYTE *)Block_buffer, sizeof(Block_buffer), &BlockCount);
        if (BlockCount == 0) {
          state = ST_FLASH_DONE; // EOF
        }
        if (firmwareWritten >= FLASHSIZE - BOOTLOADER_SIZE) {
          state = ST_FLASH_DONE; // Backstop
        }
        if (eepromWritten >= EESIZE) {
          state = ST_FLASH_DONE; // Backstop
        }
      }

      if (state == ST_FLASH_DONE) {
        if (unlocked) {
          lockFlash();
          unlocked = 0;
        }
        lcd_putsLeft(4*FH, "\024Writing Complete");
        if (event == EVT_KEY_FIRST(BOOT_KEY_EXIT) || event == EVT_KEY_BREAK(BOOT_KEY_MENU)) {
          state = ST_START;
          vpos = 0;
        }
      }

      if (event == EVT_KEY_LONG(BOOT_KEY_EXIT)) {
        state = ST_REBOOT;
      }

      lcdRefresh();

      if (PowerUpDelay < 20) {	// 200 mS
        PowerUpDelay += 1;
      }
      else {
        sdPoll10ms();
      }
    }

    if (pwrCheck() == e_power_off && state != ST_FLASHING && state != ST_USB) {
      lcdOff();    // this drains LCD caps
      pwrOff();
      for (;;) {
        // Wait for power to go off
      }
    }

    if (state == ST_REBOOT) {
      if ((~readKeys() & 0x7E) == 0) {
        lcd_clear();
        lcdRefresh();
        RCC->CSR |= RCC_CSR_RMVF;   //clear the reset flags in RCC clock control & status register
        NVIC_SystemReset();
      }
    }
  }

  return 0;
}

