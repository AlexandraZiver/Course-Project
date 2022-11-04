#include "wall.h"
#include "ui_wall.h"

Wall::Wall(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wall)
{
    ui->setupUi(this);
}

Wall::~Wall()
{
    delete ui;
}
