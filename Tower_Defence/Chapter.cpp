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
    int r_size = this->_road.getXlist().size();
    int endX = this->_road.getXlist()[r_size-1];
    int endY = this->_road.getYlist()[r_size-1];


    for (vector<Monster>::iterator iter = monster_list.begin(); iter != monster_list.end(); )
    {
        bool flag1 = ((*iter).getX() == endX && (*iter).getY() == endY);//判断怪物是否到达基地
        bool flag2 = ((*iter).getHp() <= 0);//判断怪物血量是否为0

        if (flag1) this->hd.being_attacked();//怪物到达基地则基地的生命值减少

        if (flag1 || flag2)
        {
            for (vector<Tower>::iterator i = tower_list.begin(); i != tower_list.end(); i++)
                //将把这只怪物作为目标的防御塔的target清零
                if ((*i).getTarget() == &(*iter))
                    (*i).set_target(NULL);

            iter = monster_list.erase(iter);
        }
        else iter++;
    }
}

void Chapter::tower_detect()
{
    for (vector<Tower>::iterator i = tower_list.begin(); i != tower_list.end(); i++)
    {
        if ((*i).getTarget() == NULL)
        {
            double max_range = 10000;
            for (vector<Monster>::iterator j = monster_list.begin(); j != monster_list.end(); j++)
                if (dist(*i, *j) < max_range)
                {
                    max_range = dist(*i, *j);
                    (*i).set_target(&(*j));
                }
         }
     }
}
