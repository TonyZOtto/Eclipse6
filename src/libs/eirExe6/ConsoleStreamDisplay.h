//!file {Eclipse6}/root/src/libs/eirExe6/ConsoleMessageDisplay.h Displays a list of ConsoleMessageWidget pointers
#pragma once
#include "eirExe6.h"


class ConsoleMessage;
class ConsoleMessageWidget;

class EIREXE_EXPORT ConsoleStreamDisplay : public QWidget
{
    Q_OBJECT
public:
    explicit ConsoleStreamDisplay(const QString s,
                                  QWidget *parent = nullptr);

public:
    QString title() const { return mTitle; }

public slots:
    void initialize();
    void setup();
    void start();
    void addMessage(const ConsoleMessage &msg);

signals:

private:
    QString mTitle;
    QBoxLayout * mpLayout=nullptr;
    QList<ConsoleMessageWidget *> mMessageWidgetList;
};
