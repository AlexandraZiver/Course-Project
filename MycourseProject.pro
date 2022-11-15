QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    about.cpp \
    authentication.cpp \
    ball.cpp \
    bonus.cpp \
    data.cpp \
    error.cpp \
    exception.cpp \
    gamescene.cpp \
    main.cpp \
    mainwindow.cpp \
    player.cpp \
    record.cpp \
    registr.cpp \
    registration.cpp \
    rules.cpp \
    scene.cpp \
    wall.cpp

HEADERS += \
    Box2D/Box2D.h \
    about.h \
    authentication.h \
    ball.h \
    bonus.h \
    data.h \
    error.h \
    exception.h \
    gamescene.h \
    mainwindow.h \
    player.h \
    record.h \
    registr.h \
    registration.h \
    rules.h \
    scene.h \
    wall.h

FORMS += \
    about.ui \
    authentication.ui \
    gamescene.ui \
    mainwindow.ui \
    record.ui \
    registr.ui \
    registration.ui \
    registration2.ui \
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
    ../../../Downloads/Пауза.png
