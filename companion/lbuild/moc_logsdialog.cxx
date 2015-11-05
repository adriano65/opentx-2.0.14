/****************************************************************************
** Meta object code from reading C++ file 'logsdialog.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/logsdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'logsdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_logsDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      41,   31,   11,   11, 0x08,
     108,   96,   11,   11, 0x08,
     161,   11,   11,   11, 0x08,
     180,   11,   11,   11, 0x08,
     193,   11,   11,   11, 0x08,
     206,   11,   11,   11, 0x08,
     228,   11,   11,   11, 0x08,
     246,   11,   11,   11, 0x08,
     259,   11,   11,   11, 0x08,
     290,  270,   11,   11, 0x08,
     329,  313,   11,   11, 0x08,
     390,   11,   11,   11, 0x08,
     421,  415,   11,   11, 0x08,
     461,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_logsDialog[] = {
    "logsDialog\0\0titleDoubleClick()\0axis,part\0"
    "axisLabelDoubleClick(QCPAxis*,QCPAxis::SelectablePart)\0"
    "legend,item\0"
    "legendDoubleClick(QCPLegend*,QCPAbstractLegendItem*)\0"
    "selectionChanged()\0mousePress()\0"
    "mouseWheel()\0removeSelectedGraph()\0"
    "removeAllGraphs()\0moveLegend()\0"
    "plotLogs()\0index,plot,numplots\0"
    "plotValue(int,int,int)\0plottable,event\0"
    "plottableItemDoubleClick(QCPAbstractPlottable*,QMouseEvent*)\0"
    "on_fileOpen_BT_clicked()\0index\0"
    "on_sessions_CB_currentIndexChanged(int)\0"
    "on_mapsButton_clicked()\0"
};

void logsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        logsDialog *_t = static_cast<logsDialog *>(_o);
        switch (_id) {
        case 0: _t->titleDoubleClick(); break;
        case 1: _t->axisLabelDoubleClick((*reinterpret_cast< QCPAxis*(*)>(_a[1])),(*reinterpret_cast< QCPAxis::SelectablePart(*)>(_a[2]))); break;
        case 2: _t->legendDoubleClick((*reinterpret_cast< QCPLegend*(*)>(_a[1])),(*reinterpret_cast< QCPAbstractLegendItem*(*)>(_a[2]))); break;
        case 3: _t->selectionChanged(); break;
        case 4: _t->mousePress(); break;
        case 5: _t->mouseWheel(); break;
        case 6: _t->removeSelectedGraph(); break;
        case 7: _t->removeAllGraphs(); break;
        case 8: _t->moveLegend(); break;
        case 9: _t->plotLogs(); break;
        case 10: _t->plotValue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 11: _t->plottableItemDoubleClick((*reinterpret_cast< QCPAbstractPlottable*(*)>(_a[1])),(*reinterpret_cast< QMouseEvent*(*)>(_a[2]))); break;
        case 12: _t->on_fileOpen_BT_clicked(); break;
        case 13: _t->on_sessions_CB_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->on_mapsButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData logsDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject logsDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_logsDialog,
      qt_meta_data_logsDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &logsDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *logsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *logsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_logsDialog))
        return static_cast<void*>(const_cast< logsDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int logsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
