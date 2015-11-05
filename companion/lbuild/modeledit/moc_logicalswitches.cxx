/****************************************************************************
** Meta object code from reading C++ file 'logicalswitches.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/modeledit/logicalswitches.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'logicalswitches.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LogicalSwitchesPanel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,   21,   21,   21, 0x08,
      37,   31,   21,   21, 0x08,
      51,   31,   21,   21, 0x08,
      65,   31,   21,   21, 0x08,
      89,   80,   21,   21, 0x08,
     118,  112,   21,   21, 0x08,
     142,  138,   21,   21, 0x08,
     181,   21,   21,   21, 0x08,
     193,   21,   21,   21, 0x08,
     203,   21,   21,   21, 0x08,
     214,   21,   21,   21, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_LogicalSwitchesPanel[] = {
    "LogicalSwitchesPanel\0\0edited()\0value\0"
    "v1Edited(int)\0v2Edited(int)\0andEdited(int)\0"
    "duration\0durationEdited(double)\0delay\0"
    "delayEdited(double)\0pos\0"
    "csw_customContextMenuRequested(QPoint)\0"
    "cswDelete()\0cswCopy()\0cswPaste()\0"
    "cswCut()\0"
};

void LogicalSwitchesPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LogicalSwitchesPanel *_t = static_cast<LogicalSwitchesPanel *>(_o);
        switch (_id) {
        case 0: _t->edited(); break;
        case 1: _t->v1Edited((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->v2Edited((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->andEdited((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->durationEdited((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->delayEdited((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->csw_customContextMenuRequested((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 7: _t->cswDelete(); break;
        case 8: _t->cswCopy(); break;
        case 9: _t->cswPaste(); break;
        case 10: _t->cswCut(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData LogicalSwitchesPanel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LogicalSwitchesPanel::staticMetaObject = {
    { &ModelPanel::staticMetaObject, qt_meta_stringdata_LogicalSwitchesPanel,
      qt_meta_data_LogicalSwitchesPanel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LogicalSwitchesPanel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LogicalSwitchesPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LogicalSwitchesPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LogicalSwitchesPanel))
        return static_cast<void*>(const_cast< LogicalSwitchesPanel*>(this));
    return ModelPanel::qt_metacast(_clname);
}

int LogicalSwitchesPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
