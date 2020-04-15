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
#include <exiv2/exiv2.hpp>
#include <iostream>

#include <exifkeys.h>
#include <photosegment.h>

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
