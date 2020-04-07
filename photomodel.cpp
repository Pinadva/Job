#include "photomodel.h"

PhotoModel::PhotoModel()
{

}

void PhotoModel::setPaths(QStringList &image_paths)
{
    this->image_paths = image_paths;

    // debug
    for (auto i: this->image_paths)
        qDebug() << i;
    //enddebug
}

const QStringList &PhotoModel::getPaths()
{
    return this->image_paths;
}

void PhotoModel::setImages()
{
    for (QString path: this->image_paths){
        this->images << QImage(path);
    }
}

const QList<QImage> &PhotoModel::getImages()
{
    return this->images;
}

void PhotoModel::setExiffs()
{
    for (auto path: image_paths){
        cout << "=================" << endl;
        Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(path.toStdString());
        assert(image.get() != 0);
        image->readMetadata();

        Exiv2::ExifData &exifData = image->exifData();
            if (exifData.empty()) {
                qDebug() << ": No Exif data found in the file";
                continue;
            }
            //Exiv2::ExifData::const_iterator end = exifData.end();
            try {
                cout << exifData["asdfasdf"] << endl;
                cout << exifData["Exif.Image.FNumber"] << endl;
                cout << exifData["Exif.Photo.ISOSpeedRatings"] << endl;
                cout << exifData["Exif.Photo.Flash"] << endl;
            }  catch (Exiv2::Error& e) {
               std::cout << "Caught Exiv2 exception '" << e.what() << "'\n";
            }

//            cout << exifData["Exif.Image.FNumber"] << endl;
//            cout << exifData["Image.FNumber"].toString();
//            cout << exifData["FNumber"].toString();

//               for (Exiv2::ExifData::const_iterator i = exifData.begin(); i != end; ++i) {
//                   const char* tn = i->typeName();
//                   //qDebug() << QString::fromStdString(i->toString());
//                   std::cout << std::setw(44) << std::setfill(' ') << std::left
//                             << i->key() << " "
//                             << "0x" << std::setw(4) << std::setfill('0') << std::right
//                             << std::hex << i->tag() << " "
//                             << std::setw(9) << std::setfill(' ') << std::left
//                             << (tn ? tn : "Unknown") << " "
//                             << std::dec << std::setw(3)
//                             << std::setfill(' ') << std::right
//                             << i->count() << "  "
//                             << "\n";
//               }
    }
}


