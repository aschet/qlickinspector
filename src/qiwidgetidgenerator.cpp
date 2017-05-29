/**
 * Copyright 2017 Thomas Ascher <thomas.ascher@gmx.at>
 * SPDX-License-Identifier: LGPL-3.0+
 */

#include "qiwidgetidgenerator.h"
#include "qiqtincludefix.h"

static QString getName(QWidget* widget)
{
    QString name = widget->objectName();
    if (name.isEmpty())
    {
        // NOTE: workaround to handle actions in toolbars
        QAbstractButton* button = dynamic_cast<QAbstractButton*>(widget);
        if (button)
            name = button->text();
    }

    return name;
}

QString QIWidgetIDGenerator::generate(QWidget* widget)
{
    QWidget* parent = widget->parentWidget();
    if (parent)
        return generate(parent) + "/" + getName(widget);
    else
        return getName(widget);
}
