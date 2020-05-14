#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->model     = new PhotoModel();
    this->presenter = new PhotoPresenter(model);
    this->view      = new PhotoView(presenter);
    this->add_tag   = new AddTagForm();

    connect(model, &PhotoModel::statusChanged, this, &MainWindow::updateStatusBar);
    connect(presenter, &PhotoPresenter::statusChanged, this, &MainWindow::updateStatusBar);
    connect(view, &PhotoView::statusChanged, this, &MainWindow::updateStatusBar);
    connect(view, &PhotoView::readyView, this, &MainWindow::viewResult);
    movie = new QMovie("://loader.gif");
}

MainWindow::~MainWindow()
{
    delete this->movie;
    delete this->model;
    delete this->presenter;
    delete this->view;
    delete ui;
}

void MainWindow::updateStatusBar(QString status_message = "", int error_code = 0)
{
    qDebug() << status_message;
    switch (error_code)
    {
        case -1:
            ui->statusbar->setStyleSheet("QStatusBar{color:red;}"); //:rgba(255,0,0,255)
            this->movie->stop();
            this->ui->label->clear();
            break;
        case 0:
            ui->statusbar->setStyleSheet("QStatusBar{color:black;}");
            break;
        case 1:
            ui->statusbar->setStyleSheet("QStatusBar{color:green;}");
            break;
    }
    ui->statusbar->showMessage(status_message);
}

void MainWindow::viewResult(QPixmap &result)
{
    movie->stop();
    result_pixmap = result;
    ui->label->setPixmap(result.scaled(ui->label->width(), ui->label->height()));
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    if (!result_pixmap.isNull())
        ui->label->setPixmap(result_pixmap.scaled(ui->label->width(), ui->label->height()));
    QMainWindow::resizeEvent(event);
}

void MainWindow::on_actionSelect_photos_triggered()
{
    QStringList filenames =
    QFileDialog::getOpenFileNames(this, "Выберите фотографии", SettingsSingleton::getInstance().getPath(), "*.jpg; *.jpeg; *jpe");
    if (filenames.count())
    {
        ui->label->setMovie(movie);
        movie->start();
    }
    this->presenter->process(filenames);
}

void MainWindow::on_actionAdd_tags_triggered()
{
    add_tag->show();
}

void MainWindow::on_pushButton_clicked()
{
    QHash<QString, QString> h1;
    h1.insert("1", "first");
    QHash<QString, QString> h2;
    h2.insert("2", "second");

    QList<QHash<QString, QString>> data;
    data.append(h1);
    data.append(h2);

    QByteArray b;
    QDataStream d(&b, QIODevice::WriteOnly);
    d << data;

    QList<QHash<QString, QString>> data_res;
    QDataStream d_res(&b, QIODevice::ReadOnly);
    d_res >> data_res;
    qDebug() << data_res;
}
