#include "MiniSlime.h"

int MiniSlime::base_atk = 5;
int MiniSlime::lvup_atk = 2;
double MiniSlime::base_speed = 0.03;
double MiniSlime::lvup_speed = 0.01;
int MiniSlime::base_armor = 3;
int MiniSlime::lvup_armor = 2;

MiniSlime::MiniSlime(string type, double x, double y, int lv) : Monster(type, x, y, 0, lv)
{
    this->_hp = 30;
    this->if_placed = false;
    this->_atk = base_atk + (_lv-1) * lvup_atk;
    this->_speed = base_speed + (_lv-1) * lvup_speed;
    this->_armor = base_armor + (_lv-1) * lvup_armor;
}

