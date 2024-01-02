//!file {Eclipse6}/root/src/libs/eirExe6/ConsoleMessageWidget.h Displays a ConsoleMessage
#pragma once
#include "eirExe6.h"

#include <QWidget>

#include <QGridLayout>
#include <QIcon>
#include <QString>

#include "ConsoleMessage.h"
#include "ConsoleMessageConfiguration.h"
class ConsoleStreamDisplay;

class EIREXE_EXPORT ConsoleMessageWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ConsoleMessageWidget(const ConsoleMessage msg,
                                  ConsoleStreamDisplay *parent=nullptr);

public: // const
    ConsoleStreamDisplay * display() { return mpDisplay; }
    ConsoleMessage message() const { return cmMessage; }
    ConsoleMessageConfiguration config();

public slots:
    void setup();

public: // static

signals:

private:
    ConsoleStreamDisplay * mpDisplay;
    const ConsoleMessage cmMessage;
};
