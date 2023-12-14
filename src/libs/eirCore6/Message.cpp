#include "Message.h"

Q_GLOBAL_STATIC(ExeSupport, EXE)
// BEWARE: Circular #include loop

Message::Message()
{
    ctor();
}

Message::Message(const Level level, const QString text, const Flags f)
{
    ctor();
    m_MsgLevel = level,
        m_MsgFlags = f,
        m_Text = text;
}

Message::Message(const Level level, const QString format, const QVariantList vars, const Flags f)
{
    ctor();
    m_MsgLevel = level,
        m_MsgFlags = f,
        m_Format = format;
    formatMessage();
}

void Message::ctor()
{
    m_MessageUid = Uid();
    //m_CreatedTime = EXE->baseTime();
    m_MsgLevel = $nullLevel;
    m_MsgFlags = $nullFlag;
    m_SenderUid = Uid(true);
    m_ReceiverUid = Uid(true);
}

void Message::formatMessage()
{
    m_Text = m_Format; // NEEDDO
}
