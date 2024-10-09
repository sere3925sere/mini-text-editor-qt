#ifndef PAGE_HPP
#define PAGE_HPP

#include <QObject>

#include "image.hpp"

class Page : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList lines READ lines NOTIFY linesChanged FINAL)
    Q_PROPERTY(QList<Image*> images READ images NOTIFY imagesChanged FINAL)
public:
    explicit Page(QObject *parent = nullptr);

    QStringList lines() {
        return m_lines;
    }

    void linesAdd(QString line) {
        m_lines.append(line);
    }

    QList<Image*> images() {
        return m_images;
    }

    void imagesAdd(Image* image) {
        m_images.append(image);
    }

signals:
    void linesChanged();
    void imagesChanged();

private:
    QStringList m_lines;
    QList<Image*> m_images;

};

#endif // PAGE_HPP
