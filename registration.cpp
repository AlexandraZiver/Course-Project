#include "registration.h"
#include <mainwindow.h>
#include "authorization.h"
#include "error.h"


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


void registration::on_reg_clicked()
{
    funct_registr();

    QString playerName = ui->lineEdit_PlayerName->text();
    QString password = ui->lineEdit_password->text();
    QString passwordCheck = ui->lineEdit_passwordCheck->text();
    QString login;
    int errorCode = ExceptionOn_reg_clicked(playerName, password, passwordCheck);

    Error * er;
    er = new Error;
    er->getErrorCode(errorCode);

    switch (er->getErrorCode(errorCode)) {
    case 101:
        ui->lineEdit_PlayerName->setText("");
        return;

    case 102:
        ui->lineEdit_password->setText("");
        ui->lineEdit_passwordCheck->setText("");
        return;

    case 103:
        ui->lineEdit_password->setText("");
        ui->lineEdit_passwordCheck->setText("");
        return;

    case 104:
        ui->lineEdit_passwordCheck->setText("");
        return;

    case 106:
        ui->lineEdit_PlayerName->setText("");
        return;

    case 107:
        ui->lineEdit_password->setText("");
        ui->lineEdit_passwordCheck->setText("");
        return;

    case 108:
        return;

    default:
        break;
    }

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




