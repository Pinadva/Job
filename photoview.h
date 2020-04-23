#ifndef PHOTOVIEW_H
#define PHOTOVIEW_H

#include "fraction.h"
#include "photopresenter.h"
#include "photosegment.h"
#include "settingssingleton.h"
#include "textbase.h"
#include <QObject>

class PhotoView : public PhotoBase
{
    Q_OBJECT
private:
    PhotoPresenter *presenter = nullptr;
    PhotoModel *model         = nullptr;

    QSize photo_size;
    QSize segment_size;
    int segment_cnt;
    QPixmap result_pixmap;

public:
    PhotoView();
    PhotoView(PhotoPresenter *&);

    void paint();
    void saveResult(QPixmap &);
    QPixmap drawPhotos();
    QPixmap drawCommonExif();
    QPixmap drawSegmentExif(const PhotoSegment &, int &, int &);
    const QPixmap &getResult();
signals:
    void readyView(QPixmap &);
};

#endif // PHOTOVIEW_H
