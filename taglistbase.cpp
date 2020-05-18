#include "taglistbase.h"

TagListBase::TagListBase(QWidget *parent) : QListWidget(parent)
{
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
