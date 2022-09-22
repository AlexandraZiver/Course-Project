#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <QDeclarativeItem>
#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>

class AuthenticationData;

class Authentication
{
    Q_OBJECT
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
    QSharedDataPointer<AuthenticationData> data;
};

#endif // AUTHENTICATION_H
