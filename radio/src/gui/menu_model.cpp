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

#include "../opentx.h"
#ifdef MAVLINK
#include "gui/view_mavlink.h"
#endif

#define WCHART 32
#define X0     (LCD_W-WCHART-2)
#define Y0     32

enum EnumTabModel {
  e_ModelSelect,
  e_ModelSetup,
  CASE_HELI(e_Heli)
  CASE_FLIGHT_MODES(e_FlightModesAll)
  e_InputsAll,
  e_MixAll,
  e_Limits,
  CASE_CURVES(e_CurvesAll)
#if LCD_W >= 212
  CASE_GVARS(e_GVars)
#endif
  e_LogicalSwitches,
  e_CustomFunctions,
#if defined(LUA_MODEL_SCRIPTS)
  e_CustomScripts,
#endif
  CASE_FRSKY(e_Telemetry)
  CASE_MAVLINK(e_MavSetup)
  CASE_TEMPLATES(e_Templates)
};

void menuModelSelect(uint8_t event);
void menuModelSetup(uint8_t event);
void menuModelHeli(uint8_t event);
void menuModelFlightModesAll(uint8_t event);
void menuModelExposAll(uint8_t event);
void menuModelMixAll(uint8_t event);
void menuModelLimits(uint8_t event);
void menuModelCurvesAll(uint8_t event);
void menuModelGVars(uint8_t event);
void menuModelLogicalSwitches(uint8_t event);
void menuModelCustomFunctions(uint8_t event);
void menuModelCustomScripts(uint8_t event);
void menuModelTelemetry(uint8_t event);
void menuModelTemplates(uint8_t event);
void menuModelExpoOne(uint8_t event);

const MenuFuncP_PROGMEM menuTabModel[] PROGMEM = {
  menuModelSelect,
  menuModelSetup,
  CASE_HELI(menuModelHeli)
  CASE_FLIGHT_MODES(menuModelFlightModesAll)
  menuModelExposAll,
  menuModelMixAll,
  menuModelLimits,
  CASE_CURVES(menuModelCurvesAll)
#if LCD_W >= 212 && defined(GVARS) && defined(FLIGHT_MODES)
  CASE_GVARS(menuModelGVars)
#endif
  menuModelLogicalSwitches,
  menuModelCustomFunctions,
#if defined(LUA_MODEL_SCRIPTS)
  menuModelCustomScripts,
#endif
  CASE_FRSKY(menuModelTelemetry)
  CASE_MAVLINK(menuTelemetryMavlinkSetup)
  CASE_TEMPLATES(menuModelTemplates)
};

#define COPY_MODE 1
#define MOVE_MODE 2
static uint8_t s_copyMode = 0;
static int8_t s_copySrcRow;
static int8_t s_copyTgtOfs;

uint8_t eeFindEmptyModel(uint8_t id, bool down)
{
  uint8_t i = id;
  for (;;) {
    i = (MAX_MODELS + (down ? i+1 : i-1)) % MAX_MODELS;
    if (!eeModelExists(i)) break;
    if (i == id) return 0xff; // no free space in directory left
  }
  return i;
}

void selectModel(uint8_t sub)
{
  displayPopup(STR_LOADINGMODEL);
  saveTimers();
  eeCheck(true); // force writing of current model data before this is changed
  g_eeGeneral.currModel = sub;
  eeDirty(EE_GENERAL);
  eeLoadModel(sub);
}

#if defined(SDCARD)
#define LIST_NONE_SD_FILE  1
bool listSdFiles(const char *path, const char *extension, const uint8_t maxlen, const char *selection, uint8_t flags=0)
{
  FILINFO fno;
  DIR dir;
  char *fn;   /* This function is assuming non-Unicode cfg. */
#if _USE_LFN
  TCHAR lfn[_MAX_LFN + 1];
  fno.lfname = lfn;
  fno.lfsize = sizeof(lfn);
#endif

  static uint16_t s_last_menu_offset = 0;

#if defined(CPUARM)
  static uint8_t s_last_flags;

  if (selection) {
    s_last_flags = flags;
    memset(reusableBuffer.modelsel.menu_bss, 0, sizeof(reusableBuffer.modelsel.menu_bss));
    strcpy(reusableBuffer.modelsel.menu_bss[0], path);
    strcat(reusableBuffer.modelsel.menu_bss[0], "/");
    strncat(reusableBuffer.modelsel.menu_bss[0], selection, maxlen);
    strcat(reusableBuffer.modelsel.menu_bss[0], extension);
    if (f_stat(reusableBuffer.modelsel.menu_bss[0], &fno) != FR_OK) {
      selection = NULL;
    }
  }
  else {
    flags = s_last_flags;
  }
#endif

  if (s_menu_offset == 0) {
    s_last_menu_offset = 0;
    memset(reusableBuffer.modelsel.menu_bss, 0, sizeof(reusableBuffer.modelsel.menu_bss));
  }
  else if (s_menu_offset == s_menu_count - MENU_MAX_LINES) {
    s_last_menu_offset = 0xffff;
    memset(reusableBuffer.modelsel.menu_bss, 0, sizeof(reusableBuffer.modelsel.menu_bss));
  }
  else if (s_menu_offset == s_last_menu_offset) {
    // should not happen, only there because of Murphy's law
    return true;
  }
  else if (s_menu_offset > s_last_menu_offset) {
    memmove(reusableBuffer.modelsel.menu_bss[0], reusableBuffer.modelsel.menu_bss[1], (MENU_MAX_LINES-1)*MENU_LINE_LENGTH);
    memset(reusableBuffer.modelsel.menu_bss[MENU_MAX_LINES-1], 0xff, MENU_LINE_LENGTH);
  }
  else {
    memmove(reusableBuffer.modelsel.menu_bss[1], reusableBuffer.modelsel.menu_bss[0], (MENU_MAX_LINES-1)*MENU_LINE_LENGTH);
    memset(reusableBuffer.modelsel.menu_bss[0], 0, MENU_LINE_LENGTH);
  }

  s_menu_count = 0;
  s_menu_flags = BSS;

  FRESULT res = f_opendir(&dir, path);        /* Open the directory */
  if (res == FR_OK) {

    if (flags & LIST_NONE_SD_FILE) {
      s_menu_count++;
      if (selection) {
        s_last_menu_offset++;
      }
      else if (s_menu_offset==0 || s_menu_offset < s_last_menu_offset) {
        char *line = reusableBuffer.modelsel.menu_bss[0];
        memset(line, 0, MENU_LINE_LENGTH);
        strcpy(line, "---");
        s_menu[0] = line;
      }
    }

    for (;;) {
      res = f_readdir(&dir, &fno);                   /* Read a directory item */
      if (res != FR_OK || fno.fname[0] == 0) break;  /* Break on error or end of dir */

#if _USE_LFN
      fn = *fno.lfname ? fno.lfname : fno.fname;
#else
      fn = fno.fname;
#endif

      uint8_t len = strlen(fn);
      if (len < 5 || len > maxlen+4 || strcasecmp(fn+len-4, extension) || (fno.fattrib & AM_DIR)) continue;

      s_menu_count++;
      fn[len-4] = '\0';

      if (s_menu_offset == 0) {
        if (selection && strncasecmp(fn, selection, maxlen) < 0) {
          s_last_menu_offset++;
        }
        else {
          for (uint8_t i=0; i<MENU_MAX_LINES; i++) {
            char *line = reusableBuffer.modelsel.menu_bss[i];
            if (line[0] == '\0' || strcasecmp(fn, line) < 0) {
              if (i < MENU_MAX_LINES-1) memmove(reusableBuffer.modelsel.menu_bss[i+1], line, sizeof(reusableBuffer.modelsel.menu_bss[i]) * (MENU_MAX_LINES-1-i));
              memset(line, 0, MENU_LINE_LENGTH);
              strcpy(line, fn);
              break;
            }
          }
        }
        for (uint8_t i=0; i<min(s_menu_count, (uint16_t)MENU_MAX_LINES); i++)
          s_menu[i] = reusableBuffer.modelsel.menu_bss[i];
      }
      else if (s_last_menu_offset == 0xffff) {
        for (int i=MENU_MAX_LINES-1; i>=0; i--) {
          char *line = reusableBuffer.modelsel.menu_bss[i];
          if (line[0] == '\0' || strcasecmp(fn, line) > 0) {
            if (i > 0) memmove(reusableBuffer.modelsel.menu_bss[0], reusableBuffer.modelsel.menu_bss[1], sizeof(reusableBuffer.modelsel.menu_bss[i]) * i);
            memset(line, 0, MENU_LINE_LENGTH);
            strcpy(line, fn);
            break;
          }
        }
        for (uint8_t i=0; i<min(s_menu_count, (uint16_t)MENU_MAX_LINES); i++)
          s_menu[i] = reusableBuffer.modelsel.menu_bss[i];
      }
      else if (s_menu_offset > s_last_menu_offset) {
        if (strcasecmp(fn, reusableBuffer.modelsel.menu_bss[MENU_MAX_LINES-2]) > 0 && strcasecmp(fn, reusableBuffer.modelsel.menu_bss[MENU_MAX_LINES-1]) < 0) {
          memset(reusableBuffer.modelsel.menu_bss[MENU_MAX_LINES-1], 0, MENU_LINE_LENGTH);
          strcpy(reusableBuffer.modelsel.menu_bss[MENU_MAX_LINES-1], fn);
        }
      }
      else {
        if (strcasecmp(fn, reusableBuffer.modelsel.menu_bss[1]) < 0 && strcasecmp(fn, reusableBuffer.modelsel.menu_bss[0]) > 0) {
          memset(reusableBuffer.modelsel.menu_bss[0], 0, MENU_LINE_LENGTH);
          strcpy(reusableBuffer.modelsel.menu_bss[0], fn);
        }
      }
    }
  }

  if (s_menu_offset > 0)
    s_last_menu_offset = s_menu_offset;
  else
    s_menu_offset = s_last_menu_offset;

  return s_menu_count;
}
#endif

#if defined(PCBTARANIS)
  static int8_t modelselBitmapIdx;
  static uint8_t modelselBitmap[MODEL_BITMAP_SIZE];
  #define MODELSEL_W 133
  #define BMP_DIRTY()  modelselBitmapIdx = -1
#else
  #define MODELSEL_W LCD_W
  #define BMP_DIRTY()
#endif

#if defined(NAVIGATION_MENUS)
void onModelSelectMenu(const char *result)
{
  int8_t sub = m_posVert;

  if (result == STR_SELECT_MODEL || result == STR_CREATE_MODEL) {
    selectModel(sub);
  }
  else if (result == STR_COPY_MODEL) {
    s_copyMode = COPY_MODE;
    s_copyTgtOfs = 0;
    s_copySrcRow = -1;
  }
  else if (result == STR_MOVE_MODEL) {
    s_copyMode = MOVE_MODE;
    s_copyTgtOfs = 0;
    s_copySrcRow = -1;
  }
#if defined(SDCARD)
  else if (result == STR_BACKUP_MODEL) {
    eeCheck(true); // force writing of current model data before this is changed
    POPUP_WARNING(eeBackupModel(sub));
  }
  else if (result == STR_RESTORE_MODEL || result == STR_UPDATE_LIST) {
    if (!listSdFiles(MODELS_PATH, MODELS_EXT, MENU_LINE_LENGTH-1, NULL)) {
      POPUP_WARNING(STR_NO_MODELS_ON_SD);
      s_menu_flags = 0;
    }
  }
#endif
  else if (result == STR_DELETE_MODEL) {
    POPUP_CONFIRMATION(STR_DELETEMODEL);
#if defined(CPUARM)
    SET_WARNING_INFO(modelHeaders[sub].name, sizeof(g_model.header.name), ZCHAR);
#else
    char * name = reusableBuffer.modelsel.mainname;
    eeLoadModelName(sub, name);
    SET_WARNING_INFO(name, sizeof(g_model.header.name), ZCHAR);
#endif
  }
#if defined(SDCARD)
  else {
    // The user choosed a file on SD to restore
    POPUP_WARNING(eeRestoreModel(sub, (char *)result));
    BMP_DIRTY();
    if (!s_warning && g_eeGeneral.currModel == sub)
      eeLoadModel(sub);
  }
#endif
}
#endif

void menuModelSelect(uint8_t event)
{
  if (s_warning_result) {
    s_warning_result = 0;
    eeDeleteModel(m_posVert); // delete file
    s_copyMode = 0;
    event = EVT_ENTRY_UP;
    BMP_DIRTY();
  }

  uint8_t _event_ = (IS_ROTARY_BREAK(event) || IS_ROTARY_LONG(event) ? 0 : event);

#if defined(PCBTARANIS)
  if ((s_copyMode && EVT_KEY_MASK(event) == KEY_EXIT) || event == EVT_KEY_BREAK(KEY_EXIT))
    _event_ -= KEY_EXIT;
#else
  if (s_copyMode && EVT_KEY_MASK(event) == KEY_EXIT)
    _event_ -= KEY_EXIT;
#endif

  int8_t oldSub = m_posVert;

  if (!check_submenu_simple(_event_, MAX_MODELS-1)) return;

#if defined(NAVIGATION_POT2)
  if (event==0 && p2valdiff<0) {
    event = EVT_KEY_FIRST(KEY_RIGHT);
  }
#endif

  if (s_editMode > 0) s_editMode = 0;

#if !defined(CPUARM)
  if (event) {
    eeFlush(); // flush eeprom write
  }
#endif

  int8_t sub = m_posVert;

  switch (event)
  {
      case EVT_ENTRY:
        m_posVert = sub = g_eeGeneral.currModel;
        if (sub >= LCD_LINES-1) s_pgOfs = sub-LCD_LINES+2;
        s_copyMode = 0;
        s_editMode = EDIT_MODE_INIT;
        BMP_DIRTY();
        eeCheck(true);
        break;
      case EVT_KEY_LONG(KEY_EXIT):
        if (s_copyMode && s_copyTgtOfs == 0 && g_eeGeneral.currModel != sub && eeModelExists(sub)) {
          POPUP_CONFIRMATION(STR_DELETEMODEL);
#if defined(CPUARM)
          SET_WARNING_INFO(modelHeaders[sub].name, sizeof(g_model.header.name), ZCHAR);
#else
          char * name = reusableBuffer.modelsel.mainname;
          eeLoadModelName(sub, name);
          SET_WARNING_INFO(name, sizeof(g_model.header.name), ZCHAR);
#endif
          killEvents(event);
          break;
        }
        // no break
#if defined(ROTARY_ENCODER_NAVIGATION)
      case EVT_ROTARY_LONG:
        killEvents(event);
        if (s_editMode < 0) {
          popMenu();
          return;
        }
        else if (!s_copyMode) {
          m_posVert = sub = g_eeGeneral.currModel;
          s_copyMode = 0;
          s_editMode = EDIT_MODE_INIT;
        }
        // no break
#endif
      case EVT_KEY_BREAK(KEY_EXIT):
        if (s_copyMode) {
          sub = m_posVert = (s_copyMode == MOVE_MODE || s_copySrcRow<0) ? (MAX_MODELS+sub+s_copyTgtOfs) % MAX_MODELS : s_copySrcRow;
          s_copyMode = 0;
        }
#if defined(PCBTARANIS)
        else {
          if (m_posVert != g_eeGeneral.currModel) {
            m_posVert = g_eeGeneral.currModel;
            s_pgOfs = 0;
          }
          else {
            popMenu();
            return;
          }
        }
#endif
        break;
#if defined(ROTARY_ENCODER_NAVIGATION)
      case EVT_ROTARY_BREAK:
        if (s_editMode == -1) {
          s_editMode = 0;
          break;
        }
        // no break;        
#endif
      case EVT_KEY_LONG(KEY_ENTER):
      case EVT_KEY_BREAK(KEY_ENTER):
        s_editMode = 0;
        if (READ_ONLY()) {
          if (g_eeGeneral.currModel != sub && eeModelExists(sub)) {
            selectModel(sub);
          }
        }
        else if (s_copyMode && (s_copyTgtOfs || s_copySrcRow>=0)) {
          displayPopup(s_copyMode==COPY_MODE ? STR_COPYINGMODEL : STR_MOVINGMODEL);
          eeCheck(true); // force writing of current model data before this is changed

          uint8_t cur = (MAX_MODELS + sub + s_copyTgtOfs) % MAX_MODELS;

          if (s_copyMode == COPY_MODE) {
            if (eeCopyModel(cur, s_copySrcRow))
              BMP_DIRTY();
            else
              cur = sub;
          }

          s_copySrcRow = g_eeGeneral.currModel; // to update the currModel value
          while (sub != cur) {
            uint8_t src = cur;
            cur = (s_copyTgtOfs > 0 ? cur+MAX_MODELS-1 : cur+1) % MAX_MODELS;
            eeSwapModels(src, cur);
            BMP_DIRTY();
            if (src == s_copySrcRow)
              s_copySrcRow = cur;
            else if (cur == s_copySrcRow)
              s_copySrcRow = src;
          }

          if (s_copySrcRow != g_eeGeneral.currModel) {
            g_eeGeneral.currModel = s_copySrcRow;
            eeDirty(EE_GENERAL);
          }

          s_copyMode = 0;
          event = EVT_ENTRY_UP;
        }
        else if (event == EVT_KEY_LONG(KEY_ENTER)
#if !defined(PCBTARANIS)
            || IS_ROTARY_BREAK(event)
#endif
            ) {
          s_copyMode = 0;
          killEvents(event);
#if defined(NAVIGATION_MENUS)
          if (g_eeGeneral.currModel != sub) {
            if (eeModelExists(sub)) {
              MENU_ADD_ITEM(STR_SELECT_MODEL);
              MENU_ADD_SD_ITEM(STR_BACKUP_MODEL);
              MENU_ADD_ITEM(STR_COPY_MODEL);
              MENU_ADD_ITEM(STR_MOVE_MODEL);
              MENU_ADD_ITEM(STR_DELETE_MODEL);
            }
            else {
#if defined(SDCARD)
              MENU_ADD_ITEM(STR_CREATE_MODEL);
              MENU_ADD_ITEM(STR_RESTORE_MODEL);
#else
              selectModel(sub);
#endif
            }
          }
          else {
            MENU_ADD_SD_ITEM(STR_BACKUP_MODEL);
            MENU_ADD_ITEM(STR_COPY_MODEL);
            MENU_ADD_ITEM(STR_MOVE_MODEL);
          }
          menuHandler = onModelSelectMenu;
#else
          if (g_eeGeneral.currModel != sub) {
            selectModel(sub);
          }
#endif
        }
        else if (eeModelExists(sub)) {
          s_copyMode = (s_copyMode == COPY_MODE ? MOVE_MODE : COPY_MODE);
          s_copyTgtOfs = 0;
          s_copySrcRow = -1;
        }
        break;

#if defined(PCBTARANIS)
      case EVT_KEY_BREAK(KEY_PAGE):
      case EVT_KEY_LONG(KEY_PAGE):
        chainMenu(event == EVT_KEY_BREAK(KEY_PAGE) ? menuModelSetup : menuTabModel[DIM(menuTabModel)-1]);
        killEvents(event);
        return;
#else
#if defined(ROTARY_ENCODER_NAVIGATION)
      case EVT_ROTARY_LEFT:
      case EVT_ROTARY_RIGHT:
#endif
      case EVT_KEY_FIRST(KEY_LEFT):
      case EVT_KEY_FIRST(KEY_RIGHT):
#if defined(ROTARY_ENCODER_NAVIGATION)
        if ((!IS_ROTARY_RIGHT(event) && !IS_ROTARY_LEFT(event)) || s_editMode < 0) {
#endif
        if (sub == g_eeGeneral.currModel) {
          chainMenu((IS_ROTARY_RIGHT(event) || event == EVT_KEY_FIRST(KEY_RIGHT)) ? menuModelSetup : menuTabModel[DIM(menuTabModel)-1]);
          return;
        }
        AUDIO_WARNING2();
        break;
#if defined(ROTARY_ENCODER_NAVIGATION)
        }
        // no break
#endif
#endif

      case EVT_KEY_FIRST(KEY_MOVE_UP):
      case EVT_KEY_REPT(KEY_MOVE_UP):
      case EVT_KEY_FIRST(KEY_MOVE_DOWN):
      case EVT_KEY_REPT(KEY_MOVE_DOWN):
        if (s_copyMode) {
          int8_t next_ofs = s_copyTgtOfs + oldSub - m_posVert;
          if (next_ofs == MAX_MODELS || next_ofs == -MAX_MODELS)
            next_ofs = 0;

          if (s_copySrcRow < 0 && s_copyMode==COPY_MODE) {
            s_copySrcRow = oldSub;
            // find a hole (in the first empty slot above / below)
            sub = eeFindEmptyModel(s_copySrcRow, IS_ROTARY_DOWN(event) || event==EVT_KEY_FIRST(KEY_MOVE_DOWN));
            if (sub < 0) {
              // no free room for duplicating the model
              AUDIO_ERROR();
              sub = oldSub;
              s_copyMode = 0;
            }
            next_ofs = 0;
            m_posVert = sub;
          }
          s_copyTgtOfs = next_ofs;
        }
        break;
  }

#if defined(PCBTARANIS)
  lcd_puts(27*FW-(LEN_FREE-4)*FW, 0, STR_FREE);
  if (event) reusableBuffer.modelsel.eepromfree = EeFsGetFree();
  lcd_outdezAtt(20*FW, 0, reusableBuffer.modelsel.eepromfree, 0);
  lcd_puts(21*FW, 0, STR_BYTES);
#elif !defined(PCBSKY9X)
  lcd_puts(9*FW-(LEN_FREE-4)*FW, 0, STR_FREE);
  if (event) reusableBuffer.modelsel.eepromfree = EeFsGetFree();
  lcd_outdezAtt(17*FW, 0, reusableBuffer.modelsel.eepromfree, 0);
#endif

#if defined(ROTARY_ENCODER_NAVIGATION)
  displayScreenIndex(e_ModelSelect, DIM(menuTabModel), (sub == g_eeGeneral.currModel) ? ((IS_RE_NAVIGATION_ENABLE() && s_editMode < 0) ? INVERS|BLINK : INVERS) : 0);
#elif defined(PCBTARANIS)
  displayScreenIndex(e_ModelSelect, DIM(menuTabModel), 0);
  lcd_filled_rect(0, 0, LCD_W, FH, SOLID, FILL_WHITE|GREY_DEFAULT);
#else
  displayScreenIndex(e_ModelSelect, DIM(menuTabModel), (sub == g_eeGeneral.currModel) ? INVERS : 0);
#endif

  TITLE(STR_MENUMODELSEL);

  for (uint8_t i=0; i<LCD_LINES-1; i++) {
    uint8_t y=(i+1)*FH+1;
    uint8_t k=i+s_pgOfs;
    lcd_outdezNAtt(3*FW+2, y, k+1, LEADING0+((!s_copyMode && sub==k) ? INVERS : 0), 2);

    if (s_copyMode == MOVE_MODE || (s_copyMode == COPY_MODE && s_copySrcRow >= 0)) {
      if (k == sub) {
        if (s_copyMode == COPY_MODE) {
          k = s_copySrcRow;
          lcd_putc(MODELSEL_W-FW, y, '+');
        }
        else {
          k = sub + s_copyTgtOfs;
        }
      }
      else if (s_copyTgtOfs < 0 && ((k < sub && k >= sub+s_copyTgtOfs) || (k-MAX_MODELS < sub && k-MAX_MODELS >= sub+s_copyTgtOfs)))
        k += 1;
      else if (s_copyTgtOfs > 0 && ((k > sub && k <= sub+s_copyTgtOfs) || (k+MAX_MODELS > sub && k+MAX_MODELS <= sub+s_copyTgtOfs)))
        k += MAX_MODELS-1;
    }

    k %= MAX_MODELS;

    if (eeModelExists(k)) {
#if defined(PCBSKY9X)
      putsModelName(4*FW, y, modelHeaders[k].name, k, 0);
#elif defined(CPUARM)
      putsModelName(4*FW, y, modelHeaders[k].name, k, 0);
      lcd_outdezAtt(20*FW, y, eeModelSize(k), 0);
#else
      char * name = reusableBuffer.modelsel.listnames[i];
      if (event) eeLoadModelName(k, name);
      putsModelName(4*FW, y, name, k, 0);
      lcd_outdezAtt(20*FW, y, eeModelSize(k), 0);
#endif
      if (k==g_eeGeneral.currModel && (s_copyMode!=COPY_MODE || s_copySrcRow<0 || i+s_pgOfs!=(vertpos_t)sub)) lcd_putc(1, y, '*');
    }

    if (s_copyMode && (vertpos_t)sub==i+s_pgOfs) {
      lcd_filled_rect(9, y, MODELSEL_W-1-9, 7);
      lcd_rect(8, y-1, MODELSEL_W-1-7, 9, s_copyMode == COPY_MODE ? SOLID : DOTTED);
    }
  }

#if defined(PCBTARANIS)
  if (modelselBitmapIdx != m_posVert) {
    modelselBitmapIdx = m_posVert;
    if (modelselBitmapIdx == g_eeGeneral.currModel)
      memcpy(modelselBitmap, modelBitmap, MODEL_BITMAP_SIZE);
    else
      loadModelBitmap(modelHeaders[sub].bitmap, modelselBitmap);
  }
  lcd_bmp(22*FW+2, 2*FH+FH/2, modelselBitmap);
#endif
}

#if defined(CPUARM)
uint8_t g_moduleIdx;
void menuModelFailsafe(uint8_t event)
{
  static bool longNames = false;
  bool newLongNames = false;
  uint8_t ch = 0;

  if (event == EVT_KEY_LONG(KEY_ENTER) && s_editMode) {
    s_noHi = NO_HI_LEN;
    g_model.moduleData[g_moduleIdx].failsafeChannels[m_posVert] = channelOutputs[m_posVert];
    eeDirty(EE_MODEL);
    AUDIO_WARNING1();
    SEND_FAILSAFE_NOW(g_moduleIdx);
  }

  SIMPLE_SUBMENU_NOTITLE(NUM_CHNOUT);

  SET_SCROLLBAR_X(0);

#if LCD_W >= 212
  #define COL_W   (LCD_W/2)
  const uint8_t SLIDER_W = 64;
  // Column separator
  lcd_vline(LCD_W/2, FH, LCD_H-FH);

  if (m_posVert >= 16) {
    ch = 16;
  }
#else
  #define COL_W   (LCD_W)
  const uint8_t SLIDER_W = 90;
  ch = 8 * (m_posVert / 8);
#endif

  lcd_putsCenter(0*FH, FAILSAFESET);
  lcd_invert_line(0);

#if LCD_W >= 212
  for (uint8_t col=0; col<2; col++)
#else
  uint8_t col = 0;
#endif
  {
    uint8_t x = col*COL_W+1;

    // Channels
    for (uint8_t line=0; line<8; line++) {
      uint8_t y = 9+line*7;
      int32_t val;
      uint8_t ofs = (col ? 0 : 1);

      if (ch < g_model.moduleData[g_moduleIdx].channelsStart || ch >= NUM_CHANNELS(g_moduleIdx) + g_model.moduleData[g_moduleIdx].channelsStart)
        val = 0;
      else if (s_editMode && m_posVert == ch)
        val = channelOutputs[ch];
      else
        val = g_model.moduleData[g_moduleIdx].failsafeChannels[8*col+line];

#if defined(PCBTARANIS)
      // Channel name if present, number if not
      uint8_t lenLabel = ZLEN(g_model.limitData[ch].name);
      if (lenLabel > 4) {
        newLongNames = longNames = true;
      }

      if (lenLabel > 0)
        lcd_putsnAtt(x+1-ofs, y, g_model.limitData[ch].name, sizeof(g_model.limitData[ch].name), ZCHAR | SMLSIZE);
      else
        putsChn(x+1-ofs, y, ch+1, SMLSIZE);
#else
      putsChn(x+1-ofs, y, ch+1, SMLSIZE);
#endif

      // Value
      LcdFlags flags = TINSIZE;
      if (m_posVert == ch && !s_noHi) {
        flags |= INVERS;
        if (s_editMode)
          flags |= BLINK;
      }
#if defined(PPM_UNIT_US)
      uint8_t wbar = (longNames ? SLIDER_W-10 : SLIDER_W);
      lcd_outdezAtt(x+COL_W-4-wbar-ofs, y, PPM_CH_CENTER(ch)+val/2, flags);
#elif defined(PPM_UNIT_PERCENT_PREC1)
      uint8_t wbar = (longNames ? SLIDER_W-16 : SLIDER_W-6);
      lcd_outdezAtt(x+COL_W-4-wbar-ofs, y, calcRESXto1000(val), PREC1|flags);
#else
      uint8_t wbar = (longNames ? SLIDER_W-10 : SLIDER_W);
      lcd_outdezAtt(x+COL_W-4-wbar-ofs, y, calcRESXto1000(val)/10, flags);
#endif

      // Gauge
      lcd_rect(x+COL_W-3-wbar-ofs, y, wbar+1, 6);
      uint16_t lim = g_model.extendedLimits ? 640*2 : 512*2;
      uint8_t len = limit((uint8_t)1, uint8_t((abs(val) * wbar/2 + lim/2) / lim), uint8_t(wbar/2));
      uint8_t x0 = (val>0) ? x+COL_W-ofs-3-wbar/2 : x+COL_W-ofs-2-wbar/2-len;
      lcd_hline(x0, y+1, len);
      lcd_hline(x0, y+2, len);
      lcd_hline(x0, y+3, len);
      lcd_hline(x0, y+4, len);

      ch++;
    }
  }

  longNames = newLongNames;
}
#endif

#if defined(CPUM64)
  #define editNameCursorPos m_posHorz
#else
  static uint8_t editNameCursorPos = 0;
#endif

void editName(uint8_t x, uint8_t y, char *name, uint8_t size, uint8_t event, uint8_t active)
{
#if defined(CPUM64)
  // in order to save flash
  lcd_putsLeft(y, STR_NAME);
#endif

  uint8_t mode = 0;
  if (active) {
    if (s_editMode <= 0)
      mode = INVERS + FIXEDWIDTH;
    else
      mode = FIXEDWIDTH;
  }
  lcd_putsnAtt(x, y, name, size, ZCHAR | mode);

  if (active) {
    uint8_t cur = editNameCursorPos;
    if (s_editMode > 0) {
      int8_t c = name[cur];
      int8_t v = c;

      if (p1valdiff || IS_ROTARY_RIGHT(event) || IS_ROTARY_LEFT(event) || event==EVT_KEY_FIRST(KEY_DOWN) || event==EVT_KEY_FIRST(KEY_UP)
          || event==EVT_KEY_REPT(KEY_DOWN) || event==EVT_KEY_REPT(KEY_UP)) {
         v = checkIncDec(event, abs(v), 0, ZCHAR_MAX, 0);
         if (c <= 0) v = -v;
      }

      switch (event) {
#if defined(ROTARY_ENCODER_NAVIGATION) || defined(PCBTARANIS)
        case EVT_ROTARY_BREAK:
          if (s_editMode == EDIT_MODIFY_FIELD) {
            s_editMode = EDIT_MODIFY_STRING;
            cur = 0;
          }
          else if (cur<size-1)
            cur++;
          else
            s_editMode = 0;
          break;
#endif

#if !defined(PCBTARANIS)
        case EVT_KEY_BREAK(KEY_LEFT):
          if (cur>0) cur--;
          break;
        case EVT_KEY_BREAK(KEY_RIGHT):
          if (cur<size-1) cur++;
          break;
#endif

#if defined(ROTARY_ENCODER_NAVIGATION) || defined(PCBTARANIS)
        case EVT_ROTARY_LONG:
          if (v==0) {
            s_editMode = 0;
            killEvents(event);
            break;
          }
          // no break
#endif

#if !defined(PCBTARANIS)
        case EVT_KEY_LONG(KEY_LEFT):
        case EVT_KEY_LONG(KEY_RIGHT):
#endif
          if (v>=-26 && v<=26) {
            v = -v; // toggle case
            if (event==EVT_KEY_LONG(KEY_LEFT))
              killEvents(KEY_LEFT);
          }
          break;
      }

      if (c != v) {
        name[cur] = v;
        eeDirty(EE_MODEL);
      }
      lcd_putcAtt(x+editNameCursorPos*FW, y, idx2char(v), INVERS+FIXEDWIDTH);
    }
    else {
      cur = 0;
    }
    editNameCursorPos = cur;
  }
}

#if defined(CPUM64)
#define editSingleName(x, y, label, name, size, event, active) editName(x, y, name, size, event, active)
#else
void editSingleName(uint8_t x, uint8_t y, const pm_char *label, char *name, uint8_t size, uint8_t event, uint8_t active)
{
  lcd_putsLeft(y, label);
  editName(x, y, name, size, event, active);
}
#endif

enum menuModelSetupItems {
  ITEM_MODEL_NAME,
  CASE_PCBTARANIS(ITEM_MODEL_BITMAP)
  ITEM_MODEL_TIMER1,
  CASE_PERSISTENT_TIMERS(ITEM_MODEL_TIMER1_PERSISTENT)
  ITEM_MODEL_TIMER1_MINUTE_BEEP,
  ITEM_MODEL_TIMER1_COUNTDOWN_BEEP,
  ITEM_MODEL_TIMER2,
  CASE_PERSISTENT_TIMERS(ITEM_MODEL_TIMER2_PERSISTENT)
  ITEM_MODEL_TIMER2_MINUTE_BEEP,
  ITEM_MODEL_TIMER2_COUNTDOWN_BEEP,
  ITEM_MODEL_EXTENDED_LIMITS,
  ITEM_MODEL_EXTENDED_TRIMS,
  ITEM_MODEL_TRIM_INC,
  CASE_PCBTARANIS(ITEM_MODEL_THROTTLE_LABEL)
  ITEM_MODEL_THROTTLE_REVERSED,
  ITEM_MODEL_THROTTLE_TRACE,
  ITEM_MODEL_THROTTLE_TRIM,
  CASE_CPUARM(ITEM_MODEL_PREFLIGHT_LABEL)
  CASE_CPUARM(ITEM_MODEL_CHECKLIST_DISPLAY)
  ITEM_MODEL_THROTTLE_WARNING,
  ITEM_MODEL_SWITCHES_WARNING,
  CASE_PCBTARANIS(ITEM_MODEL_POT_WARNING)
  ITEM_MODEL_BEEP_CENTER,
#if defined(PCBTARANIS)
  ITEM_MODEL_INTERNAL_MODULE_LABEL,
  ITEM_MODEL_INTERNAL_MODULE_MODE,
  ITEM_MODEL_INTERNAL_MODULE_CHANNELS,
  ITEM_MODEL_INTERNAL_MODULE_BIND,
  ITEM_MODEL_INTERNAL_MODULE_FAILSAFE,
  ITEM_MODEL_EXTERNAL_MODULE_LABEL,
  ITEM_MODEL_EXTERNAL_MODULE_MODE,
  ITEM_MODEL_EXTERNAL_MODULE_CHANNELS,
  ITEM_MODEL_EXTERNAL_MODULE_BIND,
  ITEM_MODEL_EXTERNAL_MODULE_FAILSAFE,
  ITEM_MODEL_TRAINER_LABEL,
  ITEM_MODEL_TRAINER_MODE,
  ITEM_MODEL_TRAINER_CHANNELS,
  ITEM_MODEL_TRAINER_SETTINGS,
#elif defined(CPUARM)
  ITEM_MODEL_EXTERNAL_MODULE_LABEL,
  ITEM_MODEL_EXTERNAL_MODULE_MODE,
  ITEM_MODEL_EXTERNAL_MODULE_CHANNELS,
  ITEM_MODEL_EXTERNAL_MODULE_BIND,
  ITEM_MODEL_EXTERNAL_MODULE_FAILSAFE,
#if defined(PCBSKY9X) && !defined(REVA) && !defined(REVX)
  ITEM_MODEL_EXTRA_MODULE_LABEL,
  ITEM_MODEL_EXTRA_MODULE_CHANNELS,
  ITEM_MODEL_EXTRA_MODULE_BIND,
#endif
#else
  ITEM_MODEL_PPM1_PROTOCOL,
  ITEM_MODEL_PPM1_PARAMS,
#endif
  ITEM_MODEL_SETUP_MAX
};

#if defined(PCBSKY9X)
  #define FIELD_PROTOCOL_MAX 2
#else
  #define FIELD_PROTOCOL_MAX 1
#endif

#if LCD_W >= 212
  #define MODEL_SETUP_2ND_COLUMN        (LCD_W-17*FW-MENUS_SCROLLBAR_WIDTH)
  #define MODEL_SETUP_BIND_OFS          3*FW-2
  #define MODEL_SETUP_RANGE_OFS         7*FW
  #define MODEL_SETUP_SET_FAILSAFE_OFS  10*FW
#else
  #define MODEL_SETUP_2ND_COLUMN        (LCD_W-11*FW-MENUS_SCROLLBAR_WIDTH)
  #define MODEL_SETUP_BIND_OFS          2*FW+1
  #define MODEL_SETUP_RANGE_OFS         4*FW+3
  #define MODEL_SETUP_SET_FAILSAFE_OFS  7*FW-2
#endif

#if defined(PCBTARANIS) && defined(SDCARD)
void copySelection(char *dst, const char *src, uint8_t size)
{
  if (memcmp(src, "---", 3) == 0)
    memset(dst, 0, size);
  else
    memcpy(dst, src, size);
}

void onModelSetupBitmapMenu(const char *result)
{
  if (result == STR_UPDATE_LIST) {
    if (!listSdFiles(BITMAPS_PATH, BITMAPS_EXT, sizeof(g_model.header.bitmap), NULL)) {
      POPUP_WARNING(STR_NO_BITMAPS_ON_SD);
      s_menu_flags = 0;
    }
  }
  else {
    // The user choosed a bmp file in the list
    copySelection(g_model.header.bitmap, result, sizeof(g_model.header.bitmap));
    LOAD_MODEL_BITMAP();
    memcpy(modelHeaders[g_eeGeneral.currModel].bitmap, g_model.header.bitmap, sizeof(g_model.header.bitmap));
    eeDirty(EE_MODEL);
  }
}
#endif

#if defined(PCBTARANIS)
  #define CURRENT_MODULE_EDITED(k)         (k>=ITEM_MODEL_TRAINER_LABEL ? TRAINER_MODULE : (k>=ITEM_MODEL_EXTERNAL_MODULE_LABEL ? EXTERNAL_MODULE : INTERNAL_MODULE))
#elif defined(PCBSKY9X) && !defined(REVA) && !defined(REVX)
  #define CURRENT_MODULE_EDITED(k)         (k>=ITEM_MODEL_EXTRA_MODULE_LABEL ? EXTRA_MODULE : EXTERNAL_MODULE)
#else
  #define CURRENT_MODULE_EDITED(k)         (EXTERNAL_MODULE)
#endif

void menuModelSetup(uint8_t event)
{
#if defined(PCBTARANIS)
  #define IF_INTERNAL_MODULE_ON(x)          (g_model.moduleData[INTERNAL_MODULE].rfProtocol == RF_PROTO_OFF ? HIDDEN_ROW : (uint8_t)(x))
  #define IF_EXTERNAL_MODULE_ON(x)          (g_model.externalModule == MODULE_TYPE_NONE ? HIDDEN_ROW : (uint8_t)(x))
  #define IF_TRAINER_ON(x)                  (g_model.trainerMode ? (uint8_t)(x) : HIDDEN_ROW)
  #define IF_EXTERNAL_MODULE_XJT(x)         (IS_MODULE_XJT(EXTERNAL_MODULE) ? (uint8_t)x : HIDDEN_ROW)
  #define IS_D8_RX(x)                       (g_model.moduleData[x].rfProtocol == RF_PROTO_D8)
  #define INTERNAL_MODULE_CHANNELS_ROWS()   IF_INTERNAL_MODULE_ON(1)
  #define EXTERNAL_MODULE_CHANNELS_ROWS()   IF_EXTERNAL_MODULE_ON(IS_MODULE_DSM2(EXTERNAL_MODULE) ? (uint8_t)0 : (uint8_t)1)
  #define TRAINER_CHANNELS_ROWS()           IF_TRAINER_ON(1)
  #define PORT_CHANNELS_ROWS(x)             (x==INTERNAL_MODULE ? INTERNAL_MODULE_CHANNELS_ROWS() : (x==EXTERNAL_MODULE ? EXTERNAL_MODULE_CHANNELS_ROWS() : TRAINER_CHANNELS_ROWS()))
  #define FAILSAFE_ROWS(x)                  ((g_model.moduleData[x].rfProtocol==RF_PROTO_X16 || g_model.moduleData[x].rfProtocol==RF_PROTO_LR12) ? (g_model.moduleData[x].failsafeMode==FAILSAFE_CUSTOM ? (uint8_t)1 : (uint8_t)0) : HIDDEN_ROW)
  #define MODEL_SETUP_MAX_LINES             (1+ITEM_MODEL_SETUP_MAX)
  #define POT_WARN_ITEMS()                  ((g_model.nPotsToWarn >> 6) ? (uint8_t)NUM_POTS : (uint8_t)0)
  bool CURSOR_ON_CELL = (m_posHorz >= 0);
  MENU_TAB({ 0, 0, CASE_PCBTARANIS(0) 2, CASE_PERSISTENT_TIMERS(0) 0, 0, 2, CASE_PERSISTENT_TIMERS(0) 0, 0, 0, 1, 0, CASE_PCBTARANIS(LABEL(Throttle)) 0, 0, 0, CASE_CPUARM(LABEL(PreflightCheck)) CASE_CPUARM(0) 0, 7, POT_WARN_ITEMS(), NAVIGATION_LINE_BY_LINE|(NUM_STICKS+NUM_POTS+NUM_ROTARY_ENCODERS-1), LABEL(InternalModule), 0, IF_INTERNAL_MODULE_ON(1), IF_INTERNAL_MODULE_ON(IS_D8_RX(0) ? (uint8_t)1 : (uint8_t)2), IF_INTERNAL_MODULE_ON(FAILSAFE_ROWS(INTERNAL_MODULE)), LABEL(ExternalModule), (IS_MODULE_XJT(EXTERNAL_MODULE) || IS_MODULE_DSM2(EXTERNAL_MODULE)) ? (uint8_t)1 : (uint8_t)0, EXTERNAL_MODULE_CHANNELS_ROWS(), (IS_MODULE_XJT(EXTERNAL_MODULE) && IS_D8_RX(EXTERNAL_MODULE)) ? (uint8_t)1 : (IS_MODULE_PPM(EXTERNAL_MODULE) || IS_MODULE_XJT(EXTERNAL_MODULE) || IS_MODULE_DSM2(EXTERNAL_MODULE)) ? (uint8_t)2 : HIDDEN_ROW, IF_EXTERNAL_MODULE_XJT(FAILSAFE_ROWS(EXTERNAL_MODULE)), LABEL(Trainer), 0, TRAINER_CHANNELS_ROWS(), IF_TRAINER_ON(2)});
#elif defined(CPUARM)
  #define IF_EXTERNAL_MODULE_XJT(x)         (IS_MODULE_XJT(EXTERNAL_MODULE) ? (uint8_t)x : HIDDEN_ROW)
  #define IF_EXTERNAL_MODULE_ON(x)          (g_model.externalModule == MODULE_TYPE_NONE ? HIDDEN_ROW : (uint8_t)(x))
  #define IS_D8_RX(x)                       (g_model.moduleData[x].rfProtocol == RF_PROTO_D8)
  #define EXTERNAL_MODULE_CHANNELS_ROWS()   IF_EXTERNAL_MODULE_ON(IS_MODULE_DSM2(EXTERNAL_MODULE) ? (uint8_t)0 : (uint8_t)1)
  #define TRAINER_CHANNELS_ROWS()           (HIDDEN_ROW)
  #define PORT_CHANNELS_ROWS(x)             (x==EXTERNAL_MODULE ? EXTERNAL_MODULE_CHANNELS_ROWS() : 0)
  #define FAILSAFE_ROWS(x)                  ((g_model.moduleData[x].rfProtocol==RF_PROTO_X16 || g_model.moduleData[x].rfProtocol==RF_PROTO_LR12) ? (g_model.moduleData[x].failsafeMode==FAILSAFE_CUSTOM ? (uint8_t)1 : (uint8_t)0) : HIDDEN_ROW)
  #define CURSOR_ON_CELL                    (true)
  #define MODEL_SETUP_MAX_LINES             (1+ITEM_MODEL_SETUP_MAX)
  #define POT_WARN_ITEMS()                  ((g_model.nPotsToWarn >> 6) ? (uint8_t)NUM_POTS : (uint8_t)0)
#if defined(PCBTARANIS) || (defined(PCBSKY9X) && !defined(REVA) && !defined(REVX))
  #define EXTRA_MODULE_ROWS                 LABEL(ExtraModule), 1, 2,
#else
  #define EXTRA_MODULE_ROWS
#endif
#if defined(PCBTARANIS)
  #define TRAINER_MODULE_ROWS               LABEL(Trainer), IF_TRAINER_ON(1), 2
#else
  #define TRAINER_MODULE_ROWS
#endif
  MENU_TAB({ 0, 0, CASE_PCBTARANIS(0) 2, CASE_PERSISTENT_TIMERS(0) 0, 0, 2, CASE_PERSISTENT_TIMERS(0) 0, 0, 0, 1, 0, CASE_PCBTARANIS(LABEL(Throttle)) 0, 0, 0, CASE_CPUARM(LABEL(PreflightCheck)) CASE_CPUARM(0) 0, 6, NUM_STICKS+NUM_POTS+NUM_ROTARY_ENCODERS-1, LABEL(ExternalModule), (IS_MODULE_XJT(EXTERNAL_MODULE) || IS_MODULE_DSM2(EXTERNAL_MODULE)) ? (uint8_t)1 : (uint8_t)0, EXTERNAL_MODULE_CHANNELS_ROWS(), (IS_MODULE_XJT(EXTERNAL_MODULE) && IS_D8_RX(EXTERNAL_MODULE)) ? (uint8_t)1 : (IS_MODULE_PPM(EXTERNAL_MODULE) || IS_MODULE_XJT(EXTERNAL_MODULE) || IS_MODULE_DSM2(EXTERNAL_MODULE)) ? (uint8_t)2 : HIDDEN_ROW, IF_EXTERNAL_MODULE_XJT(FAILSAFE_ROWS(EXTERNAL_MODULE)), EXTRA_MODULE_ROWS TRAINER_MODULE_ROWS });
#elif defined(CPUM64)
  #define CURSOR_ON_CELL                    (true)
  #define MODEL_SETUP_MAX_LINES             ((IS_PPM_PROTOCOL(protocol)||IS_DSM2_PROTOCOL(protocol)||IS_PXX_PROTOCOL(protocol)) ? 1+ITEM_MODEL_SETUP_MAX : ITEM_MODEL_SETUP_MAX)
  uint8_t protocol = g_model.protocol;
  MENU_TAB({ 0, 0, CASE_PCBTARANIS(0) 2, CASE_PERSISTENT_TIMERS(0) 0, 0, 2, CASE_PERSISTENT_TIMERS(0) 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, NUM_STICKS+NUM_POTS+NUM_ROTARY_ENCODERS-1, FIELD_PROTOCOL_MAX, 2 });
#else
  #define CURSOR_ON_CELL                    (true)
  #define MODEL_SETUP_MAX_LINES             ((IS_PPM_PROTOCOL(protocol)||IS_DSM2_PROTOCOL(protocol)||IS_PXX_PROTOCOL(protocol)) ? 1+ITEM_MODEL_SETUP_MAX : ITEM_MODEL_SETUP_MAX)
  uint8_t protocol = g_model.protocol;
  MENU_TAB({ 0, 0, CASE_PCBTARANIS(0) 2, CASE_PERSISTENT_TIMERS(0) 0, 0, 2, CASE_PERSISTENT_TIMERS(0) 0, 0, 0, 1, 0, 0, 0, 0, 0, NUM_SWITCHES, NUM_STICKS+NUM_POTS+NUM_ROTARY_ENCODERS-1, FIELD_PROTOCOL_MAX, 2, CASE_PCBSKY9X(1) CASE_PCBSKY9X(2) });
#endif

  if (!MENU_CHECK(menuTabModel, e_ModelSetup, MODEL_SETUP_MAX_LINES)) {
#if defined(DSM2)
    dsm2Flag = 0;
#endif
#if defined(PCBTARANIS)
    pxxFlag[INTERNAL_MODULE] = 0;
#endif
#if defined(CPUARM) && defined(PXX)
    pxxFlag[EXTERNAL_MODULE] = 0;
#endif
    return;
  }

  TITLE(STR_MENUSETUP);

  uint8_t sub = m_posVert - 1;
  int8_t editMode = s_editMode;

  for (uint8_t i=0; i<LCD_LINES-1; i++) {
    uint8_t y = 1 + 1*FH + i*FH;

    uint8_t k = i+s_pgOfs;
#if defined(CPUARM)
    for (int j=0; j<=k; j++) {
      if (mstate_tab[j+1] == HIDDEN_ROW)
        k++;
    }
#endif

    uint8_t blink = ((editMode>0) ? BLINK|INVERS : INVERS);
    uint8_t attr = (sub == k ? blink : 0);

    switch(k) {
      case ITEM_MODEL_NAME:
        editSingleName(MODEL_SETUP_2ND_COLUMN, y, STR_MODELNAME, g_model.header.name, sizeof(g_model.header.name), event, attr);
#if defined(CPUARM)
        memcpy(modelHeaders[g_eeGeneral.currModel].name, g_model.header.name, sizeof(g_model.header.name));
#endif
        break;

#if defined(PCBTARANIS) && defined(SDCARD)
      case ITEM_MODEL_BITMAP:
        lcd_putsLeft(y, STR_BITMAP);
        if (ZEXIST(g_model.header.bitmap))
          lcd_putsnAtt(MODEL_SETUP_2ND_COLUMN, y, g_model.header.bitmap, sizeof(g_model.header.bitmap), attr);
        else
          lcd_putsiAtt(MODEL_SETUP_2ND_COLUMN, y, STR_VCSWFUNC, 0, attr);
        if (attr && event==EVT_KEY_BREAK(KEY_ENTER) && READ_ONLY_UNLOCKED()) {
          s_editMode = 0;
          if (listSdFiles(BITMAPS_PATH, BITMAPS_EXT, sizeof(g_model.header.bitmap), g_model.header.bitmap, LIST_NONE_SD_FILE)) {
            menuHandler = onModelSetupBitmapMenu;
          }
          else {
            POPUP_WARNING(STR_NO_BITMAPS_ON_SD);
            s_menu_flags = 0;
          }
        }
        break;
#endif

      case ITEM_MODEL_TIMER1:
      case ITEM_MODEL_TIMER2:
      case ITEM_MODEL_TIMER1_MINUTE_BEEP:
      case ITEM_MODEL_TIMER2_MINUTE_BEEP:
      case ITEM_MODEL_TIMER1_COUNTDOWN_BEEP:
      case ITEM_MODEL_TIMER2_COUNTDOWN_BEEP:
      {
        TimerData *timer = &g_model.timers[k>=ITEM_MODEL_TIMER2 ? 1 : 0];
        if (k==ITEM_MODEL_TIMER1_MINUTE_BEEP || k==ITEM_MODEL_TIMER2_MINUTE_BEEP) {
          timer->minuteBeep = onoffMenuItem(timer->minuteBeep, MODEL_SETUP_2ND_COLUMN, y, STR_MINUTEBEEP, attr, event);
        }
        else if (k==ITEM_MODEL_TIMER1_COUNTDOWN_BEEP || k==ITEM_MODEL_TIMER2_COUNTDOWN_BEEP) {
#if defined(CPUARM)
          timer->countdownBeep = selectMenuItem(MODEL_SETUP_2ND_COLUMN, y, STR_BEEPCOUNTDOWN, STR_VBEEPCOUNTDOWN, timer->countdownBeep, 0, 2, attr, event);
#else
          timer->countdownBeep = onoffMenuItem(timer->countdownBeep, MODEL_SETUP_2ND_COLUMN, y, STR_BEEPCOUNTDOWN, attr, event);         
#endif
        }
        else {
          putsStrIdx(0*FW, y, STR_TIMER, k>=ITEM_MODEL_TIMER2 ? 2 : 1);
          putsTimerMode(MODEL_SETUP_2ND_COLUMN, y, timer->mode, m_posHorz==0 ? attr : 0);
          putsTimer(MODEL_SETUP_2ND_COLUMN+5*FW-2+5*FWNUM+1, y, timer->start, m_posHorz==1 ? attr : 0, m_posHorz==2 ? attr : 0);
#if defined(PCBTARANIS)
          if (attr && m_posHorz < 0) lcd_filled_rect(MODEL_SETUP_2ND_COLUMN, y, LCD_W-MODEL_SETUP_2ND_COLUMN-MENUS_SCROLLBAR_WIDTH, 8);
#endif
          if (attr && (editMode>0 || p1valdiff)) {
            div_t qr = div(timer->start, 60);
            switch (m_posHorz) {
              case 0:
                CHECK_INCDEC_MODELVAR_CHECK(event, timer->mode, SWSRC_FIRST, TMRMODE_COUNT+SWSRC_LAST-1/*SWSRC_None removed*/, isSwitchAvailableInTimers);
#if defined(AUTOSWITCH)
                if (s_editMode>0) {
                  int8_t val = timer->mode - (TMRMODE_COUNT-1);
                  int8_t switchVal = checkIncDecMovedSwitch(val);
                  if (val != switchVal) {
                    timer->mode = switchVal + (TMRMODE_COUNT-1);
                    eeDirty(EE_MODEL);
                  }
                }
#endif
                break;
              case 1:
                CHECK_INCDEC_MODELVAR_ZERO(event, qr.quot, 59);
                timer->start = qr.rem + qr.quot*60;
                break;
              case 2:
                qr.rem -= checkIncDecModel(event, qr.rem+2, 1, 62)-2;
                timer->start -= qr.rem ;
                if ((int16_t)timer->start < 0) timer->start=0;
                break;
            }
          }
        }
        break;
      }

#if defined(CPUARM) || defined(PCBGRUVIN9X)
      case ITEM_MODEL_TIMER1_PERSISTENT:
      case ITEM_MODEL_TIMER2_PERSISTENT:
      {
        TimerData &timer = g_model.timers[k==ITEM_MODEL_TIMER2_PERSISTENT];
        timer.persistent = selectMenuItem(MODEL_SETUP_2ND_COLUMN, y, STR_PERSISTENT, STR_VPERSISTENT, timer.persistent, 0, 2, attr, event);
        break;
      }
#endif

      case ITEM_MODEL_EXTENDED_LIMITS:
        g_model.extendedLimits = onoffMenuItem(g_model.extendedLimits, MODEL_SETUP_2ND_COLUMN, y, STR_ELIMITS, attr, event);
        break;

      case ITEM_MODEL_EXTENDED_TRIMS:
#if defined(CPUM64)
        g_model.extendedTrims = onoffMenuItem(g_model.extendedTrims, MODEL_SETUP_2ND_COLUMN, y, STR_ETRIMS, attr, event);
#else
        g_model.extendedTrims = onoffMenuItem(g_model.extendedTrims, MODEL_SETUP_2ND_COLUMN, y, STR_ETRIMS, m_posHorz<=0 ? attr : 0, event==EVT_KEY_BREAK(KEY_ENTER) ? event : 0);
        lcd_putsAtt(MODEL_SETUP_2ND_COLUMN+3*FW, y, STR_RESET_BTN, m_posHorz>0  && !s_noHi ? attr : 0);
        if (attr && m_posHorz>0) {
          s_editMode = 0;
          if (event==EVT_KEY_LONG(KEY_ENTER)) {
            s_noHi = NO_HI_LEN;
            for (uint8_t i=0; i<MAX_FLIGHT_MODES; i++) {
              memclear(&g_model.flightModeData[i], TRIMS_ARRAY_SIZE);
            }
            eeDirty(EE_MODEL);
            AUDIO_WARNING1();
          }
        }
#endif
        break;

      case ITEM_MODEL_TRIM_INC:
        g_model.trimInc = selectMenuItem(MODEL_SETUP_2ND_COLUMN, y, STR_TRIMINC, STR_VTRIMINC, g_model.trimInc, -2, 2, attr, event);
        break;

#if defined(PCBTARANIS)
      case ITEM_MODEL_THROTTLE_LABEL:
        lcd_putsLeft(y, STR_THROTTLE_LABEL);
        break;
#endif

      case ITEM_MODEL_THROTTLE_REVERSED:
        g_model.throttleReversed = onoffMenuItem(g_model.throttleReversed, MODEL_SETUP_2ND_COLUMN, y, STR_THROTTLEREVERSE, attr, event ) ;
        break;

      case ITEM_MODEL_THROTTLE_TRACE:
      {
        lcd_putsLeft(y, STR_TTRACE);
        if (attr) CHECK_INCDEC_MODELVAR_ZERO_CHECK(event, g_model.thrTraceSrc, NUM_POTS+NUM_CHNOUT, isThrottleSourceAvailable);
        uint8_t idx = g_model.thrTraceSrc + MIXSRC_Thr;
        if (idx > MIXSRC_Thr)
          idx += 1;
        if (idx >= MIXSRC_FIRST_POT+NUM_POTS)
          idx += MIXSRC_CH1 - MIXSRC_FIRST_POT - NUM_POTS;
        putsMixerSource(MODEL_SETUP_2ND_COLUMN, y, idx, attr);
        break;
      }

      case ITEM_MODEL_THROTTLE_TRIM:
        g_model.thrTrim = onoffMenuItem(g_model.thrTrim, MODEL_SETUP_2ND_COLUMN, y, STR_TTRIM, attr, event);
        break;

#if defined(CPUARM)
      case ITEM_MODEL_PREFLIGHT_LABEL:
        lcd_putsLeft(y, STR_PREFLIGHT);
        break;

      case ITEM_MODEL_CHECKLIST_DISPLAY:
        g_model.displayChecklist = onoffMenuItem(g_model.displayChecklist, MODEL_SETUP_2ND_COLUMN, y, STR_CHECKLIST, attr, event);
        break;
#endif

      case ITEM_MODEL_THROTTLE_WARNING:
        g_model.disableThrottleWarning = !onoffMenuItem(!g_model.disableThrottleWarning, MODEL_SETUP_2ND_COLUMN, y, STR_THROTTLEWARNING, attr, event);
        break;
        
      case ITEM_MODEL_SWITCHES_WARNING:
      {
        lcd_putsLeft(y, STR_SWITCHWARNING);
        swstate_t states = g_model.switchWarningStates;
        char c;
        if (attr) {
          s_editMode = 0;
          if (!READ_ONLY()) {
            switch (event) {
              CASE_EVT_ROTARY_BREAK
              case EVT_KEY_BREAK(KEY_ENTER):
#if defined(CPUM64)
                g_model.nSwToWarn ^= (1 << m_posHorz);
                eeDirty(EE_MODEL);
#else
                if (m_posHorz < NUM_SWITCHES-1) {
                  g_model.nSwToWarn ^= (1 << m_posHorz);
                  eeDirty(EE_MODEL);
                }
#endif
                break;
                
              case EVT_KEY_LONG(KEY_ENTER):
#if defined(CPUM64)
                getMovedSwitch();
                g_model.switchWarningStates = switches_states;
                AUDIO_WARNING1();
                eeDirty(EE_MODEL);
#else
                if (m_posHorz == NUM_SWITCHES-1) {
                  s_noHi = NO_HI_LEN;
                  getMovedSwitch();
                  g_model.switchWarningStates = switches_states;
                  AUDIO_WARNING1();
                  eeDirty(EE_MODEL);
                }
#endif
                killEvents(event);
                break; 
            }
          }
        }

        LcdFlags line = attr;
        
        for (uint8_t i=0; i<NUM_SWITCHES-1; i++) {
          uint8_t swactive = !(g_model.nSwToWarn & 1 << i);
#if defined(PCBTARANIS)
          c = "\300-\301"[states & 0x03];
          lcd_putcAtt(MODEL_SETUP_2ND_COLUMN+i*(2*FW+1), y, 'A'+i, line && (m_posHorz == i) ? INVERS : 0);
          if (swactive) lcd_putc(MODEL_SETUP_2ND_COLUMN+i*(2*FW+1)+FWNUM+1, y, c);
          lcd_putsAtt(MODEL_SETUP_2ND_COLUMN+((NUM_SWITCHES-1)*2*FW+8), y, PSTR("<]"), (m_posHorz == NUM_SWITCHES-1 && !s_noHi) ? line : 0); 
          states >>= 2;
#else
          attr = 0;
          
          if (IS_3POS(i)) {
            c = '0'+(states & 0x03);
            states >>= 2;
          }
          else {
            if ((states & 0x01) && swactive)
              attr = INVERS;
            c = pgm_read_byte(STR_VSWITCHES - 2 + 9 + (3*(i+1)));
            states >>= 1;
          }
          if (line && (m_posHorz == i)) {
            attr = BLINK;
            if (swactive)
              attr |= INVERS;
          }
          lcd_putcAtt(MODEL_SETUP_2ND_COLUMN+i*FW, y, (swactive || (attr & BLINK)) ? c : '-', attr);
#if !defined(CPUM64)
          lcd_putsAtt(MODEL_SETUP_2ND_COLUMN+(NUM_SWITCHES*FW), y, PSTR("<]"), (m_posHorz == NUM_SWITCHES-1 && !s_noHi) ? line : 0);
#endif       
#endif
        }
        break;
      }
#if defined(PCBTARANIS)
      case ITEM_MODEL_POT_WARNING:
      {
        lcd_putsLeft(y, STR_POTWARNING);
        uint8_t potMode = g_model.nPotsToWarn >> 6;
        if (attr) {
          if (m_posHorz) s_editMode = 0;
          if (!READ_ONLY() && m_posHorz) {
            switch (event) {
              case EVT_KEY_LONG(KEY_ENTER):
                killEvents(event);
                if (potMode == 1) {
                  SAVE_POT_POSITION(m_posHorz-1);
                  AUDIO_WARNING1();
                  eeDirty(EE_MODEL);
                }
                break;
              case EVT_KEY_BREAK(KEY_ENTER):
                g_model.nPotsToWarn ^= (1 << (m_posHorz-1));
                eeDirty(EE_MODEL);
                break;
             }
           }
         }

        lcd_putsiAtt(MODEL_SETUP_2ND_COLUMN, y, PSTR("\004""OFF\0""Man\0""Auto"), potMode, attr & ((m_posHorz == 0) ? attr : !INVERS));
        if (potMode) {
          uint8_t x = MODEL_SETUP_2ND_COLUMN+5*FW;
          for (uint8_t i=0; i<NUM_POTS ; i++) {
#if !defined(REVPLUS)
            if (i == POT3-POT1) {
              if (attr && (m_posHorz==i+1)) REPEAT_LAST_CURSOR_MOVE();
              continue;
            }
#endif
            LcdFlags flags = ((m_posHorz==i+1) && attr) ? BLINK : 0;
            flags |= (!(g_model.nPotsToWarn & (1 << i))) ? INVERS : 0;
            lcd_putsiAtt(x, y, STR_VSRCRAW, NUM_STICKS+1+i, flags);
            x += (2*FW+3);
          }
        }
       
        if (attr && (m_posHorz == 0)) {
          CHECK_INCDEC_MODELVAR(event, potMode, 0, 2);
          g_model.nPotsToWarn = (g_model.nPotsToWarn & 0x3F) | ((potMode << 6) & 0xC0);
          eeDirty(EE_MODEL);
        }
        break;
      }
#endif

      case ITEM_MODEL_BEEP_CENTER:
        lcd_putsLeft(y, STR_BEEPCTR);
        for (uint8_t i=0; i<NUM_STICKS+NUM_POTS+NUM_ROTARY_ENCODERS; i++) {
          // TODO flash saving, \001 not needed in STR_RETA123
          uint8_t x = MODEL_SETUP_2ND_COLUMN+i*FW;
#if defined(PCBTARANIS) && !defined(REVPLUS)
          if (i == POT3) {
            if (attr && m_posHorz == POT3) REPEAT_LAST_CURSOR_MOVE();
            continue;
          }
          else if (i > POT3) {
            x -= FW;
          }
#endif
          lcd_putsiAtt(x, y, STR_RETA123, i, ((m_posHorz==i) && attr) ? BLINK|INVERS : (((g_model.beepANACenter & ((BeepANACenter)1<<i)) || (attr && CURSOR_ON_LINE())) ? INVERS : 0 ) );
        }
        if (attr && CURSOR_ON_CELL) {
          if (event==EVT_KEY_BREAK(KEY_ENTER) || p1valdiff) {
            if (READ_ONLY_UNLOCKED()) {
              s_editMode = 0;
              g_model.beepANACenter ^= ((BeepANACenter)1<<m_posHorz);
              eeDirty(EE_MODEL);
            }
          }
        }
        break;

#if defined(PCBSKY9X) && !defined(REVX)
      case ITEM_MODEL_EXTRA_MODULE_LABEL:
        lcd_putsLeft(y, "RF Port 2 (PPM)");
        break;
#endif

#if defined(PCBTARANIS)
      case ITEM_MODEL_INTERNAL_MODULE_LABEL:
        lcd_putsLeft(y, TR_INTERNALRF);
        break;

      case ITEM_MODEL_INTERNAL_MODULE_MODE:
        lcd_putsLeft(y, STR_MODE);
        lcd_putsiAtt(MODEL_SETUP_2ND_COLUMN, y, STR_XJT_PROTOCOLS, 1+g_model.moduleData[0].rfProtocol, attr);
        if (attr) {
          CHECK_INCDEC_MODELVAR(event, g_model.moduleData[0].rfProtocol, RF_PROTO_OFF, RF_PROTO_LAST);
          if (checkIncDec_Ret) {
            g_model.moduleData[0].channelsStart = 0;
            g_model.moduleData[0].channelsCount = 0;
          }
        }
        break;

      case ITEM_MODEL_TRAINER_MODE:
        g_model.trainerMode = selectMenuItem(MODEL_SETUP_2ND_COLUMN, y, STR_MODE, STR_VTRAINERMODES, g_model.trainerMode, 0, 1, attr, event);
        break;
#endif

#if defined(CPUARM)
      case ITEM_MODEL_EXTERNAL_MODULE_LABEL:
        lcd_putsLeft(y, TR_EXTERNALRF);
        break;

      case ITEM_MODEL_EXTERNAL_MODULE_MODE:
        lcd_putsLeft(y, STR_MODE);
        lcd_putsiAtt(MODEL_SETUP_2ND_COLUMN, y, STR_TARANIS_PROTOCOLS, g_model.externalModule, m_posHorz==0 ? attr : 0);
        if (IS_MODULE_XJT(EXTERNAL_MODULE))
          lcd_putsiAtt(MODEL_SETUP_2ND_COLUMN+5*FW, y, STR_XJT_PROTOCOLS, 1+g_model.moduleData[EXTERNAL_MODULE].rfProtocol, m_posHorz==1 ? attr : 0);
        else if (IS_MODULE_DSM2(EXTERNAL_MODULE))
          lcd_putsiAtt(MODEL_SETUP_2ND_COLUMN+5*FW, y, STR_DSM_PROTOCOLS, g_model.moduleData[EXTERNAL_MODULE].rfProtocol, m_posHorz==1 ? attr : 0);
        if (attr && (editMode>0 || p1valdiff)) {
          switch (m_posHorz) {
            case 0:
              g_model.externalModule = checkIncDec(event, g_model.externalModule, MODULE_TYPE_NONE, MODULE_TYPE_COUNT-1, EE_MODEL, isModuleAvailable);
              if (checkIncDec_Ret) {
                g_model.moduleData[EXTERNAL_MODULE].rfProtocol = 0;
                g_model.moduleData[EXTERNAL_MODULE].channelsStart = 0;
                if (g_model.externalModule == MODULE_TYPE_PPM)
                  g_model.moduleData[EXTERNAL_MODULE].channelsCount = 0;
                else
                  g_model.moduleData[EXTERNAL_MODULE].channelsCount = MAX_EXTERNAL_MODULE_CHANNELS();
              }
              break;
            case 1:
              if (IS_MODULE_DSM2(EXTERNAL_MODULE))
                CHECK_INCDEC_MODELVAR(event, g_model.moduleData[EXTERNAL_MODULE].rfProtocol, DSM2_PROTO_LP45, DSM2_PROTO_DSMX);
              else
                CHECK_INCDEC_MODELVAR(event, g_model.moduleData[EXTERNAL_MODULE].rfProtocol, RF_PROTO_X16, RF_PROTO_LAST);
              if (checkIncDec_Ret) {
                g_model.moduleData[EXTERNAL_MODULE].channelsStart = 0;
                g_model.moduleData[EXTERNAL_MODULE].channelsCount = MAX_EXTERNAL_MODULE_CHANNELS();
              }
          }
        }
        break;
#endif

#if defined(PCBTARANIS)
      case ITEM_MODEL_TRAINER_LABEL:
        lcd_putsLeft(y, STR_TRAINER);
        break;

      case ITEM_MODEL_INTERNAL_MODULE_CHANNELS:
#elif defined(PCBSKY9X) && !defined(REVX)
      case ITEM_MODEL_EXTRA_MODULE_CHANNELS:
#endif
#if defined(CPUARM)
      case ITEM_MODEL_EXTERNAL_MODULE_CHANNELS:
#if defined(PCBTARANIS)
      case ITEM_MODEL_TRAINER_CHANNELS:
#endif
      {
        uint8_t moduleIdx = CURRENT_MODULE_EDITED(k);
        ModuleData & moduleData = g_model.moduleData[moduleIdx];
        lcd_putsLeft(y, STR_CHANNELRANGE);
        if ((int8_t)PORT_CHANNELS_ROWS(moduleIdx) >= 0) {
          lcd_putsAtt(MODEL_SETUP_2ND_COLUMN, y, STR_CH, m_posHorz==0 ? attr : 0);
          lcd_outdezAtt(lcdLastPos, y, moduleData.channelsStart+1, LEFT | (m_posHorz==0 ? attr : 0));
          lcd_putc(lcdLastPos, y, '-');
          lcd_outdezAtt(lcdLastPos + FW+1, y, moduleData.channelsStart+NUM_CHANNELS(moduleIdx), LEFT | (m_posHorz==1 ? attr : 0));
          if (attr && (editMode>0 || p1valdiff)) {
            switch (m_posHorz) {
              case 0:
                CHECK_INCDEC_MODELVAR_ZERO(event, moduleData.channelsStart, 32-8-moduleData.channelsCount);
                break;
              case 1:
                CHECK_INCDEC_MODELVAR(event, moduleData.channelsCount, -4, min<int8_t>(MAX_CHANNELS(moduleIdx), 32-8-moduleData.channelsStart));
                if ((k == ITEM_MODEL_EXTERNAL_MODULE_CHANNELS && g_model.externalModule == MODULE_TYPE_PPM)
#if defined(PCBTARANIS)
                    || (k == ITEM_MODEL_TRAINER_CHANNELS)
#endif
                    )
                  SET_DEFAULT_PPM_FRAME_LENGTH(moduleIdx);
                break;
            }
          }
        }
        break;
      }
#endif

#if defined(PCBTARANIS)
      case ITEM_MODEL_INTERNAL_MODULE_BIND:
#elif defined(PCBSKY9X) && !defined(REVX)
      case ITEM_MODEL_EXTRA_MODULE_BIND:
#endif
#if defined(CPUARM)
      case ITEM_MODEL_EXTERNAL_MODULE_BIND:
#if defined(PCBTARANIS)
      case ITEM_MODEL_TRAINER_SETTINGS:
#endif
      {
        uint8_t moduleIdx = CURRENT_MODULE_EDITED(k);
        ModuleData & moduleData = g_model.moduleData[moduleIdx];
        if (IS_MODULE_PPM(moduleIdx)) {
          lcd_putsLeft(y, STR_PPMFRAME);
          lcd_puts(MODEL_SETUP_2ND_COLUMN+3*FW, y, STR_MS);
          lcd_outdezAtt(MODEL_SETUP_2ND_COLUMN, y, (int16_t)moduleData.ppmFrameLength*5 + 225, (m_posHorz<=0 ? attr : 0) | PREC1|LEFT);
          lcd_putc(MODEL_SETUP_2ND_COLUMN+8*FW+2, y, 'u');
          lcd_outdezAtt(MODEL_SETUP_2ND_COLUMN+8*FW+2, y, (moduleData.ppmDelay*50)+300, (m_posHorz < 0 || m_posHorz==1) ? attr : 0);
          lcd_putcAtt(MODEL_SETUP_2ND_COLUMN+10*FW, y, moduleData.ppmPulsePol ? '+' : '-', (m_posHorz < 0 || m_posHorz==2) ? attr : 0);

          if (attr && (editMode>0 || p1valdiff)) {
            switch (m_posHorz) {
              case 0:
                CHECK_INCDEC_MODELVAR(event, moduleData.ppmFrameLength, -20, 35);
                break;
              case 1:
                CHECK_INCDEC_MODELVAR(event, moduleData.ppmDelay, -4, 10);
                break;
              case 2:
                CHECK_INCDEC_MODELVAR_ZERO(event, moduleData.ppmPulsePol, 1);
                break;
            }
          }
        }
        else {
          horzpos_t l_posHorz = m_posHorz;
          uint8_t xOffsetBind = MODEL_SETUP_BIND_OFS;
          if (IS_MODULE_XJT(moduleIdx) && IS_D8_RX(moduleIdx)) {
            xOffsetBind = 0;
            lcd_putsLeft(y, INDENT "Receiver");
            if (attr) l_posHorz += 1;
          }
          else {
            lcd_putsLeft(y, STR_RXNUM);
          }
          if (IS_MODULE_XJT(moduleIdx) || IS_MODULE_DSM2(moduleIdx)) {
            if (xOffsetBind) lcd_outdezNAtt(MODEL_SETUP_2ND_COLUMN, y, g_model.header.modelId, (l_posHorz==0 ? attr : 0) | LEADING0|LEFT, 2);
            if (attr && l_posHorz==0) {
              if (editMode>0 || p1valdiff) {
                CHECK_INCDEC_MODELVAR_ZERO(event, g_model.header.modelId, IS_MODULE_DSM2(moduleIdx) ? 20 : 63);
                if (checkIncDec_Ret) {
                  modelHeaders[g_eeGeneral.currModel].modelId = g_model.header.modelId;
                }
              }
              if (editMode==0 && event==EVT_KEY_BREAK(KEY_ENTER)) {
                checkModelIdUnique(g_eeGeneral.currModel);
              }
            }
            lcd_putsAtt(MODEL_SETUP_2ND_COLUMN+xOffsetBind, y, STR_MODULE_BIND, l_posHorz==1 ? attr : 0);
            lcd_putsAtt(MODEL_SETUP_2ND_COLUMN+MODEL_SETUP_RANGE_OFS+xOffsetBind, y, STR_MODULE_RANGE, l_posHorz==2 ? attr : 0);
            if (IS_MODULE_XJT(moduleIdx)) {
#if defined(PXX)
              uint8_t newFlag = 0;
              if (attr && l_posHorz>0 && s_editMode>0) {
                if (l_posHorz == 1)
                  newFlag = PXX_SEND_RXNUM;
                else if (l_posHorz == 2) {
                  newFlag = PXX_SEND_RANGECHECK;
                }
              }
              pxxFlag[moduleIdx] = newFlag;
#endif
            }
#if defined(DSM2)
            else {
              uint8_t newFlag = 0;
              if (attr && l_posHorz>0 && s_editMode>0) {
                if (l_posHorz == 1)
                  newFlag = DSM2_BIND_FLAG;
                else if (l_posHorz == 2) {
                  newFlag = DSM2_RANGECHECK_FLAG;
                }
              }
              dsm2Flag = newFlag;
            }
#endif
          }
        }
        break;
      }
#endif

#if defined(PCBTARANIS)
      case ITEM_MODEL_INTERNAL_MODULE_FAILSAFE:
#endif
#if defined(CPUARM)
      case ITEM_MODEL_EXTERNAL_MODULE_FAILSAFE:
      {
        uint8_t moduleIdx = CURRENT_MODULE_EDITED(k);
        ModuleData & moduleData = g_model.moduleData[moduleIdx];
        lcd_putsLeft(y, TR_FAILSAFE);
        if (IS_MODULE_XJT(moduleIdx)) {
          lcd_putsiAtt(MODEL_SETUP_2ND_COLUMN, y, STR_VFAILSAFE, moduleData.failsafeMode, m_posHorz==0 ? attr : 0);
          if (moduleData.failsafeMode == FAILSAFE_CUSTOM) lcd_putsAtt(MODEL_SETUP_2ND_COLUMN + MODEL_SETUP_SET_FAILSAFE_OFS, y, STR_SET, m_posHorz==1 ? attr : 0);
          if (attr) {
            if (moduleData.failsafeMode != FAILSAFE_CUSTOM)
              m_posHorz = 0;
            if (m_posHorz==0) {
              if (editMode>0 || p1valdiff) {
                CHECK_INCDEC_MODELVAR_ZERO(event, moduleData.failsafeMode, FAILSAFE_LAST);
                if (checkIncDec_Ret) SEND_FAILSAFE_NOW(moduleIdx);
              }
            }
            else if (m_posHorz==1) {
              s_editMode = 0;
              if (moduleData.failsafeMode==FAILSAFE_CUSTOM && event==EVT_KEY_FIRST(KEY_ENTER)) {
                g_moduleIdx = moduleIdx;
                pushMenu(menuModelFailsafe);
              }
            }
            else {
              lcd_filled_rect(MODEL_SETUP_2ND_COLUMN, y, LCD_W-MODEL_SETUP_2ND_COLUMN-MENUS_SCROLLBAR_WIDTH, 8);
            }
          }
        }
        break;
      }
#endif

#if !defined(CPUARM)
      case ITEM_MODEL_PPM1_PROTOCOL:
        lcd_putsLeft(y, NO_INDENT(STR_PROTO));
        lcd_putsiAtt(MODEL_SETUP_2ND_COLUMN, y, STR_VPROTOS, protocol, m_posHorz<=0 ? attr : 0);
        if (IS_PPM_PROTOCOL(protocol)) {
          lcd_putsiAtt(MODEL_SETUP_2ND_COLUMN+7*FW, y, STR_NCHANNELS, g_model.ppmNCH+2, m_posHorz!=0 ? attr : 0);
        }
        else if (m_posHorz>0 && attr) {
          MOVE_CURSOR_FROM_HERE();
        }
        if (attr && (editMode>0 || p1valdiff || (!IS_PPM_PROTOCOL(protocol) && !IS_DSM2_PROTOCOL(protocol)))) {
          switch (m_posHorz) {
            case 0:
              CHECK_INCDEC_MODELVAR_ZERO(event, g_model.protocol, PROTO_MAX-1);
              break;
            case 1:
              CHECK_INCDEC_MODELVAR(event, g_model.ppmNCH, -2, 4);
              g_model.ppmFrameLength = g_model.ppmNCH * 8;
              break;
          }
        }
        break;
#endif

#if 0
      case ITEM_MODEL_PPM2_PROTOCOL:
        lcd_putsLeft(y, PSTR("Port2"));
        lcd_putsiAtt(MODEL_SETUP_2ND_COLUMN, y, STR_VPROTOS, 0, 0);
        lcd_putsAtt(MODEL_SETUP_2ND_COLUMN+4*FW+3, y, STR_CH, m_posHorz<=0 ? attr : 0);
        lcd_outdezAtt(lcdLastPos, y, g_model.moduleData[1].channelsStart+1, LEFT | (m_posHorz<=0 ? attr : 0));
        lcd_putc(lcdLastPos, y, '-');
        lcd_outdezAtt(lcdLastPos + FW+1, y, g_model.moduleData[1].channelsStart+8+g_model.moduleData[1].channelsCount, LEFT | (m_posHorz!=0 ? attr : 0));
        if (attr && (editMode>0 || p1valdiff)) {
          switch (m_posHorz) {
            case 0:
              CHECK_INCDEC_MODELVAR_ZERO(event, g_model.moduleData[1].channelsStart, 32-8-g_model.moduleData[1].channelsCount);
              SET_DEFAULT_PPM_FRAME_LENGTH(1);
              break;
            case 1:
              CHECK_INCDEC_MODELVAR(event, g_model.moduleData[1].channelsCount, -4, min<int8_t>(8, 32-8-g_model.moduleData[1].channelsStart));
              SET_DEFAULT_PPM_FRAME_LENGTH(1);
              break;
          }
        }
        break;

      case ITEM_MODEL_PPM2_PARAMS:
        lcd_putsLeft(y, STR_PPMFRAME);
        lcd_puts(MODEL_SETUP_2ND_COLUMN+3*FW, y, STR_MS);
        lcd_outdezAtt(MODEL_SETUP_2ND_COLUMN, y, (int16_t)g_model.moduleData[1].ppmFrameLength*5 + 225, (m_posHorz<=0 ? attr : 0) | PREC1|LEFT);
        lcd_putc(MODEL_SETUP_2ND_COLUMN+8*FW+2, y, 'u');
        lcd_outdezAtt(MODEL_SETUP_2ND_COLUMN+8*FW+2, y, (g_model.moduleData[1].ppmDelay*50)+300, (m_posHorz < 0 || m_posHorz==1) ? attr : 0);
        lcd_putcAtt(MODEL_SETUP_2ND_COLUMN+10*FW, y, g_model.moduleData[1].ppmPulsePol ? '+' : '-', (m_posHorz < 0 || m_posHorz==2) ? attr : 0);
        if (attr && (editMode>0 || p1valdiff)) {
          switch (m_posHorz) {
            case 0:
              CHECK_INCDEC_MODELVAR(event, g_model.moduleData[1].ppmFrameLength, -20, 35);
              break;
            case 1:
              CHECK_INCDEC_MODELVAR(event, g_model.moduleData[1].ppmDelay, -4, 10);
              break;
            case 2:
              CHECK_INCDEC_MODELVAR_ZERO(event, g_model.moduleData[1].ppmPulsePol, 1);
              break;
          }
        }
        break;
#endif

#if !defined(CPUARM)
      case ITEM_MODEL_PPM1_PARAMS:
        if (IS_PPM_PROTOCOL(protocol)) {
          lcd_putsLeft(y, STR_PPMFRAME);
          lcd_puts(MODEL_SETUP_2ND_COLUMN+3*FW, y, STR_MS);
          lcd_outdezAtt(MODEL_SETUP_2ND_COLUMN, y, (int16_t)g_model.ppmFrameLength*5 + 225, (m_posHorz<=0 ? attr : 0) | PREC1|LEFT);
          lcd_putc(MODEL_SETUP_2ND_COLUMN+8*FW+2, y, 'u');
          lcd_outdezAtt(MODEL_SETUP_2ND_COLUMN+8*FW+2, y, (g_model.ppmDelay*50)+300, (m_posHorz < 0 || m_posHorz==1) ? attr : 0);
          lcd_putcAtt(MODEL_SETUP_2ND_COLUMN+10*FW, y, g_model.pulsePol ? '+' : '-', (m_posHorz < 0 || m_posHorz==2) ? attr : 0);
          if (attr && (editMode>0 || p1valdiff)) {
            switch (m_posHorz) {
              case 0:
                CHECK_INCDEC_MODELVAR(event, g_model.ppmFrameLength, -20, 35);
                break;
              case 1:
                CHECK_INCDEC_MODELVAR(event, g_model.ppmDelay, -4, 10);
                break;
              case 2:
                CHECK_INCDEC_MODELVAR_ZERO(event, g_model.pulsePol, 1);
                break;
            }
          }
        }
#if defined(DSM2) || defined(PXX)
        else if (IS_DSM2_PROTOCOL(protocol) || IS_PXX_PROTOCOL(protocol)) {
          if (attr && m_posHorz > 1) {
            REPEAT_LAST_CURSOR_MOVE(); // limit 3 column row to 2 colums (Rx_Num and RANGE fields)
          }

          lcd_putsLeft(y, STR_RXNUM);
          lcd_outdezNAtt(MODEL_SETUP_2ND_COLUMN, y, g_model.header.modelId, (m_posHorz<=0 ? attr : 0) | LEADING0|LEFT, 2);
          if (attr && (m_posHorz==0 && (editMode>0 || p1valdiff))) {
            CHECK_INCDEC_MODELVAR_ZERO(event, g_model.header.modelId, 99);
          }
#if defined(PXX)
          if (protocol == PROTO_PXX) {
            lcd_putsAtt(MODEL_SETUP_2ND_COLUMN+4*FW, y, STR_SYNCMENU, m_posHorz!=0 ? attr : 0);
            uint8_t newFlag = 0;
            if (attr && m_posHorz>0 && editMode>0) {
              // send reset code
              newFlag = PXX_SEND_RXNUM;
            }
            pxxFlag[0] = newFlag;
          }
#endif
#if defined(DSM2)
          if (IS_DSM2_PROTOCOL(protocol)) {
            lcd_putsAtt(MODEL_SETUP_2ND_COLUMN+4*FW, y, STR_MODULE_RANGE, m_posHorz!=0 ? attr : 0);
            dsm2Flag = (attr && m_posHorz>0 && editMode>0) ? DSM2_RANGECHECK_FLAG : 0; // [MENU] key toggles range check mode
          }
#endif
        }
#endif
        break;
#endif
    }
  }

#if defined(CPUARM) && defined(PXX)
  if (IS_PXX_RANGE_CHECK_ENABLE()) {
    displayPopup("RSSI: ");
    lcd_outdezAtt(16+4*FW, 5*FH, frskyData.rssi[0].value, BOLD);
  }
#endif
}

static uint8_t s_currIdx;

#if MENU_COLUMNS < 2
  #if LCD_W >= 212
    #define MIXES_2ND_COLUMN  (18*FW)
  #else
    #define MIXES_2ND_COLUMN  (12*FW)
  #endif
#else
  #define MIXES_2ND_COLUMN    (9*FW)
#endif

#if LCD_W >= 212
  #define EXPO_ONE_2ND_COLUMN (LCD_W-8*FW-90)
  #define EXPO_ONE_FP_WIDTH   (9*FW)
#else
  #define EXPO_ONE_2ND_COLUMN (7*FW+3*FW+2)
  #define EXPO_ONE_FP_WIDTH   (5*FW)
#endif

#if MENU_COLUMNS > 1
uint8_t editDelay(const xcoord_t x, const uint8_t y, const uint8_t event, const uint8_t attr, const pm_char *str, uint8_t delay)
{
  lcd_puts(x, y, str);
  lcd_outdezAtt(x+MIXES_2ND_COLUMN, y, (10/DELAY_STEP)*delay, attr|PREC1|LEFT);
  if (attr) CHECK_INCDEC_MODELVAR_ZERO(event, delay, DELAY_MAX);
  return delay;
}
#define EDIT_DELAY(x, y, event, attr, str, delay) editDelay(x, y, event, attr, str, delay)
#else
uint8_t editDelay(const uint8_t y, const uint8_t event, const uint8_t attr, const pm_char *str, uint8_t delay)
{
  lcd_putsLeft(y, str);
  lcd_outdezAtt(MIXES_2ND_COLUMN, y, (10/DELAY_STEP)*delay, attr|PREC1|LEFT);
  if (attr) CHECK_INCDEC_MODELVAR_ZERO(event, delay, DELAY_MAX);
  return delay;
}
#define EDIT_DELAY(x, y, event, attr, str, delay) editDelay(y, event, attr, str, delay)
#endif

#if defined(FLIGHT_MODES)

#if defined(CPUARM)
  #define FlightModesType uint16_t
#else
  #define FlightModesType uint8_t
#endif

#if defined(PCBTARANIS)
void displayFlightModes(uint8_t x, uint8_t y, FlightModesType value)
{
  lcd_puts(x, y, STR_FP);
  x = lcdNextPos + 1;
  for (uint8_t p=0; p<MAX_FLIGHT_MODES; p++) {
    lcd_putc(x, y, ((value & (1<<p)) ? '-' : '0'+p));
    x += 5;
  }
}
#else
void displayFlightModes(uint8_t x, uint8_t y, FlightModesType value)
{
  uint8_t p = MAX_FLIGHT_MODES;
  do {
    --p;
    if (!(value & (1<<p)))
      lcd_putc(x, y, '0'+p);
    x -= FWNUM;
  } while (p!=0);
}
#endif

FlightModesType editFlightModes(uint8_t x, uint8_t y, uint8_t event, FlightModesType value, uint8_t attr)
{
  lcd_putsColumnLeft(x, y, STR_FLMODE);

  uint8_t posHorz = m_posHorz;

#if defined(CPUARM) && LCD_W < 212
  bool expoMenu = (x==EXPO_ONE_2ND_COLUMN-5*FW);
#endif

  for (uint8_t p=0; p<MAX_FLIGHT_MODES; p++) {
#if defined(CPUARM) && LCD_W < 212
    if (expoMenu && ((attr && p < posHorz-4) || (x > EXPO_ONE_2ND_COLUMN-FW)))
      continue;
#endif
#if defined(PCBTARANIS)
    LcdFlags flags = 0;
    if (attr) {
      flags |= INVERS;
      if (posHorz==p) flags |= BLINK;
    }
    if (value & (1<<p))
      lcd_putcAtt(x, y, ' ', flags|FIXEDWIDTH);
    else
      lcd_putcAtt(x, y, '0'+p, flags);
#else
    lcd_putcAtt(x, y, '0'+p, ((posHorz==p) && attr) ? BLINK|INVERS : ((value & (1<<p)) ? 0 : INVERS));
#endif
    x += FW;
  }

  if (attr) {
    if (s_editMode && ((event==EVT_KEY_BREAK(KEY_ENTER) || p1valdiff))) {
      s_editMode = 0;
      value ^= (1<<posHorz);
      eeDirty(EE_MODEL);
    }
  }

  return value;
}

#if defined(PCBTARANIS)

enum FlightModesItems {
  ITEM_FLIGHT_MODES_NAME,
  ITEM_FLIGHT_MODES_SWITCH,
  ITEM_FLIGHT_MODES_TRIM_RUD,
  ITEM_FLIGHT_MODES_TRIM_ELE,
  ITEM_FLIGHT_MODES_TRIM_THR,
  ITEM_FLIGHT_MODES_TRIM_AIL,
  ITEM_FLIGHT_MODES_FADE_IN,
  ITEM_FLIGHT_MODES_FADE_OUT,
  ITEM_FLIGHT_MODES_COUNT,
  ITEM_FLIGHT_MODES_LAST = ITEM_FLIGHT_MODES_COUNT-1
};

bool isTrimModeAvailable(int mode)
{
  return (mode < 0 || (mode%2) == 0 || (mode/2) != (m_posVert-1));
}

void menuModelFlightModesAll(uint8_t event)
{
  MENU(STR_MENUFLIGHTPHASES, menuTabModel, e_FlightModesAll, 1+MAX_FLIGHT_MODES+1, {0, NAVIGATION_LINE_BY_LINE|(ITEM_FLIGHT_MODES_LAST-1), NAVIGATION_LINE_BY_LINE|ITEM_FLIGHT_MODES_LAST, NAVIGATION_LINE_BY_LINE|ITEM_FLIGHT_MODES_LAST, NAVIGATION_LINE_BY_LINE|NAVIGATION_LINE_BY_LINE|ITEM_FLIGHT_MODES_LAST, NAVIGATION_LINE_BY_LINE|ITEM_FLIGHT_MODES_LAST, NAVIGATION_LINE_BY_LINE|ITEM_FLIGHT_MODES_LAST, NAVIGATION_LINE_BY_LINE|ITEM_FLIGHT_MODES_LAST, NAVIGATION_LINE_BY_LINE|ITEM_FLIGHT_MODES_LAST, NAVIGATION_LINE_BY_LINE|ITEM_FLIGHT_MODES_LAST, 0});

  int8_t sub = m_posVert - 1;

  horzpos_t posHorz = m_posHorz;
  if (sub==0 && posHorz > 0) { posHorz += 1; }

  if (sub<MAX_FLIGHT_MODES && posHorz>=0) {
    displayColumnHeader(STR_PHASES_HEADERS, posHorz);
  }

  for (uint8_t i=0; i<LCD_LINES-1; i++) {
    uint8_t y = 1 + (i+1)*FH;
    uint8_t k = i+s_pgOfs;

    if (k==MAX_FLIGHT_MODES) {
      // last line available - add the "check trims" line
      lcd_putsLeft((LCD_LINES-1)*FH+1, STR_CHECKTRIMS);
      putsFlightMode(OFS_CHECKTRIMS, (LCD_LINES-1)*FH+1, mixerCurrentFlightMode+1);
      if (sub==MAX_FLIGHT_MODES) {
        if (!trimsCheckTimer) {
          if (event == EVT_KEY_FIRST(KEY_ENTER)) {
            trimsCheckTimer = 200; // 2 seconds trims cancelled
            s_editMode = 1;
            killEvents(event);
          }
          else {
            lcd_status_line();
            s_editMode = 0;
          }
        }
        else {
          if (event == EVT_KEY_FIRST(KEY_EXIT)) {
            trimsCheckTimer = 0;
            s_editMode = 0;
            killEvents(event);
          }
        }
      }
      return;
    }

    FlightModeData *p = flightModeAddress(k);

    putsFlightMode(0, y, k+1, (getFlightMode()==k ? BOLD : 0) | ((sub==k && CURSOR_ON_LINE()) ? INVERS : 0));

    for (uint8_t j=0; j<ITEM_FLIGHT_MODES_COUNT; j++) {
      uint8_t attr = ((sub==k && posHorz==j) ? ((s_editMode>0) ? BLINK|INVERS : INVERS) : 0);
      uint8_t active = (attr && (s_editMode>0 || p1valdiff)) ;
      switch (j) {
        case ITEM_FLIGHT_MODES_NAME:
          editName(4*FW-1, y, p->name, sizeof(p->name), event, attr);
          break;

        case ITEM_FLIGHT_MODES_SWITCH:
          putsSwitches((5+LEN_FP_NAME)*FW+FW/2, y, p->swtch, attr);
          if (active) CHECK_INCDEC_MODELSWITCH(event, p->swtch, SWSRC_FIRST_IN_MIXES, SWSRC_LAST_IN_MIXES, isSwitchAvailableInMixes);
          break;

        case ITEM_FLIGHT_MODES_TRIM_RUD:
        case ITEM_FLIGHT_MODES_TRIM_ELE:
        case ITEM_FLIGHT_MODES_TRIM_THR:
        case ITEM_FLIGHT_MODES_TRIM_AIL:
        {
          uint8_t t = j-ITEM_FLIGHT_MODES_TRIM_RUD;
          putsTrimMode((4+LEN_FP_NAME)*FW+j*(5*FW/2), y, k, t, attr);
          if (active) {
            trim_t & v = p->trim[t];
            v.mode = checkIncDec(event, v.mode==TRIM_MODE_NONE ? -1 : v.mode, -1, k==0 ? 0 : 2*MAX_FLIGHT_MODES-1, EE_MODEL, isTrimModeAvailable);
          }
          break;
        }

        case ITEM_FLIGHT_MODES_FADE_IN:
          lcd_outdezAtt(32*FW-2, y, (10/DELAY_STEP)*p->fadeIn, attr|PREC1);
          if (active) p->fadeIn = checkIncDec(event, p->fadeIn, 0, DELAY_MAX, EE_MODEL|NO_INCDEC_MARKS);
          break;

        case ITEM_FLIGHT_MODES_FADE_OUT:
          lcd_outdezAtt(35*FW, y, (10/DELAY_STEP)*p->fadeOut, attr|PREC1);
          if (active) p->fadeOut = checkIncDec(event, p->fadeOut, 0, DELAY_MAX, EE_MODEL|NO_INCDEC_MARKS);
          break;

      }
    }
  }
}

#else // PCBTARANIS

enum menuModelPhaseItems {
  ITEM_MODEL_PHASE_NAME,
  ITEM_MODEL_PHASE_SWITCH,
  ITEM_MODEL_PHASE_TRIMS,
  IF_ROTARY_ENCODERS(ITEM_MODEL_PHASE_ROTARY_ENCODERS)
  ITEM_MODEL_PHASE_FADE_IN,
  ITEM_MODEL_PHASE_FADE_OUT,
#if defined(GVARS) && !defined(PCBSTD)
  ITEM_MODEL_PHASE_GVARS_LABEL,
  ITEM_MODEL_PHASE_GV1,
  ITEM_MODEL_PHASE_GV2,
  ITEM_MODEL_PHASE_GV3,
  ITEM_MODEL_PHASE_GV4,
  ITEM_MODEL_PHASE_GV5,
#if defined(CPUARM)
  ITEM_MODEL_PHASE_GV6,
  ITEM_MODEL_PHASE_GV7,
  ITEM_MODEL_PHASE_GV8,
  ITEM_MODEL_PHASE_GV9,
#endif
#endif
  ITEM_MODEL_PHASE_MAX
};

void menuModelPhaseOne(uint8_t event)
{
  FlightModeData *fm = flightModeAddress(s_currIdx);
  putsFlightMode(13*FW, 0, s_currIdx+1, (getFlightMode()==s_currIdx ? BOLD : 0));

#if defined(GVARS) && !defined(PCBSTD)
  static const pm_uint8_t mstate_tab_fm1[] PROGMEM = {0, 0, 0, (uint8_t)-1, 1, 1, 1, 1, 1};
  static const pm_uint8_t mstate_tab_others[] PROGMEM = {0, 0, 3, IF_ROTARY_ENCODERS(NUM_ROTARY_ENCODERS-1) 0, 0, (uint8_t)-1, 2, 2, 2, 2, 2};

  if (!check(event, 0, NULL, 0, (s_currIdx == 0) ? mstate_tab_fm1 : mstate_tab_others, DIM(mstate_tab_others)-1, ITEM_MODEL_PHASE_MAX - 1 - (s_currIdx==0 ? (ITEM_MODEL_PHASE_FADE_IN-ITEM_MODEL_PHASE_SWITCH) : 0))) return;

  TITLE(STR_MENUFLIGHTPHASE);

  #define PHASE_ONE_FIRST_LINE (1+1*FH)
#else
  SUBMENU(STR_MENUFLIGHTPHASE, 3 + (s_currIdx==0 ? 0 : 2 + (bool)NUM_ROTARY_ENCODERS), {0, 0, 3, IF_ROTARY_ENCODERS(NUM_ROTARY_ENCODERS-1) 0/*, 0*/});
  #define PHASE_ONE_FIRST_LINE (1+1*FH)
#endif

  int8_t sub = m_posVert;
  int8_t editMode = s_editMode;

#if defined(GVARS) && !defined(PCBSTD)
  if (s_currIdx == 0 && sub>=ITEM_MODEL_PHASE_SWITCH) sub += ITEM_MODEL_PHASE_FADE_IN-ITEM_MODEL_PHASE_SWITCH;

  for (uint8_t k=0; k<LCD_LINES-1; k++) {
    uint8_t y = 1 + (k+1)*FH;
    int8_t i = k + s_pgOfs;
    if (s_currIdx == 0 && i>=ITEM_MODEL_PHASE_SWITCH) i += ITEM_MODEL_PHASE_FADE_IN-ITEM_MODEL_PHASE_SWITCH;
    uint8_t attr = (sub==i ? (editMode>0 ? BLINK|INVERS : INVERS) : 0);
#else
  for (uint8_t i=0, k=0, y=PHASE_ONE_FIRST_LINE; i<ITEM_MODEL_PHASE_MAX; i++, k++, y+=FH) {
    if (s_currIdx == 0 && i==ITEM_MODEL_PHASE_SWITCH) i = ITEM_MODEL_PHASE_FADE_IN;
    uint8_t attr = (sub==k ? (editMode>0 ? BLINK|INVERS : INVERS) : 0);
#endif
    switch(i) {
      case ITEM_MODEL_PHASE_NAME:
        editSingleName(MIXES_2ND_COLUMN, y, STR_PHASENAME, fm->name, sizeof(fm->name), event, attr);
        break;
      case ITEM_MODEL_PHASE_SWITCH:
        fm->swtch = switchMenuItem(MIXES_2ND_COLUMN, y, fm->swtch, attr, event);
        break;
      case ITEM_MODEL_PHASE_TRIMS:
        lcd_putsLeft(y, STR_TRIMS);
        for (uint8_t t=0; t<NUM_STICKS; t++) {
          putsTrimMode(MIXES_2ND_COLUMN+(t*FW), y, s_currIdx, t, m_posHorz==t ? attr : 0);
          if (attr && m_posHorz==t && ((editMode>0) || p1valdiff)) {
            int16_t v = getRawTrimValue(s_currIdx, t);
            if (v < TRIM_EXTENDED_MAX) v = TRIM_EXTENDED_MAX;
            v = checkIncDec(event, v, TRIM_EXTENDED_MAX, TRIM_EXTENDED_MAX+MAX_FLIGHT_MODES-1, EE_MODEL);
            if (checkIncDec_Ret) {
              if (v == TRIM_EXTENDED_MAX) v = 0;
              setTrimValue(s_currIdx, t, v);
            }
          }
        }
        break;

#if ROTARY_ENCODERS > 0
      case ITEM_MODEL_PHASE_ROTARY_ENCODERS:
        lcd_putsLeft(y, STR_ROTARY_ENCODER);
        for (uint8_t t=0; t<NUM_ROTARY_ENCODERS; t++) {
          putsRotaryEncoderMode(MIXES_2ND_COLUMN+(t*FW), y, s_currIdx, t, m_posHorz==t ? attr : 0);
          if (attr && m_posHorz==t && ((editMode>0) || p1valdiff)) {
            int16_t v = flightModeAddress(s_currIdx)->rotaryEncoders[t];
            if (v < ROTARY_ENCODER_MAX) v = ROTARY_ENCODER_MAX;
            v = checkIncDec(event, v, ROTARY_ENCODER_MAX, ROTARY_ENCODER_MAX+MAX_FLIGHT_MODES-1, EE_MODEL);
            if (checkIncDec_Ret) {
              if (v == ROTARY_ENCODER_MAX) v = 0;
              flightModeAddress(s_currIdx)->rotaryEncoders[t] = v;
            }
          }
        }
        break;
#endif

      case ITEM_MODEL_PHASE_FADE_IN:
        fm->fadeIn = EDIT_DELAY(0, y, event, attr, STR_FADEIN, fm->fadeIn);
        break;

      case ITEM_MODEL_PHASE_FADE_OUT:
        fm->fadeOut = EDIT_DELAY(0, y, event, attr, STR_FADEOUT, fm->fadeOut);
        break;

#if defined(GVARS) && !defined(PCBSTD)
      case ITEM_MODEL_PHASE_GVARS_LABEL:
        lcd_putsLeft(y, STR_GLOBAL_VARS);
        break;

      default:
      {
        uint8_t idx = i-ITEM_MODEL_PHASE_GV1;
        uint8_t posHorz = m_posHorz;
        if (attr && posHorz > 0 && s_currIdx==0) posHorz++;

        putsStrIdx(INDENT_WIDTH, y, STR_GV, idx+1);

        editName(4*FW, y, g_model.gvars[idx].name, LEN_GVAR_NAME, event, posHorz==0 ? attr : 0);

        int16_t v = fm->gvars[idx];
        if (v > GVAR_MAX) {
          uint8_t p = v - GVAR_MAX - 1;
          if (p >= s_currIdx) p++;
          putsFlightMode(11*FW, y, p+1, posHorz==1 ? attr : 0);
        }
        else {
          lcd_putsAtt(11*FW, y, STR_OWN, posHorz==1 ? attr : 0);
        }
        if (attr && s_currIdx>0 && posHorz==1 && (editMode>0 || p1valdiff)) {
          if (v < GVAR_MAX) v = GVAR_MAX;
          v = checkIncDec(event, v, GVAR_MAX, GVAR_MAX+MAX_FLIGHT_MODES-1, EE_MODEL);
          if (checkIncDec_Ret) {
            if (v == GVAR_MAX) v = 0;
            fm->gvars[idx] = v;
          }
        }

        uint8_t p = getGVarFlightPhase(s_currIdx, idx);
        lcd_outdezAtt(21*FW, y, GVAR_VALUE(idx, p), posHorz==2 ? attr : 0);
        if (attr && posHorz==2 && ((editMode>0) || p1valdiff)) {
          GVAR_VALUE(idx, p) = checkIncDec(event, GVAR_VALUE(idx, p), -GVAR_LIMIT, GVAR_LIMIT, EE_MODEL);
        }

        break;
      }
#endif
    }
  }
}

#if defined(ROTARY_ENCODERS)
  #if ROTARY_ENCODERS > 2
    #define NAME_OFS (-4-12)
    #define SWITCH_OFS (-FW/2-2-13)
    #define TRIMS_OFS  (-FW/2-4-15)
    #define ROTARY_ENC_OFS (0)
  #else
    #define NAME_OFS (-4)
    #define SWITCH_OFS (-FW/2-2)
    #define TRIMS_OFS  (-FW/2-4)
    #define ROTARY_ENC_OFS (2)
  #endif
#else
  #define NAME_OFS 0
  #define SWITCH_OFS (FW/2)
  #define TRIMS_OFS  (FW/2)
#endif

void menuModelFlightModesAll(uint8_t event)
{
  SIMPLE_MENU(STR_MENUFLIGHTPHASES, menuTabModel, e_FlightModesAll, 1+MAX_FLIGHT_MODES+1);

  int8_t sub = m_posVert - 1;

  switch (event) {
    CASE_EVT_ROTARY_BREAK
    case EVT_KEY_FIRST(KEY_ENTER):
      if (sub == MAX_FLIGHT_MODES) {
        s_editMode = 0;
        trimsCheckTimer = 200; // 2 seconds
      }
      // no break
    case EVT_KEY_FIRST(KEY_RIGHT):
      if (sub >= 0 && sub < MAX_FLIGHT_MODES) {
        s_currIdx = sub;
        pushMenu(menuModelPhaseOne);
      }
      break;
  }

  uint8_t att;
  for (uint8_t i=0; i<MAX_FLIGHT_MODES; i++) {
#if defined(CPUARM)
    int8_t y = 1 + (1+i-s_pgOfs)*FH;
    if (y<1*FH+1 || y>(LCD_LINES-1)*FH+1) continue;
#else
    uint8_t y = 1 + (i+1)*FH;
#endif
    att = (i==sub ? INVERS : 0);
    FlightModeData *p = flightModeAddress(i);
    putsFlightMode(0, y, i+1, att|(getFlightMode()==i ? BOLD : 0));

    lcd_putsnAtt(4*FW+NAME_OFS, y, p->name, sizeof(p->name), ZCHAR);
    if (i == 0) {
      lcd_puts((5+LEN_FP_NAME)*FW+SWITCH_OFS, y, STR_DEFAULT);
    }
    else {
      putsSwitches((5+LEN_FP_NAME)*FW+SWITCH_OFS, y, p->swtch, 0);
      for (uint8_t t=0; t<NUM_STICKS; t++) {
        putsTrimMode((9+LEN_FP_NAME+t)*FW+TRIMS_OFS, y, i, t, 0);
      }
#if defined(PCBGRUVIN9X)
      for (uint8_t t=0; t<NUM_ROTARY_ENCODERS; t++) {
        putsRotaryEncoderMode((13+LEN_FP_NAME+t)*FW+TRIMS_OFS+ROTARY_ENC_OFS, y, i, t, 0);
      }
#endif
    }

    if (p->fadeIn || p->fadeOut) 
      lcd_putc(LCD_W-FW-MENUS_SCROLLBAR_WIDTH, y, (p->fadeIn && p->fadeOut) ? '*' : (p->fadeIn ? 'I' : 'O'));

  }

#if defined(CPUARM)
  if (s_pgOfs != MAX_FLIGHT_MODES-(LCD_LINES-2)) return;
#endif

  lcd_putsLeft((LCD_LINES-1)*FH+1, STR_CHECKTRIMS);
  putsFlightMode(OFS_CHECKTRIMS, (LCD_LINES-1)*FH+1, mixerCurrentFlightMode+1);
  if (sub==MAX_FLIGHT_MODES && !trimsCheckTimer) {
    lcd_status_line();
  }
}

#endif // defined(PCBTARANIS)

#else // defined(FLIGHT_MODES)

#define displayFlightModes(...)

#endif

#if defined(HELI)

enum menuModelHeliItems {
  ITEM_HELI_SWASHTYPE,
  ITEM_HELI_COLLECTIVE,
  ITEM_HELI_SWASHRING,
  ITEM_HELI_ELEDIRECTION,
  ITEM_HELI_AILDIRECTION,
  ITEM_HELI_COLDIRECTION
};

#if LCD_W >= 212
  #define HELI_PARAM_OFS (23*FW)
#else
  #define HELI_PARAM_OFS (14*FW)
#endif

void menuModelHeli(uint8_t event)
{
  SIMPLE_MENU(STR_MENUHELISETUP, menuTabModel, e_Heli, 7);

  uint8_t sub = m_posVert - 1;

  for (uint8_t i=0; i<6; i++) {
    uint8_t y = 1 + 1*FH + i*FH;
    uint8_t attr = (sub == i ? ((s_editMode>0) ? BLINK|INVERS : INVERS) : 0);
    switch(i) {
      case ITEM_HELI_SWASHTYPE:
        g_model.swashR.type = selectMenuItem(HELI_PARAM_OFS, y, STR_SWASHTYPE, STR_VSWASHTYPE, g_model.swashR.type, 0, SWASH_TYPE_MAX, attr, event);
        break;

      case ITEM_HELI_COLLECTIVE:
#if defined(PCBTARANIS)
        lcd_putsLeft(y, STR_COLLECTIVE);
        if (attr) CHECK_INCDEC_MODELSOURCE(event, g_model.swashR.collectiveSource, 0, MIXSRC_LAST_CH);
#else
        g_model.swashR.collectiveSource = selectMenuItem(HELI_PARAM_OFS, y, STR_COLLECTIVE, NULL, g_model.swashR.collectiveSource, 0, MIXSRC_LAST_CH, attr, event);
#endif
        putsMixerSource(HELI_PARAM_OFS, y, g_model.swashR.collectiveSource, attr);
        break;

      case ITEM_HELI_SWASHRING:
        lcd_putsLeft(y, STR_SWASHRING);
        lcd_outdezAtt(HELI_PARAM_OFS, y, g_model.swashR.value,  LEFT|attr);
        if (attr) CHECK_INCDEC_MODELVAR_ZERO(event, g_model.swashR.value, 100);
        break;

      case ITEM_HELI_ELEDIRECTION:
        g_model.swashR.invertELE = selectMenuItem(HELI_PARAM_OFS, y, STR_ELEDIRECTION, STR_MMMINV, g_model.swashR.invertELE, 0, 1, attr, event);
        break;

      case ITEM_HELI_AILDIRECTION:
        g_model.swashR.invertAIL = selectMenuItem(HELI_PARAM_OFS, y, STR_AILDIRECTION, STR_MMMINV, g_model.swashR.invertAIL, 0, 1, attr, event);
        break;

      case ITEM_HELI_COLDIRECTION:
        g_model.swashR.invertCOL = selectMenuItem(HELI_PARAM_OFS, y, STR_COLDIRECTION, STR_MMMINV, g_model.swashR.invertCOL, 0, 1, attr, event);
        break;
    }
  }
}
#endif

typedef int16_t (*FnFuncP) (int16_t x);

int16_t expoFn(int16_t x)
{
  ExpoData *ed = expoAddress(s_currIdx);
  int16_t anas[NUM_INPUTS] = {0};
#if defined(PCBTARANIS)
  applyExpos(anas, e_perout_mode_inactive_flight_mode, ed->srcRaw, x);
#else
  anas[ed->chn] = x;
  applyExpos(anas, e_perout_mode_inactive_flight_mode);
#endif
  return anas[ed->chn];
}

void DrawFunction(FnFuncP fn, uint8_t offset=0)
{
  lcd_vlineStip(X0-offset, 0, LCD_H, 0xee);
  lcd_hlineStip(X0-WCHART-offset, Y0, WCHART*2, 0xee);

  uint8_t prev_yv = 255;

  for (int8_t xv=-WCHART; xv<=WCHART; xv++) {
    uint8_t yv = (LCD_H-1) - (((uint16_t)RESX + fn(xv * (RESX/WCHART))) / 2 * (LCD_H-1) / RESX);
    if (prev_yv != 255) {
      if (abs((int8_t)yv-prev_yv) <= 1) {
        lcd_plot(X0+xv-offset-1, prev_yv, FORCE);
      }
      else {
        uint8_t tmp = (prev_yv < yv ? 0 : 1);
        lcd_vline(X0+xv-offset-1, yv+tmp, prev_yv-yv);
      }
    }
    prev_yv = yv;
  }
}

#if defined(CURVES)
static uint8_t s_curveChan;
int16_t curveFn(int16_t x)
{
  return applyCustomCurve(x, s_curveChan);
}

struct point_t {
  uint8_t x;
  uint8_t y;
};

point_t getPoint(uint8_t i)
{
  point_t result = {0, 0};
#if defined(PCBTARANIS)
  CurveInfo &crv = g_model.curves[s_curveChan];
  int8_t *points = curveAddress(s_curveChan);
  bool custom = (crv.type == CURVE_TYPE_CUSTOM);
  uint8_t count = 5+crv.points;
#else
  CurveInfo crv = curveInfo(s_curveChan);
  int8_t *points = crv.crv;
  bool custom = crv.custom;
  uint8_t count = crv.points;
#endif
  if (i < count) {
#if defined(PCBTARANIS)
    result.x = X0-1-WCHART+i*WCHART*2/(count-1);
#else
    result.x = X0-1-WCHART+i*WCHART/(count/2);
#endif
    result.y = (LCD_H-1) - (100 + points[i]) * (LCD_H-1) / 200;
    if (custom && i>0 && i<count-1)
      result.x = X0-1-WCHART + (100 + (100 + points[count+i-1]) * (2*WCHART)) / 200;
  }
  return result;
}

void DrawCurve(uint8_t offset=0)
{
  DrawFunction(curveFn, offset);

  uint8_t i = 0;
  do {
    point_t point = getPoint(i);
    i++;
    if (point.x == 0) break;
    lcd_filled_rect(point.x-offset, point.y-1, 3, 3, SOLID, FORCE); // do markup square
  } while(1);
}
#endif

#if defined(CURVES)
#if defined(PCBTARANIS)
extern int8_t * curveEnd[MAX_CURVES];
bool moveCurve(uint8_t index, int8_t shift)
{
  if (curveEnd[MAX_CURVES-1] + shift > g_model.points + sizeof(g_model.points)) {
    AUDIO_WARNING2();
    return false;
  }

  int8_t *nextCrv = curveAddress(index+1);
  memmove(nextCrv+shift, nextCrv, 5*(MAX_CURVES-index-1)+curveEnd[MAX_CURVES-1]-curveEnd[index]);
  if (shift < 0) memclear(&g_model.points[NUM_POINTS-1] + shift, -shift);
  while (index<MAX_CURVES) {
    curveEnd[index++] += shift;
  }

  eeDirty(EE_MODEL);
  return true;
}
#else
bool moveCurve(uint8_t index, int8_t shift, int8_t custom=0)
{
  if (g_model.curves[MAX_CURVES-1] + shift > NUM_POINTS-5*MAX_CURVES) {
    AUDIO_WARNING2();
    return false;
  }

  int8_t *crv = curveAddress(index);
  if (shift < 0) {
    for (uint8_t i=0; i<custom; i++)
      crv[i] = crv[2*i];
  }

  int8_t *nextCrv = curveAddress(index+1);
  memmove(nextCrv+shift, nextCrv, 5*(MAX_CURVES-index-1)+g_model.curves[MAX_CURVES-1]-g_model.curves[index]);
  if (shift < 0) memclear(&g_model.points[NUM_POINTS-1] + shift, -shift);
  while (index<MAX_CURVES)
    g_model.curves[index++] += shift;

  for (uint8_t i=0; i<custom-2; i++)
    crv[custom+i] = -100 + ((200 * (i+1) + custom/2) / (custom-1)) ;

  eeDirty(EE_MODEL);
  return true;
}
#endif

#if defined(PCBTARANIS)
void displayPresetChoice(uint8_t event)
{
  displayWarning(event);
  lcd_outdezAtt(WARNING_LINE_X+FW*7, WARNING_LINE_Y, 45*s_warning_input_value/4, LEFT|INVERS);
  lcd_putcAtt(lcdLastPos, WARNING_LINE_Y, '@', INVERS);

  if (s_warning_result) {
    s_warning_result = 0;
    CurveInfo & crv = g_model.curves[s_curveChan];
    int8_t * points = curveAddress(s_curveChan);
    for (uint8_t i=0; i<5+crv.points; i++)
      points[i] = (i-((5+crv.points)/2)) * s_warning_input_value * 50 / (4+crv.points);
    if (crv.type == CURVE_TYPE_CUSTOM) {
      for (int i=0; i<3+crv.points; i++)
        points[crv.points+i] = -100 + ((i+1)*200) / (4+crv.points);
    }
  }
}

void onCurveOneMenu(const char *result)
{
  if (result == STR_CURVE_PRESET) {
    POPUP_INPUT(STR_PRESET, displayPresetChoice, 0, -4, 4);
  }
  else if (result == STR_MIRROR) {
    CurveInfo & crv = g_model.curves[s_curveChan];
    int8_t * points = curveAddress(s_curveChan);
    for (int i=0; i<5+crv.points; i++)
      points[i] = -points[i];
  }
  else if (result == STR_CLEAR) {
    CurveInfo & crv = g_model.curves[s_curveChan];
    int8_t * points = curveAddress(s_curveChan);
    for (int i=0; i<5+crv.points; i++)
      points[i] = 0;
    if (crv.type == CURVE_TYPE_CUSTOM) {
      for (int i=0; i<3+crv.points; i++)
        points[crv.points+i] = -100 + ((i+1)*200) / (4+crv.points);
    }
  }
}

void menuModelCurveOne(uint8_t event)
{
  static uint8_t pointsOfs = 0;
  CurveInfo & crv = g_model.curves[s_curveChan];
  int8_t * points = curveAddress(s_curveChan);

  lcd_puts(9*FW, 0, TR_PT "\003X\006Y");
  lcd_filled_rect(0, 0, LCD_W, FH, SOLID, FILL_WHITE|GREY_DEFAULT);

  SIMPLE_SUBMENU(STR_MENUCURVE, 4 + 5+crv.points + (crv.type==CURVE_TYPE_CUSTOM ? 5+crv.points-2 : 0));
  lcd_outdezAtt(PSIZE(TR_MENUCURVE)*FW+1, 0, s_curveChan+1, INVERS|LEFT);

  lcd_putsLeft(FH+1, STR_NAME);
  editName(INDENT_WIDTH, 2*FH+1, g_model.curveNames[s_curveChan], sizeof(g_model.curveNames[s_curveChan]), event, m_posVert==0);

  uint8_t attr = (m_posVert==1 ? (s_editMode>0 ? INVERS|BLINK : INVERS) : 0);
  lcd_putsLeft(3*FH+1, STR_TYPE);
  lcd_putsiAtt(INDENT_WIDTH, 4*FH+1, STR_CURVE_TYPES, crv.type, attr);
  if (attr) {
    uint8_t newType = checkIncDecModelZero(event, crv.type, CURVE_TYPE_LAST);
    if (newType != crv.type) {
      for (int i=1; i<4+crv.points; i++)
        points[i] = calcRESXto100(applyCustomCurve(calc100toRESX(-100 + i*200/(4+crv.points)), s_curveChan));
      moveCurve(s_curveChan, checkIncDec_Ret > 0 ? 3+crv.points : -3-crv.points);
      if (newType == CURVE_TYPE_CUSTOM) {
        for (int i=0; i<3+crv.points; i++)
          points[5+crv.points+i] = -100 + ((i+1)*200) / (4+crv.points);
      }
      crv.type = newType;
    }
  }

  attr = (m_posVert==2 ? (s_editMode>0 ? INVERS|BLINK : INVERS) : 0);
  lcd_putsLeft(5*FH+1, STR_COUNT);
  lcd_outdezAtt(INDENT_WIDTH, 6*FH+1, 5+crv.points, LEFT|attr);
  lcd_putsAtt(lcdLastPos, 6*FH+1, STR_PTS, attr);
  if (attr) {
    int8_t count = checkIncDecModel(event, crv.points, -3, 12); // 2pts - 17pts
    if (checkIncDec_Ret) {
      int8_t newPoints[MAX_POINTS];
      newPoints[0] = points[0];
      newPoints[4+count] = points[4+crv.points];
      for (int i=1; i<4+count; i++)
        newPoints[i] = calcRESXto100(applyCustomCurve(calc100toRESX(-100 + (i*200) / (4+count)), s_curveChan));
      moveCurve(s_curveChan, checkIncDec_Ret*(crv.type==CURVE_TYPE_CUSTOM?2:1));
      for (int i=0; i<5+count; i++) {
        points[i] = newPoints[i];
        if (crv.type == CURVE_TYPE_CUSTOM && i!=0 && i!=4+count)
          points[5+count+i-1] = -100 + (i*200) / (4+count);
      }
      crv.points = count;
    }
  }

  lcd_putsLeft(7*FH+1, STR_SMOOTH);
  menu_lcd_onoff(7*FW, 7*FH+1, crv.smooth, m_posVert==3 ? INVERS : 0);
  if (m_posVert==3) crv.smooth = checkIncDecModel(event, crv.smooth, 0, 1);

  switch(event) {
    case EVT_ENTRY:
      pointsOfs = 0;
      SET_SCROLLBAR_X(0);
      break;
    case EVT_KEY_LONG(KEY_ENTER):
      if (m_posVert > 1) {
        killEvents(event);
        MENU_ADD_ITEM(STR_CURVE_PRESET);
        MENU_ADD_ITEM(STR_MIRROR);
        MENU_ADD_ITEM(STR_CLEAR);
        menuHandler = onCurveOneMenu;
      }
      break;
    case EVT_KEY_LONG(KEY_MENU):
      pushMenu(menuChannelsView);
      killEvents(event);
      return;
  }

  DrawCurve(FW);

  uint8_t posY = FH+1;
  attr = (s_editMode > 0 ? INVERS|BLINK : INVERS);
  for (uint8_t i=0; i<5+crv.points; i++) {
    point_t point = getPoint(i);
    uint8_t selectionMode = 0;
    if (crv.type==CURVE_TYPE_CUSTOM) {
      if (m_posVert==4+2*i || (i==5+crv.points-1 && m_posVert==4+5+crv.points+5+crv.points-2-1))
        selectionMode = 2;
      else if (i>0 && m_posVert==3+2*i)
        selectionMode = 1;
    }
    else if (m_posVert == 4+i) {
      selectionMode = 2;
    }

    if (i>=pointsOfs && i<pointsOfs+7) {
      int8_t x = -100 + 200*i/(5+crv.points-1);
      if (crv.type==CURVE_TYPE_CUSTOM && i>0 && i<5+crv.points-1) x = points[5+crv.points+i-1];
      lcd_outdezAtt(6+8*FW,  posY, i+1, LEFT);
      lcd_outdezAtt(3+12*FW, posY, x, LEFT|(selectionMode==1?attr:0));
      lcd_outdezAtt(3+16*FW, posY, points[i], LEFT|(selectionMode==2?attr:0));
      posY += FH;
    }

    if (selectionMode > 0) {
      // do selection square
      lcd_filled_rect(point.x-FW-1, point.y-2, 5, 5, SOLID, FORCE);
      lcd_filled_rect(point.x-FW, point.y-1, 3, 3, SOLID);
      if (s_editMode > 0) {
        if (selectionMode == 1)
          CHECK_INCDEC_MODELVAR(event, points[5+crv.points+i-1], i==1 ? -100 : points[5+crv.points+i-2], i==5+crv.points-2 ? 100 : points[5+crv.points+i]);  // edit X
        else if (selectionMode == 2)
          CHECK_INCDEC_MODELVAR(event, points[i], -100, 100);
      }
      if (i < pointsOfs)
        pointsOfs = i;
      else if (i > pointsOfs+6)
        pointsOfs = i-6;
    }
  }
}
#else
void menuModelCurveOne(uint8_t event)
{
  TITLE(STR_MENUCURVE);
  lcd_outdezAtt(PSIZE(TR_MENUCURVE)*FW+1, 0, s_curveChan+1, INVERS|LEFT);
  DISPLAY_PROGRESS_BAR(20*FW+1);

  CurveInfo crv = curveInfo(s_curveChan);

  switch(event) {
    case EVT_ENTRY:
      s_editMode = 1;
      break;
    CASE_EVT_ROTARY_BREAK
    case EVT_KEY_BREAK(KEY_ENTER):
      if (s_editMode <= 0)
        m_posHorz = 0;
      if (s_editMode == 1 && crv.custom)
        s_editMode = 2;
      else
        s_editMode = 1;
      break;
    case EVT_KEY_LONG(KEY_ENTER):
      if (s_editMode <= 0) {
        if (int8_t(++m_posHorz) > 4)
          m_posHorz = -4;
        for (uint8_t i=0; i<crv.points; i++)
          crv.crv[i] = (i-(crv.points/2)) * int8_t(m_posHorz) * 50 / (crv.points-1);
        eeDirty(EE_MODEL);
        killEvents(event);
      }
      break;
    case EVT_KEY_BREAK(KEY_EXIT):
      if (s_editMode > 0) {
        if (--s_editMode == 0)
          m_posHorz = 0;
      }
      else {
        popMenu();
      }
      break;

    /* CASE_EVT_ROTARY_LEFT */
    case EVT_KEY_REPT(KEY_LEFT):
    case EVT_KEY_FIRST(KEY_LEFT):
      if (s_editMode==1 && m_posHorz>0) m_posHorz--;
      if (s_editMode <= 0) {
        if (crv.custom) {
          moveCurve(s_curveChan, -crv.points+2);
        }
        else if (crv.points > MIN_POINTS) {
          moveCurve(s_curveChan, -1, (crv.points+1)/2);
        }
        else {
          AUDIO_WARNING2();
        }
        return;
      }
      break;

    /* CASE_EVT_ROTARY_RIGHT */
    case EVT_KEY_REPT(KEY_RIGHT):
    case EVT_KEY_FIRST(KEY_RIGHT):
      if (s_editMode==1 && m_posHorz<(crv.points-1)) m_posHorz++;
      if (s_editMode <= 0) {
        if (!crv.custom) {
          moveCurve(s_curveChan, crv.points-2, crv.points);
        }
        else if (crv.points < MAX_POINTS) {
          if (moveCurve(s_curveChan, 1)) {
            for (int8_t i=crv.points+crv.points-2; i>=0; i--) {
              if (i%2)
                crv.crv[i] = (crv.crv[i/2] + crv.crv[1+i/2]) / 2;
              else
                crv.crv[i] = crv.crv[i/2];
            }
          }
        }
        else {
          AUDIO_WARNING2();
        }
      }
      break;
  }

  lcd_putsLeft(7*FH, STR_TYPE);
  uint8_t attr = (s_editMode <= 0 ? INVERS : 0);
  lcd_outdezAtt(5*FW-2, 7*FH, crv.points, LEFT|attr);
  lcd_putsAtt(lcdLastPos, 7*FH, crv.custom ? PSTR("pt'") : PSTR("pt"), attr);

  DrawCurve();

  if (s_editMode>0) {
    uint8_t i = m_posHorz;
    point_t point = getPoint(i);

    if (s_editMode==1 || !BLINK_ON_PHASE) {
      // do selection square
      lcd_filled_rect(point.x-1, point.y-2, 5, 5, SOLID, FORCE);
      lcd_filled_rect(point.x, point.y-1, 3, 3, SOLID);
    }

    int8_t x = -100 + 200*i/(crv.points-1);
    if (crv.custom && i>0 && i<crv.points-1) x = crv.crv[crv.points+i-1];
    lcd_puts(7, 2*FH, PSTR("x=")); lcd_outdezAtt(7+2*FW, 2*FH, x, LEFT);
    lcd_puts(7, 3*FH, PSTR("y=")); lcd_outdezAtt(7+2*FW, 3*FH, crv.crv[i], LEFT);
    lcd_rect(3, 1*FH+4, 7*FW-2, 3*FH-2);

    if (p1valdiff || event==EVT_KEY_FIRST(KEY_DOWN) || event==EVT_KEY_FIRST(KEY_UP) || event==EVT_KEY_REPT(KEY_DOWN) || event==EVT_KEY_REPT(KEY_UP))
      CHECK_INCDEC_MODELVAR(event, crv.crv[i], -100, 100);  // edit Y on up/down

    if (i>0 && i<crv.points-1 && s_editMode==2 && (event==EVT_KEY_FIRST(KEY_LEFT) || event==EVT_KEY_FIRST(KEY_RIGHT) || event==EVT_KEY_REPT(KEY_LEFT) || event==EVT_KEY_REPT(KEY_RIGHT)))
      CHECK_INCDEC_MODELVAR(event, crv.crv[crv.points+i-1], i==1 ? -99 : crv.crv[crv.points+i-2]+1, i==crv.points-2 ? 99 : crv.crv[crv.points+i]-1);  // edit X on left/right
  }
}
#endif
#endif

#if defined(PCBTARANIS) && defined(CURVES)
void editCurveRef(uint8_t x, uint8_t y, CurveRef & curve, uint8_t event, uint8_t attr)
{
  lcd_putsiAtt(x, y, "\004DiffExpoFuncCstm", curve.type, m_posHorz==0 ? attr : 0);
  if (attr && m_posHorz==0) {
    CHECK_INCDEC_MODELVAR_ZERO(event, curve.type, CURVE_REF_CUSTOM);
    if (checkIncDec_Ret) curve.value = 0;
  }
  switch (curve.type) {
    case CURVE_REF_DIFF:
    case CURVE_REF_EXPO:
      curve.value = GVAR_MENU_ITEM(x+5*FW, y, curve.value, -100, 100, m_posHorz==1 ? LEFT|attr : LEFT, 0, event);
      break;
    case CURVE_REF_FUNC:
      lcd_putsiAtt(x+5*FW, y, STR_VCURVEFUNC, curve.value, m_posHorz==1 ? attr : 0);
      if (attr && m_posHorz==1) CHECK_INCDEC_MODELVAR_ZERO(event, curve.value, CURVE_BASE-1);
      break;
    case CURVE_REF_CUSTOM:
      putsCurve(x+5*FW+2, y, curve.value, m_posHorz==1 ? attr : 0);
      if (attr && m_posHorz==1) {
        if (event==EVT_KEY_LONG(KEY_ENTER) && curve.value!=0) {
          s_curveChan = (curve.value<0 ? -curve.value-1 : curve.value-1);
          pushMenu(menuModelCurveOne);
        }
        else {
          CHECK_INCDEC_MODELVAR(event, curve.value, -MAX_CURVES, MAX_CURVES);
        }
      }
      break;
  }
}
#endif

uint8_t getExpoMixCount(uint8_t expo)
{
  uint8_t count = 0;
  uint8_t ch ;

  for(int8_t i=(expo ? MAX_EXPOS-1 : MAX_MIXERS-1); i>=0; i--) {
    ch = (expo ? EXPO_VALID(expoAddress(i)) : mixAddress(i)->srcRaw);
    if (ch != 0) {
      count++;
    }
  }
  return count;
}

bool reachExpoMixCountLimit(uint8_t expo)
{
  // check mixers count limit
  if (getExpoMixCount(expo) >= (expo ? MAX_EXPOS : MAX_MIXERS)) {
    POPUP_WARNING(expo ? STR_NOFREEEXPO : STR_NOFREEMIXER);
    return true;
  }
  return false;
}

void deleteExpoMix(uint8_t expo, uint8_t idx)
{
  pauseMixerCalculations();
  if (expo) {
    ExpoData *expo = expoAddress(idx);
#if defined(PCBTARANIS)
    int input = expo->chn;
#endif
    memmove(expo, expo+1, (MAX_EXPOS-(idx+1))*sizeof(ExpoData));
    memclear(&g_model.expoData[MAX_EXPOS-1], sizeof(ExpoData));
#if defined(PCBTARANIS)
    if (!isInputAvailable(input)) {
      memclear(&g_model.inputNames[input], LEN_INPUT_NAME);
    }
#endif
  }
  else {
    MixData *mix = mixAddress(idx);
    memmove(mix, mix+1, (MAX_MIXERS-(idx+1))*sizeof(MixData));
    memclear(&g_model.mixData[MAX_MIXERS-1], sizeof(MixData));
  }
  resumeMixerCalculations();
  eeDirty(EE_MODEL);
}

// TODO avoid this global s_currCh on ARM boards ...
int8_t s_currCh;
void insertExpoMix(uint8_t expo, uint8_t idx)
{
  pauseMixerCalculations();
  if (expo) {
    ExpoData *expo = expoAddress(idx);
    memmove(expo+1, expo, (MAX_EXPOS-(idx+1))*sizeof(ExpoData));
    memclear(expo, sizeof(ExpoData));
#if defined(PCBTARANIS)
    expo->srcRaw = (s_currCh > 4 ? MIXSRC_Rud - 1 + s_currCh : MIXSRC_Rud - 1 + channel_order(s_currCh));
    expo->curve.type = CURVE_REF_EXPO;
#endif
    expo->mode = 3; // pos&neg
    expo->chn = s_currCh - 1;
    expo->weight = 100;
  }
  else {
    MixData *mix = mixAddress(idx);
    memmove(mix+1, mix, (MAX_MIXERS-(idx+1))*sizeof(MixData));
    memclear(mix, sizeof(MixData));
    mix->destCh = s_currCh-1;
#if defined(PCBTARANIS)
    mix->srcRaw = s_currCh;
    if (!isSourceAvailable(mix->srcRaw))
      mix->srcRaw = (s_currCh > 4 ? MIXSRC_Rud - 1 + s_currCh : MIXSRC_Rud - 1 + channel_order(s_currCh));
#else
    mix->srcRaw = (s_currCh > 4 ? MIXSRC_Rud - 1 + s_currCh : MIXSRC_Rud - 1 + channel_order(s_currCh));
#endif
    mix->weight = 100;
  }
  resumeMixerCalculations();
  eeDirty(EE_MODEL);
}

void copyExpoMix(uint8_t expo, uint8_t idx)
{
  pauseMixerCalculations();
  if (expo) {
    ExpoData *expo = expoAddress(idx);
    memmove(expo+1, expo, (MAX_EXPOS-(idx+1))*sizeof(ExpoData));
  }
  else {
    MixData *mix = mixAddress(idx);
    memmove(mix+1, mix, (MAX_MIXERS-(idx+1))*sizeof(MixData));
  }
  resumeMixerCalculations();
  eeDirty(EE_MODEL);
}

void memswap(void *a, void *b, uint8_t size)
{
  uint8_t *x = (uint8_t*)a;
  uint8_t *y = (uint8_t*)b;
  uint8_t temp ;

  while (size--) {
    temp = *x;
    *x++ = *y;
    *y++ = temp;
  }
}

bool swapExpoMix(uint8_t expo, uint8_t &idx, uint8_t up)
{
  void *x, *y;
  uint8_t size;
  int8_t tgt_idx = (up ? idx-1 : idx+1);

  if (expo) {
    x = (ExpoData *)expoAddress(idx);

    if (tgt_idx < 0) {
      if (((ExpoData *)x)->chn == 0)
        return false;
      ((ExpoData *)x)->chn--;
      return true;
    }

    if (tgt_idx == MAX_EXPOS) {
      if (((ExpoData *)x)->chn == NUM_INPUTS-1)
        return false;
      ((ExpoData *)x)->chn++;
      return true;
    }

    y = (ExpoData *)expoAddress(tgt_idx);
    if(((ExpoData *)x)->chn != ((ExpoData *)y)->chn || !EXPO_VALID((ExpoData *)y)) {
      if (up) {
        if (((ExpoData *)x)->chn>0) ((ExpoData *)x)->chn--;
        else return false;
      }
      else {
        if (((ExpoData *)x)->chn<NUM_INPUTS-1) ((ExpoData *)x)->chn++;
        else return false;
      }
      return true;
    }

    size = sizeof(ExpoData);
  }
  else {
    x = (MixData *)mixAddress(idx);

    if (tgt_idx < 0) {
      if (((MixData *)x)->destCh == 0)
        return false;
      ((MixData *)x)->destCh--;
      return true;
    }

    if (tgt_idx == MAX_MIXERS) {
      if (((MixData *)x)->destCh == NUM_CHNOUT-1)
        return false;
      ((MixData *)x)->destCh++;
      return true;
    }

    y = (MixData *)mixAddress(tgt_idx);
    uint8_t destCh = ((MixData *)x)->destCh;
    if(!((MixData *)y)->srcRaw || destCh != ((MixData *)y)->destCh) {
      if (up) {
        if (destCh>0) ((MixData *)x)->destCh--;
        else return false;
      }
      else {
        if (destCh<NUM_CHNOUT-1) ((MixData *)x)->destCh++;
        else return false;
      }
      return true;
    }

    size = sizeof(MixData);
  }

  pauseMixerCalculations();
  memswap(x, y, size);
  resumeMixerCalculations();

  idx = tgt_idx;
  return true;
}

enum ExposFields {
  CASE_PCBTARANIS(EXPO_FIELD_INPUT_NAME)
  CASE_CPUARM(EXPO_FIELD_NAME)
  CASE_PCBTARANIS(EXPO_FIELD_SOURCE)
  CASE_PCBTARANIS(EXPO_FIELD_SCALE)
  EXPO_FIELD_WEIGHT,
  CASE_PCBTARANIS(EXPO_FIELD_OFFSET)
  CASE_9X(EXPO_FIELD_EXPO)
  CASE_CURVES(EXPO_FIELD_CURVE)
  CASE_FLIGHT_MODES(EXPO_FIELD_FLIGHT_PHASE)
  EXPO_FIELD_SWITCH,
  EXPO_FIELD_SIDE,
  CASE_PCBTARANIS(EXPO_FIELD_TRIM)
  EXPO_FIELD_MAX
};

#if defined(PCBTARANIS)
  #define CURVE_ROWS 1
#else
  #define CURVE_ROWS 0
#endif

void menuModelExpoOne(uint8_t event)
{
#if defined(PCBTARANIS)
  if (event == EVT_KEY_LONG(KEY_MENU)) {
    pushMenu(menuChannelsView);
    killEvents(event);
    return;
  }
#endif

  ExpoData *ed = expoAddress(s_currIdx);
#if defined(PCBTARANIS)
  putsMixerSource(7*FW+FW/2, 0, MIXSRC_FIRST_INPUT+ed->chn, 0);
#else
  putsMixerSource(7*FW+FW/2, 0, MIXSRC_Rud+ed->chn, 0);
#endif

  SUBMENU(STR_MENUINPUTS, EXPO_FIELD_MAX, {CASE_PCBTARANIS(0) CASE_CPUARM(0) CASE_PCBTARANIS(0) CASE_PCBTARANIS((ed->srcRaw >= MIXSRC_FIRST_TELEM ? (uint8_t)0 : (uint8_t)HIDDEN_ROW)) 0, CASE_PCBTARANIS(0) CASE_9X(0) CASE_CURVES(CURVE_ROWS) CASE_FLIGHT_MODES((MAX_FLIGHT_MODES-1) | NAVIGATION_LINE_BY_LINE) 0 /*, ...*/});

  SET_SCROLLBAR_X(EXPO_ONE_2ND_COLUMN+10*FW);

  int8_t sub = m_posVert;

  uint8_t y = FH+1;

#if defined(PCBTARANIS)
  for (uint8_t k=0; k<LCD_LINES-1; k++) {
    int8_t i = k + s_pgOfs;
    for (int j=0; j<=i; j++) {
      if (mstate_tab[j] == HIDDEN_ROW)
        i++;
    }
#else
  for (uint8_t i=0; i<EXPO_FIELD_MAX+1; i++) {
#endif
    uint8_t attr = (sub==i ? (s_editMode>0 ? BLINK|INVERS : INVERS) : 0);
    switch(i)
    {
#if defined(PCBTARANIS)
      case EXPO_FIELD_INPUT_NAME:
        editSingleName(EXPO_ONE_2ND_COLUMN, y, STR_INPUTNAME, g_model.inputNames[ed->chn], sizeof(g_model.inputNames[ed->chn]), event, attr);
        break;
#endif

#if defined(CPUARM)
      case EXPO_FIELD_NAME:
        editSingleName(EXPO_ONE_2ND_COLUMN-IF_9X(sizeof(ed->name)*FW), y, STR_EXPONAME, ed->name, sizeof(ed->name), event, attr);
        break;
#endif

#if defined(PCBTARANIS)
      case EXPO_FIELD_SOURCE:
        lcd_putsLeft(y, NO_INDENT(STR_SOURCE));
        putsMixerSource(EXPO_ONE_2ND_COLUMN, y, ed->srcRaw, STREXPANDED|attr);
        if (attr) ed->srcRaw = checkIncDec(event, ed->srcRaw, INPUTSRC_FIRST, INPUTSRC_LAST, EE_MODEL|INCDEC_SOURCE|NO_INCDEC_MARKS, isInputSourceAvailable);
        break;

      case EXPO_FIELD_SCALE:
        lcd_putsLeft(y, STR_SCALE);
        putsTelemetryChannel(EXPO_ONE_2ND_COLUMN, y, ed->srcRaw - MIXSRC_FIRST_TELEM, convertTelemValue(ed->srcRaw - MIXSRC_FIRST_TELEM + 1, ed->scale), LEFT|attr);
        if (attr) ed->scale = checkIncDec(event, ed->scale, 0, maxTelemValue(ed->srcRaw - MIXSRC_FIRST_TELEM + 1), EE_MODEL);
        break;
#endif

      case EXPO_FIELD_WEIGHT:
        lcd_putsLeft(y, STR_WEIGHT);
        ed->weight = GVAR_MENU_ITEM(EXPO_ONE_2ND_COLUMN, y, ed->weight, MIN_EXPO_WEIGHT, 100, IF_PCBTARANIS(LEFT)|attr, 0, event);
        break;

#if defined(PCBTARANIS)
      case EXPO_FIELD_OFFSET:
        lcd_putsLeft(y, NO_INDENT(STR_OFFSET));
        ed->offset = GVAR_MENU_ITEM(EXPO_ONE_2ND_COLUMN, y, ed->offset, -100, 100, LEFT|attr, 0, event);
        break;
#endif

#if !defined(PCBTARANIS)
      case EXPO_FIELD_EXPO:
        lcd_putsLeft(y, STR_EXPO);
        if (ed->curveMode==MODE_EXPO || ed->curveParam==0) {
          ed->curveMode = MODE_EXPO;
          ed->curveParam = GVAR_MENU_ITEM(EXPO_ONE_2ND_COLUMN, y, ed->curveParam, -100, 100, attr, 0, event);
        }
        else {
          lcd_putsAtt(EXPO_ONE_2ND_COLUMN-3*FW, y, STR_NA, attr);
        }
        break;
#endif

#if defined(CURVES)
      case EXPO_FIELD_CURVE:
        lcd_putsLeft(y, STR_CURVE);
#if defined(PCBTARANIS)
        editCurveRef(EXPO_ONE_2ND_COLUMN, y, ed->curve, event, attr);
#else
        if (ed->curveMode!=MODE_EXPO || ed->curveParam==0) {
          putsCurve(EXPO_ONE_2ND_COLUMN-3*FW, y, ed->curveParam, attr);
          if (attr) {
            CHECK_INCDEC_MODELVAR_ZERO(event, ed->curveParam, CURVE_BASE+MAX_CURVES-1);
            if (ed->curveParam) ed->curveMode = MODE_CURVE;
            if (ed->curveParam>=CURVE_BASE && event==EVT_KEY_LONG(KEY_ENTER)) {
              s_curveChan = ed->curveParam - CURVE_BASE;
              pushMenu(menuModelCurveOne);
            }
          }
        }
        else {
          lcd_putsAtt(EXPO_ONE_2ND_COLUMN-3*FW, y, STR_NA, attr);
        }
#endif
        break;
#endif

#if defined(FLIGHT_MODES)
      case EXPO_FIELD_FLIGHT_PHASE:
        ed->flightModes = editFlightModes(EXPO_ONE_2ND_COLUMN-IF_9X(EXPO_ONE_FP_WIDTH), y, event, ed->flightModes, attr);
        break;
#endif

      case EXPO_FIELD_SWITCH:
        ed->swtch = switchMenuItem(EXPO_ONE_2ND_COLUMN-IF_9X(3*FW), y, ed->swtch, attr, event);
        break;

      case EXPO_FIELD_SIDE:
        ed->mode = 4 - selectMenuItem(EXPO_ONE_2ND_COLUMN-IF_9X(3*FW), y, STR_SIDE, STR_VSIDE, 4-ed->mode, 1, 3, attr, event);
        break;

#if defined(PCBTARANIS)
      case EXPO_FIELD_TRIM:
        uint8_t not_stick = (ed->srcRaw > MIXSRC_Ail);
        int8_t carryTrim = -ed->carryTrim;
        lcd_putsLeft(y, STR_TRIM);
        lcd_putsiAtt(EXPO_ONE_2ND_COLUMN, y, STR_VMIXTRIMS, (not_stick && carryTrim == 0) ? 0 : carryTrim+1, m_posHorz==0 ? attr : 0);
        if (attr) ed->carryTrim = -checkIncDecModel(event, carryTrim, not_stick ? TRIM_ON : -TRIM_OFF, -TRIM_AIL);
        break;
#endif
    }
    y += FH;
  }

  DrawFunction(expoFn);

#if defined(PCBTARANIS)
  int x512 = getValue(ed->srcRaw);
  if (ed->srcRaw >= MIXSRC_FIRST_TELEM) {
    putsTelemetryChannel(LCD_W-8, 6*FH, ed->srcRaw - MIXSRC_FIRST_TELEM, x512, 0);
    if (ed->scale > 0) x512 = (x512 * 1024) / convertTelemValue(ed->srcRaw - MIXSRC_FIRST_TELEM + 1, ed->scale);
  }
  else {
    lcd_outdezAtt(LCD_W-8, 6*FH, calcRESXto1000(x512), PREC1);
  }
  x512 = limit(-1024, x512, 1024);
  int y512 = expoFn(x512);
  y512 = limit(-1024, y512, 1024);
  lcd_outdezAtt(LCD_W-8-6*FW, 1*FH, calcRESXto1000(y512), PREC1);
#else
  int16_t x512 = calibratedStick[ed->chn];
  lcd_outdezAtt(LCD_W-8, 6*FH, calcRESXto100(x512), 0);
  int16_t y512 = expoFn(x512);
  lcd_outdezAtt(LCD_W-8-6*FW, 1*FH, calcRESXto100(y512), 0);
#endif

#if defined(CPUARM)
  x512 = X0+x512/(RESX/WCHART);
  y512 = (LCD_H-1) - ((y512+RESX)/2) * (LCD_H-1) / RESX;
#else
  x512 = X0+x512/(RESXu/WCHART);
  y512 = (LCD_H-1) - (uint16_t)((y512+RESX)/2) * (LCD_H-1) / RESX;
#endif

  lcd_vline(x512, y512-3, 3*2+1);
  lcd_hline(x512-3, y512, 3*2+1);
}

enum MixFields {
  CASE_CPUARM(MIX_FIELD_NAME)
  MIX_FIELD_SOURCE,
  MIX_FIELD_WEIGHT,
  MIX_FIELD_OFFSET,
  MIX_FIELD_TRIM,
  CASE_CURVES(MIX_FIELD_CURVE)
  CASE_FLIGHT_MODES(MIX_FIELD_FLIGHT_PHASE)
  MIX_FIELD_SWITCH,
  MIX_FIELD_WARNING,
  MIX_FIELD_MLTPX,
  MIX_FIELD_DELAY_UP,
  MIX_FIELD_DELAY_DOWN,
  MIX_FIELD_SLOW_UP,
  MIX_FIELD_SLOW_DOWN,
  MIX_FIELD_COUNT
};

void gvarWeightItem(xcoord_t x, uint8_t y, MixData *md, uint8_t attr, uint8_t event)
{
  u_int8int16_t weight;
  MD_WEIGHT_TO_UNION(md, weight);
  weight.word = GVAR_MENU_ITEM(x, y, weight.word, GV_RANGELARGE_WEIGHT_NEG, GV_RANGELARGE_WEIGHT, attr, 0, event);
  MD_UNION_TO_WEIGHT(weight, md);
}

void menuModelMixOne(uint8_t event)
{
#if defined(PCBTARANIS)
  if (event == EVT_KEY_LONG(KEY_MENU)) {
    pushMenu(menuChannelsView);
    killEvents(event);
    return;
  }
#endif

  TITLE(s_currCh ? STR_INSERTMIX : STR_EDITMIX);
  MixData *md2 = mixAddress(s_currIdx) ;
  putsChn(lcdLastPos+1*FW, 0, md2->destCh+1,0);

#if defined(ROTARY_ENCODERS)
#if defined(CURVES)
  if ((m_posVert == MIX_FIELD_TRIM && md2->srcRaw > NUM_STICKS) || (m_posVert == MIX_FIELD_CURVE && md2->curveMode == MODE_CURVE))
#else
  if (m_posVert == MIX_FIELD_TRIM && md2->srcRaw > NUM_STICKS)
#endif  
    SUBMENU_NOTITLE(MIX_FIELD_COUNT, {CASE_CPUARM(0) 0, 0, 0, CASE_9X(0) CASE_CURVES(0) CASE_FLIGHT_MODES((MAX_FLIGHT_MODES-1) | NAVIGATION_LINE_BY_LINE) 0, 0 /*, ...*/})
  else
    SUBMENU_NOTITLE(MIX_FIELD_COUNT, {CASE_CPUARM(0) 0, 0, 0, CASE_9X(1) CASE_CURVES(1) CASE_FLIGHT_MODES((MAX_FLIGHT_MODES-1) | NAVIGATION_LINE_BY_LINE) 0, 0 /*, ...*/});
#else
  SUBMENU_NOTITLE(MIX_FIELD_COUNT, {CASE_CPUARM(0) 0, 0, 0, CASE_9X(1) CASE_PCBTARANIS(0) CASE_CURVES(1) CASE_FLIGHT_MODES((MAX_FLIGHT_MODES-1) | NAVIGATION_LINE_BY_LINE) 0, 0 /*, ...*/});
#endif

#if MENU_COLUMNS > 1
  lcd_vline(MENU_COLUMN2_X-4, FH+1, LCD_H-FH-1);
#endif

  int8_t sub = m_posVert;
  int8_t editMode = s_editMode;

  for (uint8_t k=0; k<MENU_COLUMNS*(LCD_LINES-1); k++) {

#if MENU_COLUMNS > 1
    uint8_t y;
    uint8_t COLUMN_X;
    if (k >= LCD_LINES-1) {
      y = 1 + (k-LCD_LINES+2)*FH;
      COLUMN_X = MENU_COLUMN2_X;
    }
    else {
      y = 1 + (k+1)*FH;
      COLUMN_X = 0;
    }
    int8_t i = k;
#else
    uint8_t y = 1 + (k+1)*FH;
    int8_t i = k + s_pgOfs;
#endif

    uint8_t attr = (sub==i ? (editMode>0 ? BLINK|INVERS : INVERS) : 0);
    switch(i) {
#if defined(CPUARM)
      case MIX_FIELD_NAME:
        editSingleName(COLUMN_X+MIXES_2ND_COLUMN, y, STR_MIXNAME, md2->name, sizeof(md2->name), event, attr);
        break;
#endif
      case MIX_FIELD_SOURCE:
        lcd_putsColumnLeft(COLUMN_X, y, NO_INDENT(STR_SOURCE));
        putsMixerSource(COLUMN_X+MIXES_2ND_COLUMN, y, md2->srcRaw, STREXPANDED|attr);
        if (attr) CHECK_INCDEC_MODELSOURCE(event, md2->srcRaw, 1, MIXSRC_LAST);
        break;
      case MIX_FIELD_WEIGHT:
        lcd_putsColumnLeft(COLUMN_X, y, STR_WEIGHT);
        gvarWeightItem(COLUMN_X+MIXES_2ND_COLUMN, y, md2, attr|LEFT, event);
        break;
      case MIX_FIELD_OFFSET:
      {
        lcd_putsColumnLeft(COLUMN_X, y, NO_INDENT(STR_OFFSET));
        u_int8int16_t offset;
        MD_OFFSET_TO_UNION(md2, offset);
        offset.word = GVAR_MENU_ITEM(COLUMN_X+MIXES_2ND_COLUMN, y, offset.word, GV_RANGELARGE_OFFSET_NEG, GV_RANGELARGE_OFFSET, attr|LEFT, 0, event);
        MD_UNION_TO_OFFSET(offset, md2);
        break;
      }

#if defined(PCBTARANIS)
      case MIX_FIELD_TRIM:
        lcd_putsColumnLeft(COLUMN_X, y, STR_TRIM);
        menu_lcd_onoff(COLUMN_X+MIXES_2ND_COLUMN, y, !md2->carryTrim, attr);
        if (attr) md2->carryTrim = !checkIncDecModel(event, !md2->carryTrim, 0, 1);
        break;
#else
      case MIX_FIELD_TRIM:
      {
        uint8_t not_stick = (md2->srcRaw > NUM_STICKS);
        int8_t carryTrim = -md2->carryTrim;
        lcd_putsColumnLeft(COLUMN_X, y, STR_TRIM);
        lcd_putsiAtt((not_stick ? COLUMN_X+MIXES_2ND_COLUMN : COLUMN_X+6*FW-3), y, STR_VMIXTRIMS, (not_stick && carryTrim == 0) ? 0 : carryTrim+1, m_posHorz==0 ? attr : 0);
        if (attr && m_posHorz==0 && (not_stick || editMode>0)) md2->carryTrim = -checkIncDecModel(event, carryTrim, not_stick ? TRIM_ON : -TRIM_OFF, -TRIM_AIL);
        if (!not_stick) {
          lcd_puts(COLUMN_X+MIXES_2ND_COLUMN, y, STR_DREX);
          menu_lcd_onoff(COLUMN_X+MIXES_2ND_COLUMN+DREX_CHBOX_OFFSET, y, !md2->noExpo, m_posHorz==1 ? attr : 0);
          if (attr && m_posHorz==1 && editMode>0) md2->noExpo = !checkIncDecModel(event, !md2->noExpo, 0, 1);
        }
        else if (attr) {
          REPEAT_LAST_CURSOR_MOVE();
        }
        break;
      }
#endif

#if defined(CURVES)
      case MIX_FIELD_CURVE:
      {
        lcd_putsColumnLeft(COLUMN_X, y, STR_CURVE);
#if defined(PCBTARANIS)
        editCurveRef(COLUMN_X+MIXES_2ND_COLUMN, y, md2->curve, event, attr);
#else
        int8_t curveParam = md2->curveParam;
        if (md2->curveMode == MODE_CURVE) {
          putsCurve(COLUMN_X+MIXES_2ND_COLUMN, y, curveParam, attr);
          if (attr) {
            if (event==EVT_KEY_LONG(KEY_ENTER) && (curveParam<0 || curveParam>=CURVE_BASE)){
              s_curveChan = (curveParam<0 ? -curveParam-1 : curveParam-CURVE_BASE);
              pushMenu(menuModelCurveOne);
            }
            else {
              CHECK_INCDEC_MODELVAR(event, md2->curveParam, -MAX_CURVES, CURVE_BASE+MAX_CURVES-1);
              if (md2->curveParam == 0)
                md2->curveMode = MODE_DIFFERENTIAL;
#if defined(ROTARY_ENCODER_NAVIGATION) || defined(PCBTARANIS)
              MOVE_CURSOR_FROM_HERE();
#else
              m_posHorz = 0;
#endif
            }
          }
        }
        else {
          lcd_putsAtt(COLUMN_X+MIXES_2ND_COLUMN, y, PSTR("Diff"), m_posHorz==0 ? attr : 0);
          md2->curveParam = GVAR_MENU_ITEM(COLUMN_X+MIXES_2ND_COLUMN+5*FW, y, curveParam, -100, 100, LEFT|(m_posHorz==1 ? attr : 0), 0, editMode>0 ? event : 0);
          if (attr && editMode>0 && m_posHorz==0) {
            int8_t tmp = 0;
            CHECK_INCDEC_MODELVAR(event, tmp, -1, 1);
            if (tmp != 0) {
              md2->curveMode = MODE_CURVE;
              md2->curveParam = tmp;
            }
          }
        }
#endif
        break;
      }
#endif
#if defined(FLIGHT_MODES)
      case MIX_FIELD_FLIGHT_PHASE:
        md2->flightModes = editFlightModes(COLUMN_X+MIXES_2ND_COLUMN, y, event, md2->flightModes, attr);
        break;
#endif
      case MIX_FIELD_SWITCH:
        md2->swtch = switchMenuItem(COLUMN_X+MIXES_2ND_COLUMN, y, md2->swtch, attr, event);
        break;
      case MIX_FIELD_WARNING:
        lcd_putsColumnLeft(COLUMN_X+MIXES_2ND_COLUMN, y, STR_MIXWARNING);
        if (md2->mixWarn)
          lcd_outdezAtt(COLUMN_X+MIXES_2ND_COLUMN, y, md2->mixWarn, attr|LEFT);
        else
          lcd_putsAtt(COLUMN_X+MIXES_2ND_COLUMN, y, STR_OFF, attr);
        if (attr) CHECK_INCDEC_MODELVAR_ZERO(event, md2->mixWarn, 3);
        break;
      case MIX_FIELD_MLTPX:
        md2->mltpx = selectMenuItem(COLUMN_X+MIXES_2ND_COLUMN, y, STR_MULTPX, STR_VMLTPX, md2->mltpx, 0, 2, attr, event);
        break;
      case MIX_FIELD_DELAY_UP:
        md2->delayUp = EDIT_DELAY(COLUMN_X, y, event, attr, STR_DELAYUP, md2->delayUp);
        break;
      case MIX_FIELD_DELAY_DOWN:
        md2->delayDown = EDIT_DELAY(COLUMN_X, y, event, attr, STR_DELAYDOWN, md2->delayDown);
        break;
      case MIX_FIELD_SLOW_UP:
        md2->speedUp = EDIT_DELAY(COLUMN_X, y, event, attr, STR_SLOWUP, md2->speedUp);
        break;
      case MIX_FIELD_SLOW_DOWN:
        md2->speedDown = EDIT_DELAY(COLUMN_X, y, event, attr, STR_SLOWDOWN, md2->speedDown);
        break;
    }
  }
}

static uint8_t s_maxLines = 8;
static uint8_t s_copySrcIdx;
static uint8_t s_copySrcCh;

#define _STR_MAX(x) PSTR("/" #x)
#define STR_MAX(x) _STR_MAX(x)

#if LCD_W >= 212
  #define EXPO_LINE_WEIGHT_POS 8*FW+8
  #define EXPO_LINE_SRC_POS    9*FW+3
  #define EXPO_LINE_CURVE_POS  12*FW+11
  #define EXPO_LINE_TRIM_POS   19*FW-4
  #define EXPO_LINE_SWITCH_POS 20*FW-1
  #define EXPO_LINE_SIDE_POS   25*FW
  #define EXPO_LINE_FM_POS     12*FW+11
  #define EXPO_LINE_SELECT_POS 5*FW+2
  #define EXPO_LINE_NAME_POS   LCD_W-LEN_EXPOMIX_NAME*FW-MENUS_SCROLLBAR_WIDTH
  #define MIX_LINE_WEIGHT_POS  6*FW+8
  #define MIX_LINE_SRC_POS     7*FW+3
  #define MIX_LINE_CURVE_POS   13*FW+3
  #define MIX_LINE_SWITCH_POS  19*FW+1
  #define MIX_LINE_FM_POS      13*FW+3
  #define MIX_LINE_DELAY_POS   24*FW+3
#elif defined(CPUARM)
  #define EXPO_LINE_WEIGHT_POS 7*FW+1
  #define EXPO_LINE_EXPO_POS   10*FW+5
  #define EXPO_LINE_SWITCH_POS 11*FW+2
  #define EXPO_LINE_SIDE_POS   14*FW+2
  #define EXPO_LINE_SELECT_POS 24
  #define EXPO_LINE_FM_POS
  #define EXPO_LINE_NAME_POS   LCD_W-LEN_EXPOMIX_NAME*FW-MENUS_SCROLLBAR_WIDTH
  #define MIX_LINE_SRC_POS     4*FW-1
  #define MIX_LINE_WEIGHT_POS  11*FW+3
  #define MIX_LINE_CURVE_POS   12*FW+2
  #define MIX_LINE_SWITCH_POS  16*FW
  #define MIX_LINE_DELAY_POS   19*FW+7
#else
  #define EXPO_LINE_WEIGHT_POS 7*FW+1
  #define EXPO_LINE_EXPO_POS   11*FW
  #define EXPO_LINE_SWITCH_POS 11*FW+4
  #if MAX_FLIGHT_MODES == 6
    #define EXPO_LINE_SIDE_POS 15*FW
  #else
    #define EXPO_LINE_SIDE_POS 15*FW+2
  #endif
  #define EXPO_LINE_FM_POS     LCD_W-FW-MENUS_SCROLLBAR_WIDTH
  #define EXPO_LINE_SELECT_POS 24
  #define MIX_LINE_SRC_POS     4*FW-1
  #define MIX_LINE_WEIGHT_POS  11*FW+3
  #define MIX_LINE_CURVE_POS   12*FW+2
  #define MIX_LINE_SWITCH_POS  16*FW
  #define MIX_LINE_DELAY_POS   19*FW+7
#endif

#if defined(NAVIGATION_MENUS)
void onExpoMixMenu(const char *result)
{
  bool expo = (g_menuStack[g_menuStackPtr] == menuModelExposAll);
  uint8_t chn = (expo ? expoAddress(s_currIdx)->chn+1 : mixAddress(s_currIdx)->destCh+1);

  if (result == STR_EDIT) {
    pushMenu(expo ? menuModelExpoOne : menuModelMixOne);
  }
  else if (result == STR_INSERT_BEFORE || result == STR_INSERT_AFTER) {
    if (!reachExpoMixCountLimit(expo)) {
      s_currCh = chn;
      if (result == STR_INSERT_AFTER) { s_currIdx++; m_posVert++; }
      insertExpoMix(expo, s_currIdx);
      pushMenu(expo ? menuModelExpoOne : menuModelMixOne);
    }
  }
  else if (result == STR_COPY || result == STR_MOVE) {
    s_copyMode = (result == STR_COPY ? COPY_MODE : MOVE_MODE);
    s_copySrcIdx = s_currIdx;
    s_copySrcCh = chn;
    s_copySrcRow = m_posVert;
  }
  else if (result == STR_DELETE) {
    deleteExpoMix(expo, s_currIdx);
  }
}
#endif

#if LCD_W >= 212
void displayHeaderChannelName(uint8_t ch)
{
  uint8_t len = zlen(g_model.limitData[ch-1].name, sizeof(g_model.limitData[ch-1].name));
  if (len) {
    lcd_putc(17*FW, 0, ' ');
    lcd_putsnAtt(lcdNextPos, 0, g_model.limitData[ch-1].name, len, ZCHAR);
    lcd_putc(lcdNextPos, 0, ' ');
  }
}
#endif

void displayMixInfos(uint8_t y, MixData *md)
{
#if defined(PCBTARANIS)
  putsCurveRef(MIX_LINE_CURVE_POS, y, md->curve, 0);
#else
  if (md->curveParam) {
    if (md->curveMode == MODE_CURVE)
      putsCurve(MIX_LINE_CURVE_POS, y, md->curveParam);
    else
      displayGVar(MIX_LINE_CURVE_POS+3*FW, y, md->curveParam, -100, 100);
  }
#endif

  if (md->swtch) {
    putsSwitches(MIX_LINE_SWITCH_POS, y, md->swtch);
  }
}

#if defined(PCBTARANIS)
void displayMixLine(uint8_t y, MixData *md)
{
  if (md->name[0]) {
    lcd_putsnAtt(EXPO_LINE_NAME_POS, y, md->name, sizeof(md->name), ZCHAR);
  }

  if (!md->flightModes || ((md->curve.value || md->swtch) && ((get_tmr10ms() / 200) & 1)))
    displayMixInfos(y, md);
  else
    displayFlightModes(MIX_LINE_FM_POS, y, md->flightModes);
}
#elif defined(CPUARM)
void displayMixLine(uint8_t y, MixData *md)
{
  if (md->name[0]) {
    lcd_putsnAtt(EXPO_LINE_NAME_POS, y, md->name, sizeof(md->name), ZCHAR);
  }
  else {
    displayMixInfos(y, md);
  }
}
#else
#define displayMixLine(y, md) displayMixInfos(y, md)
#endif

void displayExpoInfos(uint8_t y, ExpoData *ed)
{
#if defined(PCBTARANIS)
  putsCurveRef(EXPO_LINE_CURVE_POS, y, ed->curve, 0);
#else
  if (ed->curveMode == MODE_CURVE)
    putsCurve(EXPO_LINE_EXPO_POS-3*FW, y, ed->curveParam);
  else
    displayGVar(EXPO_LINE_EXPO_POS, y, ed->curveParam, -100, 100);
#endif

  putsSwitches(EXPO_LINE_SWITCH_POS, y, ed->swtch, 0);
}

#if defined(PCBTARANIS)
void displayExpoLine(uint8_t y, ExpoData *ed)
{ 
  putsMixerSource(EXPO_LINE_SRC_POS, y, ed->srcRaw, 0);

  if (ed->carryTrim != TRIM_ON) {
    lcd_putc(EXPO_LINE_TRIM_POS, y, ed->carryTrim > 0 ? '-' : STR_RETA123[-ed->carryTrim]);
  }

  if (!ed->flightModes || ((ed->curve.value || ed->swtch) && ((get_tmr10ms() / 200) & 1)))
    displayExpoInfos(y, ed);
  else
    displayFlightModes(EXPO_LINE_FM_POS, y, ed->flightModes);
      
  if (ed->name[0]) {
    lcd_putsnAtt(EXPO_LINE_NAME_POS, y, ed->name, sizeof(ed->name), ZCHAR);
  }
}
#elif defined(CPUARM)
void displayExpoLine(uint8_t y, ExpoData *ed)
{
  displayExpoInfos(y, ed);
  
  if (ed->name[0]) {
    lcd_putsnAtt(EXPO_LINE_NAME_POS, y, ed->name, sizeof(ed->name), ZCHAR);
  }
}
#else
#define displayExpoLine(y, ed) \
  displayExpoInfos(y, ed); \
  displayFlightModes(EXPO_LINE_FM_POS, y, ed->flightModes) 
#endif

void menuModelExpoMix(uint8_t expo, uint8_t event)
{
  uint8_t sub = m_posVert;

  if (s_editMode > 0)
    s_editMode = 0;

  uint8_t chn = (expo ? expoAddress(s_currIdx)->chn+1 : mixAddress(s_currIdx)->destCh+1);

  switch (event)
  {
    case EVT_ENTRY:
    case EVT_ENTRY_UP:
      s_copyMode = 0;
      s_copyTgtOfs = 0;
      break;
    case EVT_KEY_LONG(KEY_EXIT):
      if (s_copyMode && s_copyTgtOfs == 0) {
        deleteExpoMix(expo, s_currIdx);
        killEvents(event);
        event = 0;
      }
      // no break
#if defined(ROTARY_ENCODER_NAVIGATION)
    case EVT_ROTARY_LONG:
      if (s_copyMode) {
        killEvents(event);
      }
#endif
    case EVT_KEY_BREAK(KEY_EXIT):
      if (s_copyMode) {
        if (s_copyTgtOfs) {
          // cancel the current copy / move operation
          if (s_copyMode == COPY_MODE) {
            deleteExpoMix(expo, s_currIdx);
          }
          else {
            do {
              swapExpoMix(expo, s_currIdx, s_copyTgtOfs > 0);
              s_copyTgtOfs += (s_copyTgtOfs < 0 ? +1 : -1);
            } while (s_copyTgtOfs != 0);
            eeDirty(EE_MODEL);
          }
          m_posVert = s_copySrcRow;
          s_copyTgtOfs = 0;
        }
        s_copyMode = 0;
        event = 0;
      }
      break;
    case EVT_KEY_BREAK(KEY_ENTER):
      if (sub != 0 && (!s_currCh || (s_copyMode && !s_copyTgtOfs)) && !READ_ONLY()) {
        s_copyMode = (s_copyMode == COPY_MODE ? MOVE_MODE : COPY_MODE);
        s_copySrcIdx = s_currIdx;
        s_copySrcCh = chn;
        s_copySrcRow = sub;
        break;
      }
      // no break

    CASE_EVT_ROTARY_BREAK
    case EVT_KEY_LONG(KEY_ENTER):
      killEvents(event);
      if (s_copyTgtOfs) {
        s_copyMode = 0;
        s_copyTgtOfs = 0;
      }
      else if (sub != 0) {
        if (READ_ONLY()) {
          if (!s_currCh) {
            pushMenu(expo ? menuModelExpoOne : menuModelMixOne);
            return;
          }
        }
        else {
          if (s_copyMode) s_currCh = 0;
#if defined(NAVIGATION_MENUS)
          if (s_currCh) {
            if (reachExpoMixCountLimit(expo)) break;
            insertExpoMix(expo, s_currIdx);
            pushMenu(expo ? menuModelExpoOne : menuModelMixOne);
            s_copyMode = 0;
            return;
          }
          else {
            event = 0;
            s_copyMode = 0;
            MENU_ADD_ITEM(STR_EDIT);
            MENU_ADD_ITEM(STR_INSERT_BEFORE);
            MENU_ADD_ITEM(STR_INSERT_AFTER);
            MENU_ADD_ITEM(STR_COPY);
            MENU_ADD_ITEM(STR_MOVE);
            MENU_ADD_ITEM(STR_DELETE);
            menuHandler = onExpoMixMenu;
          }
#else
          if (s_currCh) {
            if (reachExpoMixCountLimit(expo)) break;
            insertExpoMix(expo, s_currIdx);
          }
          pushMenu(expo ? menuModelExpoOne : menuModelMixOne);
          s_copyMode = 0;
          return;
#endif
        }
      }
      break;
    case EVT_KEY_LONG(KEY_LEFT):
    case EVT_KEY_LONG(KEY_RIGHT):
      if (s_copyMode && !s_copyTgtOfs) {
        if (reachExpoMixCountLimit(expo)) break;
        s_currCh = chn;
        if (event == EVT_KEY_LONG(KEY_RIGHT)) { s_currIdx++; m_posVert++; }
        insertExpoMix(expo, s_currIdx);
        pushMenu(expo ? menuModelExpoOne : menuModelMixOne);
        s_copyMode = 0;
        killEvents(event);
        return;
      }
      break;
#if defined(ROTARY_ENCODER_NAVIGATION)
    case EVT_ROTARY_LEFT:
    case EVT_ROTARY_RIGHT:
#endif
    case EVT_KEY_FIRST(KEY_MOVE_UP):
    case EVT_KEY_REPT(KEY_MOVE_UP):
    case EVT_KEY_FIRST(KEY_MOVE_DOWN):
    case EVT_KEY_REPT(KEY_MOVE_DOWN):
      if (s_copyMode) {
        uint8_t key = (event & 0x1f);
        uint8_t next_ofs = ((IS_ROTARY_UP(event) || key==KEY_MOVE_UP) ? s_copyTgtOfs - 1 : s_copyTgtOfs + 1);

        if (s_copyTgtOfs==0 && s_copyMode==COPY_MODE) {
          // insert a mix on the same channel (just above / just below)
          if (reachExpoMixCountLimit(expo)) break;
          copyExpoMix(expo, s_currIdx);
          if (IS_ROTARY_DOWN(event) || key==KEY_MOVE_DOWN) s_currIdx++;
          else if (sub-s_pgOfs >= 6) s_pgOfs++;
        }
        else if (next_ofs==0 && s_copyMode==COPY_MODE) {
          // delete the mix
          deleteExpoMix(expo, s_currIdx);
          if (IS_ROTARY_UP(event) || key==KEY_MOVE_UP) s_currIdx--;
        }
        else {
          // only swap the mix with its neighbor
          if (!swapExpoMix(expo, s_currIdx, IS_ROTARY_UP(event) || key==KEY_MOVE_UP)) break;
          eeDirty(EE_MODEL);
        }

        s_copyTgtOfs = next_ofs;
      }
      break;
  }

  lcd_outdezAtt(FW*max(sizeof(TR_MENUINPUTS), sizeof(TR_MIXER))+FW+FW/2, 0, getExpoMixCount(expo));
  lcd_puts(FW*max(sizeof(TR_MENUINPUTS), sizeof(TR_MIXER))+FW+FW/2, 0, expo ? STR_MAX(MAX_EXPOS) : STR_MAX(MAX_MIXERS));
  SIMPLE_MENU(expo ? STR_MENUINPUTS : STR_MIXER, menuTabModel, expo ? e_InputsAll : e_MixAll, s_maxLines);

  sub = m_posVert;
  s_currCh = 0;
  uint8_t cur = 1;
  uint8_t i = 0;

  for (uint8_t ch=1; ch<=(expo ? NUM_INPUTS : NUM_CHNOUT); ch++) {
    void *pointer = NULL; MixData * &md = (MixData * &)pointer; ExpoData * &ed = (ExpoData * &)pointer;
    uint8_t y = 1+(cur-s_pgOfs)*FH;
    if (expo ? (i<MAX_EXPOS && (ed=expoAddress(i))->chn+1 == ch && EXPO_VALID(ed)) : (i<MAX_MIXERS && (md=mixAddress(i))->srcRaw && md->destCh+1 == ch)) {
      if (s_pgOfs < cur && cur-s_pgOfs < LCD_LINES) {
        if (expo) {
#if defined(PCBTARANIS)
          putsMixerSource(0, y, ch, 0);
#else
          putsMixerSource(0, y, MIXSRC_Rud+ch-1, 0);
#endif
        }
        else {
          putsChn(0, y, ch, 0); // show CHx
        }
      }
      uint8_t mixCnt = 0;
      do {
        if (s_copyMode) {
          if (s_copyMode == MOVE_MODE && s_pgOfs < cur && cur-s_pgOfs < 8 && s_copySrcCh == ch && s_copyTgtOfs != 0 && i == (s_copySrcIdx + (s_copyTgtOfs<0))) {
            lcd_rect(expo ? 18 : 22, y-1, expo ? LCD_W-18 : LCD_W-22, 9, DOTTED);
            cur++; y+=FH;
          }
          if (s_currIdx == i) {
            sub = m_posVert = cur;
            s_currCh = ch;
          }
        }
        else if (sub == cur) {
          s_currIdx = i;
        }
        if (s_pgOfs < cur && cur-s_pgOfs < 8) {
          uint8_t attr = ((s_copyMode || sub != cur) ? 0 : INVERS);         
          if (expo) {
            ed->weight = GVAR_MENU_ITEM(EXPO_LINE_WEIGHT_POS, y, ed->weight, MIN_EXPO_WEIGHT, 100, attr | (isExpoActive(i) ? BOLD : 0), 0, event);
            displayExpoLine(y, ed);
            if (ed->mode!=3) {
              lcd_putc(EXPO_LINE_SIDE_POS, y, ed->mode == 2 ? 126 : 127);
            }  
          }
          else {
#if LCD_W >= 212
            if (attr) {
              displayHeaderChannelName(ch);
            }
#endif

            if (mixCnt > 0) lcd_putsiAtt(FW, y, STR_VMLTPX2, md->mltpx, 0);

            putsMixerSource(MIX_LINE_SRC_POS, y, md->srcRaw, 0);

            gvarWeightItem(MIX_LINE_WEIGHT_POS, y, md, attr | (isMixActive(i) ? BOLD : 0), event);

            displayMixLine(y, md);
            
            char cs = ' ';
	    if (md->speedDown || md->speedUp)
              cs = 'S';
            if (md->delayUp || md->delayDown)
              cs = (cs =='S' ? '*' : 'D');
            lcd_putc(MIX_LINE_DELAY_POS, y, cs);
          }
          if (s_copyMode) {
            if ((s_copyMode==COPY_MODE || s_copyTgtOfs == 0) && s_copySrcCh == ch && i == (s_copySrcIdx + (s_copyTgtOfs<0))) {
              /* draw a border around the raw on selection mode (copy/move) */
              lcd_rect(expo ? EXPO_LINE_SELECT_POS : 22, y-1, expo ? (LCD_W-EXPO_LINE_SELECT_POS) : (LCD_W-22), 9, s_copyMode == COPY_MODE ? SOLID : DOTTED);
            }
            if (cur == sub) {
              /* invert the raw when it's the current one */
              lcd_filled_rect(expo ? EXPO_LINE_SELECT_POS+1 : 23, y, expo ? (LCD_W-EXPO_LINE_SELECT_POS-2) : (LCD_W-24), 7);
            }
          }
        }
        cur++; y+=FH; mixCnt++; i++; if (expo) ed++; else md++;
      } while (expo ? (i<MAX_EXPOS && ed->chn+1 == ch && EXPO_VALID(ed)) : (i<MAX_MIXERS && md->srcRaw && md->destCh+1 == ch));
      if (s_copyMode == MOVE_MODE && s_pgOfs < cur && cur-s_pgOfs < LCD_LINES && s_copySrcCh == ch && i == (s_copySrcIdx + (s_copyTgtOfs<0))) {
        lcd_rect(expo ? EXPO_LINE_SELECT_POS : 22, y-1, expo ? LCD_W-EXPO_LINE_SELECT_POS : LCD_W-22, 9, DOTTED);
        cur++; y+=FH;
      }
    }
    else {
      uint8_t attr = 0;
      if (sub == cur) {
        s_currIdx = i;
        s_currCh = ch;
        if (!s_copyMode) {
          attr = INVERS;
        }
      }
      if (s_pgOfs < cur && cur-s_pgOfs < LCD_LINES) {
        if (expo) {
#if defined(PCBTARANIS)
          putsMixerSource(0, y, ch, attr);
#else
          putsMixerSource(0, y, MIXSRC_Rud+ch-1, attr);
#endif
        }
        else {
          putsChn(0, y, ch, attr); // show CHx
#if LCD_W >= 212
          if (attr) {
            displayHeaderChannelName(ch);
          }
#endif
        }
        if (s_copyMode == MOVE_MODE && s_copySrcCh == ch) {
          lcd_rect(expo ? EXPO_LINE_SELECT_POS : 22, y-1, expo ? (LCD_W-EXPO_LINE_SELECT_POS) : (LCD_W-22), 9, DOTTED);
        }
      }
      cur++; y+=FH;
    }
  }
  s_maxLines = cur;
  if (sub >= s_maxLines-1) m_posVert = s_maxLines-1;
}

void menuModelExposAll(uint8_t event)
{
  return menuModelExpoMix(1, event);
}

void menuModelMixAll(uint8_t event)
{
  return menuModelExpoMix(0, event);
}

bool thrOutput(uint8_t ch)
{
  for (uint8_t i=0; i<MAX_MIXERS; i++) {
    MixData *mix = mixAddress(i);
    if (mix->destCh==ch && mix->srcRaw==MIXSRC_Thr)
      return true;
  }
  return false;
}

enum LimitsItems {
#if defined(PCBTARANIS)
  ITEM_LIMITS_CH_NAME,
#endif
  ITEM_LIMITS_OFFSET,
  ITEM_LIMITS_MIN,
  ITEM_LIMITS_MAX,
  ITEM_LIMITS_DIRECTION,
#if defined(PCBTARANIS) && defined(CURVES)
  ITEM_LIMITS_CURVE,
#endif
#if defined(PPM_CENTER_ADJUSTABLE)
  ITEM_LIMITS_PPM_CENTER,
#endif
#if defined(PPM_LIMITS_SYMETRICAL)
  ITEM_LIMITS_SYMETRICAL,
#endif
  ITEM_LIMITS_COUNT,
  ITEM_LIMITS_MAXROW = ITEM_LIMITS_COUNT-1
};

#if defined(PCBTARANIS)
  #define LIMITS_NAME_POS           4*FW
  #define LIMITS_OFFSET_POS         14*FW+4
  #define LIMITS_MIN_POS            20*FW-3
  #if defined(PPM_CENTER_ADJUSTABLE)
    #define LIMITS_DIRECTION_POS    20*FW-3
    #define LIMITS_MAX_POS          24*FW+2
    #define LIMITS_REVERT_POS       25*FW-1
    #define LIMITS_CURVE_POS        27*FW-1
    #define LIMITS_PPM_CENTER_POS   34*FW
  #else
    #define LIMITS_DIRECTION_POS    21*FW
    #define LIMITS_MAX_POS          26*FW
    #define LIMITS_REVERT_POS       27*FW
    #define LIMITS_CURVE_POS        32*FW-3
  #endif
#else
  #if defined(PPM_UNIT_US)
    #define LIMITS_MIN_POS          12*FW+1
  #else
    #define LIMITS_MIN_POS          12*FW
  #endif
  #define LIMITS_OFFSET_POS         8*FW
  #if defined(PPM_LIMITS_SYMETRICAL)
    #if defined(PPM_CENTER_ADJUSTABLE)
      #define LIMITS_MAX_POS        15*FW
      #define LIMITS_REVERT_POS     16*FW-3
      #define LIMITS_PPM_CENTER_POS 20*FW+1
    #else
      #define LIMITS_DIRECTION_POS  12*FW+4
      #define LIMITS_MAX_POS        16*FW+4
      #define LIMITS_REVERT_POS     17*FW
    #endif
  #else
    #if defined(PPM_CENTER_ADJUSTABLE)
      #define LIMITS_MAX_POS        16*FW
      #define LIMITS_REVERT_POS     17*FW-2
      #define LIMITS_PPM_CENTER_POS 21*FW+2
    #else
      #define LIMITS_MAX_POS        17*FW
      #define LIMITS_REVERT_POS     18*FW
      #define LIMITS_DIRECTION_POS  12*FW+5
    #endif
  #endif
#endif

#if defined(PCBTARANIS)
  #define LIMITS_MIN_MAX_OFFSET 1000
  #define CONVERT_US_MIN_MAX(x) (((x)*1280)/250)
  #define MIN_MAX_ATTR          attr|PREC1
#else
  #define LIMITS_MIN_MAX_OFFSET 100
  #define CONVERT_US_MIN_MAX(x) ((int16_t(x)*128)/25)
  #define MIN_MAX_ATTR          attr
#endif

#if defined(PPM_UNIT_US)
  #define SET_MIN_MAX(x, val)   x = ((val)*250)/128
  #define MIN_MAX_DISPLAY(x)    CONVERT_US_MIN_MAX(x)
#elif defined(CPUARM)
  #define MIN_MAX_DISPLAY(x)    (x)
  #define SET_MIN_MAX(x, val)   x = (val)
#else
  #define MIN_MAX_DISPLAY(x)    ((int8_t)(x))
#endif

#if defined(PCBTARANIS)
void onLimitsMenu(const char *result)
{
  uint8_t ch = m_posVert - 1;

  if (result == STR_RESET) {
    LimitData *ld = limitAddress(ch);
    ld->min = 0;
    ld->max = 0;
    ld->offset = 0;
    ld->ppmCenter = 0;
    ld->revert = false;
    ld->curve = 0;
  }
  else if (result == STR_COPY_STICKS_TO_OFS) {
    copySticksToOffset(ch);
  }
  else if (result == STR_COPY_TRIMS_TO_OFS) {
    copyTrimsToOffset(ch);
  }
}
#endif

void menuModelLimits(uint8_t event)
{
  uint8_t sub = m_posVert - 1;

  if (sub < NUM_CHNOUT) {
#if defined(PPM_CENTER_ADJUSTABLE) || defined(PPM_UNIT_US)
    lcd_outdezAtt(13*FW, 0, PPM_CH_CENTER(sub)+channelOutputs[sub]/2, 0);
    lcd_puts(13*FW, 0, STR_US);
#else
    lcd_outdezAtt(13*FW, 0, calcRESXto1000(channelOutputs[sub]), PREC1);
#endif
  }

#if defined(CPUARM)
  MENU(STR_MENULIMITS, menuTabModel, e_Limits, 1+NUM_CHNOUT+1, {0, NAVIGATION_LINE_BY_LINE|ITEM_LIMITS_MAXROW, NAVIGATION_LINE_BY_LINE|ITEM_LIMITS_MAXROW, NAVIGATION_LINE_BY_LINE|ITEM_LIMITS_MAXROW, NAVIGATION_LINE_BY_LINE|ITEM_LIMITS_MAXROW, NAVIGATION_LINE_BY_LINE|ITEM_LIMITS_MAXROW, NAVIGATION_LINE_BY_LINE|ITEM_LIMITS_MAXROW, NAVIGATION_LINE_BY_LINE|ITEM_LIMITS_MAXROW, NAVIGATION_LINE_BY_LINE|ITEM_LIMITS_MAXROW, NAVIGATION_LINE_BY_LINE|ITEM_LIMITS_MAXROW, NAVIGATION_LINE_BY_LINE|ITEM_LIMITS_MAXROW, NAVIGATION_LINE_BY_LINE|ITEM_LIMITS_MAXROW, NAVIGATION_LINE_BY_LINE|ITEM_LIMITS_MAXROW, NAVIGATION_LINE_BY_LINE|ITEM_LIMITS_MAXROW, NAVIGATION_LINE_BY_LINE|ITEM_LIMITS_MAXROW, NAVIGATION_LINE_BY_LINE|ITEM_LIMITS_MAXROW, NAVIGATION_LINE_BY_LINE|ITEM_LIMITS_MAXROW, NAVIGATION_LINE_BY_LINE|ITEM_LIMITS_MAXROW, NAVIGATION_LINE_BY_LINE|ITEM_LIMITS_MAXROW, NAVIGATION_LINE_BY_LINE|ITEM_LIMITS_MAXROW, NAVIGATION_LINE_BY_LINE|ITEM_LIMITS_MAXROW, NAVIGATION_LINE_BY_LINE|ITEM_LIMITS_MAXROW, NAVIGATION_LINE_BY_LINE|ITEM_LIMITS_MAXROW, NAVIGATION_LINE_BY_LINE|ITEM_LIMITS_MAXROW, NAVIGATION_LINE_BY_LINE|ITEM_LIMITS_MAXROW, NAVIGATION_LINE_BY_LINE|ITEM_LIMITS_MAXROW, NAVIGATION_LINE_BY_LINE|ITEM_LIMITS_MAXROW, NAVIGATION_LINE_BY_LINE|ITEM_LIMITS_MAXROW, NAVIGATION_LINE_BY_LINE|ITEM_LIMITS_MAXROW, NAVIGATION_LINE_BY_LINE|ITEM_LIMITS_MAXROW, NAVIGATION_LINE_BY_LINE|ITEM_LIMITS_MAXROW, NAVIGATION_LINE_BY_LINE|ITEM_LIMITS_MAXROW, NAVIGATION_LINE_BY_LINE|ITEM_LIMITS_MAXROW, 0});
#else
  MENU(STR_MENULIMITS, menuTabModel, e_Limits, 1+NUM_CHNOUT+1, {0, ITEM_LIMITS_MAXROW, ITEM_LIMITS_MAXROW, ITEM_LIMITS_MAXROW, ITEM_LIMITS_MAXROW, ITEM_LIMITS_MAXROW, ITEM_LIMITS_MAXROW, ITEM_LIMITS_MAXROW, ITEM_LIMITS_MAXROW, ITEM_LIMITS_MAXROW, ITEM_LIMITS_MAXROW, ITEM_LIMITS_MAXROW, ITEM_LIMITS_MAXROW, ITEM_LIMITS_MAXROW, ITEM_LIMITS_MAXROW, ITEM_LIMITS_MAXROW, ITEM_LIMITS_MAXROW, 0});
#endif

#if LCD_W >= 212
  if (sub<NUM_CHNOUT && m_posHorz>=0) {
    displayColumnHeader(STR_LIMITS_HEADERS, m_posHorz);
  }
#endif

  if (s_warning_result) {
    s_warning_result = 0;
    LimitData *ld = limitAddress(sub);
    ld->revert = !ld->revert;
    eeDirty(EE_MODEL);
  }

  for (uint8_t i=0; i<LCD_LINES-1; i++) {
    uint8_t y = 1 + (i+1)*FH;
    uint8_t k = i+s_pgOfs;

    if (k==NUM_CHNOUT) {
      // last line available - add the "copy trim menu" line
      uint8_t attr = (sub==NUM_CHNOUT) ? INVERS : 0;
      lcd_putsAtt(CENTER_OFS, y, STR_TRIMS2OFFSETS, s_noHi ? 0 : attr);
      if (attr) {
        s_editMode = 0;
        if (event==EVT_KEY_LONG(KEY_ENTER)) {
          s_noHi = NO_HI_LEN;
          killEvents(event);
          moveTrimsToOffsets(); // if highlighted and menu pressed - move trims to offsets
        }
      }
      return;
    }

    LimitData *ld = limitAddress(k);

#if LCD_W >= 212 || !defined(PPM_CENTER_ADJUSTABLE)
    int16_t v = (ld->revert) ? -LIMIT_OFS(ld) : LIMIT_OFS(ld);
    char swVal = '-';  // '-', '<', '>'
    if((channelOutputs[k] - v) > 50) swVal = (ld->revert ? 127 : 126); // Switch to raw inputs?  - remove trim!
    if((channelOutputs[k] - v) < -50) swVal = (ld->revert ? 126 : 127);
    putsChn(0, y, k+1, 0);
    lcd_putc(LIMITS_DIRECTION_POS, y, swVal);
#endif

#if defined(PCBTARANIS)
    int limit = (g_model.extendedLimits ? LIMIT_EXT_MAX : 1000);
#else
    int8_t limit = (g_model.extendedLimits ? LIMIT_EXT_MAX : 100);
#endif

#if defined(PCBTARANIS)
    putsChn(0, y, k+1, (sub==k && m_posHorz < 0) ? INVERS : 0);
    if (sub==k && m_posHorz < 0 && event==EVT_KEY_LONG(KEY_ENTER) && !READ_ONLY()) {
      killEvents(event);
      MENU_ADD_ITEM(STR_RESET);
      MENU_ADD_ITEM(STR_COPY_TRIMS_TO_OFS);
      MENU_ADD_ITEM(STR_COPY_STICKS_TO_OFS);
      menuHandler = onLimitsMenu;
    }
#else
    putsChn(0, y, k+1, 0);
#endif

    for (uint8_t j=0; j<ITEM_LIMITS_COUNT; j++) {
      uint8_t attr = ((sub==k && m_posHorz==j) ? ((s_editMode>0) ? BLINK|INVERS : INVERS) : 0);
      uint8_t active = (attr && (s_editMode>0 || p1valdiff)) ;
      if (active) STICK_SCROLL_DISABLE();
      switch(j)
      {
#if defined(PCBTARANIS)
        case ITEM_LIMITS_CH_NAME:
          editName(LIMITS_NAME_POS, y, ld->name, sizeof(ld->name), event, attr);
          break;
#endif

        case ITEM_LIMITS_OFFSET:
#if defined(PCBTARANIS)
          if (GV_IS_GV_VALUE(ld->offset, -1000, 1000) || (attr && event == EVT_KEY_LONG(KEY_ENTER))) {
            ld->offset = GVAR_MENU_ITEM(LIMITS_OFFSET_POS, y, ld->offset, -1000, 1000, attr|PREC1, 0, event);
            break;
          }
#endif

#if defined(PPM_UNIT_US)
          lcd_outdezAtt(LIMITS_OFFSET_POS, y, ((int32_t)ld->offset*128) / 25, attr|PREC1);
#else
          lcd_outdezAtt(LIMITS_OFFSET_POS, y, ld->offset, attr|PREC1);
#endif
          if (active) {
            ld->offset = checkIncDec(event, ld->offset, -1000, 1000, EE_MODEL|NO_INCDEC_MARKS|DBLKEYS_1000);
          }
          else if (attr && event==EVT_KEY_LONG(KEY_MENU)) {
            copySticksToOffset(k);
            s_editMode = 0;
          }
          break;

        case ITEM_LIMITS_MIN:
#if defined(PCBTARANIS)
          if (GV_IS_GV_VALUE(ld->min, -LIMIT_EXT_MAX, LIMIT_EXT_MAX) || (attr && event == EVT_KEY_LONG(KEY_ENTER))) {
            ld->min = GVAR_MENU_ITEM(LIMITS_MIN_POS, y, ld->min, -LIMIT_EXT_MAX, LIMIT_EXT_MAX, MIN_MAX_ATTR, DBLKEYS_1000, event);
            break;
          }
#endif
          lcd_outdezAtt(LIMITS_MIN_POS, y, MIN_MAX_DISPLAY(ld->min-LIMITS_MIN_MAX_OFFSET), MIN_MAX_ATTR);
          if (active) ld->min = LIMITS_MIN_MAX_OFFSET + checkIncDec(event, ld->min-LIMITS_MIN_MAX_OFFSET, -limit, 0, EE_MODEL|DBLKEYS_1000);
          break;

        case ITEM_LIMITS_MAX:
#if defined(PCBTARANIS)
          if (GV_IS_GV_VALUE(ld->max, -LIMIT_EXT_MAX, LIMIT_EXT_MAX) || (attr && event == EVT_KEY_LONG(KEY_ENTER))) {
            ld->max = GVAR_MENU_ITEM(LIMITS_MAX_POS, y, ld->max, -LIMIT_EXT_MAX, LIMIT_EXT_MAX, MIN_MAX_ATTR, DBLKEYS_1000, event);
            break;
          }
#endif
          lcd_outdezAtt(LIMITS_MAX_POS, y, MIN_MAX_DISPLAY(ld->max+LIMITS_MIN_MAX_OFFSET), MIN_MAX_ATTR);
          if (active) ld->max = -LIMITS_MIN_MAX_OFFSET + checkIncDec(event, ld->max+LIMITS_MIN_MAX_OFFSET, 0, +limit, EE_MODEL|DBLKEYS_1000);
          break;

        case ITEM_LIMITS_DIRECTION:
        {
          uint8_t revert = ld->revert;
#if defined(PPM_CENTER_ADJUSTABLE)
          lcd_putcAtt(LIMITS_REVERT_POS, y, revert ? 127 : 126, attr);
#else
          lcd_putsiAtt(LIMITS_REVERT_POS, y, STR_MMMINV, revert, attr);
#endif
          if (active) {
            uint8_t revert_new = checkIncDecModel(event, revert, 0, 1);
            if (checkIncDec_Ret && thrOutput(k)) {
              POPUP_CONFIRMATION(STR_INVERT_THR);
            }
            else {
              ld->revert = revert_new;
            }
          }
          break;
        }

#if defined(PCBTARANIS) && defined(CURVES)
        case ITEM_LIMITS_CURVE:
          putsCurve(LIMITS_CURVE_POS, y, ld->curve, attr);
          if (attr && event==EVT_KEY_LONG(KEY_ENTER) && ld->curve>0) {
            s_curveChan = (ld->curve<0 ? -ld->curve-1 : ld->curve-1);
            pushMenu(menuModelCurveOne);
          }
          if (active) {
            CHECK_INCDEC_MODELVAR(event, ld->curve, -MAX_CURVES, +MAX_CURVES);
          }
          break;
#endif

#if defined(PPM_CENTER_ADJUSTABLE)
        case ITEM_LIMITS_PPM_CENTER:
          lcd_outdezAtt(LIMITS_PPM_CENTER_POS, y, PPM_CENTER+ld->ppmCenter, attr);
          if (active) {
            CHECK_INCDEC_MODELVAR(event, ld->ppmCenter, -125, +125);
          }
          break;
#endif

#if defined(PPM_LIMITS_SYMETRICAL)
        case ITEM_LIMITS_SYMETRICAL:
#if defined(CPUARM)
          lcd_putcAtt(LCD_W-FW-MENUS_SCROLLBAR_WIDTH, y, ld->symetrical ? '=' : '\306', attr);
#else
          lcd_putcAtt(LCD_W-FW-MENUS_SCROLLBAR_WIDTH, y, ld->symetrical ? '=' : '^', attr);
#endif
          if (active) {
            CHECK_INCDEC_MODELVAR_ZERO(event, ld->symetrical, 1);
          }
          break;
#endif
      }
    }
  }
}

#if defined(CURVES)

#if defined(GVARS)
  #define CURVE_SELECTED() (sub >= 0 && sub < MAX_CURVES)
  #define GVAR_SELECTED()  (sub >= MAX_CURVES)
#else
  #define CURVE_SELECTED() (sub >= 0)
#endif

void menuModelCurvesAll(uint8_t event)
{
#if defined(GVARS) && defined(PCBSTD)
  SIMPLE_MENU(STR_MENUCURVES, menuTabModel, e_CurvesAll, 1+MAX_CURVES+MAX_GVARS);
#else
  SIMPLE_MENU(STR_MENUCURVES, menuTabModel, e_CurvesAll, 1+MAX_CURVES);
#endif

  int8_t  sub = m_posVert - 1;

  switch (event) {
#if defined(ROTARY_ENCODER_NAVIGATION)
    case EVT_ROTARY_BREAK:
#endif
#if defined(PCBTARANIS)
    case EVT_KEY_BREAK(KEY_ENTER):
#else
    case EVT_KEY_FIRST(KEY_RIGHT):
    case EVT_KEY_FIRST(KEY_ENTER):
#endif
      if (CURVE_SELECTED() && !READ_ONLY()) {
        s_curveChan = sub;
        pushMenu(menuModelCurveOne);
      }
      break;
  }

  for (uint8_t i=0; i<LCD_LINES-1; i++) {
    uint8_t y = 1 + FH + i*FH;
    uint8_t k = i + s_pgOfs;
    uint8_t attr = (sub == k ? INVERS : 0);
#if defined(GVARS) && defined(PCBSTD)
    if (k >= MAX_CURVES) {
      putsStrIdx(0, y, STR_GV, k-MAX_CURVES+1);
      if (GVAR_SELECTED()) {
        if (attr && s_editMode>0) attr |= BLINK;
        lcd_outdezAtt(10*FW, y, GVAR_VALUE(k-MAX_CURVES, -1), attr);
        if (attr) g_model.gvars[k-MAX_CURVES] = checkIncDec(event, g_model.gvars[k-MAX_CURVES], -1000, 1000, EE_MODEL);
      }
    }
    else
#endif
    {
      putsStrIdx(0, y, STR_CV, k+1, attr);
#if defined(PCBTARANIS)
      editName(4*FW, y, g_model.curveNames[k], sizeof(g_model.curveNames[k]), 0, 0);
      CurveInfo & crv = g_model.curves[k];
      lcd_outdezAtt(11*FW, y, 5+crv.points, LEFT);
      lcd_putsAtt(lcdLastPos, y, STR_PTS, 0);
#endif
    }
  }

  if (CURVE_SELECTED()) {
    s_curveChan = sub;
    DrawCurve(23);
  }
}
#endif

#if LCD_W >= 212 && defined(GVARS) && defined(FLIGHT_MODES)

void onGVARSMenu(const char *result)
{
  int8_t sub = m_posVert - 1;

  if (result == STR_ENABLE_POPUP) {
    g_model.gvars[sub].popup = true;
    eeDirty(EE_MODEL);
  }
  else if (result == STR_DISABLE_POPUP) {
    g_model.gvars[sub].popup = false;
    eeDirty(EE_MODEL);
  }
  else if (result == STR_CLEAR) {
    for (int i=0; i<MAX_FLIGHT_MODES; i++) {
      g_model.flightModeData[i].gvars[sub] = 0;
    }
    eeDirty(EE_MODEL);
  }
}

#define GVARS_FM_COLUMN(p) (12*FW + FWNUM + (p)*(2+3*FWNUM) - 3)

void menuModelGVars(uint8_t event)
{
  tmr10ms_t tmr10ms = get_tmr10ms();
  const char * menuTitle;
  bool first2seconds = (tmr10ms - menuEntryTime > 200); /*2 seconds*/

  if (first2seconds) {
    menuTitle = STR_GLOBAL_V;
    for (int i=0; i<MAX_GVARS; i++) {
      putsStrIdx(GVARS_FM_COLUMN(i)-16, 1, STR_FP, i, SMLSIZE|(getFlightMode()==i ? INVERS : 0));
    }
  }
  else {
    menuTitle = STR_MENUGLOBALVARS;
  }

  MENU_FLAGS(menuTitle, menuTabModel, e_GVars, first2seconds ? CHECK_FLAG_NO_SCREEN_INDEX : 0, 1+MAX_GVARS, {0, NAVIGATION_LINE_BY_LINE|MAX_FLIGHT_MODES, NAVIGATION_LINE_BY_LINE|MAX_FLIGHT_MODES, NAVIGATION_LINE_BY_LINE|MAX_FLIGHT_MODES, NAVIGATION_LINE_BY_LINE|MAX_FLIGHT_MODES, NAVIGATION_LINE_BY_LINE|MAX_FLIGHT_MODES, NAVIGATION_LINE_BY_LINE|MAX_FLIGHT_MODES, NAVIGATION_LINE_BY_LINE|MAX_FLIGHT_MODES, NAVIGATION_LINE_BY_LINE|MAX_FLIGHT_MODES, NAVIGATION_LINE_BY_LINE|MAX_FLIGHT_MODES});

  uint8_t sub = m_posVert - 1;

#if MAX_GVARS > 6
  for (uint8_t l=0; l<LCD_LINES-1; l++) {
    uint8_t i = l+s_pgOfs;
    uint8_t y = 1 + FH + l*FH;
#elif MAX_GVARS == 6
  for (uint8_t i=0; i<MAX_GVARS; i++) {
    uint8_t y = 1 + 2*FH + i*FH;
#else
  for (uint8_t i=0; i<MAX_GVARS; i++) {
    uint8_t y = 1 + 3*FH + i*FH;
#endif

    if (g_model.gvars[i].popup) lcd_putc(3*FW, y, '!');
    putsStrIdx(0, y, STR_GV, i+1, (sub==i && CURSOR_ON_LINE()) ? INVERS : 0);

    for (uint8_t j=0; j<1+MAX_FLIGHT_MODES; j++) {
      LcdFlags attr = ((sub==i && m_posHorz==j) ? ((s_editMode>0) ? BLINK|INVERS : INVERS) : 0);
      xcoord_t x = GVARS_FM_COLUMN(j-1);

#if MAX_GVARS == 6
      if (i==0 && j!=9) putsStrIdx(x+2, FH+1, STR_FP, j, SMLSIZE);
#elif MAX_GVARS <= 5
      if (i==0 && j!=9) putsStrIdx(x+2, 2*FH, STR_FP, j, SMLSIZE);
#endif

      switch(j)
      {
        case 0:
          editName(4*FW-3, y, g_model.gvars[i].name, LEN_GVAR_NAME, event, attr);
          break;

        default:
        {
          FlightModeData *fm = &g_model.flightModeData[j-1];
          int16_t & v = fm->gvars[i];
          int16_t vmin, vmax;
          if (v > GVAR_MAX) {
            uint8_t p = v - GVAR_MAX - 1;
            if (p >= j-1) p++;
            putsFlightMode(x-15, y, p+1, attr|SMLSIZE);
            vmin = GVAR_MAX+1; vmax = GVAR_MAX+MAX_FLIGHT_MODES-1;
          }
          else {
            if (abs(v) >= 100)
              lcd_outdezAtt(x, y+1, v, attr | TINSIZE);
            else
              lcd_outdezAtt(x, y, v, attr);
            vmin = -GVAR_MAX; vmax = GVAR_MAX;
          }
          if (attr) {
            if (event == EVT_KEY_LONG(KEY_ENTER)) {
              v = (v > GVAR_MAX ? 0 : GVAR_MAX+1);
              eeDirty(EE_MODEL);
            }
            else if (s_editMode>0 || p1valdiff) {
              v = checkIncDec(event, v, vmin, vmax, EE_MODEL);
            }
          }
          break;
        }
      }
    }
  }

  if (m_posVert > 0 && m_posHorz < 0 && event==EVT_KEY_LONG(KEY_ENTER)) {
    killEvents(event);
    if (g_model.gvars[sub].popup)
      MENU_ADD_ITEM(STR_DISABLE_POPUP);
    else
      MENU_ADD_ITEM(STR_ENABLE_POPUP);
    MENU_ADD_ITEM(STR_CLEAR);
    menuHandler = onGVARSMenu;
  }
}
#endif

enum LogicalSwitchFields {
  LS_FIELD_FUNCTION,
  LS_FIELD_V1,
  LS_FIELD_V2,
#if defined(PCBTARANIS)
  LS_FIELD_V3,
#endif
  LS_FIELD_ANDSW,
#if defined(CPUARM)
  LS_FIELD_DURATION,
  LS_FIELD_DELAY,
#endif
  LS_FIELD_COUNT,
  LS_FIELD_LAST = LS_FIELD_COUNT-1
};

#if LCD_W >= 212
  #define CSW_1ST_COLUMN  (4*FW-3)
  #define CSW_2ND_COLUMN  (8*FW+2+FW/2)
  #define CSW_3RD_COLUMN  (14*FW+1+FW/2)
  #define CSW_4TH_COLUMN  (22*FW)
  #define CSW_5TH_COLUMN  (26*FW+3)
  #define CSW_6TH_COLUMN  (31*FW+1)
#else
  #define CSW_1ST_COLUMN  (4*FW-3)
  #define CSW_2ND_COLUMN  (8*FW-3)
  #define CSW_3RD_COLUMN  (13*FW-6)
  #define CSW_4TH_COLUMN  (18*FW+2)
#endif

#if defined(CPUARM)
  #define INCDEC_DECLARE_VARS()   uint8_t incdecFlag = EE_MODEL; IsValueAvailable isValueAvailable = NULL
  #define INCDEC_SET_FLAG(f)      incdecFlag = (EE_MODEL|(f))
  #define INCDEC_ENABLE_CHECK(fn) isValueAvailable = fn
  #define CHECK_INCDEC_PARAM(event, var, min, max) checkIncDec(event, var, min, max, incdecFlag, isValueAvailable)
#elif defined(CPUM64)
  #define INCDEC_DECLARE_VARS()
  #define INCDEC_SET_FLAG(f)
  #define INCDEC_ENABLE_CHECK(fn)
  #define CHECK_INCDEC_PARAM(event, var, min, max) checkIncDec(event, var, min, max, EE_MODEL)
#else
  #define INCDEC_DECLARE_VARS()   uint8_t incdecFlag = EE_MODEL
  #define INCDEC_SET_FLAG(f)      incdecFlag = (EE_MODEL|(f))
  #define INCDEC_ENABLE_CHECK(fn)
  #define CHECK_INCDEC_PARAM(event, var, min, max) checkIncDec(event, var, min, max, incdecFlag)
#endif

#if defined(CPUARM)
void putsEdgeDelayParam(xcoord_t x, uint8_t y, LogicalSwitchData *cs, uint8_t lattr, uint8_t rattr)
{
  lcd_putc(x-4, y, '[');
  lcd_outdezAtt(x, y, lswTimerValue(cs->v2), LEFT|PREC1|lattr);
  lcd_putc(lcdLastPos, y, ':');
  if (cs->v3 < 0)
    lcd_putsAtt(lcdLastPos+3, y, "<<", rattr);
  else if (cs->v3 == 0)
    lcd_putsAtt(lcdLastPos+3, y, "--", rattr);
  else
    lcd_outdezAtt(lcdLastPos+3, y, lswTimerValue(cs->v2+cs->v3), LEFT|PREC1|rattr);
  lcd_putc(lcdLastPos, y, ']');
}
#endif

#if defined(CPUARM) && LCD_W < 212

#define CSWONE_2ND_COLUMN (11*FW)

void menuModelLogicalSwitchOne(uint8_t event)
{
  TITLE(STR_MENULOGICALSWITCH);

  LogicalSwitchData * cs = lswAddress(s_currIdx);
  uint8_t sw = SWSRC_SW1+s_currIdx;
  putsSwitches(14*FW, 0, sw, (getSwitch(sw) ? BOLD : 0));

  SUBMENU_NOTITLE(LS_FIELD_COUNT, {0, 0, 1, 0 /*, 0...*/});

  int8_t sub = m_posVert;

  INCDEC_DECLARE_VARS();

  int v1_val = cs->v1;

  for (uint8_t k=0; k<LCD_LINES-1; k++) {
    uint8_t y = 1 + (k+1)*FH;
    uint8_t i = k + s_pgOfs;
    uint8_t attr = (sub==i ? (s_editMode>0 ? BLINK|INVERS : INVERS) : 0);
    uint8_t cstate = lswFamily(cs->func);
    switch(i) {
      case LS_FIELD_FUNCTION:
        lcd_putsLeft(y, STR_FUNC);
        lcd_putsiAtt(CSWONE_2ND_COLUMN, y, STR_VCSWFUNC, cs->func, attr);
        if (attr) {
          cs->func = checkIncDec(event, cs->func, 0, LS_FUNC_MAX, EE_MODEL, isLogicalSwitchFunctionAvailable);
          uint8_t new_cstate = lswFamily(cs->func);
          if (cstate != new_cstate) {
            if (new_cstate == LS_FAMILY_TIMER) {
              cs->v1 = cs->v2 = 0;
            }
            else if (new_cstate == LS_FAMILY_STAY) {
              cs->v1 = 0; cs->v2 = -129; cs->v3 = 0;
            }
            else {
              cs->v1 = cs->v2 = 0;
            }
          }
        }
        break;
      case LS_FIELD_V1:
      {
        lcd_putsLeft(y, STR_V1);
        int v1_min=0, v1_max=MIXSRC_LAST_TELEM;
        if (cstate == LS_FAMILY_BOOL || cstate == LS_FAMILY_STICKY || cstate == LS_FAMILY_STAY) {
          putsSwitches(CSWONE_2ND_COLUMN, y, v1_val, attr);
          v1_min = SWSRC_OFF+1; v1_max = SWSRC_ON-1;
        }
        else if (cstate == LS_FAMILY_TIMER) {
          lcd_outdezAtt(CSWONE_2ND_COLUMN, y, v1_val+1, LEFT|attr);
          v1_max = 99;
        }
        else {
          v1_val = (uint8_t)cs->v1;
          putsMixerSource(CSWONE_2ND_COLUMN, y, v1_val, attr);
          INCDEC_SET_FLAG(INCDEC_SOURCE);
          INCDEC_ENABLE_CHECK(isSourceAvailable);
        }
        if (attr) {
	  cs->v1 = CHECK_INCDEC_PARAM(event, v1_val, v1_min, v1_max);
        }
        break;
      }
      case LS_FIELD_V2:
      {
        lcd_putsLeft(y, STR_V2);
        int v2_min=0, v2_max=MIXSRC_LAST_TELEM;
        if (cstate == LS_FAMILY_BOOL || cstate == LS_FAMILY_STICKY) {
          putsSwitches(CSWONE_2ND_COLUMN, y, cs->v2, attr);
          v2_min = SWSRC_OFF+1; v2_max = SWSRC_ON-1;
        }
        else if (cstate == LS_FAMILY_TIMER) {
          lcd_outdezAtt(CSWONE_2ND_COLUMN, y, cs->v2+1, LEFT|attr);
          v2_max = 99;
        }
        else if (cstate == LS_FAMILY_STAY) {
          putsEdgeDelayParam(CSWONE_2ND_COLUMN, y, cs, m_posHorz==0 ? attr : 0, m_posHorz==1 ? attr : 0);
          if (s_editMode <= 0) continue;
          if (attr && m_posHorz==1) {
            CHECK_INCDEC_MODELVAR(event, cs->v3, -1, 222 - cs->v2);
            break;
          }
          v2_min = -129; v2_max = 122;
        }
        else if (cstate == LS_FAMILY_COMP) {
          putsMixerSource(CSWONE_2ND_COLUMN, y, cs->v2, attr);
          INCDEC_SET_FLAG(INCDEC_SOURCE);
          INCDEC_ENABLE_CHECK(isSourceAvailable);
        }
        else {
#if defined(FRSKY)
          if (v1_val >= MIXSRC_FIRST_TELEM) {
            putsTelemetryChannel(CSWONE_2ND_COLUMN, y, v1_val - MIXSRC_FIRST_TELEM, convertLswTelemValue(cs), attr|LEFT);
            v2_max = maxTelemValue(v1_val - MIXSRC_FIRST_TELEM + 1);
            if (cs->func == LS_FUNC_DIFFEGREATER)
              v2_min = -v2_max;
            else if (cs->func == LS_FUNC_ADIFFEGREATER)
              v2_min = 0;
            else
              v2_min = minTelemValue(v1_val - MIXSRC_FIRST_TELEM + 1);
            INCDEC_SET_FLAG(INCDEC_REP10 | NO_INCDEC_MARKS);
            if (cs->v2 < v2_min || cs->v2 > v2_max) {
              cs->v2 = 0;
              eeDirty(EE_MODEL);
            }
          }
          else
#endif
          {
            v2_min = -LIMIT_EXT_PERCENT; v2_max = +LIMIT_EXT_PERCENT;
            lcd_outdezAtt(CSWONE_2ND_COLUMN, y, cs->v2, LEFT|attr);
          }
        }

        if (attr) {
          CHECK_INCDEC_MODELVAR(event, cs->v2, v2_min, v2_max);
        }
        break;
      }
      case LS_FIELD_ANDSW:
        lcd_putsLeft(y, STR_AND_SWITCH);
        putsSwitches(CSWONE_2ND_COLUMN, y, cs->andsw, attr);
        if (attr) CHECK_INCDEC_MODELVAR(event, cs->andsw, -MAX_LS_ANDSW, MAX_LS_ANDSW);
        break;
      case LS_FIELD_DURATION:
        lcd_putsLeft(y, STR_DURATION);
        if (cs->duration > 0)
          lcd_outdezAtt(CSWONE_2ND_COLUMN, y, cs->duration, attr|PREC1|LEFT);
        else
          lcd_putsiAtt(CSWONE_2ND_COLUMN, y, STR_MMMINV, 0, attr);
        if (attr) CHECK_INCDEC_MODELVAR_ZERO(event, cs->duration, MAX_LS_DURATION);
        break;
      case LS_FIELD_DELAY:
        lcd_putsLeft(y, STR_DELAY);
        if (cs->delay > 0)
          lcd_outdezAtt(CSWONE_2ND_COLUMN, y, cs->delay, attr|PREC1|LEFT);
        else
          lcd_putsiAtt(CSWONE_2ND_COLUMN, y, STR_MMMINV, 0, attr);
        if (attr) CHECK_INCDEC_MODELVAR_ZERO(event, cs->delay, MAX_LS_DELAY);
        break;
    }
  }
}

void menuModelLogicalSwitches(uint8_t event)
{
  SIMPLE_MENU(STR_MENULOGICALSWITCHES, menuTabModel, e_LogicalSwitches, NUM_LOGICAL_SWITCH+1);

  uint8_t y = 0;
  uint8_t k = 0;
  int8_t sub = m_posVert - 1;

  switch (event) {
#if defined(ROTARY_ENCODER_NAVIGATION)
    case EVT_ROTARY_BREAK:
#endif
    case EVT_KEY_FIRST(KEY_RIGHT):
    case EVT_KEY_FIRST(KEY_ENTER):
      if (sub >= 0) {
        s_currIdx = sub;
        pushMenu(menuModelLogicalSwitchOne);
      }
      break;
  }

  for (uint8_t i=0; i<LCD_LINES-1; i++) {
    y = 1 + (i+1)*FH;
    k = i+s_pgOfs;
    LogicalSwitchData * cs = lswAddress(k);

    // CSW name
    uint8_t sw = SWSRC_SW1+k;

    putsSwitches(0, y, sw, (sub==k ? INVERS : 0) | (getSwitch(sw) ? BOLD : 0));

    if (cs->func > 0) {
      // CSW func
      lcd_putsiAtt(CSW_1ST_COLUMN, y, STR_VCSWFUNC, cs->func, 0);

      // CSW params
      uint8_t cstate = lswFamily(cs->func);

      if (cstate == LS_FAMILY_BOOL || cstate == LS_FAMILY_STICKY) {
        putsSwitches(CSW_2ND_COLUMN, y, cs->v1, 0);
        putsSwitches(CSW_3RD_COLUMN, y, cs->v2, 0);
      }
      else if (cstate == LS_FAMILY_COMP) {
        putsMixerSource(CSW_2ND_COLUMN, y, cs->v1, 0);
        putsMixerSource(CSW_3RD_COLUMN, y, cs->v2, 0);
      }
      else if (cstate == LS_FAMILY_STAY) {
        putsSwitches(CSW_2ND_COLUMN, y, cs->v1, 0);
        putsEdgeDelayParam(CSW_3RD_COLUMN, y, cs, 0, 0);
      }
      else if (cstate == LS_FAMILY_TIMER) {
        lcd_outdezAtt(CSW_2ND_COLUMN, y, cs->v1+1, LEFT);
        lcd_outdezAtt(CSW_3RD_COLUMN, y, cs->v2+1, LEFT);
      }
      else {
        uint8_t v1 = cs->v1;
        putsMixerSource(CSW_2ND_COLUMN, y, v1, 0);
        if (v1 >= MIXSRC_FIRST_TELEM) {
          putsTelemetryChannel(CSW_3RD_COLUMN, y, v1 - MIXSRC_FIRST_TELEM, convertLswTelemValue(cs), LEFT);
        }
        else {
          lcd_outdezAtt(CSW_3RD_COLUMN, y, cs->v2, LEFT);
        }
      }

      // CSW and switch
      putsSwitches(CSW_4TH_COLUMN, y, cs->andsw, 0);
    }
  }
}

#else

#if defined(PCBTARANIS)
enum ClipboardType {
  CLIPBOARD_TYPE_NONE,
  CLIPBOARD_TYPE_CUSTOM_SWITCH,
  CLIPBOARD_TYPE_CUSTOM_FUNCTION,
};

struct Clipboard {
  ClipboardType type;
  union {
    LogicalSwitchData csw;
    CustomFnData cfn;
  } data;
};

Clipboard clipboard;

void onLogicalSwitchesMenu(const char *result)
{
  int8_t sub = m_posVert-1;
  LogicalSwitchData * cs = lswAddress(sub);

  if (result == STR_COPY) {
    clipboard.type = CLIPBOARD_TYPE_CUSTOM_SWITCH;
    clipboard.data.csw = *cs;
  }
  else if (result == STR_PASTE) {
    *cs = clipboard.data.csw;
    eeDirty(EE_MODEL);
  }
  else if (result == STR_CLEAR) {
    memset(cs, 0, sizeof(LogicalSwitchData));
    eeDirty(EE_MODEL);
  }
}
#endif

void menuModelLogicalSwitches(uint8_t event)
{
  INCDEC_DECLARE_VARS();

  MENU(STR_MENULOGICALSWITCHES, menuTabModel, e_LogicalSwitches, NUM_LOGICAL_SWITCH+1, {0, NAVIGATION_LINE_BY_LINE|LS_FIELD_LAST/*repeated...*/});

  uint8_t   y = 0;
  uint8_t   k = 0;
  int8_t    sub = m_posVert - 1;
  horzpos_t horz = m_posHorz;

#if LCD_W >= 212
  if (horz>=0) {
    displayColumnHeader(STR_CSW_HEADERS, horz);
  }
#endif

#if defined(PCBTARANIS)
  if (sub>=0 && horz<0 && event==EVT_KEY_LONG(KEY_ENTER) && !READ_ONLY()) {
    killEvents(event);
    LogicalSwitchData * cs = lswAddress(sub);
    if (cs->func)
      MENU_ADD_ITEM(STR_COPY);
    if (clipboard.type == CLIPBOARD_TYPE_CUSTOM_SWITCH)
      MENU_ADD_ITEM(STR_PASTE);
    if (cs->func || cs->v1 || cs->v2 || cs->delay || cs->duration || cs->andsw)
      MENU_ADD_ITEM(STR_CLEAR);
    menuHandler = onLogicalSwitchesMenu;
  }
#endif

  for (uint8_t i=0; i<LCD_LINES-1; i++) {
    y = 1 + (i+1)*FH;
    k = i+s_pgOfs;
    uint8_t attr = (sub==k ? ((s_editMode>0) ? BLINK|INVERS : INVERS)  : 0);
    uint8_t attr1 = (horz==1 ? attr : 0);
    uint8_t attr2 = (horz==2 ? attr : 0);
    LogicalSwitchData * cs = lswAddress(k);

    // CSW name
    uint8_t sw = SWSRC_SW1+k;
    putsSwitches(0, y, sw, (getSwitch(sw) ? BOLD : 0) | ((sub==k && horz<0) ? INVERS : 0));

    // CSW func
    lcd_putsiAtt(CSW_1ST_COLUMN, y, STR_VCSWFUNC, cs->func, horz==0 ? attr : 0);

    // CSW params
    uint8_t cstate = lswFamily(cs->func);
#if defined(CPUARM)
    int16_t v1_val=cs->v1, v1_min=0, v1_max=MIXSRC_LAST_TELEM, v2_min=0, v2_max=MIXSRC_LAST_TELEM;
    int16_t v3_min=-1, v3_max=100;
#else
    int8_t v1_min=0, v1_max=MIXSRC_LAST_TELEM, v2_min=0, v2_max=MIXSRC_LAST_TELEM;
    #define v1_val cs->v1
#endif

    if (cstate == LS_FAMILY_BOOL || cstate == LS_FAMILY_STICKY) {
      putsSwitches(CSW_2ND_COLUMN, y, cs->v1, attr1);
      putsSwitches(CSW_3RD_COLUMN, y, cs->v2, attr2);
      v1_min = SWSRC_FIRST_IN_LOGICAL_SWITCHES; v1_max = SWSRC_LAST_IN_LOGICAL_SWITCHES;
      v2_min = SWSRC_FIRST_IN_LOGICAL_SWITCHES; v2_max = SWSRC_LAST_IN_LOGICAL_SWITCHES;
      INCDEC_SET_FLAG(INCDEC_SWITCH);
      INCDEC_ENABLE_CHECK(isSwitchAvailableInLogicalSwitches);
    }
#if defined(CPUARM)
    else if (cstate == LS_FAMILY_STAY) {
      putsSwitches(CSW_2ND_COLUMN, y, cs->v1, attr1);
      putsEdgeDelayParam(CSW_3RD_COLUMN, y, cs, attr2, horz==LS_FIELD_V3 ? attr : 0);
      v1_min = SWSRC_FIRST_IN_LOGICAL_SWITCHES; v1_max = SWSRC_LAST_IN_LOGICAL_SWITCHES;
      v2_min=-129; v2_max = 122;
      v3_max = 222 - cs->v2;
      if (horz == 1) {
        INCDEC_SET_FLAG(INCDEC_SWITCH);
        INCDEC_ENABLE_CHECK(isSwitchAvailableInLogicalSwitches);
      }
      else {
        INCDEC_SET_FLAG(0);
        INCDEC_ENABLE_CHECK(NULL);
      }
    }
#endif
    else if (cstate == LS_FAMILY_COMP) {
#if defined(CPUARM)
      v1_val = (uint8_t)cs->v1;
#endif
      putsMixerSource(CSW_2ND_COLUMN, y, v1_val, attr1);
      putsMixerSource(CSW_3RD_COLUMN, y, cs->v2, attr2);
      INCDEC_SET_FLAG(INCDEC_SOURCE);
      INCDEC_ENABLE_CHECK(isSourceAvailable);
    }
    else if (cstate == LS_FAMILY_TIMER) {
      lcd_outdezAtt(CSW_2ND_COLUMN, y, lswTimerValue(cs->v1), LEFT|PREC1|attr1);
      lcd_outdezAtt(CSW_3RD_COLUMN, y, lswTimerValue(cs->v2), LEFT|PREC1|attr2);
      v1_min = v2_min = -128;
      v1_max = v2_max = 122;
      INCDEC_SET_FLAG(0);
      INCDEC_ENABLE_CHECK(NULL);
    }
    else {
#if defined(CPUARM)
      v1_val = (uint8_t)cs->v1;
#endif
      putsMixerSource(CSW_2ND_COLUMN, y, v1_val, attr1);
      if (horz == 1) {
        INCDEC_SET_FLAG(INCDEC_SOURCE);
        INCDEC_ENABLE_CHECK(isSourceAvailable);
      }
      else {
        INCDEC_SET_FLAG(0);
        INCDEC_ENABLE_CHECK(NULL);
      }
#if defined(FRSKY)
      if (v1_val >= MIXSRC_FIRST_TELEM) {
        putsTelemetryChannel(CSW_3RD_COLUMN, y, v1_val - MIXSRC_FIRST_TELEM, convertLswTelemValue(cs), LEFT|attr2);
        v2_max = maxTelemValue(v1_val - MIXSRC_FIRST_TELEM + 1);
#if defined(CPUARM)
        if (cs->func == LS_FUNC_DIFFEGREATER)
          v2_min = -v2_max;
        else if (cs->func == LS_FUNC_ADIFFEGREATER)
          v2_min = 0;
        else
          v2_min = minTelemValue(v1_val - MIXSRC_FIRST_TELEM + 1);
        if (horz == 2 && v2_max-v2_min > 1000)
          INCDEC_SET_FLAG(INCDEC_REP10 | NO_INCDEC_MARKS);
        if (cs->v2 < v2_min || cs->v2 > v2_max) {
          cs->v2 = 0;
          eeDirty(EE_MODEL);
        }
#else
        if (cstate == LS_FAMILY_OFS) {
          v2_min = -128;
          v2_max -= 128;
        }
        else {
          v2_max = min((uint8_t)127, (uint8_t)v2_max);
          v2_min = -v2_max;
        }
        if (cs->v2 > v2_max) {
          cs->v2 = v2_max;
          eeDirty(EE_MODEL);
        }
#endif
      }
      else {
        lcd_outdezAtt(CSW_3RD_COLUMN, y, cs->v2, LEFT|attr2);
#if defined(CPUARM) && defined(GVARS)
        if (v1_val >= MIXSRC_GVAR1) {
          v2_min = -1024; v2_max = +1024;
        }
        else
#endif
        {
          v2_min = -LIMIT_EXT_PERCENT; v2_max = +LIMIT_EXT_PERCENT;
        }
      }
#else
      if (v1_val >= MIXSRC_FIRST_TELEM) {
        putsTelemetryChannel(CSW_3RD_COLUMN, y, v1_val - MIXSRC_FIRST_TELEM, convertLswTelemValue(cs), LEFT|attr2);
        v2_min = -128; v2_max = 127;
      }
      else {
        lcd_outdezAtt(CSW_3RD_COLUMN, y, cs->v2, LEFT|attr2);
        v2_min = -LIMIT_EXT_PERCENT; v2_max = +LIMIT_EXT_PERCENT;
      }
#endif
    }

    // CSW AND switch
#if defined(CPUARM)
    putsSwitches(CSW_4TH_COLUMN, y, cs->andsw, horz==LS_FIELD_ANDSW ? attr : 0);
#else
    uint8_t andsw = cs->andsw;
    if (andsw > SWSRC_LAST_SWITCH) {
      andsw += SWSRC_SW1-SWSRC_LAST_SWITCH-1;
    }
    putsSwitches(CSW_4TH_COLUMN, y, andsw, horz==LS_FIELD_ANDSW ? attr : 0);
#endif

#if defined(CPUARM)
    // CSW duration
    if (cs->duration > 0)
      lcd_outdezAtt(CSW_5TH_COLUMN, y, cs->duration, (horz==LS_FIELD_DURATION ? attr : 0)|PREC1|LEFT);
    else
      lcd_putsiAtt(CSW_5TH_COLUMN, y, STR_MMMINV, 0, horz==LS_FIELD_DURATION ? attr : 0);

    // CSW delay
    if (cstate == LS_FAMILY_STAY) {
      lcd_puts(CSW_6TH_COLUMN, y, STR_NA);
      if (attr && horz == LS_FIELD_DELAY) {
        REPEAT_LAST_CURSOR_MOVE();
      }
    }
    else if (cs->delay > 0) {
      lcd_outdezAtt(CSW_6TH_COLUMN, y, cs->delay, (horz==LS_FIELD_DELAY ? attr : 0)|PREC1|LEFT);
    }
    else {
      lcd_putsiAtt(CSW_6TH_COLUMN, y, STR_MMMINV, 0, horz==LS_FIELD_DELAY ? attr : 0);
    }

    if (attr && horz == LS_FIELD_V3 && cstate != LS_FAMILY_STAY) {
      REPEAT_LAST_CURSOR_MOVE();
    }
#endif

    if ((s_editMode>0 || p1valdiff) && attr) {
      switch (horz) {
        case LS_FIELD_FUNCTION:
        {
#if defined(CPUARM)
          cs->func = checkIncDec(event, cs->func, 0, LS_FUNC_MAX, EE_MODEL, isLogicalSwitchFunctionAvailable);
#else
          CHECK_INCDEC_MODELVAR_ZERO(event, cs->func, LS_FUNC_MAX);
#endif
          uint8_t new_cstate = lswFamily(cs->func);
          if (cstate != new_cstate) {
#if defined(CPUARM)
            if (new_cstate == LS_FAMILY_TIMER) {
              cs->v1 = cs->v2 = -119;
            }
            else if (new_cstate == LS_FAMILY_STAY) {
              cs->v1 = 0; cs->v2 = -129; cs->v3 = 0;
            }
            else {
              cs->v1 = cs->v2 = 0;
            }
#else
            cs->v1 = cs->v2 = (new_cstate==LS_FAMILY_TIMER ? -119/*1.0*/ : 0);
#endif
          }
          break;
        }
        case LS_FIELD_V1:
          cs->v1 = CHECK_INCDEC_PARAM(event, v1_val, v1_min, v1_max);
          break;
        case LS_FIELD_V2:
          cs->v2 = CHECK_INCDEC_PARAM(event, cs->v2, v2_min, v2_max);
#if defined(PCBTARANIS)
          if (cstate==LS_FAMILY_OFS && cs->v1!=0 && event==EVT_KEY_LONG(KEY_ENTER)) {
            killEvents(event);
            getvalue_t x = getValue(v1_val);
            if (v1_val < MIXSRC_GVAR1)
              cs->v2 = calcRESXto100(x);
            else if (v1_val - MIXSRC_FIRST_TELEM + 1 == TELEM_ALT)
              cs->v2 *= 100;
            eeDirty(EE_MODEL);
          }
#endif
          break;
#if defined(CPUARM)
        case LS_FIELD_V3:
          cs->v3 = CHECK_INCDEC_PARAM(event, cs->v3, v3_min, v3_max);
          break;
#endif
        case LS_FIELD_ANDSW:
#if defined(CPUARM)
          INCDEC_SET_FLAG(INCDEC_SWITCH);
          INCDEC_ENABLE_CHECK(isSwitchAvailableInLogicalSwitches);
          cs->andsw = CHECK_INCDEC_PARAM(event, cs->andsw, -MAX_LS_ANDSW, MAX_LS_ANDSW);
#else
          CHECK_INCDEC_MODELVAR_ZERO(event, cs->andsw, MAX_LS_ANDSW);
#endif
          break;
#if defined(CPUARM)
        case LS_FIELD_DURATION:
          CHECK_INCDEC_MODELVAR_ZERO(event, cs->duration, MAX_LS_DURATION);
          break;
        case LS_FIELD_DELAY:
          CHECK_INCDEC_MODELVAR_ZERO(event, cs->delay, MAX_LS_DELAY);
          break;
#endif
      }
    }
  }
}
#endif

#if LCD_W >= 212
  #define MODEL_CUSTOM_FUNC_1ST_COLUMN          (4*FW+2)
  #define MODEL_CUSTOM_FUNC_2ND_COLUMN          (8*FW+2)
  #define MODEL_CUSTOM_FUNC_3RD_COLUMN          (21*FW)
  #define MODEL_CUSTOM_FUNC_4TH_COLUMN          (33*FW-3)
  #define MODEL_CUSTOM_FUNC_4TH_COLUMN_ONOFF    (34*FW-3)
#else
  #define MODEL_CUSTOM_FUNC_1ST_COLUMN          (3)
  #define MODEL_CUSTOM_FUNC_2ND_COLUMN          (5*FW-2)
  #define MODEL_CUSTOM_FUNC_3RD_COLUMN          (15*FW+2)
  #define MODEL_CUSTOM_FUNC_4TH_COLUMN          (20*FW)
  #if defined(GRAPHICS)
    #define MODEL_CUSTOM_FUNC_4TH_COLUMN_ONOFF  (20*FW)
  #else
    #define MODEL_CUSTOM_FUNC_4TH_COLUMN_ONOFF  (18*FW+2)
  #endif
#endif

#if defined(CPUARM) && defined(SDCARD)
void onCustomFunctionsFileSelectionMenu(const char *result)
{
  int8_t  sub = m_posVert - 1;
  CustomFnData * cf = &g_model.funcSw[sub];
  uint8_t func = CFN_FUNC(cf);

  if (result == STR_UPDATE_LIST) {
    char directory[256];
    if (func == FUNC_PLAY_SCRIPT) {
      strcpy(directory, SCRIPTS_FUNCS_PATH);
    }
    else {
      strcpy(directory, SOUNDS_PATH);
      strncpy(directory+SOUNDS_PATH_LNG_OFS, currentLanguagePack->id, 2);
    }
    if (!listSdFiles(directory, func==FUNC_PLAY_SCRIPT ? SCRIPTS_EXT : SOUNDS_EXT, sizeof(cf->play.name), NULL)) {
      POPUP_WARNING(func==FUNC_PLAY_SCRIPT ? STR_NO_SCRIPTS_ON_SD : STR_NO_SOUNDS_ON_SD);
      s_menu_flags = 0;
    }
  }
  else {
    // The user choosed a file in the list
    memcpy(cf->play.name, result, sizeof(cf->play.name));
    eeDirty(EE_MODEL);
    if (func == FUNC_PLAY_SCRIPT) {
      LUA_LOAD_MODEL_SCRIPTS();
    }
  }
}
#endif

#if defined(PCBTARANIS)
void onCustomFunctionsMenu(const char *result)
{
  int8_t sub = m_posVert-1;
  CustomFnData * cfn = &g_model.funcSw[sub];

  if (result == STR_COPY) {
    clipboard.type = CLIPBOARD_TYPE_CUSTOM_FUNCTION;
    clipboard.data.cfn = *cfn;
  }
  else if (result == STR_PASTE) {
    *cfn = clipboard.data.cfn;
    eeDirty(EE_MODEL);
  }
  else if (result == STR_CLEAR) {
    memset(cfn, 0, sizeof(CustomFnData));
    eeDirty(EE_MODEL);
  }
  else if (result == STR_INSERT) {
    memmove(cfn+1, cfn, (NUM_CFN-sub-1)*sizeof(CustomFnData));
    memset(cfn, 0, sizeof(CustomFnData));
    eeDirty(EE_MODEL);
  }
  else if (result == STR_DELETE) {
    memmove(cfn, cfn+1, (NUM_CFN-sub-1)*sizeof(CustomFnData));
    memset(&g_model.funcSw[NUM_CFN-1], 0, sizeof(CustomFnData));
    eeDirty(EE_MODEL);
  }
}
#endif

void menuModelCustomFunctions(uint8_t event)
{
  MENU(STR_MENUCUSTOMFUNC, menuTabModel, e_CustomFunctions, NUM_CFN+1, {0, NAVIGATION_LINE_BY_LINE|4/*repeated*/});

  uint8_t y;
  uint8_t k = 0;
  int8_t  sub = m_posVert - 1;

#if defined(PCBTARANIS)
   if (sub>=0 && CURSOR_ON_LINE() && event==EVT_KEY_LONG(KEY_ENTER) && !READ_ONLY()) {
     killEvents(event);
     CustomFnData *sd = &g_model.funcSw[sub];
     if (!CFN_EMPTY(sd))
       MENU_ADD_ITEM(STR_COPY);
     if (clipboard.type == CLIPBOARD_TYPE_CUSTOM_FUNCTION)
       MENU_ADD_ITEM(STR_PASTE);
     if (!CFN_EMPTY(sd) && CFN_EMPTY(&g_model.funcSw[NUM_CFN-1]))
       MENU_ADD_ITEM(STR_INSERT);
     if (!CFN_EMPTY(sd))
       MENU_ADD_ITEM(STR_CLEAR);
     for (int i=sub+1; i<NUM_CFN; i++) {
       if (!CFN_EMPTY(&g_model.funcSw[i])) {
         MENU_ADD_ITEM(STR_DELETE);
         break;
       }
     }
     menuHandler = onCustomFunctionsMenu;
   }
#endif

  for (uint8_t i=0; i<LCD_LINES-1; i++) {
    y = 1 + (i+1)*FH;
    k = i+s_pgOfs;

#if LCD_W >= 212
    putsStrIdx(0, y, STR_CF, k+1, (sub==k && CURSOR_ON_LINE()) ? INVERS : 0);
#endif

    CustomFnData *sd = &g_model.funcSw[k];
    uint8_t func = CFN_FUNC(sd);
    for (uint8_t j=0; j<5; j++) {
      uint8_t attr = ((sub==k && m_posHorz==j) ? ((s_editMode>0) ? BLINK|INVERS : INVERS) : 0);
      uint8_t active = (attr && (s_editMode>0 || p1valdiff));
      switch (j) {
        case 0:
          putsSwitches(MODEL_CUSTOM_FUNC_1ST_COLUMN, y, CFN_SWITCH(sd), attr | ((activeFnSwitches & ((MASK_CFN_TYPE)1 << k)) ? BOLD : 0));
          if (active || AUTOSWITCH_ENTER_LONG()) CHECK_INCDEC_MODELSWITCH(event, CFN_SWITCH(sd), SWSRC_FIRST, SWSRC_LAST, isSwitchAvailableInCustomFunctions);
          break;

        case 1:
          if (CFN_SWITCH(sd)) {
            lcd_putsiAtt(MODEL_CUSTOM_FUNC_2ND_COLUMN, y, STR_VFSWFUNC, func, attr);
            if (active) {
#if defined(CPUARM)
              CFN_FUNC(sd) = checkIncDec(event, CFN_FUNC(sd), 0, FUNC_MAX-1, EE_MODEL, isAssignableFunctionAvailable);
#else
              CHECK_INCDEC_MODELVAR_ZERO(event, CFN_FUNC(sd), FUNC_MAX-1);
#endif
              if (checkIncDec_Ret) CFN_RESET(sd);
            }
          }
          else {
            j = 4; // skip other fields
            if (sub==k && m_posHorz > 0) {
              REPEAT_LAST_CURSOR_MOVE();
            }
          }
          break;

        case 2:
        {
          int8_t maxParam = NUM_CHNOUT-1;
#if defined(OVERRIDE_CHANNEL_FUNCTION)
          if (func == FUNC_OVERRIDE_CHANNEL) {
            putsChn(lcdNextPos, y, CFN_CH_INDEX(sd)+1, attr);
          }
          else
#endif
          if (func == FUNC_TRAINER) {
            maxParam = 4;
#if defined(CPUARM)
            putsMixerSource(lcdNextPos, y, CFN_CH_INDEX(sd)==0 ? 0 : MIXSRC_Rud+CFN_CH_INDEX(sd)-1, attr);
#else
            putsMixerSource(lcdNextPos, y, MIXSRC_Rud+CFN_CH_INDEX(sd)-1, attr);
#endif
          }
#if defined(GVARS)
          else if (func == FUNC_ADJUST_GVAR) {
            maxParam = MAX_GVARS-1;
            putsStrIdx(lcdNextPos, y, STR_GV, CFN_GVAR_INDEX(sd)+1, attr);
            if (active) CHECK_INCDEC_MODELVAR_ZERO(event, CFN_GVAR_INDEX(sd), maxParam);
            break;
          }
#endif
#if defined(CPUARM)
          else if (func == FUNC_SET_TIMER) {
            maxParam = 1;
            putsStrIdx(lcdNextPos, y, STR_TIMER, CFN_TIMER_INDEX(sd)+1, attr);
            if (active) CHECK_INCDEC_MODELVAR_ZERO(event, CFN_TIMER_INDEX(sd), maxParam);
            break;
          }
#endif
          else if (attr) {
            REPEAT_LAST_CURSOR_MOVE();
          }
          if (active) CHECK_INCDEC_MODELVAR_ZERO(event, CFN_CH_INDEX(sd), maxParam);
          break;
        }

        case 3:
        {
          INCDEC_DECLARE_VARS();
          int16_t val_displayed = CFN_PARAM(sd);
#if defined(CPUARM)
          int16_t val_min = 0;
          int16_t val_max = 255;
#else
          int8_t val_min = 0;
          uint8_t val_max = 255;
#endif
          if (func == FUNC_RESET) {
            val_max = FUNC_RESET_PARAM_LAST;
            lcd_putsiAtt(MODEL_CUSTOM_FUNC_3RD_COLUMN, y, STR_VFSWRESET, CFN_PARAM(sd), attr);
          }
#if defined(OVERRIDE_CHANNEL_FUNCTION)
          else if (func == FUNC_OVERRIDE_CHANNEL) {
#if !defined(CPUARM)
            val_displayed = (int8_t)CFN_PARAM(sd);
#endif
            val_min = -LIMIT_EXT_PERCENT; val_max = +LIMIT_EXT_PERCENT;
            lcd_outdezAtt(MODEL_CUSTOM_FUNC_3RD_COLUMN, y, val_displayed, attr|LEFT);
          }
#endif
#if defined(CPUARM)
          else if (func == FUNC_SET_TIMER) {
            val_max = 59*60+59;
            putsTimer(MODEL_CUSTOM_FUNC_3RD_COLUMN, y, val_displayed, attr|LEFT, attr);
          }
#endif
#if defined(AUDIO)
          else if (func == FUNC_PLAY_SOUND) {
            val_max = AU_FRSKY_LAST-AU_FRSKY_FIRST-1;
            lcd_putsiAtt(MODEL_CUSTOM_FUNC_3RD_COLUMN, y, STR_FUNCSOUNDS, val_displayed, attr);
          }
#endif
#if defined(HAPTIC)
          else if (func == FUNC_HAPTIC) {
            val_max = 3;
            lcd_outdezAtt(MODEL_CUSTOM_FUNC_3RD_COLUMN, y, val_displayed, attr|LEFT);
          }
#endif
#if defined(CPUARM) && defined(SDCARD)
          else if (func == FUNC_PLAY_TRACK || func == FUNC_BACKGND_MUSIC || func == FUNC_PLAY_SCRIPT) {
#if LCD_W >= 212
            xcoord_t x = MODEL_CUSTOM_FUNC_3RD_COLUMN;
#else
            xcoord_t x = (func == FUNC_PLAY_TRACK ? MODEL_CUSTOM_FUNC_2ND_COLUMN + FW + FW*strlen(TR_PLAY_TRACK) : MODEL_CUSTOM_FUNC_3RD_COLUMN);
#endif
            if (ZEXIST(sd->play.name))
              lcd_putsnAtt(x, y, sd->play.name, sizeof(sd->play.name), attr);
            else
              lcd_putsiAtt(x, y, STR_VCSWFUNC, 0, attr);
            if (active && event==EVT_KEY_BREAK(KEY_ENTER)) {
              s_editMode = 0;
              char directory[256];
              if (func==FUNC_PLAY_SCRIPT) {
                strcpy(directory, SCRIPTS_FUNCS_PATH);
              }
              else {
                strcpy(directory, SOUNDS_PATH);
                strncpy(directory+SOUNDS_PATH_LNG_OFS, currentLanguagePack->id, 2);
              }
              if (listSdFiles(directory, func==FUNC_PLAY_SCRIPT ? SCRIPTS_EXT : SOUNDS_EXT, sizeof(sd->play.name), sd->play.name)) {
                menuHandler = onCustomFunctionsFileSelectionMenu;
              }
              else {
                POPUP_WARNING(func==FUNC_PLAY_SCRIPT ? STR_NO_SCRIPTS_ON_SD : STR_NO_SOUNDS_ON_SD);
                s_menu_flags = 0;
              }
            }
            break;
          }
          else if (func == FUNC_PLAY_VALUE) {
            val_max = MIXSRC_FIRST_TELEM + TELEM_DISPLAY_MAX - 1;
            putsMixerSource(MODEL_CUSTOM_FUNC_3RD_COLUMN, y, val_displayed, attr);
            INCDEC_ENABLE_CHECK(isSourceAvailable);
          }
#endif
#if defined(CPUARM)
          else if (func == FUNC_VOLUME) {
            val_max = MIXSRC_LAST_CH;
            putsMixerSource(MODEL_CUSTOM_FUNC_3RD_COLUMN, y, val_displayed, attr);
            INCDEC_SET_FLAG(INCDEC_SOURCE);
            INCDEC_ENABLE_CHECK(isSourceAvailable);
          }
#elif defined(VOICE)
          else if (func == FUNC_PLAY_TRACK) {
#if defined(GVARS)
            if (attr && event==EVT_KEY_LONG(KEY_ENTER)) {
              killEvents(event);
              s_editMode = !s_editMode;
              active = true;
              val_displayed = (val_displayed > 250 ? 0 : 251);
            }
            if (val_displayed > 250) {
              putsStrIdx(MODEL_CUSTOM_FUNC_3RD_COLUMN, y, STR_GV, val_displayed-250, attr);
            }
            else {
              lcd_outdezAtt(MODEL_CUSTOM_FUNC_3RD_COLUMN, y, val_displayed+PROMPT_CUSTOM_BASE, attr|LEFT);
            }
#else
            lcd_outdezAtt(MODEL_CUSTOM_FUNC_3RD_COLUMN, y, val_displayed+PROMPT_CUSTOM_BASE, attr|LEFT);
#endif
          }
          else if (func == FUNC_PLAY_BOTH) {
            lcd_putcAtt(MODEL_CUSTOM_FUNC_3RD_COLUMN+3*FWNUM, y, '|', attr);
            lcd_outdezAtt(MODEL_CUSTOM_FUNC_3RD_COLUMN+3*FWNUM, y, val_displayed+PROMPT_CUSTOM_BASE, attr);
            lcd_outdezAtt(MODEL_CUSTOM_FUNC_3RD_COLUMN+2+3*FWNUM, y, (val_displayed+PROMPT_CUSTOM_BASE+1)%10, attr|LEFT);
          }
          else if (func == FUNC_PLAY_VALUE) {
            val_max = MIXSRC_FIRST_TELEM + TELEM_DISPLAY_MAX - 1;
            putsMixerSource(MODEL_CUSTOM_FUNC_3RD_COLUMN, y, val_displayed, attr);
            INCDEC_ENABLE_CHECK(isSourceAvailable);
          }
#endif
#if defined(SDCARD)
          else if (func == FUNC_LOGS) {
            if (val_displayed) {
              lcd_outdezAtt(MODEL_CUSTOM_FUNC_3RD_COLUMN, y, val_displayed, attr|PREC1|LEFT);
              lcd_putc(lcdLastPos, y, 's');
            }
            else {
              lcd_putsiAtt(MODEL_CUSTOM_FUNC_3RD_COLUMN, y, STR_MMMINV, 0, attr);
            }
          }
#endif
#if defined(PCBTARANIS) && defined(REVPLUS)
          else if (func == FUNC_BACKLIGHT) {
            displaySlider(MODEL_CUSTOM_FUNC_3RD_COLUMN, y, CFN_PARAM(sd), 100, attr);
            INCDEC_SET_FLAG(NO_INCDEC_MARKS);
            val_min = 0;
            val_max = 100;
          }
#endif
#if defined(GVARS)
          else if (func == FUNC_ADJUST_GVAR) {
            switch (CFN_GVAR_MODE(sd)) {
              case FUNC_ADJUST_GVAR_CONSTANT:
                val_displayed = (int16_t)CFN_PARAM(sd);
                val_min = -CFN_GVAR_CST_MAX; val_max = +CFN_GVAR_CST_MAX;
                lcd_outdezAtt(MODEL_CUSTOM_FUNC_3RD_COLUMN, y, val_displayed, attr|LEFT);
                break;
              case FUNC_ADJUST_GVAR_SOURCE:
                val_max = MIXSRC_LAST_CH;
                putsMixerSource(MODEL_CUSTOM_FUNC_3RD_COLUMN, y, val_displayed, attr);
                INCDEC_SET_FLAG(INCDEC_SOURCE);
                INCDEC_ENABLE_CHECK(isSourceAvailable);
                break;
              case FUNC_ADJUST_GVAR_GVAR:
                val_max = MAX_GVARS-1;
                putsStrIdx(MODEL_CUSTOM_FUNC_3RD_COLUMN, y, STR_GV, val_displayed+1, attr);
                break;
              default: // FUNC_ADJUST_GVAR_INC
                val_max = 1;
                lcd_putsiAtt(MODEL_CUSTOM_FUNC_3RD_COLUMN, y, PSTR("\003-=1+=1"), val_displayed, attr);
                break;
            }

            if (attr && event==EVT_KEY_LONG(KEY_ENTER)) {
              killEvents(event);
              s_editMode = !s_editMode;
              active = true;
              CFN_GVAR_MODE(sd) += 1;
#if defined(CPUARM)
              CFN_GVAR_MODE(sd) &= 0x03;
#endif
              val_displayed = 0;
            }
          }
#endif
          else if (attr) {
            REPEAT_LAST_CURSOR_MOVE();
          }

          if (active) {
            CFN_PARAM(sd) = CHECK_INCDEC_PARAM(event, val_displayed, val_min, val_max);
          }
          break;
        }

        case 4:
          if (HAS_ENABLE_PARAM(func)) {
            menu_lcd_onoff(MODEL_CUSTOM_FUNC_4TH_COLUMN_ONOFF, y, CFN_ACTIVE(sd), attr);
            if (active) CHECK_INCDEC_MODELVAR_ZERO(event, CFN_ACTIVE(sd), 1);
          }
          else if (HAS_REPEAT_PARAM(func)) {
            if (CFN_PLAY_REPEAT(sd) == 0) {
#if LCD_W >= 212
              lcd_putsAtt(MODEL_CUSTOM_FUNC_4TH_COLUMN+2, y, "1x", attr);
#else
              lcd_putcAtt(MODEL_CUSTOM_FUNC_4TH_COLUMN_ONOFF+3, y, '-', attr);
#endif
            }
#if defined(CPUARM)
            else if (CFN_PLAY_REPEAT(sd) == CFN_PLAY_REPEAT_NOSTART) {
#if LCD_W >= 212
              lcd_putcAtt(MODEL_CUSTOM_FUNC_4TH_COLUMN-1, y, '!', attr);
              lcd_putsAtt(MODEL_CUSTOM_FUNC_4TH_COLUMN+2, y, "1x", attr);
#else
              lcd_putsAtt(MODEL_CUSTOM_FUNC_4TH_COLUMN_ONOFF, y, "!-", attr);
#endif
            }
#endif
            else {
              lcd_outdezAtt(MODEL_CUSTOM_FUNC_4TH_COLUMN+2+FW, y, CFN_PLAY_REPEAT(sd)*CFN_PLAY_REPEAT_MUL, attr);
#if LCD_W >= 212
              lcd_putcAtt(MODEL_CUSTOM_FUNC_4TH_COLUMN+2+FW, y, 's', attr);
#endif
            }
#if defined(CPUARM)
            if (active) CFN_PLAY_REPEAT(sd) = checkIncDecModel(event, CFN_PLAY_REPEAT(sd)==CFN_PLAY_REPEAT_NOSTART?-1:CFN_PLAY_REPEAT(sd), -1, 60/CFN_PLAY_REPEAT_MUL);
#else
            if (active) CHECK_INCDEC_MODELVAR_ZERO(event, CFN_PLAY_REPEAT(sd), 60/CFN_PLAY_REPEAT_MUL);
#endif
          }
          else if (attr) {
            REPEAT_LAST_CURSOR_MOVE();
          }
          break;
      }
    }
  }
}

#if defined(LUA_MODEL_SCRIPTS)
void onModelCustomScriptMenu(const char *result)
{
  ScriptData &sd = g_model.scriptsData[s_currIdx];

  if (result == STR_UPDATE_LIST) {
    if (!listSdFiles(SCRIPTS_MIXES_PATH, SCRIPTS_EXT, sizeof(sd.file), NULL)) {
      POPUP_WARNING(STR_NO_SCRIPTS_ON_SD);
      s_menu_flags = 0;
    }
  }
  else {
    // The user choosed a lua file in the list
    copySelection(sd.file, result, sizeof(sd.file));
    memset(sd.inputs, 0, sizeof(sd.inputs));
    eeDirty(EE_MODEL);
    LUA_LOAD_MODEL_SCRIPT(s_currIdx);
  }
}

enum menuModelCustomScriptItems {
  ITEM_MODEL_CUSTOMSCRIPT_FILE,
  ITEM_MODEL_CUSTOMSCRIPT_NAME,
  ITEM_MODEL_CUSTOMSCRIPT_PARAMS_LABEL,
};

#define SCRIPT_ONE_2ND_COLUMN_POS  (12*FW)
#define SCRIPT_ONE_3RD_COLUMN_POS  (23*FW)

void menuModelCustomScriptOne(uint8_t event)
{
  TITLE(STR_MENUCUSTOMSCRIPT);

  ScriptData &sd = g_model.scriptsData[s_currIdx];

  putsStrIdx(lcdLastPos+FW, 0, "LUA", s_currIdx+1, 0);

  SUBMENU_NOTITLE(3+scriptInputsOutputs[s_currIdx].inputsCount, { 0, 0, LABEL(inputs), 0/*repeated*/ });

  int8_t sub = m_posVert;

  for (uint8_t k=0; k<LCD_LINES-1; k++) {
    uint8_t y = 1 + (k+1)*FH;
    uint8_t i = k + s_pgOfs;
    uint8_t attr = (sub==i ? (s_editMode>0 ? BLINK|INVERS : INVERS) : 0);

    if (i == ITEM_MODEL_CUSTOMSCRIPT_FILE) {
      lcd_putsLeft(y, STR_SCRIPT);
      if (ZEXIST(sd.file))
        lcd_putsnAtt(SCRIPT_ONE_2ND_COLUMN_POS, y, sd.file, sizeof(sd.file), attr);
      else
        lcd_putsiAtt(SCRIPT_ONE_2ND_COLUMN_POS, y, STR_VCSWFUNC, 0, attr);
      if (attr && event==EVT_KEY_BREAK(KEY_ENTER) && !READ_ONLY()) {
        s_editMode = 0;
        if (listSdFiles(SCRIPTS_MIXES_PATH, SCRIPTS_EXT, sizeof(sd.file), sd.file, LIST_NONE_SD_FILE)) {
          menuHandler = onModelCustomScriptMenu;
        }
        else {
          POPUP_WARNING(STR_NO_SCRIPTS_ON_SD);
          s_menu_flags = 0;
        }
      }
    }
    else if (i == ITEM_MODEL_CUSTOMSCRIPT_NAME) {
      lcd_putsLeft(y, TR_NAME);
      editName(SCRIPT_ONE_2ND_COLUMN_POS, y, sd.name, sizeof(sd.name), event, attr);
    }
    else if (i == ITEM_MODEL_CUSTOMSCRIPT_PARAMS_LABEL) {
      lcd_putsLeft(y, STR_INPUTS);
    }
    else if (i <= ITEM_MODEL_CUSTOMSCRIPT_PARAMS_LABEL+scriptInputsOutputs[s_currIdx].inputsCount) {
      int inputIdx = i-ITEM_MODEL_CUSTOMSCRIPT_PARAMS_LABEL-1;
      lcd_putsnAtt(INDENT_WIDTH, y, scriptInputsOutputs[s_currIdx].inputs[inputIdx].name, 10, 0);
      if (scriptInputsOutputs[s_currIdx].inputs[inputIdx].type == 0) {
        lcd_outdezAtt(SCRIPT_ONE_2ND_COLUMN_POS, y, g_model.scriptsData[s_currIdx].inputs[inputIdx]+scriptInputsOutputs[s_currIdx].inputs[inputIdx].def, attr|LEFT);
        if (attr) {
          CHECK_INCDEC_MODELVAR(event, g_model.scriptsData[s_currIdx].inputs[inputIdx], scriptInputsOutputs[s_currIdx].inputs[inputIdx].min-scriptInputsOutputs[s_currIdx].inputs[inputIdx].def, scriptInputsOutputs[s_currIdx].inputs[inputIdx].max-scriptInputsOutputs[s_currIdx].inputs[inputIdx].def);
        }
      }
      else {
        putsMixerSource(SCRIPT_ONE_2ND_COLUMN_POS, y, g_model.scriptsData[s_currIdx].inputs[inputIdx]+scriptInputsOutputs[s_currIdx].inputs[inputIdx].def, attr);
        if (attr) {
          uint8_t *source = (uint8_t *)&g_model.scriptsData[s_currIdx].inputs[inputIdx];
          CHECK_INCDEC_MODELSOURCE(event, *source, scriptInputsOutputs[s_currIdx].inputs[inputIdx].min-scriptInputsOutputs[s_currIdx].inputs[inputIdx].def, scriptInputsOutputs[s_currIdx].inputs[inputIdx].max-scriptInputsOutputs[s_currIdx].inputs[inputIdx].def);
        }
      }
    }
  }

  if (scriptInputsOutputs[s_currIdx].outputsCount > 0) {
    lcd_vline(SCRIPT_ONE_3RD_COLUMN_POS-4, FH+1, LCD_H-FH-1);
    lcd_puts(SCRIPT_ONE_3RD_COLUMN_POS, FH+1, STR_OUTPUTS);

    for (int i=0; i<scriptInputsOutputs[s_currIdx].outputsCount; i++) {
      putsMixerSource(SCRIPT_ONE_3RD_COLUMN_POS+INDENT_WIDTH, FH+1+FH+i*FH, MIXSRC_FIRST_LUA+(s_currIdx*MAX_SCRIPT_OUTPUTS)+i, 0);
      lcd_outdezNAtt(SCRIPT_ONE_3RD_COLUMN_POS+11*FW+3, FH+1+FH+i*FH, calcRESXto1000(scriptInputsOutputs[s_currIdx].outputs[i].value), PREC1);
    }
  }
}

void menuModelCustomScripts(uint8_t event)
{
  lcd_outdezAtt(19*FW, 0, luaGetMemUsed(), 0);
  lcd_puts(19*FW+1, 0, STR_BYTES);

  MENU(STR_MENUCUSTOMSCRIPTS, menuTabModel, e_CustomScripts, MAX_SCRIPTS+1, {0, NAVIGATION_LINE_BY_LINE|3/*repeated*/});

  uint8_t y;
  int8_t  sub = m_posVert - 1;

  switch (event) {
#if defined(ROTARY_ENCODER_NAVIGATION)
    case EVT_ROTARY_BREAK:
#endif
#if !defined(PCBTARANIS)
    case EVT_KEY_FIRST(KEY_RIGHT):
#endif
    case EVT_KEY_FIRST(KEY_ENTER):
      if (sub >= 0) {
        s_currIdx = sub;
        pushMenu(menuModelCustomScriptOne);
      }
      break;
  }

  for (int i=0, scriptIndex=0; i<MAX_SCRIPTS; i++) {
    y = 1 + (i+1)*FH;

    ScriptData &sd = g_model.scriptsData[i];

    // LUAx header
    putsStrIdx(0, y, "LUA", i+1, sub==i ? INVERS : 0);

    // LUA script
    if (ZEXIST(sd.file)) {
      lcd_putsnAtt(5*FW, y, sd.file, sizeof(sd.file), 0);
      switch (scriptInternalData[scriptIndex].state) {
        case SCRIPT_SYNTAX_ERROR:
          lcd_puts(30*FW+2, y, "(error)");
          break;
        case SCRIPT_KILLED:
          lcd_puts(29*FW+2, y, "(killed)");
          break;
        default:
          lcd_outdezAtt(34*FW, y, luaGetCpuUsed(scriptIndex));
          lcd_putc(34*FW, y, '%');
          break;
      }
      scriptIndex++;
    }
    else {
      lcd_putsiAtt(5*FW, y, STR_VCSWFUNC, 0, 0);
    }

    // Script name
    lcd_putsnAtt(16*FW, y, sd.name, sizeof(sd.name), ZCHAR);
  }
}
#endif

enum menuModelTelemetryItems {
  CASE_CPUARM(ITEM_TELEMETRY_PROTOCOL_TYPE)
  ITEM_TELEMETRY_A1_LABEL,
  ITEM_TELEMETRY_A1_RANGE,
  ITEM_TELEMETRY_A1_OFFSET,
  ITEM_TELEMETRY_A1_ALARM1,
  ITEM_TELEMETRY_A1_ALARM2,
  ITEM_TELEMETRY_A2_LABEL,
  ITEM_TELEMETRY_A2_RANGE,
  ITEM_TELEMETRY_A2_OFFSET,
  ITEM_TELEMETRY_A2_ALARM1,
  ITEM_TELEMETRY_A2_ALARM2,
#if defined(CPUARM)
  ITEM_TELEMETRY_A3_LABEL,
  ITEM_TELEMETRY_A3_RANGE,
  ITEM_TELEMETRY_A3_OFFSET,
  ITEM_TELEMETRY_A3_ALARM1,
  ITEM_TELEMETRY_A3_ALARM2,
  ITEM_TELEMETRY_A4_LABEL,
  ITEM_TELEMETRY_A4_RANGE,
  ITEM_TELEMETRY_A4_OFFSET,
  ITEM_TELEMETRY_A4_ALARM1,
  ITEM_TELEMETRY_A4_ALARM2,
#endif
  ITEM_TELEMETRY_RSSI_LABEL,
  ITEM_TELEMETRY_RSSI_ALARM1,
  ITEM_TELEMETRY_RSSI_ALARM2,
#if defined(FRSKY_HUB) || defined(WS_HOW_HIGH)
  ITEM_TELEMETRY_USR_LABEL,
#if !defined(PCBTARANIS)
  ITEM_TELEMETRY_USR_PROTO,
#endif
  ITEM_TELEMETRY_USR_BLADES,
#endif
  ITEM_TELEMETRY_USR_VOLTAGE_SOURCE,
  ITEM_TELEMETRY_USR_CURRENT_SOURCE,
#if defined(FAS_OFFSET) || !defined(CPUM64)
  ITEM_TELEMETRY_FAS_OFFSET,
#endif
#if defined(CPUARM)
  ITEM_TELEMTETRY_PERSISTENT_MAH,
#endif
  CASE_VARIO(ITEM_TELEMETRY_VARIO_LABEL)
#if defined(VARIO)
  ITEM_TELEMETRY_VARIO_SOURCE,
#endif
  CASE_VARIO(ITEM_TELEMETRY_VARIO_RANGE)
#if defined(PCBTARANIS)
  ITEM_TELEMETRY_TOP_BAR_LABEL,
  ITEM_TELEMETRY_TOP_BAR_ALTITUDE,
#endif
  ITEM_TELEMETRY_SCREEN_LABEL1,
  ITEM_TELEMETRY_SCREEN_LINE1,
  ITEM_TELEMETRY_SCREEN_LINE2,
  ITEM_TELEMETRY_SCREEN_LINE3,
  ITEM_TELEMETRY_SCREEN_LINE4,
  ITEM_TELEMETRY_SCREEN_LABEL2,
  ITEM_TELEMETRY_SCREEN_LINE5,
  ITEM_TELEMETRY_SCREEN_LINE6,
  ITEM_TELEMETRY_SCREEN_LINE7,
  ITEM_TELEMETRY_SCREEN_LINE8,
#if defined(CPUARM)
  ITEM_TELEMETRY_SCREEN_LABEL3,
  ITEM_TELEMETRY_SCREEN_LINE9,
  ITEM_TELEMETRY_SCREEN_LINE10,
  ITEM_TELEMETRY_SCREEN_LINE11,
  ITEM_TELEMETRY_SCREEN_LINE12,
#endif
  ITEM_TELEMETRY_MAX
};

#if defined(PCBTARANIS)
  #define USRDATA_LINES (uint8_t)-1, 0,
#elif defined(FRSKY_HUB) || defined(WS_HOW_HIGH)
  #define USRDATA_LINES (uint8_t)-1, 0, 0,
#else
  #define USRDATA_LINES
#endif

#if defined(FRSKY)
#if LCD_W >= 212
  #define TELEM_COL1        (1*FW)
  #define TELEM_COL2        (16*FW)
  #define TELEM_COL3        (28*FW)
  #define TELEM_BARS_COLMIN (3*FW+56)
  #define TELEM_BARS_COLMAX (20*FW-3)
  #define TELEM_SCRTYPE_COL (10*FW)
#else
  #define TELEM_COL1        INDENT_WIDTH
  #if defined(TRANSLATIONS_FR) || defined(TRANSLATIONS_CZ)
    #define TELEM_COL2      (9*FW)
  #else
    #define TELEM_COL2      (8*FW)
  #endif
  #define TELEM_BARS_COLMIN (56-3*FW)
  #define TELEM_BARS_COLMAX (14*FW-3)
  #define TELEM_SCRTYPE_COL (10*FW)
#endif

#if defined(PCBTARANIS)
  #define CHANNEL_ROWS      LABEL(CHANNEL), 1, 0, 0, 0
  #define RSSI_ROWS         LABEL(RSSI), 0, 0
#else
  #define CHANNEL_ROWS      LABEL(CHANNEL), 1, 0, 2, 2
  #define RSSI_ROWS         LABEL(RSSI), 1, 1
#endif

#if defined(GAUGES)
  #define SCREEN_TYPE_ROWS  0
#else
  #define SCREEN_TYPE_ROWS  LABEL(SCREEN)
#endif

#if defined(PCBSTD)
  #define VARIO_RANGE_ROWS  1
#else
  #define VARIO_RANGE_ROWS  3
#endif

#if defined(FAS_OFFSET) || !defined(CPUM64)
  #define IF_FAS_OFFSET(x)  x,
#else
  #define IF_FAS_OFFSET(x) 
#endif

#if defined(PCBTARANIS)
  #define TELEMETRY_TYPE_ROWS  (g_model.moduleData[INTERNAL_MODULE].rfProtocol == RF_PROTO_OFF && g_model.externalModule == MODULE_TYPE_PPM) ? (uint8_t)0 : HIDDEN_ROW,
#elif defined(CPUARM)
  #define TELEMETRY_TYPE_ROWS  0,
#else
  #define TELEMETRY_TYPE_ROWS
#endif

void menuModelTelemetry(uint8_t event)
{
  MENU(STR_MENUTELEMETRY, menuTabModel, e_Telemetry, ITEM_TELEMETRY_MAX+1, {0, TELEMETRY_TYPE_ROWS CHANNEL_ROWS, CHANNEL_ROWS, CASE_CPUARM(CHANNEL_ROWS) CASE_CPUARM(CHANNEL_ROWS) RSSI_ROWS, USRDATA_LINES 0, 0, IF_FAS_OFFSET(0) CASE_CPUARM(0) CASE_VARIO(LABEL(Vario)) CASE_VARIO(0) CASE_VARIO(VARIO_RANGE_ROWS) CASE_PCBTARANIS(LABEL(TopBar)) CASE_PCBTARANIS(0) SCREEN_TYPE_ROWS, 2, 2, 2, 2, SCREEN_TYPE_ROWS, 2, 2, 2, 2, CASE_CPUARM(SCREEN_TYPE_ROWS) CASE_CPUARM(2) CASE_CPUARM(2) CASE_CPUARM(2) CASE_CPUARM(2)});

  uint8_t sub = m_posVert - 1;

#if !defined(PCBTARANIS)
  switch (event) {
    case EVT_KEY_BREAK(KEY_DOWN):
    case EVT_KEY_BREAK(KEY_UP):
    case EVT_KEY_BREAK(KEY_LEFT):
    case EVT_KEY_BREAK(KEY_RIGHT):
      if (s_editMode>0 && sub<=ITEM_TELEMETRY_RSSI_ALARM2)
        frskySendAlarms(); // update FrSky module when edit mode exited
      break;
  }
#endif

  for (uint8_t i=0; i<LCD_LINES-1; i++) {
    uint8_t y = 1 + 1*FH + i*FH;
    uint8_t k = i + s_pgOfs;
#if defined(CPUARM)
    for (int j=0; j<=k; j++) {
      if (mstate_tab[j+1] == HIDDEN_ROW)
        k++;
    }
#endif

    uint8_t blink = ((s_editMode>0) ? BLINK|INVERS : INVERS);
    uint8_t attr = (sub == k ? blink : 0);
#if defined(CPUARM)
    uint8_t ch = TELEM_ANA_A1;
    if (k >= ITEM_TELEMETRY_A4_LABEL)
      ch = TELEM_ANA_A4;
    else if (k >= ITEM_TELEMETRY_A3_LABEL)
      ch = TELEM_ANA_A3;
    else if (k >= ITEM_TELEMETRY_A2_LABEL)
      ch = TELEM_ANA_A2;
#else
    uint8_t ch = (k >= ITEM_TELEMETRY_A2_LABEL) ? TELEM_ANA_A2 : TELEM_ANA_A1;
#endif
    FrSkyChannelData & channel = g_model.frsky.channels[ch];
    uint8_t dest = TELEM_A1-1+ch;

    switch (k) {

#if defined(CPUARM)
      case ITEM_TELEMETRY_PROTOCOL_TYPE:
		#if defined(MAVLINK)
        //g_model.telemetryProtocol = selectMenuItem(TELEM_COL2, y, STR_TELEMETRY_TYPE, "\017FrSky S.PORT\0  FrSky D\0               Mavlink"), g_model.telemetryProtocol, PROTOCOL_TELEMETRY_FIRST, g_eeGeneral.uart3Mode==UART_MODE_TELEMETRY ? PROTOCOL_FRSKY_D_SECONDARY : PROTOCOL_MAVLINK attr, event);
        g_model.telemetryProtocol = selectMenuItem(TELEM_COL2, y, STR_TELEMETRY_TYPE, CASE_PCBTARANIS("\017FrSky S.PORT\0  FrSky D\0               Mavlink") CASE_PCBSKY9X("\017FrSky S.PORT\0  FrSky D\0       FrSky D (cable)") g_model.telemetryProtocol, PROTOCOL_TELEMETRY_FIRST, CASE_PCBTARANIS(g_eeGeneral.uart3Mode==UART_MODE_TELEMETRY ? PROTOCOL_FRSKY_D_SECONDARY : PROTOCOL_MAVLINK) CASE_PCBSKY9X(PROTOCOL_FRSKY_D_SECONDARY) attr, event);
		#else
        g_model.telemetryProtocol = selectMenuItem(TELEM_COL2, y, STR_TELEMETRY_TYPE, "\017FrSky S.PORT\0  FrSky D\0       FrSky D (cable)", g_model.telemetryProtocol, PROTOCOL_TELEMETRY_FIRST, CASE_PCBTARANIS(g_eeGeneral.uart3Mode==UART_MODE_TELEMETRY ? PROTOCOL_FRSKY_D_SECONDARY : PROTOCOL_FRSKY_D) CASE_PCBSKY9X(PROTOCOL_FRSKY_D_SECONDARY) attr, event);
		#endif
        break;
#endif

      case ITEM_TELEMETRY_A1_LABEL:
      case ITEM_TELEMETRY_A2_LABEL:
#if defined(CPUARM)
      case ITEM_TELEMETRY_A3_LABEL:
      case ITEM_TELEMETRY_A4_LABEL:
#endif
        lcd_putsLeft(y, STR_ACHANNEL);
        lcd_outdezAtt(2*FW, y, ch+1, 0);
        putsTelemetryChannel(TELEM_COL2+6*FW, y, dest, frskyData.analog[ch].value, LEFT);
        break;

      case ITEM_TELEMETRY_A1_RANGE:
      case ITEM_TELEMETRY_A2_RANGE:
#if defined(CPUARM)
      case ITEM_TELEMETRY_A3_RANGE:
      case ITEM_TELEMETRY_A4_RANGE:
#endif
        lcd_putsLeft(y, STR_RANGE);
        putsTelemetryChannel(TELEM_COL2, y, dest, 255-channel.offset, (m_posHorz<=0 ? attr : 0)|NO_UNIT|LEFT);
        lcd_putsiAtt(lcdLastPos, y, STR_VTELEMUNIT, channel.type, m_posHorz!=0 ? attr : 0);
        if (attr && (s_editMode>0 || p1valdiff)) {
          if (m_posHorz == 0) {
            uint16_t ratio = checkIncDec(event, channel.ratio, 0, 256, EE_MODEL);
            if (checkIncDec_Ret) {
              if (ratio == 127 && channel.multiplier > 0) {
                channel.multiplier--; channel.ratio = 255;
              }
              else if (ratio == 256) {
                if (channel.multiplier < FRSKY_MULTIPLIER_MAX) { channel.multiplier++; channel.ratio = 128; }
              }
              else {
                channel.ratio = ratio;
              }
            }
          }
          else {
            CHECK_INCDEC_MODELVAR_ZERO(event, channel.type, UNIT_A1A2_MAX);
          }
        }
        break;

      case ITEM_TELEMETRY_A1_OFFSET:
      case ITEM_TELEMETRY_A2_OFFSET:
#if defined(CPUARM)
      case ITEM_TELEMETRY_A3_OFFSET:
      case ITEM_TELEMETRY_A4_OFFSET:
#endif
        lcd_putsLeft(y, STR_OFFSET);
        putsTelemetryChannel(TELEM_COL2, y, dest, 0, LEFT|attr);
        if (attr) channel.offset = checkIncDec(event, channel.offset, -256, 256, EE_MODEL);
        break;

      case ITEM_TELEMETRY_A1_ALARM1:
      case ITEM_TELEMETRY_A1_ALARM2:
      case ITEM_TELEMETRY_A2_ALARM1:
      case ITEM_TELEMETRY_A2_ALARM2:
#if defined(CPUARM)
      case ITEM_TELEMETRY_A3_ALARM1:
      case ITEM_TELEMETRY_A3_ALARM2:
      case ITEM_TELEMETRY_A4_ALARM1:
      case ITEM_TELEMETRY_A4_ALARM2:
#endif
      {
#if defined(CPUARM)
        uint8_t alarm = ((k==ITEM_TELEMETRY_A1_ALARM1 || k==ITEM_TELEMETRY_A2_ALARM1 || k==ITEM_TELEMETRY_A3_ALARM1 || k==ITEM_TELEMETRY_A4_ALARM1) ? 0 : 1);
#else
        uint8_t alarm = ((k==ITEM_TELEMETRY_A1_ALARM1 || k==ITEM_TELEMETRY_A2_ALARM1) ? 0 : 1);
#endif
#if defined(PCBTARANIS)
        lcd_putsLeft(y, (alarm==0 ? STR_LOWALARM : STR_CRITICALALARM));
        putsTelemetryChannel(TELEM_COL2, y, dest, channel.alarms_value[alarm], LEFT|attr);
        if (attr && (s_editMode>0 || p1valdiff)) {
          channel.alarms_value[alarm] = checkIncDec(event, channel.alarms_value[alarm], 0, 255, EE_MODEL);
        }
#else
        lcd_putsLeft(y, STR_ALARM);
        lcd_putsiAtt(TELEM_COL2, y, STR_VALARM, ALARM_LEVEL(ch, alarm), m_posHorz<=0 ? attr : 0);
        lcd_putsiAtt(TELEM_COL2+4*FW, y, STR_VALARMFN, ALARM_GREATER(ch, alarm), (CURSOR_ON_LINE() || m_posHorz==1) ? attr : 0);
        putsTelemetryChannel(TELEM_COL2+6*FW, y, dest, channel.alarms_value[alarm], ((CURSOR_ON_LINE() || m_posHorz==2) ? attr : 0) | LEFT);

        if (attr && (s_editMode>0 || p1valdiff)) {
          uint8_t t;
          switch (m_posHorz) {
           case 0:
             t = ALARM_LEVEL(ch, alarm);
             channel.alarms_level = (channel.alarms_level & ~(3<<(2*alarm))) + (checkIncDecModel(event, t, 0, 3) << (2*alarm));
             break;
           case 1:
             t = ALARM_GREATER(ch, alarm);
             if (t != checkIncDecModel(event, t, 0, 1)) {
               channel.alarms_greater ^= (1 << alarm);
               frskySendAlarms();
             }
             break;
           case 2:
             channel.alarms_value[alarm] = checkIncDec(event, channel.alarms_value[alarm], 0, 255, EE_MODEL);
             break;
          }
        }
#endif
        break;
      }

      case ITEM_TELEMETRY_RSSI_LABEL:
        lcd_putsLeft(y, PSTR("RSSI"));
        break;

      case ITEM_TELEMETRY_RSSI_ALARM1:
      case ITEM_TELEMETRY_RSSI_ALARM2: {
        uint8_t alarm = k-ITEM_TELEMETRY_RSSI_ALARM1;
#if defined(PCBTARANIS)
        lcd_putsLeft(y, (alarm==0 ? STR_LOWALARM : STR_CRITICALALARM));
        lcd_outdezNAtt(TELEM_COL2, y, getRssiAlarmValue(alarm), LEFT|attr, 3);
        if (attr && (s_editMode>0 || p1valdiff)) {
          CHECK_INCDEC_MODELVAR(event, g_model.frsky.rssiAlarms[alarm].value, -30, 30);
        }
#else
        lcd_putsLeft(y, STR_ALARM);
        lcd_putsiAtt(TELEM_COL2, y, STR_VALARM, ((2+alarm+g_model.frsky.rssiAlarms[alarm].level)%4), m_posHorz<=0 ? attr : 0);
        lcd_putc(TELEM_COL2+4*FW, y, '<');
        lcd_outdezNAtt(TELEM_COL2+6*FW, y, getRssiAlarmValue(alarm), LEFT|(m_posHorz!=0 ? attr : 0), 3);

        if (attr && (s_editMode>0 || p1valdiff)) {
          switch (m_posHorz) {
            case 0:
              CHECK_INCDEC_MODELVAR(event, g_model.frsky.rssiAlarms[alarm].level, -3, 2); // circular (saves flash)
              break;
            case 1:
              CHECK_INCDEC_MODELVAR(event, g_model.frsky.rssiAlarms[alarm].value, -30, 30);
              break;
          }
        }
#endif
        break;
      }

#if defined(FRSKY_HUB) || defined(WS_HOW_HIGH)
      case ITEM_TELEMETRY_USR_LABEL:
        lcd_putsLeft(y, STR_USRDATA);
        break;

#if !defined(PCBTARANIS)
      case ITEM_TELEMETRY_USR_PROTO:
        lcd_putsLeft(y, STR_PROTO);
        lcd_putsiAtt(TELEM_COL2, y, STR_VTELPROTO, g_model.frsky.usrProto, attr);
        if (attr) CHECK_INCDEC_MODELVAR_ZERO(event, g_model.frsky.usrProto, USR_PROTO_LAST);
        break;
#endif

      case ITEM_TELEMETRY_USR_BLADES:
        lcd_putsLeft(y, STR_BLADES);
#if defined(CPUARM)
        lcd_outdezAtt(TELEM_COL2, y, 2+g_model.frsky.blades, attr|LEFT);
        if (attr) CHECK_INCDEC_MODELVAR(event, g_model.frsky.blades, MIN_BLADES, MAX_BLADES);
#else
        lcd_outdezAtt(TELEM_COL2+FWNUM, y, 2+g_model.frsky.blades, attr);
        if (attr) CHECK_INCDEC_MODELVAR_ZERO(event, g_model.frsky.blades, MAX_BLADES);
#endif
        break;
#endif

      case ITEM_TELEMETRY_USR_VOLTAGE_SOURCE:
        lcd_putsLeft(y, STR_VOLTAGE);
#if defined(CPUARM)
        lcd_putsiAtt(TELEM_COL2, y, STR_VOLTSRC, g_model.frsky.voltsSource, attr);
#else
        lcd_putsiAtt(TELEM_COL2, y, STR_AMPSRC, g_model.frsky.voltsSource+1, attr);
#endif
        if (attr) CHECK_INCDEC_MODELVAR_ZERO(event, g_model.frsky.voltsSource, FRSKY_VOLTS_SOURCE_LAST);
        break;

      case ITEM_TELEMETRY_USR_CURRENT_SOURCE:
        lcd_putsLeft(y, STR_CURRENT);
        lcd_putsiAtt(TELEM_COL2, y, STR_AMPSRC, g_model.frsky.currentSource, attr);
        if (attr) CHECK_INCDEC_MODELVAR_ZERO(event, g_model.frsky.currentSource, FRSKY_CURRENT_SOURCE_LAST);
        break;
        
#if defined(FAS_OFFSET) || !defined(CPUM64)
      case ITEM_TELEMETRY_FAS_OFFSET:
      	lcd_putsLeft(y, STR_FAS_OFFSET);
      	lcd_outdezAtt(TELEM_COL2, y, g_model.frsky.fasOffset, attr|LEFT|PREC1);
        lcd_outdezAtt(TELEM_COL2+6*FW, y, frskyData.hub.current, LEFT|PREC1);
        lcd_putc(TELEM_COL2+8*FW, y, 'A');
      	if (attr) g_model.frsky.fasOffset = checkIncDec(event, g_model.frsky.fasOffset, -120, 120, EE_MODEL);
        break;
#endif

#if defined(CPUARM)
      case ITEM_TELEMTETRY_PERSISTENT_MAH:
        g_model.frsky.mAhPersistent = onoffMenuItem(g_model.frsky.mAhPersistent, TELEM_COL2, y, STR_PERSISTENT_MAH, attr, event);
        break;       
#endif

#if defined(VARIO)
      case ITEM_TELEMETRY_VARIO_LABEL:
        lcd_putsLeft(y, STR_VARIO);
        break;

      case ITEM_TELEMETRY_VARIO_SOURCE:
        lcd_putsLeft(y, STR_SOURCE);
        lcd_putsiAtt(TELEM_COL2, y, STR_VARIOSRC, g_model.frsky.varioSource, attr);
        if (attr) CHECK_INCDEC_MODELVAR(event, g_model.frsky.varioSource, 0, VARIO_SOURCE_LAST);
        break;

      case ITEM_TELEMETRY_VARIO_RANGE:
        lcd_putsLeft(y, STR_LIMIT);
#if defined(PCBSTD)
        lcd_outdezAtt(TELEM_COL2, y, 5+g_model.frsky.varioCenterMax, (m_posHorz==0 ? attr : 0)|PREC1|LEFT);
        lcd_outdezAtt(TELEM_COL2+8*FW, y, 10+g_model.frsky.varioMax, (m_posHorz==1 ? attr : 0));
        if (attr && (s_editMode>0 || p1valdiff)) {
          switch (m_posHorz) {
            case 0:
              CHECK_INCDEC_MODELVAR(event, g_model.frsky.varioCenterMax, -15, +15);
              break;
            case 1:
              CHECK_INCDEC_MODELVAR(event, g_model.frsky.varioMax, -7, 7);
              break;
          }
        }
#else
        lcd_outdezAtt(TELEM_COL2, y, -10+g_model.frsky.varioMin, (m_posHorz<=0 ? attr : 0)|LEFT);
        lcd_outdezAtt(TELEM_COL2+7*FW-2, y, -5+g_model.frsky.varioCenterMin, ((CURSOR_ON_LINE() || m_posHorz==1) ? attr : 0)|PREC1);
        lcd_outdezAtt(TELEM_COL2+10*FW, y, 5+g_model.frsky.varioCenterMax, ((CURSOR_ON_LINE() || m_posHorz==2) ? attr : 0)|PREC1);
        lcd_outdezAtt(TELEM_COL2+13*FW+2, y, 10+g_model.frsky.varioMax, ((CURSOR_ON_LINE() || m_posHorz==3) ? attr : 0));
        if (attr && (s_editMode>0 || p1valdiff)) {
          switch (m_posHorz) {
            case 0:
              CHECK_INCDEC_MODELVAR(event, g_model.frsky.varioMin, -7, 7);
              break;
            case 1:
              CHECK_INCDEC_MODELVAR(event, g_model.frsky.varioCenterMin, -16, 5+min<int8_t>(10, g_model.frsky.varioCenterMax+5));
              break;
            case 2:
              CHECK_INCDEC_MODELVAR(event, g_model.frsky.varioCenterMax, -5+max<int8_t>(-10, g_model.frsky.varioCenterMin-5), +15);
              break;
            case 3:
              CHECK_INCDEC_MODELVAR(event, g_model.frsky.varioMax, -7, 7);
              break;
          }
        }
#endif
        break;
#endif

#if defined(PCBTARANIS)
      case ITEM_TELEMETRY_TOP_BAR_LABEL:
        lcd_putsLeft(y, STR_TOP_BAR);
        break;

      case ITEM_TELEMETRY_TOP_BAR_ALTITUDE:
        g_model.frsky.altitudeDisplayed = onoffMenuItem(g_model.frsky.altitudeDisplayed, TELEM_COL2, y, STR_ALTITUDE, attr, event);
        break;
#endif

      case ITEM_TELEMETRY_SCREEN_LABEL1:
      case ITEM_TELEMETRY_SCREEN_LABEL2:
#if defined(CPUARM)
      case ITEM_TELEMETRY_SCREEN_LABEL3:
      {
        uint8_t screenIndex = (k < ITEM_TELEMETRY_SCREEN_LABEL2 ? 0 : (k < ITEM_TELEMETRY_SCREEN_LABEL3 ? 1 : 2));
        putsStrIdx(0*FW, y, STR_SCREEN, screenIndex+1);
#if defined(GAUGES)
        bool screenType = IS_BARS_SCREEN(screenIndex);
        if (screenType != (bool)selectMenuItem(TELEM_SCRTYPE_COL, y, PSTR(""), STR_VSCREEN, screenType, 0, 1, attr, event))
          g_model.frsky.screensType ^= (1 << screenIndex);
#endif
        break;
      }
#else
      {
        uint8_t screenIndex = (k < ITEM_TELEMETRY_SCREEN_LABEL2 ? 1 : 2);
        putsStrIdx(0*FW, y, STR_SCREEN, screenIndex);
#if defined(GAUGES)
        bool screenType = g_model.frsky.screensType & screenIndex;
        if (screenType != (bool)selectMenuItem(TELEM_SCRTYPE_COL, y, PSTR(""), STR_VSCREEN, screenType, 0, 1, attr, event))
          g_model.frsky.screensType ^= screenIndex;
#endif
        break;
      }
#endif

      case ITEM_TELEMETRY_SCREEN_LINE1:
      case ITEM_TELEMETRY_SCREEN_LINE2:
      case ITEM_TELEMETRY_SCREEN_LINE3:
      case ITEM_TELEMETRY_SCREEN_LINE4:
      case ITEM_TELEMETRY_SCREEN_LINE5:
      case ITEM_TELEMETRY_SCREEN_LINE6:
      case ITEM_TELEMETRY_SCREEN_LINE7:
      case ITEM_TELEMETRY_SCREEN_LINE8:

#if defined(CPUARM)
      case ITEM_TELEMETRY_SCREEN_LINE9:
      case ITEM_TELEMETRY_SCREEN_LINE10:
      case ITEM_TELEMETRY_SCREEN_LINE11:
      case ITEM_TELEMETRY_SCREEN_LINE12:
#endif

      {
        uint8_t screenIndex, lineIndex;
        if (k < ITEM_TELEMETRY_SCREEN_LABEL2) {
          screenIndex = 0;
          lineIndex = k-ITEM_TELEMETRY_SCREEN_LINE1;
        }
#if defined(CPUARM)
        else if (k >= ITEM_TELEMETRY_SCREEN_LABEL3) {
          screenIndex = 2;
          lineIndex = k-ITEM_TELEMETRY_SCREEN_LINE9;
        }
#endif
        else {
          screenIndex = 1;
          lineIndex = k-ITEM_TELEMETRY_SCREEN_LINE5;
        }

#if defined(GAUGES)
        if (IS_BARS_SCREEN(screenIndex)) {
          FrSkyBarData & bar = g_model.frsky.screens[screenIndex].bars[lineIndex];
          uint8_t barSource = bar.source;
          lcd_putsiAtt(TELEM_COL1, y, STR_VTELEMCHNS, barSource, m_posHorz==0 ? attr : 0);
          if (barSource) {
            putsTelemetryChannel(TELEM_BARS_COLMIN, y, barSource-1, convertBarTelemValue(barSource, bar.barMin), (m_posHorz==1 ? attr : 0) | LEFT);
            putsTelemetryChannel(TELEM_BARS_COLMAX, y, barSource-1, convertBarTelemValue(barSource, 255-bar.barMax), (m_posHorz==2 ? attr : 0) | LEFT);
          }
          else if (attr) {
            MOVE_CURSOR_FROM_HERE();
          }
          if (attr && (s_editMode>0 || p1valdiff)) {
            switch (m_posHorz) {
              case 0:
                bar.source = CHECK_INCDEC_MODELVAR_ZERO_CHECK(event, barSource, TELEM_DISPLAY_MAX, isTelemetrySourceAvailable);
                if (checkIncDec_Ret) {
                  bar.barMin = 0;
                  bar.barMax = 255 - maxBarTelemValue(bar.source);
                }
                break;
              case 1:
                bar.barMin = checkIncDec(event, bar.barMin, 0, 254-bar.barMax, EE_MODEL|NO_INCDEC_MARKS);
                break;
              case 2:
                bar.barMax = 255 - checkIncDec(event, 255-bar.barMax, bar.barMin+1, maxBarTelemValue(barSource), EE_MODEL|NO_INCDEC_MARKS);
                break;
            }
          }
        }
        else
#endif
        {
          for (uint8_t c=0; c<NUM_LINE_ITEMS; c++) {
            uint8_t cellAttr = (m_posHorz==c ? attr : 0);
            uint8_t & value = g_model.frsky.screens[screenIndex].lines[lineIndex].sources[c];
#if defined(PCBTARANIS)
            uint8_t pos[] = {TELEM_COL1, TELEM_COL2, TELEM_COL3};
#else
            uint8_t pos[] = {INDENT_WIDTH, TELEM_COL2};
#endif
            lcd_putsiAtt(pos[c], y, STR_VTELEMCHNS, value, cellAttr);
            if (cellAttr && (s_editMode>0 || p1valdiff)) {
              CHECK_INCDEC_MODELVAR_ZERO_CHECK(event, value, (lineIndex==3 && c==0) ? TELEM_STATUS_MAX : TELEM_DISPLAY_MAX, isTelemetrySourceAvailable);
            }
          }
          if (attr && m_posHorz == NUM_LINE_ITEMS) {
            REPEAT_LAST_CURSOR_MOVE();
          }
        }
        break;
      }
    }
  }
}
#endif

#if defined(TEMPLATES)
void menuModelTemplates(uint8_t event)
{
  SIMPLE_MENU(STR_MENUTEMPLATES, menuTabModel, e_Templates, 1+TMPL_COUNT);

  uint8_t sub = m_posVert - 1;

  if (sub < TMPL_COUNT) {
    if (s_warning_result) {
      s_warning_result = 0;
      applyTemplate(sub);
      AUDIO_WARNING2();
    }
    if (event==EVT_KEY_BREAK(KEY_ENTER)) {
      POPUP_CONFIRMATION(STR_VTEMPLATES+1 + (sub * LEN2_VTEMPLATES));
      s_editMode = 0;
    }
  }

  uint8_t y = 1 + 1*FH;
  uint8_t k = 0;
  for (uint8_t i=0; i<LCD_LINES-1 && k<TMPL_COUNT; i++) {
    k = i+s_pgOfs;
    lcd_outdezNAtt(3*FW, y, k, (sub==k ? INVERS : 0)|LEADING0, 2);
    lcd_putsiAtt(4*FW, y, STR_VTEMPLATES, k, (sub==k ? INVERS  : 0));
    y+=FH;
  }
}
#endif

