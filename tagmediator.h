#ifndef TAGMEDIATOR_H
#define TAGMEDIATOR_H

#include "photosegment.h"
#include "tagvalueeditlist.h"

#include <QHash>
#include <QList>
#include <QPair>
#include <QString>

class TagMediator
{
public:
    TagMediator();
    void setPhotos(QHash<int, PhotoSegment> &);
    QHash<int, PhotoSegment> &getPhotos();

private:
    QHash<int, PhotoSegment> photos;
    QList<QPair<QString, QString> *> common_empty;
    TagValueEditList tag_value_edit_list;
};

#endif // TAGMEDIATOR_H
