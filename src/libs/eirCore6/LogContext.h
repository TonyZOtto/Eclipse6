#pragma once

#include <QFileInfo>
#include <QObject>
#include <QString>

#include "FunctionInfo.h"

class LogContext
{
    Q_GADGET
public:
    explicit LogContext();
    LogContext(const QMessageLogContext qmlc);
    LogContext(const LogContext &other);

public:
    void set(const QMessageLogContext qmlc);


    // ====================== PROPERTIES ===================
private:
    FunctionInfo m_functionInfo;
    int m_contextVersion;
    int m_lineNumber;
    QFileInfo m_fileInfo;
    QString m_category;
    Q_PROPERTY(FunctionInfo functionInfo READ functionInfo CONSTANT FINAL)
    Q_PROPERTY(int contextVersion READ contextVersion CONSTANT FINAL)
    Q_PROPERTY(int lineNumber READ lineNumber CONSTANT FINAL)
    Q_PROPERTY(QFileInfo fileInfo READ fileInfo CONSTANT FINAL)
    Q_PROPERTY(QString category READ category CONSTANT FINAL)
public:
    FunctionInfo functionInfo() const
    {
        return m_functionInfo;
    }
    int contextVersion() const
    {
        return m_contextVersion;
    }
    int lineNumber() const
    {
        return m_lineNumber;
    }
    QFileInfo fileInfo() const
    {
        return m_fileInfo;
    }
    QString category() const
    {
        return m_category;
    }
};
