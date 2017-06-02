/**
 * Copyright 2017 Thomas Ascher <thomas.ascher@gmx.at>
 * SPDX-License-Identifier: MIT
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/qglobal.h>
#if (QT_VERSION >= 0x050000)
    #include <QtWidgets/QMainWindow>
#else
    #include <QtGui/QMainWindow>
#endif

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private slots:
    void openDialog();

private:
    Ui::MainWindow *ui;
};

#endif
