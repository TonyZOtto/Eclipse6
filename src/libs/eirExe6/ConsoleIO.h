//!file {Eclipse6}/root/src/libs/eirExe6/ConsoleIO.h Handle cstdio streams for ConsoleApp
#pragma once
#include "eirExe6.h"

#include <QObject>

class EIREXE_EXPORT ConsoleIO : public QObject
{
    Q_OBJECT
public:
    explicit ConsoleIO(QObject *parent = nullptr);

signals:
};
