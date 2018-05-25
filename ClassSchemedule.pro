#-------------------------------------------------
#
# Project created by QtCreator 2018-05-16T19:22:40
#
#-------------------------------------------------

QT       += core gui
QT +=xlsx

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ClassSchemedule
TEMPLATE = app
UI_DIR=./UI

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        login.cpp \
    register_.cpp \
    startpage.cpp \
    export.cpp

HEADERS += \
        login.h \
    register_.h \
    startpage.h \
    export.h

FORMS += \
        login.ui \
    register_.ui \
    startpage.ui

RESOURCES += \
    classschemedulepicture.qrc

DISTFILES +=
