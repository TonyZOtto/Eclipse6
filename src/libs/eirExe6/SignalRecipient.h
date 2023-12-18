//!file {Eclipse6}/root/src/libs/eirExe6/SignalRecipient.h Contains Uid, Object pointer, and time
#pragma once
#include "eirExe6.h"

#include <QObject>

#include <EpochTime.h>
#include <Uid.h>

class EIREXE_EXPORT SignalRecipient
{
public: // ctors
    SignalRecipient();
    SignalRecipient(const Uid uid, QObject * obj=nullptr, EpochTime et=EpochTime());
    SignalRecipient(QObject * obj, EpochTime et=EpochTime());
    SignalRecipient(EpochTime et);

public: // const
    Uid uid() const { return mUid; }
    QObject * object() const { return mpObject; }
    EpochTime time() const { return mTime; }

public: // non-const
    void uid(const Uid v) { mUid = v; }
    void object(QObject * v) { mpObject = v; }
    void time(const EpochTime v) { mTime = v; }

private:
    Uid mUid;
    QObject * mpObject;
    EpochTime mTime;
};
