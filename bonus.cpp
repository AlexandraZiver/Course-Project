#include "bonus.h"

extern Bonus* game_bonus;
extern int player_1_speed;
extern int player_1_jump_height;

extern int player_2_speed;
extern int player_2_jump_height;

extern bool is_bonus_created;
extern bool isMusic;

extern qreal ToB2(qreal value);

Bonus::Bonus(int xspread) : QGraphicsPixmapItem(0)
{
    int bonusTypeRand = rand() % 3 + 1;

    if(bonusTypeRand == 1) {
        setPixmap(QPixmap(":/images/speedBonus.png"));
        bonus_type_ = "speedBonus";
    }
    else if(bonusTypeRand == 2) {
        setPixmap(QPixmap(":/images/jumpBonus.png"));
        bonus_type_ = "jumpBonus";
    }
    else if(bonusTypeRand == 3) {
        setPixmap(QPixmap(":/images/negativeSpeedBonus.png"));
        bonus_type_ = "negativeSpeedBonus";
    }

    setPos(rand() % (xspread - pixmap().width()), 0);
}

void Bonus::advance(int phase)
{

    if(phase) {
        moveBy(0, yspeed);
        QPointF pos = game_bonus->pos();
        if(ToB2(pos.y()) > 5.5) {
            delete this;
            return;
        }

        if(data(0).toBool()) {                          // player 1
            if(bonus_type_ == "speedBonus")
            {
                player_1_speed = 10;
            }
            else if(bonus_type_ == "jumpBonus")
            {
                player_1_jump_height = 10;
            }
            else if(bonus_type_ == "negativeSpeedBonus")
            {
                player_1_speed = 2;
            }
            bonusSound(isMusic);
            delete this;
            is_bonus_created = false;
        }

        if(data(1).toBool()) {                          // player 2
            if(bonus_type_ == "speedBonus")
            {
                player_2_speed = 13;
            }
            else if(bonus_type_ == "jumpBonus")
            {
                player_2_jump_height = 10;
            }
            else if(bonus_type_ == "negativeSpeedBonus")
            {
                player_2_speed = 2;
            }
            bonusSound(isMusic);
            delete this;
            is_bonus_created = false;
        }
    }
}
