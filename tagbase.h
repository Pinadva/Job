#ifndef TAGBASEWIDGET_H
#define TAGBASEWIDGET_H

#include <QComboBox>
#include <QCompleter>
#include <QDebug>
#include <QHBoxLayout>
#include <QKeyEvent>
#include <QLineEdit>
#include <QObject>
#include <QPainter>
#include <QPushButton>
#include <QSizePolicy>
#include <QWidget>

class TagBaseWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TagBaseWidget(QWidget *parent = nullptr);
    virtual void setData()                        = 0;
    virtual void setData(QPair<QString, QString>) = 0;
    virtual QPair<QString, QString> getData()     = 0;

public slots:
    virtual bool isValid()
    {
        return false;
    }

public slots:
    void setShortName(const QString &text = "");
    void setRemoveBtn();
    void sendRemoveTag();
signals:
    void checkValid();
    void removeTag(QPoint);

public:
    QLineEdit *short_name_lineEdit = nullptr;
    QPushButton *remove_btn        = nullptr;
    QLayout *layout                = nullptr;
};

#endif // TAGBASEWIDGET_H
