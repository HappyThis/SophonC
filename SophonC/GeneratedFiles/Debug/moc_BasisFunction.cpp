/****************************************************************************
** Meta object code from reading C++ file 'BasisFunction.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../BasisFunction/BasisFunction.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BasisFunction.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BasisFunction_t {
    QByteArrayData data[9];
    char stringdata0[64];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BasisFunction_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BasisFunction_t qt_meta_stringdata_BasisFunction = {
    {
QT_MOC_LITERAL(0, 0, 13), // "BasisFunction"
QT_MOC_LITERAL(1, 14, 7), // "NewInfo"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 5), // "Token"
QT_MOC_LITERAL(4, 29, 7), // "Linker*"
QT_MOC_LITERAL(5, 37, 8), // "ProcInfo"
QT_MOC_LITERAL(6, 46, 5), // "token"
QT_MOC_LITERAL(7, 52, 4), // "data"
QT_MOC_LITERAL(8, 57, 6) // "linker"

    },
    "BasisFunction\0NewInfo\0\0Token\0Linker*\0"
    "ProcInfo\0token\0data\0linker"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BasisFunction[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    3,   31,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QByteArray, 0x80000000 | 4,    2,    2,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QByteArray, 0x80000000 | 4,    6,    7,    8,

       0        // eod
};

void BasisFunction::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BasisFunction *_t = static_cast<BasisFunction *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->NewInfo((*reinterpret_cast< Token(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2])),(*reinterpret_cast< Linker*(*)>(_a[3]))); break;
        case 1: _t->ProcInfo((*reinterpret_cast< Token(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2])),(*reinterpret_cast< Linker*(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BasisFunction::*)(Token , QByteArray , Linker * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BasisFunction::NewInfo)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject BasisFunction::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_BasisFunction.data,
    qt_meta_data_BasisFunction,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BasisFunction::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BasisFunction::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BasisFunction.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int BasisFunction::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void BasisFunction::NewInfo(Token _t1, QByteArray _t2, Linker * _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
