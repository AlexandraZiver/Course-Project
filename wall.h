#ifndef WALL_H
#define WALL_H

#include "Box2D/Box2D.h"

#include <QGraphicsScene>
#include <QGraphicsItem>

#include <QGraphicsRectItem>

#include <QGraphicsPixmapItem>

class Wall : public QGraphicsRectItem
{
public:
    Wall(b2World *world, QSizeF size, QPointF initPos, qreal angle);
    ~Wall();
private:
    b2Body* body;
};

#endif // WALL_H
