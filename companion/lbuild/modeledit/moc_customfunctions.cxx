/****************************************************************************
** Meta object code from reading C++ file 'customfunctions.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/modeledit/customfunctions.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'customfunctions.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RepeatComboBox[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      27,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_RepeatComboBox[] = {
    "RepeatComboBox\0\0modified()\0"
    "onIndexChanged(int)\0"
};

void RepeatComboBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RepeatComboBox *_t = static_cast<RepeatComboBox *>(_o);
        switch (_id) {
        case 0: _t->modified(); break;
        case 1: _t->onIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData RepeatComboBox::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RepeatComboBox::staticMetaObject = {
    { &QComboBox::staticMetaObject, qt_meta_stringdata_RepeatComboBox,
      qt_meta_data_RepeatComboBox, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RepeatComboBox::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RepeatComboBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RepeatComboBox::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RepeatComboBox))
        return static_cast<void*>(const_cast< RepeatComboBox*>(this));
    return QComboBox::qt_metacast(_clname);
}

int RepeatComboBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QComboBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void RepeatComboBox::modified()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
static const uint qt_meta_data_CustomFunctionsPanel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,   21,   21,   21, 0x08,
      45,   21,   21,   21, 0x08,
      66,   62,   21,   21, 0x08,
     120,  105,   21,   21, 0x08,
     158,  152,   21,   21, 0x28,
     185,   21,   21,   21, 0x08,
     203,   21,   21,   21, 0x08,
     233,  215,   21,   21, 0x08,
     280,   21,   21,   21, 0x08,
     292,   21,   21,   21, 0x08,
     302,   21,   21,   21, 0x08,
     313,   21,   21,   21, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CustomFunctionsPanel[] = {
    "CustomFunctionsPanel\0\0customFunctionEdited()\0"
    "functionEdited()\0pos\0"
    "fsw_customContextMenuRequested(QPoint)\0"
    "index,modified\0refreshCustomFunction(int,bool)\0"
    "index\0refreshCustomFunction(int)\0"
    "onChildModified()\0playMusic()\0"
    "newState,oldState\0"
    "mediaPlayer_state(Phonon::State,Phonon::State)\0"
    "fswDelete()\0fswCopy()\0fswPaste()\0"
    "fswCut()\0"
};

void CustomFunctionsPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CustomFunctionsPanel *_t = static_cast<CustomFunctionsPanel *>(_o);
        switch (_id) {
        case 0: _t->customFunctionEdited(); break;
        case 1: _t->functionEdited(); break;
        case 2: _t->fsw_customContextMenuRequested((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 3: _t->refreshCustomFunction((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: _t->refreshCustomFunction((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->onChildModified(); break;
        case 6: _t->playMusic(); break;
        case 7: _t->mediaPlayer_state((*reinterpret_cast< Phonon::State(*)>(_a[1])),(*reinterpret_cast< Phonon::State(*)>(_a[2]))); break;
        case 8: _t->fswDelete(); break;
        case 9: _t->fswCopy(); break;
        case 10: _t->fswPaste(); break;
        case 11: _t->fswCut(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CustomFunctionsPanel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CustomFunctionsPanel::staticMetaObject = {
    { &ModelPanel::staticMetaObject, qt_meta_stringdata_CustomFunctionsPanel,
      qt_meta_data_CustomFunctionsPanel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CustomFunctionsPanel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CustomFunctionsPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CustomFunctionsPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CustomFunctionsPanel))
        return static_cast<void*>(const_cast< CustomFunctionsPanel*>(this));
    return ModelPanel::qt_metacast(_clname);
}

int CustomFunctionsPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ModelPanel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
