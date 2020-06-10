#include "Monster.h"
#include <cmath>
int Monster::mATK = 10;
double Monster::mSPEED = 0.05;

Monster::Monster(string type, double x, double y, double st) : Object(type), _hpBar()
{
    this->_hp = 100;
    this->_pos = 0;
    this->_x = x;
    this->_y = y;
    this->show_time = st;
    this->_alive = true;
    this->if_placed = false;
}

void Monster::move(Road r)
{
    if (if_placed && _alive)
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

void Monster::show(QPainter *painter)
{
    if (if_placed == true && _alive == true)
    {
        double GS = 2 * Icon::Grid_Size;
        painter->drawImage(_x * GS, (_y+0.2) * GS, _pic);
        _hpBar.show(painter, _hp, _x, _y);
    }
}

