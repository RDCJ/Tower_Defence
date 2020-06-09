#ifndef HEADQUARTER_H
#define HEADQUARTER_H
#include "Object.h"
#include "Monster.h"

class Headquarter : public Object
{
    public:
        Headquarter(string type);
        void be_attacked(int damage) {this->_hp -= damage;}
        int getHP() const {return this->_hp;};
        void show(QPainter *painter);

    protected:
        int _hp;
};

#endif // HEADQUARTER_H
