#include "data.h"
#include "ui_data.h"

Data::Data(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Data)
{
    ui->setupUi(this);
}

Data::~Data()
{
    delete ui;
}


void Data::on_pushButton_3_clicked()
{
    registration = new Registration;
    registration->show();
}


void Data::on_pushButton_2_clicked()
{
     close();
}

