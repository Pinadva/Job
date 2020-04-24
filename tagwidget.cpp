#include "tagwidget.h"

TagWidget::TagWidget(QWidget *parent) : QWidget(parent)
{
    short_name    = new QLineEdit(this);
    exif_name     = new QComboBox(this);
    delete_button = new QPushButton(this);

    margin = 20;

    setShortName();
    setExifName();
    setDeleteButton();
}

void TagWidget::setShortName()
{
    short_name->setGeometry(margin, margin, 50, 20);

    short_name->saveGeometry();
    repaint();
}

void TagWidget::setExifName()
{
    exif_name->addItems(extra.getExtra());
    exif_name->setGeometry(short_name->width() + margin, margin, 140, 20);

    exif_name->saveGeometry();
    repaint();
}

void TagWidget::setDeleteButton()
{
    delete_button->setGeometry(210, margin, 20, 20);
    QPixmap pm(20, 20);
    pm.fill(Qt::red);
    QIcon icon;
    icon.addPixmap(pm);
    delete_button->setIcon(icon);

    delete_button->saveGeometry();
    repaint();
}

void TagWidget::paintEvent(QPaintEvent *event)
{
}
