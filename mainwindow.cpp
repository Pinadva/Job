#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->presenter = new PhotoPresenter();

    this->label_w = ui->label->width(); // ширина label для отображения плиток
    this->bars_cnt = 4;  // количество отображаемых плиток
    this->bar_w = label_w / bars_cnt; // ширина одной плитки
    connect(presenter, SIGNAL(statusChanged(QString)), this, SLOT(updateStatusBar(QString)));
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
    auto photo_segments = this->presenter->getSegments();

    QPixmap result(ui->label->width(), ui->label->width());
    QPainter painter(&result);

    for (int i = 0; i < photo_segments.size(); ++i) {
        painter.drawPixmap(this->bar_w * (i % this->bars_cnt),
                           this->bar_w * (i / this->bars_cnt),
                           drawExiff(photo_segments[i]));
    }
    painter.end();
    ui->label->setPixmap(result);
}

QPixmap MainWindow::drawExiff(const PhotoSegment &segment)
{
    QPixmap photo = segment.photo->scaled(this->bar_w, this->bar_w);
    QPainter painter_image(&photo);

    painter_image.setBackgroundMode(Qt::OpaqueMode);
    painter_image.setBackground(Qt::black);
    painter_image.setPen(Qt::white);
    painter_image.setFont(QFont("Arial", 9));
    // вынести создание текста в отдельную функцию
    QString text = "";
    text += segment.file_name + "\n";
    for (auto i = segment.segment.begin(); i != segment.segment.end(); ++i){
        text += i.key() + " " + i.value() + "\n";
    }
    painter_image.drawText(rect(), Qt::AlignLeft, text);
    painter_image.end();

    return photo;
}

void MainWindow::updateStatusBar(QString status_message = "")
{
    qDebug() << status_message;
    ui->statusbar->showMessage(status_message, 10000);
}


