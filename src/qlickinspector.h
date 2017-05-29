/**
 * Copyright 2017 Thomas Ascher <thomas.ascher@gmx.at>
 * SPDX-License-Identifier: LGPL-3.0+
 */

#ifndef QLICKINSPECTOR_H
#define QLICKINSPECTOR_H

#include "qlickinspector_global.h"
class QlickInspectorPrivate;
class QApplication;
class QImage;
class QWidget;

class QLICKINSPECTOR_EXPORT QlickInspector
{
public:
    QlickInspector(QApplication* app);

    QlickInspector(QApplication* app, const QString& eventLogPath);

    ~QlickInspector();

    void setEnabled(bool enabled);

    bool isEnabled() const;

    void setHotKeyEnabled(bool enabled);

    bool isHotKeyEnabled() const;

    QImage renderHeatmap(QWidget* widget);

private:
    QlickInspector(const QlickInspector&);

    QlickInspectorPrivate* p;
};

#endif
