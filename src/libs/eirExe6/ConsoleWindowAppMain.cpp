#include "ConsoleWindowAppMain.h"

#include <QVBoxLayout>
#include <QTabBar>
#include <QStackedWidget>

ConsoleWindowAppMain::ConsoleWindowAppMain(QWidget *parent)
    : QMainWindow{parent}
    , mpVBoxLayout(new QVBoxLayout)
    , mpTabs(new QTabBar)
    , mpStack(new QStackedWidget)
{
    setObjectName("ConsoleWindowAppMain");
    Q_ASSERT_X(mpVBoxLayout, "ConsoleWindowAppMain", "Invalid mpVBoxLayout");
    Q_ASSERT_X(mpTabs, "ConsoleWindowAppMain", "Invalid mpTabs");
    Q_ASSERT_X(mpStack, "ConsoleWindowAppMain", "Invalid mpStack");
    mpVBoxLayout->setObjectName("ConsoleWindowAppMain:VBoxLayout");
    mpTabs->setObjectName("ConsoleWindowAppMain:TabBar");
    mpStack->setObjectName("ConsoleWindowAppMain:StackedWidget");
}

void ConsoleWindowAppMain::setupUI()
{
    Q_ASSERT_X(mpVBoxLayout, "ConsoleWindowAppMain::setupUI()", "Invalid mpVBoxLayout");
    Q_ASSERT_X(mpTabs, "ConsoleWindowAppMain::setupUI()", "Invalid mpTabs");
    Q_ASSERT_X(mpStack, "ConsoleWindowAppMain::setupUI()", "Invalid mpStack");
    mpVBoxLayout->addWidget(mpTabs);
    mpVBoxLayout->addWidget(mpStack);
    setLayout(mpVBoxLayout);
    connect(mpTabs, &QTabBar::currentChanged,
            this, &ConsoleWindowAppMain::tabChanged);
}

void ConsoleWindowAppMain::tabChanged()
{
    Q_ASSERT(!"MUSTDO");
}
