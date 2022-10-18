#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <QMainWindow> //класс, который можно использовать в качестве главного окна приложения.
#include <QObject> //Этот атрибут используется для идентификации каждого элемента
#include <QSharedDataPointer> // создает копию данных
#include <QWidget> //базовый класс для всех объектов пользовательского интерфейса.


class AuthenticationData;

class Authentication
{

public:
    Authentication();
    Authentication(const Authentication &);
    Authentication &operator=(const Authentication &);
        void showWindow();
        void enterName();
        void enterPassword();
        void buttonSafeToData();
        void buttonBackToMenu();
        void buttonStartGame();
    ~Authentication();

private:
    QSharedDataPointer <AuthenticationData> data; // создание копии данных
};

#endif // AUTHENTICATION_H
