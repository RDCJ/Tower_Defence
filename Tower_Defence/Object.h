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
        void setX(int x) {this->_x = x;};
        void setY(int y) {this->_y = y;};
        int getX() const {return this->_x;};
        int getY() const {return this->_y;};
        QImage getPic() const {return this->_pic;};
        int getHeight() const {return this->_ic.getHeight();};
        int getWidth() const {return this->_ic.getWidth();};
        string getType() const {return this->_ic.getType();};


    protected:
        int _x, _y;//在画面中的位置
        QImage _pic;//图片
        Icon _ic;
};

#endif // OBJECT_H
