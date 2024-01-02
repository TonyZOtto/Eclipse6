#pragma once

#include <QObject>

class BaseMachine : public QObject
{
    Q_OBJECT
public:
    explicit BaseMachine(QObject *parent = nullptr);

signals:
};
