#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->presenter   = new PhotoPresenter();
    this->segment_cnt = 4;

    connect(presenter, &PhotoPresenter::statusChanged, this, &MainWindow::updateStatusBar);
    connect(presenter, &PhotoPresenter::readyPaint, this, &MainWindow::paint);
    movie = new QMovie("://loader.gif");
}

MainWindow::~MainWindow()
{
    delete this->presenter;
    delete ui;
}

void MainWindow::paint()
{
    qDebug() << "start paint";
    this->photo_size   = this->presenter->getPhotos()[0].photo->size();
    this->segment_size = this->photo_size / 4;

    QPixmap result(this->photo_size.width() + 1000, this->photo_size.height());
    result.fill(Qt::white);
    QPainter painter(&result);
    painter.drawPixmap(0, 0, drawPhotos());
    painter.drawPixmap(photo_size.width() + 20, 20, drawCommonExif());
    painter.end();
    this->saveResult(result);
    result_pixmap = result.copy();
    movie->stop();
    ui->label->setPixmap(result_pixmap.scaled(ui->label->width(), ui->label->height()));
}

void MainWindow::saveResult(QPixmap &pixmap)
{
    qDebug() << "saving result";
    auto path = SettingsSingleton::getInstance().getPath();
    QFile file(path + "\\result.png");
    if (file.exists())
        file.remove();
    pixmap.save(file.fileName());
}

QPixmap MainWindow::drawPhotos()
{
    qDebug() << "draw photos";
    auto photo_segments = this->presenter->getPhotos();
    QPixmap photos(this->photo_size.width(), this->photo_size.height());
    QPainter painter(&photos);
    for (int i = 0; i < photo_segments.size(); ++i)
    {
        int x = this->segment_size.width() * (i % this->segment_cnt);
        int y = this->segment_size.height() * (i / this->segment_cnt);

        painter.drawPixmap(x, y, drawSegmentExif(photo_segments[i], x, y));
    }

    painter.end();
    return photos;
}

QPixmap MainWindow::drawSegmentExif(const PhotoSegment &segment, int &x, int &y)
{
    qDebug() << "draw segment exif";
    QPixmap photo = segment.photo->copy(x, y, this->segment_size.width(), this->segment_size.height());
    qDebug() << "photo.size =" << photo.size();
    auto data = segment.segment;
    Fraction fraction;

    TextBase text(photo, Qt::black, Qt::green);
    qDebug() << "start===================================";
    text.drawText("FileName", data["FileName"]);
    text.drawText("ISO", data["ISO"]);
    qDebug() << "Human ExposureTime =" << fraction.stringToDouble(data["ExposureTime"]);
    text.drawText("ExposureTime", fraction.stringToDouble(data["ExposureTime"]));
    text.drawText("FNumber", fraction.stringToDouble(data["FNumber"]));
    text.drawText("ExposureBiasValue", fraction.stringToDouble(data["ExposureBiasValue"]));

    return text.pixmap;
}

QPixmap MainWindow::drawCommonExif()
{
    qDebug() << "draw common exif";
    QPixmap common(1000, this->photo_size.height());
    common.fill(Qt::white);
    auto segment = this->presenter->getPhotos()[0];

    auto data = segment.common;

    TextBase text(common, Qt::white, Qt::black);
    text.drawText("Make", data["Make"]);
    text.drawText("Model", data["Model"]);
    text.drawText("Date", data["DateTime"]);
    text.drawText("Size", data["Size"]);
    text.drawText("ExposureProgram", data["ExposureProgram"]);

    return text.pixmap;
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

void MainWindow::resizeEvent(QResizeEvent *event)
{
    if (!result_pixmap.isNull())
        ui->label->setPixmap(result_pixmap.scaled(ui->label->width(), ui->label->height()));
    QMainWindow::resizeEvent(event);
}

void MainWindow::on_actionSelect_photos_triggered()
{
    QStringList filenames =
    QFileDialog::getOpenFileNames(this, "Выберите фотографии", SettingsSingleton::getInstance().getPath(), "*.jpg; *.jpeg");
    ui->label->setMovie(movie);
    movie->start();
    this->presenter->process(filenames);
}
