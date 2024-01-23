//!file {Eclipse6}/root/src/libs/eirExe6/LogCacheBase.h Base for Log Message Cacheing
#pragma once
#include "eirExe6.h"

#include <QObject>

class EIREXE_EXPORT LogCacheBase : public QObject
{
    Q_OBJECT
public:
    explicit LogCacheBase(QObject *parent = nullptr);

signals:
};
