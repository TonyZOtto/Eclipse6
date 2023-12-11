//!file {Eclipse6}/root/src/libs/eirCore6/Message.h Generic Message
#pragma once
#include "eirCore6.h"

#include <QObject>

#include <MillisecondTime.h>
#include <Uid.h>

#include "VariableMap.h"

class EIRCORE6_EXPORT Message
{
    Q_GADGET
public:
    enum Level
    {
        $null = 0,
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
        FormatReserved  = 0x00000008,
    };
    Q_DECLARE_FLAGS(Flags, Flag)
    Q_FLAG(Flags)

public:
    explicit Message();

    // ====================== PROPERTIES ===================
private:
    Uid m_MessageUid;
    MillisecondTime m_CreatedTime;
    Level m_Level;
    Flags m_Flags;
    Uid m_SenderUid;
    Uid m_ReceiverUid;
    MillisecondTime m_SentTime;
    MillisecondTime m_ReceivedTime;
    QString m_Text;
    QString m_Format;
    VariableMap m_VariableMap;

};
