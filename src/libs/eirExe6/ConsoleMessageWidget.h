//!file {Eclipse6}/root/src/libs/eirExe6/ConsoleMessageWidget.h Displays a ConsoleMessage
#pragma once
#include "eirExe6.h"

#include <QWidget>

#include <QGridLayout>
#include <QIcon>
#include <QString>

#include "ConsoleMessage.h"
#include "ConsoleMessageConfiguration.h"

class EIREXE_EXPORT ConsoleMessageWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ConsoleMessageWidget(const ConsoleMessage msg,
                                  QWidget *parent = nullptr);

public: // const
    ConsoleMessage message() const { return mMessage; }

public slots:
    void setup();

public: // static
    static ConsoleMessageConfiguration & config() { return smConfig; }

signals:

private:
    const ConsoleMessage cmMessage;
    ConsoleMessage mMessage;
    QGridLayout * mpLayout=nullptr;
    static ConsoleMessageConfiguration smConfig;
};
