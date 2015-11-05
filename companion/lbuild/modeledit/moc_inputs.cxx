/****************************************************************************
** Meta object code from reading C++ file 'inputs.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/modeledit/inputs.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'inputs.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_InputsPanel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      26,   12,   12,   12, 0x08,
      39,   12,   12,   12, 0x08,
      72,   54,   12,   12, 0x08,
     129,  125,   12,   12, 0x08,
     185,  179,   12,   12, 0x08,
     233,  227,   12,   12, 0x08,
     273,  269,   12,   12, 0x08,
     291,   12,   12,   12, 0x28,
     305,   12,   12,   12, 0x08,
     316,   12,   12,   12, 0x08,
     328,   12,   12,   12, 0x08,
     341,   12,   12,   12, 0x08,
     363,  358,   12,   12, 0x08,
     390,   12,   12,   12, 0x28,
     401,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_InputsPanel[] = {
    "InputsPanel\0\0clearExpos()\0moveExpoUp()\0"
    "moveExpoDown()\0index,data,action\0"
    "mimeExpoDropped(int,const QMimeData*,Qt::DropAction)\0"
    "pos\0expolistWidget_customContextMenuRequested(QPoint)\0"
    "index\0expolistWidget_doubleClicked(QModelIndex)\0"
    "event\0expolistWidget_KeyPress(QKeyEvent*)\0"
    "ask\0exposDelete(bool)\0exposDelete()\0"
    "exposCut()\0exposCopy()\0exposPaste()\0"
    "exposDuplicate()\0item\0expoOpen(QListWidgetItem*)\0"
    "expoOpen()\0expoAdd()\0"
};

void InputsPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        InputsPanel *_t = static_cast<InputsPanel *>(_o);
        switch (_id) {
        case 0: _t->clearExpos(); break;
        case 1: _t->moveExpoUp(); break;
        case 2: _t->moveExpoDown(); break;
        case 3: _t->mimeExpoDropped((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QMimeData*(*)>(_a[2])),(*reinterpret_cast< Qt::DropAction(*)>(_a[3]))); break;
        case 4: _t->expolistWidget_customContextMenuRequested((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 5: _t->expolistWidget_doubleClicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 6: _t->expolistWidget_KeyPress((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 7: _t->exposDelete((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->exposDelete(); break;
        case 9: _t->exposCut(); break;
        case 10: _t->exposCopy(); break;
        case 11: _t->exposPaste(); break;
        case 12: _t->exposDuplicate(); break;
        case 13: _t->expoOpen((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 14: _t->expoOpen(); break;
        case 15: _t->expoAdd(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData InputsPanel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject InputsPanel::staticMetaObject = {
    { &ModelPanel::staticMetaObject, qt_meta_stringdata_InputsPanel,
      qt_meta_data_InputsPanel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &InputsPanel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *InputsPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *InputsPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_InputsPanel))
        return static_cast<void*>(const_cast< InputsPanel*>(this));
    return ModelPanel::qt_metacast(_clname);
}

int InputsPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ModelPanel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
