/****************************************************************************
** Meta object code from reading C++ file 'registration.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../registration.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'registration.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_registration_t {
    uint offsetsAndSizes[22];
    char stringdata0[13];
    char stringdata1[21];
    char stringdata2[1];
    char stringdata3[15];
    char stringdata4[16];
    char stringdata5[14];
    char stringdata6[5];
    char stringdata7[7];
    char stringdata8[12];
    char stringdata9[8];
    char stringdata10[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_registration_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_registration_t qt_meta_stringdata_registration = {
    {
        QT_MOC_LITERAL(0, 12),  // "registration"
        QT_MOC_LITERAL(13, 20),  // "on_playNoReg_clicked"
        QT_MOC_LITERAL(34, 0),  // ""
        QT_MOC_LITERAL(35, 14),  // "on_reg_clicked"
        QT_MOC_LITERAL(50, 15),  // "on_back_clicked"
        QT_MOC_LITERAL(66, 13),  // "funct_registr"
        QT_MOC_LITERAL(80, 4),  // "Save"
        QT_MOC_LITERAL(85, 6),  // "record"
        QT_MOC_LITERAL(92, 11),  // "Save_record"
        QT_MOC_LITERAL(104, 7),  // "read_db"
        QT_MOC_LITERAL(112, 8)   // "read_rec"
    },
    "registration",
    "on_playNoReg_clicked",
    "",
    "on_reg_clicked",
    "on_back_clicked",
    "funct_registr",
    "Save",
    "record",
    "Save_record",
    "read_db",
    "read_rec"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_registration[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x08,    1 /* Private */,
       3,    0,   69,    2, 0x08,    2 /* Private */,
       4,    0,   70,    2, 0x08,    3 /* Private */,
       5,    0,   71,    2, 0x08,    4 /* Private */,
       6,    0,   72,    2, 0x08,    5 /* Private */,
       7,    0,   73,    2, 0x08,    6 /* Private */,
       8,    0,   74,    2, 0x08,    7 /* Private */,
       9,    0,   75,    2, 0x08,    8 /* Private */,
      10,    0,   76,    2, 0x08,    9 /* Private */,

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

Q_CONSTINIT const QMetaObject registration::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_registration.offsetsAndSizes,
    qt_meta_data_registration,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_registration_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<registration, std::true_type>,
        // method 'on_playNoReg_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_reg_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_back_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'funct_registr'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Save'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'record'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Save_record'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'read_db'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'read_rec'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void registration::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<registration *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_playNoReg_clicked(); break;
        case 1: _t->on_reg_clicked(); break;
        case 2: _t->on_back_clicked(); break;
        case 3: _t->funct_registr(); break;
        case 4: _t->Save(); break;
        case 5: _t->record(); break;
        case 6: _t->Save_record(); break;
        case 7: _t->read_db(); break;
        case 8: _t->read_rec(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *registration::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *registration::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_registration.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "sound"))
        return static_cast< sound*>(this);
    return QWidget::qt_metacast(_clname);
}

int registration::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
