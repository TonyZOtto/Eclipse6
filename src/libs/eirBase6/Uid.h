//!file {Eclipse6}/root/src/libs/eirBase6/Uid.h Unique Identifier support
#pragma once
#include "eirBase6.h"

#include <QUuid>

#include "Types.h"

class EIRBASE6_EXPORT Uid
{
public: // types
    typedef OWORD Data;

public: // ctors
//    explicit Uid();
    Uid(const bool null);

public: // const
    QUuid uid() const { return mUuid; }
    bool isNull() const { return mUuid.isNull(); }
    Data data() const { return mUuid.toUInt128(); }
    bool operator == (const Uid other) const;
    bool operator <  (const Uid other) const;
//    friend bool operator < (const Uid lhs, const Uid rhs);

public: // non-const
    void uid(const QUuid uu) { mUuid = uu; }
    void data(const Data d) { mUuid = QUuid::fromUInt128(d); }

private:
    QUuid mUuid;

    // QMetaType-required below
public:
    Uid() = default;
    Uid(const Uid &other) = default;
    ~Uid() = default;
    Uid &operator = (const Uid &other) = default;
};

//extern EIRBASE6_EXPORT bool operator < (const Uid lhs, const Uid rhs);

//Q_DECLARE_METATYPE(Uid);
//Q_DECLARE_TYPEINFO(Uid, Q_PRIMITIVE_TYPE)

