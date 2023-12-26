#include "CommandLine.h"

#include <QCoreApplication>

//#include "ExeSupport.h"

// --------------------- ctors ---------------------

CommandLine::CommandLine(QObject *parent)
    : QObject{parent}
    , mFlags($null)
{
    qDebug() << Q_FUNC_INFO;
    ctor();
}

CommandLine::CommandLine(const Flags f, QObject *parent)
    : QObject{parent}
    , mFlags(f)
{
    qDebug() << Q_FUNC_INFO << f;
    ctor();
}

// --------------------- public slots ---------------------

void CommandLine::setupOptions()
{
    qDebug() << Q_FUNC_INFO << mFlags;
    if ( ! mFlags.testFlag(NoHelp))
        mOptions.append(mParser.addHelpOption());
    if ( ! mFlags.testFlag(NoVersion))
        mOptions.append(mParser.addVersionOption());
    if (mpOptionsSetupFunction)
        (void)*(mpOptionsSetupFunction);
}

void CommandLine::preparse()
{
    qDebug() << Q_FUNC_INFO;
    Q_ASSERT_X(false, Q_FUNC_INFO, "MUSTDO preparse()");
    //  MUSTDO preparse()
}

void CommandLine::preparse(const QStringList argList)
{
    qDebug() << Q_FUNC_INFO;
    Q_ASSERT_X(false, Q_FUNC_INFO, "MUSTDO preparse(argList)");
    Q_UNUSED(argList);
    //  MUSTDO preparse(argList)
}

void CommandLine::process()
{
    qDebug() << Q_FUNC_INFO;
    if (mArguments.isEmpty())
        mArguments = QCoreApplication::arguments();
    mExeFileInfo = QFileInfo(mArguments.takeFirst());
    while ( ! mArguments.isEmpty())
        process(mArguments.takeFirst());
}

// --------------------- private ---------------------

void CommandLine::ctor()
{
    qDebug() << Q_FUNC_INFO << mFlags;
    setObjectName("CommandLine");
    mpOptionsSetupFunction = nullptr;
    mParser.setSingleDashWordOptionMode(QCommandLineParser::ParseAsCompactedShortOptions);
    mParser.setOptionsAfterPositionalArgumentsMode(QCommandLineParser::ParseAsOptions);
}

void CommandLine::process(const QString arg)
{
    qDebug() << Q_FUNC_INFO << arg;
    if (arg.isEmpty()) return;
    QChar tFirstChar = arg[0];
    QString tText = arg.mid(1);

    Q_ASSERT_X(false, Q_FUNC_INFO, "MUSTDO process()");
    //  MUSTDO process()
    Q_UNUSED(tFirstChar); Q_UNUSED(tText);
}


