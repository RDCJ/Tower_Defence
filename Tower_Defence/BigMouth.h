#ifndef BIGMOUTH_H
#define BIGMOUTH_H
#include "Monster.h"

class BigMouth : public Monster
{
    public:
        static int base_atk;
        static int lvup_atk;
        static double base_speed;
        static double lvup_speed;
        BigMouth(string type, double x, double y, double st, int lv);
};
#endif // BIGMOUTH_H
