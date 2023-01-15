/****************************************************************************
** Meta object code from reading C++ file 'pause.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../pause.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pause.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_Pause_t {
    uint offsetsAndSizes[12];
    char stringdata0[6];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[26];
    char stringdata4[19];
    char stringdata5[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Pause_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_Pause_t qt_meta_stringdata_Pause = {
    {
        QT_MOC_LITERAL(0, 5),  // "Pause"
        QT_MOC_LITERAL(6, 18),  // "on_menuBtn_clicked"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 25),  // "on_continueButton_clicked"
        QT_MOC_LITERAL(52, 18),  // "on_exitBtn_clicked"
        QT_MOC_LITERAL(71, 4)   // "slot"
    },
    "Pause",
    "on_menuBtn_clicked",
    "",
    "on_continueButton_clicked",
    "on_exitBtn_clicked",
    "slot"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_Pause[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x08,    1 /* Private */,
       3,    0,   39,    2, 0x08,    2 /* Private */,
       4,    0,   40,    2, 0x08,    3 /* Private */,
       5,    0,   41,    2, 0x0a,    4 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Pause::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Pause.offsetsAndSizes,
    qt_meta_data_Pause,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_Pause_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Pause, std::true_type>,
        // method 'on_menuBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_continueButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_exitBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Pause::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Pause *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_menuBtn_clicked(); break;
        case 1: _t->on_continueButton_clicked(); break;
        case 2: _t->on_exitBtn_clicked(); break;
        case 3: _t->slot(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *Pause::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Pause::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Pause.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "sound"))
        return static_cast< sound*>(this);
    return QDialog::qt_metacast(_clname);
}

int Pause::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
