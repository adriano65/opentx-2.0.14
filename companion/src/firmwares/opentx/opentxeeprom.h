/*
 * Author - Bertrand Songis <bsongis@gmail.com>
 *
 * Based on th9x -> http://code.google.com/p/th9x/
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

#ifndef open9xeeprom_h
#define open9xeeprom_h

#include <inttypes.h>
#include "eeprominterface.h"
#include "eepromimportexport.h"
#include <qbytearray.h>

#define GVARS_VARIANT          0x0001
#define FRSKY_VARIANT          0x0002
#define POS3_VARIANT           0x0004
#define MAVLINK_VARIANT        0x0008
#define M128_VARIANT           0x8002

#define SIMU_STOCK_VARIANTS    (GVARS_VARIANT|FRSKY_VARIANT)
#define SIMU_M128_VARIANTS     (M128_VARIANT|SIMU_STOCK_VARIANTS)

#define O9X_MAX_TIMERS         2
#define O9X_MAX_FLIGHT_MODES         5
#define O9X_MAX_MIXERS         32
#define O9X_MAX_EXPOS          14
#define O9X_NUM_CHNOUT         16 // number of real output channels CH1-CH16
#define O9X_NUM_CSW            12 // number of custom switches
#define O9X_NUM_FSW            16 // number of functions assigned to switches
#define O9X_MAX_CURVES         8
#define O9X_NUM_POINTS         (112-O9X_MAX_CURVES)

#define O9X_ARM_MAX_FLIGHT_MODES     9
#define O9X_ARM_MAX_MIXERS     64
#define O9X_ARM_MAX_EXPOS      32
#define O9X_ARM_NUM_CHNOUT     32 // number of real output channels CH1-CH16
#define O9X_ARM_NUM_CSW        32 // number of custom switches
#define O9X_ARM_NUM_FSW        32 // number of functions assigned to switches
#define O9X_ARM_NUM_POINTS     512
#define O9X_ARM_MAX_CSFUNCOLD  13
#define O9X_ARM_MAX_CSFUNC     15

class OpenTxGeneralData: public TransformedField {
  public:
    OpenTxGeneralData(GeneralSettings & generalData, BoardEnum board, unsigned int version, unsigned int variant=0);

  protected:
    virtual void beforeExport();
    virtual void afterImport();

    StructField internalField;
    GeneralSettings & generalData;
    BoardEnum board;
    unsigned int version;
    int inputsCount;
    unsigned int chkSum;
    unsigned int potsType[4];
};

class ProtocolsConversionTable: public ConversionTable
{
  public:
    ProtocolsConversionTable(BoardEnum board)
    {
      int val = 0;
      if (IS_ARM(board)) {
        addConversion(OFF, val++);
      }
      addConversion(PPM, val++);
	  
      if (!IS_ARM(board)) {
        addConversion(PPM16, val++);
        addConversion(PPMSIM, val++);
      }
      if (IS_ARM(board)) {
        addConversion(PXX_XJT_X16, val);
        addConversion(PXX_XJT_D8, val);
        addConversion(PXX_XJT_LR12, val++);
      }
      else {
        addConversion(PXX_DJT, val++);
      }
      if (IS_ARM(board)) {
        addConversion(LP45, val);
        addConversion(DSM2, val);
        addConversion(DSMX, val++);
      }
      else {
        addConversion(LP45, val++);
        addConversion(DSM2, val++);
        addConversion(DSMX, val++);
      }
    }
};

class ThrottleSourceConversionTable: public ConversionTable {

  public:
    ThrottleSourceConversionTable(BoardEnum board, unsigned int version);
};

class ChannelsConversionTable: public ConversionTable {
  public:
    ChannelsConversionTable() {
      for (int i=4; i<=16; i+= 2)
        addConversion(i, -4+i/2);
    }
};


class OpenTxModelData: public TransformedField {
  public:
    OpenTxModelData(ModelData & modelData, BoardEnum board, unsigned int version, unsigned int variant);

    const char * getName() { return name; }

  protected:
    virtual void beforeExport();
    virtual void afterImport();

    StructField internalField;
    ModelData & modelData;
    BoardEnum board;
    unsigned int version;
    unsigned int variant;

  private:
    char name[256];
    int subprotocols[C9X_NUM_MODULES+1/*trainer*/];
    ProtocolsConversionTable protocolsConversionTable;
    ThrottleSourceConversionTable throttleSourceConversionTable;
    ChannelsConversionTable channelsConversionTable;
};

void OpenTxEepromCleanup(void);
#endif
