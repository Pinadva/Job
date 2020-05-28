#include "photosegment.h"

PhotoSegment::PhotoSegment()
{
}

bool operator==(const PhotoSegment &left, const PhotoSegment &right)
{
    if (left.common.size() != right.common.size())
        return false;
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
