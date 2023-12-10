//!file {Eclipse6}/root/src/libs/eirExe6/ConsoleMessageWidget.h Displays a ConsoleMessage
#pragma once
#include "eirExe6.h"

#include <QWidget>

#include "ConsoleMessage.h"

class EIREXE_EXPORT ConsoleMessageWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ConsoleMessageWidget(const ConsoleMessage msg,
                                  QWidget *parent = nullptr);

signals:

private:
    const ConsoleMessage cmMessage;
};
