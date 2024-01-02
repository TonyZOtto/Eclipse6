#include "ConsoleMessageWidget.h"

#include <QLabel>
#include <QPixmap>

#include "ConsoleStreamDisplay.h"

ConsoleMessageWidget::ConsoleMessageWidget(const ConsoleMessage msg,
                                           ConsoleStreamDisplay *parent)
    : QWidget{parent}
    , mpDisplay(parent)
    , cmMessage(msg)
{
    qDebug() << Q_FUNC_INFO;
    setObjectName("ConsoleMessageWidget:"+display()->title());
    setup();
}

ConsoleMessageConfiguration ConsoleMessageWidget::config()
{
    return display()->config();
}

void ConsoleMessageWidget::setup()
{
    qDebug() << Q_FUNC_INFO;
    QGridLayout * pLayout = new QGridLayout;
    QLabel * pContextLabel = new QLabel(this);
    QLabel * pMessageLabel = new QLabel(this);
    QLabel * pIPixmapLabel = new QLabel(this);
    QPixmap tIconPixmap = cmMessage.iconPixmap(config()["IconSize"].toSize());
    pContextLabel->setFont(config()["contextFont"].value<QFont>());
    pMessageLabel->setFont(config()["messageFont"].value<QFont>());
    pIPixmapLabel->setPixmap(tIconPixmap);
    pContextLabel->setText(message().context());
    pMessageLabel->setText(message().text());
    pLayout->addWidget(pIPixmapLabel, 0, 0, 1, 2, Qt::AlignCenter);
    pLayout->addWidget(pContextLabel, 1, 0, Qt::AlignLeft);
    pLayout->addWidget(pMessageLabel, 1, 1, Qt::AlignLeft);
    setLayout(pLayout);
}
