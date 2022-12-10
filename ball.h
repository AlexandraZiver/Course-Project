#ifndef BALL_H
#define BALL_H
#include "Box2D/Box2D.h"
#include <QGraphicsItem>

#include <QGraphicsScene>
#include <QGraphicsItem>

#include <QGraphicsEllipseItem>

#include <QGraphicsPixmapItem>

class Ball : public QGraphicsPixmapItem {
public:
    Ball(b2World* world, qreal Radius, QPointF initPos, QString skinPath);
    ~Ball();
    //sleep?
    void advance(int phase);
    int attractivePover();
    qreal destinyCalculation();
private:

};

#endif // BALL_H
