#include "ConsoleWindowAppMain.h"


ConsoleWindowAppMain::ConsoleWindowAppMain(QWidget *parent)
    : QMainWindow{parent}
    , mpVBoxLayout(new QVBoxLayout)
    , mpTabs(new QTabBar)
    , mpStack(new QStackedWidget)
{
    if (layout()) qDebug() << Q_FUNC_INFO << layout()->objectName();
    setObjectName("ConsoleWindowAppMain");
    Q_ASSERT_X(mpVBoxLayout, "ConsoleWindowAppMain", "Invalid mpVBoxLayout");
    Q_ASSERT_X(mpTabs, "ConsoleWindowAppMain", "Invalid mpTabs");
    Q_ASSERT_X(mpStack, "ConsoleWindowAppMain", "Invalid mpStack");
    mpVBoxLayout->setObjectName("ConsoleWindowAppMain:VBoxLayout");
    mpTabs->setObjectName("ConsoleWindowAppMain:TabBar");
    mpStack->setObjectName("ConsoleWindowAppMain:StackedWidget");
    if (layout()) qDebug() << Q_FUNC_INFO << layout()->objectName();
}

void ConsoleWindowAppMain::setupUI()
{
    if (layout()) qDebug() << Q_FUNC_INFO << layout()->objectName();
    Q_ASSERT_X(mpVBoxLayout, "ConsoleWindowAppMain::setupUI()", "Invalid mpVBoxLayout");
    Q_ASSERT_X(mpTabs, "ConsoleWindowAppMain::setupUI()", "Invalid mpTabs");
    Q_ASSERT_X(mpStack, "ConsoleWindowAppMain::setupUI()", "Invalid mpStack");
    mpVBoxLayout->addWidget(mpTabs);
    mpVBoxLayout->addWidget(mpStack);
    if (layout()) qDebug() << Q_FUNC_INFO << layout()->objectName();
    if (layout())
    {
        delete layout();
        setLayout(nullptr);
    }
    Q_ASSERT(nullptr == layout());
    setLayout(mpVBoxLayout);
    if (layout())
        qDebug() << Q_FUNC_INFO << layout()->objectName();
    else
        qDebug() << Q_FUNC_INFO << "layout() is null";
    connect(mpTabs, &QTabBar::currentChanged,
            this, &ConsoleWindowAppMain::tabChanged);
}

void ConsoleWindowAppMain::tabChanged()
{
    if (layout()) qDebug() << Q_FUNC_INFO << layout()->objectName();
    Q_ASSERT(!"MUSTDO");
}
