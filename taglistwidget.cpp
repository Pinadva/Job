#include "taglistwidget.h"

TagListWidget::TagListWidget(QWidget *parent) : QListWidget(parent)
{
}

// void TagListWidget::addTag()
//{
//    TagListWidget::T *tag = new T(this);
//    connect(tag, &T::checkValid, this, &AddTagForm::isValid);
//    connect(tag, SIGNAL(removeTag(QPoint)), this, SLOT(removeTag(QPoint)));
//    QListWidgetItem *item = new QListWidgetItem(ui->tagList);
//    item->setSizeHint(tag->sizeHint());
//    this->setItemWidget(item, tag);
//    this->addItem(item);
//}

// template <typename T>
// void TagListWidget::addTag(TagKeyEditWidget *)
//{
//}

// template <typename T>
// void TagListWidget::addTagTest(T *)
//{

//}

// template <typename T>
// void TagListWidget::saveTags()
//{
//}

// template <typename T>
// void TagListWidget::removeTag()
//{
//}

// template <typename T>
// void TagListWidget::loadTags()
//{
//}

// template <typename T>
// void TagListWidget::addTag(T *tag)
//{
//    //    connect(tag, &T::checkValid, this, &AddTagForm::isValid);
//    //    connect(tag, SIGNAL(removeTag(QPoint)), this, SLOT(removeTag(QPoint)));
//    QListWidgetItem *item = new QListWidgetItem(this);
//    item->setSizeHint(tag->sizeHint());
//    this->setItemWidget(item, tag);
//    this->addItem(item);
//}
