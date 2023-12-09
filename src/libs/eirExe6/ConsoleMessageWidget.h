#pragma once

#include <QWidget>

#include "ConsoleMessage.h"

class ConsoleMessageWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ConsoleMessageWidget(QWidget *parent = nullptr);

signals:

private:
    ConsoleMessage mMessage;
};
