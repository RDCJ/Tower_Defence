#include "Tower.h"
#include <cmath>
using namespace std;

int Tower::max_range = 3;
int Tower::tATK = 10;
int Tower::price = 50;

Tower::Tower(string type) : Object(type)
{
    this->_target = NULL;
    _angle = 0;
}

void Tower::set_target(Monster * t)
{
    this->_target = t;
   // std::cout<<t<<endl;
    if (t != NULL) this->_start = clock();
}

void Tower::show(QPainter *painter)
{
    double deltaX, deltaY;
    if (this->getTarget() != NULL)//更新角度
    {
        deltaX = (*this->_target).getX() - this->getX();
        deltaY = (*this->_target).getY() - this->getY();
        this->_angle = atan( deltaY/deltaX ) * 180 / 3.1415 + 90;
        if (deltaX < 0) this->_angle += 180;
    }
    double GS = 2 * Icon::Grid_Size;
    painter->resetTransform();
    double centerX = this->_x * GS + this->getWidth() * Icon::Grid_Size/2;
    double centerY = this->_y * GS + this->getHeight() * Icon::Grid_Size/2;
    //旋转坐标系并绘制
    painter->translate(centerX, centerY);
    painter->rotate(_angle);
    painter->translate(-centerX, -centerY);
    painter->drawImage(this->_x * GS, this->_y * GS, this->_pic);
    painter->resetTransform();

    for (vector<Bullet>::iterator it = bullet_list.begin(); it != bullet_list.end(); it++) (*it).show(painter);

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
