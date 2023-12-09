#pragma once

#include <QMainWindow>

#include "ConsoleWindowMainWidget.h"

class ConsoleWindowAppMain : public QMainWindow
{
    Q_OBJECT
public:
    explicit ConsoleWindowAppMain(QWidget *parent = nullptr);

signals:

private:
    ConsoleWindowMainWidget * mpMainWidget=nullptr;
};
