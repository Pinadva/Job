#include "tagvalueeditwidget.h"

TagValueEditWidget::TagValueEditWidget(QWidget *parent) : TagBaseWidget(parent)
{
    this->value_lineEdit = new QLineEdit();
    setValueLineEdit();

    layout->addWidget(short_name_lineEdit);
    layout->addWidget(value_lineEdit);
    layout->addWidget(remove_btn);
    setLayout(layout);
}

void TagValueEditWidget::setValueLineEdit()
{
    value_lineEdit->setPlaceholderText("Value");
}

QPair<QString, QString> TagValueEditWidget::getData()
{
    QPair<QString, QString> pair(short_name_lineEdit->text(), value_lineEdit->text());
    return pair;
}

bool TagValueEditWidget::isValid()
{
    return !(short_name_lineEdit->text().isEmpty() and value_lineEdit->text().isEmpty());
}
