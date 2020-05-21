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
    qDebug() << "path_to_last_file" << path_to_last_file;
    QDir last_dir(path_to_last_file);
    last_dir.cdUp();
    qDebug() << "last dir" << last_dir.path();
    this->settings->setValue("path", last_dir.path());
}

QString SettingsSingleton::getPath()
{
    return this->settings->value("path").toString();
}

void SettingsSingleton::setExtraExif(QList<QHash<QString, QString>> &data, QString tag_kind)
{
    QByteArray bytes;
    QDataStream ds(&bytes, QIODevice::WriteOnly);
    ds << data;
    this->settings->setValue(tag_kind, bytes);
}

QList<QHash<QString, QString>> SettingsSingleton::getExtraExif()
{
    QList<QHash<QString, QString>> data;
    QByteArray bytes = this->settings->value("extra_exif").toByteArray();
    QDataStream ds(&bytes, QIODevice::ReadOnly);
    ds >> data;

    return data;
}
