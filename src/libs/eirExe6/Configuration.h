#pragma once

#include <QSettings>

#include <Key.h>
#include <KeySeg.h>

class Configuration : public QSettings::SettingsMap
{
public:
    Configuration();
    Configuration(QSettings * set, const Key groupKey);

public:
    KeySeg title() const;
    Key group() const;
    QVariant operator [] (const Key key) const;

public:
//    QVariant & operator [] (const Key key);

private:
    QSettings * mpSettings=nullptr;
    Key mGroup;
};
