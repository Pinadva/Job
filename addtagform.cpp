#include "addtagform.h"
#include "ui_addtagform.h"

AddTagForm::AddTagForm(QWidget *parent) : QDialog(parent), ui(new Ui::AddTagForm)
{
    ui->setupUi(this);
}

AddTagForm::~AddTagForm()
{
    delete ui;
}

void AddTagForm::on_buttonBox_accepted()
{
}

void AddTagForm::addTag()
{
    TagWidget *tag1 = new TagWidget(this);

    QListWidgetItem *item = new QListWidgetItem(ui->tagList);
    item->setSizeHint(tag1->sizeHint());
    ui->tagList->setItemWidget(item, tag1);
    ui->tagList->addItem(item);
    // ui->tags->addWidget(tag1);
}

void AddTagForm::deleteTag()
{
}

void AddTagForm::on_button_clicked()
{
    deleteTag();
    addTag();
}
