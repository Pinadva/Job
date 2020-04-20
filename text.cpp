#include "text.h"

Text::Text()
{
}

Text::Text(QPainter *painter, QColor bg_color, QColor text_color, const QHash<QString, QString> &data)
{
    this->painter    = painter;
    this->bg_color   = bg_color;
    this->text_color = text_color;
    this->data       = data;
}

Text::~Text()
{
    delete painter;
}

void Text::painterInit()
{
    painter->setBackgroundMode(Qt::OpaqueMode);
    painter->setBackground(bg_color);
    painter->setOpacity(0.5);
    painter->setPen(text_color);
    painter->setFont(QFont("Arial", 48));
}

void Text::setDefaultTextColor()
{
    painter->setPen(text_color);
}

void Text::drawText(const QString &key, const QString &value)
{
    if (value == "-")
        painter->setPen(Qt::red);
    else
        setDefaultTextColor();

    QString text = key + ": " + value + " \n";
    painter->drawText(20, y += delta_y, text);
}
