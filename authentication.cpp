#include "authentication.h"
#include "ui_authentication.h"
#include <mainwindow.h>
#include <QDebug>


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
QString ballSkin = "ball1";


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
    MainWindow *mWindow;
    mWindow = new MainWindow;
    mWindow->show();
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

    if(ballSkin=="ball1"){
        ui->ball->setPixmap(QPixmap(":/images/ball2.png"));
        ballSkin="ball2";
    }
    else if(ballSkin=="ball2"){
        ui->ball->setPixmap(QPixmap(":/images/ball3.png"));
        ballSkin="ball3";
    }
    else if (ballSkin=="ball3") {
        ui->ball->setPixmap(QPixmap(":/images/ball.png"));
        ballSkin="ball1";
    }
}

