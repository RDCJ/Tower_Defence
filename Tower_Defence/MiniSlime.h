#ifndef MINISLIME_H
#define MINISLIME_H
#include "Monster.h"

class MiniSlime : public Monster
{
    public:
        static int base_atk;
        static int lvup_atk;
        static double base_speed;
        static double lvup_speed;
        static int base_armor;
        static int lvup_armor;
        MiniSlime(string type, double x, double y, int lv);
};

#endif // MINISLIME_H
