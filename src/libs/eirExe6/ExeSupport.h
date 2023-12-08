//!file {Eclipse6}/root/src/libs/eirExe6/ExeSupport.h Basic Executable (.exe or .dll) Support Class
#pragma once
#include "eirExe6.h"

#include <QObject>

class AppArguments;
class AppSettings;
class CommandLine;


class EIREXE_EXPORT ExeSupport : public QObject
{
    Q_OBJECT
public:
    explicit ExeSupport(QObject *parent = nullptr);

signals:

private:
    AppArguments * mpArguments=nullptr;
    AppSettings * mpSettings=nullptr;
    CommandLine * mpCommandLine=nullptr;
};
