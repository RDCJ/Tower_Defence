#include "Bullet.h"
#include<cmath>
double Bullet::bSPEED = 0.3;

Bullet::Bullet(string type, double x, double y, Monster * t):Object(type)
{
    this->_x = x;
    this->_y = y;
    this->_target = t;
}

void Bullet::move()
{
    if (_target != NULL)
    {
        double deltaX = (*_target).getX() - this->getX();
        double deltaY = (*_target).getY() - this->getY();
        this->_angle = atan( deltaY/deltaX ) * 180 / 3.1415;
        if (deltaX < 0) this->_angle += 180;
    }

    this->_x += bSPEED * cos(_angle * 3.1415 / 180);
    this->_y += bSPEED * sin(_angle * 3.1415 / 180);
}

void Bullet::show(QPainter *painter)
{
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
