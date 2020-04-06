#include "photopresenter.h"

PhotoPresenter::PhotoPresenter()
{
    this->model = new PhotoModel();
}

PhotoPresenter::~PhotoPresenter()
{
    delete this->model;
}

void PhotoPresenter::process(QStringList &photo_paths)
{

    if (this->isGoodSize(photo_paths)){
        SettingsSingleton::getInstance().setPath(photo_paths.last());
        model->setPaths(photo_paths);
        model->setImages();
        model->setExiffs();
    }
}

bool PhotoPresenter::isGoodSize(QStringList &photo_paths)
{
    bool is_good = false;
    if (!photo_paths.isEmpty()){
        if (photo_paths.size() == 17)
            photo_paths.removeAt(0);
        if (photo_paths.size() == 16)
            is_good = true;
    }
    return is_good;
}

const QList<QImage> &PhotoPresenter::getImages()
{
    return this->model->getImages();
}
