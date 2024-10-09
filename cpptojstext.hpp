#ifndef CPPTOJSTEXT_H
#define CPPTOJSTEXT_H

#include <QObject>
#include <QQmlEngine>
#include "page.hpp"

class CppToJsText : public QObject
{
    Q_OBJECT
    //Q_PROPERTY(QStringList stringList READ stringList NOTIFY stringListChanged)
    Q_PROPERTY(QStringList lines READ lines NOTIFY linesListChanged FINAL)
    Q_PROPERTY(QList<Page*> pages READ pages CONSTANT)
    QML_ELEMENT
    QML_SINGLETON
public:
    explicit CppToJsText(QObject *parent = nullptr);

    QStringList lines() {
        return m_lines;
    }

    QList<Page*> pages() {
        return m_page;
    }

signals:
    void linesListChanged();

private:
    QStringList m_lines;
    QList<Page*> m_page;

};

#endif // CPPTOJSTEXT_H
