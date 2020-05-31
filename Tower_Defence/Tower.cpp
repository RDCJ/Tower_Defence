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
    if (this->getTarget() != NULL)
    {
        deltaX = (*this->_target).getX() - this->getX();
        deltaY = (*this->_target).getY() - this->getY();
        this->_angle = atan( deltaY/deltaX );
    }
   // double GS = 74;
    painter->resetTransform();
   //painter->translate(this->_x * GS , this->_y * GS );
    painter->translate(40, 40);
    painter->rotate(_angle + 90);
    painter->translate(-40, -40);
    //painter->drawImage(this->_x * GS, this->_y * GS, this->_pic);
    painter->drawImage(0, 0, this->_pic);
    painter->resetTransform();
}
