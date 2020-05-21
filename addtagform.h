#ifndef ADDTAGFORM_H
#define ADDTAGFORM_H

#include "settingssingleton.h"
#include "tagkeyedit.h"
#include "tagkeyeditlist.h"
#include "tagvalueedit.h"
#include "tagvalueeditlist.h"

#include <QDialog>
#include <QListWidget>

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

public slots:
    void accept() override;
    void save();

private slots:
    void on_buttonBox_accepted();
    void on_addBtn_clicked();
    void on_testBtn_clicked();

protected:
    void keyReleaseEvent(QKeyEvent *event) override;
    void showEvent(QShowEvent *event) override;

private:
    Ui::AddTagForm *ui;
    //    TagKeyEditList *tagList = nullptr;
    TagValueEditList *tagList = nullptr;
};

#endif // ADDTAGFORM_H
