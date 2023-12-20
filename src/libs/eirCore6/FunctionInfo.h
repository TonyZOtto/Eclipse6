#pragma once

#include <QObject>
#include <QString>

class FunctionInfo
{
    Q_GADGET
public:
    FunctionInfo() {;}
    FunctionInfo(const QString &qfi);

private:
    void parse();

    // ====================== PROPERTIES ===================
private:
    QString m_qFuncInfo;
    QString m_nameSpace;
    QString m_className;
    QString m_functionName;
    Q_PROPERTY(QString qFuncInfo READ qFuncInfo CONSTANT FINAL)
    Q_PROPERTY(QString nameSpace READ nameSpace CONSTANT FINAL)
    Q_PROPERTY(QString className READ className CONSTANT FINAL)
    Q_PROPERTY(QString functionName READ functionName CONSTANT FINAL)

public:
    QString qFuncInfo() const
    {
        return m_qFuncInfo;
    }
    QString nameSpace() const
    {
        return m_nameSpace;
    }
    QString className() const
    {
        return m_className;
    }
    QString functionName() const
    {
        return m_functionName;
    }
};
