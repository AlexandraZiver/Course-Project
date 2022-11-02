#include "authentication.h"
#include "gamescene.h"
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

qreal ballSize = 0.4;



authentication::authentication(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::authentication)
{
    ui->setupUi(this);
    connect(ui->plr1_rchange, SIGNAL(clicked()), this, SLOT(pl1_change()));
    connect(ui->plr1_lchange, SIGNAL(clicked()), this, SLOT(pl1_change()));
    connect(ui->plr2_rchange, SIGNAL(clicked()), this, SLOT(pl2_change()));
    connect(ui->plr2_lchange, SIGNAL(clicked()), this, SLOT(pl2_change()));

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


void authentication::on_pushButton_clicked()
{
    gameScene *gamescene;
    gamescene = new gameScene;
    gamescene->show();
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




void authentication::on_pushBtnSizeMed_clicked()
{
    ui->pushBtnSizeSmall->setEnabled(true);
    ui->pushBtnSizeMed->setEnabled(false);
        ui->pushBtnSizeBig->setEnabled(true);
    ballSize = 0.4;
}


void authentication::on_pushBtnSizeBig_clicked()
{
    ui->pushBtnSizeSmall->setEnabled(true);
    ui->pushBtnSizeMed->setEnabled(true);
    ui->pushBtnSizeBig->setEnabled(false);
    ballSize = 0.55;
}


void authentication::on_pushBtnSizeSmall_clicked()
{
    ui->pushBtnSizeSmall->setEnabled(false);
    ui->pushBtnSizeMed->setEnabled(true);
    ui->pushBtnSizeBig->setEnabled(true);
    ballSize = 0.3;
}

