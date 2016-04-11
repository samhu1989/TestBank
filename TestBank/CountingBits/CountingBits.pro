#-------------------------------------------------
#
# Project created by QtCreator 2016-04-11T22:29:03
#
#-------------------------------------------------

QT       -= core gui

TARGET = CountingBits
TEMPLATE = lib

DEFINES += COUNTINGBITS_LIBRARY

SOURCES += countingbits.cpp

HEADERS += countingbits.h\
        countingbits_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
