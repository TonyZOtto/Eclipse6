#include "Message.h"

QList<QIcon> Message::smLevelIcons; // TODO Use SafeList

Message::Message()
{
    ctor();
}

Message::Message(const Level level, const QString text, const Flags f)
{
    ctor();
    m_msgLevel = level,
        m_msgFlags = f,
        m_text = text;
}

Message::Message(const Level level, const QString format, const QVariantList vars, const Flags f)
{
    ctor();
    m_msgLevel = level,
        m_msgFlags = f,
        m_format = format,
        m_variantList = vars;
    formatMessage();
}

QPixmap Message::iconPixmap(const QSize &sz) const
{
    return icon(m_msgLevel).pixmap(sz);
}

QtMsgType Message::qmt() const
{
    return qmt(msgLevel());
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
    m_msgUid = Uid(false);
    m_msgLevel = $nullLevel;
    m_msgFlags = $nullFlag;
    m_senderUid = Uid(true);
    m_receiverUid = Uid(true);
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
