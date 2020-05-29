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

        Icon(string type, int x, int y, int w, int h);
        int getScrX() const {return _scrX;};
        int getScrY() const {return _scrY;};
        int getHeight() const {return _height;};
        int getWidth() const {return _width;};
        string getType() const {return this->_typeName;};

    protected:
        string _typeName;
        int _height, _width, _scrX, _scrY;
};

#endif // ICON_H
