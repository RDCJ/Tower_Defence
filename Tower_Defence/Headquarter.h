#ifndef HEADQUARTER_H
#define HEADQUARTER_H
#include "Object.h"

class Headquarter : public Object
{
    public:
        Headquarter(string type);
        void being_attacked();
    protected:
        int _hp;
};

#endif // HEADQUARTER_H
