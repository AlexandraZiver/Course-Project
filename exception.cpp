#include "exception.h"
#include "registration.h"
#include "authentication.h"
#include "ui_authentication.h"
#include <QMessageBox>
#include <QChar>
#include <QString>
#include <mainwindow.h>;
#include "ball.h"
#include "wall.h"
#include "player.h"
#include "bonus.h"
#include "gamescene.h"
#include <fstream>
#include "error.h"

exception::exception()
{

}

// Function Samira
void registration::funct_registr() {

    QString login = ui->lineEdit_PlayerName->text();

    QString password = ui->lineEdit_password->text();
    int _userRecord = 0;

    QFile fileOut("Baza.json");
    QFile RecOut("Record.csv");
    if(fileOut.open(QIODevice::Append | QIODevice::WriteOnly))
    {
        qDebug() << "Файл существует 1";

        if( RecOut.open(QIODevice::Append | QIODevice::WriteOnly))
       {
                qDebug() << "Файл существует";
                //Если первый файл открыт для  записи успешн
                QTextStream stream(&fileOut);
                QTextStream Rec(&RecOut);
                stream << login << ' ';
                stream << password<<'\n';
                Rec << login <<'\n';
                Rec << _userRecord <<'\n';
        }

    }

    fileOut.close();
    RecOut.close();
   // close();
}


void registration::on_reg_clicked()
{
    funct_registr();

    QString playerName = ui->lineEdit_PlayerName->text();
       QString password = ui->lineEdit_password->text();
       QString passwordCheck = ui->lineEdit_passwordCheck->text();
       QString login;
       bool isNameCorrect = true;
       bool isPasswordCorrect = false;

             // Перевірка на латинські букви імені
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
                 isNameCorrect = false;
                 QMessageBox::information(this, "kirillica", "Помилка в імені! Можна використовувати тільки латинські букви");
                 ui->lineEdit_PlayerName->setText("");
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
                 ui->lineEdit_password->setText("");
                 ui->lineEdit_passwordCheck->setText("");
                 return;
              }


             try{
                 if (playerName.length() <= 3)
                     throw (Error(101));
                 else if(password.length() <= 3)
                     throw (Error(102));
                 else if(password.length() >= 15)
                     throw (Error(103));

                 //Alex   //перевірка на збіг паролей
                 if(password == passwordCheck) {
                     isPasswordCorrect = true;
                 }
                 else{ throw (Error(104)); }

             }
             catch(Error &ex){
                 if(ex.getErrorCode() == 101) {
                     ex.whatError();
                     ui->lineEdit_PlayerName->setText("");
                     isNameCorrect = false;
                     return;
                 }
                 else if(ex.getErrorCode() == 102) {
                     ex.whatError();
                     ui->lineEdit_password->setText("");
                     ui->lineEdit_passwordCheck->setText("");
                     return;
                 }
                 else if(ex.getErrorCode() == 103) {
                     ex.whatError();
                     ui->lineEdit_password->setText("");
                     ui->lineEdit_passwordCheck->setText("");
                     return;
                 }
                 else if(ex.getErrorCode() == 104) {
                     ex.whatError();
                     ui->lineEdit_passwordCheck->setText("");
                 }
             }


             //Якщо пароль, ім'я введено корректно і написано все латиницею, то користувач переходить на наступне вікно гри
                   if(isPasswordCorrect && isNameCorrect && !checkBadSymbolsPassword && !checkBadSymbolsName){
                       authentication *auth;
                       auth = new authentication;
                       auth->show();
                       this->close();
                   }
             }

             //Alex перевірка на вагу м'яча

             void authentication::checkWeight(int weight)
             {

             try{
                      if( weight < 1 ||  weight > 30 || !weight ){

                             throw(Error(105));
                             }

                 }
                 catch(Error &ex) {
                    ex.whatError();
                 }
             }



  void authentication::on_player2_linkActivated(const QString &link)
  {
    //  QString player1Skin = "player1";
            QString player2Skin = "player2";
            try {
                if (player2Skin != "player2" && player2Skin != "player4") {
                   GameScene *gm;
                   gm = new GameScene;
                   gm->show();
                   this->close();
                 }
                else { throw (player2Skin); }

             }
             catch (QString player2Skin) {
                   ui->player2->setPixmap(QPixmap(":/images/player2.png"));
                   player2Skin="player2";
             }
  }

  void authentication::on_player1_linkActivated(const QString &link)
  {
      QString player1Skin = "player1";
            QString player2Skin = "player2";

            try {
                if (player1Skin != "player1" && player1Skin != "player3") {
                    GameScene *gm;
                    gm = new GameScene;
                    gm->show();
                    this->close();
                }
                else { throw (player1Skin); }

             }
             catch (QString player1Skin) {
                        // QMessageBox::critical(this, "players", "Помилка! Треба вибрати персонажа!");
                    ui->player1->setPixmap(QPixmap(":/images/player3.png"));
                    player1Skin="player3  ";
             }
  }



