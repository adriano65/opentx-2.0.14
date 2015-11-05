/****************************************************************************
** Meta object code from reading C++ file 'wizarddialog.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/wizarddialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wizarddialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_WizardDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_WizardDialog[] = {
    "WizardDialog\0\0showHelp()\0"
};

void WizardDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        WizardDialog *_t = static_cast<WizardDialog *>(_o);
        switch (_id) {
        case 0: _t->showHelp(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData WizardDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject WizardDialog::staticMetaObject = {
    { &QWizard::staticMetaObject, qt_meta_stringdata_WizardDialog,
      qt_meta_data_WizardDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &WizardDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *WizardDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *WizardDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WizardDialog))
        return static_cast<void*>(const_cast< WizardDialog*>(this));
    return QWizard::qt_metacast(_clname);
}

int WizardDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWizard::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
static const uint qt_meta_data_StandardPage[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_StandardPage[] = {
    "StandardPage\0"
};

void StandardPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData StandardPage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject StandardPage::staticMetaObject = {
    { &QWizardPage::staticMetaObject, qt_meta_stringdata_StandardPage,
      qt_meta_data_StandardPage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &StandardPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *StandardPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *StandardPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_StandardPage))
        return static_cast<void*>(const_cast< StandardPage*>(this));
    return QWizardPage::qt_metacast(_clname);
}

int StandardPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWizardPage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_ModelSelectionPage[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_ModelSelectionPage[] = {
    "ModelSelectionPage\0"
};

void ModelSelectionPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ModelSelectionPage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ModelSelectionPage::staticMetaObject = {
    { &StandardPage::staticMetaObject, qt_meta_stringdata_ModelSelectionPage,
      qt_meta_data_ModelSelectionPage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ModelSelectionPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ModelSelectionPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ModelSelectionPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ModelSelectionPage))
        return static_cast<void*>(const_cast< ModelSelectionPage*>(this));
    return StandardPage::qt_metacast(_clname);
}

int ModelSelectionPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = StandardPage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_WingtypeSelectionPage[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_WingtypeSelectionPage[] = {
    "WingtypeSelectionPage\0"
};

void WingtypeSelectionPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData WingtypeSelectionPage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject WingtypeSelectionPage::staticMetaObject = {
    { &StandardPage::staticMetaObject, qt_meta_stringdata_WingtypeSelectionPage,
      qt_meta_data_WingtypeSelectionPage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &WingtypeSelectionPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *WingtypeSelectionPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *WingtypeSelectionPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WingtypeSelectionPage))
        return static_cast<void*>(const_cast< WingtypeSelectionPage*>(this));
    return StandardPage::qt_metacast(_clname);
}

int WingtypeSelectionPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = StandardPage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_TailSelectionPage[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_TailSelectionPage[] = {
    "TailSelectionPage\0"
};

void TailSelectionPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData TailSelectionPage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TailSelectionPage::staticMetaObject = {
    { &StandardPage::staticMetaObject, qt_meta_stringdata_TailSelectionPage,
      qt_meta_data_TailSelectionPage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TailSelectionPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TailSelectionPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TailSelectionPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TailSelectionPage))
        return static_cast<void*>(const_cast< TailSelectionPage*>(this));
    return StandardPage::qt_metacast(_clname);
}

int TailSelectionPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = StandardPage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_FlybarSelectionPage[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_FlybarSelectionPage[] = {
    "FlybarSelectionPage\0"
};

void FlybarSelectionPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData FlybarSelectionPage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject FlybarSelectionPage::staticMetaObject = {
    { &StandardPage::staticMetaObject, qt_meta_stringdata_FlybarSelectionPage,
      qt_meta_data_FlybarSelectionPage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FlybarSelectionPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FlybarSelectionPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FlybarSelectionPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FlybarSelectionPage))
        return static_cast<void*>(const_cast< FlybarSelectionPage*>(this));
    return StandardPage::qt_metacast(_clname);
}

int FlybarSelectionPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = StandardPage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_ThrottlePage[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,   14,   13,   13, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_ThrottlePage[] = {
    "ThrottlePage\0\0toggled\0onMotorStateChanged(bool)\0"
};

void ThrottlePage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ThrottlePage *_t = static_cast<ThrottlePage *>(_o);
        switch (_id) {
        case 0: _t->onMotorStateChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ThrottlePage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ThrottlePage::staticMetaObject = {
    { &StandardPage::staticMetaObject, qt_meta_stringdata_ThrottlePage,
      qt_meta_data_ThrottlePage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ThrottlePage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ThrottlePage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ThrottlePage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ThrottlePage))
        return static_cast<void*>(const_cast< ThrottlePage*>(this));
    return StandardPage::qt_metacast(_clname);
}

int ThrottlePage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = StandardPage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
static const uint qt_meta_data_AileronsPage[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x09,
      33,   13,   13,   13, 0x09,
      53,   13,   13,   13, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_AileronsPage[] = {
    "AileronsPage\0\0noAileronChannel()\0"
    "oneAileronChannel()\0twoAileronChannels()\0"
};

void AileronsPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AileronsPage *_t = static_cast<AileronsPage *>(_o);
        switch (_id) {
        case 0: _t->noAileronChannel(); break;
        case 1: _t->oneAileronChannel(); break;
        case 2: _t->twoAileronChannels(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData AileronsPage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AileronsPage::staticMetaObject = {
    { &StandardPage::staticMetaObject, qt_meta_stringdata_AileronsPage,
      qt_meta_data_AileronsPage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AileronsPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AileronsPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AileronsPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AileronsPage))
        return static_cast<void*>(const_cast< AileronsPage*>(this));
    return StandardPage::qt_metacast(_clname);
}

int AileronsPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = StandardPage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
static const uint qt_meta_data_FlapsPage[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x09,
      27,   10,   10,   10, 0x09,
      44,   10,   10,   10, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_FlapsPage[] = {
    "FlapsPage\0\0noFlapChannel()\0oneFlapChannel()\0"
    "twoFlapChannels()\0"
};

void FlapsPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        FlapsPage *_t = static_cast<FlapsPage *>(_o);
        switch (_id) {
        case 0: _t->noFlapChannel(); break;
        case 1: _t->oneFlapChannel(); break;
        case 2: _t->twoFlapChannels(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData FlapsPage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject FlapsPage::staticMetaObject = {
    { &StandardPage::staticMetaObject, qt_meta_stringdata_FlapsPage,
      qt_meta_data_FlapsPage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FlapsPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FlapsPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FlapsPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FlapsPage))
        return static_cast<void*>(const_cast< FlapsPage*>(this));
    return StandardPage::qt_metacast(_clname);
}

int FlapsPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = StandardPage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
static const uint qt_meta_data_AirbrakesPage[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x09,
      35,   14,   14,   14, 0x09,
      56,   14,   14,   14, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_AirbrakesPage[] = {
    "AirbrakesPage\0\0noAirbrakeChannel()\0"
    "oneAirbrakeChannel()\0twoAirbrakeChannels()\0"
};

void AirbrakesPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AirbrakesPage *_t = static_cast<AirbrakesPage *>(_o);
        switch (_id) {
        case 0: _t->noAirbrakeChannel(); break;
        case 1: _t->oneAirbrakeChannel(); break;
        case 2: _t->twoAirbrakeChannels(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData AirbrakesPage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AirbrakesPage::staticMetaObject = {
    { &StandardPage::staticMetaObject, qt_meta_stringdata_AirbrakesPage,
      qt_meta_data_AirbrakesPage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AirbrakesPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AirbrakesPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AirbrakesPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AirbrakesPage))
        return static_cast<void*>(const_cast< AirbrakesPage*>(this));
    return StandardPage::qt_metacast(_clname);
}

int AirbrakesPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = StandardPage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
static const uint qt_meta_data_ElevonsPage[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_ElevonsPage[] = {
    "ElevonsPage\0"
};

void ElevonsPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ElevonsPage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ElevonsPage::staticMetaObject = {
    { &StandardPage::staticMetaObject, qt_meta_stringdata_ElevonsPage,
      qt_meta_data_ElevonsPage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ElevonsPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ElevonsPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ElevonsPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ElevonsPage))
        return static_cast<void*>(const_cast< ElevonsPage*>(this));
    return StandardPage::qt_metacast(_clname);
}

int ElevonsPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = StandardPage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_RudderPage[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x09,
      23,   11,   11,   11, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_RudderPage[] = {
    "RudderPage\0\0noRudder()\0hasRudder()\0"
};

void RudderPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RudderPage *_t = static_cast<RudderPage *>(_o);
        switch (_id) {
        case 0: _t->noRudder(); break;
        case 1: _t->hasRudder(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData RudderPage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RudderPage::staticMetaObject = {
    { &StandardPage::staticMetaObject, qt_meta_stringdata_RudderPage,
      qt_meta_data_RudderPage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RudderPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RudderPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RudderPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RudderPage))
        return static_cast<void*>(const_cast< RudderPage*>(this));
    return StandardPage::qt_metacast(_clname);
}

int RudderPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = StandardPage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
static const uint qt_meta_data_TailPage[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_TailPage[] = {
    "TailPage\0"
};

void TailPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData TailPage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TailPage::staticMetaObject = {
    { &StandardPage::staticMetaObject, qt_meta_stringdata_TailPage,
      qt_meta_data_TailPage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TailPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TailPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TailPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TailPage))
        return static_cast<void*>(const_cast< TailPage*>(this));
    return StandardPage::qt_metacast(_clname);
}

int TailPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = StandardPage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_VTailPage[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_VTailPage[] = {
    "VTailPage\0"
};

void VTailPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData VTailPage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject VTailPage::staticMetaObject = {
    { &StandardPage::staticMetaObject, qt_meta_stringdata_VTailPage,
      qt_meta_data_VTailPage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VTailPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VTailPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VTailPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VTailPage))
        return static_cast<void*>(const_cast< VTailPage*>(this));
    return StandardPage::qt_metacast(_clname);
}

int VTailPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = StandardPage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_SimpleTailPage[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_SimpleTailPage[] = {
    "SimpleTailPage\0"
};

void SimpleTailPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData SimpleTailPage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SimpleTailPage::staticMetaObject = {
    { &StandardPage::staticMetaObject, qt_meta_stringdata_SimpleTailPage,
      qt_meta_data_SimpleTailPage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SimpleTailPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SimpleTailPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SimpleTailPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SimpleTailPage))
        return static_cast<void*>(const_cast< SimpleTailPage*>(this));
    return StandardPage::qt_metacast(_clname);
}

int SimpleTailPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = StandardPage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_CyclicPage[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_CyclicPage[] = {
    "CyclicPage\0"
};

void CyclicPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData CyclicPage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CyclicPage::staticMetaObject = {
    { &StandardPage::staticMetaObject, qt_meta_stringdata_CyclicPage,
      qt_meta_data_CyclicPage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CyclicPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CyclicPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CyclicPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CyclicPage))
        return static_cast<void*>(const_cast< CyclicPage*>(this));
    return StandardPage::qt_metacast(_clname);
}

int CyclicPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = StandardPage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_GyroPage[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_GyroPage[] = {
    "GyroPage\0"
};

void GyroPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData GyroPage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GyroPage::staticMetaObject = {
    { &StandardPage::staticMetaObject, qt_meta_stringdata_GyroPage,
      qt_meta_data_GyroPage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GyroPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GyroPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GyroPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GyroPage))
        return static_cast<void*>(const_cast< GyroPage*>(this));
    return StandardPage::qt_metacast(_clname);
}

int GyroPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = StandardPage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_FblPage[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_FblPage[] = {
    "FblPage\0"
};

void FblPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData FblPage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject FblPage::staticMetaObject = {
    { &StandardPage::staticMetaObject, qt_meta_stringdata_FblPage,
      qt_meta_data_FblPage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FblPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FblPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FblPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FblPage))
        return static_cast<void*>(const_cast< FblPage*>(this));
    return StandardPage::qt_metacast(_clname);
}

int FblPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = StandardPage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_HeliPage[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_HeliPage[] = {
    "HeliPage\0"
};

void HeliPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData HeliPage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject HeliPage::staticMetaObject = {
    { &StandardPage::staticMetaObject, qt_meta_stringdata_HeliPage,
      qt_meta_data_HeliPage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &HeliPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *HeliPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *HeliPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HeliPage))
        return static_cast<void*>(const_cast< HeliPage*>(this));
    return StandardPage::qt_metacast(_clname);
}

int HeliPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = StandardPage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_MultirotorPage[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_MultirotorPage[] = {
    "MultirotorPage\0"
};

void MultirotorPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MultirotorPage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MultirotorPage::staticMetaObject = {
    { &StandardPage::staticMetaObject, qt_meta_stringdata_MultirotorPage,
      qt_meta_data_MultirotorPage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MultirotorPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MultirotorPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MultirotorPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MultirotorPage))
        return static_cast<void*>(const_cast< MultirotorPage*>(this));
    return StandardPage::qt_metacast(_clname);
}

int MultirotorPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = StandardPage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_OptionsPage[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_OptionsPage[] = {
    "OptionsPage\0"
};

void OptionsPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData OptionsPage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject OptionsPage::staticMetaObject = {
    { &StandardPage::staticMetaObject, qt_meta_stringdata_OptionsPage,
      qt_meta_data_OptionsPage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &OptionsPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *OptionsPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *OptionsPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OptionsPage))
        return static_cast<void*>(const_cast< OptionsPage*>(this));
    return StandardPage::qt_metacast(_clname);
}

int OptionsPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = StandardPage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_ConclusionPage[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_ConclusionPage[] = {
    "ConclusionPage\0"
};

void ConclusionPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ConclusionPage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ConclusionPage::staticMetaObject = {
    { &StandardPage::staticMetaObject, qt_meta_stringdata_ConclusionPage,
      qt_meta_data_ConclusionPage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ConclusionPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ConclusionPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ConclusionPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ConclusionPage))
        return static_cast<void*>(const_cast< ConclusionPage*>(this));
    return StandardPage::qt_metacast(_clname);
}

int ConclusionPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = StandardPage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_WizardPrinter[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_WizardPrinter[] = {
    "WizardPrinter\0"
};

void WizardPrinter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData WizardPrinter::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject WizardPrinter::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_WizardPrinter,
      qt_meta_data_WizardPrinter, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &WizardPrinter::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *WizardPrinter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *WizardPrinter::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WizardPrinter))
        return static_cast<void*>(const_cast< WizardPrinter*>(this));
    return QObject::qt_metacast(_clname);
}

int WizardPrinter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
