#ifndef TAG_H
#define TAG_H

#include "exifextra.h"

#include <QComboBox>
#include <QKeyEvent>
#include <QLineEdit>
#include <QObject>
#include <QPainter>
#include <QWidget>

class Tag : public QWidget
{
    Q_OBJECT
private:
    QLineEdit short_name;
    QComboBox exif_name;
    ExifExtra extra;

    void exifNameInit();

public:
    explicit Tag(QWidget *parent = nullptr);

    // QWidget interface
protected:
    //    void keyPressEvent(QKeyEvent *event);
    void paintEvent(QPaintEvent *event);
};

#endif // TAG_H
