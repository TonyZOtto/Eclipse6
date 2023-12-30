//!file {Eclipse6}/root/src/libs/eirCore6/VariableMap.h Map of Keys to Values
#pragma once
#include "eirCore6.h"

#include <Types.h>

#include "Key.h"
#include "Variable.h"

class EIRCORE6_EXPORT VariableMap
{
public: // ctors
    VariableMap();

public: // const
    bool isEmpty();
    Count count();
    bool contains(const Key &key);
    Variable variable(const Key &key);
    Value value(const Key &key);

public: // non-const

private:
    QMap<Key, Variable> mKeyVariableMap;
};
