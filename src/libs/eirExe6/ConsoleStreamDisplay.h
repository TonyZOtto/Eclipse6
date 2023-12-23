//!file {Eclipse6}/root/src/libs/eirExe6/ConsoleMessageDisplay.h Displays a list of ConsoleMessageWidget pointers
#pragma once
#include "eirExe6.h"

#include "ConsoleMessageConfiguration.h"
class ConsoleMessage;
class ConsoleMessageWidget;

class EIREXE_EXPORT ConsoleStreamDisplay : public QWidget
{
    Q_OBJECT
public:
    ConsoleStreamDisplay(const QString title,
                         QWidget *parent = nullptr);
    ConsoleStreamDisplay(const QString title,
                         const ConsoleMessageConfiguration &config,
                         QWidget *parent = nullptr);

public:
    QString title() const { return mTitle; }
    ConsoleMessageConfiguration config() const { return mMessageConfiguration; }

public slots:
    void initialize();
    void setup();
    void start();
    void addMessage(const ConsoleMessage &msg);

signals:

private:
    QString mTitle;
    ConsoleMessageConfiguration mMessageConfiguration;
    QBoxLayout * mpLayout=nullptr;
    QList<ConsoleMessageWidget *> mMessageWidgetList;
};
