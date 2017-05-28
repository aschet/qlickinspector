/**
 * Copyright 2017 Thomas Ascher <thomas.ascher@gmx.at>
 * SPDX-License-Identifier: LGPL-3.0+
 */

#include "qiscreenshotgrabber.h"
#include <QtWidgets/QWidget>
#include <QtGui/QPixmap>

QPixmap QIScreenshotGrabber::grab(QWidget* widget)
{
    QPixmap pixmap(widget->size());
    widget->render(&pixmap);
    return pixmap;
}
