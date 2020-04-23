#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "fraction.h"
#include "photopresenter.h"
#include "photoview.h"
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
    void viewResult(QPixmap &);

protected:
    void resizeEvent(QResizeEvent *event);

private slots:
    void on_actionSelect_photos_triggered();

private:
    Ui::MainWindow *ui;

    PhotoView *view           = nullptr;
    PhotoPresenter *presenter = nullptr;
    PhotoModel *model         = nullptr;

    QPixmap result_pixmap;
    QMovie *movie;
};
#endif // MAINWINDOW_H
