#ifndef TOWER_H
#define TOWER_H
#include "Object.h"
#include "Monster.h"

class Tower : public Object
{
    public:
        Tower(string type);
        Monster * getTarget() const {return _target;};
        void set_target(Monster * t) {this->_target = t;};
        void detect_monster();
        void shoot(Monster target);
        void show(QPainter *painter);
    protected:
        Monster * _target;
        double _angle;
};

#endif // TOWER_H
