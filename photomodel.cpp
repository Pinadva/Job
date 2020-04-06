#include "photomodel.h"

PhotoModel::PhotoModel()
{

}

void PhotoModel::setPaths(QStringList &imagePaths)
{
    this->imagePaths = imagePaths;

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

void PhotoModel::setExiffs()
{

}


