#include "tagwidget.h"

TagWidget::TagWidget(QWidget *parent) : QWidget(parent)
{
    short_name    = new QLineEdit();
    exif_name     = new QComboBox();
    delete_button = new QPushButton();
    layout        = new QHBoxLayout();

    layout->addWidget(short_name);
    layout->addWidget(exif_name);
    layout->addWidget(delete_button);

    this->setLayout(layout);
    setShortName();
    setExifName();
    setDeleteButton();
}

void TagWidget::setShortName()
{
}

void TagWidget::setExifName()
{
    exif_name->addItems(extra.getExtra());

    delete_button->saveGeometry();
}

void TagWidget::setDeleteButton()
{
    QPixmap pm(20, 20);
    pm.fill(Qt::red);
    QIcon icon;
    icon.addPixmap(pm);
    delete_button->setIcon(icon);

    repaint();
}

void TagWidget::paintEvent(QPaintEvent *event)
{
}

void TagWidget::keyReleaseEvent(QKeyEvent *event)
{
}

void TagWidget::keyPressEvent(QKeyEvent *event)
{
}
