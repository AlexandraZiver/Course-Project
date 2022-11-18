#include "wall.h"


extern qreal fromB2(qreal value);

Wall::Wall(b2World *world, QSizeF size, QPointF initPos, qreal angle):
    QGraphicsRectItem(0)
{
    setRect(-fromB2(size.width()/2), -fromB2(size.height()/2),
            fromB2(size.width()), fromB2(size.height()));          // Задаём геометрию

    setBrush(QBrush(Qt::transparent));             // Задаём цвет
    setPos(fromB2(initPos.x()), fromB2(initPos.y()));
    setRotation(angle);                     // Поворот

    // Создание объекта тела
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(initPos.x(), initPos.y());
    bodyDef.angle = 3.14*angle/180;         // Поворот для тела, но в радианах

    body = world->CreateBody(&bodyDef);

    b2PolygonShape shape;
    shape.SetAsBox(size.width()/2, size.height()/2);

    body->CreateFixture(&shape, 0.0f);
}




Wall::~Wall(){
    body->GetWorld()->DestroyBody(body);
}
