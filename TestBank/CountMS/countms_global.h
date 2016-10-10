#ifndef COUNTMS_GLOBAL_H
#define COUNTMS_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(COUNTMS_LIBRARY)
#  define COUNTMSSHARED_EXPORT Q_DECL_EXPORT
#else
#  define COUNTMSSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // COUNTMS_GLOBAL_H
