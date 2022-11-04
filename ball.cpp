#include "ball.h"
#include "ui_ball.h"

Ball::Ball(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ball)
{
    ui->setupUi(this);
}

Ball::~Ball()
{
    delete ui;
}
