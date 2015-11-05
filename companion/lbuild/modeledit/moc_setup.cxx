/****************************************************************************
** Meta object code from reading C++ file 'setup.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/modeledit/setup.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'setup.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TimerPanel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   12,   11,   11, 0x08,
      51,   11,   11,   11, 0x08,
      86,   78,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TimerPanel[] = {
    "TimerPanel\0\0index\0on_mode_currentIndexChanged(int)\0"
    "on_value_editingFinished()\0checked\0"
    "on_minuteBeep_toggled(bool)\0"
};

void TimerPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TimerPanel *_t = static_cast<TimerPanel *>(_o);
        switch (_id) {
        case 0: _t->on_mode_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_value_editingFinished(); break;
        case 2: _t->on_minuteBeep_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TimerPanel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TimerPanel::staticMetaObject = {
    { &ModelPanel::staticMetaObject, qt_meta_stringdata_TimerPanel,
      qt_meta_data_TimerPanel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TimerPanel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TimerPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TimerPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TimerPanel))
        return static_cast<void*>(const_cast< TimerPanel*>(this));
    return ModelPanel::qt_metacast(_clname);
}

int TimerPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ModelPanel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
static const uint qt_meta_data_ModulePanel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   13,   12,   12, 0x08,
      59,   13,   12,   12, 0x08,
      96,   12,   12,   12, 0x08,
     126,   12,   12,   12, 0x08,
     161,   12,   12,   12, 0x08,
     196,   13,   12,   12, 0x08,
     236,   12,   12,   12, 0x08,
     272,   12,   12,   12, 0x08,
     308,  302,   12,   12, 0x08,
     349,  302,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ModulePanel[] = {
    "ModulePanel\0\0index\0"
    "on_trainerMode_currentIndexChanged(int)\0"
    "on_protocol_currentIndexChanged(int)\0"
    "on_ppmDelay_editingFinished()\0"
    "on_channelsCount_editingFinished()\0"
    "on_channelsStart_editingFinished()\0"
    "on_ppmPolarity_currentIndexChanged(int)\0"
    "on_ppmFrameLength_editingFinished()\0"
    "on_rxNumber_editingFinished()\0value\0"
    "on_failsafeMode_currentIndexChanged(int)\0"
    "onFailsafeSpinChanged(double)\0"
};

void ModulePanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ModulePanel *_t = static_cast<ModulePanel *>(_o);
        switch (_id) {
        case 0: _t->on_trainerMode_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_protocol_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_ppmDelay_editingFinished(); break;
        case 3: _t->on_channelsCount_editingFinished(); break;
        case 4: _t->on_channelsStart_editingFinished(); break;
        case 5: _t->on_ppmPolarity_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_ppmFrameLength_editingFinished(); break;
        case 7: _t->on_rxNumber_editingFinished(); break;
        case 8: _t->on_failsafeMode_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->onFailsafeSpinChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ModulePanel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ModulePanel::staticMetaObject = {
    { &ModelPanel::staticMetaObject, qt_meta_stringdata_ModulePanel,
      qt_meta_data_ModulePanel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ModulePanel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ModulePanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ModulePanel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ModulePanel))
        return static_cast<void*>(const_cast< ModulePanel*>(this));
    return ModelPanel::qt_metacast(_clname);
}

int ModulePanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ModelPanel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
static const uint qt_meta_data_SetupPanel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      36,   11,   11,   11, 0x08,
      68,   62,   11,   11, 0x08,
     119,  111,   11,   11, 0x08,
     149,  111,   11,   11, 0x08,
     181,  111,   11,   11, 0x08,
     212,  111,   11,   11, 0x08,
     245,  111,   11,   11, 0x08,
     278,  111,   11,   11, 0x08,
     307,   62,   11,   11, 0x08,
     341,   62,   11,   11, 0x08,
     383,  111,   11,   11, 0x08,
     415,  409,   11,   11, 0x08,
     440,  111,   11,   11, 0x08,
     467,  111,   11,   11, 0x08,
     491,   62,   11,   11, 0x08,
     534,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SetupPanel[] = {
    "SetupPanel\0\0extendedLimitsToggled()\0"
    "on_name_editingFinished()\0index\0"
    "on_throttleSource_currentIndexChanged(int)\0"
    "checked\0on_throttleTrim_toggled(bool)\0"
    "on_extendedLimits_toggled(bool)\0"
    "on_extendedTrims_toggled(bool)\0"
    "on_throttleWarning_toggled(bool)\0"
    "on_throttleReverse_toggled(bool)\0"
    "on_displayText_toggled(bool)\0"
    "on_image_currentIndexChanged(int)\0"
    "on_trimIncrement_currentIndexChanged(int)\0"
    "onBeepCenterToggled(bool)\0value\0"
    "startupSwitchEdited(int)\0"
    "startupSwitchToggled(bool)\0"
    "potWarningToggled(bool)\0"
    "on_potWarningMode_currentIndexChanged(int)\0"
    "onChildModified()\0"
};

void SetupPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SetupPanel *_t = static_cast<SetupPanel *>(_o);
        switch (_id) {
        case 0: _t->extendedLimitsToggled(); break;
        case 1: _t->on_name_editingFinished(); break;
        case 2: _t->on_throttleSource_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_throttleTrim_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_extendedLimits_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_extendedTrims_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_throttleWarning_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_throttleReverse_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->on_displayText_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_image_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_trimIncrement_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->onBeepCenterToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->startupSwitchEdited((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->startupSwitchToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->potWarningToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->on_potWarningMode_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->onChildModified(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SetupPanel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SetupPanel::staticMetaObject = {
    { &ModelPanel::staticMetaObject, qt_meta_stringdata_SetupPanel,
      qt_meta_data_SetupPanel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SetupPanel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SetupPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SetupPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SetupPanel))
        return static_cast<void*>(const_cast< SetupPanel*>(this));
    return ModelPanel::qt_metacast(_clname);
}

int SetupPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void SetupPanel::extendedLimitsToggled()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
