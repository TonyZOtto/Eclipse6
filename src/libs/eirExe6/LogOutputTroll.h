//!file {Eclipse6}/root/src/libs/eirExe6/LogOutputTroll.h Log message output to QtDebug
#pragma once
#include "eirExe6.h"

#include <QObject>
#include "LogOutputBase.h"

class EIREXE_EXPORT LogOutputTroll : public LogOutputBase
{
    Q_OBJECT
public:
    explicit LogOutputTroll(QObject *parent = nullptr);
};
