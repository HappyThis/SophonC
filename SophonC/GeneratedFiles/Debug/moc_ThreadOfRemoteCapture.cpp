/****************************************************************************
** Meta object code from reading C++ file 'ThreadOfRemoteCapture.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Funtion_Network/ThreadOfRemoteCapture.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ThreadOfRemoteCapture.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ThreadOfRemoteCapture_t {
    QByteArrayData data[7];
    char stringdata0[67];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ThreadOfRemoteCapture_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ThreadOfRemoteCapture_t qt_meta_stringdata_ThreadOfRemoteCapture = {
    {
QT_MOC_LITERAL(0, 0, 21), // "ThreadOfRemoteCapture"
QT_MOC_LITERAL(1, 22, 9), // "NewPacket"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 17), // "RemoteCaptureUint"
QT_MOC_LITERAL(4, 51, 3), // "RCU"
QT_MOC_LITERAL(5, 55, 8), // "StartCap"
QT_MOC_LITERAL(6, 64, 2) // "ip"

    },
    "ThreadOfRemoteCapture\0NewPacket\0\0"
    "RemoteCaptureUint\0RCU\0StartCap\0ip"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ThreadOfRemoteCapture[] = {

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
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   27,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    6,

       0        // eod
};

void ThreadOfRemoteCapture::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ThreadOfRemoteCapture *_t = static_cast<ThreadOfRemoteCapture *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->NewPacket((*reinterpret_cast< RemoteCaptureUint(*)>(_a[1]))); break;
        case 1: _t->StartCap((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ThreadOfRemoteCapture::*)(RemoteCaptureUint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThreadOfRemoteCapture::NewPacket)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ThreadOfRemoteCapture::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_ThreadOfRemoteCapture.data,
    qt_meta_data_ThreadOfRemoteCapture,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ThreadOfRemoteCapture::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ThreadOfRemoteCapture::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ThreadOfRemoteCapture.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ThreadOfRemoteCapture::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void ThreadOfRemoteCapture::NewPacket(RemoteCaptureUint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
