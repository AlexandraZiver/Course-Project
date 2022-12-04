#ifndef PAUSE_H
#define PAUSE_H

#include <QDialog>
#include "mainwindow.h"


namespace Ui {
class Pause;
}

class Pause : public QDialog
{
    Q_OBJECT

public:
    explicit Pause(QWidget *parent = nullptr);

    ~Pause();

private slots:
void on_menuBtn_clicked();
void on_continueButton_clicked();
   void on_exitBtn_clicked();
public slots:
 void slot();


private:
    Ui::Pause *ui;
    MainWindow *window;

};

#endif // PAUSE_H
