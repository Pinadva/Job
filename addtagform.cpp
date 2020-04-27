#include "addtagform.h"
#include "ui_addtagform.h"

AddTagForm::AddTagForm(QWidget *parent) : QDialog(parent), ui(new Ui::AddTagForm)
{
    ui->setupUi(this);
    loadTags();
}

AddTagForm::~AddTagForm()
{
    delete ui;
}

void AddTagForm::on_buttonBox_accepted()
{
}

void AddTagForm::addTag()
{
    TagWidget *tag = new TagWidget(this);

    QListWidgetItem *item = new QListWidgetItem(ui->tagList);
    item->setSizeHint(tag->sizeHint());
    ui->tagList->setItemWidget(item, tag);
    ui->tagList->addItem(item);
}

void AddTagForm::addTag(TagWidget *tag)
{
    QListWidgetItem *item = new QListWidgetItem(ui->tagList);
    item->setSizeHint(tag->sizeHint());
    ui->tagList->setItemWidget(item, tag);
    ui->tagList->addItem(item);
}

void AddTagForm::removeTag(QListWidgetItem *item)
{
    ui->tagList->removeItemWidget(item);
}

void AddTagForm::saveTags()
{
    qDebug() << "saveTags";
    QHash<QString, QString> extra_exif;
    qDebug() << "count" << ui->tagList->count();
    for (int i = 0; i < ui->tagList->count(); ++i)
    {
        qDebug() << "1";
        QListWidgetItem *item = ui->tagList->item(i);
        qDebug() << "2";
        qDebug() << "item children" << item;
        QWidget *tag_wgt = ui->tagList->itemWidget(item);
        qDebug() << "3";
        auto tag_sub_wgts = tag_wgt->children();
        qDebug() << "4";
        QLineEdit *ldt = qobject_cast<QLineEdit *>(tag_sub_wgts[1]);
        qDebug() << "5";
        QComboBox *cbx = qobject_cast<QComboBox *>(tag_sub_wgts[2]);
        qDebug() << "6";

        extra_exif.insert(ldt->text(), cbx->currentText());
        qDebug() << "7";

        qDebug() << "tag =" << tag_sub_wgts;
        qDebug() << "tag cbx field =" << cbx->currentText();
        qDebug() << "tag ldt field =" << ldt->text();
    }
    qDebug() << "8";
    SettingsSingleton::getInstance().setExtraExif(extra_exif);
    qDebug() << "9";
}

void AddTagForm::loadTags()
{
    qDebug() << "loadTags";
    QHash<QString, QString> extra_exif = SettingsSingleton::getInstance().getExtraExif();
    for (auto iter = extra_exif.begin(); iter != extra_exif.end(); ++iter)
    {
        TagWidget *tag = new TagWidget(this);
        tag->setShortName(iter.key());
        tag->setExifName(iter.value());
        addTag(tag);
    }
}

void AddTagForm::accept()
{
    saveTags();
    close();
}

void AddTagForm::on_button_clicked()
{
    addTag();
}

void AddTagForm::on_pushButton_clicked()
{
    // removeTag();
}
