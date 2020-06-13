#ifndef TOWER_H
#define TOWER_H
#include "Object.h"
#include "Monster.h"
#include "Bullet.h"
#include<vector>
#include <time.h>
#include<iostream>
#include<QString>
class Tower : public Object
{
    public:
        static int max_range;
        static int price;
        Tower(string type);
        Monster * getTarget() const {return _target;};
        void set_target(Monster * t);
        int getATK() const {return _atk;};
        vector<Bullet> * getBlist() {return &this->bullet_list;};
        void show(QPainter *painter);
        void shoot();
        void lvlup();

    protected:
        int _atk;
        clock_t _start, _stop;
        vector<Bullet> bullet_list;
        Monster * _target;
        double _angle;
        int _lv;
};

#endif // TOWER_H
