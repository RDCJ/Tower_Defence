#include "Icon.h"

int Icon::Grid_Size = 40;

pair<string, Icon> pairArr[] =
{
    make_pair("tower", Icon("tower", 4, 0, 2, 2)),
    make_pair("monster", Icon("monster", 0, 0, 2, 1)),
    make_pair("headquarter", Icon("Headquarter",4, 2, 2, 2)),
    make_pair("bullet", Icon("bullet", 0, 4, 2, 0.35)),
    make_pair("hpBarFrame", Icon("hpBarFrame", 2, 4, 2.55, 0.3)),
    make_pair("hpGreen", Icon("hpGreen", 5.8, 4, 0.025, 0.25)),
    make_pair("worm", Icon("worm", 0, 1, 2, 1)),
    make_pair("bigmouth", Icon("bigmouth", 0, 0, 2, 1)),
    make_pair("slime", Icon("slime", 0, 3, 2, 1)),
    make_pair("minislime", Icon("minislime", 4.55, 4, 1.25, 0.75))
};

map<string, Icon> Icon::Icon_Set(pairArr, pairArr+sizeof(pairArr)/sizeof(pairArr[0]));

Icon::Icon(string type, double x, double y, double w, double h)
{
    this->_typeName = type;
    this->_scrX = x;
    this->_scrY = y;
    this->_width = w;
    this->_height = h;
}


Icon Icon::findIcon(string type)
{
    map<string, Icon>::iterator kv;
    kv = Icon::Icon_Set.find(type);
    return kv->second;
}
