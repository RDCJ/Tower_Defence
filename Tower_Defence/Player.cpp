#include "Player.h"

Player::Player()
{
    _score = 0;
    _money = 0;
}


void Player::show(QPainter *painter)
{
    QString score_text = "Score: " + QString::number(_score);
    QString money_text = "Money: " + QString::number(_money);

    QFont font("Microsoft YaHei", 15, QFont::DemiBold);
    QFontMetrics fm(font);
    double textWidthS = fm.width(score_text);
    double textWidthM = fm.width(money_text);

    painter->setFont(font);

    painter->drawText(WIN_WIDTH - textWidthS, 30, score_text);
    painter->drawText(WIN_WIDTH - textWidthM, 60, money_text);
    painter->resetTransform();
}

void Player::changeValue(int ps, int pm)
{
    _score += ps;
    _money += pm;
}
