#include "exception.h"
#include "registration.h"
#include "gamepreparation.h"
#include "ui_gamepreparation.h"
#include <QMessageBox>
#include <QChar>
#include <QString>
#include <mainwindow.h>;
#include "ball.h"
#include "wall.h"
#include "player.h"
#include "gamescene.h"
#include <fstream>
#include <error.h>


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


// При реєстрції
int ExceptionOn_reg_clicked(QString playerName, QString password, QString passwordCheck)
{
    Error * ex;
    ex = new Error;
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
              ex->getErrorCode(106);
              ex->whatError(106);
              return 106;
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
              ex->getErrorCode(107);
              ex->whatError(107);
              return 107;
           }

          // Перевірка довжини ім'я
          try{
              if(playerName.length() == 0 && password.length() == 0 && passwordCheck.length() == 0)
                  throw(108);
              else if (playerName.length() <= 3)
                  throw (101);
              else if(password.length() <= 3)
                  throw (102);
              else if(password.length() >= 15)
                  throw (103);
              else if(password != passwordCheck)            // Alex перевірка на збіг паролей
                  throw (104);


              /*
              //Alex   //перевірка на збіг паролей
              if(password == passwordCheck) {
              }
              else{ throw (Error(104)); }
              */
          }
          catch(int codeError){
              Error * ex;
              ex = new Error;
              ex->whatError(codeError);
              return ex->getErrorCode(codeError);
          }
        return 1;                                 // Коли повертається 1, то все гаразд
}

// При авторизації
int ExeptionOn_done_clicked(QString playerName, QString password)
{
    Error * ex;
    ex = new Error;
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
        ex->whatError(306);
        return ex->getErrorCode(306);
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
        ex->getErrorCode(307);
        ex->whatError(307);
        return 307;
    }

    try{
        if(playerName.length() == 0 && password.length() == 0)          // Коли нічого не введено
            throw(308);
        else if (playerName.length() <= 3)
            throw (301);
        else if(password.length() <= 3)
            throw (302);
        else if(password.length() >= 15)
            throw (303);

    }
    catch(int codeError){
        ex->whatError(codeError);
        return ex->getErrorCode(codeError);
    }
//    return 1;
}

//Alex перевірка на вагу м'яча

void exception::checkWeight(int weight, QLineEdit *lineEdit_3 )
{

try{
         if( weight < 0 ||  weight > 30 || !weight ){
              throw(105);
         }


    }
    catch(int codeError) {
         lineEdit_3->setText("");
       Error * ex;
       ex = new Error;
       ex->getErrorCode(codeError);
       ex->whatError(codeError);
    }
}
