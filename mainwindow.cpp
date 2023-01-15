#include "mainwindow.h"
#include "ui_mainwindow.h"


bool isMusic = true;
bool isM = true;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    gameprep = new gamepreparation();
    connect(gameprep, &gamepreparation::firstWindow, this, &MainWindow::show);
    connect(ui->soundButton,SIGNAL(clicked()),this,SLOT(soundButton()));


    music->setAudioOutput(musicOutput);
    music->setSource(QUrl::fromLocalFile("qrc:/coolmusic.mp3"));


    if (isMusic) { 
       if (isM) {
            musicOutput->setVolume(0.1);
            music->play();
            isM = false;
       }



    }

    else if (!isMusic ) {

        musicOutput->setVolume(0);
    }



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Exit_clicked()
{
    clickSound(isMusic);
    this->close();
}


void MainWindow::on_Start_Game_clicked()
{

    clickSound(isMusic);
    aut = new authorization();
    aut->show();
    this->close();

}


void MainWindow::on_About_clicked()
{
    clickSound(isMusic);
    _about = new about;
    _about->show();
    this->close();


}


void MainWindow::on_Records_clicked()
{
    clickSound(isMusic);
    rec = new record;
    rec->show();
    this->close();
}



void MainWindow::soundButton() {

    if(isMusic){
        ui->soundButton->setStyleSheet(QLatin1String("background-image: url(\":/images/no-volume.png\");\n"
                                                "background-repeat: no-repeat;\n"
                                                "border: 0"));
        musicOutput->setVolume(0);
        isM = false;


    }else if(!isMusic){
        ui->soundButton->setStyleSheet(QLatin1String("background-image: url(\":/images/volume.png\");\n"
                                                "background-repeat: no-repeat;\n"
                                                "border: 0"));
        musicOutput->setVolume(0.1);
        isM = true;




    }

    isMusic = !isMusic;

}

