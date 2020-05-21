#ifndef SETTINGSSINGLETON_H
#define SETTINGSSINGLETON_H

#include <QByteArray>
#include <QDataStream>
#include <QDebug>
#include <QDir>
#include <QHash>
#include <QSettings>

class SettingsSingleton
{
public:
    static SettingsSingleton &getInstance();
    void setPath(QString &);
    QString getPath();
    void setExtraExif(QList<QHash<QString, QString>> &, QString);
    QList<QHash<QString, QString>> getExtraExif(QString tag_kind);

private:
    SettingsSingleton();
    ~SettingsSingleton()                         = default;
    SettingsSingleton(const SettingsSingleton &) = delete;
    SettingsSingleton &operator=(const SettingsSingleton &) = delete;
    SettingsSingleton(SettingsSingleton &&)                 = delete;
    SettingsSingleton &operator=(SettingsSingleton &&) = delete;

    QSettings *settings;
};

#endif // SETTINGSSINGLETON_H
