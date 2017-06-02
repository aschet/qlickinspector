/**
 * Copyright 2017 Thomas Ascher <thomas.ascher@gmx.at>
 * SPDX-License-Identifier: LGPL-3.0+
 */

#include "qieventinterceptor.h"
#include "qieventcounter.h"
#include "qiheatmaprenderer.h"
#include <QtCore/QEvent>
#include <QtCore/QTimer>
#include <QtGui/QKeyEvent>
#include "qiqtincludefix.h"

using namespace std;

QIEventInterceptor::QIEventInterceptor(shared_ptr<QIEventCounter> counterRef)
    :counter(counterRef)
    ,enabled(false)
    ,hotKeyEnabled(false)
{

}

QIEventInterceptor::~QIEventInterceptor()
{

}

void QIEventInterceptor::setEnabled(bool enabled)
{
    this->enabled = enabled;
}

bool QIEventInterceptor::isEnabled() const
{
    return enabled;
}

void QIEventInterceptor::setHotKeyEnabled(bool enabled)
{
    hotKeyEnabled = enabled;
}

bool QIEventInterceptor::isHotKeyEnabled() const
{
    return hotKeyEnabled;
}

bool QIEventInterceptor::eventFilter(QObject* watched, QEvent* event)
{
    if (!watched->isWidgetType())
        return false;

    if (hotKeyEnabled && event->type() == QEvent::KeyPress)
    {
        if (static_cast<QKeyEvent*>(event)->key() == Qt::Key_F12)
        {
            QTimer::singleShot(0, this, SLOT(handleHotKey()));
            return true;
        }

        return false;
    }

    if (enabled && event->spontaneous() && event->type() == QEvent::MouseButtonPress)
    {
        counter->increment(static_cast<QWidget*>(watched));
    }

    return false;
}

void QIEventInterceptor::handleHotKey()
{
    QWidget* activeWindow = qApp->activePopupWidget();
    if (!activeWindow)
        activeWindow = qApp->activeModalWidget();
    if (!activeWindow)
        activeWindow = qApp->activeWindow();

    if (!activeWindow)
        return;

    bool wasEnabled = isEnabled();

    QString heatmapPath = QFileDialog::getSaveFileName(activeWindow, tr("Save Heatmap"), QDir::homePath(), tr("PNG Images (*.png)"));
    if (!heatmapPath.isEmpty())
    {
        QPixmap heatmap = QIHeatmapRenderer(counter).render(activeWindow);
        if (!heatmap.isNull())
            heatmap.save(heatmapPath, "PNG");
    }

    setEnabled(wasEnabled);
}
