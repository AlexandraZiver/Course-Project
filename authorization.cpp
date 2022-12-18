#include "authorization.h"
#include "ui_authorization.h"
#include <mainwindow.h>
#include <QFileDialog>
#include <QTextStream>
#include <QMainWindow>
#include <QTextStream>



authorization::authorization(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::authorization)
{
    ui->setupUi(this);
}

authorization::~authorization()
{
    delete ui;
}

void authorization::on_back_clicked()
{
    MainWindow *mWindow;
    mWindow = new MainWindow;
    mWindow->show();
    this->close();
}



void authorization::on_playNoReg_clicked()
{
    gamepreparation *auth;
    auth = new gamepreparation;
    auth->show();
    this->close();

}


void authorization::on_reg_clicked()
{
    registration *reg;
    reg = new registration;
    reg->show();
    this->close();
}






void authorization::on_play_clicked()
{

}


//Alex
void authorization::on_not_reg_clicked()
{
    gamepreparation *auth2;
    auth2 = new gamepreparation;
    auth2->show();
    this->close();
}

// Function Samira
void authorization::Entrancy() {

    QString Login_correct;
    QString pass_correct;

    QString login = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();

    QFile fileOut("Baza.json");

    if(fileOut.open(QIODevice::ReadOnly))
    {
        qDebug() << "Файл существует 2";

      while (!fileOut.atEnd())
      {
        QString   login1 =  fileOut.readLine();

        login1.remove('\n');
        qDebug() << "login1" <<login1 << '\n';
          Login_correct = login1.section(' ', 0, 0);
           qDebug() << "Login_correct" <<Login_correct << '\n';
          pass_correct = login1.section(' ', 1, 1);
          qDebug() << "pass_correct" <<pass_correct << '\n';
        if ((Login_correct == login) && (pass_correct == password))
                {
                    qDebug() << "Данные введены  верно!" << '\n';
                }
                else
                {
                    qDebug() << "Пароль или логин введен не правильно!" << '\n';

                }
      }
    }

    fileOut.close();
    close();
}

void authorization::on_done_clicked()
{
    // Перевірка на латинські букви імені
    QString playerName = ui->lineEdit->text();
    QString password = ui->lineEdit_2 ->text();

    int errorCode = ExeptionOn_done_clicked(playerName, password);
    Error *error = new Error(errorCode);
    error->whatError();

    switch (error->getErrorCode()) {
    case 101:
        ui->lineEdit->setText("");
        return;

    case 102:
        ui->lineEdit_2->setText("");
        return;

    case 103:
        ui->lineEdit_2->setText("");
        return;

    case 106:
        ui->lineEdit->setText("");
        return;

    case 107:
        ui->lineEdit_2->setText("");
        return;

    case 108:
        return;

    default:
        break;
    }

    Entrancy();
    gamepreparation *auth;
    auth = new gamepreparation;
    auth->show();
    this->close();
}
