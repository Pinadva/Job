#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->presenter = new PhotoPresenter();
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
                                                          SettingsSingleton::getInstance().getPath());
    this->presenter->process(filenames);
    paint();
}

void MainWindow::paint()
{
    auto images = this->presenter->getImages();
    int label_w = ui->label->width();
    int bars_cnt = 4;  // количество отображаемых плиток
    int bar_w = label_w / bars_cnt; // ширина одной плитки

    QPixmap pm(ui->label->width(), ui->label->width());
    QPainter painter(&pm);

    for (int i = 0; i < images.size(); ++i) {
        painter.drawPixmap(bar_w * (i % bars_cnt),
                           bar_w * (i / bars_cnt),
                           bar_w,
                           bar_w,
                           QPixmap::fromImage(images[i]).scaled(label_w, label_w));
    }
    painter.end();
    ui->label->setPixmap(pm);
}
