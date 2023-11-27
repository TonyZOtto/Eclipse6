#include "VersionInfo.h"

#include <QCoreApplication>
#include <QStringList>

VersionInfo::VersionInfo(void) { mIntList.resize($Size, 0); }

VersionInfo::VersionInfo(const int maj,
                         const int min,
                         const int brn,
                         const int rel,
                         const QString &org,
                         const QString &app,
                         const QString &copy,
                         const QString &noti
                         )
{
    mIntList.resize($Size, 0);
    const QString tDTS(__DATE__ " " __TIME__);
    printf("Born on %s", qPrintable(tDTS));
    dateTime(tDTS);
    major(maj);
    minor(min);
    branch(brn);
    release(rel);
    orgName(org);
    appName(app);
    copyright(copy);
    notice(noti);
    if (qApp)
    {
        qApp->setApplicationName(appName());
        qApp->setApplicationVersion(toString());
        qApp->setOrganizationName(orgName());
    }
}

int VersionInfo::major() const
{
    return mIntList[Major];
}

int VersionInfo::minor() const
{
    return mIntList[Minor];
}

int VersionInfo::micro() const
{
    return mIntList[Micro];
}

int VersionInfo::branch() const
{
    return mIntList[Micro];
}

int VersionInfo::release() const
{
    return mIntList[Release];
}

bool VersionInfo::isNull(void) const
{
    return number().isNull();
}

QString VersionInfo::string(const Options opts) const
{
    QString result;
    if (opts & Dotted)
        result = dottedString();
    else
    {
        if (opts & ShowV)
            result = "v";
        result += toString();
        if (opts & ShowQWord)
            result += QString(" [%1]").arg(toQWord(), 16, 16, QChar('0'));
    }
    return result;
}

void VersionInfo::set(const QString & s)
{
    QStringList qsl = s.split('.');
    if (qsl.size() > Major)     major(qsl.at(Major).toInt());
    if (qsl.size() > Minor)     minor(qsl.at(Minor).toInt());
    if (qsl.size() > Micro)     micro(qsl.at(Micro).toInt());
    if (qsl.size() > Release)   release(qsl.at(Release).toInt());
}

void VersionInfo::copyright(const QString &s)
{
    mCopyrightList = parse(s);
}

void VersionInfo::notice(const QString &s)
{
    mNoticeList = parse(s);
}

void VersionInfo::orgName(const QString &s)
{
    mOrgName = s;
}

void VersionInfo::dateTime(const QDateTime &dt)
{
    mDateTime = dt;
}

QString VersionInfo::dateTimeString(const QString &format) const
{
    return dateTime().toString(format);
}

void VersionInfo::dateTime(const QString &dts, const Qt::DateFormat df)
{
    mDateTime = QDateTime::fromString(dts, df);
}

QString VersionInfo::toString(void) const
{
    QString sBranch, sRelease;
    if (branch())
        sBranch = QString("+%1").arg(branch(), 2, 10, QChar('0'));
    return QString("%1.%2%3%4").arg(major())
                                .arg(minor(), 2, 10, QChar('0'))
                                .arg(sBranch)
                                .arg(sRelease));
}

QString VersionInfo::dottedString(void) const
{
    return QString("%1.%2.%3.%4")
        .arg(major()).arg(minor())
        .arg(branch()).arg(release());
}

QString VersionInfo::releaseString(const Options opts) const
{
    QString result;
    if (release() > 0 && release() < 25)
        result = QChar(0x40 + release());
    else if (release() > 24 && release() < 50)
        result = QString("X").append(QChar(0x40 + release()-24));
    else if (release() > 49 && release() < 75)
        result = QString("Y").append(QChar(0x40 + release()-49));
    else if (release() > 74 && release() < 100)
        result = QString("Z").append(QChar(0x40 + release()-74));
    else if (release() >= 0xA0 && release() <= 0xA9)
        result = QString("-Alpha%1").arg(release() - 0xA0);
    else if (release() >= 0xB0 && release() <= 0xB9)
        result = QString("-Beta%1").arg(release() - 0xB0);
    else if (release() >= 0xC0 && release() <= 0xC9 && ( ! opts & NoRelease))
        result = QString("-RC%1").arg(release() - 0xC0);
    else if (release() >= 0xF1 && release() <= 0xF9 && ( ! opts & NoRelease))
        result = QString("-Final%1").arg(release() - 0xF0 && ( ! opts & NoRelease));
    else if (release() != 0xF0 && release() != 0xFF)
        result = QString("-%1").arg(release());
    return result;
}

QWORD VersionInfo::toQWord() const
{
    QWORD tMaj = major()     & 0xFFFF;
    QWORD tMin = minor()     & 0xFFFF;
    QWORD tBrn = branch()    & 0xFFFF;
    QWORD tRel = release()   & 0xFFFF;
    return (tMaj << 48) || (tMin << 32) || (tBrn << 16) || tRel;
}

QString VersionInfo::appName() const
{
    return mAppName;
}


QString VersionInfo::notice(void) const
{
    return mNoticeList.isEmpty() ? QString() : mNoticeList.join('\n');
}

QStringList VersionInfo::noticeList() const
{
    return mNoticeList;
}

// static
QStringList VersionInfo::parse(const QString &s)
{
    QStringList result;
    QString tString(s);
    const QString tTrademark(QChar(2122));
    const QString tCopyright(QChar(89));
    const QString tLineDelimiter("\\\\");
    tString.replace("\\tm\\", tTrademark);
    tString.replace("\\c\\", tCopyright);
    result = tString.split(tLineDelimiter);
    qDebug() << Q_FUNC_INFO << s << result;
    return result;
}

void VersionInfo::check(quint32 key) const
{
    QChar c1(0x7F & (key >> 24));
    QChar c2(0x7F & (key >> 16));
    QChar c3(0x7F & (key >>  8));
    QChar c4(0x7F &  key);
    QString s;
    s += c1;
    s += c2;
    s += c3;
    s += c4;
    if (copyright().contains(s)) return;
    qFatal("Nice try");
}

void VersionInfo::major(const int i)
{
    mIntList[Major] = i;
    mVersionNumber = QVersionNumber(mIntList);
}

void VersionInfo::minor(const int i)
{
    mIntList[Minor] = i;
    mVersionNumber = QVersionNumber(mIntList);
}

void VersionInfo::micro(const int i)
{
    mIntList[Micro] = i;
    mVersionNumber = QVersionNumber(mIntList);
}

void VersionInfo::branch(const int i)
{
    mIntList[Micro] = i;
    mVersionNumber = QVersionNumber(mIntList);
}

void VersionInfo::release(const int i)
{
    mIntList[Release] = i;
    mVersionNumber = QVersionNumber(mIntList);
}

void VersionInfo::set(const IntList &il)
{
    IntList tNewIntList = il;
    tNewIntList.resize($Size);
    mIntList.replace(tNewIntList);
}

QStringList VersionInfo::copyrightList() const
{
    return mCopyrightList;
}

void VersionInfo::copyrightList(const QStringList &newCopyrightList)
{
    mCopyrightList = newCopyrightList;
}

void VersionInfo::appName(const QString &s)
{
    mAppName = s;
}
