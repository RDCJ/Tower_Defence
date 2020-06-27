#ifndef HEADQUARTER_H
#define HEADQUARTER_H
#include "Object.h"
#include "Monster.h"
#include "Hpbar.h"

class Headquarter : public Object
{
    public:
        Headquarter(string type);
        void be_attacked(int damage) {this->_hp -= damage;}
        void init_hd(double x, double y);
        int getHP() const {return this->_hp;};
        void show(QPainter *painter);

    protected:
        int _hp;
        Hpbar _hpBar;
};

#endif // HEADQUARTER_H
