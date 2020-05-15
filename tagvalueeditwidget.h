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
};

#endif // TAGVALUEEDITWIDGET_H
