#ifndef GAMEPREPARATION_H
#define GAMEPREPARATION_H

#include <QDialog>
#include "sound.h"


namespace Ui {
class gamepreparation;
}

class gamepreparation : public QDialog, public sound
{
    Q_OBJECT

public:
    explicit gamepreparation(QWidget *parent = nullptr);
    ~gamepreparation();

signals:
    void firstWindow();

public slots:


    void on_back_clicked();






    void on_start_game_clicked();



    void on_plr1_rchange_clicked();
    //

    void on_lineGetWeight_textEdited();

    void on_lineGetWeight_textChanged();

    void on_placeChangeR_clicked();

    void on_placeChangeL_clicked();


    void on_lineGetWeight_editingFinished();
    //



public slots:
    void pl1_change();
    void pl2_change();
    void ball_change();



private:
    Ui::gamepreparation *ui;

};

#endif // GAMEPREPARATION_H
