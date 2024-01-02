//!file {Eclipse6}/root/src/libs/eirBase6/Types.h Common typedef's
#pragma once

#include <QtGlobal>
#include <QByteArray>
#include <QList>
#include <QString>

typedef quint8          BYTE;
typedef quint16         WORD;
typedef quint32         DWORD;
typedef quint64         QWORD;
typedef quint128        OWORD;
typedef qint8           SBYTE;
typedef qint16          SWORD;
typedef qint32          SDWORD;
typedef qint64          SQWORD;
typedef qint128         SOWORD;
typedef quintptr        NWORD;
typedef qptrdiff        SNWORD;

typedef QString         UText;
typedef SQWORD          Nano;
typedef NWORD           Count;
typedef SNWORD          Index;

typedef size_t          Count;
typedef qsizetype       Index;

typedef QList<int>      IntList;

const Nano nanoPerMicroSecond   = 1000;                         //                      1,000   1k ns
const Nano nanoPerMilliSecond   = 1000 * nanoPerMicroSecond;    //                  1,000,000   1M ns
const Nano nanoPerSecond        = 1000 * nanoPerMilliSecond;    //              1,000,000,000   1G ns
const Nano nanoPerMinute        = 60 * nanoPerSecond;           //             60,000,000,000   60   sec
const Nano nanoPerHour          = 60 * nanoPerMinute;           //          3,600,000,000,000   3.6k sec
const Nano nanoPerDay           = 24 * nanoPerHour;             //         86,400,000,000,000  86.4M sec
const Nano nanoPerYear          = 365 * nanoPerDay;             //     31,536,000,000,000,000 ~31.5G sec
const Nano nanoPerCentury       = 36525 * nanoPerDay;           // 31,557,600,000,000,000,000 ~31.6T sec

/*
 *  nano/WORD   =                                        0.000,065,536
 *  nano/DWORD  =                                   ~4.294
 *  nano/QWORD  =                          ~18,446,180,000
 *  nano/OWORD  = ~340,282,400,000,000,000,000,000,000,000
 *  WORD   16bit=                                               65,536      65.5k
 *  DWORD  32bit=                                       ~4,294,967,000       4.3G
 *  QWORD  64bit=                          ~18,446,740,000,000,000,000      18.4E (Exa)
 *  OWORD 128bit= ~340,282,400,000,000,000,000,000,000,000,000,000,000 340,282.4Q (Quetta)
 */
