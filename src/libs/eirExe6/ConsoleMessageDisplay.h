//!file {Eclipse6}/root/src/libs/eirExe6/ConsoleMessageDisplay.h Displays a list of ConsoleMessageWidget pointers
#pragma once
#include "eirExe6.h"

#include <QWidget>

#include <QList>
#include <QVBoxLayout>

class ConsoleMessageWidget;

class EIREXE_EXPORT ConsoleMessageDisplay : public QWidget
{
    Q_OBJECT
public:
    explicit ConsoleMessageDisplay(QWidget *parent = nullptr);

signals:

private:
    QVBoxLayout * mpLayout=nullptr;
    QList<ConsoleMessageWidget *> mMessageWidgetList;
};
