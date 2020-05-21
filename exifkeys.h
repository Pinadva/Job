#ifndef EXIFKEYS_H
#define EXIFKEYS_H

#include <QHash>
#include <QPair>
#include <QString>

#include "settingssingleton.h"

class ExifKeys
{
public:
    ExifKeys();

public:
    void setUnique();
    void setUniqueExtra();
    void setCommon();
    void setCommonExtra();
    const QList<QHash<QString, QString>> &getUnique();
    const QList<QHash<QString, QString>> &getUniqueExtra();
    const QList<QHash<QString, QString>> &getCommon();
    const QList<QHash<QString, QString>> &getCommonExtra();

private:
    // <short name, full name> example: <"Make", "Exif.Image.Make">
    QList<QHash<QString, QString>> unique;
    QList<QHash<QString, QString>> unique_extra;
    QList<QHash<QString, QString>> common;
    QList<QHash<QString, QString>> common_extra;
};

#endif // EXIFKEYS_H
