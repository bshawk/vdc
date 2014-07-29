/****************************************************************************
** Meta object code from reading C++ file 'vscsimpletl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../playback/vscsimpletl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vscsimpletl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VSCSimpleTl_t {
    QByteArrayData data[9];
    char stringdata[87];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_VSCSimpleTl_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_VSCSimpleTl_t qt_meta_stringdata_VSCSimpleTl = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 14),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 7),
QT_MOC_LITERAL(4, 36, 10),
QT_MOC_LITERAL(5, 47, 8),
QT_MOC_LITERAL(6, 56, 10),
QT_MOC_LITERAL(7, 67, 12),
QT_MOC_LITERAL(8, 80, 5)
    },
    "VSCSimpleTl\0TimeLineChange\0\0nStatus\0"
    "SeekToTime\0seekTime\0UpdateTime\0"
    "SetStartTime\0sTime\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VSCSimpleTl[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06,
       4,    1,   37,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       6,    0,   40,    2, 0x0a,

 // methods: name, argc, parameters, tag, flags
       7,    1,   41,    2, 0x02,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,

 // slots: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

void VSCSimpleTl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VSCSimpleTl *_t = static_cast<VSCSimpleTl *>(_o);
        switch (_id) {
        case 0: _t->TimeLineChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->SeekToTime((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->UpdateTime(); break;
        case 3: _t->SetStartTime((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (VSCSimpleTl::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VSCSimpleTl::TimeLineChange)) {
                *result = 0;
            }
        }
        {
            typedef void (VSCSimpleTl::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VSCSimpleTl::SeekToTime)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject VSCSimpleTl::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_VSCSimpleTl.data,
      qt_meta_data_VSCSimpleTl,  qt_static_metacall, 0, 0}
};


const QMetaObject *VSCSimpleTl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VSCSimpleTl::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VSCSimpleTl.stringdata))
        return static_cast<void*>(const_cast< VSCSimpleTl*>(this));
    return QWidget::qt_metacast(_clname);
}

int VSCSimpleTl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void VSCSimpleTl::TimeLineChange(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void VSCSimpleTl::SeekToTime(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
