#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "photopresenter.h"
#include "settingssingleton.h"
#include "textbase.h"

#include <QDragEnterEvent>
#include <QFileDialog>
#include <QMainWindow>
#include <QMimeData>
#include <QMovie>
#include <QPainter>
#include <QPixmap>
#include <QTextItem>
#include <Qt>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void updateStatusBar(QString, int);

protected:
    void resizeEvent(QResizeEvent *event);

private slots:
    void paint();
    void saveResult(QPixmap &);
    QPixmap drawPhotos();
    QPixmap drawCommonExif();
    QPixmap drawSegmentExif(const PhotoSegment &, int &, int &);
    void on_actionSelect_photos_triggered();

private:
    Ui::MainWindow *ui;

    PhotoPresenter *presenter;

    QSize photo_size;
    QSize segment_size;
    int segment_cnt;
    QPixmap result_pixmap;
    QMovie *movie;
};
#endif // MAINWINDOW_H
