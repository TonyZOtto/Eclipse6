//!file {Eclipse6}/root/src/libs/eirCore6/KeySeg.h Basic Alphanumeric name string
#pragma once
#include "eirCore6.h"

#include <AText.h>
#include <Types.h>

class EIRCORE6_EXPORT KeySeg
{
public:
    typedef QList<KeySeg> List;

public:
    KeySeg() {;}
    KeySeg(const char * pch) { set(pch); }
    KeySeg(const AText s) { set(s); }

public:
    bool isEmpty() const { return mText.isEmpty(); }
    AText text() const { return mText; }
    QString toString() const { return QString(mText); }
    operator AText() const { return text(); }
    operator QString() const { return toString(); }

public:
    void clear() { mText.clear(); }
    void set(const char * pch);
    void set(const AText s);

public: // static
    static AText validFirst() { return smValidFirst; }
    static AText validChars() { return smValidFirst; }
    static char replacementChar() { return smReplacementChar; }
    static void validFirst(const AText & s);
    static void validChars(const AText & s);
    static void replacementChar(const char ch);

private:
    AText mText;

private: // static
    static AText validate(AText s);

private: // static
    static AText smValidFirst;
    static AText smValidChars;
    static char smReplacementChar;
};
