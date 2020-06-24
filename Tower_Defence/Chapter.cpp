#include "Chapter.h"
#include "Object.h"

//vector迭代器命名规则：itT指向防御塔, itM指向怪物, itB指向子弹

Chapter::Chapter() : hd("headquarter"), _player()
{
    _status = 0;
    int GS = Icon::Grid_Size;
    map_pic[0].load(":/image/chapter1map.png");
    map_pic[1].load(":/image/chapter2map.png");
    map_pic[2].load(":/image/chapter3map.png");
    harmmer_pic.load(":/image/Harmmer.png");
    tower_pic.load(":/image/Icon Set.png");
    tower_pic = tower_pic.copy(QRect(4 * GS, 0 * GS, 2 * GS, 2 * GS));
}


void Chapter::initChapter(int k)
{
    now_chapter = k;

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
        if (type == 1)
        {
            Worm new_monster("worm", _road.getXlist()[0], _road.getYlist()[0], ti, lv);
            this->monster_list.push_back(new_monster);
        }
        else if (type == 2)
        {
            Slime new_monster("slime", _road.getXlist()[0], _road.getYlist()[0], ti, lv);
            this->monster_list.push_back(new_monster);
        }
        else if (type == 3)
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
    QFont font("Courier", 17, QFont::DemiBold);
    QFontMetrics fm(font);
    {
        QString Sale = "防御塔:$" + QString::number(TOWER_PRICE);
        painter->drawText(400, 560, Sale);
    }
    {
        QString Sale = "升级:$" + QString::number(LVLUP_PRICE);
        painter->drawText(560, 560, Sale);
    }
    painter->resetTransform();
    this->hd.show(painter);

    for (vector<Monster>::iterator itM = monster_list.begin(); itM != monster_list.end(); itM++)
        (*itM).show(painter);
    for (vector<Tower>::iterator itT = tower_list.begin(); itT != tower_list.end(); itT++)
        (*itT).show(painter);

    if (mouse_flag) painter->drawImage(mx-40, my-40, tower_pic);

    if (_status == 2) _player.show(painter);
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
    painter->drawText(WIN_WIDTH/2 - textWidth/2, WIN_HEIGHT - 120, G_O);
    painter->resetTransform();

    _player.show(painter);
}

void Chapter::Success(QPainter *painter)
{
    if (ifEnd == false) _player.changeValue(hd.getHP() * 10, 0);
    ifEnd = true;
    delay(0.5);
    QString SU = "Success.";
    QFont font("Microsoft YaHei", 30, QFont::DemiBold);
    QFontMetrics fm(font);
    double textWidth = fm.width(SU);

    painter->setFont(font);
    painter->drawText(WIN_WIDTH/2 - textWidth/2, WIN_HEIGHT - 120, SU);
    painter->resetTransform();

    _player.show(painter);
}


void Chapter::showTowerRange(QPainter *painter)
{
    int GS = Icon::Grid_Size;
    for (vector<Tower>::iterator itT = tower_list.begin(); itT != tower_list.end(); itT++)
    {
        double left = (*itT).getX() * GS *2,
                   right = ((*itT).getX() + 1) * GS *2,
                   top = (*itT).getY() * GS *2,
                   bottom = ((*itT).getY() + 1) * GS * 2;
        if (_mx > left && _mx < right && _my > top && _my < bottom)
        {
            double r = Tower::max_range * GS * 2;
            painter->drawEllipse((*itT).getX() * GS *2 - r + 40, (*itT).getY() * GS *2 - r + 40,
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
    vector<MiniSlime> splited;
    for (vector<Monster>::iterator itM = monster_list.begin(); itM != monster_list.end(); itM++)//itM遍历所有怪物
        if ( (*itM).ifPlaced() && (*itM).alive() )
        {
            bool flag1 = dist((*itM), this->hd) < 0.7;//判断怪物是否到达基地
            bool flag2 = (*itM).getHp() <= 0;//判断怪物血量是否为0

            if (flag2 && (*itM).getType() == "slime")
                    slime_split((*itM).getX(), (*itM).getY(), (*itM).getLv(), (*itM).getPos(), &splited);

            if (flag1) this->hd.be_attacked((*itM).getATK());//怪物到达基地则基地的生命值减少
            if (flag2) _player.changeValue(EACH_M_SCORE, EACH_M_MONEY);
            if (flag1 || flag2)
            {
                (*itM).dead();
                for (vector<Tower>::iterator itT = tower_list.begin(); itT != tower_list.end(); itT++)//itT遍历所有防御塔
                    //将把这只怪物作为目标的防御塔的target清零
                    if ((*itT).getTarget() == &(*itM)) (*itT).set_target(NULL);
            }
        }
    for (vector<MiniSlime>::iterator itS = splited.begin(); itS != splited.end(); itS++)
        monster_list.push_back((*itS));
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
                (*itB).getTarget()->be_shooted((*itT).getATK());
                itB = (*itT).getBlist()->erase(itB);
            }
            else itB++;
        }
}


void Chapter::check_status()
{
    if (ifEnd == false)
    {
        if (this->hd.getHP() <= 0) this->_status = -1;
        bool flag = true;
        for (vector<Monster>::iterator itM = monster_list.begin(); itM != monster_list.end(); itM++)
            if ((*itM).alive() == true) flag = false;
        if (flag) this->_status = 1;
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
    if (_player.getMoney() < LVLUP_PRICE) return;
    int GS = Icon::Grid_Size;
    for (vector<Tower>::iterator itT = tower_list.begin(); itT != tower_list.end(); itT++)
    {
        double left = (*itT).getX() * GS *2,
                   right = ((*itT).getX() + 1) * GS *2,
                   top = (*itT).getY() * GS *2,
                   bottom = ((*itT).getY() + 1) * GS * 2;
        if (x > left && x < right && y > top && y < bottom)
        {
            (*itT).lvlup();
            _player.changeValue(0, -LVLUP_PRICE);
            break;
        }
    }
}


void Chapter::setMxy(double x, double y)
{
    _mx = x;
    _my = y;
}


void Chapter::slime_split(double x, double y, int lv, int pos, vector<MiniSlime> *list)
{
    int nextPos = pos + 1;
    int deltaX = _road.getXlist()[nextPos] - _road.getXlist()[pos];
    int deltaY = _road.getYlist()[nextPos] - _road.getYlist()[pos];

    MiniSlime ms1("minislime", x + deltaX * 0.25, y + deltaY * 0.25, lv, pos);
    MiniSlime ms2("minislime", x - deltaX * 0.25, y - deltaY * 0.25, lv, pos);
    list->push_back(ms1);
    list->push_back(ms2);
}
