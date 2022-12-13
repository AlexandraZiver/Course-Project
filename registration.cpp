#include "registration.h"
#include <mainwindow.h>
#include "authorization.h"


registration::registration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::registration)
{
    ui->setupUi(this);
}

registration::~registration()
{
    delete ui;
}

void registration::on_playNoReg_clicked()
{
    gamepreparation *auth;
    auth = new gamepreparation;
    auth->show();
    this->close();
}







void registration::on_back_clicked()
{
    authorization *reg;
    reg = new authorization;
    reg->show();
    this->close();
}




