#include "addcomment.h"
#include "ui_addcomment.h"

AddComment::AddComment(QWidget *parent) : QDialog(parent), ui(new Ui::AddComment)
{
    ui->setupUi(this);
}

AddComment::~AddComment()
{
    delete ui;
}

void AddComment::setPhotoPresenter(PhotoPresenter *presenter)
{
    qDebug() << "presenter =" << presenter;
    this->photo_presenter = presenter;
}

void AddComment::save()
{
    QString text = this->ui->plainTextEdit->toPlainText();
    photo_presenter->setComment(text);

    QFile comment(SettingsSingleton::getInstance().getPath() + "/comment.txt");
    comment.open(QFile::WriteOnly);
    QByteArray bytes = QByteArray::fromStdString(text.toStdString());
    comment.write(bytes);
    comment.close();

    close();
    emit valueChanged();
}

void AddComment::load()
{
    qDebug() << "bug1";
    qDebug() << photo_presenter;
    QString text = photo_presenter->getComment();
    qDebug() << "bug2";
    this->ui->plainTextEdit->setPlainText(text);
    qDebug() << "bug3";
}

void AddComment::accept()
{
    save();
}
