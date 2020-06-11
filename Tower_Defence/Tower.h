#ifndef TOWER_H
#define TOWER_H
#include "Object.h"
#include "Monster.h"
#include "Bullet.h"
#include<vector>
#include <time.h>
#include<iostream>

class Tower : public Object
{
    public:
        static int max_range;
        static int tATK;
        static int price;
        Tower(string type);
        Monster * getTarget() const {return _target;};
        void set_target(Monster * t);
        vector<Bullet> * getBlist() {return &this->bullet_list;};
        void show(QPainter *painter);
        void shoot();

    protected:
        clock_t _start, _stop;
        vector<Bullet> bullet_list;
        Monster * _target;
        double _angle;
};

#endif // TOWER_H
