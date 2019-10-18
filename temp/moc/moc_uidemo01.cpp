/****************************************************************************
** Meta object code from reading C++ file 'uidemo01.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../uidemo01.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uidemo01.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UIDemo01_t {
    QByteArrayData data[10];
    char stringdata0[189];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UIDemo01_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UIDemo01_t qt_meta_stringdata_UIDemo01 = {
    {
QT_MOC_LITERAL(0, 0, 8), // "UIDemo01"
QT_MOC_LITERAL(1, 9, 8), // "initForm"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 11), // "buttonClick"
QT_MOC_LITERAL(4, 31, 22), // "on_btnMenu_Min_clicked"
QT_MOC_LITERAL(5, 54, 22), // "on_btnMenu_Max_clicked"
QT_MOC_LITERAL(6, 77, 24), // "on_btnMenu_Close_clicked"
QT_MOC_LITERAL(7, 102, 33), // "on_addMaterial_pushButton_cli..."
QT_MOC_LITERAL(8, 136, 34), // "on_managerQuery_pushButton_cl..."
QT_MOC_LITERAL(9, 171, 17) // "selectResult_slot"

    },
    "UIDemo01\0initForm\0\0buttonClick\0"
    "on_btnMenu_Min_clicked\0on_btnMenu_Max_clicked\0"
    "on_btnMenu_Close_clicked\0"
    "on_addMaterial_pushButton_clicked\0"
    "on_managerQuery_pushButton_clicked\0"
    "selectResult_slot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UIDemo01[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    1,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList,    2,

       0        // eod
};

void UIDemo01::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UIDemo01 *_t = static_cast<UIDemo01 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->initForm(); break;
        case 1: _t->buttonClick(); break;
        case 2: _t->on_btnMenu_Min_clicked(); break;
        case 3: _t->on_btnMenu_Max_clicked(); break;
        case 4: _t->on_btnMenu_Close_clicked(); break;
        case 5: _t->on_addMaterial_pushButton_clicked(); break;
        case 6: _t->on_managerQuery_pushButton_clicked(); break;
        case 7: _t->selectResult_slot((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject UIDemo01::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_UIDemo01.data,
      qt_meta_data_UIDemo01,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *UIDemo01::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UIDemo01::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_UIDemo01.stringdata0))
        return static_cast<void*>(const_cast< UIDemo01*>(this));
    return QDialog::qt_metacast(_clname);
}

int UIDemo01::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
