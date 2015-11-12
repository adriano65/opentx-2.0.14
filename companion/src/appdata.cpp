/*
 * Author - Kjell Kernen
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

#include "appdata.h"

// Global data and storage object
AppData g;

// ** CompStoreObj class********************
void CompStoreObj::clear (const QString tag1, const QString tag2, const QString tag3)
{
    QSettings settings(PRODUCT, COMPANY);
    if (tag2.isEmpty())
    {
        settings.remove(tag1);
    }
    else if (tag3.isEmpty())
    {
        settings.beginGroup(tag1);
        settings.remove(tag2);
        settings.endGroup();
    }
    else
    {
        settings.beginGroup(tag1);
        settings.beginGroup(tag2);
        settings.remove(tag3);
        settings.endGroup();
        settings.endGroup();
    }
}

void CompStoreObj::store(const QByteArray newArray, QByteArray &array, const QString tag, const QString group1, const QString group2 )
{
    QSettings settings(PRODUCT, COMPANY);
    if (!group1.isEmpty()) settings.beginGroup(group1);
    if (!group2.isEmpty()) settings.beginGroup(group2);

    settings.setValue(tag, newArray);
    array = newArray;

    if (!group1.isEmpty()) settings.endGroup();
    if (!group2.isEmpty()) settings.endGroup();
}

void CompStoreObj::store(const QStringList newSList, QStringList &stringList, const QString tag, const QString group1, const QString group2 )
{
    QSettings settings(PRODUCT, COMPANY);
    if (!group1.isEmpty()) settings.beginGroup(group1);
    if (!group2.isEmpty()) settings.beginGroup(group2);

    settings.setValue(tag, newSList);
    stringList = newSList;

    if (!group1.isEmpty()) settings.endGroup();
    if (!group2.isEmpty()) settings.endGroup();
}

void CompStoreObj::store(const QString newString, QString &string, const QString tag, const QString group1, const QString group2 )
{
    QSettings settings(PRODUCT, COMPANY);
    if (!group1.isEmpty()) settings.beginGroup(group1);
    if (!group2.isEmpty()) settings.beginGroup(group2);

    settings.setValue(tag, newString);
    string = newString;

    if (!group1.isEmpty()) settings.endGroup();
    if (!group2.isEmpty()) settings.endGroup();
}

void CompStoreObj::store(const bool newTruth, bool &truth, const QString tag, const QString group1, const QString group2 )
{
    QSettings settings(PRODUCT, COMPANY);
    if (!group1.isEmpty()) settings.beginGroup(group1);
    if (!group2.isEmpty()) settings.beginGroup(group2);

    settings.setValue(tag, newTruth);
    truth = newTruth;

    if (!group1.isEmpty()) settings.endGroup();
    if (!group2.isEmpty()) settings.endGroup();
}

void CompStoreObj::store(const int newNumber, int &number, const QString tag, const QString group1, const QString group2 )
{
    QSettings settings(PRODUCT, COMPANY);
    if (!group1.isEmpty()) settings.beginGroup(group1);
    if (!group2.isEmpty()) settings.beginGroup(group2);

    settings.setValue(tag, newNumber);
    number = newNumber;

    if (!group1.isEmpty()) settings.endGroup();
    if (!group2.isEmpty()) settings.endGroup();
}

// Retrieval functions
void CompStoreObj::retrieve( QByteArray &array, const QString tag, const QString def, const QString group1, const QString group2 )
{
    QSettings settings(PRODUCT, COMPANY);
    if (!group1.isEmpty()) settings.beginGroup(group1);
    if (!group2.isEmpty()) settings.beginGroup(group2);

    array = settings.value(tag, def).toByteArray();

    if (!group1.isEmpty()) settings.endGroup();
    if (!group2.isEmpty()) settings.endGroup();
}

void CompStoreObj::retrieve( QStringList &stringList, const QString tag, const QString def, const QString group1, const QString group2 )
{
    QSettings settings(PRODUCT, COMPANY);
    if (!group1.isEmpty()) settings.beginGroup(group1);
    if (!group2.isEmpty()) settings.beginGroup(group2);

    stringList = settings.value(tag, def).toStringList();

    if (!group1.isEmpty()) settings.endGroup();
    if (!group2.isEmpty()) settings.endGroup();
}

void CompStoreObj::retrieve( QString &string, const QString tag, const QString def, const QString group1, const QString group2 )
{
    QSettings settings(PRODUCT, COMPANY);
    if (!group1.isEmpty()) settings.beginGroup(group1);
    if (!group2.isEmpty()) settings.beginGroup(group2);

    string = settings.value(tag, def).toString();

    if (!group1.isEmpty()) settings.endGroup();
    if (!group2.isEmpty()) settings.endGroup();
}

void CompStoreObj::retrieve( bool &truth, const QString tag, const bool def, const QString group1, const QString group2 )
{
    QSettings settings(PRODUCT, COMPANY);
    if (!group1.isEmpty()) settings.beginGroup(group1);
    if (!group2.isEmpty()) settings.beginGroup(group2);

    truth = settings.value(tag, def).toBool();

    if (!group1.isEmpty()) settings.endGroup();
    if (!group2.isEmpty()) settings.endGroup();
}

void CompStoreObj::retrieve( int &number, const QString tag, const int def, const QString group1, const QString group2 )
{
    QSettings settings(PRODUCT, COMPANY);
    if (!group1.isEmpty()) settings.beginGroup(group1);
    if (!group2.isEmpty()) settings.beginGroup(group2);

    number = settings.value(tag, def).toInt();

    if (!group1.isEmpty()) settings.endGroup();
    if (!group2.isEmpty()) settings.endGroup();
}

// Retrieve and Store functions
void CompStoreObj::getset( QByteArray &array, const QString tag, const QString def, const QString group1, const QString group2 )
{
    retrieve( array, tag, def, group1, group2);
    store(array, array, tag, group1, group2);
}

void CompStoreObj::getset( QStringList &stringList, const QString tag, const QString def, const QString group1, const QString group2 )
{
    retrieve( stringList, tag, def, group1, group2);
    store(stringList, stringList, tag, group1, group2);
}

void CompStoreObj::getset( QString &string, const QString tag, const QString def, const QString group1, const QString group2 )
{
    retrieve( string, tag, def, group1, group2);
    store(string, string, tag, group1, group2);
}

void CompStoreObj::getset( bool &truth, const QString tag, const bool def, const QString group1, const QString group2 )
{
    retrieve( truth, tag, def, group1, group2);
    store(truth, truth, tag, group1, group2);
}

void CompStoreObj::getset( int &number, const QString tag, const int def, const QString group1, const QString group2 )
{
    retrieve( number, tag, def, group1, group2);
    store(number, number, tag, group1, group2);
}

// ** FwRevision class********************
int FwRevision::get( const QString fwType )
{
    QString result;
    retrieve( result, fwType, "", "FwRevisions" );
    return result.toInt();
}

void FwRevision::set( const QString fwType, const int fwRevision )
{
    QString tempString = QString("%1").arg(fwRevision);
    store( tempString, tempString, fwType, "FwRevisions" );
}

void FwRevision::remove( const QString tag )
{
    clear( "FwRevisions", tag );
}

// ** JStickData class********************
// Get declarations
int JStickData::stick_axe() { return _stickAxe; }
int JStickData::stick_min() { return _stickMin; }
int JStickData::stick_med() { return _stickMed; }
int JStickData::stick_max() { return _stickMax; }
int JStickData::stick_inv() { return _stickInv; }

// Set declarations
void JStickData::stick_axe(const int it) { store( it, _stickAxe, QString("stick%1_axe").arg(index), "JsCalibration" );}
void JStickData::stick_min(const int it) { store( it, _stickMin, QString("stick%1_min").arg(index), "JsCalibration" );}
void JStickData::stick_med(const int it) { store( it, _stickMed, QString("stick%1_med").arg(index), "JsCalibration" );}
void JStickData::stick_max(const int it) { store( it, _stickMax, QString("stick%1_max").arg(index), "JsCalibration" );}
void JStickData::stick_inv(const int it) { store( it, _stickInv, QString("stick%1_inv").arg(index), "JsCalibration" );}

// Constructor
JStickData::JStickData()
{
    index = -1;
}

void JStickData::remove()
{
    // Remove all JStickData values from settings file
    QSettings settings(PRODUCT, COMPANY);
    settings.beginGroup( "JsCalibration" );
    settings.remove( QString( "stick%1_axe").arg(index) );
    settings.remove( QString( "stick%1_min").arg(index) );
    settings.remove( QString( "stick%1_med").arg(index) );
    settings.remove( QString( "stick%1_max").arg(index) );
    settings.remove( QString( "stick%1_inv").arg(index) );
    settings.endGroup();

    // Reset all JStickData variables to initial values
    init(index);
}

bool JStickData::existsOnDisk()
{
    QSettings settings(PRODUCT, COMPANY);
    settings.beginGroup("JsCalibration");
    int axe = settings.value( QString("stick%1_axe").arg(index), -1 ).toInt();
    settings.endGroup();

    return (axe > -1);
}

void JStickData::init(int newIndex)
{
    index = newIndex;
    _stickAxe = -1;
    _stickMin = -32767;
    _stickMed = 0;
    _stickMax = 0;
    _stickInv = 0;

    // Do not write empty joystick calibrations to disk.
    if ( !existsOnDisk() )
        return;

    flush();
}

void JStickData::flush()
{
    getset( _stickAxe, QString("stick%1_axe").arg(index), -1,     "JsCalibration" );
    getset( _stickMin, QString("stick%1_min").arg(index), -32767, "JsCalibration" );
    getset( _stickMed, QString("stick%1_med").arg(index),  0,     "JsCalibration" );
    getset( _stickMax, QString("stick%1_max").arg(index),  0,     "JsCalibration" );
    getset( _stickInv, QString("stick%1_inv").arg(index),  0,     "JsCalibration" );
}

// ** Profile class********************
// Get declarations
QString Profile::fwName()        const { return _fwName;        }
QString Profile::fwType()        const { return _fwType;        }
QString Profile::name()          const { return _name;          }
QString Profile::sdPath()        const { return _sdPath;        }
QString Profile::splashFile()    const { return _splashFile;    }
bool    Profile::burnFirmware()  const { return _burnFirmware;  }
bool    Profile::renameFwFiles() const { return _renameFwFiles; }
int     Profile::channelOrder()  const { return _channelOrder;  }
int     Profile::defaultMode()   const { return _defaultMode;   }

QString Profile::beeper()        const { return _beeper;        }
QString Profile::countryCode()   const { return _countryCode;   }
QString Profile::display()       const { return _display;       }
QString Profile::haptic()        const { return _haptic;        }
QString Profile::speaker()       const { return _speaker;       }
QString Profile::stickPotCalib() const { return _stickPotCalib; }
QString Profile::timeStamp()     const { return _timeStamp;     }
QString Profile::trainerCalib()  const { return _trainerCalib;  }
int     Profile::currentCalib()  const { return _currentCalib;  }
int     Profile::gsStickMode()   const { return _gsStickMode;   }
int     Profile::ppmMultiplier() const { return _ppmMultiplier; }
int     Profile::vBatCalib()     const { return _vBatCalib;     }
int     Profile::vBatWarn()      const { return _vBatWarn;      }

// Set declarations
void Profile::name          (const QString x) { store(x, _name,          "Name"                  ,"Profiles", QString("profile%1").arg(index));}
void Profile::fwName        (const QString x) { store(x, _fwName,        "fwName"                ,"Profiles", QString("profile%1").arg(index));}
void Profile::fwType        (const QString x) { store(x, _fwType,        "fwType"                ,"Profiles", QString("profile%1").arg(index));}
void Profile::sdPath        (const QString x) { store(x, _sdPath,        "sdPath"                ,"Profiles", QString("profile%1").arg(index));}
void Profile::splashFile    (const QString x) { store(x, _splashFile,    "SplashFileName"        ,"Profiles", QString("profile%1").arg(index));}
void Profile::burnFirmware  (const bool    x) { store(x, _burnFirmware,  "burnFirmware"          ,"Profiles", QString("profile%1").arg(index));}
void Profile::renameFwFiles (const bool    x) { store(x, _renameFwFiles, "rename_firmware_files" ,"Profiles", QString("profile%1").arg(index));}
void Profile::channelOrder  (const int     x) { store(x, _channelOrder,  "default_channel_order" ,"Profiles", QString("profile%1").arg(index));}
void Profile::defaultMode   (const int     x) { store(x, _defaultMode,   "default_mode"          ,"Profiles", QString("profile%1").arg(index));}

void Profile::beeper        (const QString x) { store(x, _beeper,        "Beeper"                ,"Profiles", QString("profile%1").arg(index));}
void Profile::countryCode   (const QString x) { store(x, _countryCode,   "countryCode"           ,"Profiles", QString("profile%1").arg(index));}
void Profile::display       (const QString x) { store(x, _display,       "Display"               ,"Profiles", QString("profile%1").arg(index));}
void Profile::haptic        (const QString x) { store(x, _haptic,        "Haptic"                ,"Profiles", QString("profile%1").arg(index));}
void Profile::speaker       (const QString x) { store(x, _speaker,       "Speaker"               ,"Profiles", QString("profile%1").arg(index));}
void Profile::stickPotCalib (const QString x) { store(x, _stickPotCalib, "StickPotCalib"         ,"Profiles", QString("profile%1").arg(index));}
void Profile::timeStamp     (const QString x) { store(x, _timeStamp,     "TimeStamp"             ,"Profiles", QString("profile%1").arg(index));}
void Profile::trainerCalib  (const QString x) { store(x, _trainerCalib,  "TrainerCalib"          ,"Profiles", QString("profile%1").arg(index));}
void Profile::currentCalib  (const int     x) { store(x, _currentCalib,  "currentCalib"          ,"Profiles", QString("profile%1").arg(index));}
void Profile::gsStickMode   (const int     x) { store(x, _gsStickMode,   "GSStickMode"           ,"Profiles", QString("profile%1").arg(index));}
void Profile::ppmMultiplier (const int     x) { store(x, _ppmMultiplier, "PPM_Multiplier"        ,"Profiles", QString("profile%1").arg(index));}
void Profile::vBatCalib     (const int     x) { store(x, _vBatCalib,     "VbatCalib"             ,"Profiles", QString("profile%1").arg(index));}
void Profile::vBatWarn      (const int     x) { store(x, _vBatWarn,      "vBatWarn"              ,"Profiles", QString("profile%1").arg(index));}

// Constructor
Profile::Profile()
{
    index = -1;
}

// The default copy operator can not be used since the index variable would be destroyed 
Profile& Profile::operator=(const Profile& rhs)
{
    name         ( rhs.name()          );
    fwName       ( rhs.fwName()        );
    fwType       ( rhs.fwType()        );
    sdPath       ( rhs.sdPath()        );
    splashFile   ( rhs.splashFile()    );
    burnFirmware ( rhs.burnFirmware()  );
    renameFwFiles( rhs.renameFwFiles() );
    channelOrder ( rhs.channelOrder()  );
    defaultMode  ( rhs.defaultMode()   );
    beeper       ( rhs.beeper()        );
    countryCode  ( rhs.countryCode()   );
    display      ( rhs.display()       );
    haptic       ( rhs.haptic()        );
    speaker      ( rhs.speaker()       );
    stickPotCalib( rhs.stickPotCalib() );
    trainerCalib ( rhs.trainerCalib()  );
    currentCalib ( rhs.currentCalib()  );
    gsStickMode  ( rhs.gsStickMode()   );
    ppmMultiplier( rhs.ppmMultiplier() );
    vBatCalib    ( rhs.vBatCalib()     );
    vBatWarn     ( rhs.vBatWarn()      );

    return *this;
}

void Profile::remove()
{
    // Remove all profile values from settings file
    QSettings settings(PRODUCT, COMPANY);
    settings.beginGroup("Profiles");
    settings.remove(QString("profile%1").arg(index));
    settings.endGroup();

    // Reset all profile variables to initial values
    init(index);
}

bool Profile::existsOnDisk()
{
    QSettings settings(PRODUCT, COMPANY);
    settings.beginGroup("Profiles");
    settings.beginGroup(QString("profile%1").arg(index));
    QStringList keyList = settings.allKeys();
    settings.endGroup();
    settings.endGroup();

    return (keyList.length() > 0);
}

void Profile::initFwVariables()
{
    _beeper =        "";
    _countryCode =   "";
    _display =       "";
    _haptic =        "";
    _speaker =       "";
    _stickPotCalib = "";
    _timeStamp =     "";
    _trainerCalib =  "";

    _currentCalib =  0;
    _gsStickMode =   0;
    _ppmMultiplier = 0;
    _vBatCalib =     0;
    _vBatWarn =      0;
}

void Profile::init(int newIndex)
{
    index = newIndex;

    _fwName =        "";
    _fwType =        "";
    _name =          "";
    _sdPath =        "";
    _splashFile =    "";
    _burnFirmware =  false;
    _renameFwFiles = false;
    _channelOrder =  0;
    _defaultMode =   1;

    initFwVariables();

    // Do not write empty profiles to disk except the default (0) profile.
    if ( index > 0 && !existsOnDisk())
        return;

    flush();
}

void Profile::flush()
{
    // Load and store all variables. Use default values if setting values are missing
    getset( _fwName,        "fwName"                ,""     ,"Profiles", QString("profile%1").arg(index));
    getset( _fwType,        "fwType"                ,""     ,"Profiles", QString("profile%1").arg(index));
    getset( _name,          "Name"                  ,""     ,"Profiles", QString("profile%1").arg(index));
    getset( _sdPath,        "sdPath"                ,""     ,"Profiles", QString("profile%1").arg(index));
    getset( _splashFile,    "SplashFileName"        ,""     ,"Profiles", QString("profile%1").arg(index));
    getset( _burnFirmware,  "burnFirmware"          ,false  ,"Profiles", QString("profile%1").arg(index));
    getset( _renameFwFiles, "rename_firmware_files" ,false  ,"Profiles", QString("profile%1").arg(index));
    getset( _channelOrder,  "default_channel_order" ,0      ,"Profiles", QString("profile%1").arg(index));
    getset( _defaultMode,   "default_mode"          ,1      ,"Profiles", QString("profile%1").arg(index));

    getset( _beeper,        "Beeper"                ,""     ,"Profiles", QString("profile%1").arg(index));
    getset( _countryCode,   "countryCode"           ,""     ,"Profiles", QString("profile%1").arg(index));
    getset( _display,       "Display"               ,""     ,"Profiles", QString("profile%1").arg(index));
    getset( _haptic,        "Haptic"                ,""     ,"Profiles", QString("profile%1").arg(index));
    getset( _speaker,       "Speaker"               ,""     ,"Profiles", QString("profile%1").arg(index));
    getset( _stickPotCalib, "StickPotCalib"         ,""     ,"Profiles", QString("profile%1").arg(index));
    getset( _timeStamp,     "TimeStamp"             ,""     ,"Profiles", QString("profile%1").arg(index));
    getset( _trainerCalib,  "TrainerCalib"          ,""     ,"Profiles", QString("profile%1").arg(index));
    getset( _currentCalib,  "currentCalib"          ,0      ,"Profiles", QString("profile%1").arg(index));
    getset( _gsStickMode,   "GSStickMode"           ,0      ,"Profiles", QString("profile%1").arg(index));
    getset( _ppmMultiplier, "PPM_Multiplier"        ,0      ,"Profiles", QString("profile%1").arg(index));
    getset( _vBatCalib,     "VbatCalib"             ,0      ,"Profiles", QString("profile%1").arg(index));
    getset( _vBatWarn,      "vBatWarn"              ,0      ,"Profiles", QString("profile%1").arg(index));
}


// ** AppData class********************

// Get declarations
QStringList AppData::recentFiles() { return _recentFiles;     }
QByteArray AppData::mainWinGeo()   { return _mainWinGeo;      }
QByteArray AppData::mainWinState() { return _mainWinState;    }
QByteArray AppData::modelEditGeo() { return _modelEditGeo;    }

QString AppData::armMcu()          { return _armMcu;          }
QString AppData::avrArguments()    { return _avrArguments;    }
QString AppData::avrPort()         { return _avrPort;         }
QString AppData::avrdudeLocation() { return _avrdudeLocation; }
QString AppData::dfuArguments()    { return _dfuArguments;    }
QString AppData::dfuLocation()     { return _dfuLocation;     }
QString AppData::locale()          { return _locale;          }
QString AppData::mcu()             { return _mcu;             }
QString AppData::programmer()      { return _programmer;      }
QString AppData::sambaLocation()   { return _sambaLocation;   }
QString AppData::sambaPort()       { return _sambaPort;       }

QString AppData::backupDir()       { return _backupDir;       }
QString AppData::gePath()          { return _gePath;          }
QString AppData::eepromDir()       { return _eepromDir;       }
QString AppData::flashDir()        { return _flashDir;        }
QString AppData::imagesDir()       { return _imagesDir;       }
QString AppData::logDir()          { return _logDir;          }
QString AppData::libDir()          { return _libDir;          }
QString AppData::snapshotDir()     { return _snapshotDir;     }
QString AppData::updatesDir()      { return _updatesDir;      }

bool AppData::enableBackup()       { return _enableBackup;    }
bool AppData::checkHardwareCompatibility() { return _checkHardwareCompatibility; }
bool AppData::backupOnFlash()      { return _backupOnFlash;   }
bool AppData::jsSupport()          { return _jsSupport;       }
bool AppData::maximized()          { return _maximized;       }
bool AppData::showSplash()         { return _showSplash;      }
bool AppData::snapToClpbrd()       { return _snapToClpbrd;    }
bool AppData::autoCheckApp()       { return _autoCheckApp;    }
bool AppData::autoCheckFw()        { return _autoCheckFw;     }
bool AppData::simuSW()             { return _simuSW;          }
bool AppData::useWizard()          { return _useWizard;       }

int AppData::backLight()           { return _backLight;       }
int AppData::embedSplashes()       { return _embedSplashes;   }
int AppData::fwServerFails()       { return _fwServerFails;   }
int AppData::generalEditTab()      { return _generalEditTab;  }
int AppData::iconSize()            { return _iconSize;        }
int AppData::historySize()         { return _historySize;     }
int AppData::jsCtrl()              { return _jsCtrl;          }
int AppData::id()                  { return _id;              }
int AppData::theme()               { return _theme;           }
int AppData::warningId()           { return _warningId;       }

// Set declarations
void AppData::recentFiles     (const QStringList x) { store(x, _recentFiles,     "recentFileList"          );}
void AppData::mainWinGeo      (const QByteArray  x) { store(x, _mainWinGeo,      "mainWindowGeometry"      );}
void AppData::mainWinState    (const QByteArray  x) { store(x, _mainWinState,    "mainWindowState"         );}
void AppData::modelEditGeo    (const QByteArray  x) { store(x, _modelEditGeo,    "modelEditGeometry"       );}

void AppData::armMcu          (const QString     x) { store(x, _armMcu,          "arm_mcu"                 );}
void AppData::avrArguments    (const QString     x) { store(x, _avrArguments,    "avr_arguments"           );}
void AppData::avrPort         (const QString     x) { store(x, _avrPort,         "avr_port"                );}
void AppData::avrdudeLocation (const QString     x) { store(x, _avrdudeLocation, "avrdudeLocation"         );}
void AppData::dfuArguments    (const QString     x) { store(x, _dfuArguments,    "dfu_arguments"           );}
void AppData::dfuLocation     (const QString     x) { store(x, _dfuLocation,     "dfu_location"            );}
void AppData::locale          (const QString     x) { store(x, _locale,          "locale"                  );}
void AppData::mcu             (const QString     x) { store(x, _mcu,             "mcu"                     );}
void AppData::programmer      (const QString     x) { store(x, _programmer,      "programmer"              );}
void AppData::sambaLocation   (const QString     x) { store(x, _sambaLocation,   "samba_location"          );}
void AppData::sambaPort       (const QString     x) { store(x, _sambaPort,       "samba_port"              );}

void AppData::backupDir       (const QString     x) { store(x, _backupDir,       "backupPath"              );}
void AppData::gePath          (const QString     x) { store(x, _gePath,          "gePath"                  );}
void AppData::eepromDir       (const QString     x) { store(x, _eepromDir,       "lastDir"                 );}
void AppData::flashDir        (const QString     x) { store(x, _flashDir,        "lastFlashDir"            );}
void AppData::imagesDir       (const QString     x) { store(x, _imagesDir,       "lastImagesDir"           );}
void AppData::logDir          (const QString     x) { store(x, _logDir,          "lastLogDir"              );}
void AppData::libDir          (const QString     x) { store(x, _libDir,          "libraryPath"             );}
void AppData::snapshotDir     (const QString     x) { store(x, _snapshotDir,     "snapshotpath"            );}
void AppData::updatesDir      (const QString     x) { store(x, _updatesDir,      "lastUpdatesDir"          );}

void AppData::enableBackup    (const bool        x) { store(x, _enableBackup,    "backupEnable"            );}
void AppData::backupOnFlash   (const bool        x) { store(x, _backupOnFlash,   "backupOnFlash"           );}
void AppData::checkHardwareCompatibility(const bool x) { store(x, _checkHardwareCompatibility,   "checkHardwareCompatibility");}
void AppData::maximized       (const bool        x) { store(x, _maximized,       "maximized"               );}
void AppData::jsSupport       (const bool        x) { store(x, _jsSupport,       "js_support"              );}
void AppData::showSplash      (const bool        x) { store(x, _showSplash,      "show_splash"             );}
void AppData::snapToClpbrd    (const bool        x) { store(x, _snapToClpbrd,    "snapshot_to_clipboard"   );}
void AppData::autoCheckApp    (const bool        x) { store(x, _autoCheckApp,    "startup_check_companion" );}
void AppData::autoCheckFw     (const bool        x) { store(x, _autoCheckFw,     "startup_check_fw"        );}
void AppData::simuSW          (const bool        x) { store(x, _simuSW,          "simuSW"                  );}
void AppData::useWizard       (const bool        x) { store(x, _useWizard,       "useWizard"               );}

void AppData::backLight       (const int         x) { store(x, _backLight,       "backLight"               );}
void AppData::embedSplashes   (const int         x) { store(x, _embedSplashes,   "embedded_splashes"       );}
void AppData::fwServerFails   (const int         x) { store(x, _fwServerFails,   "fwserver"                );}
void AppData::generalEditTab  (const int         x) { store(x, _generalEditTab,  "generalEditTab"          );}
void AppData::iconSize        (const int         x) { store(x, _iconSize,        "icon_size"               );}
void AppData::historySize     (const int         x) { store(x, _historySize,     "history_size"            );}
void AppData::jsCtrl          (const int         x) { store(x, _jsCtrl,          "js_ctrl"                 );}
void AppData::id              (const int         x) { store(x, _id,              "profileId"               );}
void AppData::theme           (const int         x) { store(x, _theme,           "theme"                   );}
void AppData::warningId       (const int         x) { store(x, _warningId,       "warningId"               );}

// Constructor
AppData::AppData()
{
    //Initialize the profiles
    for (int i=0; i<MAX_PROFILES; i++)
        profile[i].init( i );

    //Initialize the joysticks
    for (int i=0; i<MAX_JOYSTICKS; i++)
        joystick[i].init( i );

    // Import settings from companion9x, but only do it one time.
    QSettings c9x_settings("companion9x", "companion9x");
    QSettings settings(PRODUCT, COMPANY);
    if (profile[0].name().isEmpty() )
    {
        // Copy all settings from companion9x to companion
        QStringList keys = c9x_settings.allKeys();
        for (QStringList::iterator i=keys.begin(); i!=keys.end(); i++)
        {
            settings.setValue(*i, c9x_settings.value(*i));
        }

        // Store old values in new locations
        autoCheckApp(settings.value("startup_check_companion9x", true).toBool());
        useWizard(settings.value("wizardEnable", true).toBool());

        // Convert and store the firmware type
        QString fwType  = settings.value("firmware", "").toString();
        fwType.replace("open9x","opentx");
        fwType.replace("x9da","taranis");
        profile[0].fwType( fwType );

        // Move the Companion9x profile settings to profile0, the new default profile
        profile[0].name( settings.value(          "Name",                  ""    ).toString());
        profile[0].sdPath( settings.value(        "sdPath",                ""    ).toString());
        profile[0].splashFile( settings.value(    "SplashFileName",        ""    ).toString());
        profile[0].burnFirmware( settings.value(  "burnFirmware",          false ).toBool());
        profile[0].renameFwFiles( settings.value( "rename_firmware_files", false ).toBool());
        profile[0].channelOrder( settings.value(  "default_channel_order", "0"   ).toInt());
        profile[0].defaultMode( settings.value(   "default_mode",          "1"   ).toInt());

        // Ensure that the default profile has a name
        if ( profile[0].name().isEmpty() )
            profile[0].name("My Radio");

        // Delete obsolete settings fields from companion9x
        settings.remove("ActiveProfile");
        settings.remove("burnFirmware");
        settings.remove("custom_id");
        settings.remove("default_channel_order");
        settings.remove("default_mode");
        settings.remove("firmware");
        settings.remove("lastFw");
        settings.remove("modelEditTab");
        settings.remove("Name");
        settings.remove("patchImage");
        settings.remove("rename_firmware_files");
        settings.remove("sdPath");
        settings.remove("SplashFileName"); 
        settings.remove("startup_check_companion9x");
        settings.remove("wizardEnable");

        // Delete settings that we do not want to carry over from 1.52
        settings.remove("dfu_location");

        // Select the new default profile as current profile
        id( 0 );
    }

    // Remove settings that have been made obsolete during companion2.0 development
    settings.remove("compilation-server");

    // Load and store all variables. Use default values if setting values are missing
    QString _tempString;                                         // Do not touch. Do not change the settings version before a new verson update!
    getset( _tempString,      "settings_version"        ,"20" ); // This is a version marker. Will be used to upgrade the settings later on.

    getset( _recentFiles,     "recentFileList"          ,"" );
    getset( _mainWinGeo,      "mainWindowGeometry"      ,"" );
    getset( _mainWinState,    "mainWindowState"         ,"" );
    getset( _modelEditGeo,    "modelEditGeometry"       ,"" );

    getset( _armMcu,          "arm_mcu"                 ,"at91sam3s4-9x" );
    getset( _avrArguments,    "avr_arguments"           ,"" );
    getset( _avrPort,         "avr_port"                ,"" );
    getset( _avrdudeLocation, "avrdudeLocation"        ,"" );
    getset( _dfuArguments,    "dfu_arguments"           ,"-a 0" );
    getset( _dfuLocation,     "dfu_location"            ,"" );
    getset( _locale,          "locale"                  ,"" );
    getset( _mcu,             "mcu"                     ,"m64" );
    getset( _programmer,      "programmer"              ,"usbasp" );
    getset( _sambaLocation,   "samba_location"          ,"" );
    getset( _sambaPort,       "samba_port"              ,"\\USBserial\\COM23" );

    getset( _backupDir,       "backupPath"              ,"" );
    getset( _gePath,          "gePath"                  ,"" );
    getset( _eepromDir,       "lastDir"                 ,"" );
    getset( _flashDir,        "lastFlashDir"            ,"" );
    getset( _imagesDir,       "lastImagesDir"           ,"" );
    getset( _logDir,          "lastLogDir"              ,"" );
    getset( _libDir,          "libraryPath"             ,"" );
    getset( _snapshotDir,     "snapshotpath"            ,"" );
    getset( _updatesDir,      "lastUpdatesDir"          ,"" );

    getset( _enableBackup,    "backupEnable"            ,false );
    getset( _checkHardwareCompatibility,    "checkHardwareCompatibility", true );
    getset( _backupOnFlash,   "backupOnFlash"           ,true  );
    getset( _jsSupport,       "js_support"              ,false );
    getset( _maximized,       "maximized"               ,false );
    getset( _showSplash,      "show_splash"             ,true  );
    getset( _snapToClpbrd,    "snapshot_to_clipboard"   ,false );
    getset( _autoCheckApp,    "startup_check_companion" ,true  );
    getset( _autoCheckFw,     "startup_check_fw"        ,true  );
    getset( _simuSW,          "simuSW"                  ,false );
    getset( _useWizard,       "useWizard"               ,true  );

    getset( _backLight,       "backLight"               ,0  );
    getset( _embedSplashes,   "embedded_splashes"       ,0  );
    getset( _fwServerFails,   "fwserver"                ,0  );
    getset( _generalEditTab,  "generalEditTab"          ,0  );
    getset( _iconSize,        "icon_size"               ,2  );
    getset( _jsCtrl,          "js_ctrl"                 ,0  );
    getset( _historySize,     "history_size"            ,10 );
    getset( _id,              "profileId"               ,0  );
    getset( _theme,           "theme"                   ,1  );
    getset( _warningId,       "warningId"               ,0  );
}
