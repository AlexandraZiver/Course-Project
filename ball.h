#ifndef BALL_H
#define BALL_H
#include "Box2D/Box2D.h"
#include <QGraphicsItem>

#include <QGraphicsScene>
#include <QGraphicsItem>

#include <QGraphicsEllipseItem>

#include <QGraphicsPixmapItem>

class Ball : public QGraphicsEllipseItem {
public:
    Ball(b2World* world, qreal Radius, QPointF initPos);
    ~Ball();
    //sleep?
    void advance(int phase);
    int attractivePover();
private:

};

#endif // BALL_H
