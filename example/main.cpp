/**
 * Copyright 2017 Thomas Ascher <thomas.ascher@gmx.at>
 * SPDX-License-Identifier: MIT
 */

#include "mainwindow.h"
#include <QtWidgets/QApplication>
#include <QtCore/QDir>
#include "qlickinspector.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QlickInspector inspector(qApp, QDir::homePath() + "/eventlog");
    inspector.setEnabled(true);

    // NOTE: enable only for user which should be able to generate heatmap reports
    inspector.setHotKeyEnabled(true);

    MainWindow w;
    w.show();

    return a.exec();
}
