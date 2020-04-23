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
