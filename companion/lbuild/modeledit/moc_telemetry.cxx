/****************************************************************************
** Meta object code from reading C++ file 'telemetry.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/modeledit/telemetry.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'telemetry.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TelemetryAnalog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      34,   28,   16,   16, 0x08,
      69,   16,   16,   16, 0x08,
      98,   16,   16,   16, 0x08,
     124,   16,   16,   16, 0x08,
     153,   28,   16,   16, 0x08,
     195,   28,   16,   16, 0x08,
     239,   16,   16,   16, 0x08,
     274,   28,   16,   16, 0x08,
     316,   28,   16,   16, 0x08,
     360,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TelemetryAnalog[] = {
    "TelemetryAnalog\0\0modified()\0index\0"
    "on_UnitCB_currentIndexChanged(int)\0"
    "on_RatioSB_editingFinished()\0"
    "on_RatioSB_valueChanged()\0"
    "on_CalibSB_editingFinished()\0"
    "on_alarm1LevelCB_currentIndexChanged(int)\0"
    "on_alarm1GreaterCB_currentIndexChanged(int)\0"
    "on_alarm1ValueSB_editingFinished()\0"
    "on_alarm2LevelCB_currentIndexChanged(int)\0"
    "on_alarm2GreaterCB_currentIndexChanged(int)\0"
    "on_alarm2ValueSB_editingFinished()\0"
};

void TelemetryAnalog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TelemetryAnalog *_t = static_cast<TelemetryAnalog *>(_o);
        switch (_id) {
        case 0: _t->modified(); break;
        case 1: _t->on_UnitCB_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_RatioSB_editingFinished(); break;
        case 3: _t->on_RatioSB_valueChanged(); break;
        case 4: _t->on_CalibSB_editingFinished(); break;
        case 5: _t->on_alarm1LevelCB_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_alarm1GreaterCB_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_alarm1ValueSB_editingFinished(); break;
        case 8: _t->on_alarm2LevelCB_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_alarm2GreaterCB_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_alarm2ValueSB_editingFinished(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TelemetryAnalog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TelemetryAnalog::staticMetaObject = {
    { &ModelPanel::staticMetaObject, qt_meta_stringdata_TelemetryAnalog,
      qt_meta_data_TelemetryAnalog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TelemetryAnalog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TelemetryAnalog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TelemetryAnalog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TelemetryAnalog))
        return static_cast<void*>(const_cast< TelemetryAnalog*>(this));
    return ModelPanel::qt_metacast(_clname);
}

int TelemetryAnalog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ModelPanel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void TelemetryAnalog::modified()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
static const uint qt_meta_data_TelemetryCustomScreen[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      29,   23,   22,   22, 0x08,
      68,   23,   22,   22, 0x08,
      92,   23,   22,   22, 0x08,
     120,  114,   22,   22, 0x08,
     142,  114,   22,   22, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TelemetryCustomScreen[] = {
    "TelemetryCustomScreen\0\0index\0"
    "on_screenType_currentIndexChanged(int)\0"
    "customFieldChanged(int)\0barSourceChanged(int)\0"
    "value\0barMinChanged(double)\0"
    "barMaxChanged(double)\0"
};

void TelemetryCustomScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TelemetryCustomScreen *_t = static_cast<TelemetryCustomScreen *>(_o);
        switch (_id) {
        case 0: _t->on_screenType_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->customFieldChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->barSourceChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->barMinChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->barMaxChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TelemetryCustomScreen::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TelemetryCustomScreen::staticMetaObject = {
    { &ModelPanel::staticMetaObject, qt_meta_stringdata_TelemetryCustomScreen,
      qt_meta_data_TelemetryCustomScreen, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TelemetryCustomScreen::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TelemetryCustomScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TelemetryCustomScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TelemetryCustomScreen))
        return static_cast<void*>(const_cast< TelemetryCustomScreen*>(this));
    return ModelPanel::qt_metacast(_clname);
}

int TelemetryCustomScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ModelPanel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
static const uint qt_meta_data_TelemetryPanel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,   16,   15,   15, 0x08,
      68,   15,   15,   15, 0x08,
      87,   16,   15,   15, 0x08,
     128,   15,   15,   15, 0x08,
     169,  161,   15,   15, 0x08,
     207,   16,   15,   15, 0x08,
     248,   16,   15,   15, 0x08,
     289,   15,   15,   15, 0x08,
     323,   15,   15,   15, 0x08,
     357,  161,   15,   15, 0x08,
     391,   15,   15,   15, 0x08,
     430,   15,   15,   15, 0x08,
     469,   15,   15,   15, 0x08,
     514,   15,   15,   15, 0x08,
     559,   15,   15,   15, 0x08,
     594,   15,   15,   15, 0x08,
     627,  161,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TelemetryPanel[] = {
    "TelemetryPanel\0\0index\0"
    "on_telemetryProtocol_currentIndexChanged(int)\0"
    "onAnalogModified()\0"
    "on_frskyProtoCB_currentIndexChanged(int)\0"
    "on_bladesCount_editingFinished()\0"
    "checked\0on_AltitudeToolbar_ChkB_toggled(bool)\0"
    "on_rssiAlarm1CB_currentIndexChanged(int)\0"
    "on_rssiAlarm2CB_currentIndexChanged(int)\0"
    "on_rssiAlarm1SB_editingFinished()\0"
    "on_rssiAlarm2SB_editingFinished()\0"
    "on_AltitudeGPS_ChkB_toggled(bool)\0"
    "on_varioLimitMin_DSB_editingFinished()\0"
    "on_varioLimitMax_DSB_editingFinished()\0"
    "on_varioLimitCenterMin_DSB_editingFinished()\0"
    "on_varioLimitCenterMax_DSB_editingFinished()\0"
    "on_fasOffset_DSB_editingFinished()\0"
    "on_mahCount_SB_editingFinished()\0"
    "on_mahCount_ChkB_toggled(bool)\0"
};

void TelemetryPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TelemetryPanel *_t = static_cast<TelemetryPanel *>(_o);
        switch (_id) {
        case 0: _t->on_telemetryProtocol_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->onAnalogModified(); break;
        case 2: _t->on_frskyProtoCB_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_bladesCount_editingFinished(); break;
        case 4: _t->on_AltitudeToolbar_ChkB_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_rssiAlarm1CB_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_rssiAlarm2CB_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_rssiAlarm1SB_editingFinished(); break;
        case 8: _t->on_rssiAlarm2SB_editingFinished(); break;
        case 9: _t->on_AltitudeGPS_ChkB_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->on_varioLimitMin_DSB_editingFinished(); break;
        case 11: _t->on_varioLimitMax_DSB_editingFinished(); break;
        case 12: _t->on_varioLimitCenterMin_DSB_editingFinished(); break;
        case 13: _t->on_varioLimitCenterMax_DSB_editingFinished(); break;
        case 14: _t->on_fasOffset_DSB_editingFinished(); break;
        case 15: _t->on_mahCount_SB_editingFinished(); break;
        case 16: _t->on_mahCount_ChkB_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TelemetryPanel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TelemetryPanel::staticMetaObject = {
    { &ModelPanel::staticMetaObject, qt_meta_stringdata_TelemetryPanel,
      qt_meta_data_TelemetryPanel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TelemetryPanel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TelemetryPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TelemetryPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TelemetryPanel))
        return static_cast<void*>(const_cast< TelemetryPanel*>(this));
    return ModelPanel::qt_metacast(_clname);
}

int TelemetryPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ModelPanel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
