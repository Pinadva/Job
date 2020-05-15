#ifndef TAGLISTWIDGET_H
#define TAGLISTWIDGET_H

#include <QListWidget>
#include <QObject>
#include <QWidget>

#include "settingssingleton.h"
#include "tagkeyeditwidget.h"

class TagListWidget : public QListWidget
{
    Q_OBJECT
public:
    explicit TagListWidget(QWidget *parent = nullptr);

    template <typename T>
    void addTag(T *tag = nullptr)
    {
        QListWidgetItem *item = new QListWidgetItem(this);
        item->setSizeHint(tag->sizeHint());
        this->setItemWidget(item, tag);
        this->addItem(item);
    }
    //    template <typename T>
    //    void saveTags()
    //    {
    //        qDebug() << "saveTags";
    //        QList<QHash<QString, QString>> extra_exif;
    //        for (int i = 0; i < this->count(); ++i)
    //        {
    //            QListWidgetItem *item = this->item(i);
    //            QWidget *tag_parent   = this->itemWidget(item);

    //            T *tag_wgt                   = dynamic_cast<T *>(tag_parent);
    //            QPair<QString, QString> pair = tag_wgt->getText();
    //            extra_exif.append(QHash<QString, QString> {{pair.first, pair.second}});
    //            SettingsSingleton::getInstance().setExtraExif(extra_exif);
    //        }
    //    }
    //    void removeTag();
    //    void loadTags();

private:
};
#endif // TAGLISTWIDGET_H
