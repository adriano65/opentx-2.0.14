/*
 * Author Josef Glatthaar <josef.glatthaar@googlemail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 This file contains any code to immediatley access the hardware except
 initialisation and interrupt handling (this is in th9x.cpp).

 */

/*
 * warten bis mindestens ein Block empfangen
 * Erste Page löschen
 * Block in Puffer schreiben
 * Page schreiben
 * zweite bis letzte Page schreiben
 * erste Page schreiben
 *
 * Empfangen läuft parallel im Interrupt als Ringpuffer mit 2 * Pufferlaenge
 *
 * Beim Einschalten auf Tastendruck prüfen
 * Taste gedrückt: Auf Programm warten
 * Taste nicht gedrückt: in normales Programm springen
 *
 * Int7 synchronisiert Datenstrom
 * Timerinterrupt liest Bit
 * 19200 Baud = 52,08 us
 * 1:1 Teiler für Timer1
 * 1 Bit = 833 Timerinc
 *
 */


#include "th9x.h"
#include <avr/boot.h>

 uint8_t uartBuf[SPM_PAGESIZE*4];
 uint16_t page_z_buf[SPM_PAGESIZE / 2];
 volatile uint16_t uartWr;
 volatile uint8_t  g_blinkTmr10ms;

 ISR(TIMER1_COMPA_vect)
 {
   static uint8_t receiveData, receiveBit;

   receiveData <<= 1;
   if(!(PORTE & (1 << INP_E_PPM_IN)))
     receiveData |= 1;
   if(receiveBit & 0x8)
   {
     TIMSK &= ~(1<<OCIE1A);
     EIFR  &= ~(1 << INTF7);
     EIMSK |= 1 << INT7;                  // Interrupt wieder ein für die Flanke
     receiveBit = 0;
     uartBuf[uartWr++] = receiveData;
     uartWr %= sizeof(uartBuf);
   }
   else
     ++receiveBit;
 }

// ISR(TIMER0_COMP_vect, ISR_NOBLOCK) //10ms timer
// {
//   cli();
//   TIMSK &= ~(1<<OCIE0); //stop reentrance
//   sei();
//   OCR0 = OCR0 + 156;
//   lcd_clear();
//   refreshDiplay();
//   cli();
//   TIMSK |= (1<<OCIE0);
//   sei();
// }

 ISR(INT7_vect)
 {
   TCNT1 = 16000000/19200*2/3;    //Auf 2/3 stellen
   if(!(PORTE & (1 << INP_E_PPM_IN)))           // Startbit
   {
     TIFR &=  ~(1<<OCF1A);
     TIMSK |= (1<<OCIE1A);
     EIMSK &= ~(1 << INT7);
   }
 }

 bool checkEnd(void)
 {
   if(!(PINB & (1 << INP_B_KEY_EXT)))
     return(true);
   return(false);
 }

 void menu(void)
 {
   lcd_putsAtt(30,7,PSTR("Bootloader"),0);
   lcd_putsAtt(20,8,PSTR("Write program to FLASH"),0);
   lcd_putsAtt(20,9,PSTR("Write data to EEPROM"),0);
   lcd_putsAtt(20,10,PSTR("Read program from flash"),0);
   lcd_putsAtt(20,11,PSTR("Read data from EEPROM"),0);
   refreshDiplay();
 }

 void writeFlash(void)
 {
   uint16_t uartRd = 0;
   uint8_t page = 0;
   bool timeout = false;

   do
   {
     lcd_outdezAtt(40,4*8,page,0);

     refreshDiplay();

     uint8_t *buf = (uint8_t *)page_z_buf;
     do
       *buf++ = 0xff;
     while(buf < (uint8_t *)page_z_buf + SPM_PAGESIZE);
     buf = (uint8_t *)page_z_buf;
     do
     {
       while(uartRd == uartWr)      //uartWR wird im Interrupt geschrieben
       {
         if(checkEnd())
         {
           timeout = true;
           goto prog;
         }
       }
       *buf++ = uartBuf[uartRd++];
       uartRd %= sizeof(uartBuf);
       // bei Timeout break;
     }
     while(buf < (uint8_t *)page_z_buf + SPM_PAGESIZE);
prog:
     boot_spm_busy_wait();
     boot_page_erase(page);      // mindestens eine Page gekommen, dann ersten Block loeschen
     for (uint8_t i=0; i<SPM_PAGESIZE/2; ++i)
         boot_page_fill (i*2, page_z_buf[i]);
     boot_spm_busy_wait();
     boot_page_write (page++);         // Store buffer in flash page.
   }
   while((page < 224) && !timeout);                     //224);

   boot_rww_enable ();
   lcd_putsAtt(4,6,PSTR("fertig!"),INVERS);
 }

 void writeEEprom(void)
 {

 }

 void readFlash(void)
 {

 }

 void readEEprom(void)
 {

 }

 int main(void)
 {
   DDRA = 0xff;  PORTA = 0x00;
   DDRB = 0x81;  PORTB = 0x7e; //pullups keys+nc
   DDRC = 0x3e;  PORTC = 0xc1; //pullups nc
   DDRD = 0x00;  PORTD = 0xff; //pullups keys
   DDRE = 0x08;  PORTE = 0xff-(1<<OUT_E_BUZZER); //pullups + buzzer 0
   DDRF = 0x00;  PORTF = 0xff; //anain
   DDRG = 0x10;  PORTG = 0xff; //pullups + SIM_CTL=1 = phonejack = ppm_in

   while(!(PINB & (1 << INP_B_KEY_DWN)));

   lcd_init();

   if((PINB & (1 << INP_B_KEY_UP)))
     __asm__ __volatile__("jmp 0x0000");

   /* move interrupts to bootloader section */
   /* Enable change of Interrupt Vectors */
   MCUCR = (1<<IVCE);
   /* Move interrupts to boot Flash section */
   MCUCR = (1<<IVSEL);



// Achtung: Bei Einstieg über normale Software sind Register nicht auf default

   // TCNT0         10ms = 16MHz/160000
   //TCCR0  = (1<<WGM01)|(7 << CS00);//  CTC mode, clk/1024
//   TCCR0  = (7 << CS00);//  Norm mode, clk/1024
//   OCR0   = 156;
//   TIMSK |= (1<<OCIE0) |  (1<<TOIE0);


   TCCR1B = (1 << WGM12) | (1<<CS10);
   OCR1A = 16000000/19200;
//   TIFR &=  ~(1<<OCF1A);
//   TIMSK |= (1<<OCIE1A);


// Int7 ein (The falling edge between two samples of INTn generates an interrupt request.)
   EICRB = 1 << ISC71;
   EIFR  &= ~(1 << INTF7);
   EIMSK |= 1 << INT7;


   lcd_clear();

   menu();

   writeFlash();

   while(1);
   return 0;
 }
