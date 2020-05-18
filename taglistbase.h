#ifndef TAGLISTBASE_H
#define TAGLISTBASE_H

#include <QDebug>
#include <QListWidget>
#include <QObject>
#include <QWidget>

class TagListBase : public QListWidget
{
    Q_OBJECT
public:
    explicit TagListBase(QWidget *parent = nullptr);

public slots:
    void removeTag();
    void removeTag(QPoint);
signals:
};

#endif // TAGLISTBASE_H
