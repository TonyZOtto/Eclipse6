//!file {Eclipse6}/root/src/libs/eirExe6/Log.h Formatting log ,essages into text, meta-comtext, and icon
#pragma once
#include "eirExe6.h"

#include <QObject>
#include "LogFormatBase.h"

class EIREXE_EXPORT LogFormatContextual : public LogFormatBase
{
    Q_OBJECT
public:
    explicit LogFormatContextual(QObject *parent = nullptr);
};
