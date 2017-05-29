/**
 * Copyright 2017 Thomas Ascher <thomas.ascher@gmx.at>
 * SPDX-License-Identifier: LGPL-3.0+
 */

#include "qlickinspector.h"
#include "qikeyvaluestore.h"
#include "qieventcounter.h"
#include "qieventinterceptor.h"
#include "qiheatmaprenderer.h"
#include "qiqtincludefix.h"
#include <QtGui/QImage>
#include <QtGui/QDesktopServices>
#include <memory>

class QlickInspectorPrivate
{
public:
    QlickInspectorPrivate(QApplication* app, const QString& eventLogPath = QString())
    {
        std::shared_ptr<QIKeyValueStore> store = std::make_shared<QIKeyValueStore>();
        if (!store->open(eventLogPath))
        {
            qWarning("Unable to open or create event log. Data will only be logged to memory.");
            store->open();
        }

        counter = std::make_shared<QIEventCounter>(store);
        interceptor.reset(new QIEventInterceptor(counter));
        app->installEventFilter(interceptor.get());
    }

    std::shared_ptr<QIEventCounter> counter;

    std::unique_ptr<QIEventInterceptor> interceptor;
};

QlickInspector::QlickInspector(QApplication* app)
{
    p = new QlickInspectorPrivate(app);
}

QlickInspector::QlickInspector(QApplication* app, const QString& eventLogPath)
{
    p = new QlickInspectorPrivate(app, eventLogPath);
}

QlickInspector::~QlickInspector()
{
    delete p;
}

void QlickInspector::setEnabled(bool enabled)
{
    p->interceptor->setEnabled(enabled);
}

bool QlickInspector::isEnabled() const
{
    return p->interceptor->isEnabled();
}

void QlickInspector::setHotKeyEnabled(bool enabled)
{
    p->interceptor->setHotKeyEnabled(enabled);
}

bool QlickInspector::isHotKeyEnabled() const
{
    return p->interceptor->isHotKeyEnabled();
}

QImage QlickInspector::renderHeatmap(QWidget* widget)
{
    if (!widget)
    {
        return QImage();
    }

    return QIHeatmapRenderer(p->counter).render(widget).toImage();
}

QlickInspector::QlickInspector(const QlickInspector&)
{

}
