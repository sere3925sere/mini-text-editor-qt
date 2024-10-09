#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <QObject>

class Image : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int line READ line CONSTANT)
    Q_PROPERTY(int width READ width CONSTANT)
    Q_PROPERTY(int height READ height CONSTANT)
public:
    explicit Image(QObject *parent = nullptr);

    int line() {
        return m_line;
    }

    int width() {
        return m_width;
    }

    int height() {
        return m_height;
    }

    int m_line;
    int m_width;
    int m_height;

signals:

};

#endif // IMAGE_HPP
