#include "registr.h"
#include "ui_registr.h"
#include <mainwindow.h>
#include <QFileDialog>
#include <QTextStream>
#include <QMainWindow>
#include <QTextStream>



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






void registr::on_play_clicked()
{

}


//Alex
void registr::on_not_reg_clicked()
{
    authentication *auth2;
    auth2 = new authentication;
    auth2->show();
    this->close();
}

// Function Samira
void registr::Entrancy() {

    QString Login_correct;
    QString pass_correct;

    QString login = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();

    QFile fileOut("Baza.json");

    if(fileOut.open( QIODevice::ReadOnly))
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

void registr::on_done_clicked()
{
    Entrancy();
    QString login = ui->lineEdit->text();
    QString password = ui->lineEdit_2 ->text();
    authentication *auth;
    auth = new authentication;
    auth->show();
    this->close();
}

