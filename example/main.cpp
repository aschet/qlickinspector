/**
 * Copyright 2017 Thomas Ascher <thomas.ascher@gmx.at>
 * SPDX-License-Identifier: MIT
 */

#include "mainwindow.h"
#if (QT_VERSION >= 0x050000)
#include <QtWidgets/QApplication>
#else
#include <QtGui/QApplication>
#endif
#include <QtCore/QDir>
#include <qlickinspector.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QlickInspector inspector(qApp, QDir::homePath() + "/eventlog");
    inspector.setEnabled(true);

    // NOTE: enable only for users which should be able to generate heatmap reports
    inspector.setHotKeyEnabled(true);

    MainWindow w;
    w.show();

    return a.exec();
}
