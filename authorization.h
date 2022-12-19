#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <QDialog>
#include <QMessageBox>
#include "exception.h"

//#include "error.h"


namespace Ui {
class authorization;
}

class authorization : public QDialog
{
    Q_OBJECT

public:
    explicit authorization(QWidget *parent = nullptr);
    ~authorization();

private slots:
    void on_back_clicked();


    void on_playNoReg_clicked();

    void on_reg_clicked();

    void on_play_clicked();

    void on_not_reg_clicked();

    void on_done_clicked();

    void Entrancy();

private:
    Ui::authorization *ui;
};

#endif // AUTHORIZATION_H
