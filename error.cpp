#include "error.h"
#include <QMessageBox>

Error::Error(int code)
{
    errorCode = code;
}


void Error::whatError() {
    registration *reg;
    reg = new registration;

    authentication *auth;
    auth = new authentication;

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

    default:
        break;
    }
}


int Error::getErrorCode() {
    return errorCode;
}
