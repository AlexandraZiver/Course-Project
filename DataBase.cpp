
#include "Base.h"
int _stateMenu;
void Menu() {
    cout << "Выберите действие: " << endl
        << "(0) Выход из программы" << endl
        << "(1) Изменение данных" << endl
        << "(2) ///" << endl
        << "(3) Сохранение данных" << endl
        << "(4) Registr" << endl
        << "(5) Etrancy" << endl
        << "Ваш выбор" << endl;
    cin >> _stateMenu;
}


int main()
{
    // Руссификация консоли ввода/выводы
    SetConsoleCP(1251);     //Установка кодовой страниц win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);       // Установка кодовой страниц win-cp 1251 в поток вывода

    DataInitialization(); // Инициализация данных
    DataCleaning2();

    Menu();

    //int _actions;
    string fileName;

    int n = 0;
    while (_stateMenu != 0)
    {
        switch (_stateMenu)
        {


        case 1:
            system("cls");

            // DataChange(); // изменение данных

            system("pause");
            system("cls");
            Menu();
            break;
            //////////////////////////////////////////////////

        case 2:
            system("cls");

            AddZero();

            system("pause");
            system("cls");
            Menu();
            break;
            //////////////////////////////////////////////////
        case 3:
            system("cls");

            system("cls");

            SaveData();

            system("pause");
            system("cls");
            Menu();
            break;
            //////////////////////////////////////////////////
        case 4:
            system("cls");//очистка консоли


            Registr();

            system("pause");//задержка консоди
            system("cls");//лчистка консоли
            Menu();
            break;
            /////////////////////////////////////////////////
        case 5:
            system("cls");//очистка консоли



            Etrancy();

            system("pause");//задержка консоди
            system("cls");//oчистка консоли
            Menu();
            break;
            /////////////////////////////////////////////////
        default:
            cout << "Неправильно выбран пункт меню! " << endl;
            break;
        }
    }

    // просто очищает консоль
    system("cls");
    if (DataCleaning())
        cout << "Даныее очищены!" << endl;
    else
        cout << "Данные НЕ очищены!" << endl;

    cout << "Работа завершена." << endl;
    system("pause");


}

