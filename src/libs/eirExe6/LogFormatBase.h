//!file {Eclipse6}/root/src/libs/eirExe6/LogFormatBase.h Base for formatting log messages
#pragma once
#include "eirExe6.h"

#include <QObject>

class EIREXE_EXPORT LogFormatBase : public QObject
{
    Q_OBJECT
public:
    explicit LogFormatBase(QObject *parent = nullptr);

signals:
};
