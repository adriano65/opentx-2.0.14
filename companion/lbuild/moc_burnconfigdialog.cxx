/****************************************************************************
** Meta object code from reading C++ file 'burnconfigdialog.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/burnconfigdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'burnconfigdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_burnConfigDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x08,
      27,   17,   17,   17, 0x08,
      56,   17,   17,   17, 0x08,
      82,   17,   17,   17, 0x08,
     108,   17,   17,   17, 0x08,
     132,   17,   17,   17, 0x08,
     170,   17,   17,   17, 0x08,
     221,   17,   17,   17, 0x08,
     265,   17,   17,   17, 0x08,
     310,   17,   17,   17, 0x08,
     346,   17,   17,   17, 0x08,
     378,   17,   17,   17, 0x08,
     418,   17,   17,   17, 0x08,
     441,   17,   17,   17, 0x08,
     465,   17,   17,   17, 0x08,
     499,   17,   17,   17, 0x08,
     536,  528,   17,   17, 0x08,
     564,   17,   17,   17, 0x08,
     578,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_burnConfigDialog[] = {
    "burnConfigDialog\0\0shrink()\0"
    "on_avrArgs_editingFinished()\0"
    "on_pushButton_4_clicked()\0"
    "on_pushButton_3_clicked()\0"
    "on_pushButton_clicked()\0"
    "on_avrdude_location_editingFinished()\0"
    "on_avrdude_programmer_currentIndexChanged(QString)\0"
    "on_avrdude_mcu_currentIndexChanged(QString)\0"
    "on_avrdude_port_currentIndexChanged(QString)\0"
    "on_samba_location_editingFinished()\0"
    "on_samba_port_editingFinished()\0"
    "on_arm_mcu_currentIndexChanged(QString)\0"
    "on_sb_browse_clicked()\0on_dfu_browse_clicked()\0"
    "on_dfu_location_editingFinished()\0"
    "on_dfuArgs_editingFinished()\0checked\0"
    "on_advCtrChkB_toggled(bool)\0getSettings()\0"
    "putSettings()\0"
};

void burnConfigDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        burnConfigDialog *_t = static_cast<burnConfigDialog *>(_o);
        switch (_id) {
        case 0: _t->shrink(); break;
        case 1: _t->on_avrArgs_editingFinished(); break;
        case 2: _t->on_pushButton_4_clicked(); break;
        case 3: _t->on_pushButton_3_clicked(); break;
        case 4: _t->on_pushButton_clicked(); break;
        case 5: _t->on_avrdude_location_editingFinished(); break;
        case 6: _t->on_avrdude_programmer_currentIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->on_avrdude_mcu_currentIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->on_avrdude_port_currentIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->on_samba_location_editingFinished(); break;
        case 10: _t->on_samba_port_editingFinished(); break;
        case 11: _t->on_arm_mcu_currentIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->on_sb_browse_clicked(); break;
        case 13: _t->on_dfu_browse_clicked(); break;
        case 14: _t->on_dfu_location_editingFinished(); break;
        case 15: _t->on_dfuArgs_editingFinished(); break;
        case 16: _t->on_advCtrChkB_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->getSettings(); break;
        case 18: _t->putSettings(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData burnConfigDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject burnConfigDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_burnConfigDialog,
      qt_meta_data_burnConfigDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &burnConfigDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *burnConfigDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *burnConfigDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_burnConfigDialog))
        return static_cast<void*>(const_cast< burnConfigDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int burnConfigDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
