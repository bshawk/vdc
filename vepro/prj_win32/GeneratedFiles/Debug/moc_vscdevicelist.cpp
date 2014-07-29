/****************************************************************************
** Meta object code from reading C++ file 'vscdevicelist.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../main/vscdevicelist.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vscdevicelist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VSCDeviceList_t {
    QByteArrayData data[23];
    char stringdata[336];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_VSCDeviceList_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_VSCDeviceList_t qt_meta_stringdata_VSCDeviceList = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 19),
QT_MOC_LITERAL(2, 34, 0),
QT_MOC_LITERAL(3, 35, 16),
QT_MOC_LITERAL(4, 52, 15),
QT_MOC_LITERAL(5, 68, 13),
QT_MOC_LITERAL(6, 82, 15),
QT_MOC_LITERAL(7, 98, 17),
QT_MOC_LITERAL(8, 116, 3),
QT_MOC_LITERAL(9, 120, 19),
QT_MOC_LITERAL(10, 140, 14),
QT_MOC_LITERAL(11, 155, 15),
QT_MOC_LITERAL(12, 171, 17),
QT_MOC_LITERAL(13, 189, 15),
QT_MOC_LITERAL(14, 205, 17),
QT_MOC_LITERAL(15, 223, 14),
QT_MOC_LITERAL(16, 238, 13),
QT_MOC_LITERAL(17, 252, 11),
QT_MOC_LITERAL(18, 264, 13),
QT_MOC_LITERAL(19, 278, 12),
QT_MOC_LITERAL(20, 291, 15),
QT_MOC_LITERAL(21, 307, 12),
QT_MOC_LITERAL(22, 320, 14)
    },
    "VSCDeviceList\0SurveillanceClicked\0\0"
    "CameraAddClicked\0PlaybackClicked\0"
    "SearchClicked\0RecorderClicked\0"
    "CameraEditClicked\0nId\0CameraDeleteClicked\0"
    "SiteAddClicked\0SiteEditClicked\0"
    "SiteDeleteClicked\0DiskEditClicked\0"
    "SurveillanceClick\0CameraAddClick\0"
    "PlaybackClick\0SearchClick\0RecorderClick\0"
    "SiteAddClick\0DiskTreeUpdated\0UpdateOnline\0"
    "VmsTreeUpdated\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VSCDeviceList[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  114,    2, 0x06,
       3,    0,  115,    2, 0x06,
       4,    0,  116,    2, 0x06,
       5,    0,  117,    2, 0x06,
       6,    0,  118,    2, 0x06,
       7,    1,  119,    2, 0x06,
       9,    1,  122,    2, 0x06,
      10,    0,  125,    2, 0x06,
      11,    1,  126,    2, 0x06,
      12,    1,  129,    2, 0x06,
      13,    0,  132,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
      14,    0,  133,    2, 0x0a,
      15,    0,  134,    2, 0x0a,
      16,    0,  135,    2, 0x0a,
      17,    0,  136,    2, 0x0a,
      18,    0,  137,    2, 0x0a,
      19,    0,  138,    2, 0x0a,
      20,    0,  139,    2, 0x0a,
      21,    0,  140,    2, 0x0a,
      22,    0,  141,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void VSCDeviceList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VSCDeviceList *_t = static_cast<VSCDeviceList *>(_o);
        switch (_id) {
        case 0: _t->SurveillanceClicked(); break;
        case 1: _t->CameraAddClicked(); break;
        case 2: _t->PlaybackClicked(); break;
        case 3: _t->SearchClicked(); break;
        case 4: _t->RecorderClicked(); break;
        case 5: _t->CameraEditClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->CameraDeleteClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->SiteAddClicked(); break;
        case 8: _t->SiteEditClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->SiteDeleteClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->DiskEditClicked(); break;
        case 11: _t->SurveillanceClick(); break;
        case 12: _t->CameraAddClick(); break;
        case 13: _t->PlaybackClick(); break;
        case 14: _t->SearchClick(); break;
        case 15: _t->RecorderClick(); break;
        case 16: _t->SiteAddClick(); break;
        case 17: _t->DiskTreeUpdated(); break;
        case 18: _t->UpdateOnline(); break;
        case 19: _t->VmsTreeUpdated(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (VSCDeviceList::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VSCDeviceList::SurveillanceClicked)) {
                *result = 0;
            }
        }
        {
            typedef void (VSCDeviceList::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VSCDeviceList::CameraAddClicked)) {
                *result = 1;
            }
        }
        {
            typedef void (VSCDeviceList::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VSCDeviceList::PlaybackClicked)) {
                *result = 2;
            }
        }
        {
            typedef void (VSCDeviceList::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VSCDeviceList::SearchClicked)) {
                *result = 3;
            }
        }
        {
            typedef void (VSCDeviceList::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VSCDeviceList::RecorderClicked)) {
                *result = 4;
            }
        }
        {
            typedef void (VSCDeviceList::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VSCDeviceList::CameraEditClicked)) {
                *result = 5;
            }
        }
        {
            typedef void (VSCDeviceList::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VSCDeviceList::CameraDeleteClicked)) {
                *result = 6;
            }
        }
        {
            typedef void (VSCDeviceList::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VSCDeviceList::SiteAddClicked)) {
                *result = 7;
            }
        }
        {
            typedef void (VSCDeviceList::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VSCDeviceList::SiteEditClicked)) {
                *result = 8;
            }
        }
        {
            typedef void (VSCDeviceList::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VSCDeviceList::SiteDeleteClicked)) {
                *result = 9;
            }
        }
        {
            typedef void (VSCDeviceList::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VSCDeviceList::DiskEditClicked)) {
                *result = 10;
            }
        }
    }
}

const QMetaObject VSCDeviceList::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_VSCDeviceList.data,
      qt_meta_data_VSCDeviceList,  qt_static_metacall, 0, 0}
};


const QMetaObject *VSCDeviceList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VSCDeviceList::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VSCDeviceList.stringdata))
        return static_cast<void*>(const_cast< VSCDeviceList*>(this));
    return QWidget::qt_metacast(_clname);
}

int VSCDeviceList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void VSCDeviceList::SurveillanceClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void VSCDeviceList::CameraAddClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void VSCDeviceList::PlaybackClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void VSCDeviceList::SearchClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void VSCDeviceList::RecorderClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void VSCDeviceList::CameraEditClicked(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void VSCDeviceList::CameraDeleteClicked(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void VSCDeviceList::SiteAddClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void VSCDeviceList::SiteEditClicked(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void VSCDeviceList::SiteDeleteClicked(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void VSCDeviceList::DiskEditClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 10, 0);
}
QT_END_MOC_NAMESPACE
