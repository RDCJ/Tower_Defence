#include "Slime.h"

int Slime::base_atk = 10;
int Slime::lvup_atk = 5;
double Slime::base_speed = 0.02;
double Slime::lvup_speed = 0.005;
int Slime::base_armor = 5;
int Slime::lvup_armor = 2;


Slime::Slime(string type, double x, double y, double st, int lv) : Monster(type, x, y, st, lv)
{
    this->_atk = base_atk + (_lv-1) * lvup_atk;
    this->_speed = base_speed + (_lv-1) * lvup_speed;
    this->_armor = base_armor + (_lv-1) * lvup_armor;
}
