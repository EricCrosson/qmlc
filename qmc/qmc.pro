#-------------------------------------------------
#
# Project created by QtCreator 2014-07-14T21:10:27
#
#-------------------------------------------------

QT       += core qml

QT       -= gui

TARGET = qmc
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../qmccompiler

LIBS += -L../qmccompiler

LIBS += -lqmccompiler

SOURCES += main.cpp \
    comp.cpp

HEADERS += \
    comp.h

unix {
    target.path = /usr/bin
    INSTALLS += target
}
