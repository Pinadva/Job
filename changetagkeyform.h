#ifndef CHANGETAGKEYFORM_H
#define CHANGETAGKEYFORM_H

#include "photopresenter.h"
#include "settingssingleton.h"
#include "tagkeyedit.h"
#include "tagkeyeditlist.h"

#include <QDialog>

namespace Ui
{
class ChangeTagKeyForm;
}

class ChangeTagKeyForm : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeTagKeyForm(QWidget *parent = nullptr);
    ~ChangeTagKeyForm();
    void setPresenter(PhotoPresenter *);

public slots:
    void accept() override;
    void save();
    void load();

private slots:

    void on_add_unique_pushButton_clicked();
    void on_clear_unique_pushButton_clicked();
    void on_add_common_pushButton_clicked();
    void on_clear_common_pushButton_clicked();

signals:

private:
    Ui::ChangeTagKeyForm *ui;

    TagKeyEditList *unique          = nullptr;
    TagKeyEditList *common          = nullptr;
    PhotoPresenter *photo_presenter = nullptr;

    // QWidget interface
protected:
    void showEvent(QShowEvent *event) override;
};

#endif // CHANGETAGKEYFORM_H
