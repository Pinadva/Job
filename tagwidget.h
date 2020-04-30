#ifndef TAG1_H
#define TAG1_H
#include "exifextra.h"

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

class TagWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TagWidget(QWidget *parent = nullptr);

public slots:
    void setShortName(const QString &);
    void setExifName();
    void setExifName(const QString &);
    void setDeleteButton();
    void sendRemoveTag();

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

    // QWidget interface
signals:
    void checkValid();
    void removeTag(QObject *);

private:
    ExifExtra extra;

    QLineEdit *short_name      = nullptr;
    QComboBox *exif_name       = nullptr;
    QPushButton *remove_button = nullptr;
    QLayout *layout            = nullptr;

    int widget_height;
};

#endif // TAG1_H
