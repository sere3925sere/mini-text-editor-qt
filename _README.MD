This is a simple "text editor" that allows displaying of images together with text. It doesn't actually let you edit text, it only displays it. I made it as a Qt practice, and because LibreOffice Writer startup of 30 seconds was a bit annoying for me. Then I learned that even a hello world Qt Quick type application still takes about 5-10 seconds to start, and my motivation to develop it further subdued. Pretty sure it would've been instant if it was written with GDI or DirectX. I probably can still speed it up by using SSD, or by preloading Qt libraries at boot up, because only first start is slow, after first start it starts instantly.

Don't actually use this. Feel free to use code though.

Requires Qt 6.2 to compile, maybe even older version.

Open screenshot.jpg to see how it looks like. Green blue lines show where the page separation is.

References:
https://forum.qt.io/topic/101610/how-to-wrap-text-around-box-square/2
https://doc.qt.io/qt-5/qml-qtquick-text.html#lineLaidOut-signal
https://doc.qt.io/qt-6/qtqml-javascript-dynamicobjectcreation.html
https://www.qt.io/blog/text-editing-improvements-in-qt-quick 
https://github.com/teriflix/scrite
