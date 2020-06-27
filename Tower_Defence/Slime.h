#ifndef SLIME_H
#define SLIME_H
#include "Monster.h"
#include "MiniSlime.h"

class Slime : public Monster
{
    public:
        static int base_atk;
        static int lvup_atk;
        static double base_speed;
        static double lvup_speed;
        static int base_armor;
        static int lvup_armor;
        Slime(string type, double x, double y, double st, int lv);
};

#endif // SLIME_H
