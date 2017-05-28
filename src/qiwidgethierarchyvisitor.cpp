/**
 * Copyright 2017 Thomas Ascher <thomas.ascher@gmx.at>
 * SPDX-License-Identifier: LGPL-3.0+
 */

#include "qiwidgethierarchyvisitor.h"

QIWidgetHierarchyVisitor::~QIWidgetHierarchyVisitor()
{

}

void QIWidgetHierarchyVisitor::visit(QWidget* widget)
{
    auto children = widget->children();

    for (auto it = children.begin(), endIt = children.end(); it != endIt; ++it)
    {
        if ((*it)->isWidgetType())
        {
            QWidget* child = static_cast<QWidget*>(*it);
            if (child->isVisible())
                visit(child);
        }
    }
}
