//!file {Eclipse6}/root/src/libs/eirBase6/AText.h ASCII Text
#pragma once
#include "eirBase6.h"

#include <QByteArray>

class EIRBASE6_EXPORT AText : public QByteArray
{
public:
    AText() {;}
    AText(const QByteArray ba) : QByteArray(ba) {;}
    AText(const char * pch) : QByteArray(pch) {;}

public:
    char takeFirstChar();
    void append(const char ch);
};
