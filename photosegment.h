#ifndef PHOTOSEGMENT_H
#define PHOTOSEGMENT_H

#include <QHash>
#include <QPixmap>
#include <QString>

struct PhotoSegment
{
    QPixmap *photo = nullptr;
    QHash<QString, QString> segment;
    QHash<QString, QString> common;
};
#endif // PHOTOSEGMENT_H
