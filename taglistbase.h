#ifndef TAGLISTBASE_H
#define TAGLISTBASE_H

#include <QDebug>
#include <QListWidget>
#include <QObject>
#include <QWidget>

#include "tagbase.h"

class TagListBase : public QListWidget
{
    Q_OBJECT
public:
    explicit TagListBase(QString file_name = "", QWidget *parent = nullptr);
    virtual void save()     = 0;
    virtual void loadTags() = 0;

public slots:
    void addTag(TagBaseWidget *);
    void removeTag();
    void removeTag(QPoint);
    bool isValid();
signals:
private:
    QString file_name;
};

#endif // TAGLISTBASE_H
