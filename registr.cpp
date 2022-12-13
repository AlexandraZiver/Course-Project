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
    // Перевірка на латинські букви імені
    QString playerName = ui->lineEdit->text();
    QString password = ui->lineEdit_2 ->text();

    char wordName;
    bool checkBadSymbolsName = false;             // Якщо true це означає що присутні заборонені символи
    for (auto wordName : playerName) {
        int buff = wordName.toLatin1();
        qDebug() << buff;
        if( (buff >= 48 && buff <= 57) || (buff >= 65 && buff <= 90) || (buff >= 97 && buff <= 122))
        {

        }
        else {
            qDebug() << buff;
            checkBadSymbolsName = true;
            break;
        }
    }

    if(checkBadSymbolsName) {
        QMessageBox::information(this, "kirillica", "Помилка в імені! Можна використовувати тільки латинські букви");
        ui->lineEdit->setText("");
        return;
    }

    // Перевірка на латинські букви пароля
    char wordPassword;
    bool checkBadSymbolsPassword = false;             // Якщо true це означає що присутні заборонені символи
    for (auto wordPassword : password) {
        int latinica = wordPassword.toLatin1();
        qDebug() << latinica;
        if( (latinica >= 48 && latinica <= 57) || (latinica >= 65 && latinica <= 90) || (latinica >= 97 && latinica <= 122))
        {

        }
        else {
            qDebug() << latinica;
            checkBadSymbolsPassword = true;
            break;
        }

    }

    if(checkBadSymbolsPassword) {
        QMessageBox::information(this, "kirillica", "Помилка в паролі! Можна використовувати тільки латинські букви");
        ui->lineEdit_2->setText("");
        return;
    }

    try{
        if (playerName.length() <= 3)
            throw (Error(101));
        else if(password.length() <= 3)
            throw (Error(102));
        else if(password.length() >= 15)
            throw (Error(103));

    }
    catch(Error &ex){
        if(ex.getErrorCode() == 101) {
            ex.whatError();
            ui->lineEdit->setText("");
            return;
        }
        else if(ex.getErrorCode() == 102) {
            ex.whatError();
            ui->lineEdit_2->setText("");
            return;
        }
        else if(ex.getErrorCode() == 103) {
            ex.whatError();
            ui->lineEdit_2->setText("");
            return;
        }
    }

    Entrancy();
    authentication *auth;
    auth = new authentication;
    auth->show();
    this->close();
}

