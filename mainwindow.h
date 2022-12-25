#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamepreparation.h"
#include "authorization.h"
#include "rules.h"
#include "about.h"
#include "record.h"
#include "registration.h"
#include "sound.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public sound
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:

    void soundButton();

private slots:
    void on_Exit_clicked();

    void on_Start_Game_clicked();

    void on_About_clicked();

    void on_Records_clicked();

    void on_soundButton_clicked();

private:
    Ui::MainWindow *ui;
    gamepreparation *gameprep;
    authorization *aut;
    about *_about;
    record *rec;



};
#endif // MAINWINDOW_H
