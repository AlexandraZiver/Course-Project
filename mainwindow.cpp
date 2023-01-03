#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMediaPlayer>
#include <QAudioOutput>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    gameprep = new gamepreparation();

    connect(gameprep, &gamepreparation::firstWindow, this, &MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Exit_clicked()
{
    this->close();
}


void MainWindow::on_Start_Game_clicked()
{
    aut = new authorization();
    aut->show();
    this->close();

}


void MainWindow::on_About_clicked()
{
    _about = new about;
    _about->show();
    this->close();


}


void MainWindow::on_Records_clicked()
{
    rec = new record;
    rec->show();
    this->close();
}

