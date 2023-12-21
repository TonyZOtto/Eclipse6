#include "ConsoleMessageWidget.h"

ConsoleMessageWidget::ConsoleMessageWidget(const ConsoleMessage msg,
                                           QWidget *parent)
    : QWidget{parent}
    , cmMessage(msg)
    , mIcon(msg.icon())
    , mpLayout(new QGridLayout)
{
    setObjectName("ConsoleMessageWidget");
    setup();
}

void ConsoleMessageWidget::setup()
{
    qDebug() << Q_FUNC_INFO;
    Q_ASSERT_X(mpLayout, Q_FUNC_INFO, "Invalid QGridLayout");

    setLayout(mpLayout);
}
