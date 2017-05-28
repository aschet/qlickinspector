/**
 * Copyright 2017 Thomas Ascher <thomas.ascher@gmx.at>
 * SPDX-License-Identifier: LGPL-3.0+
 */

#ifndef QLICKINSPECTOR_GLOBAL_H
#define QLICKINSPECTOR_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QLICKINSPECTOR_LIBRARY)
#  define QLICKINSPECTOR_EXPORT Q_DECL_EXPORT
#else
#  define QLICKINSPECTOR_EXPORT Q_DECL_IMPORT
#endif

#endif
