#include "photomodel.h"


PhotoModel::PhotoModel()
{

}

void PhotoModel::setExifKeys()
{
    this->keys = ExifKeys();
}

void PhotoModel::setPaths(QStringList &image_paths)
{
    this->photo_paths = image_paths;

    for (auto i: this->photo_paths)
        qDebug() << i;
}

const QStringList &PhotoModel::getPaths()
{
    return this->photo_paths;
}

const QHash<int, PhotoSegment> &PhotoModel::getPhotos()
{
    return this->photos;
}

void PhotoModel::setPhotos()
{
    for (int i = 0; i < photo_paths.size(); ++i){
        auto path = this->photo_paths[i];
        qDebug() << "================================================";
        Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(path.toStdString());
        assert(image.get() != 0);
        image->readMetadata();

        Exiv2::ExifData &exifData = image->exifData();
        if (exifData.empty()) {
            qDebug() << ": No Exif data found in the file";
            // emit дай все exif
            continue;
            }

        PhotoSegment photo_segment;
        photo_segment.photo = new QPixmap(path);
        photo_segment.segment.insert("FileName", QFileInfo(path).fileName());

        setExif(this->keys.segment, photo_segment.segment, exifData);
        setExif(this->keys.common, photo_segment.common, exifData);

        this->photos.insert(photos.size(), photo_segment);

        qDebug() << "*****************";
        qDebug() << photo_segment.segment;
        qDebug() << photo_segment.common;
        qDebug() << "*****************";
    }
}

void PhotoModel::setExif(QHash<QString, QString> &src_keys, QHash<QString, QString> &dst_keys, Exiv2::ExifData &data)
{
    for (auto i = src_keys.begin(); i != src_keys.end(); ++i){
        Exiv2::ExifKey key = Exiv2::ExifKey(i.value().toStdString());
        if (data.findKey(key) != data.end()){
            auto tag = data[i.value().toStdString()].value().toString();
            dst_keys.insert(i.key(), QString::fromStdString(tag));
        }
        else {
        // emit дай any exif
        }
    }
}


void PhotoModel::clear()
{
    this->photo_paths.clear();
    this->photos.clear();
    this->keys = ExifKeys();
}




