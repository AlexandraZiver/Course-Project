#include "bonus.h"

extern Bonus* gameBonus;
extern int plr_1_Speed;
extern int plr_1_HeightJump;

extern int plr_2_Speed;
extern int plr_2_HeightJump;
extern bool bonusCreated;

extern qreal toB2(qreal value);

Bonus::Bonus(int xspread) : QGraphicsEllipseItem(0)
{
    int bonusTypeRand = rand() % 3 +1;
    QColor color = Qt::black;

    if(bonusTypeRand == 1) {
        color = Qt::yellow;
        bonusType = "speedBonus";
    }
    else if(bonusTypeRand == 2) {
        color = Qt::green;
        bonusType = "jumpBonus";
    }
    else if(bonusTypeRand == 3) {
        color = Qt::red;
        bonusType = "negativeSpeedBonus";
    }

    setBrush(color);
    setRect(0, 0, 50, 50);
    setPos(rand() % (xspread - 50), 0);
}

void Bonus::advance(int phase)
{

    if(phase) {
        moveBy(0, yspeed);
        QPointF pos = gameBonus->pos();
        if(toB2(pos.y()) > 5.5) {
            delete this;
            return;
        }


        if(data(0).toBool()) {                          // player 1
            if(bonusType == "speedBonus")
            {
                plr_1_Speed = 13;
            }
            else if(bonusType == "jumpBonus")
            {
                plr_1_HeightJump = 10;
            }
            else if(bonusType == "negativeSpeedBonus")
            {
                plr_1_Speed = 2;
            }

            delete this;
            bonusCreated = false;
        }

        if(data(1).toBool()) {                          // player 2
            if(bonusType == "speedBonus")
            {
                plr_2_Speed = 13;
            }
            else if(bonusType == "jumpBonus")
            {
                plr_2_HeightJump = 10;
            }
            else if(bonusType == "negativeSpeedBonus")
            {
                plr_2_Speed = 2;
            }
            delete this;
            bonusCreated = false;
        }
    }
}
