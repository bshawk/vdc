/****************************************************************************
** Meta object code from reading C++ file 'vscmainwindows.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../main/vscmainwindows.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vscmainwindows.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VSCMainWindows_t {
    QByteArrayData data[21];
    char stringdata[209];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_VSCMainWindows_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_VSCMainWindows_t qt_meta_stringdata_VSCMainWindows = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 13),
QT_MOC_LITERAL(2, 29, 0),
QT_MOC_LITERAL(3, 30, 15),
QT_MOC_LITERAL(4, 46, 9),
QT_MOC_LITERAL(5, 56, 11),
QT_MOC_LITERAL(6, 68, 11),
QT_MOC_LITERAL(7, 80, 6),
QT_MOC_LITERAL(8, 87, 7),
QT_MOC_LITERAL(9, 95, 10),
QT_MOC_LITERAL(10, 106, 3),
QT_MOC_LITERAL(11, 110, 12),
QT_MOC_LITERAL(12, 123, 12),
QT_MOC_LITERAL(13, 136, 5),
QT_MOC_LITERAL(14, 142, 5),
QT_MOC_LITERAL(15, 148, 13),
QT_MOC_LITERAL(16, 162, 8),
QT_MOC_LITERAL(17, 171, 8),
QT_MOC_LITERAL(18, 180, 7),
QT_MOC_LITERAL(19, 188, 8),
QT_MOC_LITERAL(20, 197, 10)
    },
    "VSCMainWindows\0CameraDeleted\0\0"
    "AddSurveillance\0AddCamera\0AddPlayback\0"
    "AddRecorder\0Search\0Setting\0EditCamera\0"
    "nId\0DeleteCamera\0MainCloseTab\0index\0"
    "about\0SetFullScreen\0AddEvent\0EditDisk\0"
    "AddSite\0EditSite\0DeleteSite\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VSCMainWindows[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       3,    0,  100,    2, 0x0a,
       4,    0,  101,    2, 0x0a,
       5,    0,  102,    2, 0x0a,
       6,    0,  103,    2, 0x0a,
       7,    0,  104,    2, 0x0a,
       8,    0,  105,    2, 0x0a,
       9,    1,  106,    2, 0x0a,
      11,    1,  109,    2, 0x0a,
      12,    1,  112,    2, 0x0a,
      14,    0,  115,    2, 0x0a,
      15,    0,  116,    2, 0x0a,
      16,    0,  117,    2, 0x0a,
      17,    0,  118,    2, 0x0a,
      18,    0,  119,    2, 0x0a,
      19,    1,  120,    2, 0x0a,
      20,    1,  123,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,

       0        // eod
};

void VSCMainWindows::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VSCMainWindows *_t = static_cast<VSCMainWindows *>(_o);
        switch (_id) {
        case 0: _t->CameraDeleted(); break;
        case 1: _t->AddSurveillance(); break;
        case 2: _t->AddCamera(); break;
        case 3: _t->AddPlayback(); break;
        case 4: _t->AddRecorder(); break;
        case 5: _t->Search(); break;
        case 6: _t->Setting(); break;
        case 7: _t->EditCamera((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->DeleteCamera((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->MainCloseTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->about(); break;
        case 11: _t->SetFullScreen(); break;
        case 12: _t->AddEvent(); break;
        case 13: _t->EditDisk(); break;
        case 14: _t->AddSite(); break;
        case 15: _t->EditSite((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->DeleteSite((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (VSCMainWindows::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VSCMainWindows::CameraDeleted)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject VSCMainWindows::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_VSCMainWindows.data,
      qt_meta_data_VSCMainWindows,  qt_static_metacall, 0, 0}
};


const QMetaObject *VSCMainWindows::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VSCMainWindows::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VSCMainWindows.stringdata))
        return static_cast<void*>(const_cast< VSCMainWindows*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int VSCMainWindows::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void VSCMainWindows::CameraDeleted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
