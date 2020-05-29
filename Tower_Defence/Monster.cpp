#include "Monster.h"

Monster::Monster(string type) : Object(type)
{
    this->_hp = 100;
    this->_pos = 0;
}

void Monster::move(Road r)
{
    if (this->_pos < r.getXlist().size())
    {
        this->_pos++;
        this->_x = r.getXlist()[this->_pos];
        this->_y = r.getYlist()[this->_pos];
    }
}
