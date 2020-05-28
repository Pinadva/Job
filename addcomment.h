#ifndef ADDCOMMENT_H
#define ADDCOMMENT_H

#include "photopresenter.h"
#include "settingssingleton.h"

#include <QByteArray>
#include <QDialog>
#include <QFile>

namespace Ui
{
class AddComment;
}

class AddComment : public QDialog
{
    Q_OBJECT

public:
    explicit AddComment(QWidget *parent = nullptr);
    ~AddComment();
    void setPhotoPresenter(PhotoPresenter *);
    void save();
    void load();

private:
    Ui::AddComment *ui;

    PhotoPresenter *photo_presenter = nullptr;

signals:
    void valuesChanged(QString, int);

    // QDialog interface
public slots:
    void accept() override;
};

#endif // ADDCOMMENT_H
