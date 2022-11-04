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
    data.cpp \
    error.cpp \
    exception.cpp \
    gamescene.cpp \
    main.cpp \
    mainwindow.cpp \
    pausewindow.cpp \
    player.cpp \
    record.cpp \
    registr.cpp \
    rules.cpp \
    wall.cpp

HEADERS += \
    about.h \
    authentication.h \
    ball.h \
    data.h \
    error.h \
    exception.h \
    gamescene.h \
    mainwindow.h \
    pausewindow.h \
    player.h \
    record.h \
    registr.h \
    rules.h \
    wall.h

FORMS += \
    about.ui \
    authentication.ui \
    gamescene.ui \
    mainwindow.ui \
    pausewindow.ui \
    record.ui \
    registr.ui \
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
