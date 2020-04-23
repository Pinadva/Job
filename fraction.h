#ifndef FRACTION_H
#define FRACTION_H

#include <QString>
#include <QStringList>

class Fraction
{
    double x, y;

public:
    Fraction();
    Fraction(QString);

    void calculate(QString);
    double toDouble();
    double toDouble(QString);
    QString stringToDouble(QString);
};

#endif // FRACTION_H
