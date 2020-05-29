#ifndef ROAD_H
#define ROAD_H
#include<vector>
using namespace std;

class Road
{
    public:
        Road() {};
        void initRoad();
        vector<int> getXlist() const {return this->Xlist;};
        vector<int> getYlist() const {return  this->Ylist;};
    protected:
        vector<int> Xlist;
        vector<int> Ylist;
};

#endif // ROAD_H
