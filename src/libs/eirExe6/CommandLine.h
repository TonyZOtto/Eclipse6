//!file {Eclipse6}/root/src/libs/eirExe6/CommandLine.h Parses Command Line for ExeSupport
#pragma once
#include "eirExe6.h"

#include <QObject>

#include <QCommandLineOption>
#include <QCommandLineParser>
#include <QFileInfo>
#include <QFileInfoList>
#include <QSettings>
#include <QString>
#include <QStringList>

#include <Types.h>

class EIREXE_EXPORT CommandLine : public QObject
{
    Q_OBJECT
public:
    enum Flag
    {
        $null           = 0,
        NoHelp          = 0x00000001,
        NoVersion       = 0x00000002,
    };
    Q_DECLARE_FLAGS(Flags, Flag)
    Q_FLAG(Flags)

public:
    CommandLine(QObject *parent);
    CommandLine(const Flags f, QObject *parent = nullptr);

public: // const
    QStringList optionNames() const;
    bool isSet(const QString &optName) const;
    QString value(const QString &optionName) const;
    QStringList values(const QString &optionName) const;
    QFileInfo exeFileInfo() const;
    QStringList positionalArguments() const;
    Count positionalArgumentCount() const;
    QString positionalArgument(const Index ix) const;
    QFileInfo positionalFileInfo(const Index ix) const;
    Count dynamicSettingCount() const;
    QSettings * dynamicSetting(const Index ix) const;
    QSettings::SettingsMap configValues() const;

public: // non-const
    void addOption(const QCommandLineOption &opt);
    void setSetupFunction(void * pFn);

public slots:
    void setupOptions();
    void preparse();
    void preparse(const QStringList argList);
    void process();

private:
    void ctor();

signals: // TODO define signals

private:
    Flags mFlags;
    void(*mpOptionsSetupFunction)();
    QCommandLineParser mParser;
    QStringList mArguments;
    QFileInfo mExeFileInfo;
    QList<QCommandLineOption> mOptions;
    QStringList mPositionalArguments;
    QFileInfoList mPositionalFileInfos;
    QList<QSettings *> mDynamicSettings;
    QSettings::SettingsMap mConfigValues;
};

Q_DECLARE_OPERATORS_FOR_FLAGS(CommandLine::Flags)

