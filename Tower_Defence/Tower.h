#ifndef TOWER_H
#define TOWER_H
#include "Object.h"
#include "Monster.h"

class Tower : public Object
{
    public:
        Tower(string type);
        void shoot(Monster target);

    protected:

};

#endif // TOWER_H
