#ifndef PHOTOPRESENTER_H
#define PHOTOPRESENTER_H

#include "photomodel.h"
#include "settingssingleton.h"

#include <QObject>

class PhotoPresenter : public QObject
{
    Q_OBJECT

public:
    PhotoPresenter();
    ~PhotoPresenter();

    void process(QStringList &);
    bool isGoodCount(QStringList &);
    bool isValid(const QHash<int, PhotoSegment> &);
    bool isGoodSize(const QHash<int, PhotoSegment> &);
    bool isSameExifs(const QHash<int, PhotoSegment> &photos);
    const QHash<int, PhotoSegment> &getPhotos();
    const QHash<int, PhotoSegment> &getSegments();

    PhotoModel *model;
signals:
    void statusChanged(QString, int);
    void readyPaint();
};

#endif // PHOTOPRESENTER_H
