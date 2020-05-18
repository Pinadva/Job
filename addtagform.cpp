#include "addtagform.h"
#include "ui_addtagform.h"

AddTagForm::AddTagForm(QWidget *parent) : QDialog(parent), ui(new Ui::AddTagForm)
{
    ui->setupUi(this);

    //    ui->testBtn->setVisible(false);

    tagList = new TagListWidget<TagKeyEditWidget>();
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
        tagList->addTag();
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
    tagList->addTag();
}

void AddTagForm::on_testBtn_clicked()
{
    // TagKeyEditWidget *t = new TagKeyEditWidget();
    //    TagValueEditWidget *t = new TagValueEditWidget();
    // ui->list->addTag(t);
}

void AddTagForm::keyReleaseEvent(QKeyEvent *event)
{
    event->accept();
    qDebug() << event->text();
    chooseKeyAction(event->text());
}

void AddTagForm::accept()
{
    save();
}
