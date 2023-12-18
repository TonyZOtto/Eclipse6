//!file {Eclipse6}/root/src/libs/eirCore6/Message.h Generic Message
#pragma once
#include "eirCore6.h"

#include <QIcon>
#include <QList>

#include <ExeSupport.h>
#include <Uid.h>

#include "VariableMap.h"

class EIRCORE6_EXPORT Message
{
    Q_GADGET
public:
    enum Level
    {
        $nullLevel = 0,
        Config,
        Detail,
        TDetail,
        Info,
        Level05,
        Progress,
        Level07,
        Prefer,
        FnArgs,
        FnLeave,
        FnEnter,
        Level12,
        Dump,
        TConfig,
        Trace,
        TProg,
        Level17,
        Level18,
        Level19,
        Level20,
        TWarn,
        Warning,
        Level23,
        TExpect,
        Expect,
        Assert,
        Error,
        MemFail,
        Terminate,
        Level30,
        Shutdown,
        $maxLevel
    };
    Q_ENUM(Level)

    enum LevelFlag
    {
        $nullLevelFlag  = 0,
        ConfigFlag      = 1 << Config,
        DetailFlag      = 1 << Detail,
        TDetailFlag     = 1 << TDetail,
        InfoFlag        = 1 << Info,
        Level05Flag     = 1 << Level05,
        ProgressFlag    = 1 << Progress,
        Level07Flag     = 1 << Level07,
        PreferFlag      = 1 << Prefer,
        FnArgsFlag      = 1 << FnArgs,
        FnLeaveFlag     = 1 << FnLeave,
        FnEnterFlag     = 1 << FnEnter,
        Level12Flag     = 1 << Level12,
        DumpFlag        = 1 << Dump,
        TConfigFlag     = 1 << TConfig,
        TraceFlag       = 1 << Trace,
        TProgFlag       = 1 << TProg,
        Level17Flag     = 1 << Level17,
        Level18Flag     = 1 << Level18,
        Level19Flag     = 1 << Level19,
        Level20Flag     = 1 << Level20,
        TWarnFlag       = 1 << TWarn,
        WarningFlag     = 1 << Warning,
        Level23Flag     = 1 << Level23,
        TExpectFlag     = 1 << TExpect,
        ExpectFlag      = 1 << Expect,
        AssertFlag      = 1 << Assert,
        ErrorFlag       = 1 << Error,
        MemFailFlag     = 1 << MemFail,
        TerminateFlag   = 1 << Terminate,
        Level30Flag     = 1 << Level30,
        ShutdownFlag    = 1 << Shutdown,
        UserFlagMask    = ConfigFlag | DetailFlag | InfoFlag
                            | ProgressFlag | WarningFlag | ExpectFlag,
        DebugFlagMask   = TDetailFlag | PreferFlag | FnArgs | FnLeave
                            | FnEnterFlag | DumpFlag | TConfigFlag
                            | TraceFlag | TProgFlag | TWarnFlag | TExpectFlag,
        ErrorFlagMask   = AssertFlag | ErrorFlag | MemFailFlag
                            | TerminateFlag | ShutdownFlag,
        QInfoMask       = ConfigFlag | DetailFlag | InfoFlag
                            | ProgressFlag,
        QDebugMask      = TDetailFlag | PreferFlag | FnArgs | FnLeave
                            | FnEnterFlag | DumpFlag | TConfigFlag
                            | TraceFlag | TProgFlag,
        QWarnMask       = TWarnFlag | WarningFlag | ExpectFlag,
        QCriticalMask   = AssertFlag | ErrorFlag,
        QFatalMask      = MemFailFlag | TerminateFlag | ShutdownFlag,
    };
    Q_DECLARE_FLAGS(LevelFlags, LevelFlag)
    Q_FLAG(LevelFlags)
    enum Flag
    {
        $nullFlag       = 0,
        FormatPrintF    = 0x00000001,
        FormatArgs      = 0x00000002,
        FormatArgsPlus  = 0x00000004,
        FormatStream    = 0x00000008,
    };
    Q_DECLARE_FLAGS(Flags, Flag)
    Q_FLAG(Flags)

public:
    explicit Message();
    Message(const Level level, const QString text, const Flags f=$nullFlag);
    Message(const Level level, const QString format,
            const QVariantList vars, const Flags f=$nullFlag);

public: // const
    QIcon icon() const;

public: // static
    static QIcon icon(const Level level);

private:
    void ctor();
    void formatMessage();

private: // static
    static QtMsgType qmt(const Level level);
    static void loadIcons();
    static QIcon levelIcon(const Level level);

private: // static
    static QList<QIcon> mLevelIcons;

    // ====================== PROPERTIES ===================
private:
    Uid m_msgUid;
    Level m_msgLevel;
    Flags m_msgFlags;
    Uid m_senderUid;
    Uid m_receiverUid;
    QDateTime m_createdTime;
    QDateTime m_sentTime;
    QDateTime m_receivedTime;
    QString m_text;
    QString m_format;
    QVariantList m_variantList;
    VariableMap m_variableMap;
    Q_PROPERTY(Uid msgUid READ msgUid CONSTANT FINAL)
    Q_PROPERTY(Level msgLevel READ msgLevel WRITE msgLevel NOTIFY changed_msgLevel FINAL)
    Q_PROPERTY(Flags msgFlags READ msgFlags WRITE msgFlags NOTIFY changed_msgFlags FINAL)
    Q_PROPERTY(Uid senderUid READ senderUid WRITE senderUid NOTIFY changed_senderUid FINAL)
    Q_PROPERTY(Uid receiverUid READ receiverUid WRITE receiverUid NOTIFY changed_receiverUid FINAL)
    Q_PROPERTY(QDateTime createdTime READ createdTime CONSTANT FINAL)
    Q_PROPERTY(QDateTime sentTime READ sentTime WRITE sentTime NOTIFY changed_sentTime FINAL)
    Q_PROPERTY(QDateTime receivedTime READ receivedTime WRITE receivedTime NOTIFY changed_receivedTime FINAL)
    Q_PROPERTY(QString text READ text WRITE text NOTIFY changed_text FINAL)
    Q_PROPERTY(QString format READ format WRITE format NOTIFY changed_format FINAL)
    Q_PROPERTY(QVariantList variantList READ variantList WRITE variantList NOTIFY changed_variantList FINAL)
public:
    Uid msgUid() const
    {
        return m_msgUid;
    }
    Level msgLevel() const
    {
        return m_msgLevel;
    }
    void msgLevel(Level new_msgLevel)
    {
        if (m_msgLevel == new_msgLevel)
            return;
        m_msgLevel = new_msgLevel;
        emit changed_msgLevel();
    }
    Flags msgFlags() const
    {
        return m_msgFlags;
    }
    void msgFlags(const Flags &new_msgFlags)
    {
        if (m_msgFlags == new_msgFlags)
            return;
        m_msgFlags = new_msgFlags;
        emit changed_msgFlags();
    }
    Uid senderUid() const
    {
        return m_senderUid;
    }
    void senderUid(const Uid &new_senderUid)
    {
        if (m_senderUid == new_senderUid)
            return;
        m_senderUid = new_senderUid;
        emit changed_senderUid();
    }
    Uid receiverUid() const
    {
        return m_receiverUid;
    }
    void receiverUid(const Uid &new_receiverUid)
    {
        if (m_receiverUid == new_receiverUid)
            return;
        m_receiverUid = new_receiverUid;
        emit changed_receiverUid();
    }
    QDateTime createdTime() const
    {
        return m_createdTime;
    }
    QDateTime sentTime() const
    {
        return m_sentTime;
    }
    void sentTime(const QDateTime &new_sentTime)
    {
        if (m_sentTime == new_sentTime)
            return;
        m_sentTime = new_sentTime;
        emit changed_sentTime();
    }
    QDateTime receivedTime() const
    {
        return m_receivedTime;
    }
    void receivedTime(const QDateTime &new_receivedTime)
    {
        if (m_receivedTime == new_receivedTime)
            return;
        m_receivedTime = new_receivedTime;
        emit changed_receivedTime();
    }
    QString text() const
    {
        return m_text;
    }
    void text(const QString &new_text)
    {
        if (m_text == new_text)
            return;
        m_text = new_text;
        emit changed_text();
    }
    QString format() const
    {
        return m_format;
    }
    void format(const QString &new_format)
    {
        if (m_format == new_format)
            return;
        m_format = new_format;
        emit changed_format();
    }
    QVariantList variantList() const
    {
        return m_variantList;
    }
    void variantList(const QVariantList &new_variantList)
    {
        if (m_variantList == new_variantList)
            return;
        m_variantList = new_variantList;
        emit changed_variantList();
    }
signals:
    void changed_msgLevel();
    void changed_msgFlags();
    void changed_senderUid();
    void changed_receiverUid();
    void changed_sentTime();
    void changed_receivedTime();
    void changed_text();
    void changed_format();
    void changed_variantList();
};
