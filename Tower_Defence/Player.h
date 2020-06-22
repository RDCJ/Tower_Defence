#ifndef PLAYER_H
#define PLAYER_H
#include<QPainter>
#include<string>
#include<QString>
#include "Setting.h"

using namespace std;

class Player
{
    public:
        Player();
        void show(QPainter *painter);
        void reset(int money) {_score = 0; _money = money;};
        int getScore() const {return _score;};
        int getMoney() const {return _money;};
        void changeValue(int ps, int pm);

    private:
        int _score, _money;

};

#endif // PLAYER_H
