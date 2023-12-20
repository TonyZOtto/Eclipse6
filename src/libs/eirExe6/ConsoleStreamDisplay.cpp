#include "ConsoleStreamDisplay.h"

#include "ConsoleMessage.h"
#include "ConsoleMessageWidget.h"

ConsoleStreamDisplay::ConsoleStreamDisplay(const QString s, QWidget *parent)
    : QWidget{parent}
    , mTitle(s)
    , mpLayout(new QBoxLayout(QBoxLayout::TopToBottom))
{
    setObjectName("ConsoleMessageDisplay:"+title());
    Q_ASSERT_X(mpLayout, "ConsoleMessageDisplay", "Invalid mpLayout");
    mpLayout->setObjectName("ConsoleMessageDisplay:QBoxLayout");
}

void ConsoleStreamDisplay::initialize()
{
    Q_ASSERT_X(mpLayout, "ConsoleMessageDisplay", "Invalid mpLayout");

}

void ConsoleStreamDisplay::addMessage(const ConsoleMessage &msg)
{
    Q_ASSERT_X(mpLayout, "ConsoleMessageDisplay", "Invalid mpLayout");
    ConsoleMessageWidget * pMsgWidget = new ConsoleMessageWidget(msg, this);
    Q_UNUSED(pMsgWidget); // NEEDDO show it
    mMessageWidgetList.append(pMsgWidget);
}

void ConsoleStreamDisplay::setup()
{
    Q_ASSERT_X(mpLayout, Q_FUNC_INFO, "Invalid mpLayout");
    setLayout(mpLayout);
}

void ConsoleStreamDisplay::start()
{

}
