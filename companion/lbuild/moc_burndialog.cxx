/****************************************************************************
** Meta object code from reading C++ file 'burndialog.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/burndialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'burndialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_burnDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      41,   11,   11,   11, 0x08,
      70,   11,   11,   11, 0x08,
      96,   11,   11,   11, 0x08,
     128,  120,   11,   11, 0x08,
     168,  159,  154,   11, 0x08,
     189,   11,   11,   11, 0x08,
     220,   11,   11,   11, 0x08,
     246,   11,   11,   11, 0x08,
     277,   11,   11,   11, 0x08,
     308,  159,   11,   11, 0x08,
     325,   11,   11,   11, 0x08,
     341,   11,   11,   11, 0x08,
     352,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_burnDialog[] = {
    "burnDialog\0\0on_FlashLoadButton_clicked()\0"
    "on_BurnFlashButton_clicked()\0"
    "on_cancelButton_clicked()\0"
    "on_EEbackupCB_clicked()\0checked\0"
    "on_EEpromCB_toggled(bool)\0bool\0fileName\0"
    "checkeEprom(QString)\0"
    "on_useProfileImageCB_clicked()\0"
    "on_useFwImageCB_clicked()\0"
    "on_useLibraryImageCB_clicked()\0"
    "on_useAnotherImageCB_clicked()\0"
    "checkFw(QString)\0displaySplash()\0"
    "updateUI()\0shrink()\0"
};

void burnDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        burnDialog *_t = static_cast<burnDialog *>(_o);
        switch (_id) {
        case 0: _t->on_FlashLoadButton_clicked(); break;
        case 1: _t->on_BurnFlashButton_clicked(); break;
        case 2: _t->on_cancelButton_clicked(); break;
        case 3: _t->on_EEbackupCB_clicked(); break;
        case 4: _t->on_EEpromCB_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: { bool _r = _t->checkeEprom((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: _t->on_useProfileImageCB_clicked(); break;
        case 7: _t->on_useFwImageCB_clicked(); break;
        case 8: _t->on_useLibraryImageCB_clicked(); break;
        case 9: _t->on_useAnotherImageCB_clicked(); break;
        case 10: _t->checkFw((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->displaySplash(); break;
        case 12: _t->updateUI(); break;
        case 13: _t->shrink(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData burnDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject burnDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_burnDialog,
      qt_meta_data_burnDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &burnDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *burnDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *burnDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_burnDialog))
        return static_cast<void*>(const_cast< burnDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int burnDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
