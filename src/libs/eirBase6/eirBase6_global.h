#ifndef EIRBASE6_GLOBAL_H
#define EIRBASE6_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(EIRBASE6_LIBRARY)
#  define EIRBASE6_EXPORT Q_DECL_EXPORT
#else
#  define EIRBASE6_EXPORT Q_DECL_IMPORT
#endif

#endif // EIRBASE6_GLOBAL_H
