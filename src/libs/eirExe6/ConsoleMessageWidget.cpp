#include "ConsoleMessageWidget.h"

ConsoleMessageWidget::ConsoleMessageWidget(const ConsoleMessage msg,
                                           QWidget *parent)
    : QWidget{parent}
    , cmMessage(msg)
{
    setObjectName("ConsoleMessageWidget");

}
