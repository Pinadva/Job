#ifndef CHANGETAGVALUEFORM_H
#define CHANGETAGVALUEFORM_H

#include "photopresenter.h"
#include "photosegment.h"
#include "settingssingleton.h"
#include "tagkeyedit.h"
#include "tagkeyeditlist.h"
#include "tagvalueedit.h"
#include "tagvalueeditlist.h"

#include <QDialog>

namespace Ui
{
class ChangeTagValueForm;
}

class ChangeTagValueForm : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeTagValueForm(QWidget *parent = nullptr);
    ~ChangeTagValueForm();

    void chooseKeyAction(QString);
    void setPhotoPresenter(PhotoPresenter *);

public slots:
    void accept() override;
    void save();
    void load();

private slots:
    void on_buttonBox_accepted();
    void on_testBtn_clicked();

protected:
    void keyReleaseEvent(QKeyEvent *event) override;
    void showEvent(QShowEvent *event) override;

signals:
    void valuesChanged(QString text = "", int = 0);

private:
    Ui::ChangeTagValueForm *ui;
    //    TagKeyEditList *tagList = nullptr;
    TagValueEditList *tag_list      = nullptr;
    PhotoPresenter *photo_presenter = nullptr;
};

#endif // CHANGETAGVALUEFORM_H
