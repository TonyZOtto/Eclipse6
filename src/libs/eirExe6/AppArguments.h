//!file {Eclipse6}/root/src/libs/eirBase6/AppArguments.h Manage Application Arguments for ExeSupport
#pragma once
#include "eirExe6.h"

#include <QObject>

class ExeSupport;

class EIREXE_EXPORT AppArguments : public QObject
{
    Q_OBJECT
public:
    explicit AppArguments(ExeSupport *parent = nullptr);

signals:

private:
    ExeSupport * mpSupport=nullptr;
};
