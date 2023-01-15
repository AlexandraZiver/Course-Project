#include "gamepreparation.h"
#include "ui_gamepreparation.h"
#include <mainwindow.h>
#include <authorization.h>
#include <QDebug>
#include <string>
#include <iostream>
#include <exception.h>

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>


#include <QUrl>

#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>

#include <QLabel>
#include <QImage>
#include <QObject>
#include <QString>

QString player1Skin = "player1";
QString player2Skin = "player2";
QString place = "place";
QString ballSkin = "ball1";

qreal ball_size;
qreal ball_weight;
QString game_map_path;
QString player_1_skin_path;
QString player_2_skin_path;
QString ball_skin_path;

extern bool isMusic;



gamepreparation::gamepreparation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gamepreparation)
{
    ui->setupUi(this);
    connect(ui->plr1_rchange, SIGNAL(clicked()), this, SLOT(pl1_change()));
    connect(ui->plr1_lchange, SIGNAL(clicked()), this, SLOT(pl1_change()));
    connect(ui->plr2_rchange, SIGNAL(clicked()), this, SLOT(pl2_change()));
    connect(ui->plr2_lchange, SIGNAL(clicked()), this, SLOT(pl2_change()));

    connect(ui->ball_rchange, SIGNAL(clicked()), this, SLOT(ball_change()));
    connect(ui->ball_lchange, SIGNAL(clicked()), this, SLOT(ball_change()));
    ui->player1->setPixmap(QPixmap(":/images/player1.png"));
    ui->player2->setPixmap(QPixmap(":/images/player2.png"));

    game_map_path = "background-image: url(:/images/ship1020.png)";           // За замовчуванням буде карта з кораблем
    player_1_skin_path = ":/images/player1.png";
    player_2_skin_path = ":/images/player2.png";
    ball_skin_path = ":/images/ball.png";
    ball_size = 0.3;
    ball_weight = 1;
}

gamepreparation::~gamepreparation()
{
    delete ui;
}


void gamepreparation::pl1_change()
{

    clickSound(isMusic);

    if(player1Skin=="player1"){
        ui->player1->setPixmap(QPixmap(":/images/player3.png"));
        player1Skin="player3";
        player_1_skin_path = ":/images/player3.png";
    }
    else if(player1Skin=="player3"){
        ui->player1->setPixmap(QPixmap(":/images/player1.png"));
        player1Skin="player1";
        player_1_skin_path = ":/images/player1.png";
    }

}

void gamepreparation::pl2_change()
{
    clickSound(isMusic);

    if(player2Skin=="player2"){
        ui->player2->setPixmap(QPixmap(":/images/player4.png"));
        player2Skin="player4";
        player_2_skin_path = ":/images/player4.png";
    }
    else if(player2Skin=="player4"){
        ui->player2->setPixmap(QPixmap(":/images/player2.png"));
        player2Skin="player2";
        player_2_skin_path = ":/images/player2.png";
    }

}

void gamepreparation::on_start_game_clicked()
{
    clickSound(isMusic);
    rules *_rules;
    _rules = new rules;
    _rules->show();
    this->close();
}

void gamepreparation::ball_change() {
    clickSound(isMusic);

    if(ballSkin=="ball1"){                                      // Средний мяч
        ui->ball->setPixmap(QPixmap(":/images/ball2.png"));
        ui->lineGetWeight->setText(""); // удаление строки введения при выборе мяча кнопками Александра
        ballSkin="ball2";
        ball_size = 0.4;
        ball_skin_path = ":/images/ball2.png";
    }
    else if(ballSkin=="ball2"){                                 // Большой мяч
        ui->ball->setPixmap(QPixmap(":/images/ball3.png"));
        ui->lineGetWeight->setText("");
        ballSkin="ball3";
        ball_size = 0.55;
        ball_skin_path = ":/images/ball4.png";
    }
    else if (ballSkin=="ball3") {                               // Маленький мяч
        ui->ball->setPixmap(QPixmap(":/images/ball.png"));
        ui->lineGetWeight->setText("");
        ballSkin="ball1";
        ball_size = 0.3;
        ball_skin_path = ":/images/ball.png";
    }
}



void gamepreparation::on_plr1_rchange_clicked()
{
    clickSound(isMusic);
}



void gamepreparation::on_lineGetWeight_textEdited()
{
    clickSound(isMusic);
    int weight = ui->lineGetWeight->text().toInt();
    ball_weight = weight;
    if( weight > 5 &&  weight <= 20 ){
        ui->ball->setPixmap(QPixmap(":/images/ball2.png"));
        ballSkin="ball2";
        ball_size = 0.4;
        ball_skin_path = ":/images/ball2.png";

    }
    if( weight > 20 &&  weight <= 30){
        ui->ball->setPixmap(QPixmap(":/images/ball3.png"));
        ballSkin="ball3";
        ball_size = 0.55;
        ball_skin_path = ":/images/ball4.png";

    }
    if ( weight <= 5 ) {
        ui->ball->setPixmap(QPixmap(":/images/ball.png"));
        ballSkin="ball1";
        ball_size = 0.3;
        ball_skin_path = ":/images/ball.png";
    }
}


void gamepreparation::on_lineGetWeight_textChanged()
{
    clickSound(isMusic);

    int weight = ui->lineGetWeight->text().toInt();
    ball_weight = weight;
    if( weight > 5 &&  weight <= 20 ){
        ui->ball->setPixmap(QPixmap(":/images/ball2.png"));
        ballSkin="ball2";
        ball_size = 0.4;

    }
    if( weight > 20 &&  weight <= 30){
        ui->ball->setPixmap(QPixmap(":/images/ball3.png"));
        ballSkin="ball3";
        ball_size = 0.55;

    }
    if ( weight <= 5 ) {
        ui->ball->setPixmap(QPixmap(":/images/ball.png"));
        ballSkin="ball1";
        ball_size = 0.3;

    }

}




void gamepreparation::on_placeChangeR_clicked()
{
    clickSound(isMusic);
    if(place=="place"){
            ui->place->setPixmap(QPixmap(":/images/ship33.png"));
            place="place2";
            game_map_path = "background-image: url(:/images/ship1020.png)";
        }

        else if(place=="place2"){
            ui->place->setPixmap(QPixmap(":/images/island3.png"));
            place="place";
            game_map_path = "background-image: url(:/images/place1020.png)";
        }
}


void gamepreparation::on_lineGetWeight_editingFinished()
{
     int weight = ui->lineGetWeight->text().toInt();
         exception *ex;
         ex = new exception;
        ex->checkWeight(weight, ui->lineGetWeight );
}



void gamepreparation::on_placeChangeL_clicked()
{
    clickSound(isMusic);
    if(place=="place"){
            ui->place->setPixmap(QPixmap(":/images/ship33.png"));
            place="place2";
            game_map_path = "background-image: url(:/images/ship1020.png)";
        }

        else if(place=="place2"){
            ui->place->setPixmap(QPixmap(":/images/island3.png"));
            place="place";
            game_map_path = "background-image: url(:/images/place1020.png)";
        }
}
void gamepreparation::on_back_clicked()
{
    clickSound(isMusic);
    authorization *reg;
    reg = new authorization;
    reg->show();
    this->close();

}






