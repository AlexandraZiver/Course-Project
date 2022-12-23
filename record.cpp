#include "record.h"
#include "ui_record.h"
#include "mainwindow.h"

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

