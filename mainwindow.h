#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "authentication.h"
#include "registr.h"
#include "rules.h"
#include "about.h"
#include "record.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Exit_clicked();

    void on_Start_Game_clicked();

    void on_About_clicked();

    void on_Records_clicked();

private:
    Ui::MainWindow *ui;
    authentication *auth;
    registr *reg;
    about *_about;
    record *rec;



};
#endif // MAINWINDOW_H
