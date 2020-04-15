#ifndef PHOTOSEGMENT_H
#define PHOTOSEGMENT_H

#endif // PHOTOSEGMENT_H
#include <QHash>
#include <QPixmap>
#include <QString>

struct PhotoSegment
{
    QPixmap *photo = nullptr;
    QHash<QString, QString> segment;
    QHash<QString, QString> common;
};
