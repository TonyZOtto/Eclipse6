#pragma once

#include "DualMap.h"
#include "Uid.h"

template<typename T> class UidMap : public DualMap<Uid, T>
{
public: // ctors

public: // const
    Uid uid(const T &tt) const { return DualMap<Uid, T>::t(tt); }
    T t(const Uid u) const { return DualMap<Uid, T>::n(u); }

public: // non-const
    Uid add(const T &t, const bool okReplace=false);
    Success add(const Uid u, const T &t, const bool okReplace=false);

private:
};

template<typename T>
Uid UidMap<T>::add(const T &t, const bool okReplace)
{
    Success success(true);
    success.test( ! DualMap<Uid, T>::contains(t) || okReplace);
    const Uid cUid(Uid::VersionRandom);
    if (success)
        success.test(DualMap<Uid, T>::add(cUid, t));
    return success ? cUid : Uid();
}

template<typename T>
Success UidMap<T>::add(const Uid u, const T &t, const bool okReplace)
{
    Success success(true);
    success.test( ! DualMap<Uid, T>::contains(t) || okReplace);
    success.test( ! DualMap<Uid, T>::contains(u) || okReplace);
    if (success)
        success.test(DualMap<Uid, T>::add(u, t));
    return success;
}
