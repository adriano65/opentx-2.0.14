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

// All temporary and permanent global variables are defined here to make 
// initialization and storage safe and visible.
// Do not access variables in QSettings directly, it is not type safe!


#ifndef COMPANION_APPDATA_H
#define COMPANION_APPDATA_H
#include <QByteArray>
#include <QStringList>
#include <QString>
#include <QSettings>

#define COMPANY "OpenTX Companion"
#define PRODUCT "OpenTX"

#define MAX_PROFILES 15
#define MAX_JOYSTICKS 8

class CompStoreObj
{
  public:
    void clear (const QString tag1="", const QString tag2="", const QString tag3="");
    void store(const QByteArray newArray, QByteArray &array, const QString tag, const QString group1="", const QString group2="" );
    void store(const QStringList newSList, QStringList &stringList, const QString tag, const QString group1="", const QString group2="" );
    void store(const QString newString, QString &string, const QString tag, const QString group1="", const QString group2="" );
    void store(const bool newTruth, bool &truth, const QString tag, const QString group1="", const QString group2="" );
    void store(const int newNumber, int &number, const QString tag, const QString group1="", const QString group2="" );

    // Retrieval functions
    void retrieve( QByteArray &array, const QString tag, const QString def, const QString group1="", const QString group2="" );
    void retrieve( QStringList &stringList, const QString tag, const QString def, const QString group1="", const QString group2="" );
    void retrieve( QString &string, const QString tag, const QString def, const QString group1="", const QString group2="" );
    void retrieve( bool &truth, const QString tag, const bool def, const QString group1="", const QString group2="" );
    void retrieve( int &number, const QString tag, const int def, const QString group1="", const QString group2="" );

    // Retrieve and Store functions
    void getset( QByteArray &array, const QString tag, const QString def, const QString group1="", const QString group2="" );
    void getset( QStringList &stringList, const QString tag, const QString def, const QString group1="", const QString group2="" );
    void getset( QString &string, const QString tag, const QString def, const QString group1="", const QString group2="" );
    void getset( bool &truth, const QString tag, const bool def, const QString group1="", const QString group2="" );
    void getset( int &number, const QString tag, const int def, const QString group1="", const QString group2="" );
}; 

class FwRevision: protected CompStoreObj
{
  public:
    int get( const QString);
    void set( const QString, const int );
    void remove( const QString );
};

class JStickData: protected CompStoreObj
{
  private:
    int index;

    int _stickAxe;
    int _stickMin;
    int _stickMed;
    int _stickMax;
    int _stickInv;

  public:
    // All the get definitions
    int stick_axe();
    int stick_min();
    int stick_med();
    int stick_max();
    int stick_inv();

    // All the set definitions
    void stick_axe(const int);
    void stick_min(const int);
    void stick_med(const int);
    void stick_max(const int);
    void stick_inv(const int);

    JStickData();
    void remove();
    bool existsOnDisk();
    void init(int index);
    void flush();
};

class Profile: protected CompStoreObj
{
  private:
    // Class Internal Variable
    int index;

    // Application Variables
    QString _fwName;
    QString _fwType;
    QString _name;
    QString _sdPath;
    QString _splashFile;
    bool    _burnFirmware;
    bool    _renameFwFiles;
    int     _channelOrder;
    int     _defaultMode;

    // Firmware Variables
    QString _beeper;
    QString _countryCode;
    QString _display;
    QString _haptic;
    QString _speaker;
    QString _stickPotCalib;
    QString _timeStamp;
    QString _trainerCalib;
    int     _currentCalib;
    int     _gsStickMode;
    int     _ppmMultiplier;
    int     _vBatCalib;
    int     _vBatWarn;

  public:
    // All the get definitions
    QString fwName() const;
    QString fwType() const;
    QString name() const;
    QString sdPath() const;
    QString splashFile() const;
    bool    burnFirmware() const;
    bool    renameFwFiles() const;
    int     channelOrder() const;
    int     defaultMode() const;

    QString beeper() const;
    QString countryCode() const;
    QString display() const;
    QString haptic() const;
    QString speaker() const;
    QString stickPotCalib() const;
    QString timeStamp() const;
    QString trainerCalib() const;
    int     currentCalib() const;
    int     gsStickMode() const;
    int     ppmMultiplier() const;
    int     vBatCalib() const;
    int     vBatWarn() const;

    // All the set definitions
    void name          (const QString);
    void fwName        (const QString);
    void fwType        (const QString);
    void sdPath        (const QString);
    void splashFile    (const QString);
    void burnFirmware  (const bool);
    void renameFwFiles (const bool);
    void channelOrder  (const int);
    void defaultMode   (const int);

    void beeper        (const QString);
    void countryCode   (const QString);
    void display       (const QString);
    void haptic        (const QString);
    void speaker       (const QString);
    void stickPotCalib (const QString);
    void timeStamp     (const QString);
    void trainerCalib  (const QString);
    void currentCalib  (const int);
    void gsStickMode   (const int);
    void ppmMultiplier (const int);
    void vBatCalib     (const int);
    void vBatWarn      (const int);

    Profile();
    Profile& operator=(const Profile&);
    void remove();
    bool existsOnDisk();
    void init(int newIndex);
    void initFwVariables();
    void flush();
};

class AppData: protected CompStoreObj
{
  // All the global variables
  public:
    Profile    profile[MAX_PROFILES];
    JStickData joystick[MAX_JOYSTICKS];
    FwRevision fwRev;

  private:
    QStringList _recentFiles;
    QByteArray _mainWinGeo;
    QByteArray _mainWinState;
    QByteArray _modelEditGeo;

    QString _armMcu;
    QString _avrArguments;
    QString _avrPort;
    QString _avrdudeLocation;
    QString _dfuArguments;
    QString _dfuLocation;
    QString _locale;
    QString _mcu;
    QString _programmer;
    QString _sambaLocation;
    QString _sambaPort;

    QString _backupDir;
    QString _gePath;
    QString _eepromDir;
    QString _flashDir;
    QString _imagesDir;
    QString _logDir;
    QString _libDir;
    QString _snapshotDir;
    QString _updatesDir;

    bool _enableBackup;
    bool _backupOnFlash;
    bool _checkHardwareCompatibility;
    bool _maximized;
    bool _jsSupport;
    bool _showSplash;
    bool _snapToClpbrd;
    bool _autoCheckApp;
    bool _autoCheckFw;
    bool _simuSW;
    bool _useWizard;

    int _backLight;
    int _embedSplashes;
    int _fwServerFails;
    int _generalEditTab;
    int _iconSize;
    int _jsCtrl;
    int _historySize;
    int _id;
    int _theme;
    int _warningId;

  public:
    // All the get definitions
    QStringList recentFiles();
    QByteArray mainWinGeo();
    QByteArray mainWinState();
    QByteArray modelEditGeo();

    QString armMcu();
    QString avrArguments();
    QString avrPort();
    QString avrdudeLocation();
    QString dfuArguments();
    QString dfuLocation();
    QString lastFw();  
    QString locale();
    QString mcu();
    QString programmer();
    QString sambaLocation();
    QString sambaPort();

    QString backupDir();
    QString gePath();
    QString eepromDir();
    QString flashDir();
    QString imagesDir();
    QString logDir();
    QString libDir();
    QString snapshotDir();
    QString updatesDir();

    bool enableBackup();
    bool backupOnFlash();
    bool checkHardwareCompatibility();
    bool jsSupport();
    bool maximized();
    bool showSplash();
    bool snapToClpbrd();
    bool autoCheckApp();
    bool autoCheckFw();
    bool simuSW();
    bool useWizard();

    int backLight();
    int embedSplashes();
    int fwServerFails();
    int generalEditTab();
    int iconSize();
    int historySize();
    int jsCtrl();
    int id();
    int theme();
    int warningId();

    // All the set definitions
    void recentFiles     (const QStringList x);
    void mainWinGeo      (const QByteArray);
    void mainWinState    (const QByteArray);
    void modelEditGeo    (const QByteArray);

    void armMcu          (const QString);
    void avrArguments    (const QString);
    void avrPort         (const QString);
    void avrdudeLocation (const QString);
    void dfuArguments    (const QString);
    void dfuLocation     (const QString);
    void lastFw          (const QString);
    void locale          (const QString);
    void mcu             (const QString);
    void programmer      (const QString);
    void sambaLocation   (const QString);
    void sambaPort       (const QString);

    void backupDir       (const QString);
    void gePath          (const QString);
    void eepromDir       (const QString);
    void flashDir        (const QString);
    void imagesDir       (const QString);
    void logDir          (const QString);
    void libDir          (const QString);
    void snapshotDir     (const QString);
    void updatesDir      (const QString);

    void enableBackup    (const bool);
    void backupOnFlash   (const bool);
    void checkHardwareCompatibility   (const bool);
    void maximized       (const bool);
    void jsSupport       (const bool);
    void showSplash      (const bool);
    void snapToClpbrd    (const bool);
    void autoCheckApp    (const bool);
    void autoCheckFw     (const bool);
    void simuSW          (const bool);
    void useWizard       (const bool);

    void backLight       (const int);
    void embedSplashes   (const int);
    void fwServerFails   (const int);
    void generalEditTab  (const int);
    void iconSize        (const int);
    void historySize     (const int);
    void jsCtrl          (const int);
    void modelEditTab    (const int);
    void id              (const int);
    void theme           (const int);
    void warningId       (const int);

    // Constructor
    AppData();
};

extern AppData g;

#endif // COMPANION_APPDATA_H
