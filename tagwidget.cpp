#include "tagwidget.h"

TagWidget::TagWidget(QWidget *parent) : QWidget(parent)
{
    short_name    = new QLineEdit();
    exif_name     = new QComboBox();
    remove_button = new QPushButton();
    layout        = new QHBoxLayout();

    layout->addWidget(short_name);
    layout->addWidget(exif_name);
    layout->addWidget(remove_button);

    this->setLayout(layout);
    setExifName();
    setDeleteButton();
}

void TagWidget::setShortName(const QString &text)
{
    short_name->setText(text);
}

void TagWidget::setExifName()
{
    exif_name->addItems(extra.getExtra());
}

void TagWidget::setExifName(const QString &cur_text)
{
    exif_name->clear();
    exif_name->addItems(extra.getExtra());
    exif_name->setCurrentIndex(exif_name->findText(cur_text));
}

void TagWidget::setDeleteButton()
{
    QPixmap pm(20, 20);
    pm.fill(Qt::red);
    QIcon icon;
    icon.addPixmap(pm);
    remove_button->setIcon(icon);

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
