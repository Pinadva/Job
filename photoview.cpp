#include "photoview.h"

PhotoView::PhotoView()
{
    this->presenter = new PhotoPresenter();
}

PhotoView::PhotoView(PhotoPresenter *&presenter)
{
    this->presenter   = presenter;
    this->segment_cnt = 4;
    connect(presenter, &PhotoPresenter::readyPaint, this, &PhotoView::paint);
}

void PhotoView::paint()
{
    qDebug() << "start paint";
    if (this->presenter->getPhotos().size() > 0)
    {
        emit processStarted();
        this->photo_size   = this->presenter->getPhotos()[0].photo->size();
        this->segment_size = this->photo_size / 4;

        QPixmap result(this->photo_size.width() + 1200, this->photo_size.height());
        result.fill(Qt::white);
        QPainter painter(&result);
        painter.drawPixmap(0, 0, drawPhotos());
        painter.drawPixmap(photo_size.width() + 20, 20, drawCommonExif());
        painter.end();
        this->saveResult(result);
        result_pixmap = result.copy();
        emit readyView(result_pixmap);
        emit statusChanged("Success", 1);
    }
}

void PhotoView::saveResult(QPixmap &pixmap)
{
    qDebug() << "saving result";
    auto path = SettingsSingleton::getInstance().getPath();
    QFile file(path + "\\result.png");
    if (file.exists())
        file.remove();
    pixmap.save(file.fileName());
}

QPixmap PhotoView::drawPhotos()
{
    qDebug() << "draw photos";
    auto photo_segments = this->presenter->getPhotos();
    QPixmap photos(this->photo_size.width(), this->photo_size.height());
    QPainter painter(&photos);
    for (int i = 0; i < photo_segments.size(); ++i)
    {
        int x = this->segment_size.width() * (i % this->segment_cnt);
        int y = this->segment_size.height() * (i / this->segment_cnt);

        painter.drawPixmap(x, y, drawUniqueExif(photo_segments[i], x, y));
    }

    painter.end();
    return photos;
}

QPixmap PhotoView::drawUniqueExif(const PhotoSegment &segment, int &x, int &y)
{
    qDebug() << "draw unique exif";
    QPixmap pixmap = segment.photo->copy(x, y, this->segment_size.width(), this->segment_size.height());
    auto extra     = segment.unique_extra;
    TextBase text(Qt::black, Qt::green);
    text.painter.begin(&pixmap);
    text.painterInit();
    for (auto item : segment.unique)
    {
        text.drawText(item.first, item.second);
    }
    text.drawText("-------------------------------");
    for (auto item : extra)
    {
        qDebug() << "unique extra item" << item.first << item.second;
        text.drawText(item.first, item.second);
    }
    text.painter.end();
    return pixmap;
}

const QPixmap &PhotoView::getResult()
{
    return result_pixmap;
}

QPixmap PhotoView::drawCommonExif()
{
    //    qDebug() << "draw common exif";
    QPixmap pixmap(1200, this->photo_size.height());
    pixmap.fill(Qt::white);
    auto segment = this->presenter->getPhotos()[0];
    auto common  = segment.common;
    auto extra   = segment.common_extra;

    TextBase text(Qt::white, Qt::black);
    text.painter.begin(&pixmap);
    text.painterInit();
    for (auto item : common)
    {
        text.drawText(item.first, item.second);
    }
    text.drawText("-------------------------------");
    for (auto item : extra)
    {
        qDebug() << "extra item" << item.first << item.second;
        text.drawText(item.first, item.second);
    }
    text.drawText("-------------------------------");
    qDebug() << "comment = " << presenter->getComment();
    QString raw_comment = presenter->getComment();
    QStringList comment = raw_comment.split("\n");
    for (QString line : comment)
    {
        text.drawText(line);
    }
    text.painter.end();

    return pixmap;
}
