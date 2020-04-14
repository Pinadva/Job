#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->presenter = new PhotoPresenter();

    this->label_w = ui->label->height(); // ширина label для отображения плиток
    this->bars_cnt = 4;  // количество отображаемых плиток
    this->bar_w = label_w / bars_cnt; // ширина одной плитки
    connect(presenter, SIGNAL(statusChanged(QString, int)), this, SLOT(updateStatusBar(QString, int)));
    connect(presenter, SIGNAL(readyPaint()), this, SLOT(paint()));
}

MainWindow::~MainWindow()
{
    delete this->presenter;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QStringList filenames = QFileDialog::getOpenFileNames(this,
                                                          "Выберите фотографии",
                                                          SettingsSingleton::getInstance().getPath(),
                                                          "*.jpg; *.jpeg");
    this->presenter->process(filenames);
}

void MainWindow::paint()
{

    qDebug() << "strart paint";
    this->photo_size = this->presenter->getPhotos()[0].photo->size();
    this->segment_size = this->photo_size / 4;

    QPixmap result(this->photo_size.width()+ 800, this->photo_size.height());
    result.fill(Qt::white);
    QPainter painter(&result);
    painter.drawPixmap(0, 0, drawPhotos());
    painter.drawPixmap(photo_size.width() + 20, 20, drawCommonExif());

    painter.end();
    this->saveResult(result);
    ui->label->setPixmap(result.scaled(ui->label->width(), ui->label->height()));
}

void MainWindow::saveResult(QPixmap &pixmap)
{
    auto path = SettingsSingleton::getInstance().getPath();
    QFile file(path + "\\result.png");
    if (file.exists())
        file.remove();
    qDebug() << pixmap.save(file.fileName());
}

QPixmap MainWindow::drawPhotos()
{
    qDebug() << "draw photos";
    auto photo_segments = this->presenter->getPhotos();
    QPixmap photos(this->photo_size.width(), this->photo_size.height());
    QPainter painter(&photos);
    for (int i = 0; i < photo_segments.size(); ++i) {
        int x = this->segment_size.width()  * (i % this->bars_cnt);
        int y = this->segment_size.height() * (i / this->bars_cnt);

        painter.drawPixmap(x, y, drawSegmentExif(photo_segments[i], x, y));
    }

    painter.end();
    return photos;
}

QPixmap MainWindow::drawSegmentExif(const PhotoSegment &segment, int &x, int &y)
{
    QPixmap photo = segment.photo->copy(x, y, this->segment_size.width(), this->segment_size.height());
    QPainter painter(&photo);
    painter.setBackgroundMode(Qt::OpaqueMode);
    painter.setBackground(Qt::black);
    painter.setOpacity(0.5);
    painter.setPen(Qt::green);
    painter.setFont(QFont("Arial", 36));

    drawText(segment.segment, painter, Qt::green);

    painter.end();
    return photo;
}

QPixmap MainWindow::drawCommonExif()
{
    qDebug() << "draw common exif";
    auto segment = this->presenter->getPhotos()[0];
    QPixmap common(800, this->photo_size.height());
    common.fill(Qt::white);
    QPainter painter(&common);
    painter.setBackgroundMode(Qt::OpaqueMode);
    painter.setBackground(Qt::white);
    painter.setOpacity(0.5);
    painter.setFont(QFont("Arial", 48));

    drawText(segment.common, painter, Qt::black);

    painter.end();
    return common;
}

void MainWindow::drawText(const QHash<QString, QString> &exif_data, QPainter &painter, QColor text_color)
{
    QString text = "";
    int y = 50;
    for (auto i = exif_data.begin(); i != exif_data.end(); ++i) {
            if (i.value() == "-"){
                painter.setPen(Qt::red);
            }
            else
                 painter.setPen(text_color);
             text = i.key() + ": " + i.value() + " \n";
                 painter.drawText(rect(), text);
             y += 20;
    }

}

void MainWindow::drawCommonText(const QHash<QString, QString> &exif_data, QPainter &painter, QColor text_color)
{
    QString text = "";
    int x = 70;
    for (auto i = exif_data.begin(); i != exif_data.end(); ++i) {
            if (i.value() == "-"){
                painter.setPen(Qt::red);
            }
            else
                 painter.setPen(text_color);
            text = i.key() + ": " + i.value() + "; ";
            painter.drawText(rect(), text);
            x += 750;
    }
}



void MainWindow::updateStatusBar(QString status_message = "", int error_code = 0)
{
    qDebug() << status_message;
    switch (error_code) {
        case -1:
            ui->statusbar->setStyleSheet("QStatusBar{color:red;}"); //:rgba(255,0,0,255)
        break;
        case 0:
            ui->statusbar->setStyleSheet("QStatusBar{color:black;}");
        break;
        case 1:
            ui->statusbar->setStyleSheet("QStatusBar{color:green;}");
        break;
    }
    ui->statusbar->showMessage(status_message, 10000);
}


