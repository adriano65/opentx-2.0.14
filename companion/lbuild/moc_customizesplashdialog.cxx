/****************************************************************************
** Meta object code from reading C++ file 'customizesplashdialog.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/customizesplashdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'customizesplashdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_customizeSplashDialog[] = {

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
      23,   22,   22,   22, 0x08,
      53,   22,   22,   22, 0x08,
      85,   22,   22,   22, 0x08,
     120,   22,   22,   22, 0x08,
     151,   22,   22,   22, 0x08,
     179,   22,   22,   22, 0x08,
     209,   22,   22,   22, 0x08,
     240,   22,   22,   22, 0x08,
     273,   22,   22,   22, 0x08,
     309,   22,   22,   22, 0x08,
     341,   22,   22,   22, 0x08,
     370,   22,   22,   22, 0x08,
     401,   22,   22,   22, 0x08,
     436,   22,   22,   22, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_customizeSplashDialog[] = {
    "customizeSplashDialog\0\0"
    "on_leftLoadFwButton_clicked()\0"
    "on_leftLoadPictButton_clicked()\0"
    "on_leftLoadProfileButton_clicked()\0"
    "on_leftLibraryButton_clicked()\0"
    "on_leftSaveButton_clicked()\0"
    "on_leftInvertButton_clicked()\0"
    "on_rightLoadFwButton_clicked()\0"
    "on_rightLoadPictButton_clicked()\0"
    "on_rightLoadProfileButton_clicked()\0"
    "on_rightLibraryButton_clicked()\0"
    "on_rightSaveButton_clicked()\0"
    "on_rightInvertButton_clicked()\0"
    "on_copyRightToLeftButton_clicked()\0"
    "on_copyLeftToRightButton_clicked()\0"
};

void customizeSplashDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        customizeSplashDialog *_t = static_cast<customizeSplashDialog *>(_o);
        switch (_id) {
        case 0: _t->on_leftLoadFwButton_clicked(); break;
        case 1: _t->on_leftLoadPictButton_clicked(); break;
        case 2: _t->on_leftLoadProfileButton_clicked(); break;
        case 3: _t->on_leftLibraryButton_clicked(); break;
        case 4: _t->on_leftSaveButton_clicked(); break;
        case 5: _t->on_leftInvertButton_clicked(); break;
        case 6: _t->on_rightLoadFwButton_clicked(); break;
        case 7: _t->on_rightLoadPictButton_clicked(); break;
        case 8: _t->on_rightLoadProfileButton_clicked(); break;
        case 9: _t->on_rightLibraryButton_clicked(); break;
        case 10: _t->on_rightSaveButton_clicked(); break;
        case 11: _t->on_rightInvertButton_clicked(); break;
        case 12: _t->on_copyRightToLeftButton_clicked(); break;
        case 13: _t->on_copyLeftToRightButton_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData customizeSplashDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject customizeSplashDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_customizeSplashDialog,
      qt_meta_data_customizeSplashDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &customizeSplashDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *customizeSplashDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *customizeSplashDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_customizeSplashDialog))
        return static_cast<void*>(const_cast< customizeSplashDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int customizeSplashDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
