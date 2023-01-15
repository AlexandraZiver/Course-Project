/****************************************************************************
** Meta object code from reading C++ file 'gamescene.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../gamescene.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamescene.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_Scene_t {
    uint offsetsAndSizes[6];
    char stringdata0[6];
    char stringdata1[8];
    char stringdata2[1];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Scene_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_Scene_t qt_meta_stringdata_Scene = {
    {
        QT_MOC_LITERAL(0, 5),  // "Scene"
        QT_MOC_LITERAL(6, 7),  // "advance"
        QT_MOC_LITERAL(14, 0)   // ""
    },
    "Scene",
    "advance",
    ""
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_Scene[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   20,    2, 0x0a,    1 /* Public */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Scene::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsScene::staticMetaObject>(),
    qt_meta_stringdata_Scene.offsetsAndSizes,
    qt_meta_data_Scene,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_Scene_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Scene, std::true_type>,
        // method 'advance'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Scene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Scene *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->advance(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *Scene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Scene::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Scene.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "sound"))
        return static_cast< sound*>(this);
    return QGraphicsScene::qt_metacast(_clname);
}

int Scene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}
namespace {
struct qt_meta_stringdata_GameScene_t {
    uint offsetsAndSizes[24];
    char stringdata0[10];
    char stringdata1[6];
    char stringdata2[1];
    char stringdata3[10];
    char stringdata4[8];
    char stringdata5[10];
    char stringdata6[17];
    char stringdata7[24];
    char stringdata8[21];
    char stringdata9[12];
    char stringdata10[9];
    char stringdata11[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_GameScene_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_GameScene_t qt_meta_stringdata_GameScene = {
    {
        QT_MOC_LITERAL(0, 9),  // "GameScene"
        QT_MOC_LITERAL(10, 5),  // "Score"
        QT_MOC_LITERAL(16, 0),  // ""
        QT_MOC_LITERAL(17, 9),  // "BallSleep"
        QT_MOC_LITERAL(27, 7),  // "EndGame"
        QT_MOC_LITERAL(35, 9),  // "StartGame"
        QT_MOC_LITERAL(45, 16),  // "GenerateNewBonus"
        QT_MOC_LITERAL(62, 23),  // "on_startNewGame_clicked"
        QT_MOC_LITERAL(86, 20),  // "on_pauseGame_clicked"
        QT_MOC_LITERAL(107, 11),  // "Save_record"
        QT_MOC_LITERAL(119, 8),  // "read_rec"
        QT_MOC_LITERAL(128, 13)   // "change_record"
    },
    "GameScene",
    "Score",
    "",
    "BallSleep",
    "EndGame",
    "StartGame",
    "GenerateNewBonus",
    "on_startNewGame_clicked",
    "on_pauseGame_clicked",
    "Save_record",
    "read_rec",
    "change_record"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_GameScene[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   74,    2, 0x0a,    1 /* Public */,
       3,    0,   75,    2, 0x0a,    2 /* Public */,
       4,    0,   76,    2, 0x0a,    3 /* Public */,
       5,    0,   77,    2, 0x0a,    4 /* Public */,
       6,    0,   78,    2, 0x0a,    5 /* Public */,
       7,    0,   79,    2, 0x08,    6 /* Private */,
       8,    0,   80,    2, 0x08,    7 /* Private */,
       9,    0,   81,    2, 0x08,    8 /* Private */,
      10,    0,   82,    2, 0x08,    9 /* Private */,
      11,    0,   83,    2, 0x08,   10 /* Private */,

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
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject GameScene::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_GameScene.offsetsAndSizes,
    qt_meta_data_GameScene,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_GameScene_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<GameScene, std::true_type>,
        // method 'Score'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'BallSleep'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'EndGame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'StartGame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'GenerateNewBonus'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_startNewGame_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pauseGame_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Save_record'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'read_rec'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'change_record'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void GameScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GameScene *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Score(); break;
        case 1: _t->BallSleep(); break;
        case 2: _t->EndGame(); break;
        case 3: _t->StartGame(); break;
        case 4: _t->GenerateNewBonus(); break;
        case 5: _t->on_startNewGame_clicked(); break;
        case 6: _t->on_pauseGame_clicked(); break;
        case 7: _t->Save_record(); break;
        case 8: _t->read_rec(); break;
        case 9: _t->change_record(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *GameScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameScene::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GameScene.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "sound"))
        return static_cast< sound*>(this);
    return QWidget::qt_metacast(_clname);
}

int GameScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
