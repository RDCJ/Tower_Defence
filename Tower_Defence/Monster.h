#ifndef MONSTER_H
#define MONSTER_H
#include "Object.h"
#include "Road.h"
class Monster : public Object
{
    public:
        static int mATK;
        static double mSPEED;
        Monster(string type);
        int getHp() const {return _hp;};
        void be_shooted(int damage) {this->_hp -= damage;};
        void move(Road r);

    protected:
        int _hp;
        int _pos;//记录怪物在Road序列中的位置

};

#endif // MONSTER_H
