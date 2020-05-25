#include "changetagkeyform.h"
#include "ui_changetagkeyform.h"

ChangeTagKeyForm::ChangeTagKeyForm(QWidget *parent) : QDialog(parent), ui(new Ui::ChangeTagKeyForm)
{
    ui->setupUi(this);

    this->unique = new TagKeyEditList("unique_extra");
    this->common = new TagKeyEditList("common_extra");

    ui->tags_horizontalLayout->addWidget(unique);
    ui->tags_horizontalLayout->addWidget(common);
    this->load();
}

ChangeTagKeyForm::~ChangeTagKeyForm()
{
    delete ui;
}

void ChangeTagKeyForm::setPresenter(PhotoPresenter *presenter)
{
    this->photo_presenter = presenter;
}

void ChangeTagKeyForm::accept()
{
    this->save();
}

void ChangeTagKeyForm::save()
{
    if (unique->isValid() and common->isValid())
    {
        unique->save();
        common->save();
        close();
    }
}

void ChangeTagKeyForm::load()
{
    unique->load();
    common->load();
}

void ChangeTagKeyForm::on_add_unique_pushButton_clicked()
{
    unique->addTag(new TagKeyEdit());
}

void ChangeTagKeyForm::on_clear_unique_pushButton_clicked()
{
}

void ChangeTagKeyForm::on_add_common_pushButton_clicked()
{
    common->addTag(new TagKeyEdit());
}

void ChangeTagKeyForm::on_clear_common_pushButton_clicked()
{
}

void ChangeTagKeyForm::showEvent(QShowEvent *event)
{
    event->accept();
    this->load();
}
