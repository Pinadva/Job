#include "tag.h"

void Tag::exifNameInit()
{
}

Tag::Tag(QWidget *parent)
{
    short_name.setGeometry(0, 0, 70, 20);
    exif_name.setGeometry(80, 0, 120, 20);
    exif_name.addItems(extra.getExtra());
}

void Tag::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.save();
    short_name.show();
    exif_name.show();
}
