#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <QDialog>
#include "gamescene.h"

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






    void on_pushButton_clicked();


    void on_pushBtnSizeMed_clicked();

    void on_pushBtnSizeBig_clicked();

    void on_pushBtnSizeSmall_clicked();

public slots:
    void pl1_change();
    void pl2_change();



private:
    Ui::authentication *ui;

};

#endif // AUTHENTICATION_H
