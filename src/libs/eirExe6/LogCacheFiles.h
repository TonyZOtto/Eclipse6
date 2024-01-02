//!file {Eclipse6}/root/src/libs/eirExe6/LogCacheFiles.h File-based log message cacheing
#pragma once
#include "eirExe6.h"

#include "LogCacheBase.h"

class EIREXE_EXPORT LogCacheFiles : public LogCacheBase
{
    Q_OBJECT
public:
    explicit LogCacheFiles(QObject *parent = nullptr);
};
