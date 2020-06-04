#include "Monster.h"
#include <cmath>
int Monster::mATK = 10;
double Monster::mSPEED = 0.1;

Monster::Monster(string type) : Object(type)
{
    this->_hp = 100;
    this->_pos = 0;
}

void Monster::move(Road r)
{
    if (this->_pos < r.getXlist().size())
    {
        int nextPos = this->_pos + 1;
        int deltaX = r.getXlist()[nextPos] - r.getXlist()[this->_pos];
        int deltaY = r.getYlist()[nextPos] - r.getYlist()[this->_pos];
        this->_x += mSPEED*deltaX;
        this->_y += mSPEED*deltaY;
        if ( abs(this->_x - r.getXlist()[nextPos]) < 0.1  &&  abs(this->_y - r.getYlist()[nextPos]) < 0.1 ) this->_pos++;
    }
}

