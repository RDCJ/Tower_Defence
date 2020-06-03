#include "Tower.h"
#include <cmath>
using namespace std;

Tower::Tower(string type) : Object(type)
{
    this->_target = NULL;
    _angle = 0;
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

    double GS = 74;
    painter->resetTransform();
    double centerX = this->_x * GS + this->getWidth() * Icon::Grid_Size/2;
    double centerY = this->_y * GS + this->getHeight() * Icon::Grid_Size/2;
    //旋转坐标系并绘制
    painter->translate(centerX, centerY);
    painter->rotate(_angle);
    painter->translate(-centerX, -centerY);
    painter->drawImage(this->_x * GS, this->_y * GS, this->_pic);
    painter->resetTransform();
}
