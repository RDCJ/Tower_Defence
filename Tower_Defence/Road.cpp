#include "Road.h"

void Road::initRoad(int l, int xl[], int yl[])
{
    this->_len = l;
    for (int i=0; i<l; i++)
    {
        this->Xlist.push_back(xl[i]);
        this->Ylist.push_back(yl[i]);
    }
}
