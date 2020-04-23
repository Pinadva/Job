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
    emit readyView(result_pixmap);
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

        painter.drawPixmap(x, y, drawSegmentExif(photo_segments[i], x, y));
    }

    painter.end();
    return photos;
}

QPixmap PhotoView::drawSegmentExif(const PhotoSegment &segment, int &x, int &y)
{
    qDebug() << "draw segment exif";
    QPixmap photo = segment.photo->copy(x, y, this->segment_size.width(), this->segment_size.height());
    auto data     = segment.segment;
    Fraction fraction;

    TextBase text(Qt::black, Qt::green);
    text.painter.begin(&photo);
    text.painterInit();

    text.drawText("FileName", data["FileName"]);
    text.drawText("ISO", data["ISO"]);
    text.drawText("ExposureTime", fraction.stringToDouble(data["ExposureTime"]));
    text.drawText("FNumber", fraction.stringToDouble(data["FNumber"]));
    text.drawText("ExposureBiasValue", fraction.stringToDouble(data["ExposureBiasValue"]));

    return photo;
}

const QPixmap &PhotoView::getResult()
{
    return result_pixmap;
}

QPixmap PhotoView::drawCommonExif()
{
    qDebug() << "draw common exif";
    QPixmap common(1000, this->photo_size.height());
    common.fill(Qt::white);
    auto segment = this->presenter->getPhotos()[0];
    auto data    = segment.common;

    TextBase text(Qt::white, Qt::black);
    text.painter.begin(&common);
    text.painterInit();

    text.drawText("Make", data["Make"]);
    text.drawText("Model", data["Model"]);
    text.drawText("Date", data["DateTime"]);
    text.drawText("Size", data["Size"]);
    text.drawText("ExposureProgram", data["ExposureProgram"]);
    text.painter.end();

    return common;
}
