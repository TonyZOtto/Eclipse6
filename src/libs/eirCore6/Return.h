//!file {Eclipse6}/root/src/libs/eirCore6/Return.h Return that can return an Error or Value
#pragma once

#include <QVariant>

#include <BaseError.h>
#include <Boolean.h>

template <typename VAL=QVariant, typename ERR=BaseError>
class Return : public Boolean
{
public:
    Return();
};
