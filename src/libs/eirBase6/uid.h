//!file {Eclipse6}/root/src/libs/eirBase6/Uid.h Unique Identifier support
#pragma once
#include "eirBase6.h"

#include <QUuid>

#include "Types.h"

class EIRBASE6_EXPORT Uid
{
public:
    typedef OWORD Data;
public:
    Uid(const bool null=false);
    QUuid uid() const { return mUuid; }
    bool isNull() const { return mUuid.isNull(); }
    Data data() const { return mUuid.toUInt128(); }

public:
    void uid(const QUuid uu) { mUuid = uu; }
    void data(const Data d) { mUuid = QUuid::fromUInt128(d); }

private:
    QUuid mUuid;
};

