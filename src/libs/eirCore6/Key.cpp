#include "Key.h"

char Key::smHinge = '/';


QString Key::toString() const
{
    return mSegList.join(smHinge);
}

void Key::set(const char *pch)
{
    set(AText(pch));
}

void Key::set(const AText s)
{
    const AText::List cList = s.split(smHinge);
    Key tResult;
    foreach (AText t, cList)
    {
        KeySeg tSeg(t);
        if ( ! tSeg.isEmpty())
            tResult.append(tSeg);
    }
}
