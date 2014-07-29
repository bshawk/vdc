/****************************************************************************
** Meta object code from reading C++ file 'vscview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../main/vscview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vscview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VSCView_t {
    QByteArrayData data[24];
    char stringdata[324];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_VSCView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_VSCView_t qt_meta_stringdata_VSCView = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 15),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 13),
QT_MOC_LITERAL(4, 39, 19),
QT_MOC_LITERAL(5, 59, 18),
QT_MOC_LITERAL(6, 78, 3),
QT_MOC_LITERAL(7, 82, 16),
QT_MOC_LITERAL(8, 99, 15),
QT_MOC_LITERAL(9, 115, 18),
QT_MOC_LITERAL(10, 134, 14),
QT_MOC_LITERAL(11, 149, 12),
QT_MOC_LITERAL(12, 162, 1),
QT_MOC_LITERAL(13, 164, 16),
QT_MOC_LITERAL(14, 181, 16),
QT_MOC_LITERAL(15, 198, 16),
QT_MOC_LITERAL(16, 215, 14),
QT_MOC_LITERAL(17, 230, 17),
QT_MOC_LITERAL(18, 248, 14),
QT_MOC_LITERAL(19, 263, 16),
QT_MOC_LITERAL(20, 280, 16),
QT_MOC_LITERAL(21, 297, 11),
QT_MOC_LITERAL(22, 309, 8),
QT_MOC_LITERAL(23, 318, 4)
    },
    "VSCView\0floatingClicked\0\0TabbedClicked\0"
    "ControlPanelClicked\0ShowDisplayClicked\0"
    "nId\0ShowFocusClicked\0ShowPlayControl\0"
    "ShowLayout1Clicked\0mouseMoveEvent\0"
    "QMouseEvent*\0e\0SetLayoutMode4x4\0"
    "SetLayoutMode3x3\0SetLayoutMode2x2\0"
    "SetLayoutMode6\0SetLayoutMode12p1\0"
    "SetLayoutMode1\0SetLayoutMode5x5\0"
    "SetLayoutMode6x6\0DeviceEvent\0deviceId\0"
    "type\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VSCView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x0a,
       3,    0,  100,    2, 0x0a,
       4,    0,  101,    2, 0x0a,
       5,    1,  102,    2, 0x0a,
       7,    1,  105,    2, 0x0a,
       8,    0,  108,    2, 0x0a,
       9,    1,  109,    2, 0x0a,
      10,    1,  112,    2, 0x0a,
      13,    0,  115,    2, 0x0a,
      14,    0,  116,    2, 0x0a,
      15,    0,  117,    2, 0x0a,
      16,    0,  118,    2, 0x0a,
      17,    0,  119,    2, 0x0a,
      18,    0,  120,    2, 0x0a,
      19,    0,  121,    2, 0x0a,
      20,    0,  122,    2, 0x0a,
      21,    2,  123,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   22,   23,

       0        // eod
};

void VSCView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VSCView *_t = static_cast<VSCView *>(_o);
        switch (_id) {
        case 0: _t->floatingClicked(); break;
        case 1: _t->TabbedClicked(); break;
        case 2: _t->ControlPanelClicked(); break;
        case 3: _t->ShowDisplayClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->ShowFocusClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->ShowPlayControl(); break;
        case 6: _t->ShowLayout1Clicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->mouseMoveEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 8: _t->SetLayoutMode4x4(); break;
        case 9: _t->SetLayoutMode3x3(); break;
        case 10: _t->SetLayoutMode2x2(); break;
        case 11: _t->SetLayoutMode6(); break;
        case 12: _t->SetLayoutMode12p1(); break;
        case 13: _t->SetLayoutMode1(); break;
        case 14: _t->SetLayoutMode5x5(); break;
        case 15: _t->SetLayoutMode6x6(); break;
        case 16: _t->DeviceEvent((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject VSCView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_VSCView.data,
      qt_meta_data_VSCView,  qt_static_metacall, 0, 0}
};


const QMetaObject *VSCView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VSCView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VSCView.stringdata))
        return static_cast<void*>(const_cast< VSCView*>(this));
    return QWidget::qt_metacast(_clname);
}

int VSCView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
