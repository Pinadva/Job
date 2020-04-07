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

    bool process(QStringList &);
    bool isGoodCount(QStringList &);
    bool isSameSize(const QHash<int, QPixmap> &);
    const QHash<int, QPixmap> &getImages();

    PhotoModel *model;
signals:
    void statusChanged(QString);
};

#endif // PHOTOPRESENTER_H
