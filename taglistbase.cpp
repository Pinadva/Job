#include "taglistbase.h"

TagListBase::TagListBase(QString file_name, QWidget *parent) : QListWidget(parent)
{
    this->file_name = file_name;
}

void TagListBase::addTag(TagBaseWidget *tag)
{
    QListWidgetItem *item = new QListWidgetItem(this);
    connect(tag, SIGNAL(checkValid()), this, SLOT(isValid()));
    connect(tag, SIGNAL(removeTag(QPoint)), this, SLOT(removeTag(QPoint)));
    item->setSizeHint(tag->sizeHint());
    this->setItemWidget(item, tag);
    this->addItem(item);
}

void TagListBase::removeTag()
{
    if (!this->selectedItems().isEmpty())
    {
        auto item = this->selectedItems().first();
        int row   = this->row(item);
        delete this->takeItem(row);
    }
}

void TagListBase::removeTag(QPoint p)
{
    qDebug() << "taglist removetag" << p;
    auto current_tag = this->itemAt(p);
    int row          = this->row(current_tag);
    delete this->takeItem(row);
}

bool TagListBase::isValid()
{
    bool isValid = true;
    for (int i = 0; i < this->count(); ++i)
    {
        QListWidgetItem *item = this->item(i);
        QWidget *tag_wgt      = this->itemWidget(item);
        TagBaseWidget *tag    = dynamic_cast<TagBaseWidget *>(tag_wgt);
        qDebug() << tag->isValid();
        if (!tag->isValid())
        {
            isValid = false;
            QColor color;
            color.setRgb(255, 102, 102);
            item->setBackground(color);
        }
        else
            item->setBackground(Qt::white);
    }
    return isValid;
}
