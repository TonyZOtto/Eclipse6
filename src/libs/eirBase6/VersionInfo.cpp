#include "VersionInfo.h"

#include <QCoreApplication>
#include <QStringList>

VersionInfo::VersionInfo(void) {;}

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
    const QString tDTS(__DATE__ " " __TIME__);
    const QDateTime tDateTime = QDateTime::fromString(tDTS);
    m_built = tDateTime;
    m_major = maj;
    m_minor = min;
    m_branch = brn;
    m_release = rel;
    m_appname = app;
    m_orgname = org;
    m_copyright = copy;
    m_notice = noti;
    if (qApp)
    {
        qApp->setApplicationName(appname());
        qApp->setApplicationVersion(string());
        qApp->setOrganizationName(orgname());
    }
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
        if (opts & ShowV) result = "v";
        result += toString(opts);
        if (opts & ShowQWord) result += QString(" [%1]").arg(toQWord(), 16, 16, QChar('0'));
    }
    return result;
}

void VersionInfo::set(const QString & s)
{
    const QStringList qsl = s.split('.');
    const int n = qsl.count();
    if (n > 0)  m_major     = qsl[0].toInt();
    if (n > 1)  m_minor     = qsl[1].toInt();
    if (n > 2)  m_branch    = qsl[2].toInt();
    if (n > 3)  m_release   = qsl[3].toInt();
}

QString VersionInfo::builtString(const QString &format) const
{
    return built().toString(format);
}

QString VersionInfo::toString(const Options opts) const
{
    QString sBranch, sRelease;
    if (branch())
        sBranch = QString("+%1").arg(branch(), 4, 10, QChar('0'));
    sRelease = releaseString(opts);
    return QString("%1.%2%3%4").arg(major())
                               .arg(minor(), (opts & Minor3wide) ? 3 : 2, 10, QChar('0'))
                               .arg(sRelease)
                               .arg(sBranch)
        ;
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
    else if (release() >= 0xC0 && release() <= 0xC9 && ( ! (opts & NoRelease)))
        result = QString("-RC%1").arg(release() - 0xC0);
    else if (release() >= 0xF1 && release() <= 0xF9 && ( ! (opts & NoRelease)))
        result = QString("-Final%1").arg(release() - 0xF0 && ( ! (opts & NoRelease)));
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

QVersionNumber VersionInfo::number() const
{
    QVersionNumber result(major(), minor(), branch());
    return result;
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

void VersionInfo::set(const IntList &il)
{
    const int n = il.count();
    if (n > 0)  m_major     = il[0];
    if (n > 1)  m_minor     = il[1];
    if (n > 2)  m_branch    = il[2];
    if (n > 3)  m_release   = il[3];
}


