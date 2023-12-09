#pragma once

#include <QWidget>

#include <QList>

class ConsoleMessageWidget;

class ConsoleMessageDisplay : public QWidget
{
    Q_OBJECT
public:
    explicit ConsoleMessageDisplay(QWidget *parent = nullptr);

signals:

private:
    QList<ConsoleMessageWidget *> mMessageWidgetList;
};
