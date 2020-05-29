#include "Chapter.h"

void Chapter::initChapter()
{
    this->_road.initRoad();
    int r_size = this->_road.getXlist().size();

    this->hd.setX(this->_road.getXlist()[r_size-1]);
    this->hd.setY(this->_road.getYlist()[r_size-1]);

    Monster monster1("monster");
    monster1.setX(this->_road.getXlist()[0]);
    monster1.setY(this->_road.getYlist()[0]);

    Tower tower1("tower");
    tower1.setX(0);
    tower1.setY(4);

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
