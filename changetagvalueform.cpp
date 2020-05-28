#include "changetagvalueform.h"
#include "ui_changetagvalueform.h"

ChangeTagValueForm::ChangeTagValueForm(QWidget *parent) : QDialog(parent), ui(new Ui::ChangeTagValueForm)
{
    ui->setupUi(this);
    //    ui->testBtn->setVisible(false);

    tag_list = new TagValueEditList();

    ui->verticalLayout->addWidget(tag_list);
    //    this->load();
}

ChangeTagValueForm::~ChangeTagValueForm()
{
    delete ui;
}

void ChangeTagValueForm::chooseKeyAction(QString key)
{
    if (key == "\u0012" or key == "r")
        this->load();
}

void ChangeTagValueForm::setPhotoPresenter(PhotoPresenter *presenter)
{
    this->photo_presenter = presenter;
}

void ChangeTagValueForm::save()
{
    if (tag_list->count() > 0)
    {
        tag_list->save();

        for (int i = 0; i < 4; ++i)
        {
            auto item              = ui->tags_gridLayout->itemAtPosition(i / 4, i % 4)->widget();
            TagValueEditList *tags = dynamic_cast<TagValueEditList *>(item);
            tags->save();
        }
        close();
        emit valuesChanged("Нажмите Ctrl+R или File->Reload чтобы применить изменения.", 0);
    }
    else
        close();
}

void ChangeTagValueForm::load()
{
    if (photo_presenter->getPhotos().size() > 0)
    {
        QHash<int, PhotoSegment> photos = photo_presenter->getPhotos();
        if (photos.size() > 0)
        {
            auto photo_segment = photos[0];
            tag_list->setEmptyTags(photo_segment.common_empty);
            tag_list->load();
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
}

void ChangeTagValueForm::showEvent(QShowEvent *event)
{
    event->accept();
    load();
}

void ChangeTagValueForm::accept()
{
    save();
}
