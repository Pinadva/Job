#ifndef TAGLISTWIDGET_H
#define TAGLISTWIDGET_H

#include <QListWidget>
#include <QObject>
#include <QWidget>

#include "settingssingleton.h"
#include "tagkeyeditwidget.h"
#include "taglistbase.h"

template <typename T>
class TagListWidget : public TagListBase
{
public:
    explicit TagListWidget(QWidget *parent = nullptr) : TagListBase(parent)
    {
    }

public:
    void addTag();
    void addTag(T *tag);
    void saveTags();
    void loadTags();
    bool isValid();

private:
};

template <typename T>
void TagListWidget<T>::addTag()
{
    T *tag = new T(this);
    connect(tag, &T::checkValid, this, &TagListWidget<T>::isValid);
    connect(tag, SIGNAL(removeTag(QPoint)), this, SLOT(removeTag(QPoint)));
    QListWidgetItem *item = new QListWidgetItem(this);
    item->setSizeHint(tag->sizeHint());
    this->setItemWidget(item, tag);
    this->addItem(item);
}

template <typename T>
void TagListWidget<T>::addTag(T *tag)
{
    QListWidgetItem *item = new QListWidgetItem(this);
    connect(tag, &T::checkValid, this, &TagListWidget<T>::isValid);
    connect(tag, SIGNAL(removeTag(QPoint)), this, SLOT(removeTag(QPoint)));
    item->setSizeHint(tag->sizeHint());
    this->setItemWidget(item, tag);
    this->addItem(item);
}

template <typename T>
void TagListWidget<T>::saveTags()
{
    qDebug() << "taglist saveTags";
    QList<QHash<QString, QString>> extra_exif;
    for (int i = 0; i < this->count(); ++i)
    {
        QListWidgetItem *item        = this->item(i);
        QWidget *tag_wgt             = this->itemWidget(item);
        T *tag                       = dynamic_cast<T *>(tag_wgt);
        QPair<QString, QString> data = tag->getData();

        extra_exif.append(QHash<QString, QString> {{data.first, data.second}});
    }
    SettingsSingleton::getInstance().setExtraExif(extra_exif);
}

template <typename T>
void TagListWidget<T>::loadTags()
{
    qDebug() << "loadTags";
    QList<QHash<QString, QString>> tags = SettingsSingleton::getInstance().getExtraExif();
    for (auto item : tags)
    {
        T *tag = new T(this);
        tag->setShortName(item.begin().key());
        tag->setExifName(item.begin().value());
        addTag(tag);
    }
}

template <typename T>
bool TagListWidget<T>::isValid()
{
    bool isValid = true;
    for (int i = 0; i < this->count(); ++i)
    {
        QListWidgetItem *item = this->item(i);
        QWidget *tag_wgt      = this->itemWidget(item);
        T *t                  = dynamic_cast<T *>(tag_wgt);

        if (!t->isValid())
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
#endif // TAGLISTWIDGET_H
