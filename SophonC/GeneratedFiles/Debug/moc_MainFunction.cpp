/****************************************************************************
** Meta object code from reading C++ file 'MainFunction.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../BasisFunction/MainFunction.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainFunction.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainFunction_t {
    QByteArrayData data[9];
    char stringdata0[60];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainFunction_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainFunction_t qt_meta_stringdata_MainFunction = {
    {
QT_MOC_LITERAL(0, 0, 12), // "MainFunction"
QT_MOC_LITERAL(1, 13, 4), // "Proc"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 7), // "Linker*"
QT_MOC_LITERAL(4, 27, 5), // "Token"
QT_MOC_LITERAL(5, 33, 8), // "ProcInfo"
QT_MOC_LITERAL(6, 42, 5), // "token"
QT_MOC_LITERAL(7, 48, 4), // "data"
QT_MOC_LITERAL(8, 53, 6) // "linker"

    },
    "MainFunction\0Proc\0\0Linker*\0Token\0"
    "ProcInfo\0token\0data\0linker"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainFunction[] = {

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
    QMetaType::Void, 0x80000000 | 4, QMetaType::QByteArray, 0x80000000 | 3,    6,    7,    8,

       0        // eod
};

void MainFunction::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainFunction *_t = static_cast<MainFunction *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Proc((*reinterpret_cast< Linker*(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2])),(*reinterpret_cast< Token(*)>(_a[3]))); break;
        case 1: _t->ProcInfo((*reinterpret_cast< Token(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2])),(*reinterpret_cast< Linker*(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainFunction::*)(Linker * , QByteArray , Token );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainFunction::Proc)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainFunction::staticMetaObject = { {
    &BasisFunction::staticMetaObject,
    qt_meta_stringdata_MainFunction.data,
    qt_meta_data_MainFunction,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainFunction::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainFunction::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainFunction.stringdata0))
        return static_cast<void*>(this);
    return BasisFunction::qt_metacast(_clname);
}

int MainFunction::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BasisFunction::qt_metacall(_c, _id, _a);
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
void MainFunction::Proc(Linker * _t1, QByteArray _t2, Token _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
