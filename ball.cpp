#include "ball.h"

extern b2Body* ballBody;

extern bool is_player_1_goal;
extern bool is_created;

extern int player_1_Score;
extern int player_2_Score;
extern qreal ballWeight;            // приходит с authentication.cpp
extern bool is_restart;

extern qreal fromB2(qreal value);

Ball::Ball(b2World* world, qreal radius, QPointF initPos)
    : QGraphicsEllipseItem(0)
{
    setRect(-fromB2(radius), -fromB2(radius), fromB2(radius*2), fromB2(radius*2));
    setBrush(Qt::yellow);
    setPos(fromB2(initPos.x()), fromB2(initPos.y()));

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(initPos.x(), initPos.y());
    bodyDef.linearDamping = attractivePover();


    ballBody = world->CreateBody(&bodyDef);

    b2CircleShape shape;
    shape.m_radius = radius;

    b2Fixture* fixture = ballBody->CreateFixture(&shape, 1.0f);
    fixture->SetRestitution(0.7);
}

Ball::~Ball() {
    ballBody->GetWorld()->DestroyBody(ballBody);
}

int  Ball::attractivePover() {
    float attractivePover = float(ballWeight)*0.98;
    return attractivePover;
}
void Ball::advance(int phase) {
    if(phase) {

        b2Vec2 pos = ballBody->GetPosition();
        setPos(fromB2(ballBody->GetPosition().x),
               fromB2(ballBody->GetPosition().y));
//                qDebug() << pos.x << "  " << pos.y;

        if(pos.y >= 5.3) {
            if(pos.x >= 5) {
                is_player_1_goal = true;                    // Забил левый игрок
                player_1_Score++;

            } else {
                is_player_1_goal = false;                   // Забил правый игрок
                player_2_Score++;
            }
            is_created = false;
            delete(this);
        }

    }
}
