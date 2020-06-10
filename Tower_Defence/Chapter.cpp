#include "Chapter.h"
#include "Object.h"

//vector迭代器命名规则：itT指向防御塔, itM指向怪物, itB指向子弹

void Chapter::initChapter(int k)
{
    //string file_name = ":/Chapter" + to_string(k) + ".ini";
    ifstream init_file;
    init_file.open("F://Tower_Defence//Tower_Defence//Chapter1.ini", ios::in);
    //读取路径信息
    int n;
    init_file>>n;
    int xl[n], yl[n];
    for (int i=0; i<n; i++) init_file >>xl[i] >>yl[i];
    this->_road.initRoad(n, xl, yl);
    //读取怪物信息
    init_file>>monster_num;
    for (int i=0; i<monster_num; i++)
    {
        int t;
        init_file >>t;
        Monster new_monster("monster", _road.getXlist()[0], _road.getYlist()[0], t);
        this->monster_list.push_back(new_monster);
    }
    init_file.close();

    this->_start = clock();
    this->_status = 2;
    //设置基地位置
    int r_size = this->_road.getXlist().size();
    this->hd.setX(this->_road.getXlist()[r_size-1]);
    this->hd.setY(this->_road.getYlist()[r_size-1]);

    int GS = Icon::Grid_Size;
    this->map_pic.load(":/image/raw map.png");
    tower_pic.load(":/image/Icon Set.png");
    tower_pic = tower_pic.copy(QRect(4 * GS, 0 * GS, 2 * GS, 2 * GS));
}


void Chapter::createTower(double x, double y)
{
    Tower newTower("tower");
    newTower.setX(x/80);
    newTower.setY(y/80);
    this->tower_list.push_back(newTower);
}


void Chapter::show(QPainter *painter, bool mouse_flag, double mx, double my)
{
    if (this->_status == 2)
    {
        painter->drawImage(0, 0, map_pic);
        painter->drawImage(0, 0, tower_pic);
        this->hd.show(painter);

        for (vector<Monster>::iterator itM = monster_list.begin(); itM != monster_list.end(); itM++)
            (*itM).show(painter);
        for (vector<Tower>::iterator itT = tower_list.begin(); itT != tower_list.end(); itT++)
            (*itT).show(painter);

        if (mouse_flag) painter->drawImage(mx, my, tower_pic);
    }
    else if (this->_status == -1) GameOver(painter);
    else if (this->_status == 1) Success(painter);
}


void Chapter::place_monster()
{
    _stop = clock();
    double dur = ((double)(_stop - _start)) / CLK_TCK;
    for (vector<Monster>::iterator itM = monster_list.begin(); itM != monster_list.end(); itM++)
    {
        if ((*itM).ifPlaced()) continue;
        if ( abs(dur - (*itM).getST()) < 0.1) (*itM).place();
    }
}


void Chapter::monster_move()
{
    for (vector<Monster>::iterator itM = monster_list.begin(); itM != monster_list.end(); itM++ )
        (*itM).move(this->_road);
}


void Chapter::check_monster()
{
    for (vector<Monster>::iterator itM = monster_list.begin(); itM != monster_list.end(); itM++)//itM遍历所有怪物
        if ( (*itM).ifPlaced() && (*itM).alive() )
        {
            bool flag1 = dist((*itM), this->hd) < 0.7;//判断怪物是否到达基地
            bool flag2 = (*itM).getHp() <= 0;//判断怪物血量是否为0

            if (flag1) this->hd.be_attacked((*itM).mATK);//怪物到达基地则基地的生命值减少

            if (flag1 || flag2)
            {
                (*itM).dead();
                for (vector<Tower>::iterator itT = tower_list.begin(); itT != tower_list.end(); itT++)//itT遍历所有防御塔
                    //将把这只怪物作为目标的防御塔的target清零
                    if ((*itT).getTarget() == &(*itM)) (*itT).set_target(NULL);
            }
        }
}


void Chapter::tower_detect()
{
    for (vector<Tower>::iterator itT = tower_list.begin(); itT != tower_list.end(); itT++)
    {
        if ( (*itT).getTarget() != NULL && dist(*itT, *(*itT).getTarget()) > Tower::max_range )
            (*itT).set_target(NULL);
        if ((*itT).getTarget() == NULL)
        {
            double mindist = 1000;
            Monster *p = NULL;
            for (vector<Monster>::iterator itM = monster_list.begin(); itM != monster_list.end(); itM++)
                if ((*itM).ifPlaced() && (*itM).alive() && dist(*itT, *itM) < mindist && dist(*itT, *itM) <= Tower::max_range)
                {
                    mindist = dist(*itT, *itM);
                    p = &(*itM);
                }
            if (p != NULL) (*itT).set_target(p);
         }
     }
}

void Chapter::tower_shoot()
{
    for (vector<Tower>::iterator itT = tower_list.begin(); itT != tower_list.end(); itT++) (*itT).shoot();
}

void Chapter::bullet_move()
{
    for (vector<Tower>::iterator itT = tower_list.begin(); itT != tower_list.end(); itT++)
        for(vector<Bullet>::iterator itB = (*itT).getBlist()->begin(); itB != (*itT).getBlist()->end(); )
        {
            (*itB).move();
            if ( (*itB).getTarget() != NULL && dist(*itB, *(*itB).getTarget()) < 0.5 )
            {
                (*itB).getTarget()->be_shooted(Tower::tATK);
                itB = (*itT).getBlist()->erase(itB);
            }
            else itB++;
        }
}


void Chapter::check_status()
{
    if (this->hd.getHP() <= 0) this->_status = -1;
    bool flag = true;
    for (vector<Monster>::iterator itM = monster_list.begin(); itM != monster_list.end(); itM++)
        if ((*itM).alive() == true) flag = false;
    if (flag) this->_status = 1;
}


void Chapter::GameOver(QPainter *painter)
{
    QString G_O = "Game Over.";
    QFont font("Courier", 15, QFont::DemiBold);
    painter->setFont(font);
    painter->translate(479, 295);
    painter->drawText(0, 0, G_O);
    painter->resetTransform();
}

void Chapter::Success(QPainter *painter)
{
    QString SU = "Success.";
    QFont font("Courier", 15, QFont::DemiBold);
    painter->setFont(font);
    painter->translate(479, 295);
    painter->drawText(0, 0, SU);
    painter->resetTransform();
}
