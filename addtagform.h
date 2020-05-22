#ifndef ADDTAGFORM_H
#define ADDTAGFORM_H

#include "photopresenter.h"
#include "photosegment.h"
#include "settingssingleton.h"
#include "tagkeyedit.h"
#include "tagkeyeditlist.h"
#include "tagmediator.h"
#include "tagvalueedit.h"
#include "tagvalueeditlist.h"

#include <QDialog>
#include <QLayout>
#include <QListWidget>
#include <QTableWidget>
#include <QTableWidgetItem>

namespace Ui
{
class AddTagForm;
}

class AddTagForm : public QDialog
{
    Q_OBJECT

public:
    explicit AddTagForm(QWidget *parent = nullptr);
    ~AddTagForm();

    void chooseKeyAction(QString);
    void setPhotoPresenter(PhotoPresenter *);

public slots:
    void accept() override;
    void save();
    void load();

private slots:
    void on_buttonBox_accepted();
    void on_addBtn_clicked();
    void on_testBtn_clicked();

protected:
    void keyReleaseEvent(QKeyEvent *event) override;
    void showEvent(QShowEvent *event) override;

signals:
    void valuesChanged();

private:
    Ui::AddTagForm *ui;
    //    TagKeyEditList *tagList = nullptr;
    TagValueEditList *tagList       = nullptr;
    PhotoPresenter *photo_presenter = nullptr;
};

#endif // ADDTAGFORM_H
