#ifndef PHOTOMODEL_H
#define PHOTOMODEL_H
#include <QStringList>
#include <QImage>
#include <QDebug>
#include <exiv2/exiv2.hpp>

using namespace std;

class PhotoModel
{
public:
    PhotoModel();
    void setPaths(QStringList &);
    const QStringList &getPaths();
    void setImages();
    const QList<QImage> &getImages();
    void setExiffs();

    QStringList image_paths;
    QList<QImage> images;
    QStringList exiffs;
};

#endif // PHOTOMODEL_H
