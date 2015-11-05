/****************************************************************************
** Meta object code from reading C++ file 'mixes.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/modeledit/mixes.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mixes.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MixesPanel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      29,   25,   11,   11, 0x08,
      48,   11,   11,   11, 0x28,
      63,   11,   11,   11, 0x08,
      75,   11,   11,   11, 0x08,
      88,   11,   11,   11, 0x08,
     102,   11,   11,   11, 0x08,
     120,   11,   11,   11, 0x08,
     132,   11,   11,   11, 0x08,
     143,   11,   11,   11, 0x08,
     155,   11,   11,   11, 0x08,
     169,   11,   11,   11, 0x08,
     190,  186,   11,   11, 0x08,
     247,  241,   11,   11, 0x08,
     296,  290,   11,   11, 0x08,
     351,  333,   11,   11, 0x08,
     422,  405,   11,   11, 0x08,
     463,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MixesPanel[] = {
    "MixesPanel\0\0clearMixes()\0ask\0"
    "mixersDelete(bool)\0mixersDelete()\0"
    "mixersCut()\0mixersCopy()\0mixersPaste()\0"
    "mixersDuplicate()\0mixerOpen()\0mixerAdd()\0"
    "moveMixUp()\0moveMixDown()\0mixerHighlight()\0"
    "pos\0mixerlistWidget_customContextMenuRequested(QPoint)\0"
    "index\0mixerlistWidget_doubleClicked(QModelIndex)\0"
    "event\0mixerlistWidget_KeyPress(QKeyEvent*)\0"
    "index,data,action\0"
    "mimeMixerDropped(int,const QMimeData*,Qt::DropAction)\0"
    "mimeData,destIdx\0"
    "pasteMixerMimeData(const QMimeData*,int)\0"
    "mixesEdited()\0"
};

void MixesPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MixesPanel *_t = static_cast<MixesPanel *>(_o);
        switch (_id) {
        case 0: _t->clearMixes(); break;
        case 1: _t->mixersDelete((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->mixersDelete(); break;
        case 3: _t->mixersCut(); break;
        case 4: _t->mixersCopy(); break;
        case 5: _t->mixersPaste(); break;
        case 6: _t->mixersDuplicate(); break;
        case 7: _t->mixerOpen(); break;
        case 8: _t->mixerAdd(); break;
        case 9: _t->moveMixUp(); break;
        case 10: _t->moveMixDown(); break;
        case 11: _t->mixerHighlight(); break;
        case 12: _t->mixerlistWidget_customContextMenuRequested((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 13: _t->mixerlistWidget_doubleClicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 14: _t->mixerlistWidget_KeyPress((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 15: _t->mimeMixerDropped((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QMimeData*(*)>(_a[2])),(*reinterpret_cast< Qt::DropAction(*)>(_a[3]))); break;
        case 16: _t->pasteMixerMimeData((*reinterpret_cast< const QMimeData*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 17: _t->mixesEdited(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MixesPanel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MixesPanel::staticMetaObject = {
    { &ModelPanel::staticMetaObject, qt_meta_stringdata_MixesPanel,
      qt_meta_data_MixesPanel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MixesPanel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MixesPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MixesPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MixesPanel))
        return static_cast<void*>(const_cast< MixesPanel*>(this));
    return ModelPanel::qt_metacast(_clname);
}

int MixesPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ModelPanel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
