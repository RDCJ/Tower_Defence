#ifndef MINISLIME_H
#define MINISLIME_H
#include "Slime.h"

class MiniSlime : public Slime
{
    public:
        static int base_atk;
        static int lvup_atk;
        static double base_speed;
        static double lvup_speed;
        MiniSlime(string type, double x, double y, int lv, int pos);
};

#endif // MINISLIME_H
