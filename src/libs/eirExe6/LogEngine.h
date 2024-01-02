//!file {Eclipse6}/root/src/libs/eirExe6/LogEngine.h The engine for handling log messages
#pragma once
#include "eirExe6.h"

#include <QObject>

#include <Message.h>

#include "Log.h"
class LogMessageQueue;

class EIREXE_EXPORT LogEngine : public QObject
{
    Q_OBJECT
public:
    explicit LogEngine(QObject *parent = nullptr);

public: // non-const
    void add(Message msg, QObject *sender=nullptr);

signals:

private:
    Log mLog;
    LogMessageQueue * mpInputQueue=nullptr;
};
