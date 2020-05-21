#include "photomodel.h"

PhotoModel::PhotoModel()
{
    exposure_programm_human = {{"0", "Not defined"},
                               {"1", "Manual"},
                               {"2", "Normal program"},
                               {"3", "Aperture priority"},
                               {"4", "Shutter priority"},
                               {"5", "Creative program"},
                               {"6", "Action program"},
                               {"7", "Portrait mode"},
                               {"8", "Landscape mode"}};
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

QHash<int, PhotoSegment> &PhotoModel::getPhotos()
{
    return this->photos;
}

void PhotoModel::setPhotos()
{
    photos.clear();
    for (int i = 0; i < photo_paths.size(); ++i)
    {
        QApplication::processEvents();
        auto path = this->photo_paths[i];
        qDebug() << "================================================";

        QFile tmpFile(path);
        if (!tmpFile.open(QIODevice::ReadOnly))
        {
            qWarning() << "Failed to open file " << path;
            emit statusChanged("Не удалось открыть файл." + path, -1);
            return;
        }
        QByteArray bytes = tmpFile.readAll();
        tmpFile.close();

        Exiv2::byte *dataBytes      = (Exiv2::byte *)bytes.data();
        Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(dataBytes, bytes.size());
        tmpFile.close();
        assert(image.get() != 0);
        image->readMetadata();

        this->data = image->exifData();
        if (data.empty())
        {
            qDebug() << ": No Exif data found in the file";
            emit statusChanged("Exif данные не найдены", -1);
            return;
        }
        PhotoSegment photo_segment;
        photo_segment.photo = new QPixmap(path);
        photo_segment.unique.append(QPair<QString, QString>("FileName", QFileInfo(path).fileName()));

        setExif(this->keys.getUnique(), photo_segment.unique, photo_segment.unique_empty);
        setExif(this->keys.getCommon(), photo_segment.common, photo_segment.common_empty);
        setExif(this->keys.getCommonExtra(), photo_segment.common_extra, photo_segment.common_empty);
        setSizeExif(photo_segment.common);

        this->photos.insert(photos.size(), photo_segment);

        qDebug() << "unique";
        qDebug() << photo_segment.unique;
        qDebug() << "end unique";

        qDebug() << "common";
        qDebug() << photo_segment.common;
        qDebug() << "end common";

        qDebug() << "extra";
        qDebug() << photo_segment.common_extra;
        qDebug() << "end extra";
    }
}

void PhotoModel::setExif(const QList<QHash<QString, QString>> &src_keys,
                         QList<QPair<QString, QString>> &tags,
                         QList<QPair<QString, QString> *> &empty_tags)
{
    for (auto hash : src_keys)
    {
        auto item          = hash.begin();
        Exiv2::ExifKey key = Exiv2::ExifKey(item.value().toStdString());
        auto tag           = createTagText(key, item.value().toStdString());
        tags.append(QPair<QString, QString>(item.key(), tag));
        if (tag.isEmpty() or tag == "-")
            empty_tags.append(&tags.last());
    }
}

void PhotoModel::setSizeExif(QList<QPair<QString, QString>> &dst_keys)
{
    Exiv2::ExifKey pX_key = Exiv2::ExifKey("Exif.Photo.PixelXDimension");
    Exiv2::ExifKey pY_key = Exiv2::ExifKey("Exif.Photo.PixelYDimension");
    if (data.findKey(pX_key) != data.end() and data.findKey(pY_key) != data.end())
    {
        auto pX_std_str    = data["Exif.Photo.PixelXDimension"].value().toString();
        auto pY_std_str    = data["Exif.Photo.PixelYDimension"].value().toString();
        QString total_text = QString::fromStdString(pX_std_str) + "x" + QString::fromStdString(pY_std_str);
        dst_keys.append(QPair<QString, QString>("Size", total_text));
    }
}

void PhotoModel::clear()
{
    this->photo_paths.clear();
    this->photos.clear();
}

QString PhotoModel::createTagText(Exiv2::ExifKey &key, std::string value)
{
    QString tag = "-";
    if (data.findKey(key) != data.end())
    {
        auto std_str_tag = data[value].value().toString();
        tag              = QString::fromStdString(std_str_tag); // create tag
        if (tag.contains(QRegExp("^-?\\d+\\/\\d+$")))
        {
            Fraction f;
            tag = f.stringToDouble(tag);
            if (QString::fromStdString(key.key()).contains("ExposureTime"))
                tag += " EV";
        }
        if (QString::fromStdString(key.key()).contains("ExposureProgram"))
            tag = exposure_programm_human[tag];
    }
    else
        tag = "-";

    return tag;
}
