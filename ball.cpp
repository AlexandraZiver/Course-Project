#include "ball.h"

extern b2Body* ballBody;

extern bool is_player_1_goal;
extern bool is_created;

extern int player_1_Score;
extern int player_2_Score;
extern qreal ballWeight;            // приходит с authentication.cpp
extern qreal ballSize;
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
    bodyDef.linearDamping = 0.1;


    ballBody = world->CreateBody(&bodyDef);

    b2CircleShape shape;
    shape.m_radius = radius;
//    qDebug() << "BallDestiny: " << destinyCalculation();
    b2Fixture* fixture = ballBody->CreateFixture(&shape, destinyCalculation());
    fixture->SetRestitution(0.7);
}


Ball::~Ball() {
    ballBody->GetWorld()->DestroyBody(ballBody);
}


qreal Ball::destinyCalculation() {
    // Припустимо що ballSize = 0,3 * 10 це площа, тоді R = (3 / pi)^(1/2) = 0,977297   v = 3,822   m = 4   p = 4 / 3,822 = 1,308                   // Максимальне значення маси для великого
    //
    //               ballSize = 0,4 * 10 це площа, тоді R = (4 / pi)^(1/2) = 1,12   v = 5,884   m = 14  p = 14 / 5,888 = 2,380
    //
    //               ballSize = 0,55 * 10 це площа, тоді R = (5,5 / pi)^(1/2) = 1,32   v = 9,634   m = 25  p = 24 / 9,634 = 2,5
    //               ballSize = 0,55 * 10 це площа, тоді R = (5,5 / pi)^(1/2) = 1,32   v = 9,634   m = 30  p = 30 / 9,634 = 3,1               // Можна помножити на 2  // Максимальне значення маси для великого

    qreal ballSquare = ballSize * 10;     // Площа кругу, для пошуку щільності нам потрібен об'єм. Для об'єма радіус, оскільки мі знаемо площу (S = piR^2), звідси
                                          // R = (S / pi)^(1/2)
    qreal ballRadius = sqrt((ballSquare / 3.141));                      // Радіус м'яча
    qreal ballAmountOf = (4 * pow(ballRadius, 3) * 3.141) / 3;              // Об'єм м'яча
    qreal ballDestiny = ballWeight / ballAmountOf;                      // Щільність м'яча

    return ballDestiny;
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
