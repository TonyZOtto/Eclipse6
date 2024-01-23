//!file {Eclipse6}/root/src/libs/eirCore6/Variable.h Value with its Key
#pragma once
#include "eirCore6.h"

#include "Key.h"
#include "Value.h"

class EIRCORE6_EXPORT Variable
{
public:
    Variable();

private:
    Key mKey;
    Value mValue;
};
