#include "exifkeys.h"

ExifKeys::ExifKeys()
{
    setUnique();
    setCommon();
    setExtra();
}

void ExifKeys::setUnique()
{
    unique.append(QHash<QString, QString> {{"ExposureTime", "Exif.Photo.ExposureTime"}});
    unique.append(QHash<QString, QString> {{"FNumber", "Exif.Photo.FNumber"}});
    unique.append(QHash<QString, QString> {{"ISO", "Exif.Photo.ISOSpeedRatings"}});
    unique.append(QHash<QString, QString> {{"ExposureBiasValue", "Exif.Photo.ExposureBiasValue"}});
}

void ExifKeys::setCommon()
{
    common.append(QHash<QString, QString> {{"Make", "Exif.Image.Make"}});
    common.append(QHash<QString, QString> {{"Model", "Exif.Image.Model"}});
    common.append(QHash<QString, QString> {{"FocalLength", "Exif.Photo.FocalLength"}});
    common.append(QHash<QString, QString> {{"DateTime", "Exif.Image.DateTime"}});
    common.append(QHash<QString, QString> {{"ExposureProgram", "Exif.Photo.ExposureProgram"}});
}

void ExifKeys::setExtra()
{
    extra = SettingsSingleton::getInstance().getExtraExif();
}

const QList<QHash<QString, QString>> &ExifKeys::getUnique()
{
    return unique;
}

const QList<QHash<QString, QString>> &ExifKeys::getCommon()
{
    return common;
}

const QList<QHash<QString, QString>> &ExifKeys::getExtra()
{
    return extra;
}
