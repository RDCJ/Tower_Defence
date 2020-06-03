#ifndef HEADQUARTER_H
#define HEADQUARTER_H
#include "Object.h"
#include "Monster.h"

class Headquarter : public Object
{
    public:
        Headquarter(string type);
        void be_attacked(int damage) {this->_hp -= damage;}
    protected:
        int _hp;
};

#endif // HEADQUARTER_H
