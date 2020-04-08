#include "photomodel.h"


PhotoModel::PhotoModel()
{

}

void PhotoModel::setExifKeys()
{

}

void PhotoModel::setPaths(QStringList &image_paths)
{
    this->photo_paths = image_paths;

    // debug
    for (auto i: this->photo_paths)
        qDebug() << i;
    //enddebug
}

const QStringList &PhotoModel::getPaths()
{
    return this->photo_paths;
}

void PhotoModel::setPhotos()
{
    for (int i = 0; i < this->photo_paths.size(); ++i){
        this->photos.insert(i, QPixmap(photo_paths[i]));
    }
}

const QHash<int, QPixmap> &PhotoModel::getPhotos()
{
    return this->photos;
}


const QHash<int, PhotoSegment> &PhotoModel::getSegments()
{
    return this->segments;
}

void PhotoModel::setSegments()
{
    // разделить на подфункции, когда будет сделан вывод
    for (auto iter = this->photos.begin(); iter != this->photos.end(); ++iter){
        auto path = this->photo_paths[iter.key()];
        cout << "================================================" << endl;
        Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(path.toStdString());
        assert(image.get() != 0);
        image->readMetadata();

        PhotoSegment photo_segment;
        photo_segment.photo = &iter.value();

        Exiv2::ExifData &exifData = image->exifData();
        if (exifData.empty()) {
            qDebug() << ": No Exif data found in the file";
            continue;
            // emit дай все exif
            }

        for (auto i = keys.segment.begin(); i != keys.segment.end(); ++i){
            Exiv2::ExifKey key = Exiv2::ExifKey(i.value().toStdString());
            if (exifData.findKey(key) != exifData.end()){

                auto tag = exifData[i.value().toStdString()].value().toString();
                photo_segment.exifs.insert(i.key(), QString::fromStdString(tag));

                cout << setw(44) << setfill(' ')<< left << i.key().toStdString() <<
                exifData[i.value().toStdString()].value() << endl;
            }
            else{
            // emit дай exif
            }

         }
        this->segments.insert(segments.size(), photo_segment);
        qDebug() << "*****************";
        qDebug() << photo_segment.exifs;
        qDebug() << "*****************";
    }

}

void PhotoModel::setPhotoSize(QSize &size)
{
    this->photo_size = size;
}

void PhotoModel::clear()
{
    this->photo_paths.clear();
    this->photos.clear();
    //this->exiffs.clear();
    this->photo_size = QSize();

}


