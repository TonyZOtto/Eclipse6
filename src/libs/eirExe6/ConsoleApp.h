//!file {Eclipse6}/root/src/libs/eirExe6/ConsoleApp.h Console Application based on ExeSupport
#pragma once
#include "eirExe6.h"

#include <QObject>

class EIREXE_EXPORT ConsoleApp : public QObject
{
    Q_OBJECT
public:
    explicit ConsoleApp(QObject *parent = nullptr);

signals:
};
