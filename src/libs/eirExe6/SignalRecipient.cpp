#include "SignalRecipient.h"

SignalRecipient::SignalRecipient() : mpObject(nullptr) {;}

SignalRecipient::SignalRecipient(const Uid uid, QObject * obj, EpochTime et)
    : mUid(uid), mpObject(obj), mTime(et) {;}

SignalRecipient::SignalRecipient(QObject *obj, EpochTime et)
    : mpObject(obj), mTime(et) {;}

SignalRecipient::SignalRecipient(EpochTime et)
    : mpObject(nullptr),  mTime(et) {;}
