#ifndef WORM_H
#define WORM_H
#include "Monster.h"

class Worm : public Monster
{
    public:
        static int base_atk;
        static int lvup_atk;
        static double base_speed;
        static double lvup_speed;
        Worm(string type, double x, double y, double st, int lv);
};
#endif // WORM_H
