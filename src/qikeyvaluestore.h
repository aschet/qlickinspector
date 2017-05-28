/**
 * Copyright 2017 Thomas Ascher <thomas.ascher@gmx.at>
 * SPDX-License-Identifier: LGPL-3.0+
 */

#ifndef QIKEYVALUESTORE_H
#define QIKEYVALUESTORE_H

#include "qlickinspector_global.h"
#include <QtCore/QString>
struct QIKeyValueStorePrivate;

class QLICKINSPECTOR_EXPORT QIKeyValueStore
{
public:
    QIKeyValueStore();

    ~QIKeyValueStore();

    bool open(const QString& path = QString());

    bool set(const QString& key, const QString& value);

    QString get(const QString& key, bool* exists = nullptr) const;

    void close();

private:
    QIKeyValueStore(const QIKeyValueStore&);

    QIKeyValueStorePrivate* p;
};

#endif
