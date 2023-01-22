#include "pause.h"
#include "ui_pause.h"
//
qreal exitBool = false;
qreal continueBool = false;
extern bool isMusic;

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

void Pause::on_exitBtn_clicked()
{
    clickSound(isMusic);
    exitBool = true;
     this->close();
}


void Pause::on_menuBtn_clicked()
{
    clickSound(isMusic);
    this->close();
    window = new MainWindow();
    window->show();

    exitBool = true;

}
void Pause::on_continueButton_clicked()
{
    clickSound(isMusic);
    continueBool = true;
   this->close();

}
