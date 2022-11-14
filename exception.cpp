#include "exception.h"
#include "registration.h"
#include "authentication.h"
#include <QMessageBox>
#include "ui_authentication.h"
#include <mainwindow.h>

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
        if (password != passwordCheck) {
            QMessageBox::critical(this, "stop", "Помилка! Паролі не співпадають!");
            ui->lineEdit_password->setText("");
            ui->lineEdit_passwordCheck->setText("");
        }
    }
    catch(QString password) {
        QMessageBox::critical(this, "stop", "Помилка!");
        return;
    }

}


void authentication::on_player2_linkActivated(const QString &link)
{

}
