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
#ifndef foldedlist_h
#define foldedlist_h


#include "th9x.h"


//ch  shwDat idt shwHdr
//                 t
// 1    dat0  0    
// 2          1
// 3          1
// 4    dat1  1
//  (4) dat2  2  
//  (4) dat3  3  
//  (4) dat4  4  
// 5          5
// 6          5
// 7          5
// 8          5
typedef uint8_t ChProc(uint8_t*line, uint8_t setCh);


class FoldedList
{
public:
  static FoldedList inst;
  struct Line{
    bool   showCh:1;// show the dest chn
    bool   showDat:1;// show the data info
    bool   showHeader:1;// show the header
    uint8_t chId;    //:4  1..NUM_XCHNOUT  dst chn id             
    int8_t idt;     //:5  0..MAX_MIXERS-1  edit index into mix data tab
  };
 private:
  Line    m_lines[MAX(MAX_MIXERS+NUM_XCHNOUT,MAX_EXPOS+4)+1];
//indize:
// IDT  index into user data tab
// IFL  index into foldedlist m_lines
  uint8_t m_prepCurrCh;   //for construction init,fill,addDat
  uint8_t m_prepCurrIFL;
  uint8_t m_prepCurrIDT;  // number of lines in data tab
  ChProc* m_chProc;
  uint8_t m_numChn;

  void*   m_prepArray;    // user data-tab info
  uint8_t m_prepDimArr;   // "
  uint8_t m_prepSzeElt;   // "

  uint8_t m_iterOfsIFL;   //= 0 in EVT_ENTRY 
  uint8_t m_iterPosIFL;
  uint8_t m_iterHitIFL;
 public:
  uint8_t m_subIFL;       // save the menus sub-var firstline..nextline
  bool    m_chnNav;
 private:
  int8_t  m_subChanged;

  bool    m_isSelectedCh; // * user info after nextline
  bool    m_isSelectedDat;// *

  bool    m_listEdit;     // * user info after doEvent
  uint8_t m_currIDTOld;   // * user info for move ops
  uint8_t m_currIDT;      // * user index for move ops
  uint8_t m_editIDT;      // * user index for edit one dataset
  uint8_t m_currDestCh;   // * for init new lines
  //bool    m_currInsMode;  // * is edit one called by insert or by edit

private:
  static uint8_t*   arrayElt(uint8_t idx){return (uint8_t*)inst.m_prepArray + (uint8_t)(inst.m_prepSzeElt * idx);  }
  //static void    editModeOff()  { inst.m_listEdit=false;}
  static uint8_t  getCh(uint8_t idt);//{return inst.m_chProc(arrayElt(idt),0);}
  static void     setCh(uint8_t idt,uint8_t ch);//{inst.m_chProc(arrayElt(idt),ch);}
public:  
  static bool    listEditMode(bool val) {return inst.m_listEdit=val;}
  static bool    listEditMode() {return inst.m_listEdit;}
  static uint8_t fillLevel()    {return inst.m_prepCurrIDT;}
  static uint8_t editIDT()      {return inst.m_editIDT;}
  //  static uint8_t currIDTOld()   {return inst.m_currIDTOld;}
  static uint8_t currDestCh()   {return inst.m_currDestCh;}
  //static bool    currInsMode()  {return inst.m_currInsMode;}
  static bool    currInsMode()  {return inst.m_chnNav;}
  static bool    isSelectedCh() {return inst.m_isSelectedCh;}
  static bool    isSelectedDat(){return inst.m_isSelectedDat;}
  /// iterate one time to fill the list (init loop)
  /// init(); addDat addDat addDat ..
  static void init(void*array,uint8_t dimArr, uint8_t szeElt, ChProc* chProc,uint8_t numChn);
  static inline bool addDat(uint8_t ch, uint8_t idx);
  static void show();           //helper func for debug
  static void fill(uint8_t ch, uint8_t idt); //helper func for construction
  static uint8_t findChn(uint8_t chn);

  /// iterate one time through the filled list (show loop)
  /// with firstLine,nextLine nextLine ..
  static Line* firstLine();//int8_t sub,bool chnNav,int8_t subChanged);
  static Line* nextLine(uint8_t lines);

  static int8_t numWithHdr(){return inst.m_prepCurrIFL;};//-1 wegen header
#define FoldedListDup      1
#define FoldedListEdit     2
#define FoldedListNew      3
#define FoldedListNewEdit  4
#define FoldedListSwap     5
  static uint8_t doEvent(int8_t sub,int8_t subChanged,bool chnNav);
  static void    rmCurrLine();

};

#define FL_INST FoldedList::inst

#endif

