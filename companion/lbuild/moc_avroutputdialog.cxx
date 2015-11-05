/****************************************************************************
** Meta object code from reading C++ file 'avroutputdialog.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/avroutputdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'avroutputdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_avrOutputDialog[] = {

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
      17,   16,   16,   16, 0x09,
      35,   16,   16,   16, 0x09,
      53,   16,   16,   16, 0x09,
      72,   16,   16,   16, 0x09,
      86,   81,   16,   16, 0x09,
     110,  102,   16,   16, 0x09,
     136,   16,   16,   16, 0x09,
     145,   16,   16,   16, 0x09,
     158,   16,   16,   16, 0x09,
     177,   16,   16,   16, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_avrOutputDialog[] = {
    "avrOutputDialog\0\0doAddTextStdOut()\0"
    "doAddTextStdErr()\0doProcessStarted()\0"
    "doCopy()\0code\0doFinished(int)\0checked\0"
    "on_checkBox_toggled(bool)\0shrink()\0"
    "forceClose()\0killTimerElapsed()\0"
    "errorWizard()\0"
};

void avrOutputDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        avrOutputDialog *_t = static_cast<avrOutputDialog *>(_o);
        switch (_id) {
        case 0: _t->doAddTextStdOut(); break;
        case 1: _t->doAddTextStdErr(); break;
        case 2: _t->doProcessStarted(); break;
        case 3: _t->doCopy(); break;
        case 4: _t->doFinished((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_checkBox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->shrink(); break;
        case 7: _t->forceClose(); break;
        case 8: _t->killTimerElapsed(); break;
        case 9: _t->errorWizard(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData avrOutputDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject avrOutputDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_avrOutputDialog,
      qt_meta_data_avrOutputDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &avrOutputDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *avrOutputDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *avrOutputDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_avrOutputDialog))
        return static_cast<void*>(const_cast< avrOutputDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int avrOutputDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
