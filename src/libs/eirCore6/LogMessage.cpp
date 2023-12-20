#include "LogMessage.h"

void LogMessage::track(const MessageTrackingItem &mti)
{
    m_tracking.insert(mti.nano(), mti);
}
