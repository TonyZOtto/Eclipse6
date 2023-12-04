//!file {Eclipse6}/root/src/libs/eirExe6/ExeSupport.h Basic Executable (.exe or .dll) Support Class
#pragma once
#include "eirExe6.h"

#include <QObject>

class EIREXE_EXPORT ExeSupport : public QObject
{
    Q_OBJECT
public:
    explicit ExeSupport(QObject *parent = nullptr);

signals:
};
