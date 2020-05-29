#include "Chapter.h"

void Chapter::initChapter()
{
    Monster monster1("monster");
    monster1.setX(9);
    monster1.setY(5);

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
    int GS = 70;
    painter->drawImage(0, 0, this->map_pic);
    painter->drawImage(GS, GS*5, this->hd.getPic());
    for (int i=0; i<m_size; i++)
        this->monster_list[i].show(painter);
    for (int i=0; i<t_size; i++)
        this->tower_list[i].show(painter);
}

void Chapter::monster_move()
{
    int m_size = this->monster_list.size();
    for (int i=0;i<m_size;i++)
        this->monster_list[i].move(3);
}
