#ifndef PHOTOMODEL_H
#define PHOTOMODEL_H
#include <QStringList>
#include <QImage>
#include <QDebug>

class PhotoModel
{
public:
    PhotoModel();
    void setPaths(QStringList &);
    const QStringList &getPaths();
    void setImages();
    const QList<QImage> &getImages();
    void setExiffs();

    QStringList imagePaths;
    QList<QImage> images;
    QStringList exiffs;
};

#endif // PHOTOMODEL_H
