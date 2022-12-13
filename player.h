#ifndef PLAYER_H
#define PLAYER_H

#include "Box2D/Box2D.h"
#include "obj.h"
#include <QGraphicsScene>
#include <QGraphicsItem>

#include <QGraphicsRectItem>

#include <QGraphicsPixmapItem>  // players

class Player_1 : public QGraphicsPixmapItem, public Obj {
public:
    Player_1(b2World* world, QPointF initPos, QString skinPath);
    ~Player_1();
    void advance(int phase) override;
};

class Player_2 : public QGraphicsPixmapItem {
public:
    Player_2(b2World* world, QPointF initPos, QString skinPath);
    ~Player_2();
    void advance(int phase) override;

};

#endif // PLAYER_H
