/****************************************************************************
** Meta object code from reading C++ file 'paperSetting.h'
**
** Created: Wed Jul 18 00:24:28 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "paperSetting.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'paperSetting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_paperSetting[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   14,   13,   13, 0x05,
      35,   13,   13,   13, 0x05,
      49,   13,   13,   13, 0x05,
      68,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      95,   13,   13,   13, 0x08,
     108,   13,   13,   13, 0x08,
     117,   13,   13,   13, 0x08,
     126,   13,   13,   13, 0x08,
     140,   14,   13,   13, 0x08,
     154,   13,   13,   13, 0x08,
     170,   13,   13,   13, 0x08,
     187,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_paperSetting[] = {
    "paperSetting\0\0pp\0readyPaper(paper)\0"
    "requireInfo()\0valueChanged(bool)\0"
    "sendActionType(canvas::AT)\0hasChanged()\0"
    "setURL()\0delURL()\0createPaper()\0"
    "reset(paper&)\0setDrawAction()\0"
    "setEraseAction()\0setNoneAction()\0"
};

void paperSetting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        paperSetting *_t = static_cast<paperSetting *>(_o);
        switch (_id) {
        case 0: _t->readyPaper((*reinterpret_cast< paper(*)>(_a[1]))); break;
        case 1: _t->requireInfo(); break;
        case 2: _t->valueChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->sendActionType((*reinterpret_cast< canvas::AT(*)>(_a[1]))); break;
        case 4: _t->hasChanged(); break;
        case 5: _t->setURL(); break;
        case 6: _t->delURL(); break;
        case 7: _t->createPaper(); break;
        case 8: _t->reset((*reinterpret_cast< paper(*)>(_a[1]))); break;
        case 9: _t->setDrawAction(); break;
        case 10: _t->setEraseAction(); break;
        case 11: _t->setNoneAction(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData paperSetting::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject paperSetting::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_paperSetting,
      qt_meta_data_paperSetting, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &paperSetting::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *paperSetting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *paperSetting::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_paperSetting))
        return static_cast<void*>(const_cast< paperSetting*>(this));
    return QWidget::qt_metacast(_clname);
}

int paperSetting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void paperSetting::readyPaper(paper _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void paperSetting::requireInfo()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void paperSetting::valueChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void paperSetting::sendActionType(canvas::AT _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
