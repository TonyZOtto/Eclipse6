#include "KeySeg.h"

AText KeySeg::smValidFirst("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
AText KeySeg::smValidChars("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_0123456789");
char KeySeg::smReplacementChar(0);


void KeySeg::set(const char *pch)
{
    AText tText(pch);
    set(tText);
}

void KeySeg::set(const AText s)
{
    mText = validate(s);
}

void KeySeg::validFirst(const AText &s)
{
    smValidFirst = s;
}

void KeySeg::validChars(const AText &s)
{
    smValidChars = s;

}

void KeySeg::replacementChar(const char ch)
{
    smReplacementChar = ch;

}

AText KeySeg::validate(AText s)
{
    //EXPECT(validFirst().contains(replacementChar());
    //EXPECT(validChars().contains(replacementChar());
    AText result;
    const char tFirst = s.takeFirstChar();
    result.append(validFirst().contains(tFirst)
                      ? tFirst : replacementChar());
    foreach(const char tChar, s)
        result.append(validChars().contains(tChar)
                      ? tChar : replacementChar());
    return result;
}
