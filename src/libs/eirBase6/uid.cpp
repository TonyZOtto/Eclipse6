#include "uid.h"

Uid::Uid(const bool null)
{
    mUuid = null ? QUuid() : QUuid::createUuid();
}

