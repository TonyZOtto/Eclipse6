#include "Settings.h"


QMap<QString, QSettings::Format> Settings::smExtFormatMap;

Settings::Settings(const QString name, QObject *parent)
    : mpParent(parent)
    , mName(name)
{
    qInfo() << Q_FUNC_INFO << name;
    if (smExtFormatMap.isEmpty())
        smExtFormatMap.insert("ini", QSettings::IniFormat);
    ctor();
}

QSettings::Format Settings::registerFormat(const QString &ext,
            QSettings::ReadFunc rf, QSettings::WriteFunc wf,
            Qt::CaseSensitivity cs)
{
    qInfo() << Q_FUNC_INFO << ext;
    QSettings::Format tFormat = QSettings::registerFormat(ext, rf, wf, cs);
    if (QSettings::InvalidFormat != tFormat)
        smExtFormatMap.insert(ext.toLower(), tFormat);
    return tFormat;
}

void Settings::ctor()
{
    qInfo() << Q_FUNC_INFO << mName;

    if (mName.startsWith("HKEY_")) return ctor(mName);

    QFileInfo tFI(mName);
    if (tFI.exists()) return ctor(tFI);

    QString tOrgName, tAppName;
    QStringList tSplit = mName.split('/');
    if (tSplit.count() >= 2)
    {
        tOrgName = tSplit[0].isEmpty()
                       ? QCoreApplication::organizationName()
                       : tSplit[0];
        tAppName = tSplit[1].isEmpty()
                       ? QCoreApplication::applicationName()
                       : tSplit[1];
        return ctor(tOrgName, tAppName);
    }
    else
    {
        tOrgName = QCoreApplication::organizationName();
        tAppName = tSplit[0];
        return ctor(tOrgName, tAppName);
    }

}

void Settings::ctor(const QFileInfo fi)
{
    qInfo() << Q_FUNC_INFO << fi;
    QString tExt = fi.suffix().toLower();
    QSettings::Format tFormat = QSettings::InvalidFormat;
    if (smExtFormatMap.contains(tExt))
        tFormat = smExtFormatMap.value(tExt);
    if (QSettings::InvalidFormat != tFormat)
    {
        mpSettings = new QSettings(fi.filePath(), tFormat, mpParent);
        Q_ASSERT_X(mpSettings, Q_FUNC_INFO, "QSettings");
        mpSettings->setObjectName("Settings:"+fi.fileName());
    }
}

#ifdef Q_OS_WINDOWS
void Settings::ctor(const QString &regHive)
{
    qInfo() << Q_FUNC_INFO << regHive;
    mpSettings = new QSettings(regHive, QSettings::NativeFormat, mpParent);
    Q_ASSERT_X(mpSettings, Q_FUNC_INFO, "QSettings");
    mpSettings->setObjectName("Settings:" + regHive);
}
#endif

void Settings::ctor(const QString &orgName, const QString &appName)
{
    qInfo() << Q_FUNC_INFO << orgName << appName;
    mpSettings = new QSettings(orgName, appName, mpParent);
    Q_ASSERT_X(mpSettings, Q_FUNC_INFO, "QSettings");
    mpSettings->setObjectName("Settings:" + orgName + "/" + appName);
}
