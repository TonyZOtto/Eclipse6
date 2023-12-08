#ifndef IFCONSOLE_H
#define IFCONSOLE_H

#include <QObject>

#include <ConsoleApp.h>

class IfConsole : public ConsoleApp
{
    Q_OBJECT
public:
    IfConsole(int &argc, char **argv);

public slots:
    void start();
};

#endif // IFCONSOLE_H
