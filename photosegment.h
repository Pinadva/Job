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
    QList<QPair<QString, QString> *> unique_empty;
    QList<QPair<QString, QString>> unique_extra;
    QList<QPair<QString, QString>> common;
    QList<QPair<QString, QString> *> common_empty;
    QList<QPair<QString, QString>> common_extra;
};
#endif // PHOTOSEGMENT_H
