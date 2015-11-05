/****************************************************************************
** Meta object code from reading C++ file 'mdichild.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/mdichild.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mdichild.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MdiChild[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   10,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      34,    9,    9,    9, 0x08,
      56,    9,    9,    9, 0x08,
      89,   86,    9,    9, 0x08,
     105,  101,    9,    9, 0x0a,
     128,    9,    9,    9, 0x0a,
     142,    9,    9,    9, 0x0a,
     154,    9,    9,    9, 0x0a,
     167,    9,    9,    9, 0x0a,
     184,    9,    9,    9, 0x0a,
     190,    9,    9,    9, 0x0a,
     197,    9,    9,    9, 0x0a,
     205,    9,    9,    9, 0x0a,
     219,    9,    9,    9, 0x0a,
     245,  230,    9,    9, 0x0a,
     270,  264,    9,    9, 0x2a,
     281,    9,    9,    9, 0x2a,
     289,    9,    9,    9, 0x0a,
     303,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MdiChild[] = {
    "MdiChild\0\0val\0copyAvailable(bool)\0"
    "documentWasModified()\0"
    "on_SimulateTxButton_clicked()\0ms\0"
    "qSleep(int)\0row\0checkAndInitModel(int)\0"
    "generalEdit()\0modelEdit()\0wizardEdit()\0"
    "openEditWindow()\0cut()\0copy()\0paste()\0"
    "writeEeprom()\0simulate()\0model,filename\0"
    "print(int,QString)\0model\0print(int)\0"
    "print()\0setModified()\0updateTitle()\0"
};

void MdiChild::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MdiChild *_t = static_cast<MdiChild *>(_o);
        switch (_id) {
        case 0: _t->copyAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->documentWasModified(); break;
        case 2: _t->on_SimulateTxButton_clicked(); break;
        case 3: _t->qSleep((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->checkAndInitModel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->generalEdit(); break;
        case 6: _t->modelEdit(); break;
        case 7: _t->wizardEdit(); break;
        case 8: _t->openEditWindow(); break;
        case 9: _t->cut(); break;
        case 10: _t->copy(); break;
        case 11: _t->paste(); break;
        case 12: _t->writeEeprom(); break;
        case 13: _t->simulate(); break;
        case 14: _t->print((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 15: _t->print((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->print(); break;
        case 17: _t->setModified(); break;
        case 18: _t->updateTitle(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MdiChild::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MdiChild::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MdiChild,
      qt_meta_data_MdiChild, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MdiChild::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MdiChild::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MdiChild::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MdiChild))
        return static_cast<void*>(const_cast< MdiChild*>(this));
    return QWidget::qt_metacast(_clname);
}

int MdiChild::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void MdiChild::copyAvailable(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
