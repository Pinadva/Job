#ifndef TAGVALUEEDITLIST_H
#define TAGVALUEEDITLIST_H

#include "settingssingleton.h"
#include "tagkeyedit.h"
#include "taglistbase.h"
#include "tagvalueedit.h"

#include <QDebug>
#include <QList>
#include <QPair>
#include <QString>

class TagValueEditList : public TagListBase
{
public:
    TagValueEditList(QString file_name = "", QWidget *parent = nullptr);
    void setEmptyTags(QList<QPair<QString, QString> *> &emty_tags);

    // TagListBase interface
public:
    void saveTags() override;
    void loadTags() override;

private:
    QList<QPair<QString, QString> *> empty_tags;
};

#endif // TAGVALUEEDITLIST_H
