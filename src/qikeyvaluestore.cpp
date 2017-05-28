/**
 * Copyright 2017 Thomas Ascher <thomas.ascher@gmx.at>
 * SPDX-License-Identifier: LGPL-3.0+
 */

#include "qikeyvaluestore.h"
#include <memory>
#include <QtCore/QString>
#include <QtCore/QByteArray>

extern "C" {
#include "unqlite.h"
}

struct QIKeyValueStorePrivate
{
    QIKeyValueStorePrivate()
    {
        db = nullptr;
    }

    QByteArray encode(const QString& str)
    {
        return str.toUtf8();
    }

    unqlite *db;
};

QIKeyValueStore::QIKeyValueStore()
{
    p = new QIKeyValueStorePrivate();
}

QIKeyValueStore::~QIKeyValueStore()
{
    close();
    delete p;
}

bool QIKeyValueStore::open(const QString &path)
{   
    close();

    QString actualPath = (path.isEmpty()) ? ":mem:" : path;

    int result = unqlite_open(&p->db, p->encode(actualPath), UNQLITE_OPEN_CREATE);
    return result == UNQLITE_OK;
}

bool QIKeyValueStore::set(const QString& key, const QString& value)
{
    QByteArray encodedKey = p->encode(key);
    QByteArray encodedValue = p->encode(value);
    int result = unqlite_kv_store(p->db, encodedKey.data(), -1, encodedValue.data(), encodedValue.size());
    if (result == UNQLITE_OK)
    {
        unqlite_commit(p->db);
    }
    return result == UNQLITE_OK;
}

QString QIKeyValueStore::get(const QString& key, bool* exists) const
{
    bool existsStore;
    if (exists == nullptr)
        exists = &existsStore;

    *exists = false;
    unqlite_int64 dataSize = 0;

    QByteArray encodedKey = p->encode(key);
    int result = unqlite_kv_fetch(p->db, encodedKey.data(), -1, nullptr, &dataSize);
    if (result != UNQLITE_OK)
        return QString();

    std::unique_ptr<char[]> value(new char[dataSize + 1]);
    memset(value.get(), 0, sizeof(char) * (dataSize + 1));

    result = unqlite_kv_fetch(p->db, encodedKey.data(), -1, value.get(), &dataSize);
    if (result != UNQLITE_OK)
        return QString();

    *exists = true;
    return QString::fromUtf8(value.get());
}

void QIKeyValueStore::close()
{
    if (p->db)
    {
        unqlite_close(p->db);
        p->db = nullptr;
    }
}

QIKeyValueStore::QIKeyValueStore(const QIKeyValueStore&)
{

}
