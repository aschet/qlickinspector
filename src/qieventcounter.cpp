/**
 * Copyright 2017 Thomas Ascher <thomas.ascher@gmx.at>
 * SPDX-License-Identifier: LGPL-3.0+
 */

#include "qieventcounter.h"
#include "qikeyvaluestore.h"
#include "qiwidgetidgenerator.h"
#include <QtCore/QString>

using namespace std;

QIEventCounter::QIEventCounter(shared_ptr<QIKeyValueStore> storeRef)
    :store(storeRef)
{

}

QIEventCounter::~QIEventCounter()
{

}

void QIEventCounter::increment(const QWidget* widget)
{
    increment(QIWidgetIDGenerator::generate(widget));
}

void QIEventCounter::increment(const QString& id)
{
    store->set(id, QString::number(get(id) + 1));
}

unsigned int QIEventCounter::get(const QWidget* widget) const
{
    return get(QIWidgetIDGenerator::generate(widget));
}

unsigned int QIEventCounter::get(const QString& id) const
{
    QString count = store->get(id);
    return count.toUInt();
}
