#include "tagkeyeditlist.h"

TagKeyEditList::TagKeyEditList(QString tag_kind, QString file_name, QWidget *parent) : TagListBase(file_name, parent)
{
    this->tag_kind = tag_kind;
}

void TagKeyEditList::save()
{
    qDebug() << "taglist saveTags";
    QList<QHash<QString, QString>> extra_exif;
    for (int i = 0; i < this->count(); ++i)
    {
        QListWidgetItem *item        = this->item(i);
        QWidget *tag_wgt             = this->itemWidget(item);
        TagKeyEdit *tag              = dynamic_cast<TagKeyEdit *>(tag_wgt);
        QPair<QString, QString> data = tag->getData();

        extra_exif.append(QHash<QString, QString> {{data.first, data.second}});
    }
    SettingsSingleton::getInstance().setExtraExif(extra_exif, this->tag_kind);
}

void TagKeyEditList::loadTags()
{
    qDebug() << "loadTags";
    this->clear();
    QList<QHash<QString, QString>> tags = SettingsSingleton::getInstance().getExtraExif(this->tag_kind);
    for (auto item : tags)
    {
        TagKeyEdit *tag = new TagKeyEdit(this);
        qDebug() << item.begin().key() << item.begin().value();
        tag->setData(QPair<QString, QString>(item.begin().key(), item.begin().value()));
        addTag(tag);
    }
}
