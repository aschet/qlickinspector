/**
 * Copyright 2017 Thomas Ascher <thomas.ascher@gmx.at>
 * SPDX-License-Identifier: LGPL-3.0+
 */

#ifndef QSEVENTINTERCEPTOR_H
#define QSEVENTINTERCEPTOR_H

#include "qlickinspector_global.h"
#include <QtCore/QObject>
#include <memory>
class QIEventCounter;
class QObject;
class QEvent;

class QLICKINSPECTOR_EXPORT QIEventInterceptor : public QObject
{
    Q_OBJECT
public:
    QIEventInterceptor(std::shared_ptr<QIEventCounter> counterRef);

    ~QIEventInterceptor();

    void setEnabled(bool enabled);

    bool isEnabled() const;

    void setHotKeyEnabled(bool enabled);

    bool isHotKeyEnabled() const;

    virtual bool eventFilter(QObject* watched, QEvent* event) override;

private slots:
    void handleHotKey();

private:
    std::shared_ptr<QIEventCounter> counter;

    bool enabled;

    bool hotKeyEnabled;
};

#endif
