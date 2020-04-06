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
                                                          SettingsSingleton::getInstance().getPath());
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
    // bar_w = 222 (ширина плитки)
    QPixmap pm_text(bar_w, bar_w / 3); // пиксмап для отображения текста
    QPainter painter_text(&pm_text);

    painter_text.setBackground(Qt::black); // задаю цвет фона (не работает)

// painter_text.setBrush(Qt::black); // задаю цвет фона (не работает)
    painter_text.setPen(Qt::white); // задаю цвет текста (все норм)
    painter_text.setFont(QFont("Arial", 6));
    painter_text.drawText(rect(), Qt::AlignLeft, "Some\nbody\nonce\ntold me");
    painter_text.end();

    QPixmap pm_image = QPixmap::fromImage(image.scaled(this->bar_w, this->bar_w));
    QPainter painter_image(&pm_image);

    qDebug() << pm_text.width()<< pm_text.height();
    painter_image.drawPixmap(0,0, pm_text);
    painter_image.end();

    return pm_image;
}


