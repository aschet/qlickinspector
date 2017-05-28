/**
 * Copyright 2017 Thomas Ascher <thomas.ascher@gmx.at>
 * SPDX-License-Identifier: LGPL-3.0+
 */

#ifndef QICOLORMAPPING_H
#define QICOLORMAPPING_H

#include "qlickinspector_global.h"
class QColor;

class QLICKINSPECTOR_EXPORT QIColorMapping
{
public:
    QIColorMapping();

    QIColorMapping(unsigned int maxCount);

    QColor map(unsigned int count) const;

private:
    unsigned int maxCount;
};

#endif
