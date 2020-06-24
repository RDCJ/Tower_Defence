#ifndef SLIME_H
#define SLIME_H
#include "Monster.h"

class Slime : public Monster
{
    public:
        static int base_atk;
        static int lvup_atk;
        static double base_speed;
        static double lvup_speed;
        Slime(string type, double x, double y, double st, int lv);
};

#endif // SLIME_H
