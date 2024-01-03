//!file {Eclipse6}/root/src/libs/eirExe6/Log.h Coder-facing log usage
#pragma once

/*
#include <LogEngine.h>
Q_GLOBAL_STATIC(LogEngine, LOG)
*/

/* =================== Internal Macros ===================== */
#define LOGCTX Q_FUNC_INFO,__FILE__,__LINE__
#define ARGVAR4 var1, var2=QVariant(),var3=QVariant(),var4=QVariant()
#define USEVAR4 var1, var2, var3, var4

#define LOGTXT(lvl, txt) \
    LOG->add(Message(LOGCTX, lvl, Message::$nullFlag, txt))
#define LOGFMTA(lvl, fmt, var1, var2, var3, var4) \
    LOG->add(Message(LOGCTX, lvl, Message::FormatArgs, fmt, ARGVAR4));
#define LOGFMTAL(lvl, fmt, vars) \
    LOG->add(Message(LOGCTX, lvl, Message::FormatArgs, fmt, vars))

/* =================== User Macros ===================== */

#define INFOMSG(msg) qInfo(msg)
#define PROGRESS(txt) LOGTXT(Message::Progress, txt)
#define PROGRESSA(fmt, ARGVAR4) LOGFMTA(Message::Progress, fmt, USEVARA)
