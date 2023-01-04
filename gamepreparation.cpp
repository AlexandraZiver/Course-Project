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

qreal ballSize;
qreal ballWeight;
QString gameMapPath;
QString player1SkinPath;
QString player2SkinPath;
QString ballSkinPath;

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

    gameMapPath = "background-image: url(:/images/ship1020.png)";           // За замовчуванням буде карта з кораблем
    player1SkinPath = ":/images/player1.png";
    player2SkinPath = ":/images/player2.png";
    ballSkinPath = ":/images/ball.png";
    ballSize = 0.3;
    ballWeight = 1;
}

gamepreparation::~gamepreparation()
{
    delete ui;
}
//Alex
void gamepreparation::on_back_clicked()
{
    clickSound(isMusic);
    authorization *reg;
    reg = new authorization;
    reg->show();
    this->close();

}

//Alex


void gamepreparation::pl1_change()
{

    clickSound(isMusic);

    if(player1Skin=="player1"){
        ui->player1->setPixmap(QPixmap(":/images/player3.png"));
        player1Skin="player3";
        player1SkinPath = ":/images/player3.png";
    }
    else if(player1Skin=="player3"){
        ui->player1->setPixmap(QPixmap(":/images/player1.png"));
        player1Skin="player1";
        player1SkinPath = ":/images/player1.png";
    }

}

void gamepreparation::pl2_change()
{
    clickSound(isMusic);

    if(player2Skin=="player2"){
        ui->player2->setPixmap(QPixmap(":/images/player4.png"));
        player2Skin="player4";
        player2SkinPath = ":/images/player4.png";
    }
    else if(player2Skin=="player4"){
        ui->player2->setPixmap(QPixmap(":/images/player2.png"));
        player2Skin="player2";
        player2SkinPath = ":/images/player2.png";
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
        ui->lineEdit_3->setText(""); // удаление строки введения при выборе мяча кнопками Александра
        ballSkin="ball2";
        ballSize = 0.4;
        ballSkinPath = ":/images/ball2.png";
    }
    else if(ballSkin=="ball2"){                                 // Большой мяч
        ui->ball->setPixmap(QPixmap(":/images/ball3.png"));
        ui->lineEdit_3->setText("");
        ballSkin="ball3";
        ballSize = 0.55;
        ballSkinPath = ":/images/ball4.png";
    }
    else if (ballSkin=="ball3") {                               // Маленький мяч
        ui->ball->setPixmap(QPixmap(":/images/ball.png"));
        ui->lineEdit_3->setText("");
        ballSkin="ball1";
        ballSize = 0.3;
        ballSkinPath = ":/images/ball.png";
    }
}



void gamepreparation::on_plr1_rchange_clicked()
{
    clickSound(isMusic);
}

// Alex
void gamepreparation::on_lineEdit_3_textEdited()
{
    clickSound(isMusic);
    int weight = ui->lineEdit_3->text().toInt();
    ballWeight = weight;
    if( weight > 5 &&  weight <= 20 ){
        ui->ball->setPixmap(QPixmap(":/images/ball2.png"));
        ballSkin="ball2";
        ballSize = 0.4;
        ballSkinPath = ":/images/ball2.png";

    }
    if( weight > 20 &&  weight <= 30){
        ui->ball->setPixmap(QPixmap(":/images/ball3.png"));
        ballSkin="ball3";
        ballSize = 0.55;
        ballSkinPath = ":/images/ball4.png";

    }
    if ( weight <= 5 ) {
        ui->ball->setPixmap(QPixmap(":/images/ball.png"));
        ballSkin="ball1";
        ballSize = 0.3;
        ballSkinPath = ":/images/ball.png";
    }
}


void gamepreparation::on_lineEdit_3_textChanged()
{
    clickSound(isMusic);

    int weight = ui->lineEdit_3->text().toInt();
    ballWeight = weight;
    if( weight > 5 &&  weight <= 20 ){
        ui->ball->setPixmap(QPixmap(":/images/ball2.png"));
        ballSkin="ball2";
        ballSize = 0.4;

    }
    if( weight > 20 &&  weight <= 30){
        ui->ball->setPixmap(QPixmap(":/images/ball3.png"));
        ballSkin="ball3";
        ballSize = 0.55;

    }
    if ( weight <= 5 ) {
        ui->ball->setPixmap(QPixmap(":/images/ball.png"));
        ballSkin="ball1";
        ballSize = 0.3;

    }

}




void gamepreparation::on_pushButton_2_clicked()
{
    clickSound(isMusic);
    if(place=="place"){
            ui->place->setPixmap(QPixmap(":/images/ship33.png"));
            place="place2";
            gameMapPath = "background-image: url(:/images/ship1020.png)";
        }

        else if(place=="place2"){
            ui->place->setPixmap(QPixmap(":/images/island3.png"));
            place="place";
            gameMapPath = "background-image: url(:/images/place1020.png)";
        }
}


void gamepreparation::on_lineEdit_3_editingFinished()
{
     int weight = ui->lineEdit_3->text().toInt();
         exception *ex;
         ex = new exception;
        ex->checkWeight(weight, ui->lineEdit_3 );
}



void gamepreparation::on_pushButton_clicked()
{
    clickSound(isMusic);
    if(place=="place"){
            ui->place->setPixmap(QPixmap(":/images/ship33.png"));
            place="place2";
            gameMapPath = "background-image: url(:/images/ship1020.png)";
        }

        else if(place=="place2"){
            ui->place->setPixmap(QPixmap(":/images/island3.png"));
            place="place";
            gameMapPath = "background-image: url(:/images/place1020.png)";
        }
}

// Alex




