#include "uid.h"

//Uid::Uid() {;} // null QUuid()

Uid::Uid(const bool null)
{
    mUuid = null ? QUuid() : QUuid::createUuid();
}

bool Uid::operator == (const Uid other) const
{
    return mUuid == other.mUuid;
}

bool Uid::operator < (const Uid other) const
{
    return mUuid < other.mUuid;
}
#if 0
bool operator < (const Uid lhs, const Uid rhs)
{
    return lhs.data() < rhs.data();
}

#endif
