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

    for (auto i : this->photo_paths)
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
    for (int i = 0; i < photo_paths.size(); ++i)
    {
        QApplication::processEvents();
        auto path = this->photo_paths[i];
        qDebug() << "================================================";

        QFile tmpFile(path);
        if (!tmpFile.open(QIODevice::ReadOnly))
        {
            qWarning() << "Failed to open file " << path;
            return;
        }
        QByteArray bytes = tmpFile.readAll();
        tmpFile.close();

        Exiv2::byte *dataBytes      = (Exiv2::byte *)bytes.data();
        Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(dataBytes, bytes.size());
        tmpFile.close();
        assert(image.get() != 0);
        image->readMetadata();

        Exiv2::ExifData &data = image->exifData();
        if (data.empty())
        {
            qDebug() << ": No Exif data found in the file";
            // emit дай все exif
            return;
        }
        PhotoSegment photo_segment;
        photo_segment.photo = new QPixmap(path);
        photo_segment.segment.insert("FileName", QFileInfo(path).fileName());

        setExif(this->keys.unique, photo_segment.segment, data);
        setExif(this->keys.similar, photo_segment.common, data);
        setSizeExif(photo_segment.common, data);

        this->photos.insert(photos.size(), photo_segment);

        qDebug() << photo_segment.segment;
        qDebug() << photo_segment.common;
    }
}

void PhotoModel::setExif(QHash<QString, QString> &src_keys, QHash<QString, QString> &dst_keys, Exiv2::ExifData &data)
{
    for (auto i = src_keys.begin(); i != src_keys.end(); ++i)
    {
        Exiv2::ExifKey key = Exiv2::ExifKey(i.value().toStdString());
        if (data.findKey(key) != data.end())
        {
            auto tag = data[i.value().toStdString()].value().toString();
            dst_keys.insert(i.key(), QString::fromStdString(tag));
        }
        else
        {
            dst_keys.insert(i.key(), "-");
        }
    }
}

void PhotoModel::setSizeExif(QHash<QString, QString> &dst_keys, Exiv2::ExifData &data)
{
    Exiv2::ExifKey pX_key = Exiv2::ExifKey("Exif.Photo.PixelXDimension");
    Exiv2::ExifKey pY_key = Exiv2::ExifKey("Exif.Photo.PixelYDimension");
    if (data.findKey(pX_key) != data.end() and data.findKey(pY_key) != data.end())
    {
        dst_keys.remove("PixelX");
        dst_keys.remove("PixelY");

        auto pX_std_str = data["Exif.Photo.PixelXDimension"].value().toString();
        auto pY_std_str = data["Exif.Photo.PixelYDimension"].value().toString();

        dst_keys["Size"] = QString::fromStdString(pX_std_str) + "x" + QString::fromStdString(pY_std_str);
    }
}

void PhotoModel::clear()
{
    this->photo_paths.clear();
    this->photos.clear();
    this->keys = ExifKeys();
}
