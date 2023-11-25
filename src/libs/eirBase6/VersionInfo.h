//!file {Eclipse6}/root/src/libs/eirBase6/VersionInfo.h Manage version numbers; wraps QVersionNumber
#pragma once

#include <QCoreApplication>
#include <QDateTime>
#include <QString>
#include <QVersionNumber>

#include "Types.h"

class VersionInfo
{
public:
    enum Segment
    {
        $Null = 0,
        Major = $Null,
        Minor,
        Micro,
        Branch = Micro,
        Release,
        $Size
    };

public:
    VersionInfo(void);
    VersionInfo(const int maj,
                const int min,
                const int brn,
                const int rel,
                const QString &org=QString(),
                const QString &app=QString(),
                const QString &copy=QString(),
                const QString &noti=QString());

public: // const
    int major() const;
    int minor() const;
    int micro() const;
    int branch() const;
    int release() const;
    bool isNull() const;
    QString toString(void) const;
    QString dottedString(void) const;
    QWORD toQWord(void) const;
    QVersionNumber number() const;
    QDateTime dateTime() const;
    QString dateTimeString(const QString &format="MM-dd-yyyy hh:mm:ss") const;
    QString copyright() const;
    QString notice() const;
    QString orgName() const;
    QString appName() const;
    QStringList copyrightList() const;
    QStringList noticeList() const;
    void check(quint32 key) const;
    void setApp(QCoreApplication *pApp) const;

public: // non-const
    void major(const int i);
    void minor(const int i);
    void micro(const int i);
    void branch(const int i);
    void release(const int i);
    void set(const IntList &il);
    void set(const int maj, const int min, const int mic, const int rel);
    void set(const QString &s);
    void copyright(const QString &s);
    void notice(const QString &s);
    void orgName(const QString &s);
    void appName(const QString &s);
    void dateTime(const QDateTime &dt);
    void dateTime(const QString &dts, const Qt::DateFormat df=Qt::TextDate);
    void copyrightList(const QStringList &newCopyrightList);
    void noticeList(const QStringList &newCopyrightList);

private: // static
    static QStringList parse(const QString &s);

private:
    IntList mIntList;
    QVersionNumber mVersionNumber;
    QStringList mCopyrightList;
    QStringList mNoticeList;
    QString mAppName;
    QString mOrgName;
    QDateTime mDateTime;
};
