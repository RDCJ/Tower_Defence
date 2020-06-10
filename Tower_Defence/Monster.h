#ifndef MONSTER_H
#define MONSTER_H
#include "Object.h"
#include "Road.h"
#include "Hpbar.h"

class Monster : public Object
{
    public:
        static int mATK;
        static double mSPEED;
        Monster(string type, double x, double y, double st);
        int getHp() const {return _hp;};
        bool alive() const {return _alive;};
        double getST() const {return show_time;};
        bool ifPlaced() const {return if_placed;};
        void place() {if_placed = true;};
        void be_shooted(int damage) {this->_hp -= damage;};
        void dead() {this->_alive = false;};
        void show(QPainter *painter);
        void move(Road r);

    protected:
        int _hp;
        int _pos;//记录怪物在Road序列中的位置
        bool _alive, if_placed;
        double show_time;
        Hpbar _hpBar;

};

#endif // MONSTER_H
