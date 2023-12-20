#include "EngineMainWindow.h"

#include <QLayout>
#include <QTimer>


EngineMainWindow::EngineMainWindow(QWidget *parent)
    : ConsoleAppMainWindow(parent)
{
    setObjectName("EngineMainWindow");
    showMaximized();
    QTimer::singleShot(200, this, &EngineMainWindow::setupUI);
}

EngineMainWindow::~EngineMainWindow() {;}

void EngineMainWindow::setupUI()
{
    setWindowTitle("INDIface6 Engine Manager");
    ConsoleAppMainWindow();
}
