/**
 * Copyright 2017 Thomas Ascher <thomas.ascher@gmx.at>
 * SPDX-License-Identifier: MIT
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButtonDialog, SIGNAL(clicked(bool)), this, SLOT(openDialog()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openDialog()
{
    Dialog dialog(this);
    dialog.exec();
}
