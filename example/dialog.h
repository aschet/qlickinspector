/**
 * Copyright 2017 Thomas Ascher <thomas.ascher@gmx.at>
 * SPDX-License-Identifier: MIT
 */

#ifndef DIALOG_H
#define DIALOG_H

#include <QtCore/qglobal.h>
#if (QT_VERSION >= 0x050000)
    #include <QtWidgets/QDialog>
#else
    #include <QtGui/QDialog>
#endif

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog(QWidget *parent = 0);

    ~Dialog();

private:
    Ui::Dialog *ui;
};

#endif
