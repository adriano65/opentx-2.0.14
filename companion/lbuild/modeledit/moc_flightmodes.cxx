/****************************************************************************
** Meta object code from reading C++ file 'flightmodes.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/modeledit/flightmodes.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'flightmodes.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FlightModePanel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      32,   16,   16,   16, 0x08,
      66,   60,   16,   16, 0x08,
     103,   16,   16,   16, 0x08,
     133,   16,   16,   16, 0x08,
     164,   60,   16,   16, 0x08,
     202,   16,   16,   16, 0x08,
     227,   16,   16,   16, 0x08,
     258,   16,   16,   16, 0x08,
     283,   16,   16,   16, 0x08,
     314,   60,   16,   16, 0x08,
     358,  350,   16,   16, 0x08,
     384,   16,   16,   16, 0x08,
     415,   60,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FlightModePanel[] = {
    "FlightModePanel\0\0nameModified()\0"
    "phaseName_editingFinished()\0index\0"
    "phaseSwitch_currentIndexChanged(int)\0"
    "phaseFadeIn_editingFinished()\0"
    "phaseFadeOut_editingFinished()\0"
    "phaseTrimUse_currentIndexChanged(int)\0"
    "phaseTrim_valueChanged()\0"
    "phaseTrimSlider_valueChanged()\0"
    "GVName_editingFinished()\0"
    "phaseGVValue_editingFinished()\0"
    "phaseGVUse_currentIndexChanged(int)\0"
    "checked\0phaseGVPopupToggled(bool)\0"
    "phaseREValue_editingFinished()\0"
    "phaseREUse_currentIndexChanged(int)\0"
};

void FlightModePanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        FlightModePanel *_t = static_cast<FlightModePanel *>(_o);
        switch (_id) {
        case 0: _t->nameModified(); break;
        case 1: _t->phaseName_editingFinished(); break;
        case 2: _t->phaseSwitch_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->phaseFadeIn_editingFinished(); break;
        case 4: _t->phaseFadeOut_editingFinished(); break;
        case 5: _t->phaseTrimUse_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->phaseTrim_valueChanged(); break;
        case 7: _t->phaseTrimSlider_valueChanged(); break;
        case 8: _t->GVName_editingFinished(); break;
        case 9: _t->phaseGVValue_editingFinished(); break;
        case 10: _t->phaseGVUse_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->phaseGVPopupToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->phaseREValue_editingFinished(); break;
        case 13: _t->phaseREUse_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData FlightModePanel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject FlightModePanel::staticMetaObject = {
    { &ModelPanel::staticMetaObject, qt_meta_stringdata_FlightModePanel,
      qt_meta_data_FlightModePanel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FlightModePanel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FlightModePanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FlightModePanel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FlightModePanel))
        return static_cast<void*>(const_cast< FlightModePanel*>(this));
    return ModelPanel::qt_metacast(_clname);
}

int FlightModePanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ModelPanel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void FlightModePanel::nameModified()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
static const uint qt_meta_data_FlightModesPanel[] = {

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
      18,   17,   17,   17, 0x08,
      36,   17,   17,   17, 0x08,
      63,   57,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FlightModesPanel[] = {
    "FlightModesPanel\0\0onPhaseModified()\0"
    "onPhaseNameChanged()\0index\0"
    "on_tabWidget_currentChanged(int)\0"
};

void FlightModesPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        FlightModesPanel *_t = static_cast<FlightModesPanel *>(_o);
        switch (_id) {
        case 0: _t->onPhaseModified(); break;
        case 1: _t->onPhaseNameChanged(); break;
        case 2: _t->on_tabWidget_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData FlightModesPanel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject FlightModesPanel::staticMetaObject = {
    { &ModelPanel::staticMetaObject, qt_meta_stringdata_FlightModesPanel,
      qt_meta_data_FlightModesPanel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FlightModesPanel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FlightModesPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FlightModesPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FlightModesPanel))
        return static_cast<void*>(const_cast< FlightModesPanel*>(this));
    return ModelPanel::qt_metacast(_clname);
}

int FlightModesPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
