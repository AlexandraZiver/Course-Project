//#ifndef EXCEPTION_H
//#define EXCEPTION_H
#include "nainwindow.h"
#include <QApplication>
#include <QLabel>
#include <iostream>
#include <string>
#include <fstream>



using namespace std;


class Exception
{
public:
    Exception();
    // exception.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
    //





    //исключения регистрация
    bool Data(std::ifstream& Reg, std::string filename) {
        size_t count = 0;
        char name;

        while (Reg >> name)
        {
            if (name != '.')
                if (!isdigit(name)) // если имя написано, тогда попадает в базу данных
                    count++; //увеличение имен в базе данных
                else {
                    //cout << "Ошибка! Вы должны ввести имя пользователя.";
                    QLabel *label = new QLabel(this);
                        label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
                        label->setText("first line\nsecond line");
                        label->setAlignment(Qt::AlignBottom | Qt::AlignRight);
                }
        }
        if (count)
            return false;
            cout << "Данное имя уже занято другим пользователем, выбeрите новое имя.";
        else
            return true;

    }

    string CorrectPassword(int length) {
            const string alphabet =
                "0123456789"
                "!@#$%^&*"
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                "abcdefghijklmnopqrstuvwxyz";
            string password;

            for (int i = 0; i < length; ++i)
                password += alphabet[rand() % alphabet.size()];

            return password;
        }

    void readValue(int& value) {
            while (!(cin >> value) || (cin.peek() != '\n') || (value <= 0)) {
                cin.clear();

                while (cin.get() != '\n');
                    QLabel *label = new QLabel("Ошибка! Введите другой пароль.");
                    label->show();
            }
    }

    //исключение вход
    bool InPutt {
        string names;
        string passwords;

        cout << "Введите логин" << endl;
        cin >> names;
        cout << "Введите пароль" << endl;
        cin >> passwords;

        if (names = _name && passwords = _password) {
            return true;
        else
            return false;
        cout << "Введен неправильный логин или пароль. Повторите попытку.";
        }
    }

    //исключения кнопки

    void Buttons{

        try
        {
            if (gameball != 0,2 || gameball != 0,4 || gameball != 0,6)
                throw "Вы не выбрали размер мяча, пожалуйста повторите попытку.";
        }
        catch (const char* exception)
        {
            std::cerr << "Ошибка: " << exception << '\n';
        }
    }

    int main()
    {
        std::cout << "Hello World!\n";
    }


};


