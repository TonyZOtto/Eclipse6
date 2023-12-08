#pragma once

#include <QApplication>
#include <QObject>

class ConsoleWindowApp : public QApplication
{
public:
    ConsoleWindowApp(int &argc, char **argv, int f=0);
};
