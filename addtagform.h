#ifndef ADDTAGFORM_H
#define ADDTAGFORM_H

#include "tagwidget.h"

#include <QDialog>

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

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddTagForm *ui;
    TagWidget *tag = nullptr;
};

#endif // ADDTAGFORM_H
