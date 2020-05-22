#include "addtagform.h"
#include "ui_addtagform.h"

AddTagForm::AddTagForm(QWidget *parent) : QDialog(parent), ui(new Ui::AddTagForm)
{
    ui->setupUi(this);

    ui->testBtn->setVisible(false);

    //    tagList = new TagKeyEditList("common_extra");
    tagList = new TagValueEditList();
    //    tagList->setEmptyTags();
    ui->verticalLayout->addWidget(tagList);
    //    this->load();
}

AddTagForm::~AddTagForm()
{
    delete ui;
}

void AddTagForm::chooseKeyAction(QString key)
{
    if (key == "\u000E") // ctrl + n
        tagList->addTag(new TagKeyEdit());
    else if (key == "\u007F") // delete
        tagList->removeTag();
}

void AddTagForm::setPhotoPresenter(PhotoPresenter *presenter)
{
    this->photo_presenter = presenter;
}

void AddTagForm::save()
{
    if (tagList->isValid())
    {
        tagList->saveTags();
        close();
        emit valuesChanged();
    }
}

void AddTagForm::load()
{
    if (photo_presenter->getPhotos().size() > 0)
    {
        QHash<int, PhotoSegment> photos = photo_presenter->getPhotos();
        if (photos.size() > 0)
        {
            auto photo_segment = photos[0];
            tagList->setEmptyTags(photo_segment.common_empty);
            tagList->loadTags();
        }
    }
}

void AddTagForm::on_buttonBox_accepted()
{
    save();
}

void AddTagForm::on_addBtn_clicked()
{
    tagList->addTag(new TagKeyEdit());
}

void AddTagForm::on_testBtn_clicked()
{
}

void AddTagForm::keyReleaseEvent(QKeyEvent *event)
{
    event->accept();
    qDebug() << event->text();
    chooseKeyAction(event->text());
}

void AddTagForm::showEvent(QShowEvent *event)
{
    event->accept();
    this->load();
}

void AddTagForm::accept()
{
    save();
}
