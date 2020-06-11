#include "Player.h"

Player::Player()
{
    _score = 0;
    _money = 100;
}

void Player::show(QPainter *painter)
{
    QString score_text = "Score: " + QString::number(_score);
    QString money_text = "Money: " + QString::number(_money);

    QFont font("Courier", 15, QFont::DemiBold);
    QFontMetrics fm(font);
    double textWidthS = fm.width(score_text);
    double textWidthM = fm.width(money_text);

    painter->setFont(font);

    painter->drawText(1040 - textWidthS, 20, score_text);
    painter->drawText(1040 - textWidthM, 40, money_text);
    painter->resetTransform();
}

void Player::changeValue(int ps, int pm)
{
    _score += ps;
    _money += pm;
}