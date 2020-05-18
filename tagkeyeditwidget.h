#ifndef TAGKEYEDITWIDGET_H
#define TAGKEYEDITWIDGET_H

#include <QComboBox>
#include <QObject>
#include <QPair>
#include <QWidget>

#include "exifextra.h"
#include "tagbasewidget.h"

class TagKeyEditWidget : public TagBaseWidget
{
    Q_OBJECT
public:
    explicit TagKeyEditWidget(QWidget *parent = nullptr);

public slots:
    void setExifName();
    void setExifName(const QString &);
    int test();

private:
    ExifExtra extra;
    QComboBox *exif_name = nullptr;

    // TagBaseWidget interface
public:
    QPair<QString, QString> getData() override;
    bool isValid() override;
};

#endif // TAGKEYEDITWIDGET_H
