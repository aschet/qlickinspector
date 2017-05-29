/**
 * Copyright 2017 Thomas Ascher <thomas.ascher@gmx.at>
 * SPDX-License-Identifier: LGPL-3.0+
 */

#include "qiheatmaprenderer.h"
#include "qiscreenshotgrabber.h"
#include "qimaxeventcountevaluator.h"
#include "qieventcounter.h"
#include "qiqtincludefix.h"
#include <QtGui/QPainter>

QIHeatmapRenderer::QIHeatmapRenderer(std::shared_ptr<QIEventCounter> counterRef)
    :counter(counterRef)
{

}

QIHeatmapRenderer::~QIHeatmapRenderer()
{

}

QPixmap QIHeatmapRenderer::render(QWidget *widget)
{
    topWidget = widget;
    colorMapping = QIColorMapping(QIMaxEventCountEvaluator(counter).getMaxCount(widget));
    screenshot = QIScreenshotGrabber::grab(widget);
    visit(widget);
    return screenshot;
}

void QIHeatmapRenderer::visit(QWidget* widget)
{
    QIWidgetHierarchyVisitor::visit(widget);

    QPainter painter(&screenshot);
    QPoint parentPos = widget->mapTo(topWidget, QPoint());
    QRect contentRect = widget->rect().translated(parentPos);

    QRegion childRegion = widget->childrenRegion();
    if (!childRegion.isEmpty())
    {
        childRegion.translate(parentPos);
        painter.setClipRegion(QRegion(contentRect).subtracted(childRegion));
    }

    painter.fillRect(contentRect, colorMapping.map(counter->get(widget)));
}
