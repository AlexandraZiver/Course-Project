#ifndef REGISTR_H
#define REGISTR_H

#include <QDialog>

namespace Ui {
class registr;
}

class registr : public QDialog
{
    Q_OBJECT

public:
    explicit registr(QWidget *parent = nullptr);
    ~registr();

private slots:
    void on_back_clicked();


    void on_playNoReg_clicked();

    void on_reg_clicked();

    void on_play_clicked();

    void on_not_reg_clicked();

    void on_done_clicked();

    void Entrancy();

private:
    Ui::registr *ui;
};

#endif // REGISTR_H
