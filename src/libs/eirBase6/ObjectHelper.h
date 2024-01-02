#pragma once

#include <QObject>
#include <QString>

class ObjectHelper
{
public:
    ObjectHelper(QObject * obj);

public:
    QString keyString() const;

private:
    QObject * mpObject=nullptr;
};
