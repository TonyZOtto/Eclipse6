#include "uid.h"

Uid::Uid(const bool null)
{
    mUuid = null ? QUuid() : QUuid::createUuid();
}

bool Uid::operator == (const Uid other)
{
    return mUuid == other.mUuid;
}

