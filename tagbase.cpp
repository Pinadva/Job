#include "tagbase.h"

TagBaseWidget::TagBaseWidget(QWidget *parent) : QWidget(parent)
{
    short_name_lineEdit = new QLineEdit();
    remove_btn          = new QPushButton();
    layout              = new QHBoxLayout();

    setRemoveBtn();

    connect(short_name_lineEdit, SIGNAL(textChanged(QString)), SIGNAL(checkValid()));
    connect(remove_btn, &QAbstractButton::clicked, this, &TagBaseWidget::sendRemoveTag);
}

void TagBaseWidget::setShortName(const QString &text)
{
    short_name_lineEdit->setText(text);
    short_name_lineEdit->setPlaceholderText("Short name");
    short_name_lineEdit->setClearButtonEnabled(true);
}

void TagBaseWidget::setRemoveBtn()
{
    QPixmap pm(20, 20);
    pm.fill(Qt::red);
    QIcon icon;
    icon.addPixmap(pm);
    remove_btn->setIcon(icon);

    repaint();
}

void TagBaseWidget::sendRemoveTag()
{
    emit removeTag(this->pos());
}
