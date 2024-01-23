#pragma once

#include <QList>
#include <QMap>
#include <QPair>

#include "Success.h"

template<typename T, typename N> class DualMap
{
    typedef QPair<T, N> TN;
    typedef QList<TN> TNList;

public: // ctors
    DualMap() {;}

public: // const
    bool contains(const N &n) const { return mNTMap.contains(n); }
    bool contains(const T &t) const { return mTNMap.contains(t); }
    T t(const N &n) const { return mNTMap.value(n); }
    N n(const T &t) const { return mTNMap.value(t); }

public: // non-const
    Success add(const T &t, const N &n, const bool okReplace=false);
    Success add(const N &n, const T &t, const bool okReplace=false)
            { return add(t, n, okReplace); }

private:
    QMap<T, N> mTNMap;
    QMap<N, T> mNTMap;
};

template<typename T, typename N>
Success DualMap<T, N>::add(const T &t, const N &n, const bool okReplace)
{
    Success success(true);
    success.test( ! contains(t) || okReplace);
    success.test( ! contains(n) || okReplace);
    if (success)
    {
        mTNMap.insert(t, n);
        mNTMap.insert(n, t);
    }
    return success;
}
