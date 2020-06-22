#include "Headquarter.h"

Headquarter::Headquarter(string type) : Object(type), _hpBar()
{
    this->_hp = 100;
}

void Headquarter::init_hd(double x, double y)
{
    _x = x;
    _y = y;
    this->_hp = 100;
}

void Headquarter::show(QPainter *painter)
{
    double GS = 2 * Icon::Grid_Size;
    painter->drawImage(this->_x * GS, this->_y * GS, this->_pic);
    _hpBar.show(painter, _hp, _x, _y);
}
