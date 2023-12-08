//!file {Eclipse6}/root/src/libs/eirExe6/CommandLine.h Parses Command Line for ExeSupport
#pragma once
#include "eirExe6.h"

#include <QObject>

class ExeSupport;

class EIREXE_EXPORT CommandLine : public QObject
{
    Q_OBJECT
public:
    explicit CommandLine(ExeSupport *parent = nullptr);

signals:

private:
    ExeSupport * mpSupport=nullptr;
};
