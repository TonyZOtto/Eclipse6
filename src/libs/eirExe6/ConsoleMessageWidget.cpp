#include "ConsoleMessageWidget.h"

#include <QLabel>
#include <QPixmap>

#include "ConsoleStreamDisplay.h"

ConsoleMessageWidget::ConsoleMessageWidget(const ConsoleMessage msg,
                                           ConsoleStreamDisplay *parent)
    : QWidget{parent}
    , mpDisplay(parent)
    , cmMessage(msg)
    , mpLayout(new QGridLayout)
{
    qDebug() << Q_FUNC_INFO;
    Q_ASSERT_X(mpLayout, Q_FUNC_INFO, "Invalid QGridLayout");
    setObjectName("ConsoleMessageWidget:"+display()->title());
    setup();
}

ConsoleMessageConfiguration ConsoleMessageWidget::config()
{
    return display()->config();
}

void ConsoleMessageWidget::setup()
{
    qDebug() << Q_FUNC_INFO;
    Q_ASSERT_X(mpLayout, Q_FUNC_INFO, "Invalid QGridLayout");
    QPixmap tIconPixmap = cmMessage.iconPixmap(config()["IconSize"].toSize());
    QLabel * pContextLabel = new QLabel(this);
    setLayout(mpLayout);
}
