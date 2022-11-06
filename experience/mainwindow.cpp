#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QMessageBox>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::nameChecked()
{
    QString name;
    name = ui->lineEdit_3->text();

    if (name.length() < 3)
        QMessageBox::critical(this, "Password", "Ошибка! Введите больше 3 символов");
}

void MainWindow::passwordControl()
{
    QString password1;
     password1 = ui->lineEdit->text();

      if (password1.length() < 3)
       QMessageBox::information(this, "Password", "Ошибка! Введите больше 3 символов");

}

void MainWindow::passwordCheck()
{
    QString password1;
    QString password2;
    password1 = ui->lineEdit->text();
    password2 = ui->lineEdit_2->text();

    if (password1 != password2)
        QMessageBox::information(this, "Password", "Ошибка! Пароли не совпадают!");

}




MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_3_cursorPositionChanged(int arg1, int arg2)
{

}

