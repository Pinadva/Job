#ifndef EXIFKEYS_H
#define EXIFKEYS_H

#include <QHash>
#include <QString>

class ExifKeys
{
public:
    ExifKeys();

    QHash<QString, QString> segment;
    QHash<QString, QString> common;
private:
    void setSegment();
    void setCommon();
};

#endif // EXIFKEYS_H
