/****************************************************************************
** Meta object code from reading C++ file 'qstorageinfo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../systeminfo/qstorageinfo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qstorageinfo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QStorageInfo_t {
    QByteArrayData data[18];
    char stringdata[228];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_QStorageInfo_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_QStorageInfo_t qt_meta_stringdata_QStorageInfo = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 19),
QT_MOC_LITERAL(2, 33, 0),
QT_MOC_LITERAL(3, 34, 5),
QT_MOC_LITERAL(4, 40, 5),
QT_MOC_LITERAL(5, 46, 18),
QT_MOC_LITERAL(6, 65, 14),
QT_MOC_LITERAL(7, 80, 11),
QT_MOC_LITERAL(8, 92, 9),
QT_MOC_LITERAL(9, 102, 23),
QT_MOC_LITERAL(10, 126, 16),
QT_MOC_LITERAL(11, 143, 9),
QT_MOC_LITERAL(12, 153, 12),
QT_MOC_LITERAL(13, 166, 13),
QT_MOC_LITERAL(14, 180, 14),
QT_MOC_LITERAL(15, 195, 11),
QT_MOC_LITERAL(16, 207, 10),
QT_MOC_LITERAL(17, 218, 8)
    },
    "QStorageInfo\0logicalDriveChanged\0\0"
    "drive\0added\0availableDiskSpace\0"
    "totalDiskSpace\0uriForDrive\0driveType\0"
    "QStorageInfo::DriveType\0allLogicalDrives\0"
    "DriveType\0UnknownDrive\0InternalDrive\0"
    "RemovableDrive\0RemoteDrive\0CdromDrive\0"
    "RamDrive\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QStorageInfo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       1,   56, // properties
       1,   60, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06,

 // methods: name, argc, parameters, tag, flags
       5,    1,   44,    2, 0x02,
       6,    1,   47,    2, 0x02,
       7,    1,   50,    2, 0x02,
       8,    1,   53,    2, 0x02,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    3,    4,

 // methods: parameters
    QMetaType::LongLong, QMetaType::QString,    3,
    QMetaType::LongLong, QMetaType::QString,    3,
    QMetaType::QString, QMetaType::QString,    3,
    0x80000000 | 9, QMetaType::QString,    3,

 // properties: name, type, flags
      10, QMetaType::QStringList, 0x00495001,

 // properties: notify_signal_id
       0,

 // enums: name, flags, count, data
      11, 0x0,    6,   64,

 // enum data: key, value
      12, uint(QStorageInfo::UnknownDrive),
      13, uint(QStorageInfo::InternalDrive),
      14, uint(QStorageInfo::RemovableDrive),
      15, uint(QStorageInfo::RemoteDrive),
      16, uint(QStorageInfo::CdromDrive),
      17, uint(QStorageInfo::RamDrive),

       0        // eod
};

void QStorageInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QStorageInfo *_t = static_cast<QStorageInfo *>(_o);
        switch (_id) {
        case 0: _t->logicalDriveChanged((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: { qlonglong _r = _t->availableDiskSpace((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< qlonglong*>(_a[0]) = _r; }  break;
        case 2: { qlonglong _r = _t->totalDiskSpace((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< qlonglong*>(_a[0]) = _r; }  break;
        case 3: { QString _r = _t->uriForDrive((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 4: { QStorageInfo::DriveType _r = _t->driveType((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QStorageInfo::DriveType*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QStorageInfo::*_t)(const QString & , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QStorageInfo::logicalDriveChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject QStorageInfo::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QStorageInfo.data,
      qt_meta_data_QStorageInfo,  qt_static_metacall, 0, 0}
};


const QMetaObject *QStorageInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QStorageInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QStorageInfo.stringdata))
        return static_cast<void*>(const_cast< QStorageInfo*>(this));
    return QObject::qt_metacast(_clname);
}

int QStorageInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QStringList*>(_v) = allLogicalDrives(); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QStorageInfo::logicalDriveChanged(const QString & _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
