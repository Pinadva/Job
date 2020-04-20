#ifndef TEXTBASE_H
#define TEXTBASE_H

#include <QDebug>
#include <QPainter>

class TextBase
{
public:
    QPainter painter;
    QPixmap pixmap;
    QColor bg_color;
    QColor text_color;
    QHash<QString, QString> data;
    int y;
    int delta_y;

    TextBase();
    TextBase(QPixmap &, QColor, QColor);

    void painterInit();
    void setDefaultTextColor();
    void drawText(QString, QString);
};

#endif // TEXTBASE_H
