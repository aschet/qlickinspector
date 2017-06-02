/**
 * Copyright 2017 Thomas Ascher <thomas.ascher@gmx.at>
 * SPDX-License-Identifier: LGPL-3.0+
 */

#include "qiwidgetidgenerator.h"
#include "qiqtincludefix.h"

static QString getName(const QWidget* widget)
{
    QString name = widget->objectName();
    if (name.isEmpty())
    {
        // NOTE: workaround to handle actions in toolbars
        const QAbstractButton* button = dynamic_cast<const QAbstractButton*>(widget);
        if (button)
            name = button->text();
    }
    if (name.isEmpty())
    {
        name = widget->windowTitle();
    }

    return name;
}

QString QIWidgetIDGenerator::generate(const QWidget* widget)
{
    QWidget* parent = widget->parentWidget();
    if (parent)
        return generate(parent) + "/" + getName(widget);
    else
        return getName(widget);
}
