#ifndef TAGVALUEEDITTABLE_H
#define TAGVALUEEDITTABLE_H

#include "photosegment.h"
#include "tagvalueedit.h"

#include <QHash>
#include <QObject>
#include <QWidget>

class TagValueEditTable : public QWidget
{
    Q_OBJECT
public:
    explicit TagValueEditTable(QWidget *parent = nullptr);

signals:
};

#endif // TAGVALUEEDITTABLE_H
