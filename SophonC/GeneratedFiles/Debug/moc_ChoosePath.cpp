/****************************************************************************
** Meta object code from reading C++ file 'ChoosePath.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Function_File/ChoosePath.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ChoosePath.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ChoosePath_t {
    QByteArrayData data[12];
    char stringdata0[89];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChoosePath_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChoosePath_t qt_meta_stringdata_ChoosePath = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ChoosePath"
QT_MOC_LITERAL(1, 11, 4), // "Proc"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 7), // "Linker*"
QT_MOC_LITERAL(4, 25, 4), // "data"
QT_MOC_LITERAL(5, 30, 5), // "Token"
QT_MOC_LITERAL(6, 36, 5), // "token"
QT_MOC_LITERAL(7, 42, 10), // "GetNextDir"
QT_MOC_LITERAL(8, 53, 11), // "QModelIndex"
QT_MOC_LITERAL(9, 65, 5), // "index"
QT_MOC_LITERAL(10, 71, 9), // "GetResult"
QT_MOC_LITERAL(11, 81, 7) // "Confirm"

    },
    "ChoosePath\0Proc\0\0Linker*\0data\0Token\0"
    "token\0GetNextDir\0QModelIndex\0index\0"
    "GetResult\0Confirm"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChoosePath[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   34,    2, 0x08 /* Private */,
       7,    1,   41,    2, 0x08 /* Private */,
      10,    1,   44,    2, 0x08 /* Private */,
      11,    0,   47,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QByteArray, 0x80000000 | 5,    2,    4,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,

       0        // eod
};

void ChoosePath::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ChoosePath *_t = static_cast<ChoosePath *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Proc((*reinterpret_cast< Linker*(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2])),(*reinterpret_cast< Token(*)>(_a[3]))); break;
        case 1: _t->GetNextDir((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 2: _t->GetResult((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: _t->Confirm(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ChoosePath::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_ChoosePath.data,
    qt_meta_data_ChoosePath,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ChoosePath::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChoosePath::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ChoosePath.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ChoosePath::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
