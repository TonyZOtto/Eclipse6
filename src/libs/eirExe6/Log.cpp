#include "Log.h"

#include <QtLogging>
#include <QIODevice>
#include <QTextStream>

#include <cstdio>

Log::Log()
{
    qInstallMessageHandler(logMessageHandler);
}

void Log::logMessageHandler(QtMsgType qmt,
                            const QMessageLogContext &context,
                            const QString &message)
{
    QTextStream cerr(stderr, QIODevice::WriteOnly);
    cerr << "{" << message << "} QtMsgType = " << qMsgTypeName(qmt);
    cerr << "^< context: version = " << context.version
         << " line = " << context.line
         << " file = " << context.file
         << " function = " << context.function
         << " category = " << context.category;
    cerr << " >" << Qt::endl;
}

QString Log::qMsgTypeName(const QtMsgType qmt)
{
    QString result("*Unknown*");
    switch (qmt)
    {
    case QtDebugMsg:        result = "Debug:0";     break;
    case QtWarningMsg:      result = "Warning:1";   break;
    case QtCriticalMsg:     result = "Critical:2";  break;
    case QtFatalMsg:        result = "Fatal:3";     break;
    case QtInfoMsg:         result = "Info:4";      break;
    }
    return result;
}

