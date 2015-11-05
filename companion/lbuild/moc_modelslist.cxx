/****************************************************************************
** Meta object code from reading C++ file 'modelslist.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/modelslist.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'modelslist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ModelsListWidget[] = {

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
      18,   17,   17,   17, 0x0a,
      36,   32,   17,   17, 0x0a,
      60,   17,   17,   17, 0x0a,
      66,   17,   17,   17, 0x0a,
      73,   17,   17,   17, 0x0a,
      81,   17,   17,   17, 0x0a,
      89,   17,   17,   17, 0x0a,
     101,   17,   17,   17, 0x0a,
     118,   17,   17,   17, 0x0a,
     131,   17,   17,   17, 0x0a,
     144,   17,   17,   17, 0x0a,
     155,   17,   17,   17, 0x0a,
     167,   17,   17,   17, 0x0a,
     184,  180,   17,   17, 0x0a,
     205,   17,   17,   17, 0x0a,
     225,  221,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ModelsListWidget[] = {
    "ModelsListWidget\0\0refreshList()\0pos\0"
    "ShowContextMenu(QPoint)\0cut()\0copy()\0"
    "paste()\0print()\0EditModel()\0"
    "OpenEditWindow()\0LoadBackup()\0"
    "OpenWizard()\0simulate()\0duplicate()\0"
    "setdefault()\0ask\0deleteSelected(bool)\0"
    "confirmDelete()\0idx\0viableModelSelected(int)\0"
};

void ModelsListWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ModelsListWidget *_t = static_cast<ModelsListWidget *>(_o);
        switch (_id) {
        case 0: _t->refreshList(); break;
        case 1: _t->ShowContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 2: _t->cut(); break;
        case 3: _t->copy(); break;
        case 4: _t->paste(); break;
        case 5: _t->print(); break;
        case 6: _t->EditModel(); break;
        case 7: _t->OpenEditWindow(); break;
        case 8: _t->LoadBackup(); break;
        case 9: _t->OpenWizard(); break;
        case 10: _t->simulate(); break;
        case 11: _t->duplicate(); break;
        case 12: _t->setdefault(); break;
        case 13: _t->deleteSelected((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->confirmDelete(); break;
        case 15: _t->viableModelSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ModelsListWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ModelsListWidget::staticMetaObject = {
    { &QListWidget::staticMetaObject, qt_meta_stringdata_ModelsListWidget,
      qt_meta_data_ModelsListWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ModelsListWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ModelsListWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ModelsListWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ModelsListWidget))
        return static_cast<void*>(const_cast< ModelsListWidget*>(this));
    return QListWidget::qt_metacast(_clname);
}

int ModelsListWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
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
