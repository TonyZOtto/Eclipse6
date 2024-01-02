//!file {Eclipse6}/root/src/libs/eirCore6/MetaTypeSample.h A sample of needed items to declare a new user QMetaType
#pragma once
#include "eirCore6.h"

#error Should not be #include'd

class MetaTypeSample
{
public:
    MetaTypeSample(const int i) : mInt(i) {;}
private:
    int mInt;

    /* ======================== QMetaType-required below */
public: // QMetaType
    MetaTypeSample() = default;
    MetaTypeSample(const MetaTypeSample &other) = default;
    ~MetaTypeSample() = default;
    MetaTypeSample &operator = (const MetaTypeSample &other) = default;
};

Q_DECLARE_METATYPE(MetaTypeSample);
Q_DECLARE_TYPEINFO(MetaTypeSample, Q_PRIMITIVE_TYPE);
