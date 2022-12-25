#include "rules.h"
#include <mainwindow.h>
#include "gamescene.h"
#include "ui_rules.h"

extern bool isMusic;

rules::rules(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rules)
{
    ui->setupUi(this);
}

rules::~rules()
{
    delete ui;
}




void rules::on_play_game_clicked()
{
    clickSound(isMusic);
    GameScene* gameScene;
    gameScene = new GameScene();
    gameScene->show();
    this->close();
}

