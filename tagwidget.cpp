#include "tagwidget.h"

TagWidget::TagWidget(QWidget *parent) : QWidget(parent)
{
    short_name    = new QLineEdit();
    exif_name     = new QComboBox();
    remove_button = new QPushButton();
    layout        = new QHBoxLayout();

    setExifName();
    setDeleteButton();

    layout->addWidget(short_name);
    layout->addWidget(exif_name);
    layout->addWidget(remove_button);

    setLayout(layout);

    connect(short_name, SIGNAL(textChanged(QString)), SIGNAL(checkValid()));
    connect(exif_name, SIGNAL(editTextChanged(QString)), SIGNAL(checkValid()));
    connect(remove_button, &QAbstractButton::clicked, this, &TagWidget::sendRemoveTag);
}

void TagWidget::setShortName(const QString &text)
{
    short_name->setText(text);
    short_name->setClearButtonEnabled(true);
}

void TagWidget::setExifName()
{
    exif_name->addItems(extra.getExtra());
    exif_name->setEditable(true);
    QCompleter *c = new QCompleter(extra.getExtra(), exif_name);
    c->setCaseSensitivity(Qt::CaseInsensitive);
    exif_name->setCompleter(c);
}

void TagWidget::setExifName(const QString &cur_text)
{
    setExifName();
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

void TagWidget::sendRemoveTag()
{
    qDebug() << this;
    qDebug() << this->parent();
    qDebug() << this->parent()->parent();
    qDebug() << this->parent()->parent()->parent();
    qDebug() << "tagwid sendrmtag" << this->pos();
    removeTag(this->pos());
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
