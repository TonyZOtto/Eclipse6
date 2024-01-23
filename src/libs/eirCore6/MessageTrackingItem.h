#pragma once

#include <QObject>
#include <QVariant>

#include <NanosecondsElapsed.h>
#include <Uid.h>

class MessageTrackingItem
{
    Q_GADGET
public:
    MessageTrackingItem(const Uid uid, const QVariant data=QVariant());

    // ====================== PROPERTIES ===================
private:
    Uid m_uid;
    NanosecondsElapsed m_nano;
    QVariant m_data;
    Q_PROPERTY(NanosecondsElapsed nano READ nano CONSTANT FINAL)
    Q_PROPERTY(Uid uid READ uid CONSTANT FINAL)
    Q_PROPERTY(QVariant data READ data CONSTANT FINAL)
public:
    Uid uid() const
    {
        return m_uid;
    }
    NanosecondsElapsed nano() const
    {
        return m_nano;
    }
    QVariant data() const
    {
        return m_data;
    }
};
