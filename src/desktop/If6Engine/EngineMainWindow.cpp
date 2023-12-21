#include "EngineMainWindow.h"

#include <QLayout>
#include <QTimer>


EngineMainWindow::EngineMainWindow(QWidget *parent)
    : ConsoleAppMainWindow(parent)
{
    qDebug() << Q_FUNC_INFO;
    setObjectName("EngineMainWindow");
    QTimer::singleShot(200, this, &EngineMainWindow::initialize);
}

EngineMainWindow::~EngineMainWindow() {;}

void EngineMainWindow::initialize()
{
    qDebug() << Q_FUNC_INFO;
    ConsoleAppMainWindow::initialize();
    QTimer::singleShot(200, this, &EngineMainWindow::setup);

}

void EngineMainWindow::setup()
{
    qDebug() << Q_FUNC_INFO;
    showMaximized();
    setWindowTitle("INDIface6 Engine Manager");
    ConsoleAppMainWindow::setup();
    QTimer::singleShot(200, this, &EngineMainWindow::start);
}

void EngineMainWindow::start()
{
    qDebug() << Q_FUNC_INFO;
    ConsoleAppMainWindow::start();

}
