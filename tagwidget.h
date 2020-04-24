#ifndef TAG1_H
#define TAG1_H
#include "exifextra.h"

#include <QComboBox>
#include <QDebug>
#include <QKeyEvent>
#include <QLineEdit>
#include <QObject>
#include <QPainter>
#include <QPushButton>
#include <QSizePolicy>
#include <QWidget>

class TagWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TagWidget(QWidget *parent = nullptr);
public slots:

signals:
    void shortNameChanged();
    void exifNameChanged();
    void deleteButtonChanged();

private:
    ExifExtra extra;

    QLineEdit *short_name      = nullptr;
    QComboBox *exif_name       = nullptr;
    QPushButton *delete_button = nullptr;

    int margin;
    // QWidget interface
private slots:
    void setShortName();
    void setExifName();
    void setDeleteButton();

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // TAG1_H
