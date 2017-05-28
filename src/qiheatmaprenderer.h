/**
 * Copyright 2017 Thomas Ascher <thomas.ascher@gmx.at>
 * SPDX-License-Identifier: LGPL-3.0+
 */

#ifndef QIHEATMAPRENDERER_H
#define QIHEATMAPRENDERER_H

#include "qlickinspector_global.h"
#include "qiwidgethierarchyvisitor.h"
#include "qicolormapping.h"
#include <memory>
#include <QtGui/QPixmap>
class QIEventCounter;

class QLICKINSPECTOR_EXPORT QIHeatmapRenderer : protected QIWidgetHierarchyVisitor
{
public:
    QIHeatmapRenderer(std::shared_ptr<QIEventCounter> counterRef);

    virtual ~QIHeatmapRenderer();

    QPixmap render(QWidget* widget);

private:
    virtual void visit(QWidget* widget) override;

    std::shared_ptr<QIEventCounter> counter;

    QIColorMapping colorMapping;

    QWidget* topWidget;

    QPixmap screenshot;
};

#endif
