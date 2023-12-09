#include "ConsoleWindowMainWidget.h"

ConsoleWindowMainWidget::ConsoleWindowMainWidget(QWidget *parent)
    : QWidget{parent}
    , mpVBoxLayout(new QVBoxLayout)
    , mpTabs(new QTabBar(this))
    , mpStack(new QStackedWidget(this))
{
    setObjectName("ConsoleWindowMainWidget");
    Q_ASSERT_X(mpVBoxLayout, "ConsoleWindowMainWidget", "Invalid mpVBoxLayout");
    Q_ASSERT_X(mpTabs, "ConsoleWindowMainWidget", "Invalid mpTabs");
    Q_ASSERT_X(mpStack, "ConsoleWindowMainWidget", "Invalid mpStack");
    mpVBoxLayout->setObjectName("ConsoleWindowMainWidget:VBoxLayout");
    mpTabs->setObjectName("ConsoleWindowMainWidget:TabBar");
    mpStack->setObjectName("ConsoleWindowMainWidget:StackedWidget");
}

void ConsoleWindowMainWidget::setupUI()
{
    Q_ASSERT_X(mpVBoxLayout, "ConsoleWindowMainWidget", "Invalid mpVBoxLayout");
    Q_ASSERT_X(mpTabs, "ConsoleWindowMainWidget", "Invalid mpTabs");
    Q_ASSERT_X(mpStack, "ConsoleWindowMainWidget", "Invalid mpStack");
    mpVBoxLayout->addWidget(mpTabs);
    mpVBoxLayout->addWidget(mpStack);
    setLayout(mpVBoxLayout);
    connect(mpTabs, &QTabBar::currentChanged,
            this, &ConsoleWindowMainWidget::tabChanged);
}

void ConsoleWindowMainWidget::tabChanged()
{
    Q_ASSERT(!"MUSTDO");
}
