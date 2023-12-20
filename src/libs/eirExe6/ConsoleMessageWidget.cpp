#include "ConsoleMessageWidget.h"

ConsoleMessageWidget::ConsoleMessageWidget(const ConsoleMessage msg,
                                           QWidget *parent)
    : QWidget{parent}
    , cmMessage(msg)
    , mIcon(msg.icon())
    , mpLayout(new QHBoxLayout)
{
    setObjectName("ConsoleMessageWidget");
    setup();
}

void ConsoleMessageWidget::setup()
{
    Q_ASSERT_X(mpLayout, Q_FUNC_INFO, "Invalid mpEngineDisplay");

    setLayout(mpLayout);
}
