#include "gamescene.h"
#include "ui_gamescene.h"
#include <mainwindow.h>

#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QMessageBox>

Player_1* pl1;
Player_2* pl2;
Ball* gameBall;

Bonus* gameBonus;

b2Body* ballBody;
b2Body* PlayerBody1;
b2Body* PlayerBody2;

int player_1_Score = 0;             // Счёт первого игрока
int player_2_Score = 0;             // Счёт второго игрока
int ScoreToWin = 7;

bool is_player_1_goal = false;      // true - первый (левый) игрок забил, false - второй (правый) игрок забил
bool is_created = true;             // Создан ли мяч? true потому что в начале он создан
bool is_paused = false;             // Стоит ли пауза. Изначально не стоит - false

bool bonusCreated = false;

int plr_1_Speed = PlayerSpeed;              // Швидкість гравця
int plr_1_HeightJump = PlayerHeightJump;    // Высота стрибка

int plr_2_Speed = PlayerSpeed;
int plr_2_HeightJump = PlayerHeightJump;

int counterPlayer1 = 0;             // double jump for Player1     200 row
int counterPlayer2 = 0;             // double jump for Player2

extern qreal ballSize;              // приходит с authentication.cpp


qreal fromB2(qreal value) {
    return value * SCALE;
}

qreal toB2(qreal value) {
    return value/SCALE;
}


GameScene::GameScene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameScene)
{
    ui->setupUi(this);
    ui->winLabel->hide();
    ui->startNewGame->hide();

    world = new b2World(b2Vec2(0.00f, 10.00f));

    scene = new Scene(0, 0, 10, 6, world);      // x, y, width, height

    ui->graphicsView->setScene(scene);

    scene->addRect(scene->sceneRect());

    scene->addItem(new Wall(world, QSizeF(10, 0.1), QPointF(5, 5.95), 0));    // Пол
    scene->addItem(new Wall(world, QSizeF(10, 0.15), QPointF(0, 3), 90));       // Стена слева
    scene->addItem(new Wall(world, QSizeF(10, 0.1), QPointF(10, 3), 90));       // Стена справа
    scene->addItem(new Wall(world, QSizeF(3, 0.1), QPointF(5, 4.5), 90));      // Перегородка по середине

    pl1 = new Player_1(world, QSizeF(1, 1), QPointF(1, 5.40), 0);
    pl2 = new Player_2(world, QSizeF(1, 1), QPointF(7, 5.40), 0);
    scene->addItem(pl1);
    scene->addItem(pl2);

    gameBall = new Ball(world, ballSize, QPointF(5, 0.5));
    scene->addItem(gameBall);


    generateBonus = new QTimer(this);
    connect(generateBonus, SIGNAL(timeout()),
            this, SLOT(generateNewBonus()));
    generateBonus->start(30000);

    frameTimer = new QTimer(this);
    connect(frameTimer, SIGNAL(timeout()),
            scene, SLOT(advance()));
    frameTimer->start(1000/60);



    scoreTimer = new QTimer(this);
    connect(scoreTimer, SIGNAL(timeout()),
            this, SLOT(score()));
    scoreTimer->start(1000);

}

GameScene::~GameScene()
{
    delete ui;
    delete scene;
    delete world;
}


void GameScene::score() {

    if(player_1_Score == ScoreToWin) {
        ui->scorePlayer1->setText(QString::number(player_1_Score));
        ui->winLabel->setText(QString("Gratz Team Red WIN"));
        ui->winLabel->show();
        ui->startNewGame->show();
        endGame();
        is_created = true;

        // Сброс бонусів
        plr_1_Speed = PlayerSpeed;
        plr_1_HeightJump = PlayerHeightJump;
        plr_2_Speed = PlayerSpeed;
        plr_2_HeightJump = PlayerHeightJump;
    } else if(player_2_Score == ScoreToWin) {
        ui->scorePlayer2->setText(QString::number(player_2_Score));
        ui->winLabel->setText(QString("Gratz Team Blue WIN"));
        ui->winLabel->show();
        ui->startNewGame->show();
        endGame();
        is_created = true;

        // Сброс бонусів
        plr_1_Speed = PlayerSpeed;
        plr_1_HeightJump = PlayerHeightJump;
        plr_2_Speed = PlayerSpeed;
        plr_2_HeightJump = PlayerHeightJump;
    }

    if(!is_created && is_player_1_goal && !is_paused) {                   // is_created = false когда был гол и мячик удалился в Ball::advance() | первый игрок забил
        is_created = true;
        gameBall = new Ball(world, ballSize, QPointF(3, 2));
        ballBody->SetType(b2_staticBody);
        QTimer::singleShot(1000, this, SLOT(ballSleep()));
        scene->addItem(gameBall);
        ui->scorePlayer1->setText(QString::number(player_1_Score));
        qDebug()  << "Score: " << player_1_Score << " : " << player_2_Score;

        // Сброс бонусів
        plr_1_Speed = PlayerSpeed;
        plr_1_HeightJump = PlayerHeightJump;
        plr_2_Speed = PlayerSpeed;
        plr_2_HeightJump = PlayerHeightJump;
    }
    else if(!is_created && !is_player_1_goal && !is_paused) {             // второй игрок забил
        is_created = true;
        gameBall = new Ball(world, ballSize, QPointF(7, 2));
        ballBody->SetType(b2_staticBody);
        QTimer::singleShot(1000, this, SLOT(ballSleep()));
        scene->addItem(gameBall);
        ui->scorePlayer2->setText(QString::number(player_2_Score));
        qDebug()  << "Score: " << player_1_Score << " : " << player_2_Score;

        // Сброс бонусів
        plr_1_Speed = PlayerSpeed;
        plr_1_HeightJump = PlayerHeightJump;
        plr_2_Speed = PlayerSpeed;
        plr_2_HeightJump = PlayerHeightJump;
    }
}


void GameScene::ballSleep() {
    if(!is_paused) {
        ballBody->SetType(b2_dynamicBody);
    }
}


void GameScene::endGame() {
    PlayerBody1->SetType(b2_staticBody);
    PlayerBody2->SetType(b2_staticBody);
    is_paused = true;
}


void GameScene::startGame() {
    ui->startNewGame->hide();
    ui->winLabel->hide();
    PlayerBody1->SetType(b2_dynamicBody);
    PlayerBody2->SetType(b2_dynamicBody);

    // Обновление счёта
    player_1_Score = 0;
    player_2_Score = 0;
    ui->scorePlayer1->setText(QString::number(player_1_Score));
    ui->scorePlayer2->setText(QString::number(player_2_Score));

    is_paused = false;
    is_created = false;

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

            vel.x = -plr_1_Speed;

        break;
    case Qt::Key_D:

        if(pos.x > 0 && pos.x < 4.3658) {   // Что бы он не смог двигаться по перегородке
            vel.x = plr_1_Speed;
        }
        break;

    case Qt::Key_W:

        // counter обновляется в Player_1::advance
        if(pos.y > 2 && counterPlayer1 < 2)
        {
            vel.y = -plr_1_HeightJump;   // Высота прыжка
            counterPlayer1++;
        }
        break;

    case Qt::Key_Left:
        if(pos2.x < 10 && pos2.x > 5.63) {   // Что бы он не смог двигаться по перегородке  // зацепка
            vel2.x = -plr_2_Speed;
        }
        break;

    case Qt::Key_Right:
            vel2.x = plr_2_Speed;
        break;

    case Qt::Key_Up:

        if(pos2.y > 2 && counterPlayer2 < 2)
        {
            vel2.y = -plr_2_HeightJump;   // Высота прыжка
            counterPlayer2++;
        }
        break;
    }
    PlayerBody1->SetLinearVelocity(vel);
    PlayerBody2->SetLinearVelocity(vel2);
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


void GameScene::on_startNewGame_clicked()
{
    startGame();
}


b2Vec2 pastBallVel;
b2Vec2 pastPlayer1Vel;
b2Vec2 pastPLayer2Vel;
void GameScene::on_pauseGame_clicked()
{
    if(PlayerBody1->GetType() == b2_dynamicBody && PlayerBody2->GetType() == b2_dynamicBody) {      // paused
        is_paused = true;
        pastBallVel = ballBody->GetLinearVelocity();
        pastPlayer1Vel = PlayerBody1->GetLinearVelocity();
        pastPLayer2Vel = PlayerBody2->GetLinearVelocity();

        PlayerBody1->SetType(b2_staticBody);
        PlayerBody2->SetType(b2_staticBody);
        ballBody->SetType(b2_staticBody);

        if(bonusCreated)
        gameBonus->yspeed = 0;

        ui->pauseGame->setText("Unpause");
    }
    else if(PlayerBody1->GetType() == b2_staticBody && PlayerBody2->GetType() == b2_staticBody) {   // unpaused
        is_paused = false;
        PlayerBody1->SetType(b2_dynamicBody);
        PlayerBody2->SetType(b2_dynamicBody);
        ballBody->SetType(b2_dynamicBody);

        ballBody->SetLinearVelocity(pastBallVel);
        PlayerBody1->SetLinearVelocity(pastPlayer1Vel);
        PlayerBody2->SetLinearVelocity(pastPLayer2Vel);

        if(bonusCreated)
        gameBonus->yspeed = 2;

        ui->pauseGame->setText("Pause");
    }
}


void GameScene::generateNewBonus()
{
    if(!is_paused) {
        gameBonus = new Bonus(scene->sceneRect().width());
        scene->addItem(gameBonus);
        bonusCreated = true;
    }
}



