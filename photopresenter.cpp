#include "photopresenter.h"

PhotoPresenter::PhotoPresenter()
{
    this->model = new PhotoModel();
}

PhotoPresenter::~PhotoPresenter()
{
    delete this->model;
}

void PhotoPresenter::process(QStringList &photoPaths)
{

    if (this->isGoodSize(photoPaths)){
        SettingsSingleton::getInstance().setPath(photoPaths.last());
        model->setPaths(photoPaths);
        model->setImages();
        model->setExiffs();
    }
}

bool PhotoPresenter::isGoodSize(QStringList &photoPaths)
{
    bool isGood = false;
    if (!photoPaths.isEmpty()){
        if (photoPaths.size() == 17)
            photoPaths.removeAt(0);
        if (photoPaths.size() == 16)
            isGood = true;
    }
    return isGood;
}
