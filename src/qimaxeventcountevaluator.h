/**
 * Copyright 2017 Thomas Ascher <thomas.ascher@gmx.at>
 * SPDX-License-Identifier: LGPL-3.0+
 */

#ifndef QIMAXEVENTCOUNTEVALUATOR_H
#define QIMAXEVENTCOUNTEVALUATOR_H

#include "qiwidgethierarchyvisitor.h"
#include <memory>
class QIEventCounter;

class QLICKINSPECTOR_EXPORT QIMaxEventCountEvaluator : protected QIWidgetHierarchyVisitor
{
public:
    QIMaxEventCountEvaluator(std::shared_ptr<QIEventCounter> counterRef);

    virtual ~QIMaxEventCountEvaluator();

    unsigned int getMaxCount(QWidget* widget);

private:
    virtual void visit(QWidget* widget) override;

    std::shared_ptr<QIEventCounter> counter;

    unsigned int maxCount;
};

#endif
