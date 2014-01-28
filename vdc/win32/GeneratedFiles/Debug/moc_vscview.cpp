/****************************************************************************
** Meta object code from reading C++ file 'vscview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../main/vscview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vscview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VSCView_t {
    QByteArrayData data[11];
    char stringdata[126];
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
QT_MOC_LITERAL(4, 39, 18),
QT_MOC_LITERAL(5, 58, 3),
QT_MOC_LITERAL(6, 62, 16),
QT_MOC_LITERAL(7, 79, 15),
QT_MOC_LITERAL(8, 95, 14),
QT_MOC_LITERAL(9, 110, 12),
QT_MOC_LITERAL(10, 123, 1)
    },
    "VSCView\0floatingClicked\0\0TabbedClicked\0"
    "ShowDisplayClicked\0nId\0ShowFocusClicked\0"
    "ShowPlayControl\0mouseMoveEvent\0"
    "QMouseEvent*\0e\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VSCView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a,
       3,    0,   45,    2, 0x0a,
       4,    1,   46,    2, 0x0a,
       6,    1,   49,    2, 0x0a,
       7,    0,   52,    2, 0x0a,
       8,    1,   53,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,

       0        // eod
};

void VSCView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VSCView *_t = static_cast<VSCView *>(_o);
        switch (_id) {
        case 0: _t->floatingClicked(); break;
        case 1: _t->TabbedClicked(); break;
        case 2: _t->ShowDisplayClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->ShowFocusClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->ShowPlayControl(); break;
        case 5: _t->mouseMoveEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
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
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
