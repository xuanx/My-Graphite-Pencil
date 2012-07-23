/****************************************************************************
** Meta object code from reading C++ file 'eraserSetting.h'
**
** Created: Wed Jul 18 00:24:27 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "eraserSetting.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'eraserSetting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_eraserSetting[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   15,   14,   14, 0x05,
      43,   37,   14,   14, 0x05,
      60,   14,   14,   14, 0x05,
      74,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      89,   14,   14,   14, 0x08,
      97,   14,   14,   14, 0x08,
     110,   14,   14,   14, 0x08,
     125,   14,   14,   14, 0x08,
     141,   14,   14,   14, 0x08,
     156,   14,   14,   14, 0x08,
     169,   14,   14,   14, 0x08,
     178,   14,   14,   14, 0x08,
     191,  189,   14,   14, 0x08,
     211,  189,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_eraserSetting[] = {
    "eraserSetting\0\0en\0sendEraser(eraser)\0"
    "angle\0sendAngle(float)\0sizeChanged()\0"
    "valueChanged()\0reset()\0resetAngle()\0"
    "angleChanged()\0setAllEnabled()\0"
    "createEraser()\0hasChanged()\0reSize()\0"
    "toRotate()\0s\0setShapeState(bool)\0"
    "setPenState(bool)\0"
};

void eraserSetting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        eraserSetting *_t = static_cast<eraserSetting *>(_o);
        switch (_id) {
        case 0: _t->sendEraser((*reinterpret_cast< eraser(*)>(_a[1]))); break;
        case 1: _t->sendAngle((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 2: _t->sizeChanged(); break;
        case 3: _t->valueChanged(); break;
        case 4: _t->reset(); break;
        case 5: _t->resetAngle(); break;
        case 6: _t->angleChanged(); break;
        case 7: _t->setAllEnabled(); break;
        case 8: _t->createEraser(); break;
        case 9: _t->hasChanged(); break;
        case 10: _t->reSize(); break;
        case 11: _t->toRotate(); break;
        case 12: _t->setShapeState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->setPenState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData eraserSetting::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject eraserSetting::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_eraserSetting,
      qt_meta_data_eraserSetting, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &eraserSetting::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *eraserSetting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *eraserSetting::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_eraserSetting))
        return static_cast<void*>(const_cast< eraserSetting*>(this));
    return QWidget::qt_metacast(_clname);
}

int eraserSetting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void eraserSetting::sendEraser(eraser _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void eraserSetting::sendAngle(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void eraserSetting::sizeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void eraserSetting::valueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
