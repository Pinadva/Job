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

    if (this->isGoodCount(photo_paths)){
        SettingsSingleton::getInstance().setPath(photo_paths.last());
        model->setPaths(photo_paths);
        model->setPhotos();
        if (this->isSameSize(this->model->getPhotos()))
        //model->setExiffs();
            emit readyPaint();
        else
            this->model->clear();
    }
}

bool PhotoPresenter::isGoodCount(QStringList &photo_paths)
{
    bool is_good = false;
    if (!photo_paths.isEmpty()){
        if (photo_paths.size() == 17)
            photo_paths.removeAt(0);
        if (photo_paths.size() == 16)
            is_good = true;
        else {
            emit statusChanged("Выбрано неверное количество файлов. Необходимо 16 или 17 файлов.");
        }
    }
    return is_good;
}

const QHash<int, QPixmap> &PhotoPresenter::getImages()
{
    return this->model->getPhotos();
}

bool PhotoPresenter::isSameSize(const QHash<int, QPixmap> &photos)
{
    auto size = photos[0].size();
    for (auto iter = photos.begin(); iter != photos.end(); ++iter){
        qDebug() << iter->size();
        if (size != iter->size()){
            emit statusChanged("Размер фотографий должен быть одинаковым.");
            return false;
        }
    }
    this->model->setPhotoSize(size);
    return true;
}
