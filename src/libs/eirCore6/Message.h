//!file {Eclipse6}/root/src/libs/eirCore6/Message.h Generic Message
#pragma once
#include "eirCore6.h"

#include <QIcon>
#include <QList>
#include <QSize>

#include <EpochTime.h>
#include <Uid.h>

#include "VariableMap.h"

class EIRCORE6_EXPORT Message
{
    Q_GADGET
public:
    enum Level
    {
        $nullLevel = 0,
        Config,         //  1
        Detail,         //  2
        TDetail,        //  3
        Info,           //  4
        MsgInfo,        //  5
        Progress,       //  6
        Level07,        //  7
        Prefer,         //  8
        FnArgs,         //  9
        FnLeave,        // 10
        FnEnter,        // 11
        MsgTrace,       // 12
        Dump,           // 13
        TConfig,        // 14
        Trace,          // 15
        TProg,          // 16
        Level17,        // 17
        Level18,        // 18
        Level19,        // 19
        MsgWarn,        // 20
        TWarn,          // 21
        Warning,        // 22
        MsgCritical,    // 23
        TExpect,        // 24
        Expect,         // 25
        Assert,         // 26
        Error,          // 27
        MemFail,        // 28
        Terminate,      // 29
        MsgFatal,       // 30
        Shutdown,       // 31
        $maxLevel       // 32
    };
    Q_ENUM(Level)

    enum LevelFlag
    {
        $nullLevelFlag  = 0,
        ConfigFlag      = 1 << Config,
        DetailFlag      = 1 << Detail,
        TDetailFlag     = 1 << TDetail,
        InfoFlag        = 1 << Info,
        MsgInfoFlag     = 1 << MsgInfo,
        ProgressFlag    = 1 << Progress,
        Level07Flag     = 1 << Level07,
        PreferFlag      = 1 << Prefer,
        FnArgsFlag      = 1 << FnArgs,
        FnLeaveFlag     = 1 << FnLeave,
        FnEnterFlag     = 1 << FnEnter,
        MsgTraceFlag    = 1 << MsgTrace,
        DumpFlag        = 1 << Dump,
        TConfigFlag     = 1 << TConfig,
        TraceFlag       = 1 << Trace,
        TProgFlag       = 1 << TProg,
        Level17Flag     = 1 << Level17,
        Level18Flag     = 1 << Level18,
        Level19Flag     = 1 << Level19,
        MsgWarnFlag     = 1 << MsgWarn,
        TWarnFlag       = 1 << TWarn,
        WarningFlag     = 1 << Warning,
        MsgCriticalFlag = 1 << MsgCritical,
        TExpectFlag     = 1 << TExpect,
        ExpectFlag      = 1 << Expect,
        AssertFlag      = 1 << Assert,
        ErrorFlag       = 1 << Error,
        MemFailFlag     = 1 << MemFail,
        TerminateFlag   = 1 << Terminate,
        MsgFatalFlag    = 1 << MsgFatal,
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
        MsgMask         = MsgInfoFlag | MsgTraceFlag | MsgWarnFlag
                            | MsgCriticalFlag | MsgFatalFlag,
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
    QPixmap iconPixmap(const QSize &sz) const;

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
    static QList<QIcon> smLevelIcons;

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
    Q_PROPERTY(Level msgLevel READ msgLevel CONSTANT FINAL)
    Q_PROPERTY(Flags msgFlags READ msgFlags CONSTANT FINAL)
    Q_PROPERTY(Uid senderUid READ senderUid CONSTANT FINAL)
    Q_PROPERTY(Uid receiverUid READ receiverUid CONSTANT FINAL)
    Q_PROPERTY(QDateTime createdTime READ createdTime CONSTANT FINAL)
    Q_PROPERTY(QDateTime sentTime READ sentTime CONSTANT FINAL)
    Q_PROPERTY(QDateTime receivedTime READ receivedTime CONSTANT FINAL)
    Q_PROPERTY(QString text READ text CONSTANT FINAL)
    Q_PROPERTY(QString format READ format CONSTANT FINAL)
    Q_PROPERTY(QVariantList variantList READ variantList CONSTANT FINAL)
public:
    Uid msgUid() const
    {
        return m_msgUid;
    }
    Level msgLevel() const
    {
        return m_msgLevel;
    }
    Flags msgFlags() const
    {
        return m_msgFlags;
    }
    Uid senderUid() const
    {
        return m_senderUid;
    }
    Uid receiverUid() const
    {
        return m_receiverUid;
    }
    QDateTime createdTime() const
    {
        return m_createdTime;
    }
    QDateTime sentTime() const
    {
        return m_sentTime;
    }
    QDateTime receivedTime() const
    {
        return m_receivedTime;
    }
    QString text() const
    {
        return m_text;
    }
    QString format() const
    {
        return m_format;
    }
    QVariantList variantList() const
    {
        return m_variantList;
    }
};
