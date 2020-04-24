#ifndef EXIFEXTRA_H
#define EXIFEXTRA_H

#include <QStringList>

class ExifExtra
{
private:
    QStringList extra;

    void extraInit();

public:
    ExifExtra();
    const QStringList &getExtra();
};

#endif // EXIFEXTRA_H
