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
    void setExtraExif(QHash<QString, QString> &);
    QHash<QString, QString> getExtraExif();

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
