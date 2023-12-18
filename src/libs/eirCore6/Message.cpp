#include "Message.h"

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

void Message::ctor()
{
    m_msgUid = Uid();
    m_createdTime = QDateTime::currentDateTime(); // TODO ClockCalendar
    m_msgLevel = $nullLevel;
    m_msgFlags = $nullFlag;
    m_senderUid = Uid(true);
    m_receiverUid = Uid(true);
    if (mLevelIcons.isEmpty())
        loadIcons();
}

void Message::formatMessage()
{
    m_text = m_format; // NEEDDO
}

// static
void Message::loadIcons()
{
    mLevelIcons.resize($maxLevel);
//    for (Level level = Level(int($nullLevel) + 1); level < $maxLevel; ++level)
  //      mLevelIcons[level] = levelIcon(level);
}

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
