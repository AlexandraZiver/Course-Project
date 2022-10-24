#ifndef BALL_H
#define BALL_H

#include "gamescene.h"

//Ball::Ball(b2World* world, qreal radius, QPointF initPos)
//    : QGraphicsEllipseItem(0)
//{
//    setRect( (-radius * 100), -radius * 100, radius * 2 * 100, radius * 2 * 100);
//    setBrush(Qt::yellow);
//    setPos(initPos.x() * 100, initPos.y() * 100);

//    b2BodyDef bodyDef;
//    bodyDef.type = b2_dynamicBody;
//    bodyDef.position.Set(initPos.x(), initPos.y());
//    bodyDef.linearDamping = 0.6;

//    ballBody = world->CreateBody(&bodyDef);

//    b2CircleShape shape;
//    shape.m_radius = radius;

//    b2Fixture* fixture = ballBody->CreateFixture(&shape, 1.0f);
//    fixture->SetRestitution(0.7);
//}

//Ball::~Ball() {
//    ballBody->GetWorld()->DestroyBody(ballBody);
//}


//// Анимация Мяча

//void Ball::advance(int phase) {
//    if(phase) {
//        b2Vec2 pos = ballBody->GetPosition();
//        setPos(ballBody->GetPosition().x * 100,
//               ballBody->GetPosition().y * 100 );
////                qDebug() << pos.x << "  " << pos.y;

//        if(pos.y >= 5.3) {
//            if(pos.x >= 5) {
//                is_player_1_goal = true;                    // Забил левый игрок
//                player_1_Score++;

//            } else {
//                is_player_1_goal = false;                   // Забил правый игрок
//                player_2_Score++;
//            }
//            is_created = false;
//            delete(this);

//        }


//    }
//}

#endif // BALL_H
