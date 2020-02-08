/****************************************************************************
** Meta object code from reading C++ file 'FileSend.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Function_File/FileSend.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FileSend.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FileSend_t {
    QByteArrayData data[12];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FileSend_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FileSend_t qt_meta_stringdata_FileSend = {
    {
QT_MOC_LITERAL(0, 0, 8), // "FileSend"
QT_MOC_LITERAL(1, 9, 14), // "NewServerReady"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 7), // "Linker*"
QT_MOC_LITERAL(4, 33, 6), // "linker"
QT_MOC_LITERAL(5, 40, 15), // "ServerListening"
QT_MOC_LITERAL(6, 56, 13), // "ServerSending"
QT_MOC_LITERAL(7, 70, 12), // "ServerFinish"
QT_MOC_LITERAL(8, 83, 8), // "ProcInfo"
QT_MOC_LITERAL(9, 92, 5), // "Token"
QT_MOC_LITERAL(10, 98, 5), // "token"
QT_MOC_LITERAL(11, 104, 4) // "data"

    },
    "FileSend\0NewServerReady\0\0Linker*\0"
    "linker\0ServerListening\0ServerSending\0"
    "ServerFinish\0ProcInfo\0Token\0token\0"
    "data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FileSend[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       5,    1,   42,    2, 0x06 /* Public */,
       6,    1,   45,    2, 0x06 /* Public */,
       7,    1,   48,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    3,   51,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9, QMetaType::QByteArray, 0x80000000 | 3,   10,   11,    4,

       0        // eod
};

void FileSend::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FileSend *_t = static_cast<FileSend *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->NewServerReady((*reinterpret_cast< Linker*(*)>(_a[1]))); break;
        case 1: _t->ServerListening((*reinterpret_cast< Linker*(*)>(_a[1]))); break;
        case 2: _t->ServerSending((*reinterpret_cast< Linker*(*)>(_a[1]))); break;
        case 3: _t->ServerFinish((*reinterpret_cast< Linker*(*)>(_a[1]))); break;
        case 4: _t->ProcInfo((*reinterpret_cast< Token(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2])),(*reinterpret_cast< Linker*(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FileSend::*)(Linker * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileSend::NewServerReady)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FileSend::*)(Linker * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileSend::ServerListening)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FileSend::*)(Linker * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileSend::ServerSending)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (FileSend::*)(Linker * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileSend::ServerFinish)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FileSend::staticMetaObject = { {
    &BasisFunction::staticMetaObject,
    qt_meta_stringdata_FileSend.data,
    qt_meta_data_FileSend,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FileSend::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FileSend::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FileSend.stringdata0))
        return static_cast<void*>(this);
    return BasisFunction::qt_metacast(_clname);
}

int FileSend::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BasisFunction::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void FileSend::NewServerReady(Linker * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FileSend::ServerListening(Linker * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FileSend::ServerSending(Linker * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FileSend::ServerFinish(Linker * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
