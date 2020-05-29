#ifndef CHAPTER_H
#define CHAPTER_H
#include<QPainter>
#include<string>
#include<vector>
#include "Object.h"
#include "Monster.h"
#include "Tower.h"
#include "Road.h"
#include "Headquarter.h"

class Chapter
{
    public:
        Chapter() : hd("headquarter") {};
        void initChapter();
        void show(QPainter *painter);
        void monster_move();

    protected:
        QImage map_pic;//地图大小：13 * 8
        Headquarter hd;
        Road _road;
        vector<Monster> monster_list;
        vector<Tower> tower_list;
};

#endif // CHAPTER_H
