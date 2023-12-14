#pragma once

#include <ConsoleWindowAppMain.h>

class EngineMainWindow : public ConsoleWindowAppMain
{
    Q_OBJECT

public:
    EngineMainWindow(QWidget *parent = nullptr);
    ~EngineMainWindow();

public slots:
    void setupUI();

private:
};
