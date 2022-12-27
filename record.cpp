#include "record.h"
#include "ui_record.h"
#include "mainwindow.h"

record::record(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::record)
{
    ui->setupUi(this);
}

record::~record()
{
    delete ui;
}

void record::on_back_clicked()
{
    MainWindow *mWindow;
    mWindow = new MainWindow;
    mWindow->show();
    this->close();
}


void record::on_show_json_clicked()
{
    QString _login ;
    QString _password ;
    QFile fileOut("Baza.json");
   if( fileOut.open(QIODevice::ReadOnly | QIODevice::Text ))
   {


        ui->textEdit->clear();

        QJsonDocument json= QJsonDocument().fromJson(fileOut.readAll());
        qDebug() << json;

        QJsonArray arrayJson = json.array();
        for (int i=0; i < arrayJson.size();i++)
        {
         qDebug() << arrayJson[i];
        QJsonObject jobj = arrayJson[i].toObject();
        QJsonValue    login = jobj["login"];
        QJsonValue    password = jobj["password"];
     _login = login.toString();
     _password = password.toString();
     qDebug() << _login;
     qDebug() << _password;

        ui->textEdit->append(_login +   " " + _password);
        }
  }

  fileOut.close();
}

