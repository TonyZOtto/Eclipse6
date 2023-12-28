#include "AText.h"


QString AText::toString() const
{
    return QString(*this);
}

char AText::takeFirstChar()
{
    char result = 0;
    if ( ! isEmpty()) result = *(first(1)).data();
    removeFirst();
    return result;
}
