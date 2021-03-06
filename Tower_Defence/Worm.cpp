#include "Worm.h"

int Worm::base_atk = 10;
int Worm::lvup_atk = 5;
double Worm::base_speed = 0.04;
double Worm::lvup_speed = 0.01;
int Worm::base_armor = 0;
int Worm::lvup_armor = 2;

Worm::Worm(string type, double x, double y, double st, int lv) : Monster(type, x, y, st, lv)
{
    this->_atk = base_atk + (_lv-1) * lvup_atk;
    this->_speed = base_speed + (_lv-1) * lvup_speed;
    this->_armor = base_armor + (_lv-1) * lvup_armor;
}
