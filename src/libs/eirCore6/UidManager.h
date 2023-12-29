#pragma once

#include <QObject>

#include <Key.h>
#include <Return.h>
#include <Types.h>
#include <Uid.h>

class UidManager : public QObject
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

signals:
    void registered(const Uid uid, const Key &key);
};
