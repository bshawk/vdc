/****************************************************************************
** Meta object code from reading C++ file 'vscsetting.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../setting/vscsetting.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vscsetting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VSCSetting_t {
    QByteArrayData data[9];
    char stringdata[105];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_VSCSetting_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_VSCSetting_t qt_meta_stringdata_VSCSetting = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 19),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 18),
QT_MOC_LITERAL(4, 51, 11),
QT_MOC_LITERAL(5, 63, 11),
QT_MOC_LITERAL(6, 75, 16),
QT_MOC_LITERAL(7, 92, 4),
QT_MOC_LITERAL(8, 97, 6)
    },
    "VSCSetting\0RecorderTreeUpdated\0\0"
    "radioButtonClicked\0applyConfig\0"
    "treeClicked\0QTreeWidgetItem*\0item\0"
    "column\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VSCSetting[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       3,    0,   35,    2, 0x08,
       4,    0,   36,    2, 0x08,
       5,    2,   37,    2, 0x08,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6, QMetaType::Int,    7,    8,

       0        // eod
};

void VSCSetting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VSCSetting *_t = static_cast<VSCSetting *>(_o);
        switch (_id) {
        case 0: _t->RecorderTreeUpdated(); break;
        case 1: _t->radioButtonClicked(); break;
        case 2: _t->applyConfig(); break;
        case 3: _t->treeClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (VSCSetting::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VSCSetting::RecorderTreeUpdated)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject VSCSetting::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_VSCSetting.data,
      qt_meta_data_VSCSetting,  qt_static_metacall, 0, 0}
};


const QMetaObject *VSCSetting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VSCSetting::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VSCSetting.stringdata))
        return static_cast<void*>(const_cast< VSCSetting*>(this));
    return QWidget::qt_metacast(_clname);
}

int VSCSetting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void VSCSetting::RecorderTreeUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
