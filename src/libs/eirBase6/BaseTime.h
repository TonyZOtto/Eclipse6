#pragma once

#include <QDateTime>

class BaseTime
{
public:
    BaseTime() {;}

public: // static
    static QDateTime base() { return smBaseDateTime; }

private:
    static QDateTime smBaseDateTime;
};
