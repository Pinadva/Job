#include "settingssingleton.h"

SettingsSingleton::SettingsSingleton()
{
    this->settings = new QSettings("settings.txt", QSettings::IniFormat);
}

SettingsSingleton &SettingsSingleton::instance()
{
    static SettingsSingleton self;
    return self;
}

void SettingsSingleton::setPath(QString &pathToLastFile)
{
    this->settings->setValue("path", pathToLastFile);
}

QString SettingsSingleton::getPath()
{
    return this->settings->value("path").toString();
}
