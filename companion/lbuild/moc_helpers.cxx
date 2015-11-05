/****************************************************************************
** Meta object code from reading C++ file 'helpers.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/helpers.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'helpers.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GVarGroup[] = {

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
      11,   10,   10,   10, 0x09,
      30,   10,   10,   10, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_GVarGroup[] = {
    "GVarGroup\0\0gvarCBChanged(int)\0"
    "valuesChanged()\0"
};

void GVarGroup::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GVarGroup *_t = static_cast<GVarGroup *>(_o);
        switch (_id) {
        case 0: _t->gvarCBChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->valuesChanged(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData GVarGroup::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GVarGroup::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GVarGroup,
      qt_meta_data_GVarGroup, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GVarGroup::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GVarGroup::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GVarGroup::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GVarGroup))
        return static_cast<void*>(const_cast< GVarGroup*>(this));
    return QObject::qt_metacast(_clname);
}

int GVarGroup::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
static const uint qt_meta_data_CurveGroup[] = {

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
      12,   11,   11,   11, 0x09,
      31,   11,   11,   11, 0x09,
      48,   11,   11,   11, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_CurveGroup[] = {
    "CurveGroup\0\0gvarCBChanged(int)\0"
    "typeChanged(int)\0valuesChanged()\0"
};

void CurveGroup::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CurveGroup *_t = static_cast<CurveGroup *>(_o);
        switch (_id) {
        case 0: _t->gvarCBChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->typeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->valuesChanged(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CurveGroup::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CurveGroup::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CurveGroup,
      qt_meta_data_CurveGroup, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CurveGroup::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CurveGroup::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CurveGroup::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CurveGroup))
        return static_cast<void*>(const_cast< CurveGroup*>(this));
    return QObject::qt_metacast(_clname);
}

int CurveGroup::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
