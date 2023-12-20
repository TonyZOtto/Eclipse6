//!file {Eclipse6}/root/src/libs/eirExe6/ConsoleWindowAppMain.h Provides a QMainWindow for a ConsoleWindowApp
#pragma once
#include "eirExe6.h"

class ConsoleStreamDisplay;

class EIREXE_EXPORT ConsoleAppMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit ConsoleAppMainWindow(QWidget *parent = nullptr);

public: // access
    ConsoleStreamDisplay * engineDisplay;

public slots:
    void initialize();
    void setup();
    void start();
    void addDisplay(ConsoleStreamDisplay * pcsd);
    void streamTabChanged();

signals:

private:
    QWidget * mpMainWidget=nullptr;
    QBoxLayout * mpMainLayout=nullptr;
    QTabBar * mpStreamTabs=nullptr;
    QStackedWidget * mpStreamStack=nullptr;
    ConsoleStreamDisplay * mpEngineDisplay=nullptr;

};
