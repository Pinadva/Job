#include "textbase.h"

TextBase::TextBase()
{
}
TextBase::TextBase(QColor bg_color, QColor text_color)
{
    qDebug() << "textBase";
    this->bg_color   = bg_color;
    this->text_color = text_color;

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
    qDebug() << "drawText";
    QString text = key + ": " + value + " \n";
    painter.drawText(20, y, text);
    y += delta_y;
}

void TextBase::drawText(QString text)
{
    painter.drawText(20, y, text);
    y += delta_y;
}

void TextBase::chooseColor(QString value)
{
    if (value == "-")
    {
        qDebug() << "if";
        painter.setPen(Qt::red);
    }
    else
    {
        qDebug() << "else";
        setDefaultTextColor();
    }
}
