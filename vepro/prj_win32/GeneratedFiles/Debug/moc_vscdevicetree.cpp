/****************************************************************************
** Meta object code from reading C++ file 'vscdevicetree.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../main/vscdevicetree.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vscdevicetree.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VSCDeviceTree_t {
    QByteArrayData data[19];
    char stringdata[289];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_VSCDeviceTree_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_VSCDeviceTree_t qt_meta_stringdata_VSCDeviceTree = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 16),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 17),
QT_MOC_LITERAL(4, 50, 3),
QT_MOC_LITERAL(5, 54, 19),
QT_MOC_LITERAL(6, 74, 14),
QT_MOC_LITERAL(7, 89, 15),
QT_MOC_LITERAL(8, 105, 17),
QT_MOC_LITERAL(9, 123, 15),
QT_MOC_LITERAL(10, 139, 14),
QT_MOC_LITERAL(11, 154, 15),
QT_MOC_LITERAL(12, 170, 17),
QT_MOC_LITERAL(13, 188, 17),
QT_MOC_LITERAL(14, 206, 21),
QT_MOC_LITERAL(15, 228, 12),
QT_MOC_LITERAL(16, 241, 13),
QT_MOC_LITERAL(17, 255, 15),
QT_MOC_LITERAL(18, 271, 16)
    },
    "VSCDeviceTree\0CameraAddClicked\0\0"
    "CameraEditClicked\0nId\0CameraDeleteClicked\0"
    "SiteAddClicked\0SiteEditClicked\0"
    "SiteDeleteClicked\0DiskEditClicked\0"
    "CameraAddClick\0CameraEditClick\0"
    "CameraDeleteClick\0CameraRecordClick\0"
    "CameraStopRecordClick\0SiteAddClick\0"
    "SiteEditClick\0SiteDeleteClick\0"
    "SiteRefreshClick\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VSCDeviceTree[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x06,
       3,    1,   95,    2, 0x06,
       5,    1,   98,    2, 0x06,
       6,    0,  101,    2, 0x06,
       7,    1,  102,    2, 0x06,
       8,    1,  105,    2, 0x06,
       9,    0,  108,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
      10,    0,  109,    2, 0x0a,
      11,    0,  110,    2, 0x0a,
      12,    0,  111,    2, 0x0a,
      13,    0,  112,    2, 0x0a,
      14,    0,  113,    2, 0x0a,
      15,    0,  114,    2, 0x0a,
      16,    0,  115,    2, 0x0a,
      17,    0,  116,    2, 0x0a,
      18,    0,  117,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
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

void VSCDeviceTree::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VSCDeviceTree *_t = static_cast<VSCDeviceTree *>(_o);
        switch (_id) {
        case 0: _t->CameraAddClicked(); break;
        case 1: _t->CameraEditClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->CameraDeleteClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->SiteAddClicked(); break;
        case 4: _t->SiteEditClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->SiteDeleteClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->DiskEditClicked(); break;
        case 7: _t->CameraAddClick(); break;
        case 8: _t->CameraEditClick(); break;
        case 9: _t->CameraDeleteClick(); break;
        case 10: _t->CameraRecordClick(); break;
        case 11: _t->CameraStopRecordClick(); break;
        case 12: _t->SiteAddClick(); break;
        case 13: _t->SiteEditClick(); break;
        case 14: _t->SiteDeleteClick(); break;
        case 15: _t->SiteRefreshClick(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (VSCDeviceTree::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VSCDeviceTree::CameraAddClicked)) {
                *result = 0;
            }
        }
        {
            typedef void (VSCDeviceTree::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VSCDeviceTree::CameraEditClicked)) {
                *result = 1;
            }
        }
        {
            typedef void (VSCDeviceTree::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VSCDeviceTree::CameraDeleteClicked)) {
                *result = 2;
            }
        }
        {
            typedef void (VSCDeviceTree::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VSCDeviceTree::SiteAddClicked)) {
                *result = 3;
            }
        }
        {
            typedef void (VSCDeviceTree::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VSCDeviceTree::SiteEditClicked)) {
                *result = 4;
            }
        }
        {
            typedef void (VSCDeviceTree::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VSCDeviceTree::SiteDeleteClicked)) {
                *result = 5;
            }
        }
        {
            typedef void (VSCDeviceTree::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VSCDeviceTree::DiskEditClicked)) {
                *result = 6;
            }
        }
    }
}

const QMetaObject VSCDeviceTree::staticMetaObject = {
    { &QTreeWidget::staticMetaObject, qt_meta_stringdata_VSCDeviceTree.data,
      qt_meta_data_VSCDeviceTree,  qt_static_metacall, 0, 0}
};


const QMetaObject *VSCDeviceTree::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VSCDeviceTree::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VSCDeviceTree.stringdata))
        return static_cast<void*>(const_cast< VSCDeviceTree*>(this));
    return QTreeWidget::qt_metacast(_clname);
}

int VSCDeviceTree::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void VSCDeviceTree::CameraAddClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void VSCDeviceTree::CameraEditClicked(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void VSCDeviceTree::CameraDeleteClicked(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void VSCDeviceTree::SiteAddClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void VSCDeviceTree::SiteEditClicked(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void VSCDeviceTree::SiteDeleteClicked(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void VSCDeviceTree::DiskEditClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}
QT_END_MOC_NAMESPACE
