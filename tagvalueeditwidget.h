#ifndef TAGVALUEEDITWIDGET_H
#define TAGVALUEEDITWIDGET_H

#include <QObject>
#include <QWidget>

#include "tagbasewidget.h"

class TagValueEditWidget : public TagBaseWidget
{
    Q_OBJECT
public:
    explicit TagValueEditWidget(QWidget *parent = nullptr);

public slots:
    void setValueLineEdit();

private:
    QLineEdit *value_lineEdit = nullptr;

    // TagBaseWidget interface
public:
    QPair<QString, QString> getData() override;
    bool isValid() override;
};

#endif // TAGVALUEEDITWIDGET_H
