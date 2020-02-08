/****************************************************************************
** Meta object code from reading C++ file 'ChooseLocalFile.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Function_File/ChooseLocalFile.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ChooseLocalFile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ChooseLocalFile_t {
    QByteArrayData data[6];
    char stringdata0[53];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChooseLocalFile_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChooseLocalFile_t qt_meta_stringdata_ChooseLocalFile = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ChooseLocalFile"
QT_MOC_LITERAL(1, 16, 9), // "GetResult"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 11), // "QModelIndex"
QT_MOC_LITERAL(4, 39, 5), // "index"
QT_MOC_LITERAL(5, 45, 7) // "Confirm"

    },
    "ChooseLocalFile\0GetResult\0\0QModelIndex\0"
    "index\0Confirm"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChooseLocalFile[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x08 /* Private */,
       5,    0,   27,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

       0        // eod
};

void ChooseLocalFile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ChooseLocalFile *_t = static_cast<ChooseLocalFile *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->GetResult((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: _t->Confirm(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ChooseLocalFile::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_ChooseLocalFile.data,
    qt_meta_data_ChooseLocalFile,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ChooseLocalFile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChooseLocalFile::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ChooseLocalFile.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ChooseLocalFile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
