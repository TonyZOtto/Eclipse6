#pragma once

#include <QFileInfo>
#include <QList>
#include <QMetaType>
#include <QObject>
#include <QString>
#include <QStringList>

#include "Key.h"
#include "KeySegList.h"

class FunctionInfo
{
    Q_GADGET
public:
    enum Flag
    {
        $$nullFlag          = 0,
        AnteConst           = 0x01000000,
        Virtual             = 0x02000000,
        ReturnVoid          = 0x00100000,
        ArgumentsVoid       = 0x00000100,
        ArgumentConst       = 0x00000200,
        ArgummentPointer    = 0x00000400,
        ArgummentReference  = 0x00000400,
        PostConst           = 0x00000001,
        PureVirtual         = 0x00000002,
    };
    Q_DECLARE_FLAGS(Flags, Flag)
    Q_FLAG(Flags)

    struct ArgumentInfo
    {
        QString aiTypeString;
        Flags aiFlags;
        QMetaType aiArgumentType;
        KeySeg aiName;
    };

public:
    FunctionInfo() {;}
    FunctionInfo(const QMessageLogContext context);

public:
    //! Supply Q_FUNC_INFO string to parser if default ctor was used.
    void parse(const char * qfi, const char * fileName,
               const char * category, const int fileLine,
               const int contextVersion);

private:
    //! Parse Q_FUNC_INFO into component parts
    void parse();
    //! Split Q_FUNC_INFO string into AmteMatter, Names, ArgumentString, and PostMatter
    void initialSplit();
    //! Identify AnteMatter flags
    void handleAnte();
    //! Split into namespace(s) and class & function names
    void handleNames();
    //! Identify PostMatter flags
    void handlePost();
    //! Split argument string into ArgumentInfo structures
    void splitArguments();

    // ====================== PROPERTIES ===================
private:
    QString m_qFuncInfo;
    QString m_logCategory;
    QFileInfo m_fileInfo;
    int m_fileLine;
    Flags m_flags;
    QString m_anteMatter;
    QString m_names;
    QString m_argumentString;
    QString m_postMatter;
    QString m_nameSpace;
    Key m_className;
    Key m_functionName;
    QString m_returnString;
    QMetaType m_returnType;
    QList<ArgumentInfo> m_arguments;
    int m_contextVersion;
};
