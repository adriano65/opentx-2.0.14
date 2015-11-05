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
#ifndef lcd_h
#define lcd_h


#include "th9x.h"


#define DISPLAY_W 128
#define DISPLAY_H  64
#define FW          6
#define FWNUM       5
#define FH          8


#define NO_INV        0x00
#define INVERS        0x01
#define BLINK         0x02
#define BLINKF        (BLINK|INVERS)
#define ATT_CSR_MV    INVERS
#define ATT_CSR_EDT   BLINK


#define LEADING0      0x04
#define SIGN          0x08

#define BSS_NO_INV    0x10
#define BSS_INVERS    0x11
#define BSS_BLINK     0x12
#define PREC1         0x20
#define PREC2         0x40
#define PREC3         0x60
#define PREC(n)       (((n)>>5)&3)
#define DBLSIZE       0x80

#define ARR_W         "\x7f"
#define ARR_E         "\x7e"
#define ARR_NE        "\x7d"
#define ARR_SW        "\x7b"
#define ARR_N_S       "\x24"

#ifdef SIM
extern uint8_t displayBuf[DISPLAY_W*DISPLAY_H/8+DISPLAY_W];
extern bool lcd_refresh;
extern uint8_t lcd_buf[DISPLAY_W*DISPLAY_H/8];
#else
extern uint8_t displayBuf[DISPLAY_W*DISPLAY_H/8];
#endif

//extern unsigned char font_5x8_x20_x7f[];
extern void lcd_barAtt(uint8_t x,uint8_t y,uint8_t w,uint8_t mode);
extern void lcd_fill(uint8_t x,uint8_t y,uint8_t w,uint8_t h);
extern void lcd_rect(uint8_t x,uint8_t y,uint8_t w,uint8_t h);

extern void lcd_putcAtt(unsigned char x,unsigned char y,const char c,uint8_t mode);
extern unsigned char lcd_putsAtt(unsigned char x,unsigned char y,const prog_char * s,uint8_t mode);
extern void lcd_putsnAtt(unsigned char x,unsigned char y,const prog_char * s,unsigned char len,uint8_t mode);
extern void lcd_putsmAtt(uint8_t x,uint8_t y,const prog_char * s,uint8_t skip,uint8_t mode);

extern void lcd_putc(unsigned char x,unsigned char y,const char c);
extern void lcd_puts_P(unsigned char x,unsigned char y,const prog_char * s);
//extern void lcd_putsn_P(unsigned char x,unsigned char y,const prog_char * s,unsigned char len);
extern void lcd_putsm_P(uint8_t x,uint8_t y,const prog_char * s,uint8_t skip);
extern void lcd_outhex4(unsigned char x,unsigned char y,uint16_t val);
extern void lcd_outdezAtt(unsigned char x,unsigned char y,int16_t val,uint8_t mode);
void lcd_outdezNAtt(uint8_t x,uint8_t y,int16_t val,uint8_t mode,uint8_t len);
//extern void lcd_outdezAtt(unsigned char x,unsigned char y,int16_t val,uint8_t mode);
extern void lcd_outdez(unsigned char x,unsigned char y,int16_t val);

extern void lcd_plot(unsigned char x,unsigned char y);
extern void lcd_hline(int8_t x,int8_t y, signed char w);
extern void lcd_hlineStip(int8_t x,int8_t y, signed char w,uint8_t pat);
extern void lcd_vline(int8_t x,int8_t y, signed char h);
extern void lcd_vlineStip(int8_t x,int8_t y, int8_t h, uint8_t pat);
extern void lcd_img_f(unsigned char x,unsigned char y);
extern void lcd_img(uint8_t i_x,uint8_t i_y,const prog_uchar * imgdat,uint8_t idx,uint8_t mode);

extern void lcd_init();
extern void lcd_clear();
extern void refreshDiplay();
extern void lcdSetRefVolt(unsigned char val);
#define BLINK_ON_PHASE (g_blinkTmr10ms & (1<<6))
#define BLINK_SYNC      g_blinkTmr10ms = (0x40-10)
#endif
/*eof*/
