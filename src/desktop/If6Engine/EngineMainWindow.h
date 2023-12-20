#pragma once

#include <ConsoleAppMainWindow.h>

class EngineMainWindow : public ConsoleAppMainWindow
{
    Q_OBJECT

public:
    EngineMainWindow(QWidget *parent = nullptr);
    ~EngineMainWindow();

public slots:
    void setupUI();

private:
};
