//!file {Eclipse6}/root/src/libs/eirExe6/ConsoleWindowAppMain.h Provides a QMainWindow for a ConsoleWindowApp
#pragma once
#include "eirExe6.h"

#include <QMainWindow>

class QVBoxLayout;
class QTabBar;
class QStackedWidget;

class ConsoleMessageDisplay;

class EIREXE_EXPORT ConsoleWindowAppMain : public QMainWindow
{
    Q_OBJECT
public:
    explicit ConsoleWindowAppMain(QWidget *parent = nullptr);

signals:

public slots:
    void setupUI();
    void tabChanged();

private:
    QVBoxLayout * mpVBoxLayout=nullptr;
    QTabBar * mpTabs=nullptr;
    QStackedWidget * mpStack=nullptr;
    ConsoleMessageDisplay * mpEmptyDisplay;
};
