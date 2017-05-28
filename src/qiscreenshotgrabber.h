/**
 * Copyright 2017 Thomas Ascher <thomas.ascher@gmx.at>
 * SPDX-License-Identifier: LGPL-3.0+
 */

#ifndef QISCREENSHOTGRABBER_H
#define QISCREENSHOTGRABBER_H

#include "qlickinspector_global.h"
class QPixmap;
class QWidget;

class QLICKINSPECTOR_EXPORT QIScreenshotGrabber
{
public:
    static QPixmap grab(QWidget* widget);
};

#endif
