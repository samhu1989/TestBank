#-------------------------------------------------
#
# Project created by QtCreator 2016-10-10T19:34:12
#
#-------------------------------------------------

QT       -= core gui

TARGET = CountMS
TEMPLATE = lib

DEFINES += COUNTMS_LIBRARY

SOURCES += countms.cpp

HEADERS += countms.h\
        countms_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

DESTDIR = $$OUT_PWD/../../TestBank_RunTime/bin
