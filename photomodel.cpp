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

}


