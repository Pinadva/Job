#ifndef TAG1_H
#define TAG1_H
#include "exifextra.h"

#include <QComboBox>
#include <QDebug>
#include <QHBoxLayout>
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
    QLayout *layout            = nullptr;

    int widget_height;
    // QWidget interface
private slots:
    void setShortName();
    void setExifName();
    void setDeleteButton();

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

    // QWidget interface

    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // TAG1_H
