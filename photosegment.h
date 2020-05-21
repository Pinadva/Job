#ifndef PHOTOSEGMENT_H
#define PHOTOSEGMENT_H

#include <QHash>
#include <QLabel>
#include <QPair>
#include <QPixmap>
#include <QString>

struct PhotoSegment
{
    QPixmap *photo = nullptr;
    QList<QPair<QString, QString>> unique;
    QList<QPair<QString, QString>> common;
    QList<QPair<QString, QString>> extra;
};
#endif // PHOTOSEGMENT_H
