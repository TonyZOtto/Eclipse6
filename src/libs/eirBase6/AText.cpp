#include "AText.h"


char AText::takeFirstChar()
{
    char result = 0;
    if ( ! isEmpty()) result = *(first(1)).data();
    removeFirst();
    return result;
}

void AText::append(const char ch)
{
    if (ch) append(ch);
}
