#pragma once

#include <QObject>

#include <MillisecondTime.h>

class ConsoleMessage : public QObject
{
    Q_GADGET
public:
    enum ClassFlag
    {
        $null = 0,
        InfoTrivia      = 0x0000001,
        Shutdown        = 0x8000000,
    };
    Q_DECLARE_FLAGS(ClassFlags, ClassFlag)
    Q_FLAGS(ClassFlags)


public:
    explicit ConsoleMessage(QObject *parent = nullptr);

signals:

    // =================== PROPERTIES ===================
private:
    ClassFlags mFlags;
    MillisecondTime mCreatedMst;
};
