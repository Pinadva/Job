#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "settingssingleton.h"
#include "photopresenter.h"

#include <QMainWindow>
#include <QFileDialog>
#include <QDragEnterEvent>
#include <QPainter>
#include <QPixmap>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButton_clicked();
    void paint();

private:
    Ui::MainWindow *ui;

    PhotoPresenter *presenter;
};
#endif // MAINWINDOW_H
