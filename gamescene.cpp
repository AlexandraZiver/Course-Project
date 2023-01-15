#include "gamescene.h"
#include "ui_gamescene.h"
#include <mainwindow.h>
#include "registration.h"
#include "authorization.h"
#include "exception.h"
#include "registration.h"

#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QMessageBox>

Player_1* player_1;
Player_2* player_2;
Ball* gameBall;

Bonus* game_bonus;

b2Body* ball_body;
b2Body* player_1_body;
b2Body* player_2_body;

int player_1_score = 0;             // Рахунок першого гравця
int player_2_score = 0;             // Рахунок другого гравця
int ScoreToWin = 7;

bool is_player_1_goal = false;      // true - первый (левый) игрок забил, false - второй (правый) игрок забил
bool is_ball_created = true;             // Создан ли мяч? true потому что в начале он создан
bool is_paused = false;             // Стоит ли пауза. Изначально не стоит - false
bool is_bonus_created = false;          // Чи створен Бонус

int player_1_speed = PlayerSpeed;              // Швидкість гравця
int player_2_speed = PlayerSpeed;
int player_1_jump_height = PlayerHeightJump;    // Высота стрибка
int player_2_jump_height = PlayerHeightJump;

int jump_counter_player_1 = 0;             // double jump for Player1     200 row
int jump_counter_player_2 = 0;             // double jump for Player2

extern qreal ball_size;              // приходит с gamepreparation.cpp
extern qreal exitBool;              // приходит с паузы
extern qreal continueBool;          // приходит с паузы

extern QString game_map_path;         // Карта
extern QString player_1_skin_path;     // Шлях до модельки гравця 1
extern QString player_2_skin_path;     // Шлях до модельки гравця 2
extern QString ball_skin_path;        // Шлях до модельки м'яча

// Samira
extern QString Users_name;
extern std:: vector<std::pair<int, QString>> rec;


extern bool isMusic;

qreal FromB2(qreal value) {
    return value * SCALE;
}

qreal ToB2(qreal value) {
    return value/SCALE;
}


GameScene::GameScene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameScene)
{
    ui->setupUi(this);
    ui->winLabel->hide();
    ui->startNewGame->hide();
    setAttribute(Qt::WA_DeleteOnClose);//alex

    world = new b2World(b2Vec2(0.00f, 10.00f));



    scene = new Scene(0, 0, 10, 6, world);      // x, y, width, height

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setStyleSheet(game_map_path);

    scene->addItem(new Wall(world, QSizeF(10, 0.1), QPointF(5, 5.95), 0));    // Підлога
    scene->addItem(new Wall(world, QSizeF(10, 0.1), QPointF(5, -8), 0));    // Потолок
    scene->addItem(new Wall(world, QSizeF(20, 0.15), QPointF(0, 3), 90));       // Стіна зліва
    scene->addItem(new Wall(world, QSizeF(20, 0.1), QPointF(10, 3), 90));       // Стіна справа
    scene->addItem(new Wall(world, QSizeF(4, 0.2), QPointF(5, 4.5), 90));      // Перегородка по центру (сітка)

    player_1 = new Player_1(world, QPointF(1, 5.40), player_1_skin_path);
    player_2 = new Player_2(world, QPointF(7, 5.40), player_2_skin_path);
    scene->addItem(player_1);
    scene->addItem(player_2);

    gameBall = new Ball(world, ball_size, QPointF(5, 0.5), ball_skin_path);
    scene->addItem(gameBall);


    generateBonus = new QTimer(this);
    connect(generateBonus, SIGNAL(timeout()),
            this, SLOT(GenerateNewBonus()));
    generateBonus->start(30000);

    frameTimer = new QTimer(this);
    connect(frameTimer, SIGNAL(timeout()),
            scene, SLOT(advance()));
    frameTimer->start(1000/60);



    scoreTimer = new QTimer(this);
    connect(scoreTimer, SIGNAL(timeout()),
            this, SLOT(Score()));
    scoreTimer->start(1000);

}

GameScene::~GameScene()
{
    delete ui;
    delete scene;
    delete world;
}
void GameScene::Save_record() // зберігає вектор з рекордами у файл
{
    QFile fileOut("record.json");
    if (fileOut.open(QIODevice::WriteOnly| QIODevice::Truncate ))
    {
        qDebug() << "Save_record is open";
        QJsonArray arrayJson ;
        for (int i = 0; i < rec.size(); i++)
        {
            QJsonObject jobj;
            jobj.insert("_userRecord",QJsonValue::fromVariant(rec[i].first));
            jobj.insert("login",QJsonValue::fromVariant(rec[i].second));
            arrayJson.append(jobj);
        }
         fileOut.write(QJsonDocument(arrayJson).toJson(QJsonDocument::Indented));
    }
fileOut.close();
}

void GameScene::read_rec()
{
    int _userRecord ;
    QString _login ;
    QFile fileOut("record.json");
   if( fileOut.open(QIODevice::ReadOnly | QIODevice::Text ))
   {
        QJsonDocument json= QJsonDocument().fromJson(fileOut.readAll());
        qDebug() << "read rec is open";

        QJsonArray arrayJson = json.array();
        for (int i=0; i < arrayJson.size();i++)
        {
         qDebug() << arrayJson[i];
        QJsonObject jobj = arrayJson[i].toObject();
        QJsonValue    userRecord = jobj["_userRecord"];
        QJsonValue    login = jobj["login"];
        _login = login.toString();
        _userRecord = userRecord.toInt();
        qDebug() << _login;
        qDebug() << _userRecord;

          rec.push_back({_userRecord, _login});
        }
    }
  fileOut.close();
}

void GameScene::change_record()  // створює вектор з рекордами
{
    int size = 0;
    QFile fileOut("record.json");

   if( fileOut.open(QIODevice::ReadOnly | QIODevice::Text ))
   {
       size = fileOut.size();
       if (size != 0)
       {
           rec.clear();
       }
       read_rec();
   }
   for (int i = 0; i < rec.size(); i++)
   {
       if (rec[i].second == Users_name)
       {
           rec[i].first++;
           qDebug() <<  Users_name;
       }
   }
    fileOut.close();
}

void GameScene::Score() {

    if(player_1_score == ScoreToWin) {

        change_record();
        Save_record();
        ui->scorePlayer1->setText(QString::number(player_1_score));
        ui->winLabel->setText(QString("Gratz Team Red WIN"));
        EndGame();
        player_1_score = 0;

    } else if(player_2_score == ScoreToWin) {
        ui->scorePlayer2->setText(QString::number(player_2_score));
        ui->winLabel->setText(QString("Gratz Team Blue WIN"));
        EndGame();
        player_2_score = 0;

    }

    if(!is_ball_created && is_player_1_goal && !is_paused) {                   // is_ball_created = false когда был гол и мячик удалился в Ball::advance() | первый игрок забил
        is_ball_created = true;
        gameBall = new Ball(world, ball_size, QPointF(3, 2), ball_skin_path);
        ball_body->SetType(b2_staticBody);
        QTimer::singleShot(1000, this, SLOT(BallSleep()));
        scene->addItem(gameBall);
        ui->scorePlayer1->setText(QString::number(player_1_score));
        qDebug()  << "Score: " << player_1_score << " : " << player_2_score;

        // Сброс бонусів
        player_1_speed = PlayerSpeed;
        player_1_jump_height = PlayerHeightJump;
        player_2_speed = PlayerSpeed;
        player_2_jump_height = PlayerHeightJump;
    }
    else if(!is_ball_created && !is_player_1_goal && !is_paused) {             // второй игрок забил
        is_ball_created = true;
        gameBall = new Ball(world, ball_size, QPointF(7, 2), ball_skin_path);
        ball_body->SetType(b2_staticBody);
        QTimer::singleShot(1000, this, SLOT(BallSleep()));
        scene->addItem(gameBall);
        ui->scorePlayer2->setText(QString::number(player_2_score));
        qDebug()  << "Score: " << player_1_score << " : " << player_2_score;

        // Сброс бонусів
        player_1_speed = PlayerSpeed;
        player_1_jump_height = PlayerHeightJump;
        player_2_speed = PlayerSpeed;
        player_2_jump_height = PlayerHeightJump;
    }
}


void GameScene::BallSleep() {
    if(!is_paused) {
        ball_body->SetType(b2_dynamicBody);
    }
}


void GameScene::EndGame() {
    ui->winLabel->show();
    ui->startNewGame->show();
    player_1_body->SetType(b2_staticBody);
    player_2_body->SetType(b2_staticBody);
    is_paused = true;
    game_bonus->yspeed = 0;
    is_ball_created = true;

    // Сброс бонусів
    player_1_speed = PlayerSpeed;
    player_1_jump_height = PlayerHeightJump;
    player_2_speed = PlayerSpeed;
    player_2_jump_height = PlayerHeightJump;
}


void GameScene::StartGame() {
    ui->startNewGame->hide();
    ui->winLabel->hide();
    player_1_body->SetType(b2_dynamicBody);
    player_2_body->SetType(b2_dynamicBody);
    is_paused = false;
    game_bonus->yspeed = 2;
    is_ball_created = false;

    // Обновление счёта
    player_1_score = 0;
    player_2_score = 0;
    ui->scorePlayer1->setText(QString::number(player_1_score));
    ui->scorePlayer2->setText(QString::number(player_2_score));

}


bool key_A_pressed = false;
bool key_D_pressed = false;

bool key_Left_pressed = false;
bool key_Right_pressed = false;

void Scene::keyPressEvent(QKeyEvent *event) {
    // Player 1
       b2Vec2 pos = player_1_body->GetPosition();
       b2Vec2 vel = player_1_body->GetLinearVelocity();

    // Player 2
       b2Vec2 pos2 = player_2_body->GetPosition();
       b2Vec2 vel2 = player_2_body->GetLinearVelocity();

    switch(event->key()) {
    case Qt::Key_A:
            vel.x = -player_1_speed;
            key_A_pressed = true;
        break;
    case Qt::Key_D:


        if(pos.x > 0 && pos.x < 4.3658) {   // Что бы он не смог двигаться по перегородке
            vel.x = player_1_speed;
            key_D_pressed = true;
        }
        break;

    case Qt::Key_W:

        // counter обновляется в Player_1::advance
        if(pos.y > 2 && jump_counter_player_1 < 2)
        {
            vel.y = -player_1_jump_height;   // Высота прыжка
            jump_counter_player_1++;
            jumpSound(isMusic);
        }

        break;

    case Qt::Key_Left:
        if(pos2.x < 10 && pos2.x > 5.63) {   // Что бы он не смог двигаться по перегородке  // зацепка
            vel2.x = -player_2_speed;
            key_Left_pressed = true;
        }
        break;

    case Qt::Key_Right:
            vel2.x = player_2_speed;
            key_Right_pressed = true;
        break;

    case Qt::Key_Up:

        if(pos2.y > 2 && jump_counter_player_2 < 2)
        {
            vel2.y = -player_2_jump_height;   // Высота прыжка
            jump_counter_player_2++;
            jumpSound(isMusic);
        }
        break;
    }
    player_1_body->SetLinearVelocity(vel);
    player_2_body->SetLinearVelocity(vel2);
}



void Scene::keyReleaseEvent(QKeyEvent * event)
{
    // Player 1
       b2Vec2 pos = player_1_body->GetPosition();
       b2Vec2 vel = player_1_body->GetLinearVelocity();

    // Player 2
       b2Vec2 pos2 = player_2_body->GetPosition();
       b2Vec2 vel2 = player_2_body->GetLinearVelocity();


       // player 1
       if(event->key() == Qt::Key_A && !key_D_pressed) {
           vel.x = 0;
       }
       else if(event->key() == Qt::Key_D && !key_A_pressed) {
           if(pos.x > 0 && pos.x < 4.3658) {   // Что бы он не смог двигаться по перегородке
                vel.x = 0;
           }
       }

       // player 2
       if(event->key() == Qt::Key_Left && !key_Right_pressed) {
           if(pos2.x < 10 && pos2.x > 5.63) {   // Что бы он не смог двигаться по перегородке
               vel2.x = 0;
           }
       }
       else if(event->key() == Qt::Key_Right && !key_Left_pressed) {
            vel2.x = 0;
       }

       switch(event->key()) {
       case Qt::Key_A:
                key_A_pressed = false;
            break;
       case Qt::Key_D:
                key_D_pressed = false;
            break;
       case Qt::Key_Left:
           key_Left_pressed = false;
           break;
       case Qt::Key_Right:
           key_Right_pressed = false;
           break;

        }
    player_1_body->SetLinearVelocity(vel);
    player_2_body->SetLinearVelocity(vel2);
}


Scene::Scene(qreal x, qreal y, qreal width, qreal height, b2World *world)
    : QGraphicsScene(FromB2(x), FromB2(y), FromB2(width), FromB2(height))
{
    this->world = world;
}


void Scene::advance() {
    world->Step(1.00f/60.00, 6, 2);
    QGraphicsScene::advance();
}


void GameScene::on_startNewGame_clicked()
{
    StartGame();
}


b2Vec2 pastBallVel;
b2Vec2 pastPlayer1Vel;
b2Vec2 pastPLayer2Vel;

void GameScene::on_pauseGame_clicked()
{
    if(player_1_body->GetType() == b2_dynamicBody && player_2_body->GetType() == b2_dynamicBody) {      // paused
        is_paused = true;
        pastBallVel = ball_body->GetLinearVelocity();
        pastPlayer1Vel = player_1_body->GetLinearVelocity();
        pastPLayer2Vel = player_2_body->GetLinearVelocity();

        player_1_body->SetType(b2_staticBody);
        player_2_body->SetType(b2_staticBody);
        ball_body->SetType(b2_staticBody);

        if(is_bonus_created)
        game_bonus->yspeed = 0;
//
        hide();
        pause = new Pause();
        pause->setModal(true);
        pause->exec();
       if(exitBool) {
           player_1_score = 0;
           player_2_score = 0;
           ui->scorePlayer1->setText(QString::number(player_1_score));
           ui->scorePlayer2->setText(QString::number(player_2_score));
           scene->clear();
           exitBool= false;
           is_paused = false;
       this->close();

}

if(continueBool) {
    this->show();
        is_paused = false;
               player_1_body->SetType(b2_dynamicBody);
               player_2_body->SetType(b2_dynamicBody);
               ball_body->SetType(b2_dynamicBody);

               ball_body->SetLinearVelocity(pastBallVel);
               player_1_body->SetLinearVelocity(pastPlayer1Vel);
               player_2_body->SetLinearVelocity(pastPLayer2Vel);

               if(is_bonus_created)
               game_bonus->yspeed = 2;
               continueBool = false;

//

}
    }
        }

void GameScene::GenerateNewBonus()
{
    if(!is_paused) {
        game_bonus = new Bonus(scene->sceneRect().width());
        scene->addItem(game_bonus);
        is_bonus_created = true;
    }
}








