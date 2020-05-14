#include "addtagform.h"
#include "ui_addtagform.h"

AddTagForm::AddTagForm(QWidget *parent) : QDialog(parent), ui(new Ui::AddTagForm)
{
    ui->setupUi(this);
    loadTags();

    TagWidget *t = new TagWidget();
    connect(t, &TagWidget::checkValid, this, &AddTagForm::isValid);
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
    connect(tag, &TagWidget::checkValid, this, &AddTagForm::isValid);
    connect(tag, &TagWidget::removeTag, this, &AddTagForm::removeTag);
    QListWidgetItem *item = new QListWidgetItem(ui->tagList);
    item->setSizeHint(tag->sizeHint());
    ui->tagList->setItemWidget(item, tag);
    ui->tagList->addItem(item);
}

void AddTagForm::addTag(TagWidget *tag)
{
    connect(tag, &TagWidget::checkValid, this, &AddTagForm::isValid);
    connect(tag, &TagWidget::removeTag, this, &AddTagForm::removeTag);
    QListWidgetItem *item = new QListWidgetItem(ui->tagList);
    item->setSizeHint(tag->sizeHint());
    ui->tagList->setItemWidget(item, tag);
    ui->tagList->addItem(item);
}

void AddTagForm::removeTag(QPoint p)
{
    qDebug() << "addtag removetag" << p;
    auto current_tag = ui->tagList->itemAt(p);
    auto row         = ui->tagList->row(current_tag);
    delete ui->tagList->takeItem(row);
}

void AddTagForm::saveTags()
{
    qDebug() << "saveTags";
    QList<QHash<QString, QString>> extra_exif;
    for (int i = 0; i < ui->tagList->count(); ++i)
    {
        QListWidgetItem *item    = ui->tagList->item(i);
        QWidget *tag_wgt         = ui->tagList->itemWidget(item);
        QObjectList tag_sub_wgts = tag_wgt->children();
        QLineEdit *ldt           = qobject_cast<QLineEdit *>(tag_sub_wgts[1]);
        QComboBox *cbx           = qobject_cast<QComboBox *>(tag_sub_wgts[2]);

        extra_exif.append(QHash<QString, QString> {{ldt->text(), cbx->currentText()}});
    }
    SettingsSingleton::getInstance().setExtraExif(extra_exif);
}

void AddTagForm::loadTags()
{
    qDebug() << "loadTags";
    QList<QHash<QString, QString>> tags = SettingsSingleton::getInstance().getExtraExif();
    for (auto item : tags)
    {
        TagWidget *tag = new TagWidget(this);
        tag->setShortName(item.begin().key());
        tag->setExifName(item.begin().value());
        addTag(tag);
    }
}

void AddTagForm::accept()
{
    if (isValid())
    {
        saveTags();
        close();
    }
}

bool AddTagForm::isValid()
{
    bool isValid = true;
    for (int i = 0; i < ui->tagList->count(); ++i)
    {
        QListWidgetItem *item    = ui->tagList->item(i);
        QWidget *tag_wgt         = ui->tagList->itemWidget(item);
        QObjectList tag_sub_wgts = tag_wgt->children();
        QLineEdit *ldt           = qobject_cast<QLineEdit *>(tag_sub_wgts[1]);
        QComboBox *cbx           = qobject_cast<QComboBox *>(tag_sub_wgts[2]);
        if (cbx->findText(cbx->currentText()) == -1 or ldt->text().isEmpty())
        {
            isValid = false;
            QColor color;
            color.setRgb(255, 102, 102);
            item->setBackground(color);
        }
        else
            item->setBackground(Qt::white);
    }
    return isValid;
}

void AddTagForm::on_button_clicked()
{
    addTag();
}

void AddTagForm::on_pushButton_clicked()
{
}
