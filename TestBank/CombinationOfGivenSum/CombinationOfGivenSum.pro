#-------------------------------------------------
#
# Project created by QtCreator 2016-09-23T17:05:57
#
#-------------------------------------------------

QT       -= gui

TARGET = CombinationOfGivenSum
TEMPLATE = lib

DEFINES += COMBINATIONOFGIVENSUM_LIBRARY

SOURCES += combinationofgivensum.cpp

HEADERS += combinationofgivensum.h\
        combinationofgivensum_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

DESTDIR = $$OUT_PWD/../../TestBank_RunTime/bin
