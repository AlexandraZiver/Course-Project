#include "gamescene.h"

extern b2Body* PlayerBody1;
extern b2Body* PlayerBody2;

extern qreal fromB2(qreal value);
extern qreal toB2(qreal value);

extern int counterPlayer1;
extern int counterPlayer2;

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

    shape.SetAsBox(toB2(pixmap().width()/2), toB2(pixmap().height()/2));

    PlayerBody1 = world->CreateBody(&playerBodyDef);
    PlayerBody1->CreateFixture(&shape, 5);
    PlayerBody1->SetFixedRotation(true);

}

void Player_1::advance(int phase)
{
    if(phase) {
        setPos(fromB2(PlayerBody1->GetPosition().x), fromB2(PlayerBody1->GetPosition().y));

        b2Vec2 vel = PlayerBody1->GetLinearVelocity();
        b2Vec2 pos = PlayerBody1->GetPosition();
        if(pos.x > 4.3658 && pos.x < 5.661) {   // Перегородка, движение в этом интервале сводится к 0.
            vel.x = 0;
            PlayerBody1->SetLinearVelocity(vel);
        }
        // Для double jump. Когда герой на земле а это y = 5.385
        if(pos.y <= 5.400 && pos.y >= 5.10) {
            counterPlayer1 = 0;
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
    PlayerBody1->GetWorld()->DestroyBody(PlayerBody1);
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

    shape.SetAsBox(toB2(pixmap().width()/2), toB2(pixmap().height()/2));

    PlayerBody2 = world->CreateBody(&playerBodyDef);
    PlayerBody2->CreateFixture(&shape, 5);
    PlayerBody2->SetFixedRotation(true);
}

void Player_2::advance(int phase) {
    if(phase) {
        setPos(fromB2(PlayerBody2->GetPosition().x), fromB2(PlayerBody2->GetPosition().y));

        b2Vec2 vel = PlayerBody2->GetLinearVelocity();
        b2Vec2 pos = PlayerBody2->GetPosition();

        if(pos.x > 4.3658 && pos.x < 5.639) {   // Перегородка, движение в этом интервале сводится к 0.
            vel.x = 0;
            PlayerBody2->SetLinearVelocity(vel);
        }

        if(pos.y <= 5.400 && pos.y >= 5.10) {
            counterPlayer2 = 0;
        }

    }
    else {
        foreach(QGraphicsItem* item, collidingItems()) {
            item->setData(1, true);
        }
    }
}

Player_2::~Player_2() {
    PlayerBody2->GetWorld()->DestroyBody(PlayerBody2);
}
