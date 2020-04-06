#include "photomodel.h"

PhotoModel::PhotoModel()
{

}

void PhotoModel::setPaths(QStringList &image_paths)
{
    this->imagePaths = image_paths;

    // debug
    for (auto i: this->imagePaths)
        qDebug() << i;
    //enddebug
}

const QStringList &PhotoModel::getPaths()
{
    return this->imagePaths;
}

void PhotoModel::setImages()
{
    for (QString path: this->imagePaths){
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


