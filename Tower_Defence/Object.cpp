#include "Object.h"
#include <cmath>

Object::Object(string type) : _ic(Icon::Icon_Set.find(type)->second)
{
    QImage all;
    int GS = Icon::Grid_Size;
    all.load(":/image/Icon Set.png");
    this->_pic = all.copy(QRect(_ic.getScrX()*GS, _ic.getScrY()*GS, _ic.getWidth()*GS, _ic.getHeight()*GS));
}

void Object::show(QPainter *painter)
{
    double GS = 74;
    painter->drawImage(this->_x * GS, this->_y * GS, this->_pic);
}

double dist(Object p1, Object p2)
{
    double xx = p1.getX() - p2.getX();
    double yy = p1.getY() - p2.getY();
    return sqrt(xx*xx + yy*yy);
}
