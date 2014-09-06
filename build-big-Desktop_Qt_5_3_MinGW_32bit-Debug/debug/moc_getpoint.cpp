/****************************************************************************
** Meta object code from reading C++ file 'getpoint.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../big/getpoint.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'getpoint.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Getpoint_t {
    QByteArrayData data[9];
    char stringdata[101];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Getpoint_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Getpoint_t qt_meta_stringdata_Getpoint = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 11),
QT_MOC_LITERAL(2, 21, 0),
QT_MOC_LITERAL(3, 22, 16),
QT_MOC_LITERAL(4, 39, 7),
QT_MOC_LITERAL(5, 47, 15),
QT_MOC_LITERAL(6, 63, 12),
QT_MOC_LITERAL(7, 76, 11),
QT_MOC_LITERAL(8, 88, 12)
    },
    "Getpoint\0setPointnum\0\0doubleclickmouse\0"
    "loading\0displaypointnum\0getcursorpos\0"
    "biggergraph\0smallergraph"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Getpoint[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       3,    0,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   53,    2, 0x0a /* Public */,
       5,    0,   54,    2, 0x0a /* Public */,
       6,    0,   55,    2, 0x0a /* Public */,
       7,    0,   56,    2, 0x0a /* Public */,
       8,    0,   57,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Getpoint::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Getpoint *_t = static_cast<Getpoint *>(_o);
        switch (_id) {
        case 0: _t->setPointnum((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->doubleclickmouse(); break;
        case 2: _t->loading(); break;
        case 3: _t->displaypointnum(); break;
        case 4: _t->getcursorpos(); break;
        case 5: _t->biggergraph(); break;
        case 6: _t->smallergraph(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Getpoint::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Getpoint::setPointnum)) {
                *result = 0;
            }
        }
        {
            typedef void (Getpoint::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Getpoint::doubleclickmouse)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject Getpoint::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Getpoint.data,
      qt_meta_data_Getpoint,  qt_static_metacall, 0, 0}
};


const QMetaObject *Getpoint::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Getpoint::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Getpoint.stringdata))
        return static_cast<void*>(const_cast< Getpoint*>(this));
    return QWidget::qt_metacast(_clname);
}

int Getpoint::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Getpoint::setPointnum(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Getpoint::doubleclickmouse()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
