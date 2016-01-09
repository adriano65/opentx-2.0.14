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

#include "opentx.h"
#include <errno.h>
#include <fcntl.h>
#include <stdarg.h>
#include <sys/stat.h>
#if defined(RTCLOCK)
  #include <time.h>
#endif

#if defined WIN32 || !defined __GNUC__
  #include <direct.h>
#endif

#if defined(SIMU_DISKIO)
  FILE * diskImage = 0;
#endif

#if defined(SIMU_AUDIO) && defined(CPUARM)
  #include <SDL.h>
#endif

volatile uint8_t pina=0xff, pinb=0xff, pinc=0xff, pind, pine=0xff, pinf=0xff, ping=0xff, pinh=0xff, pinj=0xff, pinl=0;
uint8_t portb, portc, porth=0, dummyport;
uint16_t dummyport16;
const char *eepromFile = NULL;
FILE *fp = NULL;

#if defined(PCBTARANIS)
uint32_t Peri1_frequency ;
uint32_t Peri2_frequency ;
GPIO_TypeDef gpioa;
GPIO_TypeDef gpiob;
GPIO_TypeDef gpioc;
GPIO_TypeDef gpiod;
GPIO_TypeDef gpioe;
TIM_TypeDef tim1;
TIM_TypeDef tim3;
TIM_TypeDef tim4;
TIM_TypeDef tim8;
TIM_TypeDef tim10;
RCC_TypeDef rcc;
DMA_Stream_TypeDef dma2_stream2;
DMA_Stream_TypeDef dma2_stream6;
DMA_TypeDef dma2;
#elif defined(PCBSKY9X)
Pio Pioa, Piob, Pioc;
Pwm pwm;
Twi Twio;
Usart Usart0;
Dacc dacc;
Adc Adc0;
#endif

#if defined(PCBSKY9X)
  uint32_t eeprom_pointer;
  char* eeprom_buffer_data;
  volatile int32_t eeprom_buffer_size;
  bool eeprom_read_operation;
  #define EESIZE_SIMU (128*4096)
#else
  extern uint16_t eeprom_pointer;
  extern const char* eeprom_buffer_data;
#endif

#if !defined(EESIZE_SIMU)
  #define EESIZE_SIMU EESIZE
#endif

#if defined(SDCARD) && !defined(SKIP_FATFS_DECLARATION)
char simuSdDirectory[1024] = "";
#endif

uint8_t eeprom[EESIZE_SIMU];
sem_t *eeprom_write_sem;

#if defined(CPUARM)
#if defined(PCBTARANIS)
#define SWITCH_CASE(swtch, pin, mask) \
    case swtch: \
      if ((int)state > 0) pin &= ~(mask); else pin |= (mask); \
      break;
#else
#define SWITCH_CASE(swtch, pin, mask) \
    case swtch: \
      if ((int)state > 0) pin |= (mask); else pin &= ~(mask); \
      break;
#endif
#define SWITCH_3_CASE(swtch, pin1, pin2, mask1, mask2) \
    case swtch: \
      if ((int)state < 0) pin1 &= ~(mask1); else pin1 |= (mask1); \
      if ((int)state > 0) pin2 &= ~(mask2); else pin2 |= (mask2); \
      break;
#define KEY_CASE(key, pin, mask) \
    case key: \
      if ((int)state > 0) pin &= ~mask; else pin |= mask;\
      break;
#define TRIM_CASE KEY_CASE
#else
#define SWITCH_CASE(swtch, pin, mask) \
    case swtch: \
      if ((int)state > 0) pin &= ~(mask); else pin |= (mask); \
      break;
#define SWITCH_3_CASE(swtch, pin1, pin2, mask1, mask2) \
    case swtch: \
      if ((int)state >= 0) pin1 &= ~(mask1); else pin1 |= (mask1); \
      if ((int)state <= 0) pin2 &= ~(mask2); else pin2 |= (mask2); \
      break;
#define KEY_CASE(key, pin, mask) \
    case key: \
      if ((int)state > 0) pin |= (mask); else pin &= ~(mask);\
      break;
#define TRIM_CASE KEY_CASE
#endif

void simuSetKey(uint8_t key, bool state)
{
  switch (key) {
    KEY_CASE(KEY_MENU, GPIO_BUTTON_MENU, PIN_BUTTON_MENU)
    KEY_CASE(KEY_EXIT, GPIO_BUTTON_EXIT, PIN_BUTTON_EXIT)
#if defined(PCBTARANIS)
    KEY_CASE(KEY_ENTER, GPIO_BUTTON_ENTER, PIN_BUTTON_ENTER)
    KEY_CASE(KEY_PAGE, GPIO_BUTTON_PAGE, PIN_BUTTON_PAGE)
    KEY_CASE(KEY_MINUS, GPIO_BUTTON_MINUS, PIN_BUTTON_MINUS)
    KEY_CASE(KEY_PLUS, GPIO_BUTTON_PLUS, PIN_BUTTON_PLUS)
#else
    KEY_CASE(KEY_RIGHT, GPIO_BUTTON_RIGHT, PIN_BUTTON_RIGHT)
    KEY_CASE(KEY_LEFT, GPIO_BUTTON_LEFT, PIN_BUTTON_LEFT)
    KEY_CASE(KEY_UP, GPIO_BUTTON_UP, PIN_BUTTON_UP)
    KEY_CASE(KEY_DOWN, GPIO_BUTTON_DOWN, PIN_BUTTON_DOWN)
#endif
#if defined(PCBSKY9X) && !defined(REVX)
    KEY_CASE(BTN_REa, PIOB->PIO_PDSR, 0x40)
#elif defined(PCBGRUVIN9X) || defined(PCBMEGA2560)
    KEY_CASE(BTN_REa, pind, 0x20)
#elif defined(ROTARY_ENCODER_NAVIGATION)
    //KEY_CASE(BTN_REa, RotEncoder, 0x20)
#endif
  }
}

void simuSetTrim(uint8_t trim, bool state)
{
  // TRACE("trim=%d state=%d", trim, state);

  switch (trim) {
    TRIM_CASE(0, GPIO_TRIM_LH_L, PIN_TRIM_LH_L)
    TRIM_CASE(1, GPIO_TRIM_LH_R, PIN_TRIM_LH_R)
    TRIM_CASE(2, GPIO_TRIM_LV_DN, PIN_TRIM_LV_DN)
    TRIM_CASE(3, GPIO_TRIM_LV_UP, PIN_TRIM_LV_UP)
    TRIM_CASE(4, GPIO_TRIM_RV_DN, PIN_TRIM_RV_DN)
    TRIM_CASE(5, GPIO_TRIM_RV_UP, PIN_TRIM_RV_UP)
    TRIM_CASE(6, GPIO_TRIM_RH_L, PIN_TRIM_RH_L)
    TRIM_CASE(7, GPIO_TRIM_RH_R, PIN_TRIM_RH_R)
  }
}

// TODO use a better numbering to allow google tests to work on Taranis
void simuSetSwitch(uint8_t swtch, int8_t state)
{
  // TRACE("swtch=%d state=%d", swtch, state);
  switch (swtch) {
#if defined(PCBTARANIS)
    SWITCH_3_CASE(0, GPIO_PIN_SW_A_L, GPIO_PIN_SW_A_H, PIN_SW_A_L, PIN_SW_A_H)
    SWITCH_3_CASE(1, GPIO_PIN_SW_B_L, GPIO_PIN_SW_B_H, PIN_SW_B_L, PIN_SW_B_H)
    SWITCH_3_CASE(2, GPIO_PIN_SW_C_L, GPIO_PIN_SW_C_H, PIN_SW_C_L, PIN_SW_C_H)
    SWITCH_3_CASE(3, GPIO_PIN_SW_D_L, GPIO_PIN_SW_D_H, PIN_SW_D_L, PIN_SW_D_H)
    SWITCH_3_CASE(4, GPIO_PIN_SW_E_H, GPIO_PIN_SW_E_L, PIN_SW_E_H, PIN_SW_E_L)
    SWITCH_CASE(5, GPIO_PIN_SW_F, PIN_SW_F)
    SWITCH_3_CASE(6, GPIO_PIN_SW_G_L, GPIO_PIN_SW_G_H, PIN_SW_G_L, PIN_SW_G_H)
    SWITCH_CASE(7, GPIO_PIN_SW_H, PIN_SW_H)
#elif defined(PCBSKY9X)
    SWITCH_CASE(0, PIOC->PIO_PDSR, 1<<20)
    SWITCH_CASE(1, PIOA->PIO_PDSR, 1<<15)
    SWITCH_CASE(2, PIOC->PIO_PDSR, 1<<31)
    SWITCH_3_CASE(3, PIOC->PIO_PDSR, PIOC->PIO_PDSR, 0x00004000, 0x00000800)
    SWITCH_CASE(4, PIOA->PIO_PDSR, 1<<2)
    SWITCH_CASE(5, PIOC->PIO_PDSR, 1<<16)
    SWITCH_CASE(6, PIOC->PIO_PDSR, 1<<8)
#elif defined(PCBGRUVIN9X)
    SWITCH_CASE(0, ping, 1<<INP_G_ThrCt)
    SWITCH_CASE(1, ping, 1<<INP_G_RuddDR)
    SWITCH_CASE(2, pinc, 1<<INP_C_ElevDR)
    SWITCH_3_CASE(3, ping, pinb, (1<<INP_G_ID1), (1<<INP_B_ID2))
    SWITCH_CASE(4, pinc, 1<<INP_C_AileDR)
    SWITCH_CASE(5, ping, 1<<INP_G_Gear)
    SWITCH_CASE(6, pinb, 1<<INP_B_Trainer)
#elif defined(PCBMEGA2560)
    SWITCH_CASE(0, ping, 1<<INP_G_ThrCt)
    SWITCH_CASE(1, ping, 1<<INP_G_RuddDR)
    SWITCH_CASE(2, pinc, 1<<INP_C_ElevDR)
    SWITCH_3_CASE(3, pinc, pinc, (1<<INP_C_ID1), (1<<INP_C_ID2))
    SWITCH_CASE(4, pinc, 1<<INP_C_AileDR)
    SWITCH_CASE(5, ping, 1<<INP_G_Gear)
    SWITCH_CASE(6, pinb, 1<<INP_B_Trainer)
#else // PCB9X
#if defined(JETI) || defined(FRSKY) || defined(NMEA) || defined(ARDUPILOT)
    SWITCH_CASE(0, pinc, 1<<INP_C_ThrCt)
    SWITCH_CASE(4, pinc, 1<<INP_C_AileDR)
#else
    SWITCH_CASE(0, pine, 1<<INP_E_ThrCt)
    SWITCH_CASE(4, pine, 1<<INP_E_AileDR)
#endif
    SWITCH_3_CASE(3, ping, pine, (1<<INP_G_ID1), (1<<INP_E_ID2))
    SWITCH_CASE(1, ping, 1<<INP_G_RuddDR)
    SWITCH_CASE(2, pine, 1<<INP_E_ElevDR)
    SWITCH_CASE(5, pine, 1<<INP_E_Gear)
    SWITCH_CASE(6, pine, 1<<INP_E_Trainer)
#endif

    default:
      break;
  }
}

uint16_t getTmr16KHz()
{
  return get_tmr10ms() * 160;
}

#if !defined(PCBTARANIS)
bool eeprom_thread_running = true;
void *eeprom_write_function(void *)
{
  while (!sem_wait(eeprom_write_sem)) {
    if (!eeprom_thread_running)
      return NULL;
#if defined(CPUARM)
    if (eeprom_read_operation) {
      assert(eeprom_buffer_size);
      eeprom_read_block(eeprom_buffer_data, (const void *)(int64_t)eeprom_pointer, eeprom_buffer_size);
    }
    else {
#endif
    if (fp) {
      if (fseek(fp, eeprom_pointer, SEEK_SET) == -1)
        perror("error in fseek");
    }
    while (--eeprom_buffer_size) {
      assert(eeprom_buffer_size > 0);
      if (fp) {
        if (fwrite(eeprom_buffer_data, 1, 1, fp) != 1)
          perror("error in fwrite");
#if !defined(CPUARM)
        sleep(5/*ms*/);
#endif
      }
      else {
        memcpy(&eeprom[eeprom_pointer], eeprom_buffer_data, 1);
      }
      eeprom_pointer++;
      eeprom_buffer_data++;
      
      if (fp && eeprom_buffer_size == 1) {
        fflush(fp);
      }
    }
#if defined(CPUARM)
    }
    Spi_complete = 1;
#endif
  }
  return 0;
}
#endif

uint8_t main_thread_running = 0;
char * main_thread_error = NULL;
extern void opentxStart();
void *main_thread(void *)
{
#ifdef SIMU_EXCEPTIONS
  signal(SIGFPE, sig);
  signal(SIGSEGV, sig);

  try {
#endif

    s_current_protocol[0] = 255;

    g_menuStackPtr = 0;
    g_menuStack[0] = menuMainView;
    g_menuStack[1] = menuModelSelect;

    eeReadAll(); // load general setup and selected model

#if defined(SIMU_DISKIO)
    f_mount(&g_FATFS_Obj, "", 1);
    // call sdGetFreeSectors() now because f_getfree() takes a long time first time it's called
    sdGetFreeSectors();
#endif

#if defined(CPUARM) && defined(SDCARD)
    referenceSystemAudioFiles();
#endif

    if (g_eeGeneral.backlightMode != e_backlight_mode_off) backlightOn(); // on Tx start turn the light on

    if (main_thread_running == 1) {
      opentxStart();
    }
    else {
#if defined(CPUARM)
      eeLoadModel(g_eeGeneral.currModel);
#endif
    }

    s_current_protocol[0] = 0;

    while (main_thread_running) {
      perMain();
      sleep(10/*ms*/);
    }
#ifdef SIMU_EXCEPTIONS
  }
  catch (...) {
    main_thread_running = 0;
  }
#endif

#if defined(SIMU_DISKIO)
  if (diskImage) {
    fclose(diskImage);
  }
#endif

  return NULL;
}

#if defined WIN32 || !defined __GNUC__
#define chdir  _chdir
#define getcwd _getcwd
#endif

pthread_t main_thread_pid;
void StartMainThread(bool tests)
{
#if defined(SDCARD)
  if (strlen(simuSdDirectory) == 0)
    getcwd(simuSdDirectory, 1024);
#endif

#if defined(CPUARM)
  pthread_mutex_init(&mixerMutex, NULL);
  pthread_mutex_init(&audioMutex, NULL);
#endif

  g_tmr10ms = 1;      // must be non-zero otherwise some SF functions (that use this timer as a marker when it was last executed) will be executed twice on startup
#if defined(RTCLOCK)
  g_rtcTime = time(0);
#endif
  
  main_thread_running = (tests ? 1 : 2);
  pthread_create(&main_thread_pid, NULL, &main_thread, NULL);
}

void StopMainThread()
{
  main_thread_running = 0;
  pthread_join(main_thread_pid, NULL);
}

#if defined(CPUARM)
int Volume = volumeScale[VOLUME_LEVEL_DEF];
bool dacQueue(AudioBuffer *buffer)
{
  return false;
}

void setVolume(uint8_t volume)
{
  Volume = volumeScale[min<uint8_t>(volume, VOLUME_LEVEL_MAX)];
}
#endif

#if defined(SIMU_AUDIO) && defined(CPUARM)

int leftover_len = 0;
uint16_t leftover_data[AUDIO_BUFFER_SIZE];

void copyBuffer(uint8_t * dest, uint16_t * buff, unsigned int samples) 
{
  for(unsigned int i=0; i<samples; i++) {
    int sample = ((int32_t)(uint32_t)(buff[i]) - 0x8000);  // conversion from uint16_t 
    *((uint16_t*)dest) = (int16_t)((sample * Volume)/127);
    dest += 2;
  }
}

void fill_audio(void *udata, Uint8 *stream, int len)
{
  SDL_memset(stream, 0, len);

  if (leftover_len) {
    copyBuffer(stream, leftover_data, leftover_len);
    len -= leftover_len*2;
    stream += leftover_len*2;
    leftover_len = 0;
    // putchar('l');
  }

  if (audioQueue.filledAtleast(len/(AUDIO_BUFFER_SIZE*2)+1) ) {
    while(true) {
      AudioBuffer *nextBuffer = audioQueue.getNextFilledBuffer();
      if (nextBuffer) {
        if (len >= nextBuffer->size*2) {
          copyBuffer(stream, nextBuffer->data, nextBuffer->size);
          stream += nextBuffer->size*2;
          len -= nextBuffer->size*2;
          // putchar('+');
        }
        else {
          //partial
          copyBuffer(stream, nextBuffer->data, len/2);
          leftover_len = (nextBuffer->size-len/2);
          memcpy(leftover_data, &nextBuffer->data[len/2], leftover_len*2);
          len = 0;
          // putchar('p');
          break;
        }
      }
      else {
        break;
      }
    }
  }

  //fill the rest of buffer with silence
  if (len > 0) {
    SDL_memset(stream, 0x8000, len);  // make sure this is silence.
    // putchar('.');
  }
}

bool audio_thread_running = false;

void *audio_thread(void *)
{
  /*
    Checking here if SDL audio was initialized is wrong, because
    the SDL_CloseAudio() de-initializes it.

    if ( !SDL_WasInit(SDL_INIT_AUDIO) ) {
      fprintf(stderr, "ERROR: couldn't initialize SDL audio support\n");
      return 0;
    }
  */

  SDL_AudioSpec wanted, have;

  /* Set the audio format */
  wanted.freq = AUDIO_SAMPLE_RATE;
  wanted.format = AUDIO_S16SYS;
  wanted.channels = 1;    /* 1 = mono, 2 = stereo */
  wanted.samples = AUDIO_BUFFER_SIZE*2;  /* Good low-latency value for callback */
  wanted.callback = fill_audio;
  wanted.userdata = NULL;

  /*
    SDL_OpenAudio() internally calls SDL_InitSubSystem(SDL_INIT_AUDIO),
    which initializes SDL Audio subsystem if necessary
  */
  if ( SDL_OpenAudio(&wanted, &have) < 0 ) {
    fprintf(stderr, "Couldn't open audio: %s\n", SDL_GetError());
    return 0;
  }
  SDL_PauseAudio(0);

  while (audio_thread_running) {
    audioQueue.wakeup();
    sleep(1);
  }
  SDL_CloseAudio();
  return 0;
}

pthread_t audio_thread_pid;

void StartAudioThread()
{ 
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  struct sched_param sp;
  sp.sched_priority = SCHED_RR;
  pthread_attr_setschedparam(&attr, &sp);
  pthread_create(&audio_thread_pid, &attr, &audio_thread, NULL);
  audio_thread_running = true;
  return;
}

void StopAudioThread()
{
  audio_thread_running = false;
  pthread_join(audio_thread_pid, NULL);
}
#endif // #if defined(CPUARM)

pthread_t eeprom_thread_pid;

void StartEepromThread(const char *filename)
{
  eepromFile = filename;
  if (eepromFile) {
    fp = fopen(eepromFile, "rb+");
    if (!fp)
      fp = fopen(eepromFile, "wb+");
    if (!fp) perror("error in fopen");
  }
#ifdef __APPLE__
  eeprom_write_sem = sem_open("eepromsem", O_CREAT, S_IRUSR | S_IWUSR, 0);
#else
  eeprom_write_sem = (sem_t *)malloc(sizeof(sem_t));
  sem_init(eeprom_write_sem, 0, 0);
#endif

#if !defined(PCBTARANIS)
  eeprom_thread_running = true;
  assert(!pthread_create(&eeprom_thread_pid, NULL, &eeprom_write_function, NULL));
#endif
}

void StopEepromThread()
{
#if !defined(PCBTARANIS)
  eeprom_thread_running = false;
  sem_post(eeprom_write_sem);
  pthread_join(eeprom_thread_pid, NULL);
#endif
}

#if defined(PCBTARANIS)
void eeprom_read_block (void *pointer_ram, uint16_t pointer_eeprom, size_t size)
#else
void eeprom_read_block (void *pointer_ram, const void *pointer_eeprom, size_t size)
#endif
{
  assert(size);

  if (fp) {
    // TRACE("EEPROM read (pos=%d, size=%d)", pointer_eeprom, size);
    if (fseek(fp, (long)pointer_eeprom, SEEK_SET)==-1) perror("error in fseek");
    if (fread(pointer_ram, size, 1, fp) <= 0) perror("error in fread");
  }
  else {
    memcpy(pointer_ram, &eeprom[(uint64_t)pointer_eeprom], size);
  }
}

#if defined(PCBTARANIS)
void eeWriteBlockCmp(const void *pointer_ram, uint16_t pointer_eeprom, size_t size)
{
  assert(size);

  if (fp) {
    // TRACE("EEPROM write (pos=%d, size=%d)", pointer_eeprom, size);
    if (fseek(fp, (long)pointer_eeprom, SEEK_SET)==-1) perror("error in fseek");
    if (fwrite(pointer_ram, size, 1, fp) <= 0) perror("error in fwrite");
  }
  else {
    memcpy(&eeprom[(uint64_t)pointer_eeprom], pointer_ram, size);
  }
}

#endif

#if defined(CPUARM)
uint16_t stack_free(uint8_t)
#else
uint16_t stack_free()
#endif
{
  return 500;
}

#if 0
static void EeFsDump(){
  for(int i=0; i<EESIZE; i++)
  {
    printf("%02x ",eeprom[i]);
    if(i%16 == 15) puts("");
  }
  puts("");
}
#endif

#if defined(SDCARD) && !defined(SKIP_FATFS_DECLARATION) && !defined(SIMU_DISKIO)
namespace simu {
#include <dirent.h>
#if !defined WIN32
  #include <libgen.h>
#endif
}
#include "FatFs/ff.h"

#if defined WIN32 || !defined __GNUC__
#include <direct.h>
#include <stdlib.h>
#endif

#include <map>
#include <string>

#if defined(CPUARM)
FATFS g_FATFS_Obj;
#endif

char *convertSimuPath(const char *path)
{
  static char result[1024];
  if (path[0] == '/' && strcmp(simuSdDirectory, "/") != 0)
    sprintf(result, "%s%s", simuSdDirectory, path);
  else
    strcpy(result, path);

  return result;
}

typedef std::map<std::string, std::string> filemap_t;

filemap_t fileMap;

char *findTrueFileName(const char *path)
{
  TRACE("findTrueFileName(%s)", path);
  static char result[1024];
  filemap_t::iterator i = fileMap.find(path);
  if (i != fileMap.end()) {
    strcpy(result, i->second.c_str());
    TRACE("\tfound in map: %s", result);
    return result;
  }
  else {
    //find file
    //add to map
#if defined WIN32 || !defined __GNUC__
    char drive[_MAX_DRIVE];
    char dir[_MAX_DIR];
    char fname[_MAX_FNAME];
    char ext[_MAX_EXT];
    _splitpath(path, drive, dir, fname, ext);
    std::string fileName = std::string(fname) + "." + std::string(ext);
    std::string dirName = std::string(drive) + std::string(dir);
    if (dir) {
      // TRACE("\tsearching for: %s", fileName.c_str());
      WIN32_FIND_DATA ffd;
      HANDLE hFind = FindFirstFile(dirName.c_str(), &ffd);
      if (INVALID_HANDLE_VALUE != hFind) {
        do {
          if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY == 0) {
            // TRACE("comparing with: %s", ffd.cFileName);
            if (!strcasecmp(fileName.c_str(), ffd.cFileName)) {
              strcpy(result, dirName.c_str());
              strcat(result, "/");
              strcat(result, ffd.cFileName);
              TRACE("\tfound: %s", ffd.cFileName);
              fileMap.insert(filemap_t:: value_type(path, result));
              return result;  
            }
          }
        }
        while (FindNextFile(hFind, &ffd) != 0);
      }
    }
#else
    strcpy(result, path);
    std::string fileName = simu::basename(result);
    strcpy(result, path);
    std::string dirName = simu::dirname(result);
    simu::DIR * dir = simu::opendir(dirName.c_str());
    if (dir) {
      // TRACE("\tsearching for: %s", fileName.c_str());
      for (;;) {
        struct simu::dirent * res = simu::readdir(dir);
        if (res == 0) break;
        if ((res->d_type == simu::DT_REG) || (res->d_type == simu::DT_LNK)) {
          // TRACE("comparing with: %s", res->d_name);
          if (!strcasecmp(fileName.c_str(), res->d_name)) {
            strcpy(result, dirName.c_str());
            strcat(result, "/");
            strcat(result, res->d_name);
            TRACE("\tfound: %s", res->d_name);
            fileMap.insert(filemap_t:: value_type(path, result));
            return result;  
          }
        }
      }
    }
#endif
  }
  TRACE("\tnot found");
  strcpy(result, path);
  return result;
}

FRESULT f_stat (const TCHAR * name, FILINFO *)
{
  char *path = convertSimuPath(name);
  char * realPath = findTrueFileName(path);
  struct stat tmp;
  if (stat(realPath, &tmp)) {
    TRACE("f_stat(%s) = error %d (%s)", path, errno, strerror(errno));
    return FR_INVALID_NAME;
  }
  else {
    TRACE("f_stat(%s) = OK", path);
    return FR_OK;
  }
}

FRESULT f_mount (FATFS* ,const TCHAR*, BYTE opt)
{
  return FR_OK;
}

FRESULT f_open (FIL * fil, const TCHAR *name, BYTE flag)
{
  char *path = convertSimuPath(name);
  char * realPath = findTrueFileName(path);
  if (!(flag & FA_WRITE)) {
    struct stat tmp;
    if (stat(realPath, &tmp)) {
      TRACE("f_open(%s) = INVALID_NAME", path);
      return FR_INVALID_NAME;
    }
    fil->fsize = tmp.st_size;
  }
  fil->fs = (FATFS*)fopen(realPath, (flag & FA_WRITE) ? "wb+" : "rb+");
  fil->fptr = 0;
  if (fil->fs) {
    TRACE("f_open(%s) = %p", path, (FILE*)fil->fs);
    return FR_OK;
  }
  TRACE("f_open(%s) = error %d (%s)", path, errno, strerror(errno));
  return FR_INVALID_NAME;
}

FRESULT f_read (FIL* fil, void* data, UINT size, UINT* read)
{
  if (fil && fil->fs) {
    *read = fread(data, 1, size, (FILE*)fil->fs);
    fil->fptr += *read;
    // TRACE("fread(%p) %u, %u", fil->fs, size, *read);
  }
  return FR_OK;
}

FRESULT f_write (FIL* fil, const void* data, UINT size, UINT* written)
{
  if (fil && fil->fs) *written = fwrite(data, 1, size, (FILE*)fil->fs);
  fil->fptr += size;
  return FR_OK;
}

FRESULT f_lseek (FIL* fil, DWORD offset)
{
  if (fil && fil->fs) fseek((FILE*)fil->fs, offset, SEEK_SET);
  fil->fptr = offset;
  return FR_OK;
}

FRESULT f_close (FIL * fil)
{
  if (fil && fil->fs) {
    TRACE("f_close(%p)", (FILE*)fil->fs);
    fclose((FILE*)fil->fs);
    fil->fs = NULL;
  }
  return FR_OK;
}

FRESULT f_chdir (const TCHAR *name)
{
  chdir(convertSimuPath(name));
  return FR_OK;
}

FRESULT f_opendir (DIR * rep, const TCHAR * name)
{
  char *path = convertSimuPath(name);
  rep->fs = (FATFS *)simu::opendir(path);
  if ( rep->fs ) {
    TRACE("f_opendir(%s) = OK", path);
    return FR_OK;
  }
  TRACE("f_opendir(%s) = error %d (%s)", path, errno, strerror(errno));
  return FR_INVALID_NAME;
}

FRESULT f_readdir (DIR * rep, FILINFO * fil)
{
  if (!rep->fs) return FR_NO_FILE;
  simu::dirent * ent = simu::readdir((simu::DIR *)rep->fs);
  if (!ent) return FR_NO_FILE;

#if defined(WIN32) || !defined(__GNUC__) || defined(__APPLE__)
  fil->fattrib = (ent->d_type == DT_DIR ? AM_DIR : 0);
#else
  if (ent->d_type == simu::DT_UNKNOWN) {
    fil->fattrib = 0;
    struct stat buf;
    if (stat(ent->d_name, &buf) == 0) {
      fil->fattrib = (S_ISDIR(buf.st_mode) ? AM_DIR : 0);
    }
  }
  else {
    fil->fattrib = (ent->d_type == simu::DT_DIR ? AM_DIR : 0);
  }
#endif

  memset(fil->fname, 0, 13);
  memset(fil->lfname, 0, SD_SCREEN_FILE_LENGTH);
  strncpy(fil->fname, ent->d_name, 13-1);
  strcpy(fil->lfname, ent->d_name);
  // TRACE("f_readdir(): %s", fil->fname);
  return FR_OK;
}

FRESULT f_mkfs (const TCHAR *path, BYTE, UINT)
{
  TRACE("Format SD...");
  return FR_OK;
}

FRESULT f_mkdir (const TCHAR*)
{
  return FR_OK;
}

FRESULT f_unlink (const TCHAR*)
{
  return FR_OK;
}

int f_putc (TCHAR c, FIL * fil)
{
  if (fil && fil->fs) fwrite(&c, 1, 1, (FILE*)fil->fs);
  return FR_OK;
}

int f_puts (const TCHAR * str, FIL * fil)
{
  int n;
  for (n = 0; *str; str++, n++) {
    if (f_putc(*str, fil) == EOF) return EOF;
  }
  return n;
}

int f_printf (FIL *fil, const TCHAR * format, ...)
{
  va_list arglist;
  va_start(arglist, format);
  if (fil && fil->fs) vfprintf((FILE*)fil->fs, format, arglist);
  va_end(arglist);
  return 0;
}

FRESULT f_getcwd (TCHAR *path, UINT sz_path)
{
  strcpy(path, ".");
  return FR_OK;
}

FRESULT f_getfree (const TCHAR* path, DWORD* nclst, FATFS** fatfs)
{
  // just fake that we always have some clusters free
  *nclst = 10;
  return FR_OK;  
}

#if defined(PCBSKY9X)
int32_t Card_state = SD_ST_MOUNTED;
uint32_t Card_CSD[4]; // TODO elsewhere
#endif

#endif  // #if defined(SDCARD) && !defined(SKIP_FATFS_DECLARATION) && !defined(SIMU_DISKIO)


#if defined(SIMU_DISKIO)
#include "FatFs/diskio.h"
#include <time.h>
#include <stdio.h>

#if defined(CPUARM)
FATFS g_FATFS_Obj = { 0};
#endif

int ff_cre_syncobj (BYTE vol, _SYNC_t* sobj) /* Create a sync object */
{
  return 1;
}

int ff_req_grant (_SYNC_t sobj)        /* Lock sync object */
{
  return 1;
}

void ff_rel_grant (_SYNC_t sobj)        /* Unlock sync object */
{

}

int ff_del_syncobj (_SYNC_t sobj)        /* Delete a sync object */
{
  return 1;
}

DWORD get_fattime (void)
{
  time_t tim = time(0);
  const struct tm * t = gmtime(&tim);

  /* Pack date and time into a DWORD variable */
  return ((DWORD)(t->tm_year - 80) << 25)
    | ((uint32_t)(t->tm_mon+1) << 21)
    | ((uint32_t)t->tm_mday << 16)
    | ((uint32_t)t->tm_hour << 11)
    | ((uint32_t)t->tm_min << 5)
    | ((uint32_t)t->tm_sec >> 1);
}

unsigned int noDiskStatus = 0;

void traceDiskStatus()
{
  if (noDiskStatus > 0) {
    TRACE("disk_status() called %d times", noDiskStatus);
    noDiskStatus = 0;  
  }
}

DSTATUS disk_initialize (BYTE pdrv)
{
  traceDiskStatus();
  TRACE("disk_initialize(%u)", pdrv);
  diskImage = fopen("sdcard.image", "r+");
  return diskImage ? (DSTATUS)0 : (DSTATUS)STA_NODISK;
}

DSTATUS disk_status (BYTE pdrv)
{
  ++noDiskStatus;
  // TRACE("disk_status(%u)", pdrv);
  return (DSTATUS)0;
}

DRESULT disk_read (BYTE pdrv, BYTE* buff, DWORD sector, UINT count)
{
  if (diskImage == 0) return RES_NOTRDY;
  traceDiskStatus();
  TRACE("disk_read(%u, %p, %u, %u)", pdrv, buff, sector, count);
  fseek(diskImage, sector*512, SEEK_SET);
  fread(buff, count, 512, diskImage);
  return RES_OK;
}

DRESULT disk_write (BYTE pdrv, const BYTE* buff, DWORD sector, UINT count)
{
  if (diskImage == 0) return RES_NOTRDY;
  traceDiskStatus();
  TRACE("disk_write(%u, %p, %u, %u)", pdrv, buff, sector, count);
  fseek(diskImage, sector*512, SEEK_SET);
  fwrite(buff, count, 512, diskImage);
  return RES_OK;
}

DRESULT disk_ioctl (BYTE pdrv, BYTE cmd, void* buff)
{
  if (diskImage == 0) return RES_NOTRDY;
  traceDiskStatus();
  TRACE("disk_ioctl(%u, %u, %p)", pdrv, cmd, buff);
  if (pdrv) return RES_PARERR;

  DRESULT res;
  BYTE *ptr = (BYTE *)buff;

  if (cmd == CTRL_POWER) {
    switch (*ptr) {
      case 0:         /* Sub control code == 0 (POWER_OFF) */
        res = RES_OK;
        break;
      case 1:         /* Sub control code == 1 (POWER_ON) */
        res = RES_OK;
        break;
      case 2:         /* Sub control code == 2 (POWER_GET) */
        *(ptr+1) = (BYTE)1;  /* fake powered */
        res = RES_OK;
        break;
      default :
        res = RES_PARERR;
    }
    return res;
  }

  switch(cmd) {
/* Generic command (Used by FatFs) */
    case CTRL_SYNC :     /* Complete pending write process (needed at _FS_READONLY == 0) */
      break;

    case GET_SECTOR_COUNT: /* Get media size (needed at _USE_MKFS == 1) */
      {
        struct stat buf;
        if (stat("sdcard.image", &buf) == 0) {
          DWORD noSectors  = buf.st_size / 512;
          *(DWORD*)buff = noSectors;
          TRACE("disk_ioctl(GET_SECTOR_COUNT) = %u", noSectors);
          return RES_OK; 
        }
        return RES_ERROR;
      }

    case GET_SECTOR_SIZE: /* Get sector size (needed at _MAX_SS != _MIN_SS) */
      TRACE("disk_ioctl(GET_SECTOR_SIZE) = 512");
      *(WORD*)buff = 512;
      res = RES_OK;
      break;

    case GET_BLOCK_SIZE : /* Get erase block size (needed at _USE_MKFS == 1) */
      *(WORD*)buff = 512 * 4;
      res = RES_OK;
      break;

    case CTRL_TRIM : /* Inform device that the data on the block of sectors is no longer used (needed at _USE_TRIM == 1) */
      break;

/* Generic command (Not used by FatFs) */
    case CTRL_LOCK : /* Lock/Unlock media removal */
    case CTRL_EJECT: /* Eject media */
    case CTRL_FORMAT: /* Create physical format on the media */
      return RES_PARERR;


/* MMC/SDC specific ioctl command */
    // case MMC_GET_TYPE    10  /* Get card type */
    // case MMC_GET_CSD     11  /* Get CSD */
    // case MMC_GET_CID     12  /* Get CID */
    // case MMC_GET_OCR     13  /* Get OCR */
    // case MMC_GET_SDSTAT    14  /* Get SD status */

/* ATA/CF specific ioctl command */
    // case ATA_GET_REV     20  /* Get F/W revision */
    // case ATA_GET_MODEL   21  /* Get model name */
    // case ATA_GET_SN      22  /* Get serial number */
    default:
      return RES_PARERR;
  }
  return RES_OK;
}

uint32_t sdIsHC()
{
  return sdGetSize() > 2000000;
}

uint32_t sdGetSpeed()
{
  return 330000;
}

#endif // #if defined(SIMU_DISKIO)



bool lcd_refresh = true;
uint8_t lcd_buf[DISPLAY_BUF_SIZE];

void lcdSetRefVolt(uint8_t val)
{
}

void lcdRefresh()
{
  memcpy(lcd_buf, displayBuf, DISPLAY_BUF_SIZE);
  lcd_refresh = true;
}

#if defined(PCBTARANIS)
void pwrInit() { }
uint32_t pwrCheck() { return true; }
void pwrOff() { }
void usbStart() { }
int usbPlugged() { return false; }
void USART_DeInit(USART_TypeDef* ) { }
ErrorStatus RTC_SetTime(uint32_t RTC_Format, RTC_TimeTypeDef* RTC_TimeStruct) { return SUCCESS; }
ErrorStatus RTC_SetDate(uint32_t RTC_Format, RTC_DateTypeDef* RTC_DateStruct) { return SUCCESS; }
void RTC_GetTime(uint32_t RTC_Format, RTC_TimeTypeDef* RTC_TimeStruct) { }
void RTC_GetDate(uint32_t RTC_Format, RTC_DateTypeDef* RTC_DateStruct) { }
void RTC_TimeStructInit(RTC_TimeTypeDef* RTC_TimeStruct) { }
void RTC_DateStructInit(RTC_DateTypeDef* RTC_DateStruct) { }
void PWR_BackupAccessCmd(FunctionalState NewState) { }
void RCC_RTCCLKConfig(uint32_t RCC_RTCCLKSource) { }
void RCC_APB1PeriphClockCmd(uint32_t RCC_APB1Periph, FunctionalState NewState) { }
void RCC_RTCCLKCmd(FunctionalState NewState) { }
ErrorStatus RTC_Init(RTC_InitTypeDef* RTC_InitStruct) { return SUCCESS; }
void USART_SendData(USART_TypeDef* USARTx, uint16_t Data) { }
FlagStatus USART_GetFlagStatus(USART_TypeDef* USARTx, uint16_t USART_FLAG) { return SET; }
void GPIO_PinAFConfig(GPIO_TypeDef* GPIOx, uint16_t GPIO_PinSource, uint8_t GPIO_AF) { }
void USART_Init(USART_TypeDef* USARTx, USART_InitTypeDef* USART_InitStruct) { }
void USART_Cmd(USART_TypeDef* USARTx, FunctionalState NewState) { }
void USART_ITConfig(USART_TypeDef* USARTx, uint16_t USART_IT, FunctionalState NewState) { }
void RCC_PLLI2SConfig(uint32_t PLLI2SN, uint32_t PLLI2SR) { }
void RCC_PLLI2SCmd(FunctionalState NewState) { }
void RCC_I2SCLKConfig(uint32_t RCC_I2SCLKSource) { }
void SPI_I2S_DeInit(SPI_TypeDef* SPIx) { }
void I2S_Init(SPI_TypeDef* SPIx, I2S_InitTypeDef* I2S_InitStruct) { }
void I2S_Cmd(SPI_TypeDef* SPIx, FunctionalState NewState) { }
void SPI_I2S_ITConfig(SPI_TypeDef* SPIx, uint8_t SPI_I2S_IT, FunctionalState NewState) { }
void RCC_LSEConfig(uint8_t RCC_LSE) { }
FlagStatus RCC_GetFlagStatus(uint8_t RCC_FLAG) { return RESET; }
ErrorStatus RTC_WaitForSynchro(void) { return SUCCESS; }
void unlockFlash() { }
void lockFlash() { }
void writeFlash(uint32_t *address, uint32_t *buffer) { SIMU_SLEEP(100); }
uint32_t isBootloaderStart(const void *block) { return 1; }
#if defined(REVPLUS)
void turnBacklightOn(uint8_t level, uint8_t color)
{
  TIM4->CCR4 = (100-level)*color;
  TIM4->CCR2 = (100-level)*(100-color);
}

void turnBacklightOff(void)
{
  TIM4->CCR4 = 0;
  TIM4->CCR2 = 0;
}
#endif

#endif  // #if defined(PCBTARANIS)

