#include "BaseError.h"

BaseError::BaseError() : mId(0) {;} // Boolean is null
BaseError::BaseError(const bool is) // id 1 with no string
    : Boolean( ! is), mId(is) {;}
BaseError::BaseError(const ErrorId i, const QString &s,
                     const QVariant &v)
{
    set(i, s,v);
}

void BaseError::id(const ErrorId i)
{
    Boolean::set(0 != i);
    mId = i;
}

void BaseError::set(const ErrorId i, const QString &s,
                    const QVariant &v)
{
    Boolean::set( ! i);
    mId = i, mString = s, mData = v;
}
