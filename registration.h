#ifndef REGISTRATION_H
#define REGISTRATION_H

#include "ui_registration.h"
#include "exception.h"
#include "error.h"
#include <QWidget>
#include <QObject>
#include <QFile>

namespace Ui {
class registration;
}

class registration : public QWidget
{
    Q_OBJECT

public:
    explicit registration(QWidget *parent = nullptr);
    ~registration();

private slots:
    void on_playNoReg_clicked();

    void on_reg_clicked();

    void on_back_clicked();

     void funct_registr();

   

private:
    Ui::registration *ui;
};

#endif // REGISTRATION_H
