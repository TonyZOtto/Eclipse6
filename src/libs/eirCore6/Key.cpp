#include "Key.h"

char Key::smHinge = '/';


QString Key::toString() const
{
    QString result;
    KeySegList tSegList = mSegList;
    result = tSegList.takeFirst().toString();
    foreach (KeySeg tSeg, tSegList)
        result += smHinge + tSeg.toString();
    return result;
}

#if 0
bool operator < (const Key lhs, const Key rhs)
{
    return lhs.toString() < rhs.toString();
}
#endif

void Key::set(const char *pch)
{
    set(AText(pch));
}

void Key::set(const AText s)
{
    const AText::List cList = s.split(smHinge);
    Key tKey;
    foreach (AText t, cList)
        tKey.append(KeySeg(t));
}

Key &Key::append(const KeySeg &seg)
{
    if ( ! seg.isEmpty()) mSegList.append(seg);
    return *this;
}

