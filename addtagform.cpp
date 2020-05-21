#include "addtagform.h"
#include "ui_addtagform.h"

AddTagForm::AddTagForm(QWidget *parent) : QDialog(parent), ui(new Ui::AddTagForm)
{
    ui->setupUi(this);

    ui->testBtn->setVisible(false);

    tagList = new TagKeyEditList("common_extra");
    //    tagList = new TagListWidget<TagValueEditWidget>();
    ui->verticalLayout->addWidget(tagList);

    tagList->loadTags();
}

AddTagForm::~AddTagForm()
{
    delete ui;
}

void AddTagForm::chooseKeyAction(QString key)
{
    if (key == "\u000E") // ctrl + n
        tagList->addTag(new TagKeyEditWidget());
    else if (key == "\u007F") // delete
        tagList->removeTag();
}

void AddTagForm::save()
{
    if (tagList->isValid())
    {
        tagList->saveTags();
        close();
    }
}

void AddTagForm::on_buttonBox_accepted()
{
    save();
}

void AddTagForm::on_addBtn_clicked()
{
    tagList->addTag(new TagKeyEditWidget());
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
    tagList->loadTags();
}

void AddTagForm::accept()
{
    save();
}
