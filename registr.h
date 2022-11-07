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

private:
    Ui::registr *ui;
};

#endif // REGISTR_H
