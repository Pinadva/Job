#ifndef EXIFKEYS_H
#define EXIFKEYS_H

#include <QHash>
#include <QString>

#include "settingssingleton.h"

class ExifKeys
{
public:
    ExifKeys();

    QHash<QString, QString> unique;  // <short name, full name> example: <"Make", "Exif.Image.Make">
    QHash<QString, QString> similar; // <short name, full name> example: <"Make", "Exif.Image.Make">
    QHash<QString, QString> extra;

private:
    void setUnique();
    void setCommon();
    void setExtra();
};

#endif // EXIFKEYS_H
