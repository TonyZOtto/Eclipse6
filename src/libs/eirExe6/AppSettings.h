//!file {Eclipse6}/root/src/libs/eirExe6/AppSettings.h Manage Application Setting Values
#pragma once
#include "eirExe6.h"

#include <QObject>

class EIREXE_EXPORT AppSettings : public QObject
{
    Q_OBJECT
public:
    explicit AppSettings(QObject *parent = nullptr);

signals:
};
