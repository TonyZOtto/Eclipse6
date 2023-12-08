#pragma once

#include <QObject>

class ConsoleMessage : public QObject
{
    Q_OBJECT
public:
    explicit ConsoleMessage(QObject *parent = nullptr);

signals:
};
