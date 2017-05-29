/**
 * Copyright 2017 Thomas Ascher <thomas.ascher@gmx.at>
 * SPDX-License-Identifier: LGPL-3.0+
 */

#ifndef QIWIDGETIDGENERATOR_H
#define QIWIDGETIDGENERATOR_H

#include "qlickinspector_global.h"
#include <QtCore/QString>
class QWidget;

class QLICKINSPECTOR_EXPORT QIWidgetIDGenerator
{
public:
    static QString generate(QWidget* widget);
};

#endif
