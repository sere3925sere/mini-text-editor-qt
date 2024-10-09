#include "cpptojstext.hpp"
#include <QFile>

#include "image.hpp"

CppToJsText::CppToJsText(QObject *parent)
    : QObject{parent}
{
    const int fontSize = 12;

    //m_lines << "aaaa" << "i" << "u" << "e" << "o";
    //m_page = new QList<Page*>(0x10);
    //m_page.resize(0x10);
    m_page.reserve(0x10);

    QFile file("test.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Unable to open file!";
        //TODO: throw exception here
        return;
    }

    Page* page = new Page(this);

    QTextStream in(&file);
    for (int i = 0; ; ) {
        if (in.atEnd()) break;
        QString line = in.readLine();
        if (line == "/p") {
            page->linesAdd(""); i++;
            m_page.append(page);
            page = new Page(this);
            i = 0;
            continue;
        } else if (line == "/i") {
            //page->linesAdd(line); i++;
            Image* image = new Image(page);
            image->m_line = i;
            image->m_width = 256;
            image->m_height = 256;
            page->imagesAdd(image);
            for (int j = 0; j < (256 / fontSize); j++) {
                page->linesAdd(""); i++;
            }
            continue;

            //TODO
            //image.
        }
        //qDebug() << line;
        //eh->lines() << line;
        page->linesAdd(line); i++;
    }
    m_page.append(page);
}
