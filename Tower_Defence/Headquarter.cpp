#include "Headquarter.h"

Headquarter::Headquarter(string type) : Object(type)
{
    this->_hp = 100;
}

void Headquarter::show(QPainter *painter)
{
    double GS = 74;
    painter->drawImage(this->_x * GS, this->_y * GS, this->_pic);
}
