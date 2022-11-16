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

    void on_player2_linkActivated(const QString &link);

    void on_plr1_rchange_clicked();

    void on_lineEdit_3_textEdited(const QString &arg1);

    void on_lineEdit_3_textChanged(const QString &arg1);

    void on_placeChange_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

public slots:
    void pl1_change();
    void pl2_change();
    void ball_change();



private:
    Ui::authentication *ui;

};

#endif // AUTHENTICATION_H
