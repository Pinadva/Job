#include "changetagvalueform.h"
#include "ui_changetagvalueform.h"

ChangeTagValueForm::ChangeTagValueForm(QWidget *parent) : QDialog(parent), ui(new Ui::ChangeTagValueForm)
{
    ui->setupUi(this);

    //    ui->testBtn->setVisible(false);

    //    tagList = new TagKeyEditList("common_extra");
    tagList = new TagValueEditList();
    //    tagList->setEmptyTags();

    ui->verticalLayout->addWidget(tagList);
    //    this->load();
}

ChangeTagValueForm::~ChangeTagValueForm()
{
    delete ui;
}

void ChangeTagValueForm::chooseKeyAction(QString key)
{
    //    if (key == "\u000E") // ctrl + n
    //        tagList->addTag(new TagKeyEdit());
    //    else if (key == "\u007F") // delete
    //        tagList->removeTag();
}

void ChangeTagValueForm::setPhotoPresenter(PhotoPresenter *presenter)
{
    this->photo_presenter = presenter;
}

void ChangeTagValueForm::save()
{
    tagList->save();

    for (int i = 0; i < 4; ++i)
    {
        auto item              = ui->tags_gridLayout->itemAtPosition(i / 4, i % 4)->widget();
        TagValueEditList *tags = dynamic_cast<TagValueEditList *>(item);
        tags->save();
    }
    close();
    emit valuesChanged();
}

void ChangeTagValueForm::load()
{
    if (photo_presenter->getPhotos().size() > 0)
    {
        QHash<int, PhotoSegment> photos = photo_presenter->getPhotos();
        if (photos.size() > 0)
        {
            auto photo_segment = photos[0];
            tagList->setEmptyTags(photo_segment.common_empty);
            tagList->load();
        }
        for (int i = 0; i < photos.size(); ++i)
        {
            PhotoSegment photo     = photos[i];
            TagValueEditList *tags = new TagValueEditList();
            tags->setEmptyTags(photo.unique_empty);
            tags->load();
            ui->tags_gridLayout->addWidget(tags, i / 4, i % 4);
        }
    }
}

void ChangeTagValueForm::on_buttonBox_accepted()
{
    save();
}

void ChangeTagValueForm::on_testBtn_clicked()
{
}

void ChangeTagValueForm::keyReleaseEvent(QKeyEvent *event)
{
    event->accept();
    qDebug() << event->text();
    chooseKeyAction(event->text());
}

void ChangeTagValueForm::showEvent(QShowEvent *event)
{
    event->accept();
    this->load();
}

void ChangeTagValueForm::accept()
{
    save();
}
