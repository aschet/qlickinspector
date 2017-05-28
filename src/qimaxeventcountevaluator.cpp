/**
 * Copyright 2017 Thomas Ascher <thomas.ascher@gmx.at>
 * SPDX-License-Identifier: LGPL-3.0+
 */

#include "qimaxeventcountevaluator.h"
#include "qieventcounter.h"

QIMaxEventCountEvaluator::QIMaxEventCountEvaluator(std::shared_ptr<QIEventCounter> counterRef)
    :counter(counterRef)
{

}

QIMaxEventCountEvaluator::~QIMaxEventCountEvaluator()
{

}

unsigned int QIMaxEventCountEvaluator::getMaxCount(QWidget *widget)
{
    maxCount = 0;
    visit(widget);
    return maxCount;
}

void QIMaxEventCountEvaluator::visit(QWidget *widget)
{
    unsigned int count = counter->get(widget);
    if (count > maxCount)
        maxCount = count;

    QIWidgetHierarchyVisitor::visit(widget);
}
