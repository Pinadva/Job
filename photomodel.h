#ifndef PHOTOMODEL_H
#define PHOTOMODEL_H

#include <QApplication>
#include <QByteArray>
#include <QDebug>
#include <QFileInfo>
#include <QHash>
#include <QImage>
#include <QPixmap>
#include <QStringList>
#include <exifkeys.h>
#include <exiv2/exiv2.hpp>
#include <iostream>

#include "fraction.h"
#include "photobase.h"
#include "photosegment.h"

using namespace std;

class PhotoModel : public PhotoBase
{
private:
    void setExifKeys();

public:
    PhotoModel();
    void setPaths(QStringList &);
    const QStringList &getPaths();
    void setPhotos();
    const QHash<int, PhotoSegment> &getPhotos();
    void setExif(const QList<QHash<QString, QString>> &source_keys, QList<QHash<QString, QString>> &dist_keys, Exiv2::ExifData &);
    void setSizeExif(QList<QHash<QString, QString>> &, Exiv2::ExifData &);
    void clear();
    QString createTagText(Exiv2::ExifKey, Exiv2::ExifData &);

    QStringList photo_paths;
    QHash<int, PhotoSegment> photos; // <i, exif данные>
    ExifKeys keys;
};

#endif // PHOTOMODEL_H
