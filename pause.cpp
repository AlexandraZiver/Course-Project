#include "pause.h"
#include "ui_pause.h"
//Alex
qreal exitBool = false;
qreal continueBool = false;
Pause::Pause(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pause)
{
    ui->setupUi(this);
}

Pause::~Pause()
{
    delete ui;
}

void Pause::slot()
{

}
void Pause::on_exitBtn_clicked()
{
    exitBool = true;
     this->close();
}


void Pause::on_menuBtn_clicked()
{
    this->close();
    window = new MainWindow();
    window->show();

    exitBool = true;

}
void Pause::on_continueButton_clicked()
{
    continueBool = true;
   this->close();

}
//Alex
