#ifndef ADDTAGFORM_H
#define ADDTAGFORM_H

#include "settingssingleton.h"
#include "tagwidget.h"

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

    void addTag();
    void addTag(TagWidget *);
    void removeTag(QListWidgetItem *);
    void saveTags();
    void loadTags();

public slots:
    void accept() override;

private slots:
    void on_buttonBox_accepted();
    void on_button_clicked();

    void on_pushButton_clicked();

private:
    Ui::AddTagForm *ui;

    // QDialog interface
};

#endif // ADDTAGFORM_H
