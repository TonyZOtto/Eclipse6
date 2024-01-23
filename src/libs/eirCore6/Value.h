//!file {Eclipse6}/root/src/libs/eirCore6/Value.h Wraps QVariant for storing Variable values
#pragma once
#include "eirCore6.h"

#include <QVariant>

class EIRCORE6_EXPORT Value
{
public:
    Value();

private:
    QMetaType mMetaType;
    QVariant mVariant;
    QVariant mDefault;

};
