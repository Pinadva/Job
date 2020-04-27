#include "exifkeys.h"

ExifKeys::ExifKeys()
{
    setUnique();
    setCommon();
}

void ExifKeys::setUnique()
{
    unique["ExposureTime"]      = "Exif.Photo.ExposureTime";
    unique["FNumber"]           = "Exif.Photo.FNumber";
    unique["ISO"]               = "Exif.Photo.ISOSpeedRatings";
    unique["ExposureBiasValue"] = "Exif.Photo.ExposureBiasValue";
}

void ExifKeys::setCommon()
{
    similar["Make"]            = "Exif.Image.Make";
    similar["Model"]           = "Exif.Image.Model";
    similar["FocalLength"]     = "Exif.Image.FocalLength";
    similar["DateTime"]        = "Exif.Image.DateTime";
    similar["ExposureProgram"] = "Exif.Photo.ExposureProgram";
    similar["PixelX"]          = "Exif.Photo.PixelXDimension";
    similar["PixelY"]          = "Exif.Photo.PixelYDimension";
}

void ExifKeys::setExtra()
{
}
