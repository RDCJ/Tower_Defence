#ifndef CHAPTER_H
#define CHAPTER_H
#include<QPainter>
#include<QFile>
#include<string>
#include<vector>
#include<iostream>
#include<fstream>
#include "Object.h"
#include "Monster.h"
#include "Tower.h"
#include "Road.h"
#include "Headquarter.h"
#include "Bullet.h"
#include <time.h>

using namespace std;

class Chapter
{
    public:
        Chapter() : hd("headquarter") {_status = 0;};
        void initChapter(int k);
        void show(QPainter *painter, bool mouse_flag, double mx, double my);
        void place_monster();
        void monster_move();
        void check_monster();
        void tower_detect();
        void tower_shoot();
        void bullet_move();
        void createTower(double x, double y);
        void check_status();
        void GameOver(QPainter *painter);
        void Success(QPainter *painter);

    protected:
        QImage map_pic, tower_pic;//地图大小：13 * 8
        Headquarter hd;//基地
        Road _road;
        vector<Monster> monster_list;
        vector<Tower> tower_list;
        clock_t _start, _stop;
        int monster_num;
        int _status;//记录游戏状态 (0:未开始  1:成功  -1:失败  2:进行中)    
};

#endif // CHAPTER_H
