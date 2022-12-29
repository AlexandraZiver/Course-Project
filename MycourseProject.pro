QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia
QT += multimedia
QT += multimediawidgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    about.cpp \
    authorization.cpp \
    ball.cpp \
    bonus.cpp \
    data.cpp \
    error.cpp \
    exception.cpp \
    gamepreparation.cpp \
    gamescene.cpp \
    main.cpp \
    mainwindow.cpp \
    obj.cpp \
    pause.cpp \
    player.cpp \
    record.cpp \
    registration.cpp \
    rules.cpp \
    scene.cpp \
    sound.cpp \
    wall.cpp

HEADERS += \
    Box2D/Box2D.h \
    about.h \
    authorization.h \
    ball.h \
    bonus.h \
    data.h \
    error.h \
    exception.h \
    gamepreparation.h \
    gamescene.h \
    mainwindow.h \
    obj.h \
    pause.h \
    player.h \
    record.h \
    registration.h \
    rules.h \
    scene.h \
    sound.h \
    wall.h

FORMS += \
    about.ui \
    authorization.ui \
    gamepreparation.ui \
    gamescene.ui \
    mainwindow.ui \
    pause.ui \
    record.ui \
    registration.ui \
    rules.ui

TRANSLATIONS += \
    MycourseProject_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.


RESOURCES += \
    recources.qrc

win32: LIBS += -L$$PWD/./ -lBox2D

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/./Box2D.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/./libBox2D.a

DISTFILES += \
    ../../../Downloads/Пауза.png \
    .DS_Store \
    images/Pause.png
