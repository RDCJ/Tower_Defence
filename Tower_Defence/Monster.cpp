#include "Monster.h"

Monster::Monster(string type) : Object(type)
{
    this->_hp = 100;
}

void Monster::move(int direction)
{
    //1, 2, 3, 4: 上 下 左 右
    switch (direction)
    {
        case 1:
            this->_y--;
            break;
        case 2:
            this->_y++;
            break;
        case 3:
            this->_x--;
            break;
        case 4:
            this->_x++;
            break;
    }
}
