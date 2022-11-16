#include "exception.h"
#include "registration.h"
#include "authentication.h"
#include <QMessageBox>
#include <mainwindow.h>;
#include "registration.h"

exception::exception()
{

}
void registration::on_reg_clicked()
{
    QString playerName = ui->lineEdit_PlayerName->text();
      QString password = ui->lineEdit_password->text();
      QString passwordCheck = ui->lineEdit_passwordCheck->text();
      try {
              if (playerName.length() <= 3) {
                  QMessageBox::critical(this, "name", "Помилка! Ім'я має перевищувати 3 символи");
                  ui->lineEdit_PlayerName->setText("");
              }

          }
          catch(QString playerName) {
              QMessageBox::critical(this, "name", "Помилка!");
          }


          try {
              if (password.length() <= 3) {
                  QMessageBox::critical(this, "password", "Помилка! Пароль має містити більше 3 символів!");
                  ui->lineEdit_password->setText("");
                  ui->lineEdit_passwordCheck->setText("");
              }
          }
          catch(QString password) {
                  QMessageBox::critical(this, "password", "Помилка!");
                  return;
          }



          try {
              if (password.length() >= 15) {
                  QMessageBox::critical(this, "password", "Помилка! Пароль має містити не більше 15 символів!");
                  ui->lineEdit_password->setText("");
                  ui->lineEdit_passwordCheck->setText("");
              }
          }
          catch(QString password) {
              QMessageBox::critical(this, "password", "Помилка!");
              return;
          }




      try {
          if (password == passwordCheck) {
              authentication *auth;
              auth = new authentication;
              auth->show();
              this->close();
          }
          else{ throw (password);}




      }
      catch(QString password) {
          QMessageBox::critical(this, "stop", "Помилка! Паролі не співпадають!");
          ui->lineEdit_password->setText(password);
          ui->lineEdit_passwordCheck->setText("");
//
//          return;
      }

  }



  void authentication::on_player2_linkActivated(const QString &link)
  {

  }

  void authentication::checkWeight(int weight)
  {

try{
           if( weight < 1 ||  weight > 30 || !weight ){

                  throw(weight);
                  }

      }
      catch(int weight) {

          QMessageBox::critical(this, "Помилка","Ви помилились при введенні ваги! Введіть вагу від 1кг до 30кг");

      }

  }

