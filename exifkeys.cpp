#include "exifkeys.h"

ExifKeys::ExifKeys()
{
    setSegment();
    setCommon();
}

void ExifKeys::setSegment()
{
    segment["Make"] = "Exif.Image.Make";
    segment["Model"] = "Exif.Image.Model";
    segment["ExposureTime"] = "Exif.Photo.ExposureTime";
    segment["FNumber"] = "Exif.Photo.FNumber";
    segment["ISOSpeedRatings"] = "Exif.Photo.ISOSpeedRatings";
    segment["FlashExposureComp"] = "Exif.Sony1.FlashExposureComp";
}

void ExifKeys::setCommon()
{

}
