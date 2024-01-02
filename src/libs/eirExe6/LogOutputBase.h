//!file {Eclipse6}/root/src/libs/eirExe6/LogOutputBase.h Base for sinking formatted log messages
#pragma once
#include "eirExe6.h"

#include <QObject>

class EIREXE_EXPORT LogOutputBase : public QObject
{
    Q_OBJECT
public:
    explicit LogOutputBase(QObject *parent = nullptr);

signals:
};
