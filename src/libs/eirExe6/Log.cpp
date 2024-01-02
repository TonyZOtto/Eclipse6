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
    cerr << "{" << message << "} QtMsgType = " << qmt;
    cerr << "^< context: version = " << context.version
         << " line = " << context.line
         << " file = " << context.file
         << " function = " << context.function
         << " category = " << context.category;
    cerr << " >" << Qt::endl;
}

