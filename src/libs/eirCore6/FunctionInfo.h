//!file {Eclipse6}/root/src/libs/eirCore6/FunctionInfo.h Break down a Q_FUNC_INFO
#pragma once
#include "eirCore6.h"

#include <QFileInfo>
#include <QList>
#include <QMetaType>
#include <QObject>
#include <QString>
#include <QStringList>

#include "Key.h"
#include "KeySegList.h"

class EIRCORE6_EXPORT FunctionInfo
{
    Q_GADGET
public: // types
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

public: // ctors
    FunctionInfo() {;}
    FunctionInfo(const QMessageLogContext context);
    FunctionInfo(const char * qfi, const char * fileName,
                 const char * category, const int fileLine,
                 const int contextVersion=QMessageLogContext().version);

public: // const
    QString fullFunction() const;
    friend bool operator == (const FunctionInfo lhs, const FunctionInfo rhs);

public: // non-const
    void parse(const char * qfi, const char * fileName,
               const char * category, const int fileLine,
               const int contextVersion=QMessageLogContext().version);


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
    Q_PROPERTY(QString qFuncInfo READ qFuncInfo CONSTANT FINAL)
    Q_PROPERTY(QFileInfo fileInfo READ fileInfo CONSTANT FINAL)
    Q_PROPERTY(int fileLine READ fileLine CONSTANT FINAL)
    Q_PROPERTY(Flags flags READ flags CONSTANT FINAL)
    Q_PROPERTY(QString anteMatter READ anteMatter CONSTANT FINAL)
    Q_PROPERTY(QString names READ names CONSTANT FINAL)
    Q_PROPERTY(QString argumentString READ argumentString CONSTANT FINAL)
    Q_PROPERTY(QString postMatter READ postMatter CONSTANT FINAL)
    Q_PROPERTY(QString nameSpace READ nameSpace CONSTANT FINAL)
    Q_PROPERTY(Key className READ className CONSTANT FINAL)
    Q_PROPERTY(Key functionName READ functionName CONSTANT FINAL)
    Q_PROPERTY(QString returnString READ returnString CONSTANT FINAL)
    Q_PROPERTY(QMetaType returnType READ returnType CONSTANT FINAL)
public:
    QString qFuncInfo() const
    {
        return m_qFuncInfo;
    }
    QFileInfo fileInfo() const
    {
        return m_fileInfo;
    }
    int fileLine() const
    {
        return m_fileLine;
    }
    Flags flags() const
    {
        return m_flags;
    }
    QString anteMatter() const
    {
        return m_anteMatter;
    }
    QString names() const
    {
        return m_names;
    }
    QString argumentString() const
    {
        return m_argumentString;
    }
    QString postMatter() const
    {
        return m_postMatter;
    }
    QString nameSpace() const
    {
        return m_nameSpace;
    }
    Key className() const
    {
        return m_className;
    }
    Key functionName() const
    {
        return m_functionName;
    }
    QString returnString() const
    {
        return m_returnString;
    }
    QMetaType returnType() const
    {
        return m_returnType;
    }
};

inline bool operator == (const FunctionInfo lhs, const FunctionInfo rhs)
{
    return lhs.qFuncInfo() == rhs.qFuncInfo();
}

