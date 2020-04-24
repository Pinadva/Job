#ifndef TAG1_H
#define TAG1_H
#include "exifextra.h"

#include <QComboBox>
#include <QDebug>
#include <QKeyEvent>
#include <QLineEdit>
#include <QObject>
#include <QPainter>
#include <QWidget>

class Tag1 : public QWidget
{
    Q_OBJECT
public:
    explicit Tag1(QWidget *parent = nullptr);

signals:
private:
    QLineEdit short_name;
    QComboBox exif_name;
    ExifExtra extra;

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // TAG1_H
