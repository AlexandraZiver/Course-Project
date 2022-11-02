#include "rulles.h"
#include "ui_rulles.h"

rulles::rulles(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rulles)
{
    ui->setupUi(this);
}

rulles::~rulles()
{
    delete ui;
}




void rulles::on_play_game_clicked()
{

}

