#include "exifextra.h"

ExifExtra::ExifExtra()
{
    extraInit();
}

const QStringList &ExifExtra::getExtra()
{
    return extra;
}

void ExifExtra::extraInit()
{
    extra = QStringList({"Exif.Image.ProcessingSoftware ",
                         "Exif.Image.NewSubfileType",
                         "Exif.Image.SubfileType",
                         "Exif.Image.ImageWidth",
                         "Exif.Image.ImageLength",
                         "Exif.Image.BitsPerSample",
                         "Exif.Image.Compression",
                         "Exif.Image.PhotometricInterpr",
                         "Exif.Image.Thresholding",
                         "Exif.Image.CellWidth",
                         "Exif.Image.CellLength",
                         "Exif.Image.FillOrder",
                         "Exif.Image.DocumentName",
                         "Exif.Image.ImageDescription",
                         "Exif.Image.Make",
                         "Exif.Image.Model",
                         "Exif.Image.StripOffsets",
                         "Exif.Image.Orientation",
                         "Exif.Image.SamplesPerPixel"});
}
