//!file {Eclipse6}/root/src/libs/eirExe6/Settings.h Wraps QSettings
#pragma once
#include "eirExe6.h"

#include <QObject>

#include <QFileInfo>
#include <QString>
#include <QSettings>

class EIREXE_EXPORT Settings : public QObject
{
    Q_OBJECT
public:
    explicit Settings(const QString name, QObject *parent=nullptr);

public:
    bool isValid() const { return nullptr != mpSettings; }

public: // static
    static QSettings::Format registerFormat(const QString &ext,
                       QSettings::ReadFunc rf,
                       QSettings::WriteFunc wf,
                       Qt::CaseSensitivity cs=Qt::CaseSensitive);

private:
    void ctor();
    void ctor(const QFileInfo fi);
#ifdef Q_OS_WINDOWS
    void ctor(const QString &regHive);
#endif
    void ctor(const QString &orgName, const QString &appName);

private:
    QObject * mpParent=nullptr;
    QSettings * mpSettings=nullptr;
    QString mName;
    static QMap<QString, QSettings::Format> smExtFormatMap;
};
