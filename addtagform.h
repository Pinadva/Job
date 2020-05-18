#ifndef ADDTAGFORM_H
#define ADDTAGFORM_H

#include "settingssingleton.h"
#include "tagkeyeditwidget.h"
#include "taglistwidget.h"
#include "tagvalueeditwidget.h"

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

private:
    Ui::AddTagForm *ui;
    TagListWidget<TagKeyEditWidget> *tagList = nullptr;
    //    TagListWidget<TagValueEditWidget> *tagList = nullptr;
};

#endif // ADDTAGFORM_H
