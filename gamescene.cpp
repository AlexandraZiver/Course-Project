#include "gamescene.h"
#include "ui_gamescene.h"

GameScene::GameScene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameScene)
{
    ui->setupUi(this);
}

GameScene::~GameScene()
{
    delete ui;
}
