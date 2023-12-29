//!file {Eclipse6}/root/src/libs/eirBase6/BaseError.h Base Error with Id, String, and Data
#pragma once
#include "eirBase6.h"

#include "Boolean.h"

#include <QString>
#include <QVariant>

#include "Types.h"

class EIRBASE6_EXPORT BaseError : public Boolean
{
public: // types
    typedef SNWORD ErrorId;

public: // ctors
    BaseError(); // null
    BaseError(const bool is); // no info
    BaseError(const ErrorId i, const QString &s,
              const QVariant &v=QVariant());

public: // const
    ErrorId id() const { return mId; }
    QString string() const { return mString; }
    QVariant data() const { return mData; }

public: // non-const
    void id(const ErrorId id);
    void string(const QString s) { mString = s; }
    void data(const QVariant v) { mData = v; }
    void set(const ErrorId i, const QString &s,
             const QVariant &v=QVariant());

private:
    ErrorId mId;
    QString mString;
    QVariant mData;
};
