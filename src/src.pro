#-------------------------------------------------
#
# Project created by QtCreator 2017-05-27T14:28:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qlickinspector
TEMPLATE = lib
VERSION = 1.0.0

CONFIG(debug, debug|release) {
     win32: TARGET = $$join(TARGET,,,d)
}

win32 {
    DESTDIR         = $$[QT_INSTALL_LIBS]
    DLLDESTDIR      = $$[QT_INSTALL_BINS]
}

DEFINES += QLICKINSPECTOR_LIBRARY

SOURCES += \
    unqlite.c \
    qieventcounter.cpp \
    qieventinterceptor.cpp \
    qikeyvaluestore.cpp \
    qiscreenshotgrabber.cpp \
    qiwidgetidgenerator.cpp \
    qiwidgethierarchyvisitor.cpp \
    qimaxeventcountevaluator.cpp \
    qiheatmaprenderer.cpp \
    qicolormapping.cpp \
    qlickinspector.cpp

HEADERS += \
    unqlite.h \
    qlickinspector_global.h \
    qieventcounter.h \
    qieventinterceptor.h \
    qikeyvaluestore.h \
    qiscreenshotgrabber.h \
    qiwidgetidgenerator.h \
    qiwidgethierarchyvisitor.h \
    qimaxeventcountevaluator.h \
    qiheatmaprenderer.h \
    qicolormapping.h \
    qlickinspector.h \
    qiqtincludefix.h

headers.files = \
    qlickinspector_global.h \
    qlickinspector.h

headers.path = $$[QT_INSTALL_HEADERS]

win32 {
    target.path = $$[QT_INSTALL_BINS]
} else {
    target.path = $$[QT_INSTALL_LIBS]
}

INSTALLS += headers target
