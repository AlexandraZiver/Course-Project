#include "record.h"
#include "ui_record.h"
#include "mainwindow.h"
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QXmlStreamAttribute>

extern bool isMusic;

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
    clickSound(isMusic);
    MainWindow *mWindow;
    mWindow = new MainWindow;
    mWindow->show();
    this->close();
}

//Samira
void record::on_show_json_clicked()
{
    Save_xml();
    Read_xml();
}

void record::on_pushButton_clicked()
{
     int _userRecord ;
    QString _login ;
    QFile fileOut("record.json");
   if( fileOut.open(QIODevice::ReadOnly | QIODevice::Text ))
   {


        ui->textEdit_3->clear();

        QJsonDocument json= QJsonDocument().fromJson(fileOut.readAll());
        qDebug() << json;

        QJsonArray arrayJson = json.array();
        for (int i=0; i < arrayJson.size();i++)
        {
         qDebug() << arrayJson[i];
        QJsonObject jobj = arrayJson[i].toObject();
        QJsonValue    userRecord = jobj["_userRecord"];
        QJsonValue    login = jobj["login"];
         _login = login.toString();
         _userRecord = userRecord.toInt();


     qDebug() << _login;
     qDebug() << _userRecord;
     QString record_str = QString::number(_userRecord);
        ui->textEdit_3->append( _login + ":" + " " +record_str );
        }
  }

  fileOut.close();
}

void record::on_show_sql_clicked()
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

        ui->textEdit->append(_login + + ":" + " " + _password);
        }
  }

  fileOut.close();
}
