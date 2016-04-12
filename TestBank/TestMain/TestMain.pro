TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

DESTDIR = $$OUT_PWD/../../TestBank_RunTime/bin

win32: LIBS += -L$$DESTDIR -lCountingBits

INCLUDEPATH += $$PWD/../CountingBits
DEPENDPATH += $$PWD/../CountingBits
