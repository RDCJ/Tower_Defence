#include "MiniSlime.h"
int MiniSlime::base_atk = 5;
int MiniSlime::lvup_atk = 2;
double MiniSlime::base_speed = 0.03;
double MiniSlime::lvup_speed = 0.01;

MiniSlime::MiniSlime(string type, double x, double y, int lv, int pos) : Slime(type, x, y, 0, lv)
{
    this->_hp = 30;
    this->if_placed = true;
    this->_pos = pos;
    this->_atk = MiniSlime::base_atk + (_lv-1) * MiniSlime::lvup_atk;
    this->_speed = MiniSlime::base_speed + (_lv-1) * MiniSlime::lvup_speed;
}
