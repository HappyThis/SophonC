/****************************************************************************
** Meta object code from reading C++ file 'RemoteCapture.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Funtion_Network/RemoteCapture.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RemoteCapture.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RemoteCapture_t {
    QByteArrayData data[7];
    char stringdata0[59];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RemoteCapture_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RemoteCapture_t qt_meta_stringdata_RemoteCapture = {
    {
QT_MOC_LITERAL(0, 0, 13), // "RemoteCapture"
QT_MOC_LITERAL(1, 14, 8), // "StartCap"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 2), // "ip"
QT_MOC_LITERAL(4, 27, 9), // "NewPacket"
QT_MOC_LITERAL(5, 37, 17), // "RemoteCaptureUint"
QT_MOC_LITERAL(6, 55, 3) // "RCU"

    },
    "RemoteCapture\0StartCap\0\0ip\0NewPacket\0"
    "RemoteCaptureUint\0RCU"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RemoteCapture[] = {

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
       4,    1,   27,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,

       0        // eod
};

void RemoteCapture::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RemoteCapture *_t = static_cast<RemoteCapture *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->StartCap((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->NewPacket((*reinterpret_cast< RemoteCaptureUint(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RemoteCapture::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RemoteCapture::StartCap)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RemoteCapture::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_RemoteCapture.data,
    qt_meta_data_RemoteCapture,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RemoteCapture::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RemoteCapture::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RemoteCapture.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int RemoteCapture::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void RemoteCapture::StartCap(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
