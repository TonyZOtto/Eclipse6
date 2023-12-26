#include "CommandLine.h"

#include "ExeSupport.h"

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
    Q_ASSERT_X(false, Q_FUNC_INFO, "MUSTDO process()");
    //  MUSTDO process()
}

void CommandLine::ctor()
{
    qDebug() << Q_FUNC_INFO << mFlags;
    setObjectName("CommandLine");
    mpOptionsSetupFunction = nullptr;
    mParser.setSingleDashWordOptionMode(QCommandLineParser::ParseAsCompactedShortOptions);
    mParser.setOptionsAfterPositionalArgumentsMode(QCommandLineParser::ParseAsOptions);
}


