#include "Road.h"

void Road::initRoad()
{
    int xl[17] = {11, 10, 10, 10, 10, 9, 8, 7, 6, 5, 4, 3, 2, 2, 2, 2, 1};
    int yl[17] = {5, 5, 4, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 4, 5, 5};
    for (int i=0;i<17;i++)
    {
        this->Xlist.push_back(xl[i]);
        this->Ylist.push_back(yl[i]);
    }
}
