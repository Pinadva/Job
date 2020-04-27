#ifndef PHOTOSEGMENT_H
#define PHOTOSEGMENT_H

#include <QHash>
#include <QPixmap>
#include <QString>

struct PhotoSegment
{
    QPixmap *photo = nullptr;
    QList<QHash<QString, QString>> unique;
    QList<QHash<QString, QString>> common;
    QList<QHash<QString, QString>> extra;
};
#endif // PHOTOSEGMENT_H
