#include "UidManager.h"

#include "ExeSupport.h"

UidManager::UidManager(ExeSupport *parent)
    : QObject{parent}
{
    setObjectName("UidManager");
}

bool UidManager::contains(const Key &key) const
{
    return mKeyUidDMap.contains(key);
}

bool UidManager::contains(const Uid uid) const
{
    return mKeyUidDMap.contains(uid);
}

Uid UidManager::uid(const Key &key)
{
    if ( ! contains(key))
        add(key);
    return mKeyUidDMap.uid(key);
}

Uid UidManager::uid(QObject *obj)
{
    Key tKey("Object");
    AText tBA;
    tBA.setNum(qptrdiff(obj), 16);
    tKey.append(tBA);
    return uid(tKey);
}

Key UidManager::key(const Uid uid) const
{
    return mKeyUidDMap.t(uid);
}

Uid UidManager::add(const Key &key)
{
    Success success(true);
    success.test( ! contains(key));
    const Uid cUid;
    if (success)
        success.test(add(cUid, key));
    return success ? cUid : Uid();
}

Success UidManager::add(const Uid u, const Key &k)
{
    Success success(true);
    success.test( ! contains(u));
    success.test( ! contains(k));
    if (success)
    {
        const Uid cUid = mKeyUidDMap.add(k);
        success.test( ! cUid.isNull());
        if (success)
            emit added(cUid, k);
        else
            emit addFailed(uid(k), k);
    }
    return success;
}

#if 0
Return<BaseError, Count> UidManager::load(const Url &url)
{
    Return<BaseError, Count> result;
    Q_UNUSED(url);
    Q_ASSERT_X(false, Q_FUNC_INFO, "MUSTDO load(url)"); // MUSTDO load(url)
    Q_ASSERT_X(result.isValid(), Q_FUNC_INFO, "result not valid");
    Q_ASSERT_X(result.isValid(), Q_FUNC_INFO, "result not valid");
    return result;
}

Return<BaseError, Count> UidManager::save(const Url &url)
{
    Return<BaseError, Count> result;
    Q_UNUSED(url);
    Q_ASSERT_X(false, Q_FUNC_INFO, "MUSTDO save(url)"); // MUSTDO save(url)
    Q_ASSERT_X(result.isValid(), Q_FUNC_INFO, "result not valid");
    return result;
}
#endif
