//!file {Eclipse6}/root/src/libs/eirCore6/Message.h Generic Message
#pragma once
#include "eirCore6.h"

#include <QObject>

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

private:
    void ctor();
    virtual void formatMessage();

    // ====================== PROPERTIES ===================
private:
    Uid m_MessageUid;
    QDateTime m_CreatedTime;
    Level m_MsgLevel;
    Flags m_MsgFlags;
    Uid m_SenderUid;
    Uid m_ReceiverUid;
    QDateTime m_SentTime;
    QDateTime m_ReceivedTime;
    QString m_Text;
    QString m_Format;
    QVariantList m_VariantList;
    VariableMap m_VariableMap;
public:
    Uid MessageUid() const
    {
        return m_MessageUid;
    }
    MillisecondTime CreatedTime() const
    {
        return m_CreatedTime;
    }
    Level MsgLevel() const
    {
        return m_MsgLevel;
    }
    Flags MsgFlags() const
    {
        return m_MsgFlags;
    }
    Uid SenderUid() const
    {
        return m_SenderUid;
    }
    Uid ReceiverUid() const
    {
        return m_ReceiverUid;
    }
    MillisecondTime SentTime() const
    {
        return m_SentTime;
    }
    MillisecondTime ReceivedTime() const
    {
        return m_ReceivedTime;
    }
    QString Text() const
    {
        return m_Text;
    }
    QString Format() const
    {
        return m_Format;
    }
    QVariantList VariantList() const
    {
        return m_VariantList;
    }

    Q_PROPERTY(Uid MessageUid READ MessageUid CONSTANT FINAL)
    Q_PROPERTY(MillisecondTime CreatedTime READ CreatedTime CONSTANT FINAL)
    Q_PROPERTY(Level MsgLevel READ MsgLevel CONSTANT FINAL)
    Q_PROPERTY(Flags MsgFlags READ MsgFlags CONSTANT FINAL)
    Q_PROPERTY(Uid SenderUid READ SenderUid CONSTANT FINAL)
    Q_PROPERTY(Uid ReceiverUid READ ReceiverUid CONSTANT FINAL)
    Q_PROPERTY(MillisecondTime SentTime READ SentTime CONSTANT FINAL)
    Q_PROPERTY(MillisecondTime ReceivedTime READ ReceivedTime CONSTANT FINAL)
    Q_PROPERTY(QString Text READ Text CONSTANT FINAL)
    Q_PROPERTY(QString Format READ Format CONSTANT FINAL)
    Q_PROPERTY(QVariantList VariantList READ VariantList CONSTANT FINAL)
};
