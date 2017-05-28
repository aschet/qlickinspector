#-------------------------------------------------
#
# Project created by QtCreator 2017-05-27T14:34:02
#
#-------------------------------------------------

QT       += widgets testlib

TARGET = tst_teststest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    qlickinspectortests.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

FORMS += \
    qlickinspectortestsui.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../src/ -lsrc
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../src/ -lsrcd
else:unix: LIBS += -L$$OUT_PWD/../src/ -lsrc

INCLUDEPATH += $$PWD/../src
DEPENDPATH += $$PWD/../src
