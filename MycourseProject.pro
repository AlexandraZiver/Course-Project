QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    about.cpp \
    authentication.cpp \
    main.cpp \
    mainwindow.cpp \
    record.cpp \
    registr.cpp \
    rules.cpp

HEADERS += \
    about.h \
    authentication.h \
    mainwindow.h \
    record.h \
    registr.h \
    rules.h

FORMS += \
    about.ui \
    authentication.ui \
    mainwindow.ui \
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
