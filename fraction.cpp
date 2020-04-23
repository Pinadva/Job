#include "fraction.h"

Fraction::Fraction()
{
}

Fraction::Fraction(QString f)
{
    calculate(f);
}

void Fraction::calculate(QString f)
{
    QStringList nums = f.split("/");
    x                = nums.first().toDouble();
    if (nums.first() == nums.last())
        y = 1.;
    else if (nums.last() == "0")
        y = 1.;
    else
        y = nums.last().toDouble();
}

double Fraction::toDouble()
{
    return x / y;
}

double Fraction::toDouble(QString f)
{
    calculate(f);
    return x / y;
}

QString Fraction::stringToDouble(QString f)
{
    calculate(f);
    return QString::number(x / y);
}
