#include "tagvalueeditwidget.h"

TagValueEditWidget::TagValueEditWidget(QWidget *parent) : TagBaseWidget(parent)
{
    this->value_lineEdit = new QLineEdit();
    connect(value_lineEdit, &QLineEdit::textChanged, this, &TagValueEditWidget::checkValid);
    layout->addWidget(short_name_lineEdit);
    layout->addWidget(value_lineEdit);
    layout->addWidget(remove_btn);
    setLayout(layout);
}

void TagValueEditWidget::setValueLineEdit(const QString &text)
{
    value_lineEdit->setText(text);
    value_lineEdit->setPlaceholderText("Value");
    value_lineEdit->setClearButtonEnabled(true);
}

void TagValueEditWidget::setData()
{
    setShortName("");
    setValueLineEdit("");
}

void TagValueEditWidget::setData(QPair<QString, QString> data)
{
    setShortName(data.first);
    setValueLineEdit(data.second);
}

QPair<QString, QString> TagValueEditWidget::getData()
{
    QPair<QString, QString> pair(short_name_lineEdit->text(), value_lineEdit->text());
    return pair;
}

bool TagValueEditWidget::isValid()
{
    return !(short_name_lineEdit->text().isEmpty() or value_lineEdit->text().isEmpty());
}
