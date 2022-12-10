#ifndef BONUS_H
#define BONUS_H

#include "Box2D/Box2D.h"
#include <QGraphicsItem>

#include <QGraphicsScene>
#include <QGraphicsItem>

#include <QGraphicsRectItem>

#include <QGraphicsPixmapItem>


class Bonus : public QGraphicsPixmapItem {
public:
    Bonus(int xspread);
    void advance(int phase);
    int yspeed =  2;
private:
    QString bonusType;
    QColor bonusColor;

};

#endif // BONUS_H
