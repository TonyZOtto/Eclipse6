//!file {Eclipse6}/root/src/libs/eirBase6/Boolean.h A bool value that can be null or invalid
#pragma once
#include "eirBase6.h"

class EIRBASE6_EXPORT Boolean
{
    /*  Truth table:    Value   Valid
     *      true        true    true
     *      false       false   true
     *      null        true    false
     *      invalid     false   false
     */
public: // ctors
    Boolean(); // a null instance
    Boolean(const bool is);

public: // const
    bool isNull() const;
    bool isValid() const;
    bool isTrue() const;
    bool isFalse() const;
    bool toBool() const { return isTrue(); }
    operator bool () const { return toBool(); }
    bool operator () () const { return toBool(); }

public: // non-const
    void set(const bool is=true);
    void reset() { set(false); }
    void nullify();
    void invalidate();

private:
    bool mValue;
    bool mValid;
};
