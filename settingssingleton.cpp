#include "settingssingleton.h"

SettingsSingleton::SettingsSingleton()
{
    this->settings = new QSettings("settings.txt", QSettings::IniFormat);
}

SettingsSingleton &SettingsSingleton::getInstance()
{
    static SettingsSingleton self;
    return self;
}

void SettingsSingleton::setPath(QString &path_to_last_file)
{
    this->settings->setValue("path", path_to_last_file);
}

QString SettingsSingleton::getPath()
{
    return this->settings->value("path").toString();
}
