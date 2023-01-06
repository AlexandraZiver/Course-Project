#include "about.h"
#include "ui_about.h"
#include "mainwindow.h"

extern bool isMusic;

about::about(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);
}

about::~about()
{
    delete ui;
}

void about::on_back_clicked()
{
    clickSound(isMusic);
    MainWindow *mWindow;
    mWindow = new MainWindow;
    mWindow->show();
    this->close();

}

