#ifndef PAUSE_H
#define PAUSE_H

#include <QDialog>
#include "mainwindow.h"
#include "sound.h"


namespace Ui {
class Pause;
}

class Pause : public QDialog, public sound
{
    Q_OBJECT

public:
    explicit Pause(QWidget *parent = nullptr);

    ~Pause();

private slots:
void on_menuBtn_clicked();
void on_continueButton_clicked();
   void on_exitBtn_clicked();


private:
    Ui::Pause *ui;
    MainWindow *window;

};

#endif // PAUSE_H
