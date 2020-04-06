#ifndef PHOTOPRESENTER_H
#define PHOTOPRESENTER_H

#include "photomodel.h"
#include "settingssingleton.h"

class PhotoPresenter
{
public:
    PhotoPresenter();
    ~PhotoPresenter();

    void process(QStringList &);
    bool isGoodSize(QStringList &);
    const QList<QImage> &getImages();

    PhotoModel *model;
};

#endif // PHOTOPRESENTER_H
