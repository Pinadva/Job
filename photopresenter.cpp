#include "photopresenter.h"

PhotoPresenter::PhotoPresenter()
{
    this->model = new PhotoModel();
}

PhotoPresenter::PhotoPresenter(PhotoModel *&model)
{
    this->model = model;
}

PhotoPresenter::~PhotoPresenter()
{
    delete this->model;
}

void PhotoPresenter::process(QStringList &photo_paths)
{
    if (this->isGoodCount(photo_paths))
    {
        SettingsSingleton::getInstance().setPath(photo_paths.last());
        this->model->setPaths(photo_paths);
        this->model->setPhotos();
        if (this->isValid(this->model->getPhotos()))
        {
            qDebug() << "paint";
            emit statusChanged("Успешно.", 1);
            emit readyPaint();
        }
        else
        {
            qDebug() << "invalid";
            this->model->clear();
        }
    }
}

bool PhotoPresenter::isGoodCount(QStringList &photo_paths)
{
    bool is_good = false;
    if (!photo_paths.isEmpty())
    {
        if (photo_paths.size() == 17)
            photo_paths.removeAt(0);
        if (photo_paths.size() == 16)
            is_good = true;
        else
        {
            emit statusChanged("Выбрано неверное количество файлов. Необходимо 16 или 17 файлов.", -1);
        }
    }
    return is_good;
}

bool PhotoPresenter::isValid(const QHash<int, PhotoSegment> &photos)
{
    if (!this->isDateTimeExists(photos))
        return false;

    if (!this->isGoodSize(photos))
        return false;

    if (!this->isSameExifs(photos))
        return false;

    return true;
}

bool PhotoPresenter::isDateTimeExists(const QHash<int, PhotoSegment> &photos)
{
    auto common = photos[0].common;
    qDebug() << common.keys();
    if (common.find("DateTime") == common.end())
    {
        emit statusChanged("В exif данных отсутствует поле даты и времени", -1);
        return false;
    }
    return true;
}

bool PhotoPresenter::isGoodSize(const QHash<int, PhotoSegment> &photos)
{
    auto size = photos[0].photo->size();

    for (auto iter = photos.begin(); iter != photos.end(); ++iter)
    {
        if (size != iter.value().photo->size())
        {
            emit statusChanged("Размер фотографий должен быть одинаковым.", -1);
            return false;
        }
    }
    return true;
}

bool PhotoPresenter::isSameExifs(const QHash<int, PhotoSegment> &photos)
{
    auto exif = photos[0].common;

    for (auto i = photos.begin(); i != photos.end(); ++i)
    {
        for (auto key : exif.keys())
        {
            if (key != "DateTime")
            {
                if (exif[key] != i->common[key])
                {
                    emit statusChanged("Общие exif данные должны быть одинаковыми.", -1);
                    return false;
                }
            }
        }
    }
    return true;
}

const QHash<int, PhotoSegment> &PhotoPresenter::getPhotos()
{
    return this->model->getPhotos();
}
