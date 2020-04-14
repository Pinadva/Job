#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "settingssingleton.h"
#include "photopresenter.h"

#include <QMainWindow>
#include <QFileDialog>
#include <QDragEnterEvent>
#include <QPainter>
#include <QPixmap>
#include <QTextItem>
#include <QMimeData>
#include <Qt>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void updateStatusBar(QString, int);

private slots:
    void on_pushButton_clicked();

    void paint();
    void saveResult(QPixmap &);
    QPixmap drawSegmentExif(const PhotoSegment &, int &, int &);
    QPixmap drawPhotos();
    QPixmap drawCommonExif();
    void drawText(const QHash<QString, QString> &, QPainter &, QColor);
    void drawCommonText(const QHash<QString, QString> &, QPainter &, QColor);

private:
    Ui::MainWindow *ui;

    PhotoPresenter *presenter;
    int label_w; // ширина label для отображения плиток
    int bars_cnt; // количество отображаемых плиток
    int bar_w; // ширина одной плитки
    QSize photo_size;
    QSize segment_size;
};
#endif // MAINWINDOW_H
