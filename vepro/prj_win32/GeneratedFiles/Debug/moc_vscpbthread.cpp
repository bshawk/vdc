/****************************************************************************
** Meta object code from reading C++ file 'vscpbthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../playback/vscpbthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vscpbthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VSCPbThread_t {
    QByteArrayData data[7];
    char stringdata[79];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_VSCPbThread_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_VSCPbThread_t qt_meta_stringdata_VSCPbThread = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 14),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 12),
QT_MOC_LITERAL(4, 41, 10),
QT_MOC_LITERAL(5, 52, 8),
QT_MOC_LITERAL(6, 61, 16)
    },
    "VSCPbThread\0ChangedToPause\0\0GetANewFrame\0"
    "SeekToTime\0seekTime\0videoResizeEvent\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VSCPbThread[] = {

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
       1,    0,   34,    2, 0x06,
       3,    0,   35,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       4,    1,   36,    2, 0x0a,
       6,    0,   39,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,

       0        // eod
};

void VSCPbThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VSCPbThread *_t = static_cast<VSCPbThread *>(_o);
        switch (_id) {
        case 0: _t->ChangedToPause(); break;
        case 1: _t->GetANewFrame(); break;
        case 2: _t->SeekToTime((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->videoResizeEvent(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (VSCPbThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VSCPbThread::ChangedToPause)) {
                *result = 0;
            }
        }
        {
            typedef void (VSCPbThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VSCPbThread::GetANewFrame)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject VSCPbThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_VSCPbThread.data,
      qt_meta_data_VSCPbThread,  qt_static_metacall, 0, 0}
};


const QMetaObject *VSCPbThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VSCPbThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VSCPbThread.stringdata))
        return static_cast<void*>(const_cast< VSCPbThread*>(this));
    return QThread::qt_metacast(_clname);
}

int VSCPbThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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
void VSCPbThread::ChangedToPause()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void VSCPbThread::GetANewFrame()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
