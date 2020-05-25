#ifndef PHOTOMODEL_H
#define PHOTOMODEL_H

#include "fraction.h"
#include "photobase.h"
#include "photosegment.h"

#include <QApplication>
#include <QByteArray>
#include <QDebug>
#include <QFileInfo>
#include <QHash>
#include <QImage>
#include <QPixmap>
#include <QRegularExpression>
#include <QStringList>
#include <exifkeys.h>
#include <exiv2/exiv2.hpp>
#include <iostream>

using namespace std;

class PhotoModel : public PhotoBase
{
public:
    PhotoModel();
    void setExifKeys();
    void setPaths(QStringList &);
    const QStringList &getPaths();
    void setPhotos();
    QHash<int, PhotoSegment> &getPhotos();
    void setExif(const QList<QHash<QString, QString>> &source_keys,
                 QList<QPair<QString, QString>> &tags,
                 QList<QPair<QString, QString> *> &);
    void setSizeExif(QList<QPair<QString, QString>> &);
    void clear();
    QString createTagText(Exiv2::ExifKey &, string);
    void setComment(QString);
    QString getComment();

    QStringList photo_paths;
    QHash<int, PhotoSegment> photos; // <i, exif данные>
    ExifKeys keys;
    Exiv2::ExifData data;
    QHash<QString, QString> exposure_programm_human;
    QString comment;
};

#endif // PHOTOMODEL_H
