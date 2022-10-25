#ifndef EXCEPTION_H
#define EXCEPTION_H



class Exception
{
public:
    Exception();
    // exception.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
    //

    #include <iostream>
    #include <string>
    #include <fstream>

    using namespace std;


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
                    cout << "Ошибка! Вы должны ввести имя пользователя.";
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
                    cout << "Ошибка! Вводить можно только положительные числа!" << endl;
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


