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

   /*  QString playerName = ui->lineEdit->text();

    QString password = ui->lineEdit_2->text();
    int _userRecord = 0;
    //int n ;
   // n = AmountOfData() + 1;


    QFile fileOut("Baza.txt");
    QFile RecOut("Record.txt");
    if(fileOut.open(QIODevice::Append | QIODevice::WriteOnly))
    {
        qDebug() << "Файл существует 1";

        if( RecOut.open(QIODevice::Append | QIODevice::WriteOnly))
       {
                qDebug() << "Файл существует";
                //Если первый файл открыт для  записи успешн
                QTextStream stream(&fileOut);
                QTextStream Rec(&RecOut);
                stream << playerName << '\n';
                stream << password<<'\n';
                Rec << playerName <<'\n';
                Rec << _userRecord <<'\n';
        }


    }

    fileOut.close();
    RecOut.close();
    close();  */

}






void registr::on_play_clicked()
{

}



void registr::on_not_reg_clicked()
{
    authentication *auth2;
    auth2 = new authentication;
    auth2->show();
    this->close();
}


void registr::on_done_clicked()
{
    QString login = ui->lineEdit->text();
    QString password = ui->lineEdit_2 ->text();
    authentication *auth;
    auth = new authentication;
    auth->show();
    this->close();
}

