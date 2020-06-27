#include "Tower.h"
#include <cmath>
using namespace std;

double Tower::max_range = TOWER_RANGE;
int Tower::price = TOWER_PRICE;
int Tower::base_atk = 10;
int Tower::lvup_atk = 5;

Tower::Tower(string type) : Object(type)
{
    this->_target = NULL;
    _angle = 0;
    _lv = 1;
    _atk = Tower::base_atk + (_lv-1) * Tower::lvup_atk;
}


void Tower::set_target(Monster * t)
{
    this->_target = t;
    if (t != NULL) this->_start = clock();
}


void Tower::show(QPainter *painter)
{
    double deltaX, deltaY;
    if (this->getTarget() != NULL)//更新角度
    {
        deltaX = this->_target->getX() - this->getX();
        deltaY = this->_target->getY() - this->getY();
        this->_angle = atan( deltaY/deltaX ) * 180 / 3.1415 + 90;
        if (deltaX < 0) this->_angle += 180;
    }
    double GS = 2 * Icon::Grid_Size;
    painter->resetTransform();
    double centerX = this->_x * GS + this->getWidth() * GS/4;
    double centerY = this->_y * GS + this->getHeight() * GS/4;
    //旋转坐标系并绘制
    painter->translate(centerX, centerY);
    painter->rotate(_angle);
    painter->translate(-centerX, -centerY);
    painter->drawImage(this->_x * GS, this->_y * GS, this->_pic);
    painter->resetTransform();

    QString LV = "Lv." + QString::number(_lv);
    QFont font("Courier", 8, QFont::DemiBold);

    painter->setFont(font);
    painter->drawText(_x * GS + 5, _y * GS - 5, LV);
    painter->resetTransform();

    for (vector<Bullet>::iterator it = bullet_list.begin(); it != bullet_list.end(); it++) it->show(painter);

}

void Tower::shoot()
{
    if (this->_target != NULL)
    {
        this->_stop = clock();
        double dur = ((double)(this->_stop - this->_start)) / CLK_TCK;
        if (dur >=0.5)
        {
            Bullet new_bullet("bullet", this->_x, this->_y + 0.5, this->_target);
            this->bullet_list.push_back(new_bullet);
            this->_start = clock();
        }
    }
}


void Tower::lvlup()
{
    _lv ++;
    _atk = Tower::base_atk + (_lv-1) * Tower::lvup_atk;
}
