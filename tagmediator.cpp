#include "tagmediator.h"

TagMediator::TagMediator()
{
}

void TagMediator::setPhotos(QHash<int, PhotoSegment> &photos)
{
    this->photos = photos;
}

QHash<int, PhotoSegment> &TagMediator::getPhotos()
{
    return this->photos;
}
