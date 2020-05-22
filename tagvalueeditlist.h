#ifndef TAGVALUEEDITLIST_H
#define TAGVALUEEDITLIST_H

#include "settingssingleton.h"
#include "tagkeyedit.h"
#include "taglistbase.h"
#include "tagvalueedit.h"

#include <QDebug>
#include <QHash>
#include <QList>
#include <QPair>
#include <QString>

class TagValueEditList : public TagListBase
{
public:
    TagValueEditList(QString file_name = "", QWidget *parent = nullptr);
    void setPhotos(QHash<int, QString> &);
    void setEmptyTags(QList<QPair<QString, QString> *> &empty_tags);

    // TagListBase interface
public:
    void save() override;
    void loadTags() override;

private:
    QHash<int, QString> photos;
    QList<QPair<QString, QString> *> empty_tags;
};

#endif // TAGVALUEEDITLIST_H
