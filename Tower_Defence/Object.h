#ifndef OBJECT_H
#define OBJECT_H
#include<QImage>
#include<QPainter>
#include<string>
#include "Icon.h"

using namespace std;

class Object
{
    public:
        Object(string type);
        void show(QPainter *painter);
        void setX(double x) {this->_x = x;};
        void setY(double y) {this->_y = y;};
        double getX() const {return this->_x;};
        double getY() const {return this->_y;};
        QImage getPic() const {return this->_pic;};
        double getHeight() const {return this->_ic.getHeight();};
        double getWidth() const {return this->_ic.getWidth();};
        string getType() const {return this->_ic.getType();};
        friend double dist(Object p1, Object p2);
    protected:
        double _x, _y;//在画面中的位置
        QImage _pic;//图片
        Icon _ic;
};

#endif // OBJECT_H
