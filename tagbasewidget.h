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
    virtual QPair<QString, QString> getData() = 0;
    virtual bool isValid()                    = 0;

public slots:
    void setShortName(const QString &);
    void setRemoveBtn();
    void sendRemoveTag();
signals:
    void checkValid();
    void removeTag(QPoint);

public:
    QLineEdit *short_name_lineEdit = nullptr;
    QPushButton *remove_btn        = nullptr;
    QLayout *layout                = nullptr;

    int widget_height;
};

#endif // TAGBASEWIDGET_H
