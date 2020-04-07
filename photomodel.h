#ifndef PHOTOMODEL_H
#define PHOTOMODEL_H

#include <QSize>
#include <QStringList>
#include <QImage>
#include <QDebug>
#include <exiv2/exiv2.hpp>
#include <QHash>
#include <iostream>
#include <QPixmap>

using namespace std;

class PhotoModel
{
public:
    PhotoModel();
    void setPaths(QStringList &);
    const QStringList &getPaths();
    void setPhotos();
    const QHash<int, QPixmap> &getPhotos();
    void setExiffs();
    void setPhotoSize(QSize &);
    void clear();

    QStringList photo_paths;
    QHash<int, QPixmap> photos;
    QStringList exiffs;
    QSize photo_size;

};

#endif // PHOTOMODEL_H
