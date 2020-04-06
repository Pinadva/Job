#ifndef SETTINGSSINGLETON_H
#define SETTINGSSINGLETON_H

#include <QSettings>

class SettingsSingleton
{
public:
    static SettingsSingleton &instance();
    void setPath(QString &);
private:
    SettingsSingleton();
    ~SettingsSingleton()              = default;
    SettingsSingleton(const SettingsSingleton &) = delete;
    SettingsSingleton &operator=(const SettingsSingleton &) = delete;
    SettingsSingleton(SettingsSingleton &&)                 = delete;
    SettingsSingleton &operator=(SettingsSingleton &&) = delete;

    QSettings *settings;
};

#endif // SETTINGSSINGLETON_H
