#include "EngineMainWindow.h"

#include <QTimer>


EngineMainWindow::EngineMainWindow(QWidget *parent)
    : ConsoleWindowAppMain(parent)
{
    setObjectName("EngineMainWindow");
    showMaximized();
    QTimer::singleShot(200, this, &EngineMainWindow::setupUI);
}

EngineMainWindow::~EngineMainWindow() {;}
