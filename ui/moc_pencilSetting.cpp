/****************************************************************************
** Meta object code from reading C++ file 'pencilSetting.h'
**
** Created: Wed Jul 18 00:24:30 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "pencilSetting.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pencilSetting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_pencilSetting[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   15,   14,   14, 0x05,
      43,   37,   14,   14, 0x05,
      62,   60,   14,   14, 0x05,
      80,   14,   14,   14, 0x05,
      94,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
     109,   14,   14,   14, 0x08,
     117,   14,   14,   14, 0x08,
     130,   14,   14,   14, 0x08,
     143,   14,   14,   14, 0x08,
     158,   14,   14,   14, 0x08,
     173,   14,   14,   14, 0x08,
     189,   14,   14,   14, 0x08,
     204,   14,   14,   14, 0x08,
     217,   14,   14,   14, 0x08,
     226,   14,   14,   14, 0x08,
     237,   14,   14,   14, 0x08,
     253,  251,   14,   14, 0x08,
     273,  251,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_pencilSetting[] = {
    "pencilSetting\0\0pn\0sendPencil(pencil)\0"
    "angle\0sendAngle(float)\0c\0sendColor(QColor)\0"
    "sizeChanged()\0valueChanged()\0reset()\0"
    "resetColor()\0resetAngle()\0angleChanged()\0"
    "colorChanged()\0setAllEnabled()\0"
    "createPencil()\0hasChanged()\0reSize()\0"
    "toRotate()\0selectColor()\0s\0"
    "setShapeState(bool)\0setPenState(bool)\0"
};

void pencilSetting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        pencilSetting *_t = static_cast<pencilSetting *>(_o);
        switch (_id) {
        case 0: _t->sendPencil((*reinterpret_cast< pencil(*)>(_a[1]))); break;
        case 1: _t->sendAngle((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 2: _t->sendColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 3: _t->sizeChanged(); break;
        case 4: _t->valueChanged(); break;
        case 5: _t->reset(); break;
        case 6: _t->resetColor(); break;
        case 7: _t->resetAngle(); break;
        case 8: _t->angleChanged(); break;
        case 9: _t->colorChanged(); break;
        case 10: _t->setAllEnabled(); break;
        case 11: _t->createPencil(); break;
        case 12: _t->hasChanged(); break;
        case 13: _t->reSize(); break;
        case 14: _t->toRotate(); break;
        case 15: _t->selectColor(); break;
        case 16: _t->setShapeState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->setPenState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData pencilSetting::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject pencilSetting::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_pencilSetting,
      qt_meta_data_pencilSetting, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &pencilSetting::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *pencilSetting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *pencilSetting::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_pencilSetting))
        return static_cast<void*>(const_cast< pencilSetting*>(this));
    return QWidget::qt_metacast(_clname);
}

int pencilSetting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void pencilSetting::sendPencil(pencil _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void pencilSetting::sendAngle(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void pencilSetting::sendColor(QColor _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void pencilSetting::sizeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void pencilSetting::valueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
