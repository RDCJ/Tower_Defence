#ifndef BULLET_H
#define BULLET_H
#include "Object.h"
#include "Monster.h"
#include "Setting.h"

class Bullet : public Object
{
    public:
        static double bSPEED;
        Bullet(string type, double x, double y, Monster * t);
        Monster * getTarget() const {return this->_target;};
        void set_target(Monster * t) {this->_target = t;};
        void show(QPainter *painter);
        void move();
        ~Bullet() {};

    protected:
        Monster * _target;
        double _angle;
};

#endif // BULLET_H
