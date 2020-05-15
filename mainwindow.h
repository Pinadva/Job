#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "addtagform.h"
#include "fraction.h"
#include "photopresenter.h"
#include "photoview.h"
#include "settingssingleton.h"
#include "tagbasewidget.h"
#include "tagkeyeditwidget.h"
#include "taglistwidget.h"
#include "textbase.h"

#include <QByteArray>
#include <QDataStream>
#include <QDebug>
#include <QDir>
#include <QDragEnterEvent>
#include <QFileDialog>
#include <QHash>
#include <QMainWindow>
#include <QMimeData>
#include <QMovie>
#include <QPainter>
#include <QPixmap>
#include <QSettings>
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
    void chooseKeyAction(QString);

protected:
    void resizeEvent(QResizeEvent *event);

private slots:
    void on_actionSelect_photos_triggered();
    void on_actionAdd_tags_triggered();

    void on_pushButton_clicked();

    void on_testBtn_clicked();

private:
    Ui::MainWindow *ui;

    PhotoView *view           = nullptr;
    PhotoPresenter *presenter = nullptr;
    PhotoModel *model         = nullptr;
    AddTagForm *add_tag       = nullptr;

    QPixmap result_pixmap;
    QMovie *movie;

    // QWidget interface
protected:
    void keyReleaseEvent(QKeyEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
};
#endif // MAINWINDOW_H
