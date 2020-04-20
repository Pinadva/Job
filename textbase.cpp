#include "textbase.h"

TextBase::TextBase()
{
}
TextBase::TextBase(QPixmap &pixmap, QColor bg_color, QColor text_color)
{
    qDebug() << "textBase";
    this->pixmap     = pixmap;
    this->bg_color   = bg_color;
    this->text_color = text_color;
    this->data       = data;

    this->y       = 60;
    this->delta_y = 80;
}

void TextBase::painterInit()
{
    painter.setBackgroundMode(Qt::OpaqueMode);
    painter.setBackground(bg_color);
    painter.setOpacity(0.5);
    painter.setPen(text_color);
    painter.setFont(QFont("Arial", 48));
}

void TextBase::setDefaultTextColor()
{
    painter.setPen(text_color);
}

void TextBase::drawText(QString key, QString value)
{
    qDebug() << "drTxt pxmp.size" << pixmap.size();
    painter.begin(&pixmap);
    painterInit();
    qDebug() << "drawText";
    if (value == "-")
    {
        painter.setPen(Qt::red);
    }
    else
    {
        setDefaultTextColor();
    }
    QString text = key + ": " + value + " \n";
    qDebug() << "key + value = " << key << value;
    qDebug() << "text = " << text;
    painter.drawText(20, y, text);
    y += delta_y;
    qDebug() << "painter.drawText";
    painter.end();
}
