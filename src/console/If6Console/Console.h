#ifndef CONSOLE_H
#define CONSOLE_H

#include <QCoreApplication>
#include <QObject>

class Console : public QCoreApplication
{
    Q_OBJECT
public:
    Console(int &argc, char **argv);

public slots:
    void start();
};

#endif // CONSOLE_H
