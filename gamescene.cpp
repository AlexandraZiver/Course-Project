#include "gamescene.h"
#include "ui_gamescene.h"

#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QMessageBox>


Player_1* pl1;
Player_2* pl2;

Ball* gameBall;

b2Body* ballBody;
b2Body* PlayerBody1;
b2Body* PlayerBody2;

int player_1_Score = 0;             // Счёт первого игрока
int player_2_Score = 0;             // Счёт второго игрока
int ScoreToWin = 7;

bool is_player_1_goal = false;      // true - первый (левый) игрок забил, false - второй (правый) игрок забил
bool is_created = true;             // Создан ли мяч? true потому что в начале он создан

int counterPlayer1 = 0;             // double jump for Player1     200 row
int counterPlayer2 = 0;             // double jump for Player2

qreal fromB2(qreal value) {
    return value * SCALE;
}



qreal toB2(qreal value) {
    return value/SCALE;
}


gameScene::gameScene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameScene)
{
    ui->setupUi(this);
    ui->winLabel->hide();
    ui->startNewGame->hide();

    world = new b2World(b2Vec2(0.00f, 10.00f));

    scene = new Scene(0, 0, 10, 6, world);      // x, y, width, height

    ui->graphicsView->setScene(scene);

    scene->addRect(scene->sceneRect());

    // QSizeF(длина, толщина) ,  Координаты QPointF(по x, по y)  , угол наклона
    // Все значения умножаются на 100, кроме угла

    scene->addItem(new GroundRect(world, QSizeF(10, 0.1), QPointF(5, 5.95), 0));    // Пол
    scene->addItem(new GroundRect(world, QSizeF(10, 0.15), QPointF(0, 3), 90));       // Стена слева
    scene->addItem(new GroundRect(world, QSizeF(10, 0.1), QPointF(10, 3), 90));       // Стена справа
    scene->addItem(new GroundRect(world, QSizeF(3, 0.1), QPointF(5, 4.5), 90));      // Перегородка по середине

//    pl1 = new Player_1(world, QSizeF(1, 1), QPointF(5.5, 2), 0);

    pl1 = new Player_1(world, QSizeF(1, 1), QPointF(1, 5.40), 0);
    pl2 = new Player_2(world, QSizeF(1, 1), QPointF(7, 5.40), 0);
    scene->addItem(pl1);
    scene->addItem(pl2);

    gameBall = new Ball(world, 0.4, QPointF(5, 0.5));
    scene->addItem(gameBall);


    frameTimer = new QTimer(this);
    connect(frameTimer, SIGNAL(timeout()),
            scene, SLOT(advance()));
    frameTimer->start(1000/60);



    scoreTimer = new QTimer(this);
    connect(scoreTimer, SIGNAL(timeout()),
            this, SLOT(score()));
    scoreTimer->start(1000);

}

gameScene::~gameScene()
{
    delete ui;
    delete scene;
    delete world;
}


void gameScene::score() {

    if(player_1_Score == ScoreToWin) {
        ui->scorePlayer1->setText(QString::number(player_1_Score));
//        QMessageBox::about(this, "Wins", "Gratz Team Red WIN");
        ui->winLabel->setText(QString("Gratz Team Red WIN"));
        ui->winLabel->show();
        ui->startNewGame->show();
        endGame();
        is_created = true;
    } else if(player_2_Score == ScoreToWin) {
        ui->scorePlayer2->setText(QString::number(player_2_Score));
//        QMessageBox::about(this, "Wins", "Gratz Team Red WIN");
        ui->winLabel->setText(QString("Gratz Team Blue WIN"));
        ui->winLabel->show();
        ui->startNewGame->show();
        endGame();
        is_created = true;
    }

    Ball* gameBall;
    if(!is_created && is_player_1_goal) {                   // is_created = false когда был гол и мячик удалился в Ball::advance() | первый игрок забил
        is_created = true;
        gameBall = new Ball(world, 0.4, QPointF(3, 2));
        ballBody->SetType(b2_staticBody);
        QTimer::singleShot(1000, this, SLOT(ballSleep()));
        scene->addItem(gameBall);
        ui->scorePlayer1->setText(QString::number(player_1_Score));
        qDebug()  << "Score: " << player_1_Score << " : " << player_2_Score;
    }
    else if(!is_created && !is_player_1_goal) {             // второй игрок забил
        is_created = true;
        gameBall = new Ball(world, 0.4, QPointF(7, 2));
        ballBody->SetType(b2_staticBody);
        QTimer::singleShot(1000, this, SLOT(ballSleep()));
        scene->addItem(gameBall);
        ui->scorePlayer2->setText(QString::number(player_2_Score));
        qDebug()  << "Score: " << player_1_Score << " : " << player_2_Score;

    }



}


void gameScene::ballSleep() {
    ballBody->SetType(b2_dynamicBody);
}

void gameScene::endGame() {
    PlayerBody1->SetType(b2_staticBody);
    PlayerBody2->SetType(b2_staticBody);
//    ballBody->SetType(b2_staticBody);
}

void gameScene::startGame() {
    ui->startNewGame->hide();
    ui->winLabel->hide();
    PlayerBody1->SetType(b2_dynamicBody);
    PlayerBody2->SetType(b2_dynamicBody);

    // Обновление счёта
    player_1_Score = 0;
    player_2_Score = 0;
    ui->scorePlayer1->setText(QString::number(player_1_Score));
    ui->scorePlayer2->setText(QString::number(player_2_Score));

    is_created = false;

}

Player_1::Player_1(b2World* world, QSizeF size, QPointF initPos, qreal angle)
    : QGraphicsRectItem(0)
{
    setRect(-fromB2(size.width()/2), -fromB2(size.height()/2),
            fromB2(size.width()), fromB2(size.height()));
    setBrush(Qt::red);
    setPos(fromB2(initPos.x()), fromB2(initPos.y()));
    b2BodyDef playerBodyDef;
    playerBodyDef.position.Set(initPos.x(), initPos.y());
    playerBodyDef.angle = 3.14*angle/180;
    playerBodyDef.type = b2_dynamicBody;

    b2CircleShape c;
    b2PolygonShape shape;

    shape.SetAsBox(size.width()/2, size.width()/2);

    PlayerBody1 = world->CreateBody(&playerBodyDef);
    PlayerBody1->CreateFixture(&shape, 5);
    PlayerBody1->CreateFixture(&c, 1.0f);
    PlayerBody1->SetFixedRotation(true);

}

void Player_1::advance(int phase)
{

    if(phase) {
        PlayerBody1->SetAngularDamping(PlayerBody1->GetAngularDamping());
        PlayerBody1->SetAngularVelocity(PlayerBody1->GetAngularVelocity());
        setPos(fromB2(PlayerBody1->GetPosition().x), fromB2(PlayerBody1->GetPosition().y));

        b2Vec2 vel = PlayerBody1->GetLinearVelocity();
        b2Vec2 pos = PlayerBody1->GetPosition();
        // Мир 10 на 6 WxH
//        qDebug() << vel.x << vel.y;

        // x = 4.3008 был
        if(pos.x > 4.3658 && pos.x < 5.661) {   // Перегородка, движение в этом интервале сводится к 0.
//            qDebug() << pos.x;
            vel.x = 0;
            PlayerBody1->SetLinearVelocity(vel);
        }


//        qDebug() << pos.y;
        // Для double jump. Когда герой на земле а это y = 5.385
        if(pos.y <= 5.400 && pos.y >= 5.30) {
            counterPlayer1 = 0;
        }

    }
}

Player_1::~Player_1()
{
    PlayerBody1->GetWorld()->DestroyBody(PlayerBody1);
}



Player_2::Player_2(b2World* world, QSizeF size, QPointF initPos, qreal angle)
    : QGraphicsRectItem(0)
{
    setRect(-fromB2(size.width()/2), -fromB2(size.height()/2),
            fromB2(size.width()), fromB2(size.height()));
    setBrush(Qt::blue);
    setPos(fromB2(initPos.x()), fromB2(initPos.y()));
    b2BodyDef playerBodyDef;
    playerBodyDef.position.Set(initPos.x(), initPos.y());
    playerBodyDef.angle = 3.14*angle/180;
    playerBodyDef.type = b2_dynamicBody;

    b2CircleShape c;
    b2PolygonShape shape;

    shape.SetAsBox(size.width()/2, size.width()/2);

    PlayerBody2 = world->CreateBody(&playerBodyDef);
    PlayerBody2->CreateFixture(&shape, 5);
    PlayerBody2->CreateFixture(&c, 1.0f);
    PlayerBody2->SetFixedRotation(true);
}

void Player_2::advance(int phase) {
    if(phase) {
        PlayerBody2->SetAngularDamping(PlayerBody2->GetAngularDamping());
        PlayerBody2->SetAngularVelocity(PlayerBody2->GetAngularVelocity());
        setPos(fromB2(PlayerBody2->GetPosition().x), fromB2(PlayerBody2->GetPosition().y));

        b2Vec2 vel = PlayerBody2->GetLinearVelocity();
        b2Vec2 pos = PlayerBody2->GetPosition();

//        qDebug() << pos.x;
//        qDebug() << vel.x << vel.y;
        if(pos.x > 4.3658 && pos.x < 5.639) {   // Перегородка, движение в этом интервале сводится к 0.
//            qDebug() << vel.x << vel.y;
            vel.x = 0;
            PlayerBody2->SetLinearVelocity(vel);
        }

        if(pos.y <= 5.400 && pos.y >= 5.30) {
            counterPlayer2 = 0;
        }

    }
}

Player_2::~Player_2() {
    PlayerBody2->GetWorld()->DestroyBody(PlayerBody2);
}


void Scene::keyPressEvent(QKeyEvent *event) {
    // Player 1
       b2Vec2 pos = PlayerBody1->GetPosition();
       b2Vec2 vel = PlayerBody1->GetLinearVelocity();

    // Player 2
       b2Vec2 pos2 = PlayerBody2->GetPosition();
       b2Vec2 vel2 = PlayerBody2->GetLinearVelocity();

    switch(event->key()) {
    case Qt::Key_A:

            vel.x = -PlayerSpeed;

        break;
    case Qt::Key_D:

        if(pos.x > 0 && pos.x < 4.3658) {   // Что бы он не смог двигаться по перегородке // зацепка
            vel.x = PlayerSpeed;
        }
        break;

    case Qt::Key_W:

        // counter обновляется в Player_1::advance
        if(pos.y > 2 && counterPlayer1 < 2)
        {
            vel.y = -PlayerHeightJump;   // Высота прыжка
            counterPlayer1++;
        }
        break;

    case Qt::Key_Left:

        // pos2.x < 10 && pos2.x > 5.60
        if(pos2.x < 10 && pos2.x > 5.63) {   // Что бы он не смог двигаться по перегородке  // зацепка
            vel2.x = -PlayerSpeed;
        }
        break;

    case Qt::Key_Right:

            vel2.x = PlayerSpeed;
        break;

    case Qt::Key_Up:

        if(pos2.y > 2 && counterPlayer2 < 2)
        {
            vel2.y = -PlayerHeightJump;   // Высота прыжка
            counterPlayer2++;
        }
        break;
    }
    PlayerBody1->SetLinearVelocity(vel);
    PlayerBody2->SetLinearVelocity(vel2);

    //    if(event->key() == Qt::Key_W) {
//        addItem(new Circle(world, 0.2, QPointF(toB2(3), toB2(3))));
//    }
}


Ball::Ball(b2World* world, qreal radius, QPointF initPos)
    : QGraphicsEllipseItem(0)
{
    setRect(-fromB2(radius), -fromB2(radius), fromB2(radius*2), fromB2(radius*2));
    setBrush(Qt::yellow);
    setPos(fromB2(initPos.x()), fromB2(initPos.y()));

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(initPos.x(), initPos.y());
    bodyDef.linearDamping = 0.6;

    ballBody = world->CreateBody(&bodyDef);

    b2CircleShape shape;
    shape.m_radius = radius;

    b2Fixture* fixture = ballBody->CreateFixture(&shape, 1.0f);
    fixture->SetRestitution(0.7);
}

Ball::~Ball() {
    ballBody->GetWorld()->DestroyBody(ballBody);
}


// Анимация Мяча

void Ball::advance(int phase) {
    if(phase) {
        b2Vec2 pos = ballBody->GetPosition();
        setPos(fromB2(ballBody->GetPosition().x),
               fromB2(ballBody->GetPosition().y) );
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


Circle::Circle(b2World *world, qreal radius, QPointF initPos) :
    QGraphicsEllipseItem(0)
{
    setRect(-fromB2(radius), -fromB2(radius), fromB2(radius*2), fromB2(radius*2));
    setBrush(QBrush(Qt::green));
    setPos(fromB2(initPos.x()), fromB2(initPos.y()));

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(initPos.x(), initPos.y());
    bodyDef.linearDamping = 0.2;    // Что бы шарики катились с затухание, а не бесконечно

    body = world->CreateBody(&bodyDef);

    b2CircleShape shape;
    shape.m_radius = radius;

    b2Fixture* fixture = body->CreateFixture(&shape, 1.0f);
    fixture->SetRestitution(0.7);      // Упругость столкновения, с какой скоростью тело упало, с такой же оно отлетело от статического объекта. В случае 0 абсолютно не упрогое (прилипло при падении)
}



Circle::~Circle()
{
    body->GetWorld()->DestroyBody(body);
}



void Circle::advance(int phase) // Метод анимации
{
    if(phase) {
        setPos(fromB2(body->GetPosition().x),
               fromB2(body->GetPosition().y) );
    }
}



GroundRect::GroundRect(b2World *world, QSizeF size, QPointF initPos, qreal angle):
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




GroundRect::~GroundRect(){
    body->GetWorld()->DestroyBody(body);
}



Scene::Scene(qreal x, qreal y, qreal width, qreal height, b2World *world)
    : QGraphicsScene(fromB2(x), fromB2(y), fromB2(width), fromB2(height))
{
    this->world = world;
}



void Scene::advance() {
    world->Step(1.00f/60.00, 6, 2);
    QGraphicsScene::advance();
}



void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    addItem(new Circle(world, 0.2, QPointF(toB2(event->scenePos().x()),
                                           toB2(event->scenePos().y()))));
}


void gameScene::on_startNewGame_clicked()
{
    startGame();
}




b2Vec2 pastBallVel;
b2Vec2 pastPlayer1Vel;
b2Vec2 pastPLayer2Vel;
void gameScene::on_pauseGame_clicked()
{

    if(PlayerBody1->GetType() == b2_dynamicBody && PlayerBody2->GetType() == b2_dynamicBody) {

        pastBallVel = ballBody->GetLinearVelocity();
        pastPlayer1Vel = PlayerBody1->GetLinearVelocity();
        pastPLayer2Vel = PlayerBody2->GetLinearVelocity();

        PlayerBody1->SetType(b2_staticBody);
        PlayerBody2->SetType(b2_staticBody);
        ballBody->SetType(b2_staticBody);
        ui->pauseGame->setText("Unpause");
    }
    else if(PlayerBody1->GetType() == b2_staticBody && PlayerBody2->GetType() == b2_staticBody) {
        PlayerBody1->SetType(b2_dynamicBody);
        PlayerBody2->SetType(b2_dynamicBody);
        ballBody->SetType(b2_dynamicBody);

        ballBody->SetLinearVelocity(pastBallVel);
        PlayerBody1->SetLinearVelocity(pastPlayer1Vel);
        PlayerBody2->SetLinearVelocity(pastPLayer2Vel);
        ui->pauseGame->setText("Pause");
    }
}

