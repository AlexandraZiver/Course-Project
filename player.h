#ifndef PLAYER_H
#define PLAYER_H

#include "Box2D/Box2D.h"

#include <QGraphicsScene>
#include <QGraphicsItem>

#include <QGraphicsRectItem>

#include <QGraphicsPixmapItem>  // players

class Player_1 : public QGraphicsRectItem {
public:
    Player_1(b2World* world, QSizeF size, QPointF initPos, qreal angel);
    ~Player_1();
    void advance(int phase);
};

class Player_2 : public QGraphicsRectItem {
public:
    Player_2(b2World* world, QSizeF size, QPointF initPos, qreal angle);
    ~Player_2();
    void advance(int phase);

};

#endif // PLAYER_H
