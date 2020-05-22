#include "tagvalueedit.h"

TagValueEdit::TagValueEdit(QWidget *parent) : TagBaseWidget(parent)
{
    this->value_lineEdit = new QLineEdit();
    connect(value_lineEdit, &QLineEdit::textChanged, this, &TagValueEdit::checkValid);
    layout->addWidget(short_name_lineEdit);
    layout->addWidget(value_lineEdit);
    //    layout->addWidget(remove_btn);
    setLayout(layout);
}

void TagValueEdit::setValueLineEdit(const QString &text)
{
    value_lineEdit->setText(text);
    value_lineEdit->setPlaceholderText("Exif.Photo.FocalLength");
    value_lineEdit->setClearButtonEnabled(true);
}

void TagValueEdit::setData()
{
    setShortName("");
    short_name_lineEdit->setReadOnly(true);
    setValueLineEdit("");
}

void TagValueEdit::setData(QPair<QString, QString> data)
{
    setShortName(data.first);
    short_name_lineEdit->setReadOnly(true);
    setValueLineEdit(data.second);
}

QPair<QString, QString> TagValueEdit::getData()
{
    QPair<QString, QString> pair(short_name_lineEdit->text(), value_lineEdit->text());
    return pair;
}

bool TagValueEdit::isValid()
{
    return !(short_name_lineEdit->text().isEmpty() or value_lineEdit->text().isEmpty());
}
