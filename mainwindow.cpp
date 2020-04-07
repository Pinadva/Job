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

    on_pushButton_clicked();
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
    paint();
}

void MainWindow::paint()
{
    auto images = this->presenter->getImages();

    QPixmap pm(ui->label->width(), ui->label->width());
    QPainter painter(&pm);

    for (int i = 0; i < images.size(); ++i) {
        painter.drawPixmap(this->bar_w * (i % this->bars_cnt),
                           this->bar_w * (i / this->bars_cnt),
                           drawExiff(images[i]));
    }
    painter.end();
    ui->label->setPixmap(pm);
}

QPixmap MainWindow::drawExiff(QImage &image)
{
    QPixmap pm_image = QPixmap::fromImage(image.scaled(this->bar_w, this->bar_w));
    QPainter painter_image(&pm_image);

    painter_image.setBackgroundMode(Qt::OpaqueMode);
    painter_image.setBackground(Qt::black);
    painter_image.setPen(Qt::white);
    painter_image.setFont(QFont("Arial", 9));
    painter_image.drawText(rect(), Qt::AlignLeft, "Some body\nonce\ntold me");
    painter_image.end();

    return pm_image;
}


