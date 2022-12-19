#include "error.h"
#include <QMessageBox>

Error::Error(){

};
void Error::whatError(int errorCode) {
    registration *reg;
    reg = new registration;

    authorization *auth;
    auth = new authorization;

    switch (errorCode) {
    case 101:
        QMessageBox::information(reg, "name", "Помилка! Ім'я має перевищувати 3 символи");
        break;

    case 102:
        QMessageBox::information(reg, "name", "Помилка! Пароль має містити більше 3 символів!");
        break;

    case 103:
        QMessageBox::information(reg, "name", "Помилка! Пароль має містити не більше 15 символів!");
        break;

    case 104:
        QMessageBox::information(reg, "stop", "Помилка! Паролі не співпадають!");
        break;

    case 105:
        QMessageBox::information(auth, "Помилка", "Ви помилились при введенні ваги! Введіть вагу від 1кг до 30кг");
        break;

    case 106:
        QMessageBox::information(reg, "kirillica", "Помилка в імені! Можна використовувати тільки латинські букви");
        break;

    case 107:
        QMessageBox::information(reg, "kirillica", "Помилка в паролі! Можна використовувати тільки латинські букви");
        break;

    case 108:
        QMessageBox::information(reg, "Помилка", "Заповніть поля, будь ласка");
        break;

    case 201:
        QMessageBox::information(reg, "Помилка", "Акаунта з таким логіном не існує");
        break;

    case 202:
        QMessageBox::information(reg, "Помилка", "Пароль не підходить");
        break;

    case 203:
        QMessageBox::information(reg, "Помилка", "Акаунта з таким ім'ям вже існує");                             // При регистрации
        break;
    default:
        break;
    }
}


int Error::getErrorCode() {
    return errorCode;
}
