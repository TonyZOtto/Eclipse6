#include "Message.h"

#include <QVariant>


QList<QIcon> Message::smLevelIcons; // TODO Use SafeList

Message::Message()
{
}

Message::Message(const char *qfi, const char *filename, const int fileline,
            const Level level, const Flags flags, const char *text)
{
    set(qfi, filename, fileline, level, flags, text);
}

QPixmap Message::iconPixmap(const QSize &sz) const
{
    return icon(m_msgLevel).pixmap(sz);
}

QtMsgType Message::qmt() const
{
    return qmt(msgLevel());
}


void Message::set(const char *qfi, const char *filename, const int fileline,
        const Level level, const Flags flags, const char *text)
{
    set(qfi, filename, fileline, level, flags, text, QVariantList());
}

void Message::set(const Uid sender, const Uid receiver)
{
    m_senderUid = sender, m_receiverUid = receiver;
}

void Message::set(char *qfi, char *filename, const int fileline,
        const Level level, const Flags flags, const QString format,
        const QVariant var1, const QVariant var2,
        const QVariant var3, const QVariant var4)
{
    QVariantList tVars;
    if (var4.isValid()) tVars << var1 << var2 << var3 << var4;
    else if (var3.isValid()) tVars << var1 << var2 << var3;
    else if (var2.isValid()) tVars << var1 << var2;
    else if (var1.isValid()) tVars << var1;
    set(qfi, filename, fileline, level, flags, format, tVars);
}

void Message::set(const char *qfi, const char *filename, const int fileline,
        const Level level, const Flags flags, const QString format,
        const QVariantList vars)
{
    set(level);
    set(qfi, filename, fileline);
    set(flags, format, vars);
}

void Message::set(const Level level)
{
    m_uid = Uid(Uid::VersionTimebased);
    m_msgNano.sample();
    m_msgLevel = level;
}

void Message::set(const char *qfi, const char *filename, const int fileline)
{
    m_functionInfo.parse(qfi, filename, NULL, fileline);
}

void Message::set(const Flags flags, const QString format,
                  const QVariantList vars)
{
    m_msgFlags = flags;
    if (vars.isEmpty())
    {
        m_text = format;
    }
    else
    {
        m_format = format;
        m_variantList = vars;
        formatMessage();
    }
}

// static
QIcon Message::icon(const Level level)
{
    QIcon result;
    if (smLevelIcons.isEmpty()) loadIcons();
    if (smLevelIcons.count() > int(level))
        result = smLevelIcons.value(level);
    return result;
}

void Message::ctor()
{
    m_msgNano.sample();
    m_msgUid = Uid(Uid::VersionTimebased);
    m_msgLevel = $nullLevel;
    m_msgFlags = $nullFlag;
    m_senderUid = Uid();
    m_receiverUid = Uid();
    if (smLevelIcons.isEmpty())
        loadIcons();
}

void Message::formatMessage()
{
    m_text = m_format; // NEEDDO
}

QtMsgType Message::qmt(const Level level)
{
    QtMsgType result = QtMsgType(-1); // invalid
    // MUSTDO!
    Q_UNUSED(level);
    return result;
}

// private static
void Message::loadIcons()
{
    smLevelIcons.resize($maxLevel);
//    for (Level level = Level(int($nullLevel) + 1); level < $maxLevel; ++level)
  //      mLevelIcons[level] = levelIcon(level);
}

// private static
QIcon Message::levelIcon(const Level level)
{
    QIcon result;
    QColor tIconColor;
    QtMsgType tQmt = qmt(level);
    switch (tQmt)
    {
    case QtMsgType::QtInfoMsg:      tIconColor = Qt::blue;      break;
    case QtMsgType::QtDebugMsg:     tIconColor = Qt::green;     break;
    case QtMsgType::QtWarningMsg:   tIconColor = Qt::yellow;    break;
    case QtMsgType::QtCriticalMsg:  tIconColor = Qt::red;       break;
    case QtMsgType::QtFatalMsg:     tIconColor = Qt::black;     break;
    default:                        tIconColor = Qt::magenta;   break;
    }
    return result;
}
