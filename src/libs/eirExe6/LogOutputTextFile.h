//!file {Eclipse6}/root/src/libs/eirExe6/LogOutputTextFile.h Log message output to a text file
#pragma once
#include "eirExe6.h"

#include <QObject>
#include "LogOutputBase.h"

class EIREXE_EXPORT LogOutputTextFile : public LogOutputBase
{
    Q_OBJECT
public:
    explicit LogOutputTextFile(QObject *parent = nullptr);
};
