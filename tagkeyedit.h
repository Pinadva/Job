#ifndef TAGKEYEDITWIDGET_H
#define TAGKEYEDITWIDGET_H

#include <QComboBox>
#include <QObject>
#include <QPair>
#include <QWidget>

#include "exifextra.h"
#include "tagbase.h"

class TagKeyEdit : public TagBaseWidget
{
    Q_OBJECT
public:
    explicit TagKeyEdit(QWidget *parent = nullptr);

public slots:
    void setExifName();
    void setExifName(const QString &);

private:
    ExifExtra extra;
    QComboBox *exif_name = nullptr;

    // TagBaseWidget interface
public:
    void setData() override;
    void setData(QPair<QString, QString>) override;
    QPair<QString, QString> getData() override;
    bool isValid() override;
};

#endif // TAGKEYEDITWIDGET_H
