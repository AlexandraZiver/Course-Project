#include "authentication.h"
#include "ui_authentication.h"
#include <mainwindow.h>
#include <registr.h>
#include <QDebug>
#include <string>
#include <iostream>

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
qreal ballWeight = 0.8;


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

void authentication::on_back_clicked()
{
    registr *reg;
    reg = new registr;
    reg->show();
    this->close();

}




void authentication::pl1_change()
{

    if(player1Skin=="player1"){
        ui->player1->setPixmap(QPixmap(":/images/player3.png"));
        player1Skin="player3";
    }
    else if(player1Skin=="player3"){
        ui->player1->setPixmap(QPixmap(":/images/player1.png"));
        player1Skin="player1";
    }

}

void authentication::pl2_change()
{
    if(player2Skin=="player2"){
        ui->player2->setPixmap(QPixmap(":/images/player4.png"));
        player2Skin="player4";
    }
    else if(player2Skin=="player4"){
        ui->player2->setPixmap(QPixmap(":/images/player2.png"));
        player2Skin="player2";
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
        ballSkin="ball2";
        ballSize = 0.4;
    }
    else if(ballSkin=="ball2"){                                 // Большой мяч
        ui->ball->setPixmap(QPixmap(":/images/ball3.png"));
        ballSkin="ball3";
        ballSize = 0.55;
    }
    else if (ballSkin=="ball3") {                               // Маленький мяч
        ui->ball->setPixmap(QPixmap(":/images/ball.png"));
        ballSkin="ball1";
        ballSize = 0.3;
    }
}





void authentication::on_massa_clicked()
{

}




void authentication::on_plr1_rchange_clicked()
{

}


void authentication::on_lineEdit_3_textEdited(const QString &arg1)
{
    int massa = ui->lineEdit_3->text().toInt();

    if( massa > 5 &&  massa < 10 ){                                      // Средний мяч
        ui->ball->setPixmap(QPixmap(":/images/ball2.png"));
        ballSkin="ball2";
        ballSize = 0.4;

    }
    if( massa > 10 &&  massa < 15){                                 // Большой мяч
        ui->ball->setPixmap(QPixmap(":/images/ball3.png"));
        ballSkin="ball3";
        ballSize = 0.55;

    }
    if ( massa < 5 ) {                               // Маленький мяч
        ui->ball->setPixmap(QPixmap(":/images/ball.png"));
        ballSkin="ball1";
        ballSize = 0.3;

    }
}


void authentication::on_lineEdit_3_textChanged(const QString &arg1)
{

    int massa = ui->lineEdit_3->text().toInt();

    if( massa > 5 &&  massa < 10 ){                                      // Средний мяч
        ui->ball->setPixmap(QPixmap(":/images/ball2.png"));
        ballSkin="ball2";
        ballSize = 0.4;

    }
    if( massa > 10 &&  massa < 15){                                 // Большой мяч
        ui->ball->setPixmap(QPixmap(":/images/ball3.png"));
        ballSkin="ball3";
        ballSize = 0.55;

    }
    if ( massa < 5 ) {                               // Маленький мяч
        ui->ball->setPixmap(QPixmap(":/images/ball.png"));
        ballSkin="ball1";
        ballSize = 0.3;

    }
}


void authentication::on_placeChange_clicked()
{

}

