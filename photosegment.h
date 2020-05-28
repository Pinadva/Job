#ifndef PHOTOSEGMENT_H
#define PHOTOSEGMENT_H

#include <QDebug>
#include <QHash>
#include <QLabel>
#include <QPair>
#include <QPixmap>
#include <QString>

class PhotoSegment
{
public:
    PhotoSegment();
    //    bool operator==(const PhotoSegment &second) const;
    friend bool operator==(const PhotoSegment &first, const PhotoSegment &second);
    friend bool operator!=(const PhotoSegment &first, const PhotoSegment &second);
    QPixmap *photo = nullptr;
    QList<QPair<QString, QString>> unique;
    QList<QPair<QString, QString> *> unique_empty;
    QList<QPair<QString, QString>> unique_extra;
    QList<QPair<QString, QString>> common;
    QList<QPair<QString, QString> *> common_empty;
    QList<QPair<QString, QString>> common_extra;
};

#endif // PHOTOSEGMENT_H
