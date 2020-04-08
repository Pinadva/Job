#ifndef EXIFKEYS_H
#define EXIFKEYS_H

#include <QHash>
#include <QString>

class ExifKeys
{
public:
    ExifKeys();

    QHash<QString, QString> segment; // <short name, full name> example: <"Make", "Exif.Image.Make">
    QHash<QString, QString> common; // <short name, full name> example: <"Make", "Exif.Image.Make">
private:
    void setSegment();
    void setCommon();
};

#endif // EXIFKEYS_H
