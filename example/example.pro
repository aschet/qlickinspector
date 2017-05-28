#-------------------------------------------------
#
# Project created by QtCreator 2017-05-28T12:26:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = example
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp

HEADERS  += mainwindow.h \
    dialog.h

FORMS    += mainwindow.ui \
    dialog.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../src/ -lqlickinspector
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../src/ -lqlickinspectord
else:unix: LIBS += -L$$OUT_PWD/../src/ -lqlickinspector

INCLUDEPATH += $$PWD/../src
DEPENDPATH += $$PWD/../src
