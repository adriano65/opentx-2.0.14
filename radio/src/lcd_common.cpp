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

uint8_t displayBuf[DISPLAY_BUF_SIZE];

#if defined(LUA)
bool lcd_locked = false;
#endif

void lcd_clear()
{
  memset(displayBuf, 0, sizeof(displayBuf));
}

uint8_t lcdLastPos;
uint8_t lcdNextPos;

#if defined(CPUARM)
void lcdPutPattern(xcoord_t x, uint8_t y, const uint8_t * pattern, uint8_t width, uint8_t height, LcdFlags flags)
{
  bool blink = false;
  bool inv = false;
  if (flags & BLINK) {
    if (BLINK_ON_PHASE) {
      if (flags & INVERS)
        inv = true;
      else {
        blink = true;
      }
    }
  }
  else if (flags & INVERS) {
    inv = true;
  }

  uint8_t lines = (height+7)/8;
  assert(lines <= 5);

  for (int8_t i=0; i<width+2; i++) {
    if (x<LCD_W) {
      uint8_t b[5] = { 0 };
      if (i==0) {
        if (x==0 || !inv) {
          lcdNextPos++;
          continue;
        }
        else {
          // we need to work on the previous x when INVERS
          x--;
        }
      }
      else if (i<=width) {
        uint8_t skip = true;
        for (uint8_t j=0; j<lines; j++) {
          b[j] = pgm_read_byte(pattern++); /*top byte*/
          if (b[j] != 0xff) {
            skip = false;
          }
        }
        if (skip) {
          if (flags & FIXEDWIDTH) {
            for (uint8_t j=0; j<lines; j++) {
              b[j] = 0;
            }
          }
          else {
            continue;
          }
        }
        if ((flags & CONDENSED) && i==2) {
          /*condense the letter by skipping column 3 */
          continue;
        }
      }

      for (int8_t j=-1; j<=height; j++) {
        bool plot;
        if (j < 0 || ((j == height) && !(flags & SMLSIZE))) {
          plot = false;
          if (height >= 12) continue;
          if (j<0 && !inv) continue;
        }
        else {
          uint8_t line = (j / 8);
          uint8_t pixel = (j % 8);
          plot = b[line] & (1 << pixel);
        }
        if (inv) plot = !plot;
        if (!blink) {
          lcd_plot(x, y+j, plot ? FORCE : ERASE);
        }
      }
    }

    x++;
    lcdNextPos++;
  }
}

void lcd_putcAtt(xcoord_t x, uint8_t y, const unsigned char c, LcdFlags flags)
{
  const pm_uchar * q;

  lcdNextPos = x-1;

#if !defined(BOOT)
  unsigned char c_remapped = 0;

  if (flags & (DBLSIZE+BOLD)) {
    // To save space only some DBLSIZE and BOLD chars are available
    // c has to be remapped. All non existing chars mapped to 0 (space)
    if (c>=',' && c<=':')
      c_remapped = c - ',' + 1;
    else if (c>='A' && c<='Z')
      c_remapped = c - 'A' + 16;
    else if (c>='a' && c<='z')
      c_remapped = c - 'a' + 42;
    else if (c=='_')
      c_remapped = 4;
    else if (c!=' ')
      flags &= ~BOLD;
  }

  if (flags & DBLSIZE) {
    if (c >= 0xC0) {
      q = &font_10x14_extra[((uint16_t)(c-0xC0))*20];
    }
    else {
      if (c >= 128)
        c_remapped = c - 60;
      q = &font_10x14[((uint16_t)c_remapped)*20];
    }
    lcdPutPattern(x, y, q, 10, 16, flags);
  }
  else if (flags & XXLSIZE) {
    q = &font_22x38_num[((uint16_t)c-'0'+5)*110];
    lcdPutPattern(x, y, q, 22, 38, flags);
  }
  else if (flags & MIDSIZE) {
    q = &font_8x10[((uint16_t)c-0x20)*16];
    lcdPutPattern(x, y, q, 8, 12, flags);
  }
  else if (flags & SMLSIZE) {
    q = (c < 0xc0 ? &font_4x6[(c-0x20)*5] : &font_4x6_extra[(c-0xc0)*5]);
    lcdPutPattern(x, y, q, 5, 6, flags);
  }
  else if (flags & TINSIZE) {
    q = &font_3x5[((uint16_t)c-0x2d)*3];
    lcdPutPattern(x, y, q, 3, 5, flags);
  }
#if defined(BOLD_FONT)
  else if (flags & BOLD) {
    q = &font_5x7_B[c_remapped*5];
    lcdPutPattern(x, y, q, 5, 7, flags);
  }
#endif
  else
#endif
  {
#if !defined(BOOT)
    q = (c < 0xC0) ? &font_5x7[(c-0x20)*5] : &font_5x7_extra[(c-0xC0)*5];
#else
    q = &font_5x7[(c-0x20)*5];
#endif
    lcdPutPattern(x, y, q, 5, 7, flags);
  }
}
#endif

void lcd_putc(xcoord_t x, uint8_t y, const unsigned char c)
{
  lcd_putcAtt(x, y, c, 0);
}

void lcd_putsnAtt(xcoord_t x, uint8_t y, const pm_char * s, uint8_t len, LcdFlags mode)
{
  const xcoord_t orig_x = x;
#if defined(CPUARM)
  const uint8_t orig_len = len;
#endif
  bool setx = false;
  while (len--) {
    unsigned char c;
    switch (mode & (BSS+ZCHAR)) {
      case BSS:
        c = *s;
        break;
#if !defined(BOOT)
      case ZCHAR:
        c = idx2char(*s);
        break;
#endif
      default:
        c = pgm_read_byte(s);
        break;
    }

    if (setx) {
      x = c;
      setx = false;
    }
    else if (!c) {
      break;
    }
    else if (c >= 0x20) {
      lcd_putcAtt(x, y, c, mode);
      x = lcdNextPos;
    }
    else if (setx) {
      x = c;
      setx = false;
    }
    else if (c == 0x1F) {  //X-coord prefix
      setx = true;
    }
    else if (c == 0x1E) {  //NEWLINE
#if defined(CPUARM)
      len = orig_len;
#endif
      x = orig_x;
      y += FH;
#if defined(CPUARM)      
      if (mode & DBLSIZE) y += FH;
      else if (mode & MIDSIZE) y += 4;
      else if (mode & SMLSIZE) y--;
#endif
      if (y >= LCD_H) break;
    }
#if defined(CPUARM)      
    else if (c == 0x1D) {  // TAB
      x |= 0x3F;
      x += 1;
    }
#endif
    else {
      x += (c*FW/2); // EXTENDED SPACE
    }
    s++;
  }
  lcdLastPos = x;
  lcdNextPos = x;
#if defined(CPUARM)
  if (mode&MIDSIZE)
    lcdLastPos += 1;
#endif
}

void lcd_putsn(xcoord_t x, uint8_t y, const pm_char * s, uint8_t len)
{
  lcd_putsnAtt(x, y, s, len, 0);
}

void lcd_putsAtt(xcoord_t x, uint8_t y, const pm_char * s, LcdFlags flags)
{
  lcd_putsnAtt(x, y, s, 255, flags);
}

void lcd_puts(xcoord_t x, uint8_t y, const pm_char * s)
{
  lcd_putsAtt(x, y, s, 0);
}

void lcd_putsLeft(uint8_t y, const pm_char * s)
{
  lcd_puts(0, y, s);
}

#if !defined(BOOT)
void lcd_putsiAtt(xcoord_t x, uint8_t y,const pm_char * s,uint8_t idx, LcdFlags flags)
{
  uint8_t length;
  length = pgm_read_byte(s++);
  lcd_putsnAtt(x, y, s+length*idx, length, flags & ~(BSS|ZCHAR));
}

void lcd_outhex4(xcoord_t x, uint8_t y, uint16_t val)
{
  x += FWNUM*4+1;
  for(int i=0; i<4; i++) {
    x -= FWNUM;
    char c = val & 0xf;
    c = c>9 ? c+'A'-10 : c+'0';
    lcd_putcAtt(x, y, c, c>='A' ? CONDENSED : 0);
    val >>= 4;
  }
}

void lcd_outdez8(xcoord_t x, uint8_t y, int8_t val)
{
  lcd_outdezAtt(x, y, val);
}

void lcd_outdezAtt(xcoord_t x, uint8_t y, lcdint_t val, LcdFlags flags)
{
  lcd_outdezNAtt(x, y, val, flags);
}

void lcd_outdezNAtt(xcoord_t x, uint8_t y, lcdint_t val, LcdFlags flags, uint8_t len)
{
  uint8_t fw = FWNUM;
  int8_t mode = MODE(flags);
  flags &= ~LEADING0;
  bool dblsize = flags & DBLSIZE;
#if defined(CPUARM)
  bool xxlsize = flags & XXLSIZE;
  bool midsize = flags & MIDSIZE;
  bool smlsize = flags & SMLSIZE;
  bool tinsize = flags & TINSIZE;
#else
  #define xxlsize 0
  #define midsize 0
  #define smlsize 0
  #define tinsize 0
#endif

  bool neg = false;
  if (flags & UNSIGN) {
    flags -= UNSIGN;
  }
  else if (val < 0) {
    neg = true;
    val = -val;
  }

  xcoord_t xn = 0;
  uint8_t ln = 2;

  if (mode != MODE(LEADING0)) {
    len = 1;
    lcduint_t tmp = ((lcduint_t)val) / 10;
    while (tmp) {
      len++;
      tmp /= 10;
    }
    if (len <= mode) {
      len = mode + 1;
    }
  }

  if (dblsize) {
    fw += FWNUM;
  }
  else if (xxlsize) {
    fw += 4*FWNUM-1;
  }
  else if (midsize) {
    fw += FWNUM-3;
  }
  else if (tinsize) {
    fw -= 1;
  }
  else {
    if (flags & LEFT) {
      if (mode > 0)
        x += 2;
    }
#if defined(BOLD_FONT) && !defined(CPUM64) || defined(EXTSTD)
    if (flags & BOLD) fw += 1;
#endif
  }

  if (flags & LEFT) {
    x += len * fw;
    if (neg) {
      x += ((xxlsize|dblsize|midsize) ? 7 : FWNUM);
    }
  }

  lcdLastPos = x;
  x -= fw;
  if (dblsize) x++;

  for (uint8_t i=1; i<=len; i++) {
    div_t qr = div((lcduint_t)val, 10);
    char c = qr.rem + '0';
    LcdFlags f = flags;
#if !defined(PCBTARANIS)
    if (dblsize) {
      if (c=='1' && i==len && xn>x+10) { x+=1; }
      if ((lcduint_t)val >= 1000) { x+=FWNUM; f&=~DBLSIZE; }
    }
#endif
    lcd_putcAtt(x, y, c, f);
    if (mode == i) {
      flags &= ~PREC2; // TODO not needed but removes 20bytes, could be improved for sure, check asm
      if (dblsize) {
        xn = x - 2;
        if (c>='2' && c<='3') ln++;
        uint8_t tn = (qr.quot % 10);
        if (tn==2 || tn==4) {
          if (c=='4') {
            xn++;
          }
          else {
            xn--;
            ln++;
          }
        }
      }
      else if (xxlsize) {
        x -= 17;
        lcd_putcAtt(x+2, y, '.', f);
      }
      else if (midsize) {
        x -= 3;
        xn = x;
      }
      else if (smlsize) {
        x -= 2;
        lcd_plot(x+1, y+5);
        if ((flags&INVERS) && ((~flags & BLINK) || BLINK_ON_PHASE)) {
          lcd_vline(x+1, y, 7);
        }
      }
      else if (tinsize) {
        x--;
        lcd_plot(x-1, y+4);
        if ((flags&INVERS) && ((~flags & BLINK) || BLINK_ON_PHASE)) {
          lcd_vline(x-1, y-1, 7);
        }
        x--;
      }
      else {
        x -= 2;
        lcd_putcAtt(x, y, '.', f);
      }
    }
#if !defined(PCBTARANIS)
    if (dblsize && (lcduint_t)val >= 1000 && (lcduint_t)val < 10000) x-=2;
#endif
    val = qr.quot;
    x -= fw;
#if defined(BOLD_FONT) && !defined(CPUM64) || defined(EXTSTD)
    if (i==len && (flags & BOLD)) x += 1;
#endif
  }

  if (xn) {
    if (midsize) {
      if ((flags&INVERS) && ((~flags & BLINK) || BLINK_ON_PHASE)) {
        lcd_vline(xn, y, 12);
        lcd_vline(xn+1, y, 12);
      }
      lcd_hline(xn, y+9, 2);
      lcd_hline(xn, y+10, 2);
    }
    else {
      // TODO needed on CPUAVR? y &= ~0x07;
      lcd_filled_rect(xn, y+2*FH-3, ln, 2);
    }
  }
  if (neg) lcd_putcAtt(x, y, '-', flags);
}
#endif

void lcd_hline(xcoord_t x, uint8_t y, xcoord_t w, LcdFlags att)
{
  lcd_hlineStip(x, y, w, 0xff, att);
}

#if defined(CPUARM)
void lcd_line(xcoord_t x1, int8_t y1, xcoord_t x2, int8_t y2, uint8_t pat, LcdFlags att)
{
  int dx = x2-x1;      /* the horizontal distance of the line */
  int dy = y2-y1;      /* the vertical distance of the line */
  int dxabs = abs(dx);
  int dyabs = abs(dy);
  int sdx = sgn(dx);
  int sdy = sgn(dy);
  int x = dyabs>>1;
  int y = dxabs>>1;
  int px = x1;
  int py = y1;

  if (dxabs >= dyabs) {
    /* the line is more horizontal than vertical */
    for (int i=0; i<dxabs; i++) {
      y += dyabs;
      if (y>=dxabs) {
        y -= dxabs;
        py += sdy;
      }
      px += sdx;
      if ((1<<(px%8)) & pat)
        lcd_plot(px, py, att);
    }
  }
  else {
    /* the line is more vertical than horizontal */
    for (int i=0; i<dyabs; i++) {
      x += dxabs;
      if (x >= dyabs) {
        x -= dyabs;
        px += sdx;
      }
      py += sdy;
      if ((1<<(py%8)) & pat)
        lcd_plot(px, py, att);
    }
  }
}
#endif

void lcd_vline(xcoord_t x, int8_t y, int8_t h)
{
  lcd_vlineStip(x, y, h, SOLID);
}

void lcd_rect(xcoord_t x, uint8_t y, xcoord_t w, uint8_t h, uint8_t pat, LcdFlags att)
{
  lcd_vlineStip(x, y, h, pat);
  lcd_vlineStip(x+w-1, y, h, pat);
  if (~att & ROUND) { x+=1; w-=2; }
  lcd_hlineStip(x, y+h-1, w, pat);
  lcd_hlineStip(x, y, w, pat);
}

#if !defined(BOOT)
void lcd_filled_rect(xcoord_t x, int8_t y, xcoord_t w, uint8_t h, uint8_t pat, LcdFlags att)
{
#if defined(CPUM64)
  for (int8_t i=y; i<y+h; i++) {
    lcd_hlineStip(x, i, w, pat, att);
    pat = (pat >> 1) + ((pat & 1) << 7);
  }
#else
  for (int8_t i=y; i<y+h; i++) {
    if ((att&ROUND) && (i==y || i==y+h-1))
      lcd_hlineStip(x+1, i, w-2, pat, att);
    else
      lcd_hlineStip(x, i, w, pat, att);
    pat = (pat >> 1) + ((pat & 1) << 7);
  }
#endif
}

#if defined(PCBTARANIS)
void lcdDrawTelemetryTopBar()
{
  putsModelName(0, 0, g_model.header.name, g_eeGeneral.currModel, 0);
  uint8_t att = (g_vbat100mV < g_eeGeneral.vBatWarn ? BLINK : 0);
  putsVBat(16*FW+1,0,att);
  if (g_model.timers[0].mode) {
    att = (timersStates[0].val<0 ? BLINK : 0);
    putsTimer(22*FW+5*FWNUM+3, 0, timersStates[0].val, att, att);
    lcd_putsiAtt(18*FW+2, 1, STR_VTELEMCHNS, TELEM_TIMER1, SMLSIZE);
  }
  if (g_model.timers[1].mode) {
    att = (timersStates[1].val<0 ? BLINK : 0);
    putsTimer(31*FW+5*FWNUM+3, 0, timersStates[1].val, att, att);
    lcd_putsiAtt(27*FW+2, 1, STR_VTELEMCHNS, TELEM_TIMER2, SMLSIZE);
  }
  lcd_invert_line(0);
}
#else
void lcdDrawTelemetryTopBar()
{
  putsModelName(0, 0, g_model.header.name, g_eeGeneral.currModel, 0);
  uint8_t att = (g_vbat100mV < g_eeGeneral.vBatWarn ? BLINK : 0);
  putsVBat(14*FW,0,att);
  if (g_model.timers[0].mode) {
    att = (timersStates[0].val<0 ? BLINK : 0);
    putsTimer(17*FW+5*FWNUM+1, 0, timersStates[0].val, att, att);
  }
  lcd_invert_line(0);
}
#endif

#if defined(CPUARM) && defined(RTCLOCK)
void putsTime(xcoord_t x, uint8_t y, struct gtm t, LcdFlags att)
{
  putsTimer(x, y, t.tm_hour*60+t.tm_min, att, att);
}
#endif

void putsTimer(xcoord_t x, uint8_t y, putstime_t tme, LcdFlags att, LcdFlags att2)
{
  div_t qr;

  if (!(att & LEFT)) {
    if (att & DBLSIZE)
      x -= 5*(2*FWNUM)-4;
    else if (att & MIDSIZE)
      x -= 5*8-4;
    else
      x -= 5*FWNUM+1;
  }

  if (tme < 0) {
    lcd_putcAtt(x - ((att & DBLSIZE) ? FW+2 : ((att & MIDSIZE) ? FW+0 : FWNUM)), y, '-', att);
    tme = -tme;
  }

  qr = div(tme, 60);

#if defined(PCBTARANIS)
#define separator ':'
  if (att & TIMEHOUR) {
    div_t qr2 = div(qr.quot, 60);
    lcd_outdezNAtt(x, y, qr2.quot, att|LEADING0|LEFT, 2);
    lcd_putcAtt(lcdLastPos, y, separator, att&att2);
    qr.quot = qr2.rem;
    if (att & MIDSIZE)
      x += 17;
    else
      x += 13;
  }
#elif defined(CPUARM)
  char separator = ':';
  if (tme >= 3600 && (~att & DBLSIZE)) {
    qr = div(qr.quot, 60);
    separator = CHR_HOUR;
  }
#else
#define separator ':'
#endif
  lcd_outdezNAtt(x, y, qr.quot, att|LEADING0|LEFT, 2);
#if defined(CPUARM) && defined(RTCLOCK)
  if (att&TIMEBLINK)
    lcd_putcAtt(lcdLastPos, y, separator, BLINK);
  else
#endif
  lcd_putcAtt(lcdLastPos, y, separator, att&att2);
  lcd_outdezNAtt(lcdNextPos, y, qr.rem, att2|LEADING0|LEFT, 2);
}

// TODO to be optimized with putsTelemetryValue
void putsVolts(xcoord_t x, uint8_t y, uint16_t volts, LcdFlags att)
{
  lcd_outdezAtt(x, y, (int16_t)volts, (~NO_UNIT) & (att | ((att&PREC2)==PREC2 ? 0 : PREC1)));
  if (~att & NO_UNIT) lcd_putcAtt(lcdLastPos, y, 'v', att);
}

void putsVBat(xcoord_t x, uint8_t y, LcdFlags att)
{
  putsVolts(x, y, g_vbat100mV, att);
}

void putsStrIdx(xcoord_t x, uint8_t y, const pm_char *str, uint8_t idx, LcdFlags att)
{
  lcd_putsAtt(x, y, str, att & ~LEADING0);
  lcd_outdezNAtt(lcdNextPos, y, idx, att|LEFT, 2);
}

void putsMixerSource(xcoord_t x, uint8_t y, uint8_t idx, LcdFlags att)
{
#if defined(PCBTARANIS)
  if (idx == 0) {
    lcd_putsiAtt(x, y, STR_VSRCRAW, 0, att);
  }
  else if (idx <= MIXSRC_LAST_INPUT) {
    lcd_putcAtt(x+2, y+1, CHR_INPUT, TINSIZE);
    lcd_filled_rect(x, y, 7, 7);
    if (ZEXIST(g_model.inputNames[idx-MIXSRC_FIRST_INPUT]))
      lcd_putsnAtt(x+8, y, g_model.inputNames[idx-MIXSRC_FIRST_INPUT], 4, ZCHAR|att);
    else
      lcd_outdezNAtt(x+8, y, idx, att|LEADING0|LEFT, 2);
  }
#endif

#if defined(PCBTARANIS)
  else if (idx <= MIXSRC_LAST_LUA) {
    div_t qr = div(idx-MIXSRC_FIRST_LUA, MAX_SCRIPT_OUTPUTS);
#if defined(LUA_MODEL_SCRIPTS)
    if (qr.quot < MAX_SCRIPTS && qr.rem < scriptInputsOutputs[qr.quot].outputsCount) {
      lcd_putcAtt(x+2, y+1, '1'+qr.quot, TINSIZE);
      lcd_filled_rect(x, y, 7, 7);
      lcd_putsnAtt(x+8, y, scriptInputsOutputs[qr.quot].outputs[qr.rem].name, att & STREXPANDED ? 9 : 4, att);
    }
    else
#endif
    {
      putsStrIdx(x, y, "LUA", qr.quot+1, att);
      lcd_putcAtt(lcdLastPos, y, 'a'+qr.rem, att);
    }
  }
#endif

#if defined(PCBTARANIS)
  else if (idx < MIXSRC_SW1)
    lcd_putsiAtt(x, y, STR_VSRCRAW, idx-MIXSRC_Rud+1, att);
#else
  if (idx < MIXSRC_THR)
    lcd_putsiAtt(x, y, STR_VSRCRAW, idx, att);
  else if (idx < MIXSRC_SW1)
    putsSwitches(x, y, idx-MIXSRC_THR+1+3*(1/*+EXTRA_3POS*/), att);
  // TODO would perhaps save flash if those switches were in VSRCRAW
#endif
  else if (idx <= MIXSRC_LAST_LOGICAL_SWITCH)
    putsSwitches(x, y, SWSRC_SW1+idx-MIXSRC_SW1, att);
  else if (idx < MIXSRC_CH1)
    putsStrIdx(x, y, STR_PPM_TRAINER, idx-MIXSRC_FIRST_TRAINER+1, att);
  else if (idx <= MIXSRC_LAST_CH) {
    putsStrIdx(x, y, STR_CH, idx-MIXSRC_CH1+1, att);
#if defined(PCBTARANIS)
    if (ZEXIST(g_model.limitData[idx-MIXSRC_CH1].name) && (att & STREXPANDED)) {
      lcd_putcAtt(lcdLastPos, y, ' ', att);
      lcd_putsnAtt(lcdLastPos+3, y, g_model.limitData[idx-MIXSRC_CH1].name, LEN_CHANNEL_NAME, ZCHAR|att);
    }
#endif
  }
#if defined(GVARS) || !defined(PCBSTD)
  else if (idx <= MIXSRC_LAST_GVAR)
    putsStrIdx(x, y, STR_GV, idx-MIXSRC_GVAR1+1, att);
#endif
  else
    lcd_putsiAtt(x, y, STR_VTELEMCHNS, idx-MIXSRC_FIRST_TELEM+1, att);
}

void putsChnLetter(xcoord_t x, uint8_t y, uint8_t idx, LcdFlags att)
{
  lcd_putsiAtt(x, y, STR_RETA123, idx-1, att);
}

void putsModelName(xcoord_t x, uint8_t y, char *name, uint8_t id, LcdFlags att)
{
  uint8_t len = sizeof(g_model.header.name);
  while (len>0 && !name[len-1]) --len;
  if (len==0) {
    putsStrIdx(x, y, STR_MODEL, id+1, att|LEADING0);
  }
  else {
    lcd_putsnAtt(x, y, name, sizeof(g_model.header.name), ZCHAR|att);
  }
}

void putsSwitches(xcoord_t x, uint8_t y, int8_t idx, LcdFlags att)
{
  if (idx == SWSRC_OFF)
    return lcd_putsiAtt(x, y, STR_OFFON, 0, att);
  if (idx < 0) {
    lcd_putcAtt(x-2, y, '!', att);
    idx = -idx;
  }
#if defined(CPUARM) && defined(FLIGHT_MODES)
  if (idx >= SWSRC_FIRST_FLIGHT_MODE)
    putsStrIdx(x, y, STR_FP, idx-SWSRC_FIRST_FLIGHT_MODE, att);
  else
#endif
  lcd_putsiAtt(x, y, STR_VSWITCHES, idx, att);
}

#if defined(FLIGHT_MODES)
void putsFlightMode(xcoord_t x, uint8_t y, int8_t idx, LcdFlags att)
{
  if (idx==0) { lcd_putsiAtt(x, y, STR_MMMINV, 0, att); return; }
  if (idx < 0) { lcd_putcAtt(x-2, y, '!', att); idx = -idx; }
  if (att & CONDENSED)
    lcd_outdezNAtt(x+FW*1, y, idx-1, (att & ~CONDENSED), 1);
  else
    putsStrIdx(x, y, STR_FP, idx-1, att);
}
#endif

#if defined(PCBTARANIS)
void putsCurveRef(xcoord_t x, uint8_t y, CurveRef &curve, LcdFlags att)
{
  if (curve.value != 0) {
    switch (curve.type) {
      case CURVE_REF_DIFF:
        lcd_putcAtt(x, y, 'D', att);
        GVAR_MENU_ITEM(x+FW, y, curve.value, -100, 100, LEFT|att, 0, 0);
        break;

      case CURVE_REF_EXPO:
        lcd_putcAtt(x, y, 'E', att);
        GVAR_MENU_ITEM(x+FW, y, curve.value, -100, 100, LEFT|att, 0, 0);
        break;

      case CURVE_REF_FUNC:
        lcd_putsiAtt(x, y, STR_VCURVEFUNC, curve.value, att);
        break;

      case CURVE_REF_CUSTOM:
        putsCurve(x, y, curve.value, att);
        break;
    }
  }
}

void putsCurve(xcoord_t x, uint8_t y, int8_t idx, LcdFlags att)
{
  if (idx == 0) {
    return lcd_putsiAtt(x, y, STR_MMMINV, 0, att);
  }

  if (idx < 0) {
    lcd_putcAtt(x-3, y, '!', att);
    idx = -idx;
  }

  putsStrIdx(x, y, STR_CV, idx, att);
}
#else
void putsCurve(xcoord_t x, uint8_t y, int8_t idx, LcdFlags att)
{
  if (idx < 0) {
    lcd_putcAtt(x-3, y, '!', att);
    idx = -idx+CURVE_BASE-1;
  }
  if (idx < CURVE_BASE)
    lcd_putsiAtt(x, y, STR_VCURVEFUNC, idx, att);
  else
    putsStrIdx(x, y, STR_CV, idx-CURVE_BASE+1, att);
}
#endif

void putsTimerMode(xcoord_t x, uint8_t y, int8_t mode, LcdFlags att)
{
  if (mode >= 0) {
    if (mode < TMRMODE_COUNT)
      return lcd_putsiAtt(x, y, STR_VTMRMODES, mode, att);
    else
      mode -= (TMRMODE_COUNT-1);
  }
  putsSwitches(x, y, mode, att);
}

#if defined(PCBTARANIS)
void putsTrimMode(xcoord_t x, uint8_t y, uint8_t phase, uint8_t idx, LcdFlags att)
{
  trim_t v = getRawTrimValue(phase, idx);
  unsigned int mode = v.mode;
  unsigned int p = mode >> 1;

  if (mode == TRIM_MODE_NONE) {
    lcd_putsAtt(x, y, "--", att);
  }
  else {
    if (mode % 2 == 0)
      lcd_putcAtt(x, y, ':', att|FIXEDWIDTH);
    else
      lcd_putcAtt(x, y, '+', att|FIXEDWIDTH);
    lcd_putcAtt(lcdNextPos, y, '0'+p, att);
  }
}
#else
void putsTrimMode(xcoord_t x, uint8_t y, uint8_t phase, uint8_t idx, LcdFlags att)
{
  trim_t v = getRawTrimValue(phase, idx);

  if (v > TRIM_EXTENDED_MAX) {
    uint8_t p = v - TRIM_EXTENDED_MAX - 1;
    if (p >= phase) p++;
    lcd_putcAtt(x, y, '0'+p, att);
  }
  else {
    putsChnLetter(x, y, idx+1, att);
  }
}
#endif

#if ROTARY_ENCODERS > 0
void putsRotaryEncoderMode(xcoord_t x, uint8_t y, uint8_t phase, uint8_t idx, LcdFlags att)
{
  int16_t v = flightModeAddress(phase)->rotaryEncoders[idx];

  if (v > ROTARY_ENCODER_MAX) {
    uint8_t p = v - ROTARY_ENCODER_MAX - 1;
    if (p >= phase) p++;
    lcd_putcAtt(x, y, '0'+p, att);
  }
  else {
    lcd_putcAtt(x, y, 'a'+idx, att);
  }
}
#endif

#if defined(FRSKY) || defined(CPUARM)
void putsTelemetryValue(xcoord_t x, uint8_t y, lcdint_t val, uint8_t unit, LcdFlags att)
{
  convertUnit(val, unit);
  lcd_outdezAtt(x, y, val, att & (~NO_UNIT));
  if (!(att & NO_UNIT) && unit != UNIT_RAW) {
    lcd_putsiAtt(lcdLastPos/*+1*/, y, STR_VTELEMUNIT, unit, 0);
  }
}

const pm_uint8_t bchunit_ar[] PROGMEM = {
  UNIT_DIST,    // Alt
  UNIT_RAW,     // Rpm
  UNIT_PERCENT, // Fuel
  UNIT_TEMPERATURE, // T1
  UNIT_TEMPERATURE, // T2
  UNIT_KTS,     // Speed
  UNIT_DIST,    // Dist
  UNIT_DIST,    // GPS Alt
};

void putsTelemetryChannel(xcoord_t x, uint8_t y, uint8_t channel, lcdint_t val, LcdFlags att)
{
  switch (channel) {
#if defined(CPUARM) && defined(RTCLOCK)
    case TELEM_TX_TIME-1:
    {
      gtm t;
      t.tm_hour = val / 60;
      t.tm_min = val % 60;
      putsTime(x, y, t, att);
      break;
    }
#endif
    case TELEM_TIMER1-1:
    case TELEM_TIMER2-1:
      att &= ~NO_UNIT;
      putsTimer(x, y, val, att, att);
      break;
#if defined(FRSKY)
    case TELEM_MIN_A1-1:
    case TELEM_MIN_A2-1:
#if defined(CPUARM)
    case TELEM_MIN_A3-1:
    case TELEM_MIN_A4-1:
#endif
      channel -= TELEM_MIN_A1-TELEM_A1;
      // no break
    case TELEM_A1-1:
    case TELEM_A2-1:
#if defined(CPUARM)
    case TELEM_A3-1:
    case TELEM_A4-1:
#endif
      channel -= TELEM_A1-1;
      // A1 and A2
    {
      lcdint_t converted_value = applyChannelRatio(channel, val);
      if (ANA_CHANNEL_UNIT(channel) >= UNIT_RAW) {
        converted_value = div10_and_round(converted_value);
      }
      else {
#if LCD_W >= 212
        att |= PREC2;
#else
        if (abs(converted_value) < 1000) {
          att |= PREC2;
        }
        else {
          converted_value = div10_and_round(converted_value);
          att |= PREC1;
        }
#endif
      }
      putsTelemetryValue(x, y, converted_value, g_model.frsky.channels[channel].type, att);
      break;
    }
#endif

    case TELEM_CELL-1:
    case TELEM_MIN_CELL-1:
      putsTelemetryValue(x, y, val, UNIT_VOLTS, att|PREC2);
      break;

    case TELEM_TX_VOLTAGE-1:
    case TELEM_VFAS-1:
    case TELEM_CELLS_SUM-1:
    case TELEM_MIN_CELLS_SUM-1:
    case TELEM_MIN_VFAS-1:
      putsTelemetryValue(x, y, val, UNIT_VOLTS, att|PREC1);
      break;

    case TELEM_CURRENT-1:
    case TELEM_MAX_CURRENT-1:
      putsTelemetryValue(x, y, val, UNIT_AMPS, att|PREC1);
      break;

    case TELEM_CONSUMPTION-1:
      putsTelemetryValue(x, y, val, UNIT_MAH, att);
      break;

    case TELEM_POWER-1:
    case TELEM_MAX_POWER-1:
      putsTelemetryValue(x, y, val, UNIT_WATTS, att);
      break;

    case TELEM_ACCx-1:
    case TELEM_ACCy-1:
    case TELEM_ACCz-1:
      putsTelemetryValue(x, y, val, UNIT_RAW, att|PREC2);
      break;

    case TELEM_VSPEED-1:
      putsTelemetryValue(x, y, div10_and_round(val), UNIT_RAW, att|PREC1);
      break;

    case TELEM_ASPEED-1:
    case TELEM_MAX_ASPEED-1:
      putsTelemetryValue(x, y, val, UNIT_KTS, att|PREC1);
      break;

#if defined(CPUARM)
    case TELEM_SWR-1:
#endif
    case TELEM_RSSI_TX-1:
    case TELEM_RSSI_RX-1:
      putsTelemetryValue(x, y, val, UNIT_RAW, att);
      break;

    case TELEM_HDG-1:
      putsTelemetryValue(x, y, val, UNIT_HDG, att);
      break;

#if defined(FRSKY_SPORT)
    case TELEM_ALT-1:
      putsTelemetryValue(x, y, div10_and_round(val), UNIT_DIST, att|PREC1);
      break;
#elif defined(WS_HOW_HIGH)
    case TELEM_ALT-1:
    case TELEM_MIN_ALT-1:
    case TELEM_MAX_ALT-1:
      if (IS_IMPERIAL_ENABLE() && IS_USR_PROTO_WS_HOW_HIGH()) {
        putsTelemetryValue(x, y, val, UNIT_FEET, att);
        break;
      }
      // no break
#endif

    default:
    {
      uint8_t unit = 1;
      if (channel >= TELEM_MAX_T1-1 && channel <= TELEM_MAX_DIST-1)
        channel -= TELEM_MAX_T1 - TELEM_T1;
      if (channel <= TELEM_GPSALT-1)
        unit = channel + 1 - TELEM_ALT;
      if (channel >= TELEM_MIN_ALT-1 && channel <= TELEM_MAX_ALT-1)
        unit = 0;
      putsTelemetryValue(x, y, val, pgm_read_byte(bchunit_ar+unit), att);
      break;
    }
  }
}
#else // defined(FRSKY)
void putsTelemetryChannel(xcoord_t x, uint8_t y, uint8_t channel, lcdint_t val, uint8_t att)
{
  switch (channel) {
    case TELEM_TIMER1-1:
    case TELEM_TIMER2-1:
      att &= ~NO_UNIT;
      putsTimer(x, y, val, att, att);
      break;

    case TELEM_TX_VOLTAGE-1:
      lcd_outdezAtt(x, y, val, (att|PREC1) & (~NO_UNIT));
      if (!(att & NO_UNIT))
        lcd_putc(lcdLastPos/*+1*/, y, 'v');
      break;
  }
}
#endif

void lcdSetContrast()
{
  lcdSetRefVolt(g_eeGeneral.contrast);
}

#endif
