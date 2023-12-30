#include "Success.h"

Success::Success() {;}
Success::Success(const bool initial) : Boolean(initial) {;}

bool Success::isSuccess() const
{
    bool result = false;
    if (Boolean::isNull()) result = true;
    else result = Boolean::isTrue();
    return result;
}

bool Success::test(const bool is)
{
    if (Boolean::isNull()) Boolean::set(is);
    else if (is != Boolean::isTrue()) Boolean::set(is);
    else {;}
    return is;
}
