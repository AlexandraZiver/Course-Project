#include "ball.h"

extern b2Body* ball_body;

extern bool is_player_1_goal;
extern bool is_ball_created;

extern int player_1_score;
extern int player_2_score;
extern qreal ball_weight;            // приходит с gamepreparation.cpp
extern qreal ball_size;
extern bool is_restart;

extern qreal FromB2(qreal value);


Ball::Ball(b2World* world, qreal radius, QPointF initPos, QString skinPath)
    : QGraphicsPixmapItem(0)
{
    setPixmap(QPixmap(skinPath));
    QPointF pixmapPos(-pixmap().width()/2, -pixmap().width()/2);            // Центруемо м'яч
    setOffset(pixmapPos);

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(initPos.x(), initPos.y());
    bodyDef.linearDamping = 0.1;


    ball_body = world->CreateBody(&bodyDef);

    b2CircleShape shape;
    shape.m_radius = radius;
    b2Fixture* fixture = ball_body->CreateFixture(&shape, DestinyCalculation());
    fixture->SetRestitution(0.7);
}


Ball::~Ball() {
    ball_body->GetWorld()->DestroyBody(ball_body);
}


qreal Ball::DestinyCalculation() {
    // Припустимо що ballSize = 0,3 * 10 це площа, тоді R = (3 / pi)^(1/2) = 0,977297   v = 3,822   m = 4   p = 4 / 3,822 = 1,308                   // Максимальне значення маси для великого
    //
    //               ballSize = 0,4 * 10 це площа, тоді R = (4 / pi)^(1/2) = 1,12   v = 5,884   m = 14  p = 14 / 5,888 = 2,380
    //
    //               ballSize = 0,55 * 10 це площа, тоді R = (5,5 / pi)^(1/2) = 1,32   v = 9,634   m = 25  p = 24 / 9,634 = 2,5
    //               ballSize = 0,55 * 10 це площа, тоді R = (5,5 / pi)^(1/2) = 1,32   v = 9,634   m = 30  p = 30 / 9,634 = 3,1               // Можна помножити на 2  // Максимальне значення маси для великого

    qreal ball_square = ball_size * 10;     // Площа кругу, для пошуку щільності нам потрібен об'єм. Для об'єма радіус, оскільки мі знаемо площу (S = piR^2), звідси
                                          // R = (S / pi)^(1/2)
    qreal ball_radius = sqrt((ball_square / 3.141));                      // Радіус м'яча
    qreal ball_volume = (4 * pow(ball_radius, 3) * 3.141) / 3;              // Об'єм м'яча
    qreal ball_destiny = ball_weight / ball_volume;                      // Щільність м'яча

    return ball_destiny;
}

void Ball::advance(int phase) {
    if(phase) {

        b2Vec2 pos = ball_body->GetPosition();
        setPos(FromB2(ball_body->GetPosition().x),
               FromB2(ball_body->GetPosition().y));
        if(pos.y >= 5.1) {
            if(pos.x >= 5) {
                is_player_1_goal = true;                    // Забил левый игрок
                player_1_score++;

            } else {
                is_player_1_goal = false;                   // Забил правый игрок
                player_2_score++;
            }
            is_ball_created = false;
            delete(this);
        }
    }
}
