//!file {Eclipse6}/root/src/libs/eirExe6/CommandLine.h Parses Command Line for ExeSupport
#pragma once
#include "eirExe6.h"

#include <Message.h>

class ConsoleMessage : public Message
{
    Q_GADGET
public:
    enum FormatFlag
    {
        $nullFormat = 0,
    };
    Q_DECLARE_FLAGS(FormatFlags, FormatFlag)
    Q_FLAG(FormatFlags);

public: // ctors
    explicit ConsoleMessage(const Message &msg=Message());

public: // const
    QString context(const FormatFlags fflags=$nullFormat) const;
    QString text(const FormatFlags fflags=$nullFormat) const;

public: // non-const

public slots:

signals:

    // =================== PROPERTIES ===================
private:

};
