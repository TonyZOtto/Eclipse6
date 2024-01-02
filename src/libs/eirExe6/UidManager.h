//!file {Eclipse6}/root/src/libs/eirCore6/UidManager.h Maps between Uids and Keys
#pragma once
#include "eirExe6.h"

#include <QObject>

#include <Key.h>
#include <Return.h>
#include <Success.h>
#include <Types.h>
#include <Uid.h>
#include <UidMap.h>
#include <Url.h>

class ExeSupport;

class EIREXE_EXPORT UidManager : public QObject
{
    Q_OBJECT
public: // ctor
    explicit UidManager(ExeSupport *parent = nullptr);

public: // const
    Count count() const;
    bool contains(const Key &key) const;
    bool contains(const Uid uid) const;
    Key key(const Uid uid) const;

public: // non-const
    Uid uid(const Key &key);
    Uid uid(QObject * obj);

public slots:
    Uid add(const Key &key);
    Success add(const Uid uid, const Key &k);
//    Return<BaseError, Count> load(const Url &url);
  //  Return<BaseError, Count> save(const Url &url);

signals:
    void added(const Uid uid, const Key &key);
    void addFailed(const Uid uid, const Key &key);

private:
    UidMap<Key> mKeyUidDMap;
};
