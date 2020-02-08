/****************************************************************************
** Meta object code from reading C++ file 'RemoteCmd.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Funtion_Cmd/RemoteCmd.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RemoteCmd.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RemoteCmd_t {
    QByteArrayData data[10];
    char stringdata0[73];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RemoteCmd_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RemoteCmd_t qt_meta_stringdata_RemoteCmd = {
    {
QT_MOC_LITERAL(0, 0, 9), // "RemoteCmd"
QT_MOC_LITERAL(1, 10, 8), // "ProcInfo"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 5), // "Token"
QT_MOC_LITERAL(4, 26, 5), // "token"
QT_MOC_LITERAL(5, 32, 4), // "data"
QT_MOC_LITERAL(6, 37, 7), // "Linker*"
QT_MOC_LITERAL(7, 45, 6), // "linker"
QT_MOC_LITERAL(8, 52, 10), // "TextChange"
QT_MOC_LITERAL(9, 63, 9) // "CurChange"

    },
    "RemoteCmd\0ProcInfo\0\0Token\0token\0data\0"
    "Linker*\0linker\0TextChange\0CurChange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RemoteCmd[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   29,    2, 0x09 /* Protected */,
       8,    0,   36,    2, 0x08 /* Private */,
       9,    0,   37,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QByteArray, 0x80000000 | 6,    4,    5,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RemoteCmd::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RemoteCmd *_t = static_cast<RemoteCmd *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ProcInfo((*reinterpret_cast< Token(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2])),(*reinterpret_cast< Linker*(*)>(_a[3]))); break;
        case 1: _t->TextChange(); break;
        case 2: _t->CurChange(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RemoteCmd::staticMetaObject = { {
    &BasisFunction::staticMetaObject,
    qt_meta_stringdata_RemoteCmd.data,
    qt_meta_data_RemoteCmd,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RemoteCmd::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RemoteCmd::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RemoteCmd.stringdata0))
        return static_cast<void*>(this);
    return BasisFunction::qt_metacast(_clname);
}

int RemoteCmd::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BasisFunction::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
