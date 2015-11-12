/****************************************************************************
** Meta object code from reading C++ file 'simulatordialog.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/simulation/simulatordialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'simulatordialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SimulatorDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   17,   16,   16, 0x08,
      52,   44,   16,   16, 0x08,
      79,   44,   16,   16, 0x08,
     106,   44,   16,   16, 0x08,
     132,   44,   16,   16, 0x08,
     158,   44,   16,   16, 0x08,
     186,   44,   16,   16, 0x08,
     214,   44,   16,   16, 0x08,
     241,   44,   16,   16, 0x08,
     268,   16,   16,   16, 0x08,
     299,   16,   16,   16, 0x08,
     330,   16,   16,   16, 0x08,
     362,   16,   16,   16, 0x08,
     394,   16,   16,   16, 0x08,
     409,   16,   16,   16, 0x08,
     425,   16,   16,   16, 0x08,
     442,   16,   16,   16, 0x08,
     467,   16,   16,   16, 0x08,
     490,   16,   16,   16, 0x08,
     508,   16,   16,   16, 0x08,
     540,  529,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SimulatorDialog[] = {
    "SimulatorDialog\0\0value\0onButtonPressed(int)\0"
    "checked\0on_FixRightY_clicked(bool)\0"
    "on_FixRightX_clicked(bool)\0"
    "on_FixLeftY_clicked(bool)\0"
    "on_FixLeftX_clicked(bool)\0"
    "on_holdRightY_clicked(bool)\0"
    "on_holdRightX_clicked(bool)\0"
    "on_holdLeftY_clicked(bool)\0"
    "on_holdLeftX_clicked(bool)\0"
    "on_trimHLeft_valueChanged(int)\0"
    "on_trimVLeft_valueChanged(int)\0"
    "on_trimHRight_valueChanged(int)\0"
    "on_trimVRight_valueChanged(int)\0"
    "onTimerEvent()\0onTrimPressed()\0"
    "onTrimReleased()\0openTelemetrySimulator()\0"
    "openTrainerSimulator()\0openDebugOutput()\0"
    "onDebugOutputClose()\0axis,value\0"
    "onjoystickAxisValueChanged(int,int)\0"
};

void SimulatorDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SimulatorDialog *_t = static_cast<SimulatorDialog *>(_o);
        switch (_id) {
        case 0: _t->onButtonPressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_FixRightY_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_FixRightX_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_FixLeftY_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_FixLeftX_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_holdRightY_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_holdRightX_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_holdLeftY_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->on_holdLeftX_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_trimHLeft_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_trimVLeft_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_trimHRight_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_trimVRight_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->onTimerEvent(); break;
        case 14: _t->onTrimPressed(); break;
        case 15: _t->onTrimReleased(); break;
        case 16: _t->openTelemetrySimulator(); break;
        case 17: _t->openTrainerSimulator(); break;
        case 18: _t->openDebugOutput(); break;
        case 19: _t->onDebugOutputClose(); break;
        case 20: _t->onjoystickAxisValueChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SimulatorDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SimulatorDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SimulatorDialog,
      qt_meta_data_SimulatorDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SimulatorDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SimulatorDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SimulatorDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SimulatorDialog))
        return static_cast<void*>(const_cast< SimulatorDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int SimulatorDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    }
    return _id;
}
static const uint qt_meta_data_SimulatorDialog9X[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SimulatorDialog9X[] = {
    "SimulatorDialog9X\0\0dialChanged()\0"
};

void SimulatorDialog9X::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SimulatorDialog9X *_t = static_cast<SimulatorDialog9X *>(_o);
        switch (_id) {
        case 0: _t->dialChanged(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData SimulatorDialog9X::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SimulatorDialog9X::staticMetaObject = {
    { &SimulatorDialog::staticMetaObject, qt_meta_stringdata_SimulatorDialog9X,
      qt_meta_data_SimulatorDialog9X, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SimulatorDialog9X::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SimulatorDialog9X::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SimulatorDialog9X::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SimulatorDialog9X))
        return static_cast<void*>(const_cast< SimulatorDialog9X*>(this));
    return SimulatorDialog::qt_metacast(_clname);
}

int SimulatorDialog9X::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SimulatorDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
static const uint qt_meta_data_SimulatorDialogTaranis[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      24,   23,   23,   23, 0x08,
      34,   23,   23,   23, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SimulatorDialogTaranis[] = {
    "SimulatorDialogTaranis\0\0resetSH()\0"
    "on_switchH_sliderReleased()\0"
};

void SimulatorDialogTaranis::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SimulatorDialogTaranis *_t = static_cast<SimulatorDialogTaranis *>(_o);
        switch (_id) {
        case 0: _t->resetSH(); break;
        case 1: _t->on_switchH_sliderReleased(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData SimulatorDialogTaranis::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SimulatorDialogTaranis::staticMetaObject = {
    { &SimulatorDialog::staticMetaObject, qt_meta_stringdata_SimulatorDialogTaranis,
      qt_meta_data_SimulatorDialogTaranis, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SimulatorDialogTaranis::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SimulatorDialogTaranis::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SimulatorDialogTaranis::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SimulatorDialogTaranis))
        return static_cast<void*>(const_cast< SimulatorDialogTaranis*>(this));
    return SimulatorDialog::qt_metacast(_clname);
}

int SimulatorDialogTaranis::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SimulatorDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
