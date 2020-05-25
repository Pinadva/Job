#include "exifkeys.h"

ExifKeys::ExifKeys()
{
    setUnique();
    setUniqueExtra();
    setCommon();
    setCommonExtra();
}

void ExifKeys::setUnique()
{
    unique.append(QHash<QString, QString> {{"ExposureTime", "Exif.Photo.ExposureTime"}});
    unique.append(QHash<QString, QString> {{"FNumber", "Exif.Photo.FNumber"}});
    unique.append(QHash<QString, QString> {{"ISO", "Exif.Photo.ISOSpeedRatings"}});
    unique.append(QHash<QString, QString> {{"ExposureBiasValue", "Exif.Photo.ExposureBiasValue"}});
    //    unique.append(QHash<QString, QString> {{"FocalLength", "Exif.Image.FocalLength"}});
}

void ExifKeys::setUniqueExtra()
{
    unique_extra = SettingsSingleton::getInstance().getExtraExif("unique_extra");
}

void ExifKeys::setCommon()
{
    common.append(QHash<QString, QString> {{"Make", "Exif.Image.Make"}});
    common.append(QHash<QString, QString> {{"Model", "Exif.Image.Model"}});
    common.append(QHash<QString, QString> {{"FocalLength", "Exif.Photo.FocalLength"}});
    common.append(QHash<QString, QString> {{"DateTime", "Exif.Image.DateTime"}});
    common.append(QHash<QString, QString> {{"ExposureProgram", "Exif.Photo.ExposureProgram"}});
}

void ExifKeys::setCommonExtra()
{
    qDebug() << "***********************************************";
    qDebug() << "setCommonExtra";
    common_extra = SettingsSingleton::getInstance().getExtraExif("common_extra");
    //    for (auto item : extra)
    //    {
    //        qDebug() << item;
    //    }
    qDebug() << "***********************************************";
}

const QList<QHash<QString, QString>> &ExifKeys::getUnique()
{
    return unique;
}

const QList<QHash<QString, QString>> &ExifKeys::getUniqueExtra()
{
    return unique_extra;
}

const QList<QHash<QString, QString>> &ExifKeys::getCommon()
{
    return common;
}

const QList<QHash<QString, QString>> &ExifKeys::getCommonExtra()
{
    return common_extra;
}
