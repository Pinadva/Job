#ifndef EXIFKEYS_H
#define EXIFKEYS_H

#include <QHash>
#include <QString>

#include "settingssingleton.h"

class ExifKeys
{
public:
    ExifKeys();

public:
    void setUnique();
    void setCommon();
    void setExtra();
    const QList<QHash<QString, QString>> &getUnique();
    const QList<QHash<QString, QString>> &getCommon();
    const QList<QHash<QString, QString>> &getExtra();

private:
    // <short name, full name> example: <"Make", "Exif.Image.Make">
    QList<QHash<QString, QString>> unique;
    QList<QHash<QString, QString>> common;
    QList<QHash<QString, QString>> extra;
};

#endif // EXIFKEYS_H
