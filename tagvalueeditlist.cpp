#include "tagvalueeditlist.h"

TagValueEditList::TagValueEditList(QString file_name, QWidget *parent) : TagListBase(file_name, parent)
{
}

void TagValueEditList::setPhotos(QHash<int, QString> &photos)
{
    this->photos = photos;
}

void TagValueEditList::setEmptyTags(QList<QPair<QString, QString> *> &empty_tags)
{
    this->empty_tags = empty_tags;
}

void TagValueEditList::saveTags()
{
    qDebug() << "taglist saveTags";
    if (empty_tags.length() > 0)
        for (int i = 0; i < this->count(); ++i)
        {
            QListWidgetItem *item        = this->item(i);
            QWidget *tag_wgt             = this->itemWidget(item);
            TagValueEdit *tag            = dynamic_cast<TagValueEdit *>(tag_wgt);
            QPair<QString, QString> data = tag->getData();

            if (i < this->empty_tags.length())
            {
                empty_tags[i]->first  = data.first;
                empty_tags[i]->second = data.second;
            }
        }
    for (auto item : empty_tags)
    {
        qDebug() << "item in empty tags = " << item->first << item->second;
    }
}

void TagValueEditList::loadTags()
{
    this->clear();
    qDebug() << empty_tags.length();
    if (empty_tags.length() > 0)
        for (auto item : empty_tags)
        {
            TagValueEdit *tag = new TagValueEdit(this);
            qDebug() << item->first << item->second;
            tag->setData(QPair<QString, QString>(item->first, item->second));
            addTag(tag);
        }
}
