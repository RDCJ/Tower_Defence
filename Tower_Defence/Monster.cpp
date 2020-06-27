#include "Monster.h"
#include <cmath>

Monster::Monster(string type, double x, double y, double st, int lv) : Object(type), _hpBar()
{
    this->_hp = 100;
    this->_pos = 0;
    this->_x = x;
    this->_y = y;
    this->_lv = lv;
    this->_shield = 0;
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
            this->_x += _speed * deltaX;
            this->_y += _speed * deltaY;
            adjustPos(r.getXlist()[nextPos], r.getYlist()[nextPos], nextPos);
        }
}


void Monster::show(QPainter *painter)
{
    if (if_placed == true && _alive == true)
    {
        double GS = 2 * Icon::Grid_Size;
        painter->drawImage(_x * GS, (_y+0.2) * GS, _pic);
        _hpBar.show(painter, _hp, _x, _y);

        QString LV = "Lv." + QString::number(_lv);
        QFont font("Microsoft YaHei", 8, QFont::DemiBold);

        painter->setFont(font);
        painter->drawText(_x * GS + 5, _y * GS - 5, LV);
        painter->resetTransform();
    }
}


void Monster::be_shooted(int damage)
{
    if (_shield > 0) _shield--;
    else if (damage >= _armor) _hp = _hp - (damage - _armor);
}


void Monster::adjustPos(double x, double y, int pos)
{
      if ( abs(this->_x - x) < 0.2  &&  abs(this->_y - y) < 0.2 ) this->_pos = pos;
}


void Monster::setPos(double x, double y, int pos)
{
    _x = x;
    _y = y;
    _pos = pos;
}
