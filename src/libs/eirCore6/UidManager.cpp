#include "UidManager.h"

UidManager::UidManager(QObject *parent)
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

Uid UidManager::uid(const Key &key) const
{
    return mKeyUidDMap.uid(key);
}

Key UidManager::key(const Uid uid) const
{
    return mKeyUidDMap.t(uid);
}

Uid UidManager::add(const Key &key)
{
    Success success(true);
    success.test( ! contains(key));
    const Uid cUid(false);
    if (success)
        success.test(add(cUid, key));
    return success ? cUid : Uid();
}

Success UidManager::add(const Uid uid, const Key &key)
{
    Success success(true);
    success.test( ! contains(uid));
    success.test( ! contains(key));
    if (success)
    {
        const Uid cUid = mKeyUidDMap.add(key);
        success.test( ! cUid.isNull());
        if (success)
            emit added(cUid, key);
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
