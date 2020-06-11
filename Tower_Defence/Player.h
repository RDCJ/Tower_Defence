#ifndef PLAYER_H
#define PLAYER_H
#include<QPainter>
#include<string>
#include<QString>
using namespace std;

class Player
{
    public:
        Player();
        void show(QPainter *painter);
        int getScore() const {return _score;};
        int getMoney() const {return _money;};
        void changeValue(int ps, int pm);

    private:
        int _score, _money;

};

#endif // PLAYER_H
