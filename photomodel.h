#ifndef PHOTOMODEL_H
#define PHOTOMODEL_H

#include <QFileInfo>
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
    const QHash<int, PhotoSegment> &getPhotos();
    void setExif(QHash<QString, QString> &source_keys, QHash<QString, QString> &dist_keys, Exiv2::ExifData &);
    void setSizeExif(QHash<QString, QString> &, Exiv2::ExifData &);
    void clear();

    QStringList photo_paths;
    QHash<int, PhotoSegment> photos; // <i, exif данные>
    ExifKeys keys;
signals:
    void statusChanged(QString, int);

};

#endif // PHOTOMODEL_H
