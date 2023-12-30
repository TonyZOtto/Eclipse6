//!file {Eclipse6}/root/src/libs/eirBase6/Success.h Typically returns success of a function
#pragma once
#include "eirBase6.h"

#include "Boolean.h"

class EIRBASE6_EXPORT Success : public Boolean
{
public: // ctors
    Success();
    Success(const bool initial);

public: // const
    bool isSuccess() const;
    bool toBool() const { return isSuccess(); }
    operator bool () const { return toBool(); }
    bool operator () () const { return toBool(); }

public: // non-const
    bool test(const bool is);
};
