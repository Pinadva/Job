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
        this->model->setPaths(photo_paths);
        this->model->setPhotos();
        if (this->isValid(this->model->getPhotos())){
            emit readyPaint();
        }
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

bool PhotoPresenter::isValid(const QHash<int, PhotoSegment> &photos)
{
    bool same_size = true;
    bool same_exif = true;

    auto size = photos[0].photo->size();
    auto exif = photos[0].common;
    for (auto iter = photos.begin(); iter != photos.end(); ++iter){
        if (size != iter->photo->size()){
            emit statusChanged("Размер фотографий должен быть одинаковым.");
            same_size = false;
            return same_size;
        }
        if (exif != iter->common){
            emit statusChanged("Общие EXIF данные должны быть одинаковыми.");
            same_exif = false;
            return same_exif;
        }
    }
    return true;
}

const QHash<int, PhotoSegment> &PhotoPresenter::getPhotos()
{
    return this->model->getPhotos();
}

const QHash<int, PhotoSegment> &PhotoPresenter::getSegments()
{
    return this->model->getPhotos();
}

