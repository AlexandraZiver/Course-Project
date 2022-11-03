#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <QDialog>


namespace Ui {
class authentication;
}

class authentication : public QDialog
{
    Q_OBJECT

public:
    explicit authentication(QWidget *parent = nullptr);
    ~authentication();

signals:
    void firstWindow();

private slots:


    void on_back_clicked();






    void on_start_game_clicked();

public slots:
    void pl1_change();
    void pl2_change();
    void ball_change();



private:
    Ui::authentication *ui;

};

#endif // AUTHENTICATION_H
