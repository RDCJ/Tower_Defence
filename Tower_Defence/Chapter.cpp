#include "Chapter.h"
#include "Object.h"

void Chapter::initChapter(int k)
{
    this->_road.initRoad();
    int r_size = this->_road.getXlist().size();

    this->hd.setX(this->_road.getXlist()[r_size-1]);
    this->hd.setY(this->_road.getYlist()[r_size-1]);

    Monster monster1("monster");
    monster1.setX(this->_road.getXlist()[0]);
    monster1.setY(this->_road.getYlist()[0]);

    Tower tower1("tower");
    tower1.setX(10);
    tower1.setY(6);

    this->monster_list.push_back(monster1);
    this->tower_list.push_back(tower1);

    this->map_pic.load(":/image/raw map.png");
}

void Chapter::show(QPainter *painter)
{
    int m_size = this->monster_list.size();
    int t_size = this->tower_list.size();

    painter->drawImage(0, 0, this->map_pic);

    this->hd.show(painter);

    for (int i=0; i<m_size; i++)
        this->monster_list[i].show(painter);
    for (int i=0; i<t_size; i++)
        this->tower_list[i].show(painter);
}

void Chapter::monster_move()
{
    int m_size = this->monster_list.size();
    for (int i=0;i<m_size;i++)
        this->monster_list[i].move(this->_road);
}

void Chapter::check_monster()
{
    for (vector<Monster>::iterator itM = monster_list.begin(); itM != monster_list.end(); )//itM遍历所有怪物
    {
        bool flag1 = dist((*itM), this->hd) < 0.7;//判断怪物是否到达基地
        bool flag2 = ((*itM).getHp() <= 0);//判断怪物血量是否为0

        if (flag1) this->hd.be_attacked((*itM).mATK);//怪物到达基地则基地的生命值减少

        if (flag1 || flag2)
        {
            for (vector<Tower>::iterator itT = tower_list.begin(); itT != tower_list.end(); itT++)//itT遍历所有防御塔
            {
                //将把这只怪物作为目标的防御塔的target清零
                if ((*itT).getTarget() == &(*itM)) (*itT).set_target(NULL);
                for (vector<Bullet>::iterator itB = (*itT).getBlist()->begin(); itB != (*itT).getBlist()->end(); itB++)//itB遍历所有属于itT的子弹
                    if ((*itB).getTarget() == &(*itM)) (*itB).set_target(NULL);
                itM = monster_list.erase(itM);
            }
        }
        else itM++;
    }
}

void Chapter::tower_detect()
{
    for (vector<Tower>::iterator i = tower_list.begin(); i != tower_list.end(); i++)
    {
        if ((*i).getTarget() == NULL)
        {
            double mindist = 1000;
            for (vector<Monster>::iterator j = monster_list.begin(); j != monster_list.end(); j++)
                if (dist(*i, *j) < mindist && dist(*i, *j) <= Tower::max_range)
                {
                    mindist = dist(*i, *j);
                    (*i).set_target(&(*j));
                }
         }
        if ((*i).getTarget() != NULL && dist(*i, *(*i).getTarget()) > Tower::max_range) (*i).set_target(NULL);
     }
}

void Chapter::tower_shoot()
{
    for (vector<Tower>::iterator it = tower_list.begin(); it != tower_list.end(); it++) (*it).shoot();
}

void Chapter::bullet_move()
{
    for (vector<Tower>::iterator itT = tower_list.begin(); itT != tower_list.end(); itT++)
        for(vector<Bullet>::iterator itB = (*itT).getBlist()->begin(); itB != (*itT).getBlist()->end(); )
        {
            (*itB).move();
            if ( (*itB).getTarget() != NULL && dist(*itB, *(*itB).getTarget()) < 0.7 )
            {
                (*itB).getTarget()->be_shooted(Tower::tATK);
                itB = (*itT).getBlist()->erase(itB);
            }
            else itB++;
        }
}
