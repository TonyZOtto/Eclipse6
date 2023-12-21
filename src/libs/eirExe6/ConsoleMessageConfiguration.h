#pragma once

#include "Configuration.h"

#include <QFont>
#include <QSize>

class ConsoleMessageConfiguration : public Configuration
{
public:
    ConsoleMessageConfiguration();

public:
    QSize iconSize() const { return mIconSize; }
    QFont contextFont() const { return mContextFont; }
    QFont messageFont() const { return mMessageFont; }

private:
    void setDefaults();

private:
    QSize mIconSize;
    QFont mContextFont;
    QFont mMessageFont;
};
