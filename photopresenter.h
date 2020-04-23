#ifndef PHOTOPRESENTER_H
#define PHOTOPRESENTER_H

#include "photomodel.h"
#include "settingssingleton.h"

#include <QObject>

class PhotoPresenter : public PhotoBase
{
    Q_OBJECT

public:
    PhotoPresenter();
    PhotoPresenter(PhotoModel *&);
    ~PhotoPresenter();

    void process(QStringList &);
    bool isGoodCount(QStringList &);
    bool isValid(const QHash<int, PhotoSegment> &);
    bool isDateTimeExists(const QHash<int, PhotoSegment> &);
    bool isGoodSize(const QHash<int, PhotoSegment> &);
    bool isSameExifs(const QHash<int, PhotoSegment> &);
    const QHash<int, PhotoSegment> &getPhotos();

    PhotoModel *model = nullptr;
signals:
    void readyPaint();
};

#endif // PHOTOPRESENTER_H
