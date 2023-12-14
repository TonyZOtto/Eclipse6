//!file {Eclipse6}/root/src/libs/eirCore6/Key.h Standard alphanumeric delimited string
#pragma once
#include "eirCore6.h"

#include "KeySeg.h"

class EIRCORE6_EXPORT Key
{
public:
    Key() {;}
    Key(const char * pch) { set(pch); }
    Key(const AText s) { set(s); }

public:
    bool isEmpty() const { return mSegList.isEmpty(); }
    int count() const  { return mSegList.count(); }
    QString toString() const;
    operator QString() const { return toString(); }

public:
    void clear() { mSegList.clear(); }
    void set(const char * pch);
    void set(const AText s);

private:
    KeySeg::List mSegList;
};
