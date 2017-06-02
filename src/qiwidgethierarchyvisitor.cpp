/**
 * Copyright 2017 Thomas Ascher <thomas.ascher@gmx.at>
 * SPDX-License-Identifier: LGPL-3.0+
 */

#include "qiwidgethierarchyvisitor.h"
#include "qiqtincludefix.h"

QIWidgetHierarchyVisitor::~QIWidgetHierarchyVisitor()
{

}

void QIWidgetHierarchyVisitor::visit(const QWidget* widget)
{
    const QObjectList& children = widget->children();

    for (QObjectList::const_iterator it = children.begin(), endIt = children.end(); it != endIt; ++it)
    {
        if ((*it)->isWidgetType())
        {
            const QWidget* child = static_cast<const QWidget*>(*it);
            if (child->isVisible())
                visit(child);
        }
    }
}
