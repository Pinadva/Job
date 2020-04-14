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
    QPixmap result(ui->label->width(), ui->label->height());
    result.fill(Qt::white);
    QPainter painter(&result);
    painter.drawPixmap(0, 0, drawPhotos());
    painter.drawPixmap(ui->label->height() + 10, 0, drawCommonExif());

    painter.end();
    this->saveResult(result);
    ui->label->setPixmap(result);
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
    auto photo_segments = this->presenter->getSegments();
    QPixmap photos(ui->label->height(), ui->label->height());
    QPainter painter(&photos);
    for (int i = 0; i < photo_segments.size(); ++i) {
        painter.drawPixmap(this->bar_w * (i % this->bars_cnt),
                           this->bar_w * (i / this->bars_cnt),
                           drawSegmentExif(photo_segments[i]));
    }

    painter.end();
    return photos;
}

QPixmap MainWindow::drawSegmentExif(const PhotoSegment &segment)
{
    QPixmap photo = segment.photo->scaled(this->bar_w, this->bar_w);
    QPainter painter(&photo);
    painter.setBackgroundMode(Qt::OpaqueMode);
    painter.setBackground(Qt::black);
    painter.setOpacity(0.5);
    painter.setPen(Qt::white);
    painter.setFont(QFont("Arial", 9));

    drawText(segment.segment, painter, Qt::white);

    painter.end();
    return photo;
}

QPixmap MainWindow::drawCommonExif()
{
    qDebug() << "draw common exif";
    auto segment = this->presenter->getSegments()[0];
    QPixmap common(200, ui->label->height());
    common.fill(Qt::white);
    QPainter painter(&common);
    painter.setBackgroundMode(Qt::OpaqueMode);
    painter.setBackground(Qt::white);
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 9));

    drawText(segment.common, painter, Qt::black);

    painter.end();
    return common;
}

void MainWindow::drawText(const QHash<QString, QString> &exif_data, QPainter &painter, QColor text_color)
{
    QString text = "";
    int y = 10;
    for (auto i = exif_data.begin(); i != exif_data.end(); ++i) {
            if (i.value() == "-"){
                painter.setPen(Qt::red);
            }
            else
                 painter.setPen(text_color);
             text = i.key() + ": " + i.value() + " \n";
                 painter.drawText(QPointF(1, y), text);
             y += 15;
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


