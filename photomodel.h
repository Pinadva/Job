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

#include <photosegment.h>
#include <exifkeys.h>

using namespace std;

class PhotoModel
{
private:
    void setExifKeys();

public:
    PhotoModel();
    void setPaths(QStringList &);
    const QStringList &getPaths();
    void setPhotos();
    const QHash<int, QPixmap> &getPhotos();
    const QHash<int, PhotoSegment> &getSegments();
    void setSegments();
    void setPhotoSize(QSize &);
    void clear();

    QStringList photo_paths;
    QHash<int, QPixmap> photos;
    QHash<int, PhotoSegment> segments; // <i, exif данные>
    ExifKeys keys;
    QSize photo_size;


};

#endif // PHOTOMODEL_H
