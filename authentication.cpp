#include "authentication.h"
#include "ui_authentication.h"
#include <mainwindow.h>
#include <registr.h>
#include <QDebug>
#include <string>
#include <iostream>
#include <exception.h>>

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

qreal ballSize = 0.4;
qreal ballWeight = 0;
QString gameMapPath = "background-image: url(:/images/ship1020.png)";              // За замовчуванням буде карта з кораблем
QString player1SkinPath;
QString player2SkinPath;
QString ballSkinPath;


authentication::authentication(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::authentication)
{
    ui->setupUi(this);
    connect(ui->plr1_rchange, SIGNAL(clicked()), this, SLOT(pl1_change()));
    connect(ui->plr1_lchange, SIGNAL(clicked()), this, SLOT(pl1_change()));
    connect(ui->plr2_rchange, SIGNAL(clicked()), this, SLOT(pl2_change()));
    connect(ui->plr2_lchange, SIGNAL(clicked()), this, SLOT(pl2_change()));

    connect(ui->ball_rchange, SIGNAL(clicked()), this, SLOT(ball_change()));
    connect(ui->ball_lchange, SIGNAL(clicked()), this, SLOT(ball_change()));

}

authentication::~authentication()
{
    delete ui;
}
//Alex
void authentication::on_back_clicked()
{

    registr *reg;
    reg = new registr;
    reg->show();
    this->close();

}

//Alex


void authentication::pl1_change()
{

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

void authentication::pl2_change()
{
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





void authentication::on_start_game_clicked()
{
    rules *_rules;
    _rules = new rules;
    _rules->show();
    this->close();
}

void authentication::ball_change() {

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



void authentication::on_plr1_rchange_clicked()
{

}

// Alex
void authentication::on_lineEdit_3_textEdited()
{
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


void authentication::on_lineEdit_3_textChanged()
{

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




void authentication::on_pushButton_2_clicked()
{
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


void authentication::on_pushButton_clicked()
{
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


void authentication::on_lineEdit_3_editingFinished()
{
     int weight = ui->lineEdit_3->text().toInt();
    if( weight < 1 ||  weight > 30 || !weight ){
         ui->lineEdit_3->setText("");
        checkWeight(weight);}

}
// Alex
