#include "gamescene.h"

extern b2Body* player_1_body;
extern b2Body* player_2_body;

extern qreal FromB2(qreal value);
extern qreal ToB2(qreal value);

extern int jump_counter_player_1;
extern int jump_counter_player_2;

extern bool is_restart;

Player_1::Player_1(b2World* world, QPointF initPos, QString skinPath)
    : QGraphicsPixmapItem(0)
{
    setPixmap(QPixmap(skinPath));
    QPointF pixmapPos(-pixmap().width()/2, -pixmap().height()/2);
    setOffset(pixmapPos);

    b2BodyDef playerBodyDef;
    playerBodyDef.position.Set(initPos.x(), initPos.y());
    playerBodyDef.type = b2_dynamicBody;

    b2PolygonShape shape;

    shape.SetAsBox(ToB2(pixmap().width()/2), ToB2(pixmap().height()/2));

    player_1_body = world->CreateBody(&playerBodyDef);
    player_1_body->CreateFixture(&shape, 5);
    player_1_body->SetFixedRotation(true);

}

void Player_1::advance(int phase)
{
    if(phase) {
        setPos(FromB2(player_1_body->GetPosition().x), FromB2(player_1_body->GetPosition().y));

        b2Vec2 vel = player_1_body->GetLinearVelocity();
        b2Vec2 pos = player_1_body->GetPosition();
        if(pos.x > 4.3658 && pos.x < 5.661) {   // Перегородка, движение в этом интервале сводится к 0.
            vel.x = 0;
            player_1_body->SetLinearVelocity(vel);
        }
        // Для double jump. Когда герой на земле а это y = 5.385
        if(pos.y <= 5.400 && pos.y >= 5.10) {
            jump_counter_player_1 = 0;
        }

    }
    else {
        foreach(QGraphicsItem* item, collidingItems()) {
            item->setData(0, true);
        }
    }
}

Player_1::~Player_1()
{
    player_1_body->GetWorld()->DestroyBody(player_1_body);
}

Player_2::Player_2(b2World* world, QPointF initPos, QString skinPath)
    : QGraphicsPixmapItem(0)
{

    setPixmap(QPixmap(skinPath));
    QPointF pixmapPos(-pixmap().width()/2, -pixmap().height()/2);
    setOffset(pixmapPos);

    b2BodyDef playerBodyDef;
    playerBodyDef.position.Set(initPos.x(), initPos.y());
    playerBodyDef.type = b2_dynamicBody;

    b2PolygonShape shape;

    shape.SetAsBox(ToB2(pixmap().width()/2), ToB2(pixmap().height()/2));

    player_2_body = world->CreateBody(&playerBodyDef);
    player_2_body->CreateFixture(&shape, 5);
    player_2_body->SetFixedRotation(true);
}

void Player_2::advance(int phase) {
    if(phase) {
        setPos(FromB2(player_2_body->GetPosition().x), FromB2(player_2_body->GetPosition().y));

        b2Vec2 vel = player_2_body->GetLinearVelocity();
        b2Vec2 pos = player_2_body->GetPosition();

        if(pos.x > 4.3658 && pos.x < 5.639) {   // Перегородка, движение в этом интервале сводится к 0.
            vel.x = 0;
            player_2_body->SetLinearVelocity(vel);
        }

        if(pos.y <= 5.400 && pos.y >= 5.10) {
            jump_counter_player_2 = 0;
        }

    }
    else {
        foreach(QGraphicsItem* item, collidingItems()) {
            item->setData(1, true);
        }
    }
}

Player_2::~Player_2() {
    player_2_body->GetWorld()->DestroyBody(player_2_body);
}
