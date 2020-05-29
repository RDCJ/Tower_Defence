#ifndef MONSTER_H
#define MONSTER_H
#include "Object.h"

class Monster : public Object
{
    public:
        Monster(string type);
        int getHp() const {return _hp;};
        void move(int direction);
    protected:
        int _hp;
};

#endif // MONSTER_H
