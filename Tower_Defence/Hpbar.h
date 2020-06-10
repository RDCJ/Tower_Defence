#ifndef HPBAR_H
#define HPBAR_H
#include "Object.h"
#include<QPainter>

class Hpbar
{
    public:
        Hpbar();
        void show(QPainter *painter, int hp, double x, double y);
    private:
        Object _hpBarFrame, _hpGreen;
};

#endif // HPBAR_H
