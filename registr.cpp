#include "registr.h"
#include "ui_registr.h"
#include <mainwindow.h>


registr::registr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registr)
{
    ui->setupUi(this);
}

registr::~registr()
{
    delete ui;
}

void registr::on_back_clicked()
{
    MainWindow *mWindow;
    mWindow = new MainWindow;
    mWindow->show();
    this->close();
}





void registr::on_playNoReg_clicked()
{
    authentication *auth;
    auth = new authentication;
    auth->show();
    this->close();

}


void registr::on_reg_clicked()
{
    registration *reg;
    reg = new registration;
    reg->show();
    this->close();
}

