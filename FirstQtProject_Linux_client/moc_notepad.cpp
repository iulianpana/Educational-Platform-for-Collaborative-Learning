/****************************************************************************
** Meta object code from reading C++ file 'notepad.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "notepad.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'notepad.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Notepad_t {
    QByteArrayData data[19];
    char stringdata[270];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Notepad_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Notepad_t qt_meta_stringdata_Notepad = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 20),
QT_MOC_LITERAL(2, 29, 0),
QT_MOC_LITERAL(3, 30, 20),
QT_MOC_LITERAL(4, 51, 18),
QT_MOC_LITERAL(5, 70, 5),
QT_MOC_LITERAL(6, 76, 9),
QT_MOC_LITERAL(7, 86, 7),
QT_MOC_LITERAL(8, 94, 6),
QT_MOC_LITERAL(9, 101, 11),
QT_MOC_LITERAL(10, 113, 10),
QT_MOC_LITERAL(11, 124, 4),
QT_MOC_LITERAL(12, 129, 4),
QT_MOC_LITERAL(13, 134, 18),
QT_MOC_LITERAL(14, 153, 26),
QT_MOC_LITERAL(15, 180, 3),
QT_MOC_LITERAL(16, 184, 24),
QT_MOC_LITERAL(17, 209, 40),
QT_MOC_LITERAL(18, 250, 18)
    },
    "Notepad\0pushAllModifications\0\0"
    "pullAllModifications\0on_browser_clicked\0"
    "index\0newFolder\0newFile\0Delete\0"
    "updateError\0updateText\0save\0quit\0"
    "on_execute_clicked\0customContextMenuRequested\0"
    "pos\0on_browser_doubleClicked\0"
    "on_editWindow_customContextMenuRequested\0"
    "commitLocalChanges\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Notepad[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08,
       3,    0,   90,    2, 0x08,
       4,    1,   91,    2, 0x08,
       6,    0,   94,    2, 0x08,
       7,    0,   95,    2, 0x08,
       8,    0,   96,    2, 0x08,
       9,    0,   97,    2, 0x08,
      10,    0,   98,    2, 0x08,
      11,    0,   99,    2, 0x08,
      12,    0,  100,    2, 0x08,
      13,    0,  101,    2, 0x08,
      14,    1,  102,    2, 0x08,
      16,    1,  105,    2, 0x08,
      17,    1,  108,    2, 0x08,
      18,    0,  111,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   15,
    QMetaType::Void, QMetaType::QModelIndex,    5,
    QMetaType::Void, QMetaType::QPoint,   15,
    QMetaType::Void,

       0        // eod
};

void Notepad::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Notepad *_t = static_cast<Notepad *>(_o);
        switch (_id) {
        case 0: _t->pushAllModifications(); break;
        case 1: _t->pullAllModifications(); break;
        case 2: _t->on_browser_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: _t->newFolder(); break;
        case 4: _t->newFile(); break;
        case 5: _t->Delete(); break;
        case 6: _t->updateError(); break;
        case 7: _t->updateText(); break;
        case 8: _t->save(); break;
        case 9: _t->quit(); break;
        case 10: _t->on_execute_clicked(); break;
        case 11: _t->customContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 12: _t->on_browser_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 13: _t->on_editWindow_customContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 14: _t->commitLocalChanges(); break;
        default: ;
        }
    }
}

const QMetaObject Notepad::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Notepad.data,
      qt_meta_data_Notepad,  qt_static_metacall, 0, 0}
};


const QMetaObject *Notepad::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Notepad::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Notepad.stringdata))
        return static_cast<void*>(const_cast< Notepad*>(this));
    return QDialog::qt_metacast(_clname);
}

int Notepad::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
