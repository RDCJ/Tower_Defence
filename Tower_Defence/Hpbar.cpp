#include "Hpbar.h"

Hpbar::Hpbar() : _hpBarFrame("hpBarFrame"), _hpGreen("hpGreen") {}

void Hpbar::show(QPainter *painter, int hp, double x, double y)
{
    double deltaX = 0.1;
    int num = hp / 10;
    double GS = 2 * Icon::Grid_Size;
    painter->drawImage((x - 0.07) * GS, (y - 0.2) * GS, _hpBarFrame.getPic());
    for (int i=0; i<num; i++)
       painter->drawImage((x + i*deltaX - 0.06) * GS, (y - 0.18) * GS, _hpGreen.getPic());
}
