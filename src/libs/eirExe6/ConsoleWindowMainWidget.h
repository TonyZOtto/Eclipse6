#pragma once

#include <QWidget>

#include <QStackedWidget>
#include <QTabBar>
#include <QVBoxLayout>

class ConsoleWindowMainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ConsoleWindowMainWidget(QWidget *parent = nullptr);

public slots:
    void setupUI();
    void tabChanged();

signals:

private:
    QVBoxLayout * mpVBoxLayout=nullptr;
    QTabBar * mpTabs=nullptr;
    QStackedWidget * mpStack=nullptr;
};
