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
    QByteArrayData data[12];
    char stringdata[168];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Notepad_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Notepad_t qt_meta_stringdata_Notepad = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 19),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 5),
QT_MOC_LITERAL(4, 35, 20),
QT_MOC_LITERAL(5, 56, 18),
QT_MOC_LITERAL(6, 75, 17),
QT_MOC_LITERAL(7, 93, 11),
QT_MOC_LITERAL(8, 105, 10),
QT_MOC_LITERAL(9, 116, 15),
QT_MOC_LITERAL(10, 132, 15),
QT_MOC_LITERAL(11, 148, 18)
    },
    "Notepad\0on_treeView_clicked\0\0index\0"
    "on_NewFolder_clicked\0on_NewFile_clicked\0"
    "on_Delete_clicked\0updateError\0updateText\0"
    "on_Save_clicked\0on_Quit_clicked\0"
    "on_execute_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Notepad[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x08,
       4,    0,   62,    2, 0x08,
       5,    0,   63,    2, 0x08,
       6,    0,   64,    2, 0x08,
       7,    0,   65,    2, 0x08,
       8,    0,   66,    2, 0x08,
       9,    0,   67,    2, 0x08,
      10,    0,   68,    2, 0x08,
      11,    0,   69,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex,    3,
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

void Notepad::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Notepad *_t = static_cast<Notepad *>(_o);
        switch (_id) {
        case 0: _t->on_treeView_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: _t->on_NewFolder_clicked(); break;
        case 2: _t->on_NewFile_clicked(); break;
        case 3: _t->on_Delete_clicked(); break;
        case 4: _t->updateError(); break;
        case 5: _t->updateText(); break;
        case 6: _t->on_Save_clicked(); break;
        case 7: _t->on_Quit_clicked(); break;
        case 8: _t->on_execute_clicked(); break;
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
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
