/**
 * Copyright 2017 Thomas Ascher <thomas.ascher@gmx.at>
 * SPDX-License-Identifier: LGPL-3.0+
 */

#ifndef QIEVENTCOUNTER_H
#define QIEVENTCOUNTER_H

#include "qlickinspector_global.h"
#include <memory>
class QWidget;
class QIKeyValueStore;

class QLICKINSPECTOR_EXPORT QIEventCounter
{
public:
    QIEventCounter(std::shared_ptr<QIKeyValueStore> storeRef);

    ~QIEventCounter();

    void increment(QWidget* widget);

    void increment(const QString& id);

    unsigned int get(QWidget* widget) const;

    unsigned int get(const QString& id) const;

private:
    std::shared_ptr<QIKeyValueStore> store;
};

#endif
