#ifndef ICON_H
#define ICON_H
#include<string>
#include<map>
using namespace std;

class Icon
{
    public:
        static int Grid_Size;
        static map<string, Icon> Icon_Set;
        static Icon findIcon(string type);

        Icon(string type, double x, double y, double w, double h);
        double getScrX() const {return _scrX;};
        double getScrY() const {return _scrY;};
        double getHeight() const {return _height;};
        double getWidth() const {return _width;};
        string getType() const {return this->_typeName;};

    protected:
        string _typeName;
        double _scrX, _scrY;
        double _height, _width;
};

#endif // ICON_H
