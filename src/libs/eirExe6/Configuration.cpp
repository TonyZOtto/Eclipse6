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
    Q_ASSERT_X(mpSettings, Q_FUNC_INFO, "QSettings *");
    return mpSettings->value(key());
}
