#include "BigMouth.h"

int BigMouth::base_atk = 10;
int BigMouth::lvup_atk = 5;
double BigMouth::base_speed = 0.03;
double BigMouth::lvup_speed = 0.005;

BigMouth::BigMouth(string type, double x, double y, double st, int lv) : Monster(type, x, y, st, lv)
{
    _armor = 3;
    _atk = base_atk + (_lv-1) * lvup_atk;
    _speed = base_speed + (_lv-1) * lvup_speed;
}
