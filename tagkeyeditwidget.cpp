#include "tagkeyeditwidget.h"

TagKeyEditWidget::TagKeyEditWidget(QWidget *parent) : TagBaseWidget(parent)
{
    this->exif_name = new QComboBox();
    setExifName();

    layout->addWidget(short_name_lineEdit);
    layout->addWidget(exif_name);
    layout->addWidget(remove_btn);
    setLayout(layout);
}

void TagKeyEditWidget::setExifName()
{
    exif_name->addItems(extra.getExtra());
    exif_name->setEditable(true);
    QCompleter *c = new QCompleter(extra.getExtra(), exif_name);
    c->setCaseSensitivity(Qt::CaseInsensitive);
    exif_name->setCompleter(c);
}

void TagKeyEditWidget::setExifName(const QString &cur_text)
{
    setExifName();
    exif_name->setCurrentIndex(exif_name->findText(cur_text));
}

int TagKeyEditWidget::test()
{
    return 123;
}

QPair<QString, QString> TagKeyEditWidget::getText()
{
    QPair<QString, QString> pair(short_name_lineEdit->text(), exif_name->currentText());
    return pair;
}
