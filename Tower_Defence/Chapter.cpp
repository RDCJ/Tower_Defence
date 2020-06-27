#include "Chapter.h"
#include "Object.h"
#include<QMediaPlayer>
//vector迭代器命名规则：itT指向防御塔, itM指向怪物, itB指向子弹

Chapter::Chapter() : hd("headquarter"), _player()
{
    _status = 0;
    now_chapter = 0;
    int GS = Icon::Grid_Size;
    map_pic[0].load(":/image/chapter1map.png");
    map_pic[1].load(":/image/chapter2map.png");
    map_pic[2].load(":/image/chapter3map.png");
    harmmer_pic.load(":/image/Harmmer.png");
    tower_pic.load(":/image/Icon Set.png");
    tower_pic = tower_pic.copy(QRect(4 * GS, 0 * GS, 2 * GS, 2 * GS));
    music = new QMediaPlayer;
    music->setVolume(30);
}


void Chapter::initChapter(int k)
{
    music->stop();
    now_chapter = k;
    if (now_chapter == 1)
    {
         music->setMedia(QUrl("qrc:/music/funny.mp3"));
         music->play();
    }
    else if (now_chapter == 2)
    {
         music->setMedia(QUrl("qrc:/music/fighting2.mp3"));
         music->play();
    }
    else if (now_chapter == 3)
    {
         music->setMedia(QUrl("qrc:/music/fighting1.mp3"));
         music->play();
    }
    tower_list.clear();
    monster_list.clear();

    QString file_name = ":/chapter/Chapter" + QString::number(k) + ".ini";
    QFile init_file(file_name);
    init_file.open(QIODevice::ReadOnly);
    QTextStream stream(&init_file);
    //读取路径信息
    int n, m;
    stream>>n;
    int xl[n], yl[n];
    for (int i=0; i<n; i++) stream >>xl[i] >>yl[i];
    this->_road.initRoad(n, xl, yl);
    //读取怪物信息
    stream>>monster_num;
    for (int i=0; i<monster_num; i++)
    {
        int type, ti, lv;
        stream >>type >>ti >>lv;
        if (type == 1)//虱虫
        {
            Worm new_monster("worm", _road.getXlist()[0], _road.getYlist()[0], ti, lv);
            this->monster_list.push_back(new_monster);
        }
        else if (type == 2)//史莱姆
        {
            Slime new_monster("slime", _road.getXlist()[0], _road.getYlist()[0], ti, lv);
            this->monster_list.push_back(new_monster);
            this->monster_list.push_back(MiniSlime("minislime", 0, 0, lv));
            this->monster_list.push_back(MiniSlime("minislime", 0, 0, lv));
        }
        else if (type == 3)//大颚虫
        {
            BigMouth new_monster("bigmouth", _road.getXlist()[0], _road.getYlist()[0], ti, lv);
            this->monster_list.push_back(new_monster);
        }
    }
    //设置初始金钱
    stream>>m;
    this->_player.reset(m);
    init_file.close();

    this->_start = clock();
    this->_status = 2;
    this->ifEnd = false;
    //设置基地位置
    int r_size = this->_road.getXlist().size();
    hd.init_hd(_road.getXlist()[r_size-1], _road.getYlist()[r_size-1]);
}


void Chapter::createTower(double x, double y)
{
    if (_player.getMoney() >= Tower::price)
    {
        _player.changeValue(0, -Tower::price);
        Tower newTower("tower");
        newTower.setX((x-40)/80);
        newTower.setY((y-40)/80);
        this->tower_list.push_back(newTower);
    }
}


void Chapter::show(QPainter *painter, bool mouse_flag, double mx, double my)
{
    if (this->_status != 0) GamingScreen(painter, mouse_flag, mx, my);
    if (this->_status == -1) GameOver(painter);
    else if (this->_status == 1) Success(painter);
    showTowerRange(painter);
}


void Chapter::GamingScreen(QPainter *painter, bool mouse_flag, double mx, double my)
{
    painter->drawImage(0, 0, map_pic[now_chapter - 1]);
    painter->drawImage(400, 560, tower_pic);
    painter->drawImage(560, 560, harmmer_pic);

    QFont font("Microsoft YaHei", 15, QFont::DemiBold);
    QFontMetrics fm(font);
    painter->setFont(font);
    _stop = clock();
    double dur = (double(_stop - _start)) / CLK_TCK;
    if (dur < 10)
    {
        QString waiting = "你有十秒钟的准备时间: " + QString::number(10 - floor(dur));
        double textWidth = fm.width(waiting);
        painter->drawText(WIN_WIDTH/2 - textWidth/2, 30, waiting);
    }
    painter->resetTransform();

    drawSales(painter);

    this->hd.show(painter);
    for (vector<Monster>::iterator itM = monster_list.begin(); itM != monster_list.end(); itM++)
        itM->show(painter);
    for (vector<Tower>::iterator itT = tower_list.begin(); itT != tower_list.end(); itT++)
        itT->show(painter);

    if (mouse_flag) painter->drawImage(mx-40, my-40, tower_pic);

    _player.show(painter);
}

void Chapter::GameOver(QPainter *painter)
{
    ifEnd = true;
    delay(0.5);
    QString G_O = "Game Over.";
    QFont font("Microsoft YaHei", 30, QFont::DemiBold);
    QFontMetrics fm(font);
    double textWidth = fm.width(G_O);

    painter->setFont(font);
    painter->drawText(WIN_WIDTH/2 - textWidth/2, 70, G_O);
    painter->resetTransform();
}


void Chapter::Success(QPainter *painter)
{
    if (ifEnd == false) _player.changeValue(hd.getHP() * 5, 0);
    ifEnd = true;
    delay(0.5);
    QString SU = "Success.";
    QFont font("Microsoft YaHei", 30, QFont::DemiBold);
    QFontMetrics fm(font);
    double textWidth = fm.width(SU);

    painter->setFont(font);
    painter->drawText(WIN_WIDTH/2 - textWidth/2, 70, SU);
    painter->resetTransform();
}



void Chapter::drawSales(QPainter *painter)
{
    QFont font("Microsoft YaHei", 8, QFont::DemiBold);
    QFontMetrics fm(font);
    painter->setFont(font);
    {
        QString Sale = "防御塔:$" + QString::number(TOWER_PRICE);
        painter->drawText(400, 560, Sale);
    }
    {
        QString Sale = "升级:$" + QString::number(LVLUP_PRICE_BASE) + "+Lv×5";
        painter->drawText(560, 560, Sale);
    }
    painter->resetTransform();
}


void Chapter::showTowerRange(QPainter *painter)
{
    int GS = Icon::Grid_Size;
    for (vector<Tower>::iterator itT = tower_list.begin(); itT != tower_list.end(); itT++)
    {
        double left = itT->getX() * GS *2,
                   right = (itT->getX() + 1) * GS *2,
                   top = itT->getY() * GS *2,
                   bottom = (itT->getY() + 1) * GS * 2;
        if (_mx > left && _mx < right && _my > top && _my < bottom)
        {
            double r = Tower::max_range * GS * 2;
            painter->drawEllipse(itT->getX() * GS *2 - r + 40, itT->getY() * GS *2 - r + 40,
                                             r *2, r *2);
            break;
        }
    }
}

void Chapter::place_monster()
{
    _stop = clock();
    double dur = ((double)(_stop - _start)) / CLK_TCK;
    for (vector<Monster>::iterator itM = monster_list.begin(); itM != monster_list.end(); itM++)
    {
        if (itM->ifPlaced()) continue;
        if (itM->getType() == "minislime") continue;
        if ( abs(dur - itM->getST()) < 0.1) itM->place();
    }
}


void Chapter::monster_move()
{
    for (vector<Monster>::iterator itM = monster_list.begin(); itM != monster_list.end(); itM++ )
        itM->move(this->_road);
}


void Chapter::check_monster()
{
    for (vector<Monster>::iterator itM = monster_list.begin(); itM != monster_list.end(); itM++)//itM遍历所有怪物
        if ( itM->ifPlaced() && itM->alive() )
        {
            bool flag1 = dist((*itM), this->hd) < 0.7;//判断怪物是否到达基地
            bool flag2 = itM->getHp() <= 0;//判断怪物血量是否为0

            if (flag2 && itM->getType() == "slime")
            {
                MiniSlime* son1 = static_cast<MiniSlime*>(&(*(itM+1)));
                MiniSlime* son2 = static_cast<MiniSlime*>(&(*(itM+2)));
                son1->place(); son2->place();
                int nextPos = itM->getPos() + 1, lastPos = itM->getPos() - 1;
                int deltaX = _road.getXlist()[nextPos] - _road.getXlist()[itM->getPos()];
                int deltaY = _road.getYlist()[nextPos] - _road.getYlist()[itM->getPos()];
                son1->setPos(itM->getX() + 0.25 * deltaX, itM->getY() + 0.25 * deltaY, itM->getPos());
                son2->setPos(itM->getX() - 0.25 * deltaX, itM->getY() - 0.25 * deltaY, itM->getPos());

                son1->adjustPos(_road.getXlist()[nextPos], _road.getYlist()[nextPos], nextPos);
                son1->adjustPos(_road.getXlist()[lastPos], _road.getYlist()[lastPos], lastPos);
                son1->adjustPos(_road.getXlist()[nextPos], _road.getYlist()[nextPos], nextPos);
                son1->adjustPos(_road.getXlist()[lastPos], _road.getYlist()[lastPos], lastPos);
            }

            if (flag1) this->hd.be_attacked(itM->getATK());//怪物到达基地则基地的生命值减少
            if (flag2) _player.changeValue(EACH_M_SCORE, EACH_M_MONEY);
            if (flag1 || flag2)
            {
                itM->dead();
                for (vector<Tower>::iterator itT = tower_list.begin(); itT != tower_list.end(); itT++)//itT遍历所有防御塔
                    //将把这只怪物作为目标的防御塔的target清零
                    if (itT->getTarget() == &(*itM)) itT->set_target(NULL);
            }
        }
}


void Chapter::tower_detect()
{
    for (vector<Tower>::iterator itT = tower_list.begin(); itT != tower_list.end(); itT++)
    {
        if ( itT->getTarget() != NULL && dist(*itT, *itT->getTarget()) > Tower::max_range )
            itT->set_target(NULL);
        if (itT->getTarget() == NULL)
        {
            double mindist = 1000;
            Monster *p = NULL;
            for (vector<Monster>::iterator itM = monster_list.begin(); itM != monster_list.end(); itM++)
                if (itM->ifPlaced() && itM->alive() && dist(*itT, *itM) < mindist && dist(*itT, *itM) <= Tower::max_range)
                {
                    mindist = dist(*itT, *itM);
                    p = &(*itM);
                }
            if (p != NULL) itT->set_target(p);
         }
     }
}

void Chapter::tower_shoot()
{
    for (vector<Tower>::iterator itT = tower_list.begin(); itT != tower_list.end(); itT++) itT->shoot();
}

void Chapter::bullet_move()
{
    for (vector<Tower>::iterator itT = tower_list.begin(); itT != tower_list.end(); itT++)
        for(vector<Bullet>::iterator itB = itT->getBlist()->begin(); itB != itT->getBlist()->end(); )
        {
            itB->move();
            if ( itB->getTarget() != NULL && dist(*itB, *itB->getTarget()) < 0.5 )
            {
                itB->getTarget()->be_shooted(itT->getATK());
                itB = itT->getBlist()->erase(itB);
            }
            else itB++;
        }
}


void Chapter::check_status()
{
    if (ifEnd == false)
    {
        if (this->hd.getHP() <= 0)
        {
            this->_status = -1;
            music->stop();
            music->setMedia(QUrl("qrc:/music/fail.mp3"));
            music->play();
            return;
        }
        bool flag = true;
        for (vector<Monster>::iterator itM = monster_list.begin(); itM != monster_list.end(); itM++)
            if (itM->ifPlaced() == false && itM->getType() == "minislime") continue;
            else if (itM->alive() == true) flag = false;
        if (flag)
        {
            this->_status = 1;
            music->stop();
            music->setMedia(QUrl("qrc:/music/success.mp3"));
            music->play();
        }
    }
}


void Chapter::delay(double time)
{
    clock_t a, b;
    a = clock();
    b = clock();
    double dur = ((double)(b - a)) / CLK_TCK;
    while (dur < time)
    {
        b = clock();
        dur = ((double)(b - a)) / CLK_TCK;
    }
}

void Chapter::lvlupTower(double x, double y)
{
    int GS = Icon::Grid_Size;
    for (vector<Tower>::iterator itT = tower_list.begin(); itT != tower_list.end(); itT++)
    {
        double left = itT->getX() * GS *2,
                   right = (itT->getX() + 1) * GS *2,
                   top = itT->getY() * GS *2,
                   bottom = (itT->getY() + 1) * GS * 2;
        if (x > left && x < right && y > top && y < bottom)
        {
            int cost = LVLUP_PRICE_BASE + (itT->getLv() - 1) * LVLUP_PRICE_LVUP;
            if (_player.getMoney() < cost) return;
            itT->lvlup();
            _player.changeValue(0, -cost);
            break;
        }
    }
}


void Chapter::setMxy(double x, double y)
{
    _mx = x;
    _my = y;
}

