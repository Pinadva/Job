#include "exifkeys.h"

ExifKeys::ExifKeys()
{
    setSegment();
    setCommon();
}

void ExifKeys::setSegment()
{
    segment["ImageID"]           = "Exif.Image.ImageID";
    segment["ExposureTime"]      = "Exif.Photo.ExposureTime";
    segment["FNumber"]           = "Exif.Photo.FNumber";
    segment["ISO"]               = "Exif.Photo.ISOSpeedRatings";
    segment["ExposureBiasValue"] = "Exif.Photo.ExposureBiasValue";
}

void ExifKeys::setCommon()
{
    common["Make"]             = "Exif.Image.Make";
    common["Model"]            = "Exif.Image.Model";
    common["LensMake"]         = "Exif.Photo.LensMake";
    common["ReelName"]         = "Exif.Image.ReelName";
    common["LensSerialNumber"] = "Exif.Photo.LensSerialNumber";
    common["LensInfo"]         = "Exif.Image.LensInfo";
    common["FocalLength"]      = "Exif.Image.FocalLength";
    common["DateTime"]         = "Exif.Image.DateTime";
    common["ExposureProgram"]  = "Exif.Photo.ExposureProgram";
    common["PixelX"]           = "Exif.Photo.PixelXDimension";
    common["PixelY"]           = "Exif.Photo.PixelYDimension";
}
