#include "photosegment.h"

PhotoSegment::PhotoSegment()
{
}

bool operator==(const PhotoSegment &left, const PhotoSegment &right)
{
    if (left.common.size() != right.common.size())
        return false;
    qDebug() << "77777777777777777777777777777777777777777777777777777777777777777777777777";
    for (auto i : left.common)
    {
        qDebug() << i;
    }
    qDebug() << "*************";
    for (auto j : right.common)
    {
        qDebug() << j;
    }
    qDebug() << "77777777777777777777777777777777777777777777777777777777777777777777777777";
    for (int i = 0; i < left.common.size(); ++i)
    {
        if (left.common[i].first != "DateTime" and right.common[i].first != "DateTime")
            if (left.common[i] != right.common[i])
                return false;
    }

    return true;
}

bool operator!=(const PhotoSegment &first, const PhotoSegment &second)
{
    return !(first == second);
}
