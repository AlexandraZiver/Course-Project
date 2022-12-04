#include "registration.h"
#include <mainwindow.h>
#include "registr.h"


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
    authentication *auth;
    auth = new authentication;
    auth->show();
    this->close();
}







void registration::on_back_clicked()
{
    registr *reg;
    reg = new registr;
    reg->show();
    this->close();
}




