#pragma once

#include <QSettings>

class Configuration : public QSettings::SettingsMap
{
public:
    Configuration();
    Configuration(QSettings * set, const QString group);

private:
    QSettings * mpSettings=nullptr;
};
