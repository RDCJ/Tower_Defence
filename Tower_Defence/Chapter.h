#ifndef CHAPTER_H
#define CHAPTER_H
#include<QPainter>
#include<QFile>
#include<string>
#include<vector>
#include<iostream>
#include<fstream>
#include <time.h>
#include<QTextStream>

#include "Object.h"
#include "Monster.h"
#include "Tower.h"
#include "Road.h"
#include "Headquarter.h"
#include "Bullet.h"
#include "Hpbar.h"
#include "Player.h"
#include "Setting.h"

using namespace std;

class Chapter
{
    public:
        Chapter() : hd("headquarter"), _player() {_status = 0;};
        void initChapter(int k, Player pl);
        void show(QPainter *painter, bool mouse_flag, double mx, double my);
        void GamingScreen(QPainter *painter, bool mouse_flag, double mx, double my);
        void GameOver(QPainter *painter);
        void Success(QPainter *painter);
        void showTowerRange(QPainter *painter);
        int getStatus() const {return _status;};
        void place_monster();
        void monster_move();
        void check_monster();
        void tower_detect();
        void tower_shoot();
        void bullet_move();
        void createTower(double x, double y);
        void lvlupTower(double x, double y);
        //string blockType(double x, double y);
        void check_status();
        void delay(double time);
        void setMxy(double x, double y);

    protected:
        QImage map_pic, tower_pic, harmmer_pic;//地图大小：13 * 8
        vector<Monster> monster_list;
        vector<Tower> tower_list;
        clock_t _start, _stop;
        Headquarter hd;//基地
        int monster_num;
        int _status;//记录游戏状态 (0:未开始  1:成功  -1:失败  2:进行中)
        double _mx, _my;//记录鼠标的位置
        Player _player;
        Road _road;
        bool ifEnd;
};

#endif // CHAPTER_H
