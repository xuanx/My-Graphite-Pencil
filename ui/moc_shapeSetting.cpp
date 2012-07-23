/****************************************************************************
** Meta object code from reading C++ file 'shapeSetting.h'
**
** Created: Wed Jul 18 00:24:32 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "shapeSetting.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'shapeSetting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_drawShape[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   11,   10,   10, 0x05,
      38,   10,   10,   10, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_drawShape[] = {
    "drawShape\0\0x,y\0sendPoint(float,float)\0"
    "finished(bool)\0"
};

void drawShape::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        drawShape *_t = static_cast<drawShape *>(_o);
        switch (_id) {
        case 0: _t->sendPoint((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 1: _t->finished((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData drawShape::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject drawShape::staticMetaObject = {
    { &picture::staticMetaObject, qt_meta_stringdata_drawShape,
      qt_meta_data_drawShape, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &drawShape::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *drawShape::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *drawShape::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_drawShape))
        return static_cast<void*>(const_cast< drawShape*>(this));
    return picture::qt_metacast(_clname);
}

int drawShape::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = picture::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void drawShape::sendPoint(float _t1, float _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void drawShape::finished(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
static const uint qt_meta_data_shapeSetting[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,
      29,   13,   13,   13, 0x05,
      48,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      62,   13,   13,   13, 0x0a,
      70,   13,   13,   13, 0x0a,
      78,   13,   13,   13, 0x0a,
      93,   13,   13,   13, 0x0a,
     115,  109,   13,   13, 0x0a,
     146,  142,   13,   13, 0x2a,

       0        // eod
};

static const char qt_meta_stringdata_shapeSetting[] = {
    "shapeSetting\0\0finished(bool)\0"
    "valueChanged(bool)\0sizeChanged()\0"
    "clear()\0reSet()\0valueChanged()\0"
    "available(bool)\0x,y,c\0addItem(float,float,float)\0"
    "x,y\0addItem(float,float)\0"
};

void shapeSetting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        shapeSetting *_t = static_cast<shapeSetting *>(_o);
        switch (_id) {
        case 0: _t->finished((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->valueChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->sizeChanged(); break;
        case 3: _t->clear(); break;
        case 4: _t->reSet(); break;
        case 5: _t->valueChanged(); break;
        case 6: _t->available((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->addItem((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 8: _t->addItem((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData shapeSetting::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject shapeSetting::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_shapeSetting,
      qt_meta_data_shapeSetting, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &shapeSetting::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *shapeSetting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *shapeSetting::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_shapeSetting))
        return static_cast<void*>(const_cast< shapeSetting*>(this));
    return QWidget::qt_metacast(_clname);
}

int shapeSetting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void shapeSetting::finished(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void shapeSetting::valueChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void shapeSetting::sizeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
