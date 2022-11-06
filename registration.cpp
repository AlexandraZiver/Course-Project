#include "registration.h"
#include "ui_registration.h"

Registration::Registration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
}

Registration::~Registration()
{
    delete ui;
}



void Registration::on_pushButton_2_clicked()
{

        QString login = ui->login->text();

        QString password = ui->pass->text();
        int _userRecord = 0;
        //int n ;
       // n = AmountOfData() + 1;


        QFile fileOut("Baza.txt");
        QFile RecOut("Record.txt");
        if(fileOut.open(QIODevice::Append | QIODevice::WriteOnly))
        {
            qDebug() << "Файл существует 1";

            if( RecOut.open(QIODevice::Append | QIODevice::WriteOnly))
           {
                    qDebug() << "Файл существует";
                    //Если первый файл открыт для  записи успешн
                    QTextStream stream(&fileOut);
                    QTextStream Rec(&RecOut);
                    stream << login << '\n';
                    stream << password<<'\n';
                    Rec << login <<'\n';
                    Rec << _userRecord <<'\n';
            }

        }

        fileOut.close();
        RecOut.close();
        close();

}

