#include "EngineMainWindow.h"

#include <QLayout>
#include <QTimer>


EngineMainWindow::EngineMainWindow(QWidget *parent)
    : ConsoleWindowAppMain(parent)
{
    if (layout()) qDebug() << Q_FUNC_INFO << layout()->objectName();
    setObjectName("EngineMainWindow");
    showMaximized();
    QTimer::singleShot(200, this, &EngineMainWindow::setupUI);
    if (layout()) qDebug() << Q_FUNC_INFO << layout()->objectName();
}

EngineMainWindow::~EngineMainWindow() {;}

void EngineMainWindow::setupUI()
{
    if (layout()) qDebug() << Q_FUNC_INFO << layout()->objectName();
    setWindowTitle("INDIface6 Engine Manager");
    ConsoleWindowAppMain();
    if (layout()) qDebug() << Q_FUNC_INFO << layout()->objectName();
}
