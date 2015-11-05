/*
 * Author	Thomas Husterer <thus1@t-online.de>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 */

#include "simpgmspace.h"
#include "lcd.h"
#include "th9x.h"
#include <ctype.h>

volatile unsigned char pinb,pinc,pind,pine,ping=0xff;
uint8_t portb;
unsigned char dummyport;
const char *eepromFile = NULL;
uint8_t eeprom[EESIZE];

void lcd_img_f(int ofs,unsigned char x,unsigned char y,int i_w,int i_h)
{
  
  prog_uchar  buf[1000];
  FILE *fp=fopen("../th9x-orig/flash.bin", "r");
  fseek(fp,ofs,SEEK_SET);
  fread(buf,1,i_h/8*i_w,fp);
  fclose(fp);
  prog_uchar  *q = buf;//+0x10e*3+0x10;
  int h=i_h;
  while(h>0){
    int w=i_w;
    unsigned char *p = &displayBuf[ y / 8 * DISPLAY_W + x ];
    while(w>0){
      *p = pgm_read_byte(q); p++; q++;
      w--;
    }
    h-=8;
    y+=8;
  }
}


FILE *fp = 0;

void eeWriteBlockCmp(const void *i_pointer_ram, void *pointer_eeprom, size_t size)
{
  if (eepromFile) {
    if(!fp) fp = fopen(eepromFile, "r+");
    long ofs = (long) pointer_eeprom;
    const char* pointer_ram= (const char*)i_pointer_ram;
    //printf("eeWr p=%10p blk%3d ofs=%2d l=%d",pointer_ram,
    //       (int)pointer_eeprom/16,
    //       (int)pointer_eeprom%16,
    //       (int)size);
    while(size){
      if(fseek(fp, ofs , SEEK_SET)==-1) perror("error in seek");
      char buf[1];
      fread(buf, 1, 1,fp);

      if(buf[0] !=  pointer_ram[0]){
        //printf("X");
        g_tmr10ms++;
        if(fseek(fp, ofs , SEEK_SET)==-1) perror("error in seek");
        fwrite(pointer_ram, 1, 1,fp);
      }else{
        //printf(".");
      }

      size--;
      ofs++;
      (const char*)pointer_ram++;
    }
    //fclose(fp);
    //puts("");
  }
  else {
    memcpy(&eeprom[(int64_t)pointer_eeprom], i_pointer_ram, size);
  }
}
void eeprom_write_blockxx (const void *pointer_ram,
                    void *pointer_eeprom,
                    size_t size)
{
  // printf("eeprom_write_block p=%p ofs=%d l=%2d\n",pointer_ram,(long int)pointer_eeprom,(long int)size);
  //  FILE *fp=fopen(eepromFile, "r+");
  if(!fp) fp = fopen(eepromFile, "r+");
  if(fseek(fp, (long) pointer_eeprom, SEEK_SET)==-1) perror("error in seek");
  fwrite(pointer_ram, size, 1,fp);
  //fclose(fp);
}

void eeprom_read_block (void *pointer_ram,
                   const void *pointer_eeprom,
                   size_t size)
{
  if (eepromFile) {
    //FILE *fp=fopen(eepromFile, "r");
    if(!fp) fp = fopen(eepromFile, "r+");
    if(fseek(fp, (long) pointer_eeprom, SEEK_SET)==-1) perror("error in seek");
    fread(pointer_ram, size, 1, fp);
    //fclose(fp);
  }
  else {
    memcpy(pointer_ram, &eeprom[(uint64_t)pointer_eeprom], size);
  }
}

uint8_t main_thread_running = 0;
char * main_thread_error = NULL;
void *main_thread(void *)
{
#ifdef SIMU_EXCEPTIONS
  signal(SIGFPE, sig);
  signal(SIGSEGV, sig);

  try {
#endif
    eeReadAll(); //load general setup and selected model

    if (main_thread_running == 1) {
      checkMem();  //enough eeprom free?
      checkTHR();
      checkSwitches(); //must be last
    }

    chainMenu(menuProc0); //call evt_entry

    while (main_thread_running) {
      perMain();
      sleep(1/*ms*/);
    }
#ifdef SIMU_EXCEPTIONS
  }
  catch (...) {
    main_thread_running = 0;
  }
#endif

  return NULL;
}

pthread_t main_thread_pid;
void StartMainThread(bool tests)
{
  main_thread_running = (tests ? 1 : 2);
  pthread_create(&main_thread_pid, NULL, &main_thread, NULL);
}

void StopMainThread()
{
  main_thread_running = 0;
  pthread_join(main_thread_pid, NULL);
}

