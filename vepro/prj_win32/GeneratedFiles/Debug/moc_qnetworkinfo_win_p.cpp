/****************************************************************************
** Meta object code from reading C++ file 'qnetworkinfo_win_p.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../systeminfo/windows/qnetworkinfo_win_p.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qnetworkinfo_win_p.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QNetworkInfoPrivate_t {
    QByteArrayData data[28];
    char stringdata[477];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_QNetworkInfoPrivate_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_QNetworkInfoPrivate_t qt_meta_stringdata_QNetworkInfoPrivate = {
    {
QT_MOC_LITERAL(0, 0, 19),
QT_MOC_LITERAL(1, 20, 13),
QT_MOC_LITERAL(2, 34, 0),
QT_MOC_LITERAL(3, 35, 12),
QT_MOC_LITERAL(4, 48, 2),
QT_MOC_LITERAL(5, 51, 32),
QT_MOC_LITERAL(6, 84, 32),
QT_MOC_LITERAL(7, 117, 4),
QT_MOC_LITERAL(8, 122, 31),
QT_MOC_LITERAL(9, 154, 3),
QT_MOC_LITERAL(10, 158, 31),
QT_MOC_LITERAL(11, 190, 3),
QT_MOC_LITERAL(12, 194, 25),
QT_MOC_LITERAL(13, 220, 25),
QT_MOC_LITERAL(14, 246, 4),
QT_MOC_LITERAL(15, 251, 23),
QT_MOC_LITERAL(16, 275, 3),
QT_MOC_LITERAL(17, 279, 28),
QT_MOC_LITERAL(18, 308, 5),
QT_MOC_LITERAL(19, 314, 18),
QT_MOC_LITERAL(20, 333, 4),
QT_MOC_LITERAL(21, 338, 28),
QT_MOC_LITERAL(22, 367, 8),
QT_MOC_LITERAL(23, 376, 20),
QT_MOC_LITERAL(24, 397, 27),
QT_MOC_LITERAL(25, 425, 6),
QT_MOC_LITERAL(26, 432, 22),
QT_MOC_LITERAL(27, 455, 20)
    },
    "QNetworkInfoPrivate\0cellIdChanged\0\0"
    "netInterface\0id\0currentCellDataTechnologyChanged\0"
    "QNetworkInfo::CellDataTechnology\0tech\0"
    "currentMobileCountryCodeChanged\0mcc\0"
    "currentMobileNetworkCodeChanged\0mnc\0"
    "currentNetworkModeChanged\0"
    "QNetworkInfo::NetworkMode\0mode\0"
    "locationAreaCodeChanged\0lac\0"
    "networkInterfaceCountChanged\0count\0"
    "networkNameChanged\0name\0"
    "networkSignalStrengthChanged\0strength\0"
    "networkStatusChanged\0QNetworkInfo::NetworkStatus\0"
    "status\0networkStrengthTimeout\0"
    "networkStatusTimeout\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QNetworkInfoPrivate[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   74,    2, 0x06,
       5,    2,   79,    2, 0x06,
       8,    2,   84,    2, 0x06,
      10,    2,   89,    2, 0x06,
      12,    1,   94,    2, 0x06,
      15,    2,   97,    2, 0x06,
      17,    2,  102,    2, 0x06,
      19,    3,  107,    2, 0x06,
      21,    3,  114,    2, 0x06,
      23,    3,  121,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
      26,    0,  128,    2, 0x08,
      27,    0,  129,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 6,    3,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,   11,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,   16,
    QMetaType::Void, 0x80000000 | 13, QMetaType::Int,   14,   18,
    QMetaType::Void, 0x80000000 | 13, QMetaType::Int, QMetaType::QString,   14,    3,   20,
    QMetaType::Void, 0x80000000 | 13, QMetaType::Int, QMetaType::Int,   14,    3,   22,
    QMetaType::Void, 0x80000000 | 13, QMetaType::Int, 0x80000000 | 24,   14,    3,   25,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QNetworkInfoPrivate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QNetworkInfoPrivate *_t = static_cast<QNetworkInfoPrivate *>(_o);
        switch (_id) {
        case 0: _t->cellIdChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->currentCellDataTechnologyChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QNetworkInfo::CellDataTechnology(*)>(_a[2]))); break;
        case 2: _t->currentMobileCountryCodeChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 3: _t->currentMobileNetworkCodeChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: _t->currentNetworkModeChanged((*reinterpret_cast< QNetworkInfo::NetworkMode(*)>(_a[1]))); break;
        case 5: _t->locationAreaCodeChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 6: _t->networkInterfaceCountChanged((*reinterpret_cast< QNetworkInfo::NetworkMode(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->networkNameChanged((*reinterpret_cast< QNetworkInfo::NetworkMode(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 8: _t->networkSignalStrengthChanged((*reinterpret_cast< QNetworkInfo::NetworkMode(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 9: _t->networkStatusChanged((*reinterpret_cast< QNetworkInfo::NetworkMode(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QNetworkInfo::NetworkStatus(*)>(_a[3]))); break;
        case 10: _t->networkStrengthTimeout(); break;
        case 11: _t->networkStatusTimeout(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QNetworkInfoPrivate::*_t)(int , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QNetworkInfoPrivate::cellIdChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (QNetworkInfoPrivate::*_t)(int , QNetworkInfo::CellDataTechnology );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QNetworkInfoPrivate::currentCellDataTechnologyChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (QNetworkInfoPrivate::*_t)(int , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QNetworkInfoPrivate::currentMobileCountryCodeChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (QNetworkInfoPrivate::*_t)(int , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QNetworkInfoPrivate::currentMobileNetworkCodeChanged)) {
                *result = 3;
            }
        }
        {
            typedef void (QNetworkInfoPrivate::*_t)(QNetworkInfo::NetworkMode );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QNetworkInfoPrivate::currentNetworkModeChanged)) {
                *result = 4;
            }
        }
        {
            typedef void (QNetworkInfoPrivate::*_t)(int , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QNetworkInfoPrivate::locationAreaCodeChanged)) {
                *result = 5;
            }
        }
        {
            typedef void (QNetworkInfoPrivate::*_t)(QNetworkInfo::NetworkMode , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QNetworkInfoPrivate::networkInterfaceCountChanged)) {
                *result = 6;
            }
        }
        {
            typedef void (QNetworkInfoPrivate::*_t)(QNetworkInfo::NetworkMode , int , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QNetworkInfoPrivate::networkNameChanged)) {
                *result = 7;
            }
        }
        {
            typedef void (QNetworkInfoPrivate::*_t)(QNetworkInfo::NetworkMode , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QNetworkInfoPrivate::networkSignalStrengthChanged)) {
                *result = 8;
            }
        }
        {
            typedef void (QNetworkInfoPrivate::*_t)(QNetworkInfo::NetworkMode , int , QNetworkInfo::NetworkStatus );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QNetworkInfoPrivate::networkStatusChanged)) {
                *result = 9;
            }
        }
    }
}

const QMetaObject QNetworkInfoPrivate::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QNetworkInfoPrivate.data,
      qt_meta_data_QNetworkInfoPrivate,  qt_static_metacall, 0, 0}
};


const QMetaObject *QNetworkInfoPrivate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QNetworkInfoPrivate::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QNetworkInfoPrivate.stringdata))
        return static_cast<void*>(const_cast< QNetworkInfoPrivate*>(this));
    return QObject::qt_metacast(_clname);
}

int QNetworkInfoPrivate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void QNetworkInfoPrivate::cellIdChanged(int _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QNetworkInfoPrivate::currentCellDataTechnologyChanged(int _t1, QNetworkInfo::CellDataTechnology _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QNetworkInfoPrivate::currentMobileCountryCodeChanged(int _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QNetworkInfoPrivate::currentMobileNetworkCodeChanged(int _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QNetworkInfoPrivate::currentNetworkModeChanged(QNetworkInfo::NetworkMode _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QNetworkInfoPrivate::locationAreaCodeChanged(int _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void QNetworkInfoPrivate::networkInterfaceCountChanged(QNetworkInfo::NetworkMode _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void QNetworkInfoPrivate::networkNameChanged(QNetworkInfo::NetworkMode _t1, int _t2, const QString & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void QNetworkInfoPrivate::networkSignalStrengthChanged(QNetworkInfo::NetworkMode _t1, int _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void QNetworkInfoPrivate::networkStatusChanged(QNetworkInfo::NetworkMode _t1, int _t2, QNetworkInfo::NetworkStatus _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_END_MOC_NAMESPACE
