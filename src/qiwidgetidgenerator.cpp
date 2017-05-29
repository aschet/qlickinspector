/**
 * Copyright 2017 Thomas Ascher <thomas.ascher@gmx.at>
 * SPDX-License-Identifier: LGPL-3.0+
 */

#include "qiwidgetidgenerator.h"
#include "qiqtincludefix.h"

QString QIWidgetIDGenerator::generate(QWidget* widget)
{
    QWidget* parent = widget->parentWidget();
    if (parent)
        return generate(parent) + "/" + widget->objectName();
    else
        return widget->objectName();
}
