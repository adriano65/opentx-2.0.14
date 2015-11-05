/****************************************************************************
** Meta object code from reading C++ file 'downloaddialog.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/downloaddialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'downloaddialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_downloadDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      28,   15,   15,   15, 0x08,
      43,   15,   15,   15, 0x08,
      80,   59,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_downloadDialog[] = {
    "downloadDialog\0\0fileError()\0httpFinished()\0"
    "httpReadyRead()\0bytesRead,totalBytes\0"
    "updateDataReadProgress(qint64,qint64)\0"
};

void downloadDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        downloadDialog *_t = static_cast<downloadDialog *>(_o);
        switch (_id) {
        case 0: _t->fileError(); break;
        case 1: _t->httpFinished(); break;
        case 2: _t->httpReadyRead(); break;
        case 3: _t->updateDataReadProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData downloadDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject downloadDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_downloadDialog,
      qt_meta_data_downloadDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &downloadDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *downloadDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *downloadDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_downloadDialog))
        return static_cast<void*>(const_cast< downloadDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int downloadDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
