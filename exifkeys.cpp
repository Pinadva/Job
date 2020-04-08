#include "exifkeys.h"

ExifKeys::ExifKeys()
{
    setSegment();
    setCommon();
}

void ExifKeys::setSegment()
{
    segment["ExposureTime"] = "Exif.Photo.ExposureTime";
    segment["FNumber"] = "Exif.Photo.FNumber";
    segment["ISO"] = "Exif.Photo.ISOSpeedRatings";
    segment["FlashExposureComp"] = "Exif.Sony1.FlashExposureComp";
}

void ExifKeys::setCommon()
{
    common["Make"] = "Exif.Image.Make";
    common["Model"] = "Exif.Image.Model";
    common["LensInfo"] = "Exif.Image.LensInfo";
    common["FocalLength"] = "Exif.Image.FocalLength";
    //megapixels
    common["Width"] = "Exif.Image.ImageWidth";
    common["Length"] = "Exif.Image.ImageLength";
    //modifyDate
    common["ExposureProgram"] = "Exif.Image.ExposureProgram";
    //iso min
    //iso max
}
