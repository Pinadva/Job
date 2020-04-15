#ifndef SETTINGSSINGLETON_H
#define SETTINGSSINGLETON_H

#include <QDebug>
#include <QDir>
#include <QSettings>

class SettingsSingleton
{
public:
    static SettingsSingleton &getInstance();
    void setPath(QString &);
    QString getPath();

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
