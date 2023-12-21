#include "Configuration.h"

Configuration::Configuration() {}

Configuration::Configuration(QSettings *set, const Key groupKey)
    : mpSettings(set)
    , mGroup(groupKey)
{
    ;
}

QVariant Configuration::operator [](const Key key) const
{
    return mpSettings[key()];
}

QVariant &Configuration::operator [](const Key key)
{
    return mpSettings[key()];
}
