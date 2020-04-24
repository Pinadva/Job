#include "addtagform.h"
#include "ui_addtagform.h"

AddTagForm::AddTagForm(QWidget *parent) : QDialog(parent), ui(new Ui::AddTagForm)
{
    tag = new TagWidget(this);
    ui->setupUi(this);
    ui->tags->addWidget(tag);
}

AddTagForm::~AddTagForm()
{
    delete ui;
}

void AddTagForm::on_buttonBox_accepted()
{
}

void AddTagForm::addTagWidget()
{
    //    TagWidget *t = new TagWidget(this);
    //    ui->tags->addWidget(t);
    //    repaint();
}
