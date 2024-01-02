//!file {Eclipse6}/root/src/libs/eirCore6/Key.h Standard alphanumeric delimited string
#pragma once

#include <QString>

#include "KeySeg.h"
#include "KeySegList.h"

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
    QString operator() () const { return toString(); }
    friend  bool operator == (const Key lhs, const Key rhs);
    friend  bool operator <  (const Key lhs, const Key rhs);
    bool operator < (const Key other);

public:
    void clear() { mSegList.clear(); }
    void set(const char * pch);
    void set(const AText s);
    Key & append(const KeySeg &seg);

private:
    KeySegList mSegList;
    static char smHinge;
};

inline bool Key::operator <(const Key other)
{
    return toString() < other.toString();
}

inline bool operator == (const Key lhs, const Key rhs)
{
    return lhs.toString() == rhs.toString();
}

inline bool operator < (const Key lhs, const Key rhs)
{
    return lhs.toString() < rhs.toString();
}
