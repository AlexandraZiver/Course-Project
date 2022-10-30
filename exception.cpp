#ifndef EXCEPTION_H
#define EXCEPTION_H
#include "nainwindow.h"
#include <QApplication>
#include <QLabel>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_textEdit_copyAvailable(bool b)
{

}

//исключения регистрации
void MainWindow::on_pushButton_clicked()
{
    int count = 0;
    char name;
    while (Reg >> name)
    {
            if (name != '.') {
                if (name) // если имя написано, тогда попадает в базу данных
                    count++; //увеличение имен в базе данных

                else {
                    ui->label->setText("Ошибка! Вы должны ввести имя пользователя");
                }
                if (count)
                    ui->label2->setText( "Данное имя уже занято другим пользователем, выбeрите новое имя.");
            }
    }
}


/*void readValue(int& value) {
         while (!(qtin >> value) || (cin.peek() != '\n') || (value <= 0)) {
            cin.clear();

            while (cin.get() != '\n')
                cout << "Ошибка! Вводить можно только положительные числа!" << endl;
        }*/

//исключение пароль
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
    //if (!alphabet)
        QMessageBox::critical(this, "Ошибка! Вводить можно только положительные числа!");
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
        QMessageBox::critical(this, "Ошибка!");
    }
}
