#include "ConsoleMessage.h"

ConsoleMessage::ConsoleMessage(const Message &msg)
    : Message(msg)
{
    qDebug() << Q_FUNC_INFO << msg.text();

}

QString ConsoleMessage::context(const FormatFlags fflags) const
{
    QString result;
    Q_UNUSED(fflags); // TODO Future
    FunctionInfo tFnI = functionInfo();
    result = QString("%1:%2 %3")
                 .arg(tFnI.fileInfo().baseName(), 40)
                 .arg(tFnI.fileLine())
                 .arg(tFnI.fullFunction(), 40);
                    // TODO Configure or smarter
    return result;
}

QString ConsoleMessage::text(const FormatFlags fflags) const
{
    QString result = Message::text();
    Q_UNUSED(fflags); // TODO Future
    // TODO? formatting
    return result;
}
