#include "exception.h"
#include "registration.h"

#include <QMessageBox>

exception::exception()
{

}

void registration::on_reg_clicked()
{
    QString playerName = ui->lineEdit_PlayerName->text();
    QString password = ui->lineEdit_password->text();
    QString passwordCheck = ui->lineEdit_passwordCheck->text();

    if(playerName.length() <= 3) {
        QMessageBox::critical(this, "name", "Ошибка! Имя должно превышать 3 символа");
        ui->lineEdit_PlayerName->setText("");
        ui->lineEdit_password->setText("");
        ui->lineEdit_passwordCheck->setText("");
        return;
    }

    if (password.length() <= 3) {
        QMessageBox::critical(this, "password", "Ошибка! Пароль должен содержать больше 3 символов!");
        ui->lineEdit_PlayerName->setText("");
        ui->lineEdit_password->setText("");
        ui->lineEdit_passwordCheck->setText("");
    }

    if (password.length() >= 15) {
        QMessageBox::critical(this, "password", "Ошибка! Пароль должен содержать не более 15 символов!");
        ui->lineEdit_PlayerName->setText("");
        ui->lineEdit_password->setText("");
        ui->lineEdit_passwordCheck->setText("");
    }

    if (password != passwordCheck) {
        QMessageBox::critical(this, "stop", "Ошибка! Пароли не совпадают!");
        ui->lineEdit_PlayerName->setText("");
        ui->lineEdit_password->setText("");
        ui->lineEdit_passwordCheck->setText("");
    }
}
