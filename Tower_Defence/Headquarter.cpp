#include "Headquarter.h"

Headquarter::Headquarter(string type) : Object(type)
{
    this->_hp = 100;
}

void Headquarter::being_attacked()
{
    this->_hp -= 10;
}
