#include "tag1.h"

Tag1::Tag1(QWidget *parent) : QWidget(parent)
{
    //    qDebug() << extra.getExtra();
    exif_name.setMinimumSize(120, 20);
    exif_name.setGeometry(5, 5, 120, 20);
    exif_name.saveGeometry();
    exif_name.addItems(extra.getExtra());
}

void Tag1::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.drawLine(10, 10, 100, 100);
    p.end();
}
