#pragma once

#include <QtCore/qglobal.h>

#if defined(EIRCORE6_LIBRARY)
#  define EIRCORE6_EXPORT Q_DECL_EXPORT
#else
#  define EIRCORE6_EXPORT Q_DECL_IMPORT
#endif
