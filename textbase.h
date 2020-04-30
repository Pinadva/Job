#ifndef TEXTBASE_H
#define TEXTBASE_H

#include <QDebug>
#include <QPainter>

class TextBase
{
private:
    QColor bg_color;
    QColor text_color;
    int y;
    int delta_y;

public:
    QPainter painter;

    TextBase();
    TextBase(QColor, QColor);

    void painterInit();
    void chooseColor(QString);
    void drawText(QString, QString);
    void drawText(QString);
};

#endif // TEXTBASE_H
