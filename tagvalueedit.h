#ifndef TAGVALUEEDITWIDGET_H
#define TAGVALUEEDITWIDGET_H

#include <QObject>
#include <QWidget>

#include "tagbase.h"

class TagValueEditWidget : public TagBaseWidget
{
    Q_OBJECT
public:
    explicit TagValueEditWidget(QWidget *parent = nullptr);

public slots:
    void setValueLineEdit(const QString &);

private:
    QLineEdit *value_lineEdit = nullptr;

    // TagBaseWidget interface
public:
    void setData() override;
    void setData(QPair<QString, QString>) override;
    QPair<QString, QString> getData() override;
    bool isValid() override;
};

#endif // TAGVALUEEDITWIDGET_H
