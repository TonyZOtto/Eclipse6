#include "Boolean.h"

Boolean::Boolean() : mValue(true), mValid(false) {;}
Boolean::Boolean(const bool is) : mValue(is),  mValid(true) {;}

bool Boolean::isNull() const
{
    return true == mValue && false == mValid;
}

bool Boolean::isValid() const
{
    return mValid;
}

bool Boolean::isTrue() const
{
    return true == mValue && true == mValid;
}

bool Boolean::isFalse() const
{
    return ! toBool();
}

void Boolean::set(const bool is)
{
    mValue = is, mValid = false;
}

void Boolean::nullify()
{
    mValue = true, mValid = false;
}

void Boolean::invalidate()
{
    mValue = false, mValid = false;
}
