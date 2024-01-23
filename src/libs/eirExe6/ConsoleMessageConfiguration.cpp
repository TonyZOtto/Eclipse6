#include "ConsoleMessageConfiguration.h"

ConsoleMessageConfiguration::ConsoleMessageConfiguration()
    : Configuration(new QSettings(), "ConsoleMessage")
{
    setDefaults();
}

void ConsoleMessageConfiguration::setDefaults()
{
    mIconSize = QSize(32, 32);
    mContextFont = QFont("Typewriter", 9);
    mMessageFont = QFont("Helvetica", 12);
}
