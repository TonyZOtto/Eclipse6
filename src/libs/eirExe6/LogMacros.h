//!file {Eclipse6}/root/src/libs/eirExe6/Log.h Coder-facing log usage
#pragma once

/*
#include <LogEngine.h>
Q_GLOBAL_STATIC(LOG, LogEngine)
*/

/* =================== Internal Macros ===================== */
#define LOGCTX(cat) Q_FILE_INFO,__FILE__.__LINE__
#define LOGADD(lvl, txt) LOG->add(Message(LOGCTX, lvl, 0, txt))
#define LOGFMTA(lvl, fmt, var1, var2, var3, var4) \
            LOG->add(Message(LOGCTX, lvl, Message::FormatArgs, fmt, \
                            var1, var2, var3, var4))
#define LOGFMTAL(lvl, fmt, vars) \
            LOG->add(Message(LOGCTX, lvl, Message::FormatArgs, fmt, vars))

/* =================== User Macros ===================== */

