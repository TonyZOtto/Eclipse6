#include "ConsoleMessageDisplay.h"

ConsoleMessageDisplay::ConsoleMessageDisplay(QWidget *parent)
    : QWidget{parent}
    , mpLayout(new QVBoxLayout)
{
    setObjectName("ConsoleMessageDisplay");
    Q_ASSERT_X(mpLayout, "ConsoleMessageDisplay", "Invalid mpLayout");

}
