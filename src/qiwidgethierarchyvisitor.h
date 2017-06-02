/**
 * Copyright 2017 Thomas Ascher <thomas.ascher@gmx.at>
 * SPDX-License-Identifier: LGPL-3.0+
 */

#ifndef QIWIDGETHIERARCHYVISITOR_H
#define QIWIDGETHIERARCHYVISITOR_H

#include "qlickinspector_global.h"
class QWidget;

class QLICKINSPECTOR_EXPORT QIWidgetHierarchyVisitor
{
public:
    virtual ~QIWidgetHierarchyVisitor();

    virtual void visit(const QWidget* widget);
};

#endif
