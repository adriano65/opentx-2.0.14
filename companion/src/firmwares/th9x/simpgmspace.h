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

#ifndef simpgmspace_h
#define simpgmspace_h

#ifdef SIMU_EXCEPTIONS
extern char * main_thread_error;
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#if defined(WIN32) || !defined(__GNUC__)
#define write_backtrace(output)
#else
#include <execinfo.h>
#include <string.h>
inline void write_backtrace(char *output)
{

  void *buf[16];
  char **s;
  int n = backtrace(buf,16);
  s = backtrace_symbols(buf, n);
  if (s) {
    for(int i=0; i<n; i++)
      sprintf(output+strlen(output), "%02i: %s\n",i,s[i]);
  }
}
#endif
void sig(int sgn)
{
  main_thread_error = (char *)malloc(2048);
  sprintf(main_thread_error,"Signal %d caught\n", sgn);
  write_backtrace(main_thread_error);
  throw std::exception();
}
#define assert(x) do { if (!(x)) { main_thread_error = (char *)malloc(2048); sprintf(main_thread_error, "Assert failed, %s:%d: %s\n", __FILE__, __LINE__, #x); write_backtrace(main_thread_error); throw std::exception(); } } while(0)
#else
#include <assert.h>
#endif

#include <inttypes.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

typedef unsigned char prog_uchar;
typedef const char prog_char;
typedef const uint16_t prog_uint16_t;
typedef const uint8_t prog_uint8_t;
typedef const int16_t prog_int16_t;
typedef const int8_t prog_int8_t;



#define PROGMEM
#define pgm_read_byte(address_short) (*(uint8_t*)(address_short))
#define pgm_read_word(address_short) (*(uint16_t*)(address_short))
#define pgm_read_adr(address_short) *address_short
#define pgm_read_stringP(adr) ((adr))
#define PSTR(adr) adr
#define _delay_us(a)
#define cli()
#define sei()
#define strcpy_P strcpy
#define strncpy_P strncpy
#define memcpy_P memcpy

#define PORTA dummyport
#define PORTB portb
#define PORTC dummyport
#define PORTD dummyport
#define PORTE dummyport
#define PORTF dummyport
#define PORTG dummyport
#define DDRA   dummyport
#define DDRB   dummyport
#define DDRC   dummyport
#define PINB  ~pinb
#define PIND  ~pind
#define PINE  ~pine
#define PING  ~ping
#define EEMEM

extern volatile unsigned char pinb,pinc,pind,pine,ping;
extern uint8_t portb;
extern unsigned char dummyport;
extern uint8_t main_thread_running;

extern void setSwitch(int8_t swtch);

void StartMainThread(bool tests=true);
void StartEepromThread(const char *filename="eeprom.bin");

extern const char *eepromFile;

//extern uint16_t anaIn(uint8_t chan);
//void eeprom_write_block (const void *pointer_ram,
//                    void *pointer_eeprom,
//                         size_t size);
void eeprom_read_block (void *pointer_ram,
                   const void *pointer_eeprom,
                        size_t size);
#undef offsetof
#define offsetof(st, m) ((size_t) ( (char *)&((st *)(0))->m - (char *)0 ))
#define wdt_reset()


#ifndef __GNUC__
#include <windows.h>
#define sleep(x) Sleep(x)
#undef min
#undef max
#else
#include <unistd.h>
#define sleep(x) usleep(1000*x)
#endif

#endif
