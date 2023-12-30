//!file {Eclipse6}/root/src/libs/eirCore6/UidManager.h Maps between Uids and Keys
#pragma once
#include "eirCore6.h"

#include <QObject>

#include <Key.h>
#include <Return.h>
#include <Success.h>
#include <Types.h>
#include <Uid.h>
#include <UidMap.h>
#include <Url.h>


class EIRCORE6_EXPORT UidManager : public QObject
{
    Q_OBJECT
public: // ctor
    explicit UidManager(QObject *parent = nullptr);

public: // const
    Count count() const;
    bool contains(const Key &key) const;
    bool contains(const Uid uid) const;
    Uid uid(const Key &key) const;
    Key key(const Uid uid) const;

public: // non-const


public slots:
    Uid add(const Key &key);
    Success add(const Uid uid, const Key &key);
//    Return<BaseError, Count> load(const Url &url);
  //  Return<BaseError, Count> save(const Url &url);

signals:
    void added(const Uid uid, const Key &key);

private:
    UidMap<Key> mKeyUidDMap;
};
