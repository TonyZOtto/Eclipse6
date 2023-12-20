#include "ConsoleAppMainWindow.h"

#include "ConsoleStreamDisplay.h"

ConsoleAppMainWindow::ConsoleAppMainWindow(QWidget *parent)
    : QMainWindow{parent}
    , mpMainWidget(new QWidget)
    , mpMainLayout(new QBoxLayout(QBoxLayout::TopToBottom))
    , mpStreamTabs(new QTabBar)
    , mpStreamStack(new QStackedWidget)
    , mpEngineDisplay(new ConsoleStreamDisplay("Engine", this))
{
    setObjectName("ConsoleWindowAppMain");
    Q_ASSERT_X(mpMainWidget, Q_FUNC_INFO, "Invalid mpMainWidget");
    Q_ASSERT_X(mpMainLayout, Q_FUNC_INFO, "Invalid mpMainLayout");
    Q_ASSERT_X(mpStreamTabs, Q_FUNC_INFO, "Invalid mpStreamTabs");
    Q_ASSERT_X(mpStreamStack, Q_FUNC_INFO, "Invalid mpStreamStack");
    Q_ASSERT_X(mpEngineDisplay, Q_FUNC_INFO, "Invalid mpEngineDisplay");
    mpMainLayout->setObjectName("ConsoleWindowAppMain:QBoxLayout");
    mpStreamTabs->setObjectName("ConsoleWindowAppMain:TabBar");
    mpStreamStack->setObjectName("ConsoleWindowAppMain:StackedWidget");
}

void ConsoleAppMainWindow::initialize()
{
    Q_ASSERT_X(mpEngineDisplay, Q_FUNC_INFO, "Invalid mpEngineDisplay");
    mpEngineDisplay->initialize();
}

void ConsoleAppMainWindow::setup()
{
    Q_ASSERT_X(mpMainWidget, Q_FUNC_INFO, "Invalid mpMainWidget");
    Q_ASSERT_X(mpMainLayout, Q_FUNC_INFO, "Invalid mpMainLayout");
    Q_ASSERT_X(mpStreamTabs, Q_FUNC_INFO, "Invalid mpStreamTabs");
    Q_ASSERT_X(mpStreamStack, Q_FUNC_INFO, "Invalid mpStreamStack");
    mpMainLayout->addWidget(mpStreamTabs);
    mpMainLayout->addWidget(mpStreamStack);
    mpMainWidget->setLayout(mpMainLayout);
    setCentralWidget(mpMainWidget);
    connect(mpStreamTabs, &QTabBar::currentChanged,
            this, &ConsoleAppMainWindow::streamTabChanged);
    mpEngineDisplay->setup();
    mpMainWidget->show();
}

void ConsoleAppMainWindow::start()
{
    Q_ASSERT_X(mpEngineDisplay, Q_FUNC_INFO, "Invalid mpEngineDisplay");
    mpEngineDisplay->start();
    addDisplay(mpEngineDisplay);
}

void ConsoleAppMainWindow::addDisplay(ConsoleStreamDisplay *pcsd)
{
    Q_ASSERT_X(pcsd, Q_FUNC_INFO, "Invalid ConsoleStreamDisplay");
    Q_ASSERT_X(mpStreamTabs, Q_FUNC_INFO, "Invalid mpStreamTabs");
    Q_ASSERT_X(mpStreamStack, Q_FUNC_INFO, "Invalid mpStreamStack");
    const QString cTitle = pcsd->title();
    mpStreamTabs->addTab(cTitle);
    mpStreamStack->addWidget(pcsd);
}

void ConsoleAppMainWindow::streamTabChanged()
{
    Q_ASSERT(!"MUSTDO");
}
