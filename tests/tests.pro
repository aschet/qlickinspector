#-------------------------------------------------
#
# Project created by QtCreator 2017-05-27T14:34:02
#
#-------------------------------------------------

QT       += core gui testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tests
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    qlickinspectortests.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

FORMS += \
    qlickinspectortestsui.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../src/release -lqlickinspector
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../src/debug -lqlickinspectord
else:unix: LIBS += -L$$OUT_PWD/../src/ -lqlickinspector

INCLUDEPATH += $$PWD/../src
DEPENDPATH += $$PWD/../src
